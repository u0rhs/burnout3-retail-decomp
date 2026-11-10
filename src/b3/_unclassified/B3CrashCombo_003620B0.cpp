// CB3CrashCombo::UpdateSkids() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): if (((self->field_198 == m) && (self->field_110 != 0)) && (self->field_110->field_4 == v)); s = self->field_1F8;; if (((self->field_198 == m) && (self->field_110 != (0 & 0xFF))) && (self->field_110->field_4 == v))).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003620B0_rec {
    int field_0;
    int field_4;
    int field_8;
    float field_C;
};
struct UnkStruct_003620B0_obj {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
};
struct UnkStruct_003620B0_car {
    unsigned char pad_0[0x204];
    UnkStruct_003620B0_obj * field_204;
};
struct UnkStruct_003620B0 {
    UnkStruct_003620B0_rec field_0[16];
    int field_100;
    int field_104;
    int field_108;
    UnkStruct_003620B0_rec * field_10C;
    UnkStruct_003620B0_rec * field_110;
    UnkStruct_003620B0_rec * field_114;
    unsigned char field_118;
    unsigned char field_119;
    unsigned char pad_11A[0x26];
    CGtV3d field_140;
    unsigned char pad_150[0x48];
    int field_198;
    unsigned char pad_19C[0x44];
    CGtV3d field_1E0;
    unsigned char pad_1F0[0x1];
    unsigned char field_1F1;
    unsigned char field_1F2;
    unsigned char pad_1F3[0x5];
    float field_1F8;
    float field_1FC;
    float field_200;
    float field_204[7];
    int field_220;
    unsigned char pad_224[0x4];
    UnkStruct_003620B0_car * field_228;
    unsigned char pad_22C[0x108];
    int field_334;
};
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0052267C D_0052267C;


static inline XAxisType v278_len(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one, r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r), "=&r"(one) : "r"(l.lVector));
    asm(".set reorder");
    return XAxisType(r);
}
extern "C" void UpdateSkids__13CB3CrashComboFv ( UnkStruct_003620B0 * self );





void UpdateSkids__13CB3CrashComboFv(UnkStruct_003620B0 *self)
{
  if (self->field_1F2 != 0)
  {
    if ((((self->field_119 != 0) || (self->field_1F1 != 0)) || (self->field_198 != self->field_220)) || (self->field_334 != 0))
    {
      self->field_1E0 = self->field_228->field_204->field_30;
      self->field_1F1 = 0;
      self->field_1F2 = 0;
      self->field_1F8 = 0.0f;
    }
    self->field_1FC += D_0052267C.field_0;
    float d = v278_len(self->field_140 - self->field_228->field_204->field_30);
    self->field_204[self->field_198] += d;
    self->field_200 += d;
    self->field_1F8 += d;
    int m = self->field_220;
    int v = 31;
    switch (m)
    {
      case 1:
        v = 15;
        break;

      case 2:
        v = 14;
        break;

      case 3:
        v = 18;
        break;

      case 4:
        v = 17;
        break;

      case 5:
        v = 16;
        break;

      case 6:
        v = 16;
        break;

    }

    float s;
    if ((v != 31) && ((s = self->field_1F8) >= 10.0f))
    {
      s = self->field_1F8;
      if (((self->field_198 == m) && (self->field_110 != (0 & 0xFF))) && (self->field_110->field_4 == v))
      {
        self->field_110->field_C += d;
      }
      else
      {
        UnkStruct_003620B0_rec *e = &self->field_0[self->field_108];
        self->field_100++;
        self->field_108 = (self->field_108 + 1) % 16;
        if (self->field_108 == self->field_104)
        {
          self->field_104 = (self->field_104 + 1) % 16;
        }
        if (self->field_110 == e)
        {
          self->field_110 = 0;
        }
        if (self->field_114 == e)
        {
          self->field_114 = 0;
        }
        self->field_118 = 1;
        self->field_10C = e;
        e->field_0 = 0;
        e->field_4 = v;
        e->field_8 = 0;
        e->field_C = s;
        self->field_110 = self->field_10C;
      }
      self->field_114 = 0;
    }
  }
  else
  {
    self->field_1E0 = self->field_228->field_204->field_30;
  }
  self->field_220 = self->field_198;
}
