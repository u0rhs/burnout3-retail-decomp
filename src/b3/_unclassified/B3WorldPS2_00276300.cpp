// CB3World::Render(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3WorldPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): u_long128 *t1 = (u_long128 *) farFogPlane.field_0;; u_long128 *t1 = (u_long128 *) farFogPlane.field_0;).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_Rw_gp { u_long128 field_0; u_long128 field_10; };
struct UnkStruct_farFogPlane { UnkStruct_Rw_gp * field_0; };
struct UnkStruct_Rw_obj {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual bool vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4();
    virtual void vfunc_B8(); virtual void vfunc_BC(); virtual void vfunc_C0(); virtual bool vfunc_C4();
};
struct UnkStruct_Rw_g88 {
    unsigned char pad_0[0x1B4];
    UnkStruct_Rw_obj * field_1B4;
};
struct UnkStruct_D_0051BA88 { UnkStruct_Rw_g88 * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Rw_cam { unsigned char pad_0[0x18EA]; unsigned char field_18EA; unsigned char pad_18EB[0xC1]; signed char field_19AC; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00667054 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00666274 { char * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA94 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00645170 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665F1C { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E85A30 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E85960 { u_long128 field_0; };
struct UnkStruct_Rw_pad { unsigned char pad_0[0x10]; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00667054 D_00667054;
extern UnkStruct_D_00666274 D_00666274;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_00665F1C D_00665F1C;
extern UnkStruct_D_01E85A30 D_01E85A30;
extern UnkStruct_D_01E85960 D_01E85960;
extern UnkStruct_Rw_pad D_00665EC0;
extern UnkStruct_Rw_pad D_01E85900;
extern UnkStruct_Rw_pad D_00666330;
extern UnkStruct_Rw_pad gTextureCache;
extern UnkStruct_Rw_pad gVehicleRenderer;
extern UnkStruct_Rw_pad D_01D9D200;
extern UnkStruct_Rw_pad D_004EB1E0;
extern UnkStruct_Rw_pad D_004EE040;
extern UnkStruct_Rw_pad D_01E86D70;
extern unsigned char D_0055EF70[];
extern unsigned char D_005179E6[];
extern "C" void func_00301D50(void *);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void BeginRender__21CB3EnvironmentManagerFi(void *, int);
extern "C" void BuildCustomCameraData__18CB3GraphicsManagerFi(void *, int);
extern "C" void func_00220450(void *);
extern "C" void ClearOffscreenBuffer__18CB3GraphicsManagerFUi(void *, unsigned int);
extern "C" void RenderBackdropTexture__21CB3EnvironmentManagerFv(void *);
extern "C" void RenderSky__21CB3EnvironmentManagerFv(void *);
extern "C" void RenderSunBlob__21CB3EnvironmentManagerFv(void *);
extern "C" void RenderClouds__21CB3EnvironmentManagerFv(void *);
extern "C" void BuildEnvmapSunCoronaData__21CB3EnvironmentManagerFv(void *);
extern "C" void SendRegistersToGS__13CB3CameraDataCFv(void *);
extern "C" void RenderSkyToEnvironmentMap__21CB3EnvironmentManagerFv(void *);
extern "C" void RenderSunToEnvironmentMap__21CB3EnvironmentManagerFv(void *);
extern "C" void ForceBufferSwap__15CGtTextureCacheFv(void *);
extern "C" void RenderBeforeVehicles__16CB3StreamedTrackFv(void *);
extern "C" void func_00222CA0(void *);
extern "C" void func_002622A0(void *, int);
extern "C" void Draw__16CB3TrafficSystemFi(void *, int);
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);
extern "C" bool func_00131E40(void *);
extern "C" bool func_00131CA0(void *);
extern "C" void func_003CC6E0(void *, int);
extern "C" void Draw__15CB3RacePositionFi(void *, int);
extern "C" void DrawTrafficValues__15CB3RacePositionFv(void *);
extern "C" void Render__15CB3WrongWayWallFv(void *);
extern "C" void RenderWorld__15CB3DebugManagerFv(void *);
extern "C" void SunOcclusionTest__21CB3EnvironmentManagerFv(void *);
extern "C" void Render__8CB3BloomFbb(void *, bool, unsigned char);
extern "C" void RenderSunCorona__21CB3EnvironmentManagerFv(void *);
extern "C" bool UpdateCamera__22CB3DirectionalBlurBaseFi(void *, int);
extern "C" void Render__13CB3RadialBlurFv(void *);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void RenderRaceCars__8CB3WorldFii(void *, int, int);
extern "C" void EndCoronaSubmit__17CB3EffectsManagerFv(void *);
extern "C" void RenderAfterVehicles__16CB3StreamedTrackFv(void *);
extern "C" void RenderFullScreenSpecular__18CB3GraphicsManagerFQ29GtMathPs26CGtV3dfb(void *, const void *, float);
extern "C" void RenderAfterSpecular__16CB3StreamedTrackFv(void *);
extern "C" void RenderShadows__12CB3ShadowMgrFi(void *, int);
extern "C" void RenderPreFogEffects__17CB3EffectsManagerFi(void *, int);
extern "C" void Render__6CB3FogFQ29GtMathPs26CGtV3dff(void *, float, float);
extern "C" void Draw__11CB3GameDataFi(void *, int);
extern "C" void func_0021C010(void *);
extern "C" void RenderPostFogEffects__17CB3EffectsManagerFi(void *, int);
extern "C" void Render__18CB3DirectionalBlurFv(void *);
extern "C" void Render__8CB3WorldFi ( unsigned char * self , int idx );






void Render__8CB3WorldFi(unsigned char *self, int idx)
{
  UnkStruct_Rw_cam *cam;
  int i;
  unsigned char *trk;
  cam = (UnkStruct_Rw_cam *) ((self + (idx * 0x27D0)) + 0x12AD50);
  trk = (self + (idx * 0x1CC)) + 0x12A348;
  func_00301D50(trk);
  OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, idx + 1);
  BeginRender__21CB3EnvironmentManagerFi(&D_01E85900, idx);
  BuildCustomCameraData__18CB3GraphicsManagerFi(&D_00665EC0, cam->field_19AC);
  D_00667050.field_0 = 0;
  func_00220450(&gVehicleRenderer);
  ClearOffscreenBuffer__18CB3GraphicsManagerFUi(&D_00665EC0, 3);
  RenderBackdropTexture__21CB3EnvironmentManagerFv(&D_01E85900);
  RenderSky__21CB3EnvironmentManagerFv(&D_01E85900);
  RenderSunBlob__21CB3EnvironmentManagerFv(&D_01E85900);
  RenderClouds__21CB3EnvironmentManagerFv(&D_01E85900);
  BuildEnvmapSunCoronaData__21CB3EnvironmentManagerFv(&D_01E85900);
  for (i = 1; i < D_00667054.field_0; i++)
  {
    D_00667050.field_0 = i;
    SendRegistersToGS__13CB3CameraDataCFv((((char *) (&D_00665EC0)) + (i * 0x230)) + 0x470);
    RenderSkyToEnvironmentMap__21CB3EnvironmentManagerFv(&D_01E85900);
  }

