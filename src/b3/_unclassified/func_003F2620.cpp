// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): anchor[0].Set(0.5f, 0.5f);; anchor[0].Set(0.5f, 0.5f);).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_003F2620 { unsigned char pad_0[4]; int field_4; int field_8; };
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
struct UnkStruct_D_prof { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_flt { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_flt D_004A55A0, D_004A55A4, D_004A55A8, D_004A55AC;
extern UnkStruct_D_prof D_0051BF9C;
extern UnkStruct_D_gen D_01E88A80, D_01E89800, D_01E894FC, D_01E89518, D_01E8E5D8, D_01E8F940, D_0051BA44, D_01E89788;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_003A6330(void *, int, unsigned long, int, int, int);
extern "C" int func_0013A630(void *, int);
extern "C" int func_00456780(void *, const int *, const CGtV2d *, const CGtV2d *, const CGtV2d *, const CGtV4d *, const CGtV2d *, const CGtV2d *, int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
static inline bool func_003F2620_inl1(UnkStruct_003F2620 *self, int prof)
{
    for (int j = 0; j < 5; j++) {
        if (func_0013A630((void *)(prof), self->field_4 * 5 + j) == 0) return false;
    }
    return true;
}
extern "C" int func_003F2620 ( UnkStruct_003F2620 * self );







// 0x003F2620
int func_003F2620(UnkStruct_003F2620 *self)
{
  float tex[4];
  CGtV2d anchor[4];
  CGtV2d pos[4];
  CGtV2d size[4];
  CGtV4d colour[4];
  CGtV2d uv0[4];
  CGtV2d uv1[4];
  tex[0] = D_004A55A0.field_0;
  tex[1] = D_004A55A4.field_0;
  tex[2] = D_004A55A8.field_0;
  tex[3] = D_004A55AC.field_0;
  anchor[0].Set(0.5f, 0.5f);
  pos[0].Set(48.0f, 160.0f);
  pos[1].Set(48.0f, 208.0f);
  pos[2].Set(48.0f, 256.0f);
  pos[3].Set(48.0f, 304.0f);
  anchor[1].Set(0.5f, 0.5f);
  anchor[2].Set(0.5f, 0.5f);
  anchor[3].Set(0.5f, 0.5f);
  size[0].Set(32.0f, 48.0f);
  size[1].Set(32.0f, 48.0f);
  size[2].Set(32.0f, 48.0f);
  size[3].Set(32.0f, 48.0f);
  colour[0] = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
  colour[1] = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
  colour[2] = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
  colour[3] = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
  uv0[0].Set(0.0f, 0.0f);
  uv0[1].Set(0.0f, 0.0f);
  uv0[2].Set(0.0f, 0.0f);
  uv0[3].Set(0.0f, 0.0f);
  uv1[0].Set(0.25f, 0.5f);
  uv1[1].Set(0.25f, 0.5f);
  uv1[2].Set(0.25f, 0.5f);
  uv1[3].Set(0.25f, 0.5f);
  Prepare__15CB3MenuPageBaseFb(self, false);
  Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
  self->field_4 = 0;
  func_0031ECD0(&D_01E89800, 0, 3);
  Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
  func_00319C80(&D_01E89518, 0x1C7, 0xE);
  func_003A6330(&D_01E8E5D8, 3, 0, -1, 1, 1);
  self->field_8 = 0;
  for (int i = 0; i < 4; i++)
  {
    self->field_4 = i;
    int prof = D_0051BF9C.field_0;
    bool ok = func_003F2620_inl1(self, prof);
    if (!ok)
    {
      colour[i] = CGtV4d(1.0f, 1.0f, 1.0f, 0.0f);
    }
  }

  self->field_4 = 0;
  func_00456780(&D_01E8F940, (const int *) tex, pos, anchor, size, colour, uv0, uv1, 4);
  const unsigned short *s = func_00271A00(&D_0051BA44, 0xC3E);
  Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, s, false, 80.0f);
  return 1;
}
