/*******************************************************************************
 * Copyright (c) 2009-2014, MAV'RIC Development Team
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation 
 * and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/*******************************************************************************
 * \file lsm330dlc.h
 * 
 * \author MAV'RIC Team
 * \author Felix Schill
 * \author Geraud L'Eplattenier
 *   
 * \brief This file is the driver for the integrated 3axis gyroscope and 
 * accelerometer LSM330DLC
 * 
 ******************************************************************************/


#ifndef LSM330DLC_H_
#define LSM330DLC_H_

#include <stdint.h>
#include "i2c.hpp"

extern "C" 
{
	#include <stdint.h>
	#include "gyroscope.h"
	#include "accelerometer.h"		
}

/**
 * \brief	Structure containing the accelerometer's data
*/
/*typedef struct
{
	accelerometer_t *raw_accelero;
} lsm_acc_t;
*/
/**
 * \brief	Structure containing the gyroscope's data
*/
/*typedef struct
{
	gyroscope_t *raw_gyro;
} lsm_gyro_t;
*/


class Lsm330dlc 		
{
	public:
		/**
		 * @brief  	Constructor
		 * 
		 * @param 	i2c 	Reference to I2C device 
		 */
		Lsm330dlc(I2c& i2c, accelerometer_t& accel_data, gyroscope_t& gyro_data);

		/**
		 * @brief   Initialise the sensor
		 * @details Sends configuration via I2C, the I2C peripheral must be 
		 * 			activated before this method is called
		 * 			
		 * @return 	true 	Success
		 * @return 	false 	Failed
		 */	
		bool init(void);

		/**
		 * @brief   Main update function
		 * @details Get new data from the sensor
		 * 
		 * @return 	true 	Success
		 * @return 	false 	Failed
		 */
		bool update(void);

	private:
		I2c&				i2c_;
		accelerometer_t& 	accel_data_;
		gyroscope_t& 		gyro_data_;
};

#endif 