// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): inline CGt2dObject *inline_fn(CGt2dObject **arg0); {; return *arg0;; }; func_003D0710(*(po = &self->field_48[i]), dpc_CGtV2d(320.0f, y), dpc_CGtV2d(0.5f, 1.0f), mgr->field_110, 1, 1, 0, D_00665ED0.pFont, 36.0f, 3.402823466e+38f, text[i], 0);; dpr_CGtV2d sz = (*po)->mObjectSpace.mSize;; func_003D0710).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_0039C570_row { CGt2dObject * field_0[5]; };
struct UnkStruct_0039C570 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_0039C570_row field_C[3];
    CGt2dObject * field_48[2];
    CGt2dObject * field_50;
    unsigned char pad_54[0xC];
    CGt2dFrame * field_60;
    int field_64;
    unsigned char field_68;
};
struct UnkStruct_D_00665ED0 { CGt2dFont * pFont; unsigned char pad[0x100]; };
struct UnkStruct_D_0064E470 { unsigned char pad_0[0x7C]; float * field_7C; int * field_80; };
struct UnkStruct_0039C570_vt {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual int vfunc_A4();
};
struct UnkStruct_D_0051BA88_x { unsigned char pad_0[0x1B4]; UnkStruct_0039C570_vt * field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_D_0051BA88_x * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00648704_x { unsigned char pad_0[0x3AC]; int field_3AC; };
struct UnkStruct_D_00648704 { UnkStruct_D_00648704_x * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0064E470 D_0064E470;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_00648704 D_00648704;
extern UnkStruct_D_Byte16 D_0051BA39, D_01E65499;
extern UnkStruct_D_Pad16 D_01E90438, D_0051BA44, D_006481A0, D_01E90220;
extern unsigned short D_0064ED24[];
extern unsigned short D_004C9AA0[];
extern unsigned short D_004C9AC0[];
extern const int D_004C9A88[];
extern const signed char D_004C9A68[];

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void func_0039D110(UnkStruct_0039C570 *, int, unsigned short *, unsigned short *, int);
extern "C" void func_0039C1C0(UnkStruct_0039C570 *, unsigned short *, unsigned short **, unsigned short **);
extern "C" unsigned short * func_003B8550(void *, float);
extern "C" void func_003B8840(unsigned short *, int);
extern "C" void func_0014E7E0(void *, int *, int *, int *);
extern "C" void *func_001A3AA0(unsigned short *, unsigned short *, const int *);
extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
extern "C" void func_0039D530(unsigned short *, unsigned short *, void *);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, CGt2dFont *font, float size, float d, unsigned short *text, int e);
extern "C" int func_0039C570 ( UnkStruct_0039C570 * self , int mode );













inline CGt2dObject *func_0039C570_inl1(CGt2dObject **arg0)
{
  return *arg0;
}

// 0x0039C570
int func_0039C570(UnkStruct_0039C570 *self, int mode)
{
  int i;
  unsigned short *text[2];
  int vals[3];
  int score;
  Prepare__20CB3MenuComponentBaseFv(self);
  CGt2dScene * const scene = &D_01E903E0;
  int layer = self->field_8 + 2;
  CB3MenuPageManager * const mgr = &D_01E90240;
  UnkStruct_D_Pad16 * const sb = &D_01E90438;
  unsigned short *str;
  bool big = false;
  CGt2dFrame *root = scene->field_14;
  self->field_68 = 0;
  self->field_60 = root->ConstructChild();
  self->field_60->field_0.SetIdentity();
  switch (mode)
  {
    default:

    case 0:
      self->field_64 = 3;
      for (i = 0; i < self->field_64; i++)
    {
      unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 10);
      PrintInt__10CGtUnicodeFPUsii(s, i + 1, 0, 0);
      func_0039D110(self, i, s, func_00271A00(&D_0051BA44, D_004C9A88[i]), 0);
    }

      func_0039C1C0(self, func_00271A00(&D_0051BA44, 0x976), &text[0], &text[1]);
      str = 0;
      break;

    case 3:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x979);
      text[1] = func_00271A00(&D_0051BA44, 0x97A);
      str = 0;
      break;

