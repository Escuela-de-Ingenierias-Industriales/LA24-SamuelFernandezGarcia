/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PruebaSensores.h
 *
 * Code generated for Simulink model 'PruebaSensores'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Jan  5 22:18:00 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PruebaSensores_h_
#define RTW_HEADER_PruebaSensores_h_
#ifndef PruebaSensores_COMMON_INCLUDES_
#define PruebaSensores_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#endif                                 /* PruebaSensores_COMMON_INCLUDES_ */

#include "PruebaSensores_types.h"
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint128m_T macm;                     /* '<S1>/m a cm' */
  uint128m_T macm1;                    /* '<S1>/m a cm1' */
  uint64m_T Switch1;                   /* '<S1>/Switch1' */
  uint64m_T Switch2;                   /* '<S1>/Switch2' */
} B_PruebaSensores_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Ultra Izquierda' */
  codertarget_arduinobase_inter_T obj_b;/* '<S1>/Ultra Derecha' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S1>/Scope1' */
} DW_PruebaSensores_T;

/* Parameters (default storage) */
struct P_PruebaSensores_T_ {
  real_T UltraDerecha_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S1>/Ultra Derecha'
                                        */
  real_T UltraIzquierda_SampleTime;    /* Expression: -1
                                        * Referenced by: '<S1>/Ultra Izquierda'
                                        */
  real_T Range_Value;                  /* Expression: 0
                                        * Referenced by: '<S1>/Range'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch2'
                                        */
  uint64m_T macm_Gain;                 /* Computed Parameter: macm_Gain
                                        * Referenced by: '<S1>/m a cm'
                                        */
  uint64m_T macm1_Gain;                /* Computed Parameter: macm1_Gain
                                        * Referenced by: '<S1>/m a cm1'
                                        */
  uint32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S1>/Gain4'
                                        */
  uint32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S1>/Gain5'
                                        */
  uint32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  uint32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S1>/Gain3'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PruebaSensores_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PruebaSensores_T PruebaSensores_P;

/* Block signals (default storage) */
extern B_PruebaSensores_T PruebaSensores_B;

/* Block states (default storage) */
extern DW_PruebaSensores_T PruebaSensores_DW;

/* Model entry point functions */
extern void PruebaSensores_initialize(void);
extern void PruebaSensores_step(void);
extern void PruebaSensores_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PruebaSensores_T *const PruebaSensores_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PruebaSensores'
 * '<S1>'   : 'PruebaSensores/Subsystem Reference1'
 */
#endif                                 /* RTW_HEADER_PruebaSensores_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
