// Hand-written; the lifter refused it ([L] CB3World::RenderFrontEnd(int): clone of proven CB3World::Render; 4+4 N140 pads stand in for the YAxisType lane-flip dead slots; int off = idx*4 for the addu order; RELOC constant D_0012AD28 bytes checked equal (L262_bytecmp 0 mismatched)).

// func_00275EF0 -- hand-written (v283); the lifter refused it (vsub.y). Clone of the proven CB3World::Render
// (B3WorldPS2_00276300.cpp): same globals, callees and loops; struct types are placeholders, every type [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00667054 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E85A30 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E85960 { u_long128 field_0; };
struct UnkStruct_Rw_pad { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00667054 D_00667054;
extern UnkStruct_D_01E85A30 D_01E85A30;
extern UnkStruct_D_01E85960 D_01E85960;
extern UnkStruct_Rw_pad D_00665EC0;
extern UnkStruct_Rw_pad D_01E85900;
extern UnkStruct_Rw_pad D_00666330;
extern UnkStruct_Rw_pad gTextureCache;
extern UnkStruct_Rw_pad gVehicleRenderer;
extern UnkStruct_Rw_pad D_01D9D200;
extern UnkStruct_Rw_pad D_01E86D70;
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
extern "C" void func_00222CA0(void *);
extern "C" void func_002622A0(void *, int);
extern "C" void SunOcclusionTest__21CB3EnvironmentManagerFv(void *);
extern "C" void RenderSunCorona__21CB3EnvironmentManagerFv(void *);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void EndCoronaSubmit__17CB3EffectsManagerFv(void *);

extern "C" void RenderFullScreenSpecular__18CB3GraphicsManagerFQ29GtMathPs26CGtV3dfb(void *, CGtV3d, float);
extern "C" void RenderAllBackdrops__14CB3StaticTrackF20EBackdropRenderRangebb(void *, int, bool, bool);
extern "C" void SetupCameraData__18CB3VehicleRendererFv(void *);
extern "C" void BeginVehicleRendering__18CB3VehicleRendererFv(void *);
extern "C" void EndVehicleRendering__18CB3VehicleRendererFv(void *);
extern "C" void Draw__10CB3RaceCarFv(void *);
extern "C" void RenderFrontEndShadow__12CB3ShadowMgrFi(void *, int);

struct UnkStruct_00275EF0_car;

// [G] the race car fields this function sets before each Draw (lane widths only)
struct UnkStruct_00275EF0_car {
    unsigned char pad_0[0x10];
    CGtV3d field_10;
    unsigned char pad_20[0x10];
    CGtV3d field_30;
    unsigned char pad_40[0x1B];
    unsigned char field_5B;
    float field_5C;
    float field_60[8];
};

// N140 frame pads [G]: retail's frame keeps 8 dead 16-byte slots around the specular temporary (4 above, 4 below:
// four caller temporaries and four inline locals -- [L] the four YAxisType lane flips, whose header bodies leave no slot).
struct UnkStruct_00275EF0_pad { int x[4]; UnkStruct_00275EF0_pad() {} ~UnkStruct_00275EF0_pad() {} };
static inline void func_00275EF0_inl1(CGtV3d &v) { UnkStruct_00275EF0_pad p; v.SetY(-v.Y()); }

// 0x00275EF0 -- [L] CB3World::RenderFrontEnd(int) (research/retail_names.csv high; research/proto/new_names.csv
// medium); the asm label is still func_00275EF0. A trimmed copy of CB3World::Render (0x276300).
extern "C" void func_00275EF0(unsigned char *self, int idx)
{
  UnkStruct_00275EF0_pad p0;
  UnkStruct_00275EF0_pad p1;
  UnkStruct_00275EF0_pad p2;
  UnkStruct_00275EF0_pad p3;
  int i;
  OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, 1);
  BeginRender__21CB3EnvironmentManagerFi(&D_01E85900, 0);
  BuildCustomCameraData__18CB3GraphicsManagerFi(&D_00665EC0, idx);
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
  RenderAllBackdrops__14CB3StaticTrackF20EBackdropRenderRangebb(self + 0x12A330, 0, true, true);
  RenderAllBackdrops__14CB3StaticTrackF20EBackdropRenderRangebb(self + 0x12A330, 1, false, true);
  RenderAllBackdrops__14CB3StaticTrackF20EBackdropRenderRangebb(self + 0x12A330, 2, false, true);
  func_00222CA0(&D_00665EC0);
  func_002622A0(&D_01D9D200, 0);
  SetupCameraData__18CB3VehicleRendererFv(&gVehicleRenderer);
  BeginVehicleRendering__18CB3VehicleRendererFv(&gVehicleRenderer);
  if (idx >= 0)
  {
    int off = idx * 4;
    UnkStruct_00275EF0_car *car = *(UnkStruct_00275EF0_car **) ((unsigned char *) (off + (int) self) + 0x12AD28);
    car->field_5B = 1;
    car->field_5C = 0.625f;
    car->field_60[0] = -0.4956515133f;
    car->field_60[1] = -0.1862764955f;
    car->field_60[2] = -0.3000000119f;
    car->field_60[3] = 0.2937499881f;
    car->field_60[4] = 0.1703812927f;
    car->field_60[5] = -0.1570656002f;
    car->field_60[6] = 0.237499997f;
    car->field_60[7] = 0.131249994f;
    func_00275EF0_inl1(car->field_30);
    func_00275EF0_inl1(car->field_10);
    Draw__10CB3RaceCarFv(car);
    car->field_5C = 0.625f;
    car->field_60[0] = 0.4956515133f;
    car->field_60[1] = -0.1862764955f;
    car->field_60[2] = 0.3000000119f;
    car->field_60[3] = 0.2937499881f;
    car->field_60[4] = -0.1703812927f;
    car->field_60[5] = -0.1570656002f;
    car->field_60[6] = -0.237499997f;
    car->field_60[7] = 0.131249994f;
    func_00275EF0_inl1(car->field_30);
    func_00275EF0_inl1(car->field_10);
    Draw__10CB3RaceCarFv(car);
  }
  EndVehicleRendering__18CB3VehicleRendererFv(&gVehicleRenderer);
  EndCoronaSubmit__17CB3EffectsManagerFv(&D_01D9D200);
  RenderAllBackdrops__14CB3StaticTrackF20EBackdropRenderRangebb(self + 0x12A330, 1, true, false);
  RenderFullScreenSpecular__18CB3GraphicsManagerFQ29GtMathPs26CGtV3dfb(&D_00665EC0, CGtV3d(D_01E85960.field_0), *((float *) ((((char *) (&D_01E85900)) + (D_01E85A30.field_0 << 6)) + 0xDC)));
  RenderAllBackdrops__14CB3StaticTrackF20EBackdropRenderRangebb(self + 0x12A330, 2, true, false);
  if (idx >= 0)
  {
    RenderFrontEndShadow__12CB3ShadowMgrFi(&D_01E86D70, idx);
  }
  SunOcclusionTest__21CB3EnvironmentManagerFv(&D_01E85900);
  RenderSunCorona__21CB3EnvironmentManagerFv(&D_01E85900);
  D_01E85A30.field_0 = -1;
  CloseViewport__22CB3GraphicsManagerBaseFv(&D_00665EC0);
}
