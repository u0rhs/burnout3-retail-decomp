// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): int i;; for (i = self->field_30; i < (self->field_18 + self->field_30); i++); for (s0 = self->field_30; s0 < (self->field_18 + self->field_30); s0++); self->field_80[i] = 0;; self->field_C0[i] = 0;; self->field_80[s0] = 0;; self->field_C0[s0] = 0;; UnkStruct_0030B9D0_row *e = (UnkStruct_0030B9D0_row).

#include "b3/_unclassified/GtRandom.h"

struct UnkStruct_0030B9D0_self {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x14];
    int field_30;
    unsigned char pad_34[0x4C];
    unsigned long field_80[8];
    int field_C0[16];
};

struct UnkStruct_0030B9D0_row { unsigned char pad_0[0x80]; unsigned long field_80; };
struct UnkStruct_D_00518680 { CGtRandom r; unsigned char pad[0x100]; };
extern UnkStruct_D_00518680 D_00518680;

extern "C" unsigned long func_0030B6E0(UnkStruct_0030B9D0_self *, int);
extern "C" void func_0030B9D0 ( UnkStruct_0030B9D0_self * self , int p1 );






// 0x0030B9D0
void func_0030B9D0(UnkStruct_0030B9D0_self *self, int p1)
{
  int j;
  int s0;
  for (s0 = self->field_30; s0 < (self->field_18 + self->field_30); s0++)
  {
    self->field_80[s0] = 0;
    self->field_C0[s0] = 0;
  }

  for (s0 = self->field_30; s0 < (self->field_18 + self->field_30); s0++)
  {
    ((UnkStruct_0030B9D0_row *) (((char *) self) + (s0 * 8)))->field_80 = func_0030B6E0(self, p1);
    bool done = false;
    unsigned int v = D_00518680.r.Random() % 3;
    int t1 = v;
    UnkStruct_0030B9D0_row *e = (UnkStruct_0030B9D0_row *) (((char *) self) + (s0 * 8));
    while (!done)
    {
      bool found = false;
      for (j = 0; j < s0; j++)
      {
        if ((self->field_80[j] == e->field_80) && (self->field_C0[j] == t1))
        {
          found = true;
          break;
        }
      }

      if (found)
      {
        t1++;
        if (t1 >= 3)
        {
          t1 = 0;
        }
        if (t1 == v)
        {
          break;
        }
      }
      else
      {
        done = true;
      }
    }

    self->field_C0[s0] = t1;
  }

}
