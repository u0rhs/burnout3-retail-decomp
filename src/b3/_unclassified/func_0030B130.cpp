// Hand-written; the lifter refused it (a165 tiny).

#include "b3/GtMath.h"
struct UnkStruct_a165_burn { unsigned char pad_0[0x38]; float field_38; };
struct CB3Burn { static float gmarBoostBarSizes[4]; };
struct UnkStruct_a165_b { UnkStruct_a165_burn *field_0; unsigned char pad_4[0x10]; float field_14; float field_18; float field_1C; };
// 0x0030B130
extern "C" void func_0030B130(UnkStruct_a165_b *s, int flag) {
 if (flag == 0) s->field_14 = 2.0f;
 s->field_1C = GtMath::Min(s->field_18 / 2.5f, s->field_0->field_38 / CB3Burn::gmarBoostBarSizes[3]);
 s->field_18 = 0.0f; }
