/*
 * conf_imu_rev3.h
 *
 * Created: 20/11/2013 22:20:48
 *  Author: sfx
 */ 


#ifndef CONF_IMU_REV3_H_
#define CONF_IMU_REV3_H_


#define RAW_GYRO_X 1
#define RAW_GYRO_Y 0
#define RAW_GYRO_Z 2

#define RAW_GYRO_X_SCALE   12600.0f
#define RAW_GYRO_Y_SCALE  -12600.0f
#define RAW_GYRO_Z_SCALE   12600.0f

#define RAW_ACC_X 0
#define RAW_ACC_Y 1
#define RAW_ACC_Z 2

//#define RAW_ACC_X_SCALE  261.5f
//#define RAW_ACC_Y_SCALE  262.5f
//#define RAW_ACC_Z_SCALE  255.0f
//#define RAW_ACC_X_SCALE  259.67f
//#define RAW_ACC_Y_SCALE  261.324f
//#define RAW_ACC_Z_SCALE  256.724f
// Felix outside
//#define RAW_ACC_X_SCALE  264.9173f
#define RAW_ACC_X_SCALE  258.9173f
#define RAW_ACC_Y_SCALE  258.9853f
#define RAW_ACC_Z_SCALE  258.0829f

#define RAW_COMPASS_X 2
#define RAW_COMPASS_Y 0
#define RAW_COMPASS_Z 1

// Inside values
//#define RAW_MAG_X_SCALE 579.41f
//#define RAW_MAG_Y_SCALE 540.3f
//#define RAW_MAG_Z_SCALE 525.59f

// Outside values
//#define RAW_MAG_X_SCALE 534.90f
//#define RAW_MAG_Y_SCALE 514.85f
//#define RAW_MAG_Z_SCALE 478.57f

// Felix Outside values
#define RAW_MAG_X_SCALE 530.2771f
#define RAW_MAG_Y_SCALE 525.2934f
#define RAW_MAG_Z_SCALE 498.4476f

#define ACC_BIAIS_X 18.0f
#define ACC_BIAIS_Y 9.0f
#define ACC_BIAIS_Z -16.0f
 
//#define ACC_BIAIS_X 4.685f
//#define ACC_BIAIS_Y 4.376f
//#define ACC_BIAIS_Z -16.26f

// Felix Outside values
// #define ACC_BIAIS_X  21.5871f
// #define ACC_BIAIS_Y  10.0884f
// #define ACC_BIAIS_Z  -14.9891f


// Inside values
//#define MAG_BIAIS_X 34.20f
//#define MAG_BIAIS_Y -47.07f
//#define MAG_BIAIS_Z -76.93f

// Outside values
//#define MAG_BIAIS_X 47.62f
//#define MAG_BIAIS_Y -47.29f
//#define MAG_BIAIS_Z -74.38f

// Felix Outside values
#define MAG_BIAIS_X  131.7582f
#define MAG_BIAIS_Y -26.1298f
#define MAG_BIAIS_Z  61.1646f





#endif /* CONF_IMU_REV3_H_ */