  for (i = 1; i < D_00667054.field_0; i++)
  {
    D_00667050.field_0 = i;
    SendRegistersToGS__13CB3CameraDataCFv((((char *) (&D_00665EC0)) + (i * 0x230)) + 0x470);
    RenderSunToEnvironmentMap__21CB3EnvironmentManagerFv(&D_01E85900);
  }

  D_00667050.field_0 = 0;
  SendRegistersToGS__13CB3CameraDataCFv(&D_00666330);
  ForceBufferSwap__15CGtTextureCacheFv(&gTextureCache);
  RenderBeforeVehicles__16CB3StreamedTrackFv(trk);
  func_00222CA0(&D_00665EC0);
  func_002622A0(&D_01D9D200, idx);
  if ((*((self + (idx * 0x1CC)) + 0x12A38C)) != 0)
  {
    Draw__16CB3TrafficSystemFi(self + 0x4DE0, idx);
  }
  RenderRaceCars__8CB3WorldFii(self, idx, idx);
  EndCoronaSubmit__17CB3EffectsManagerFv(&D_01D9D200);
  RenderAfterVehicles__16CB3StreamedTrackFv(trk);
  {
    u_long128 spec = D_01E85960.field_0;
    RenderFullScreenSpecular__18CB3GraphicsManagerFQ29GtMathPs26CGtV3dfb(&D_00665EC0, &spec, *((float *) ((((char *) (&D_01E85900)) + (D_01E85A30.field_0 << 6)) + 0xDC)));
  }
  RenderAfterSpecular__16CB3StreamedTrackFv(trk);
  RenderShadows__12CB3ShadowMgrFi(&D_01E86D70, idx);
  RenderPreFogEffects__17CB3EffectsManagerFi(&D_01D9D200, idx);
  {
    char *fe = ((char *) (&D_01E85900)) + (D_01E85A30.field_0 << 6);
    Render__6CB3FogFQ29GtMathPs26CGtV3dff(fe + 0xC0, *((float *) (fe + 0xD4)), *((float *) (fe + 0xD8)));
  }
  Draw__11CB3GameDataFi(self + 0x125B40, idx);
  func_0021C010(trk);
  RenderPostFogEffects__17CB3EffectsManagerFi(&D_01D9D200, idx);
  if ((*(self + 0x1437F3)) == 0)
  {
    if (D_00665F1C.field_0 != 0)
    {
      _rwDMAOpenVIFPkt(0x80000000, 2);
      const unsigned long c = 0x1000000000008001;
      u_long128 q2;
asm ( "pcpyld %0, %2, %1" : "=r" ( q2 ) : "r" ( c ) , "r" ( 14 ) ) ;
      u_long128 q3;
      u_long128 *t1 = (u_long128 *) farFogPlane.field_0;
asm ( "pcpyld %0, %2, %1" : "=r" ( q3 ) : "r" ( 0x50003 ) , "r" ( 71 ) ) ;
      t1[0] = q2;
      t1[1] = q3;
      farFogPlane.field_0++;
      if (func_00131E40(&D_004EE040))
      {
        func_003CC6E0(self + 0x12A7E0, idx);
      }
      else
      {
        Draw__15CB3RacePositionFi(self + 0x1260D0, idx);
      }
    }
  }
  {
    UnkStruct_Rw_obj *o = D_0051BA88.field_0->field_1B4;
    if ((o != 0) && o->vfunc_C4())
    {
      DrawTrafficValues__15CB3RacePositionFv(self + 0x1260D0);
    }
  }
  {
    char *w;
    if (idx < D_00645170.field_0)
    {
      w = (((char *) D_0055EF70) + (idx * 0x4590)) + 0x1CB80;
    }
    else
    {
      w = 0;
    }
    if (w != 0)
    {
      Render__15CB3WrongWayWallFv(w + 0x1590);
    }
  }
  RenderWorld__15CB3DebugManagerFv(&D_004EB1E0);
  SunOcclusionTest__21CB3EnvironmentManagerFv(&D_01E85900);
  Render__8CB3BloomFbb(D_00666274.field_0 + 0x50, D_0051BA94.field_0 != (-1), D_005179E6[idx * 0xBB0]);
  RenderSunCorona__21CB3EnvironmentManagerFv(&D_01E85900);
  if (UpdateCamera__22CB3DirectionalBlurBaseFi(D_00666274.field_0 + 0x60, idx))
  {
    if (((!func_00131CA0(&D_004EE040)) || (!func_00131E40(&D_004EE040))) || D_0051BA88.field_0->field_1B4->vfunc_AC())
    {
      Render__18CB3DirectionalBlurFv(D_00666274.field_0 + 0x60);
    }
  }
  else
    if (cam->field_18EA == 0)
  {
    Render__13CB3RadialBlurFv(D_00666274.field_0);
  }
  D_01E85A30.field_0 = -1;
  CloseViewport__22CB3GraphicsManagerBaseFv(&D_00665EC0);
}
