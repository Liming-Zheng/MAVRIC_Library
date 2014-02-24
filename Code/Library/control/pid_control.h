/*
 * pid_control.h
 *
 *  Created on: Mar 7, 2010
 *      Author: felix
 */

#ifndef PID_CONTROL_H_
#define PID_CONTROL_H_
#include "compiler.h"
#include <math.h>

typedef struct {
	float pregain, postgain;
	float accumulator;
	float clip;
	float leakiness;
} Integrator_t;

typedef struct {
	float gain;
	float previous;
	float LPF;
	float clip;
} Differentiator_t;

typedef struct {
	float p_gain;
	float clip_min, clip_max;
	Integrator_t integrator;
	Differentiator_t differentiator;
	float output;
	float error;
	uint32_t last_update; // last update time in timer tick
	float dt;  // is updated from system time at each update.
	float soft_zone_width;  // approximate width of a "soft zone" on the error input, i.e. a region of low gain around the target point. Value 0 -> switched off
}PID_Controller_t;

PID_Controller_t passthroughController(void);

void initInt(Integrator_t *integrator, float pregain, float postgain, float clip_val);

void resetInt(Integrator_t *integrator);

void initDiff(Differentiator_t *diff, float gain, float LPF, float clip_val);

float integrate(Integrator_t *integrator, float input, float dt);

float differentiate(Differentiator_t *diff, float input,  float dt);

float pid_update(PID_Controller_t* controller, float error);

float pid_update_dt(PID_Controller_t* controller, float error, float dt);


#endif /* PID_CONTROL_H_ */
