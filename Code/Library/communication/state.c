/**
 * \page The MAV'RIC License
 *
 * The MAV'RIC Framework
 *
 * Copyright � 2011-2014
 *
 * Laboratory of Intelligent Systems, EPFL
 */
 

/**
 * \file state.c
 *
 *  Place where the state structure is defined
 */


#include "state.h"
#include "print_util.h"
#include "mavlink/include/maveric/mavlink.h"

void state_init(state_structure_t *state_structure, uint8_t autopilot_type, uint8_t autopilot_name, uint8_t mav_state, uint8_t mav_mode, HIL_mode simu_mode, mavlink_communication_t *mavlink_communication)
{
	state_structure->autopilot_type = autopilot_type;
	state_structure->autopilot_name = autopilot_name;
	
	state_structure->mav_state = mav_state;
	state_structure->mav_mode = mav_mode;
	
	state_structure->simulation_mode = simu_mode;
	
	state_structure->mav_mode_previous = state_structure->mav_mode;
	state_structure->mav_state_previous = state_structure->mav_state;
	
	state_structure->simulation_mode_previous = state_structure->simulation_mode;
	
	// Add callbacks for onboard parameters requests
	mavlink_message_handler_msg_callback_t callback;
	
	callback.message_id 	= MAVLINK_MSG_ID_SET_MODE; // 11
	callback.sysid_filter 	= MAVLINK_BASE_STATION_ID;
	callback.compid_filter 	= MAV_COMP_ID_ALL;
	callback.function 		= (mavlink_msg_callback_function_t)	&state_set_mav_mode;
	callback.module_struct 	= (handling_module_struct_t)		state_structure;
	mavlink_message_handler_add_msg_callback( &mavlink_communication->message_handler, &callback );
	
	print_util_dbg_print("State initialized.\n");
}

task_return_t mavlink_telemetry_send_heartbeat(state_structure_t* state_structure)
{
	mavlink_msg_heartbeat_send(MAVLINK_COMM_0, state_structure->autopilot_type, state_structure->autopilot_name, state_structure->mav_mode, 0, state_structure->mav_state);
	
	return TASK_RUN_SUCCESS;
}

void state_set_mav_mode(state_structure_t* state_structure, mavlink_received_t* rec)
{
	mavlink_set_mode_t packet;
	
	mavlink_msg_set_mode_decode(&rec->msg,&packet);
	
	// Check if this message is for this system and subsystem
	// No component ID in mavlink_set_mode_t so no control
	if ((uint8_t)packet.target_system == (uint8_t)mavlink_system.sysid)
	{
		print_util_dbg_print("base_mode:");
		print_util_dbg_print_num(packet.base_mode,10);
		print_util_dbg_print(", custom mode:");
		print_util_dbg_print_num(packet.custom_mode,10);
		print_util_dbg_print("\n");

		if (state_structure->simulation_mode == 0)
		{
			switch(packet.base_mode)
			{
				case MAV_MODE_STABILIZE_DISARMED:
				case MAV_MODE_GUIDED_DISARMED:
				case MAV_MODE_AUTO_DISARMED:
					state_structure->mav_state = MAV_STATE_STANDBY;
					state_structure->mav_mode = MAV_MODE_MANUAL_DISARMED;
					break;
				
				case MAV_MODE_MANUAL_ARMED:
					//if (remote_controller_get_thrust_from_remote()<-0.95f)
					{
						state_structure->mav_state = MAV_STATE_ACTIVE;
						state_structure->mav_mode = MAV_MODE_MANUAL_ARMED;
					}
					break;
			}
		}
		else
		{
			switch(packet.base_mode)
			{
				case MAV_MODE_STABILIZE_DISARMED:
				case MAV_MODE_GUIDED_DISARMED:
				case MAV_MODE_AUTO_DISARMED:
					state_structure->mav_state = MAV_STATE_STANDBY;
					state_structure->mav_mode = MAV_MODE_MANUAL_DISARMED;
					break;
				case MAV_MODE_MANUAL_ARMED:
					state_structure->mav_state = MAV_STATE_ACTIVE;
					state_structure->mav_mode = MAV_MODE_MANUAL_ARMED;
					break;
				case MAV_MODE_STABILIZE_ARMED:
					state_structure->mav_state = MAV_STATE_ACTIVE;
					state_structure->mav_mode = MAV_MODE_STABILIZE_ARMED;
					break;
				case MAV_MODE_GUIDED_ARMED:
					state_structure->mav_state = MAV_STATE_ACTIVE;
					state_structure->mav_mode = MAV_MODE_GUIDED_ARMED;
					break;
				case MAV_MODE_AUTO_ARMED:
					state_structure->mav_state = MAV_STATE_ACTIVE;
					state_structure->mav_mode = MAV_MODE_AUTO_ARMED;
					break;
			}
		}
	}
}