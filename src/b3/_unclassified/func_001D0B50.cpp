// func_001D0B50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): if (self && self); {; }; if (self->field_1568->field_10C0.IsAheadOf(other) != 0); if (((0, self->field_1568->field_10C0)).IsAheadOf(other) != 0)).

#include "b3/GtMath.h"

class CB3Score;

class CB3Score;
struct UnkStruct_001D0B50;
struct UnkStruct_001D0B50_1;
struct UnkStruct_001D0B50_6;
struct UnkStruct_001D0B50_e1;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A0;

class CB3Score {
public:
    int IsAheadOf(CB3Score*);
};

struct UnkStruct_001D0B50_1 {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0xE13];
    int field_27C0;
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  
};

struct UnkStruct_001D0B50_e1 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_001D0B50_e1 field_0[1];  
};

struct UnkStruct_001D0B50_6 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

struct UnkStruct_001D0B50 {
    unsigned char pad_0[0x13F4];
    UnkStruct_001D0B50_1 * field_13F4;
    unsigned char pad_13F8[0x146];
    unsigned char field_153E;
    unsigned char pad_153F[0x15];
    signed char field_1554;
    unsigned char pad_1555[0x3];
    int field_1558;
    float field_155C;
    float field_1560[1];  
    unsigned char pad_1564[0x4];
    UnkStruct_001D0B50_6 * field_1568;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern "C" void func_001D0B50 ( UnkStruct_001D0B50 * self );






// 0x001D0B50
void func_001D0B50(UnkStruct_001D0B50 *self)
{
  UnkStruct_001D0B50_1 *t0 = self->field_13F4;
  if (t0->field_1914 != 0)
  {
    if (D_0064D3A0.field_0 == 1)
    {
      self->field_1554 = 0;
    }
    else
    {
      self->field_1554 = t0->field_19AC % 2;
    }
    char *v5;
    if (D_0064D3A0.field_0 == 0)
    {
      v5 = 0;
    }
    else
    {
      v5 = (((char *) (&D_00522660)) + (self->field_1554 * 0x27D0)) + 0x12AD50;
      if (self && self)
      {
      }
    }
    CB3Score *other = (CB3Score *) (v5 + 0x10C0);
    if (((0, self->field_1568->field_10C0)).IsAheadOf(other) != 0)
    {
      self->field_1558 = 2;
    }
    else
    {
      self->field_1558 = 3;
    }
    int denom = 18000;
    float mm0 = (self->field_1560[self->field_1554] - 1600.0f) / ((float) denom);
    self->field_155C = GtMath::Min(GtMath::Max(mm0, 0.0f), 1.0f);
    if (self->field_1558 == 3)
    {
      self->field_153E = 1;
    }
    else
    {
      self->field_153E = 0;
    }
  }
  else
  {
    self->field_1558 = 1;
    self->field_155C = 0.0f;
    self->field_1554 = self->field_13F4->field_27C0;
    self->field_153E = 0;
    return;
  }
}