    case 4:
      self->field_64 = 3;
      for (i = 0; i < self->field_64; i++)
    {
      unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 10);
      PrintInt__10CGtUnicodeFPUsii(s, i + 1, 0, 0);
      func_0039D110(self, i, s, func_00271A00(&D_0051BA44, D_004C9A88[i]), 0);
    }

      text[0] = func_00271A00(&D_0051BA44, 0x97D);
      text[1] = func_00271A00(&D_0051BA44, 0x97E);
      str = 0;
      break;

    case 5:
      self->field_64 = 3;
      for (i = 0; i < self->field_64; i++)
    {
      unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 10);
      PrintInt__10CGtUnicodeFPUsii(s, i + 1, 0, 0);
      func_0039D110(self, i, s, func_00271A00(&D_0051BA44, D_004C9A88[i]), 0);
    }

      text[0] = func_00271A00(&D_0051BA44, 0x97F);
      text[1] = func_00271A00(&D_0051BA44, 0x980);
      str = 0;
      break;

    case 2:
    {
      UnkStruct_D_0064E470 * const d = &D_0064E470;
      self->field_64 = 3;
      for (i = 0; i < self->field_64; i++)
      {
        unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 10);
        PrintInt__10CGtUnicodeFPUsii(s, d->field_80[D_004C9A68[i]], 0, 0);
        func_0039D110(self, i, s, func_00271A00(&D_0051BA44, 0xC39), 1);
      }

      func_0039C1C0(self, func_00271A00(&D_0051BA44, 0x978), &text[0], &text[1]);
      str = 0;
      break;
    }

    case 1:
    {
      UnkStruct_D_0064E470 * const d = &D_0064E470;
      self->field_64 = 3;
      for (i = 0; i < self->field_64; i++)
      {
        unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 10);
        s = func_003B8550(sb, d->field_7C[D_004C9A68[i]]);
        func_0039D110(self, i, s, D_004C9AA0, 0);
      }

      func_0039C1C0(self, func_00271A00(&D_0051BA44, 0x977), &text[0], &text[1]);
      str = 0;
      break;
    }

    case 6:
      func_0014E7E0(&D_006481A0, &vals[2], &vals[1], &vals[0]);
      D_0051BA88.field_0->field_1B4->vfunc_A4();
      score = D_00648704.field_0->field_3AC;
      self->field_64 = 3;
      for (i = 0; i < self->field_64; i++)
    {
      unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 10);
      func_003B8840(s, vals[i]);
      func_0039D110(self, i, s, D_004C9AC0, 0);
    }

      text[0] = func_00271A00(&D_0051BA44, 0x981);
      text[1] = func_00271A00(&D_0051BA44, 0x982);
      str = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x14);
      func_001A3AA0(str, func_00271A00(&D_0051BA44, 0xC38), &score);
      break;

    case 7:

    case 11:

    case 16:
      func_0039C1C0(self, func_00271A00(&D_0051BA44, 0x976), &text[0], &text[1]);
      self->field_64 = 0;
      str = 0;
      break;

    case 9:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x985);
      text[1] = func_00271A00(&D_0051BA44, 0x986);
      str = 0;
      break;

    case 12:
    {
      unsigned short *fmt = func_00271A00(&D_0051BA44, 0xC30);
      unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, Length__10CGtUnicodeFPCUs(fmt) + 4);
      self->field_64 = 0;
      func_0039D530(s, fmt, &D_01E90220);
      func_0039C1C0(self, s, &text[0], &text[1]);
      str = 0;
      break;
    }

    case 17:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x98F);
      text[1] = func_00271A00(&D_0051BA44, 0x990);
      str = 0;
      break;

    case 8:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x983);
      text[1] = func_00271A00(&D_0051BA44, 0x984);
      str = 0;
      break;

    case 10:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x987);
      text[1] = func_00271A00(&D_0051BA44, 0x988);
      score = D_00648704.field_0->field_3AC;
      str = AllocUTF16String__19CB3MenuStringBufferFi(sb, 0x14);
      func_001A3AA0(str, func_00271A00(&D_0051BA44, 0xC38), &score);
      big = true;
      break;

    case 13:

    case 18:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x989);
      text[1] = func_00271A00(&D_0051BA44, 0x98A);
      score = D_00648704.field_0->field_3AC;
      str = AllocUTF16String__19CB3MenuStringBufferFi(sb, 0x14);
      func_001A3AA0(str, func_00271A00(&D_0051BA44, 0xC38), &score);
      big = true;
      break;

    case 14:

    case 19:
      self->field_64 = 0;
      text[0] = func_00271A00(&D_0051BA44, 0x98B);
      text[1] = func_00271A00(&D_0051BA44, 0x98C);
      score = D_00648704.field_0->field_3AC;
      str = AllocUTF16String__19CB3MenuStringBufferFi(sb, 0x14);
      func_001A3AA0(str, func_00271A00(&D_0051BA44, 0xC38), &score);
      big = true;
      break;

    case 15:

    case 20:
    {
      self->field_64 = 0;
      int c = D_0051BA39.field_0;
      if (D_01E65499.field_0 != 0)
      {
        D_0051BA88.field_0->field_1B4->vfunc_A4();
        score = D_00648704.field_0->field_3AC;
        text[0] = D_0064ED24;
      }
      else
      {
        int id;
        if (D_0051BA88.field_0->field_1B4->vfunc_A4())
        {
          score = D_00648704.field_0->field_3AC;
          id = c + 0x257;
        }
        else
        {
          score = D_00648704.field_0->field_3AC;
          id = c + 0x309;
        }
        text[0] = func_00271A00(&D_0051BA44, id);
      }
      text[1] = func_00271A00(&D_0051BA44, 0x4BA);
      str = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x14);
      func_001A3AA0(str, func_00271A00(&D_0051BA44, 0xC38), &score);
      big = true;
      break;
    }

  }

  for (i = 0; i < 2; i++)
  {
    if ((text[i] != 0) && ((*text[i]) != 0))
    {
      *((CGt2dObject **) ((((char *) self) + (i * 4)) + 0x48)) = scene->ConstructObject(layer, self->field_60);
      CGt2dObject **po;
      float y;
      if (self->field_64 > 0)
      {
        y = (0.0f + 140.0f) + (36.0f * ((float) i));
      }
      else
      {
        y = 80.0f + ((0.0f + 140.0f) + (36.0f * ((float) i)));
      }
      func_003D0710(func_0039C570_inl1(po = &self->field_48[i]), CGtV2d(320.0f, y), CGtV2d(0.5f, 1.0f), mgr->field_110, 1, 1, 0, D_00665ED0.pFont, 36.0f, 3.402823466e+38f, text[i], 0);
      CGtV2d & sz = func_0039C570_inl1(po)->mObjectSpace.mSize;
      CGtV2d size = sz;
      if (size.marValues[0] > 580.0f)
      {
        float s = 580.0f / size.marValues[0];
        size *= s;
        sz = size;
        func_0039C570_inl1(po)->mObjectSpace.mTopLeftPos = CGtV2d(320.0f, y) - (size * CGtV2d(0.5f, 1.0f));
      }
    }
  }

  if (str != 0)
  {
    self->field_50 = scene->ConstructObject(layer, self->field_60);
    CGtV2d pos;
    if (big)
    {
      pos.Set(320.0f, 360.0f);
    }
    else
    {
      pos.Set(320.0f, 400.0f);
    }
    func_003D0710(self->field_50, pos, CGtV2d(0.5f, 1.0f), mgr->field_110, 1, 1, 0, D_00665ED0.pFont, 36.0f, 3.402823466e+38f, str, 0);
  }
  return 1;
}
