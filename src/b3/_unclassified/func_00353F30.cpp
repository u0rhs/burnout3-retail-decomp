// Hand-written; the lifter refused it (wirefix: pad objects use UnkStruct_00353F30_pad (N140 form drop_pad_dtor removes)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00353F30_a2 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_00353F30_pad { int x[4]; UnkStruct_00353F30_pad() {} ~UnkStruct_00353F30_pad() {} };
// 0x00353F30
extern "C" int func_00353F30(CGtV4d * v, int mode, UnkStruct_00353F30_a2 * s, float * acc)
{
    // [G] N140 pads: retail frame 0x50 has two unused 16-byte slots (guard objects?)
    UnkStruct_00353F30_pad g1;
    UnkStruct_00353F30_pad g2;
    if (mode == 2) {
        *acc = *acc + 1.0f;
    } else {
        CGtV4d t;
        t = *v;
        asm("qmtc2.ni %1, $vf2\n\tvmulx.w %0, %0, $vf2x" : "+j"(t.mData) : "r"(2.0f));
        *acc = *acc + s->field_20 / (float)t.W();  // [C] retail FPU form, not a VU lane op: 0x353F7C lwc1 / 0x353F80 div.s (the cast keeps the port's PS2 float model)
    }
    return 1;
}
