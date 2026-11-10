// Hand-written; the lifter refused it (xyz copy (vadd.xyz) + SetW-variant (vsubw.w/vaddx.w) as local asm; D_00522680 as >8-byte struct (lui, not gp)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_a187_p { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_a187_q {
    unsigned char pad_0[0x1000];
    CGtV4d field_1000;
    unsigned char field_1010[4];
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
};
struct UnkStruct_a187_o {
    unsigned char pad_0[0x204];
    UnkStruct_a187_p *field_204;
    unsigned char pad_208[0xABC];
    UnkStruct_a187_q *field_CC4;
};
struct UnkStruct_a187_gf { float field_0; int pad_4[3]; };
extern UnkStruct_a187_gf D_00522680;
// 0x001AE360
extern "C" void func_001AE360(void *unused, UnkStruct_a187_o *o)
{
    u_long128 pos = o->field_204->field_30.mData;
    UnkStruct_a187_q *q = o->field_CC4;
    float g = D_00522680.field_0;
    u_long128 m = q->field_1000.mData;
    asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(pos));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, $vf1x" : "+j"(m) : "r"(g));
    q->field_1000.mData = m;
    q->field_1015 |= 0x18;
    o->field_CC4->field_1016 |= 0xF0;
    q->field_1015 &= 0xF9;
    if (q->field_1014 != 2) {
        q->field_1014 = 2;
        q->field_1015 |= 1;
    }
}
