/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PruebaSensores.c
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

#include "PruebaSensores.h"
#include "PruebaSensores_types.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PruebaSensores_private.h"

/* Block signals (default storage) */
B_PruebaSensores_T PruebaSensores_B;

/* Block states (default storage) */
DW_PruebaSensores_T PruebaSensores_DW;

/* Real-time model */
static RT_MODEL_PruebaSensores_T PruebaSensores_M_;
RT_MODEL_PruebaSensores_T *const PruebaSensores_M = &PruebaSensores_M_;
void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

void uMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0UL;
    i++;
  }
}

/* Model step function */
void PruebaSensores_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_inter_T *obj;
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  uint32_T tmp;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<S1>/Ultra Izquierda' */
  if (PruebaSensores_DW.obj.SampleTime !=
      PruebaSensores_P.UltraIzquierda_SampleTime) {
    PruebaSensores_DW.obj.SampleTime =
      PruebaSensores_P.UltraIzquierda_SampleTime;
  }

  obj = &PruebaSensores_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (PruebaSensores_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Range'
   */
  if (PruebaSensores_P.Range_Value > PruebaSensores_P.Switch1_Threshold) {
    /* Gain: '<S1>/Gain1' incorporates:
     *  Gain: '<S1>/Gain'
     *  MATLABSystem: '<S1>/Ultra Izquierda'
     */
    tmp = (uint32_T)PruebaSensores_P.Gain_Gain * b_varargout_1;
    uMultiWordMul(&PruebaSensores_P.Gain1_Gain, 1, &tmp, 1, &tmp_0.chunks[0U], 2);
    uMultiWordShr(&tmp_0.chunks[0U], 2, 2U, &PruebaSensores_B.Switch1.chunks[0U],
                  2);
  } else {
    /* Gain: '<S1>/Gain4' incorporates:
     *  Gain: '<S1>/Gain'
     *  MATLABSystem: '<S1>/Ultra Izquierda'
     *  Switch: '<S1>/Switch1'
     */
    tmp = (uint32_T)PruebaSensores_P.Gain_Gain * b_varargout_1;
    uMultiWordMul(&PruebaSensores_P.Gain4_Gain, 1, &tmp, 1,
                  &PruebaSensores_B.Switch1.chunks[0U], 2);
  }

  /* Gain: '<S1>/m a cm' incorporates:
   *  Switch: '<S1>/Switch1'
   */
  tmp_0 = PruebaSensores_P.macm_Gain;
  tmp_1 = PruebaSensores_B.Switch1;
  uMultiWordMul(&PruebaSensores_P.macm_Gain.chunks[0U], 2,
                &PruebaSensores_B.Switch1.chunks[0U], 2,
                &PruebaSensores_B.macm.chunks[0U], 4);

  /* MATLABSystem: '<S1>/Ultra Derecha' */
  if (PruebaSensores_DW.obj_b.SampleTime !=
      PruebaSensores_P.UltraDerecha_SampleTime) {
    PruebaSensores_DW.obj_b.SampleTime =
      PruebaSensores_P.UltraDerecha_SampleTime;
  }

  obj = &PruebaSensores_DW.obj_b;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(68UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (PruebaSensores_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, datatype_id);

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/Range'
   */
  if (PruebaSensores_P.Range_Value > PruebaSensores_P.Switch2_Threshold) {
    /* Gain: '<S1>/Gain3' incorporates:
     *  Gain: '<S1>/Gain2'
     *  MATLABSystem: '<S1>/Ultra Derecha'
     */
    tmp = (uint32_T)PruebaSensores_P.Gain2_Gain * b_varargout_1;
    uMultiWordMul(&PruebaSensores_P.Gain3_Gain, 1, &tmp, 1, &tmp_1.chunks[0U], 2);
    uMultiWordShr(&tmp_1.chunks[0U], 2, 2U, &PruebaSensores_B.Switch2.chunks[0U],
                  2);
  } else {
    /* Gain: '<S1>/Gain5' incorporates:
     *  Gain: '<S1>/Gain2'
     *  MATLABSystem: '<S1>/Ultra Derecha'
     */
    tmp = (uint32_T)PruebaSensores_P.Gain2_Gain * b_varargout_1;
    uMultiWordMul(&PruebaSensores_P.Gain5_Gain, 1, &tmp, 1, &tmp_0.chunks[0U], 2);

    /* Switch: '<S1>/Switch2' incorporates:
     *  Gain: '<S1>/Gain5'
     *  Switch: '<S1>/Switch1'
     */
    PruebaSensores_B.Switch2 = tmp_0;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Gain: '<S1>/m a cm1' incorporates:
   *  Switch: '<S1>/Switch2'
   */
  uMultiWordMul(&PruebaSensores_P.macm1_Gain.chunks[0U], 2,
                &PruebaSensores_B.Switch2.chunks[0U], 2,
                &PruebaSensores_B.macm1.chunks[0U], 4);

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PruebaSensores_M->Timing.taskTime0 =
    ((time_T)(++PruebaSensores_M->Timing.clockTick0)) *
    PruebaSensores_M->Timing.stepSize0;
}

/* Model initialize function */
void PruebaSensores_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PruebaSensores_M, -1);
  PruebaSensores_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  PruebaSensores_M->Sizes.checksums[0] = (8814690U);
  PruebaSensores_M->Sizes.checksums[1] = (3580597377U);
  PruebaSensores_M->Sizes.checksums[2] = (2926833524U);
  PruebaSensores_M->Sizes.checksums[3] = (300188851U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    PruebaSensores_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PruebaSensores_M->extModeInfo,
      &PruebaSensores_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PruebaSensores_M->extModeInfo,
                        PruebaSensores_M->Sizes.checksums);
    rteiSetTPtr(PruebaSensores_M->extModeInfo, rtmGetTPtr(PruebaSensores_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<S1>/Ultra Izquierda' */
    PruebaSensores_DW.obj.matlabCodegenIsDeleted = false;
    PruebaSensores_DW.obj.SampleTime =
      PruebaSensores_P.UltraIzquierda_SampleTime;
    obj = &PruebaSensores_DW.obj;
    PruebaSensores_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(69UL);
    PruebaSensores_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Ultra Derecha' */
    PruebaSensores_DW.obj_b.matlabCodegenIsDeleted = false;
    PruebaSensores_DW.obj_b.SampleTime =
      PruebaSensores_P.UltraDerecha_SampleTime;
    obj = &PruebaSensores_DW.obj_b;
    PruebaSensores_DW.obj_b.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(68UL);
    PruebaSensores_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void PruebaSensores_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Ultra Izquierda' */
  obj = &PruebaSensores_DW.obj;
  if (!PruebaSensores_DW.obj.matlabCodegenIsDeleted) {
    PruebaSensores_DW.obj.matlabCodegenIsDeleted = true;
    if ((PruebaSensores_DW.obj.isInitialized == 1L) &&
        PruebaSensores_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
      MW_AnalogIn_Close
        (PruebaSensores_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Ultra Izquierda' */
  /* Terminate for MATLABSystem: '<S1>/Ultra Derecha' */
  obj = &PruebaSensores_DW.obj_b;
  if (!PruebaSensores_DW.obj_b.matlabCodegenIsDeleted) {
    PruebaSensores_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((PruebaSensores_DW.obj_b.isInitialized == 1L) &&
        PruebaSensores_DW.obj_b.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(68UL);
      MW_AnalogIn_Close
        (PruebaSensores_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Ultra Derecha' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
