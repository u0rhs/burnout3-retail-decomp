// func_00438FB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): UnkStruct_00438FB0b *new_var;; self->field_48 = 0;; new_var = self;; new_var->field_48 = 0;; if (self->field_40 != s->field_8); if (new_var->field_40 != s->field_8); if (self->field_40 == 0); if (new_var->field_40 == 0)).

#include "b3/GtMath.h"

struct UnkStruct_00438FB0;
struct UnkStruct_00438FB0_2;
struct UnkStruct_D_004F50A0;

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  
};

struct UnkStruct_00438FB0_2 {
    unsigned char pad_0[0x24];
    int field_24;
    int field_28;
    int field_2C;
    float field_30;
};

struct UnkStruct_00438FB0 {
    unsigned char pad_0[0x34];
    UnkStruct_00438FB0_2 * field_34;
    float field_38;
    float field_3C;
    int field_40;
    int field_44;
    int field_48;
};

extern UnkStruct_D_004F50A0 D_004F50A0;

struct UnkStruct_00438FB0_3 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    float field_10;
};

struct UnkStruct_00438FB0_2b {
    unsigned char pad_0[0x20];
    UnkStruct_00438FB0_3 field_20;
};

struct UnkStruct_00438FB0b {
    unsigned char pad_0[0x34];
    UnkStruct_00438FB0_2b * field_34;
    float field_38;
    float field_3C;
    int field_40;
    int field_44;
    int field_48;
};
extern "C" void func_00438FB0 ( UnkStruct_00438FB0b * self );





// 0x00438FB0
void func_00438FB0(UnkStruct_00438FB0b *self)
{
  // [C] v0 was uninitialised when field_3C > 0 (UB): retail keeps v0 in self's register, i.e. v0 == self (same object bytes
  // with this initialiser, tiny_compile + obj_same); natively locals zero-init, v0 was null and the port crashed (port lane play1).
  UnkStruct_00438FB0b *v0 = self;
  UnkStruct_00438FB0_3 *s = &self->field_34->field_20;
  float dt = GtMath::Max(D_004F50A0.field_0 - self->field_38, 0.0f);
  self->field_38 = D_004F50A0.field_0;
  self->field_3C -= dt;
  if (self->field_3C <= 0.0f)
  {
    self->field_40 = 0;
    self->field_44 = 0;
    v0 = self;
    v0->field_48 = 0;
  }
  if (v0->field_40 != s->field_8)
  {
    if (v0->field_40 == 0)
    {
      s->field_10 -= dt;
      if (s->field_10 < 0.0f)
      {
        s->field_8 = 0;
        s->field_4 = 0;
        s->field_C = 0;
        s->field_10 = 0.0f;
      }
    }
    else
    {
      if (!(s->field_10 <= 0.5625f))
      {
        s->field_10 -= dt;
        if (s->field_10 < 0.5625f)
        {
          s->field_10 = 0.5625f;
        }
      }
      if (s->field_10 <= 0.5625f)
      {
        s->field_8 = self->field_40;
        s->field_4 = self->field_44;
        s->field_C = self->field_48;
      }
    }
  }
  else
    if (self->field_40 != 0)
  {
    if (s->field_10 < 0.0f)
    {
      s->field_10 = 0.0f;
    }
    s->field_10 += dt;
    if (!(s->field_10 <= 1.25f))
    {
      s->field_10 = 1.25f;
    }
  }
}
