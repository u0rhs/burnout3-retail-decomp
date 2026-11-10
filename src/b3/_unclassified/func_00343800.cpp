// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): col.SetA(0.0f);; col.SetA(0.0f);).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" float sinf(float);
struct UnkStruct_00343800_o { CGtV2d field_0; CGtV2d field_8; CGtV4d field_10; };
struct UnkStruct_00343800_c { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_00343800 {
    unsigned char pad_0[0xC];
    UnkStruct_00343800_c * field_C;
    unsigned char pad_10[0xC];
    UnkStruct_00343800_o * field_1C;
    unsigned char pad_20[0xC];
    float field_2C;
};
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
extern UnkStruct_D_01E90350 D_01E90350;
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_01E90420 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_01E90420 D_004F50A0;
extern const UnkStruct_D_01E90420 D_004C5D6C;
static inline CGtV2d func_00343800_inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }
extern "C" void func_00343800 ( UnkStruct_00343800 * self , float dt );






// 0x00343800
void func_00343800(UnkStruct_00343800 *self, float dt)
{
  CGtV4d col;
  col = D_01E90350.field_0;
  switch (D_01E90424.field_0)
  {
    case 0:

    case 1:
    {
      col.SetA(0.0f);
      UnkStruct_00343800_o *o = self->field_1C;
      float y = 414.0f + ((1.0f - D_01E90420.field_0) * D_004C5D6C.field_0);
      o->field_0 = CGtV2d(320.0f, y) - (o->field_8 * CGtV2d(0.5f, 1.0f));
      break;
    }

    case 2:

    case 3:

    case 4:
    {
      UnkStruct_00343800_o *o = self->field_1C;
      col.SetA(D_01E90420.field_0);
      float y = 414.0f + ((1.0f - D_01E90420.field_0) * D_004C5D6C.field_0);
      o->field_0 = CGtV2d(320.0f, y) - (o->field_8 * CGtV2d(0.5f, 1.0f));
      break;
    }

    case 5:
    {
CGtV4d c ( 1.0f , 1.0f , 1.0f , 1.0f ) ;
      float a;
      if ((D_004F50A0.field_0 - self->field_2C) <= 2.0f)
      {
        a = 0.0f;
      }
      else
      {
        a = 0.5f + sinf(3.1415927f * (D_004F50A0.field_0 - ((float) ((int) D_004F50A0.field_0))));
      }
      c.SetA(a);
      self->field_1C->field_10 = c;
      break;
    }

  }

  self->field_C->field_10 = col;
}
