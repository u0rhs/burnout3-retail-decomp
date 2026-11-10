// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): unsigned char new_var;; if (prev != 0); new_var = prev;; if (new_var); self->field_2D0[i - self->field_E80].field_0 = sz;; self->field_2D0[i - self->field_E80].field_0 = sz;).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EGtBuddyPresence {};
class CGtTexture;

class CGtBuddiesPS2DirtySock {
public:
    int GetNumBuddies();
    int GetBuddyName(int, char *);
    int IsBuddyIgnored(char *, bool *);
    int IsWannaBeMyBuddy(char *, bool *);
    int IsWannaBeHisBuddy(char *, bool *);
    int IsTemporaryBuddy(char *, bool *);
    int GetPresence(char *, EGtBuddyPresence *);
    unsigned char pad_0[0x10];
};

struct UnkStruct_003670E0_e0 {
    void * field_0;
    unsigned char pad_4[0x8];
    void * field_C;
    unsigned char pad_10[0x20];
};
struct UnkStruct_003670E0_e1 {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV2d field_10;
    CGtV2d field_18;
    int field_20;
    unsigned char pad_24[0x1C];
};

struct UnkStruct_003670E0 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
    unsigned char pad_11[0xCF];
    UnkStruct_003670E0_e0 field_E0[9];
    unsigned char pad_290[0x40];
    UnkStruct_003670E0_e1 field_2D0[9];
    unsigned char pad_510[0x970];
    int field_E80;
};

struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_UV { CGtV2d uv; unsigned char pad[0x100]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_B D_01E3D4B0;
extern UnkStruct_B D_01E3D45B;
extern UnkStruct_I D_01E3D4A8;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_UV D_01EA4790;
extern UnkStruct_UV D_01EA4798;
extern UnkStruct_I D_01EA4664;
extern UnkStruct_I D_01EA4668;
extern UnkStruct_I D_01EA466C;
extern UnkStruct_I D_01EA4670;
extern UnkStruct_I D_01EA4674;
extern UnkStruct_I D_01EA467C;
extern UnkStruct_I D_01EA4680;

extern "C" void func_00366980(UnkStruct_003670E0 *, int);
extern "C" void func_00284E10(void *);
extern "C" int func_0035F970(void *, char *, bool *);
extern "C" int func_0035F900(void *, char *, bool *);
extern "C" int func_0035F190(void *, char *, int *);
extern "C" void * HLBListGetBuddyByName(int, char *);
extern "C" int HLBMsgListGetTotalCount(void *);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void Update__24CB3BuddyDisplayComponentFf ( UnkStruct_003670E0 * self , float p0 );






void Update__24CB3BuddyDisplayComponentFf(UnkStruct_003670E0 *self, float p0)
{
  unsigned char v0;
  char name[0x10];
  if (D_01E3D4B0.field_0 == 0)
  {
    return;
  }
  unsigned char prev = D_01E3D45B.field_0;
  D_01E3D45B.field_0 = 0;
  v0 = prev;
  if (v0)
  {
    func_00366980(self, 0);
  }
  int i = self->field_E80;
  bool any = false;
  while ((i < D_01E3D390.GetNumBuddies()) && (i < (self->field_E80 + 9)))
  {
    bool b9F;
    bool b9E;
    bool b9D;
    bool b9C;
    bool b9B;
    bool b9A;
    EGtBuddyPresence pres;
    int i90;
    D_01E3D390.GetBuddyName(i, name);
    D_01E3D390.IsBuddyIgnored(name, &b9F);
    D_01E3D390.IsWannaBeMyBuddy(name, &b9E);
    D_01E3D390.IsWannaBeHisBuddy(name, &b9D);
    D_01E3D390.IsTemporaryBuddy(name, &b9C);
    func_0035F970(&D_01E3D390, name, &b9B);
    D_01E3D390.GetPresence(name, &pres);
    func_0035F900(&D_01E3D390, name, &b9A);
    func_0035F190(&D_01E3D390, name, &i90);
    self->field_E0[(i + 1) - self->field_E80].field_0 = (void *) RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    if (i90 != 0)
    {
      self->field_E0[(i + 1) - self->field_E80].field_C = (void *) RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    }
    else
    {
      self->field_E0[(i + 1) - self->field_E80].field_C = 0;
    }
    if (b9B)
    {
      {
CGtV2d sz ( 24.0f , 24.0f ) ;
        self->field_2D0[i - self->field_E80].field_0 = sz;
        self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
        self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
        self->field_2D0[i - self->field_E80].field_20 = D_01EA4680.field_0;
      }
    }
    else
    {
      void *hb = HLBListGetBuddyByName(D_01E3D4A8.field_0, name);
      int cnt = (hb != 0) ? (HLBMsgListGetTotalCount(hb)) : (0);
      if (cnt > 0)
      {
        any = true;
        {
CGtV2d sz ( 24.0f , 24.0f ) ;
          self->field_2D0[i - self->field_E80].field_0 = sz;
CGtV2d an ( 0.0f , 0.5f ) ;
          self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
          self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
          self->field_2D0[i - self->field_E80].field_8 = an;
          self->field_2D0[i - self->field_E80].field_20 = D_01EA4670.field_0;
        }
      }
      else
        if (b9A)
      {
        {
CGtV2d sz ( 24.0f , 24.0f ) ;
          self->field_2D0[i - self->field_E80].field_0 = sz;
          self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
          self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
          self->field_2D0[i - self->field_E80].field_20 = D_01EA466C.field_0;
        }
      }
      else
        if (b9F)
      {
        {
CGtV2d sz ( 24.0f , 24.0f ) ;
          self->field_2D0[i - self->field_E80].field_0 = sz;
          self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
          self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
          self->field_2D0[i - self->field_E80].field_20 = D_01EA4664.field_0;
        }
      }
      else
        if (b9E)
      {
        {
CGtV2d sz ( 24.0f , 24.0f ) ;
          self->field_2D0[i - self->field_E80].field_0 = sz;
          self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
          self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
          self->field_2D0[i - self->field_E80].field_20 = D_01EA4668.field_0;
        }
      }
      else
        if (b9D)
      {
        {
CGtV2d sz ( 24.0f , 24.0f ) ;
          self->field_2D0[i - self->field_E80].field_0 = sz;
          self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
          self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
          self->field_2D0[i - self->field_E80].field_20 = D_01EA4674.field_0;
        }
      }
      else
        if ((pres == 1) && (!b9C))
      {
        {
CGtV2d sz ( 24.0f , 24.0f ) ;
          self->field_2D0[i - self->field_E80].field_0 = sz;
          self->field_2D0[i - self->field_E80].field_10 = D_01EA4790.uv;
          self->field_2D0[i - self->field_E80].field_18 = D_01EA4798.uv;
          self->field_2D0[i - self->field_E80].field_20 = D_01EA467C.field_0;
        }
      }
      else
      {
        self->field_E0[(i + 1) - self->field_E80].field_0 = 0;
      }
    }
    i++;
  }

  if ((self->field_10 == 0) && any)
  {
    func_00284E10(&D_01E7A800);
  }
  self->field_10 = any;
}
