// NONMATCHING: func_00263E80 -- retail 60 / ours 60 instructions, 14 in changed runs
// near32: 14 off, registers only (retail r a3 / d a2; ours r a2 / d t0). Fixed archive logic: the 0x4C offset applies when flag != 0 (beqz skips it; int flag, no andi); fields field_8/field_40 volatile for retail's reloads; header SetPlus(va.Y()) shares one lqc2; one 0x40 N140 pad below va/vb gives the 0x60 frame; r computed after u. sreg 2 rounds no gain
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00263E80_slot { unsigned char *field_0; int field_4; volatile int field_8; int pad_C; };
struct UnkStruct_00263E80_ring {
    UnkStruct_00263E80_slot field_0[4];
    volatile int field_40;
    float field_44;
    unsigned char pad_48[4];
};
struct UnkStruct_00263E80_blk { float field_0[4]; CGtV3dPlus field_10[8]; };
struct UnkStruct_00263E80_pad { int x[16]; UnkStruct_00263E80_pad() {} ~UnkStruct_00263E80_pad() {} };
extern "C" void func_00263E80(UnkStruct_00263E80_ring *o, const CGtV3d *a, const CGtV3d *b, int flag, float f)
{
    CGtV3d va = *a;
    CGtV3d vb = *b;
    UnkStruct_00263E80_pad pad; // [G] N140: retail's dead 0x40 frame below va/vb
    if (flag != 0) o = (UnkStruct_00263E80_ring *)((char *)o + 0x4C);
    UnkStruct_00263E80_slot *s = &o->field_0[o->field_40];
    int c = s->field_8;
    int q = c / 4;
    UnkStruct_00263E80_blk *u = (UnkStruct_00263E80_blk *)((unsigned int)(s->field_0 + q * 0x90) | 0x20000000);
    int r = c & 3;
    CGtV3dPlus *d = &u->field_10[r * 2];
    s->field_8 = s->field_8 + 1;
    if (s->field_8 == s->field_4) s->field_8 = 0;
    o->field_40 = o->field_40 + 1;
    o->field_40 = o->field_40 & 3;
    d[0].SetGtV3d(va);
    d[0].SetPlus(va.Y());
    d[1].SetGtV3d(vb);
    d[1].SetPlus(vb.Y());
    u->field_0[r] = f;
    o->field_44 = f;
}
