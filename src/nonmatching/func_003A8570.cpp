// NONMATCHING: func_003A8570 -- retail 84 / ours 83 instructions, 20 in changed runs
// psweep: scoped #pragma opt_rebuildconditionals off [G] improves 28 -> 24
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_rebuildconditionals off
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003A8570 -- retail 84 / ours 81 instructions, 19 in changed runs
// a115: 81 vs 84 instrs, 19 in changed runs. Logic right. Retail loads both D_004CA060 quads (a1,a2) before the compare, n=9BC in a3, 220 gets the plain-D_060 copy (sp+0x30), 224 the cond value (sp+0x40), and func_003AB640 is called without reloading a1. u_long128 wrapper-struct locals keep the stack slots but ours reloads/orders the lq/sq differently.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_8570;
struct UnkStruct_8570_3;
struct UnkStruct_8570_4;
struct UnkStruct_8570_5;
struct UnkStruct_D_004CA060;
struct UnkStruct_D_004CA070;

struct UnkStruct_D_004CA070 {
    u_long128 field_0;
};

struct UnkStruct_D_004CA060 {
    u_long128 field_0;
};

struct UnkStruct_8570_3 {
    u_long128 field_0;
    unsigned char pad_10[0x20];
    u_long128 field_30;
};

struct UnkStruct_8570_4 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_8570_5 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_8570 {
    unsigned char pad_0[0xC0];
    int field_C0;
    unsigned char pad_C4[0x15C];
    UnkStruct_8570_4 * field_220;
    UnkStruct_8570_5 * field_224;
    unsigned char pad_228[0x28];
    unsigned short field_250;
    unsigned char pad_252[0x694];
    unsigned char field_8E6;
    unsigned char pad_8E7[0xCD];
    int field_9B4;
    int field_9B8;
    int field_9BC;
};

extern UnkStruct_D_004CA070 D_004CA070;
extern UnkStruct_D_004CA060 D_004CA060;

extern "C" int func_00319330(void *);
extern "C" void func_003AB640(UnkStruct_8570 *, u_long128);

struct UnkStruct_8570_L { u_long128 field_0; };
struct UnkStruct_8570_W { u_long128 field_0; };
// [G] 0x30 bytes: the frame keeps 0x20 bytes past this temp (retail sp+0x10, the other at sp+0x40)
struct UnkStruct_8570_M { u_long128 field_0; unsigned char pad_10[0x20]; };
// 0x003A86C0

extern "C" int func_003A8570(UnkStruct_8570 * self)
{
    if (self->field_8E6 != 0) {
        int n = self->field_9BC;
        if (self->field_250 == 5) {
            UnkStruct_8570_W c2;
            UnkStruct_8570_W c1;
            c1.field_0 = D_004CA060.field_0;
            if (self->field_9B8 + 1 < n - 1) {
                c2.field_0 = D_004CA060.field_0;
            } else {
                c2.field_0 = D_004CA070.field_0;
            }
            if (self->field_220 != 0) {
                self->field_220->field_10 = c1.field_0;
            }
            if (self->field_224 != 0) {
                self->field_224->field_10 = c2.field_0;
            }
            if (self->field_9B8 < n - 1) {
                self->field_9B4 = self->field_C0;
                self->field_9B8 = self->field_9B8 + 1;
                func_003AB640(self, c1.field_0);
                return 1;
            }
            return 0;
        } else {
            UnkStruct_8570_W d1;
            UnkStruct_8570_W d2;
            d1.field_0 = D_004CA060.field_0;
            if (self->field_9B8 + 1 < n - 1) {
                d2.field_0 = D_004CA060.field_0;
            } else {
                d2.field_0 = D_004CA070.field_0;
            }
            if (self->field_220 != 0) {
                self->field_220->field_10 = d1.field_0;
            }
            if (self->field_224 != 0) {
                self->field_224->field_10 = d2.field_0;
            }
            self->field_9B8 = (self->field_9B8 + 1);
            return func_00319330(((char *)self + 0x250));
        }
    }
    return func_00319330(((char *)self + 0x250));
}


#pragma pop
