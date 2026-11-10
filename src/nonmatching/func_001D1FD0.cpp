// NONMATCHING: func_001D1FD0 -- retail 141 / ours 150 instructions, 131 in changed runs
// a251: signature fixed (void; func_001D28C0 takes (self,float) only; 3 u_long128 quad locals; flag=0 initialiser; if(<=1.0) else-out-of-line shape). Remaining: retail keeps 1.0f in saved $f20 across the call (frame 0x90, swc1 f20) -- local float 'one' gets constant-folded; quads' stack slots/layout still off (131)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001D1FD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"

struct UnkStruct_001D1FD0;
struct UnkStruct_001D1FD0_2;
struct UnkStruct_001D1FD0_3;
struct UnkStruct_001D1FD0_6;
struct UnkStruct_D_004E0DA8;
struct UnkStruct_D_004E0DAC;
struct UnkStruct_D_004E0DC0;
struct UnkStruct_D_00522680;
struct UnkStruct_D_01E754FC;

struct UnkStruct_D_01E754FC {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001D1FD0_2 {
    unsigned char pad_0[0x23B0];
    float field_23B0;
    float field_23B4;
};

struct UnkStruct_001D1FD0_3 {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    float field_10;
    unsigned char pad_14[0x8];
    float field_1C;
    float field_20;
    unsigned char pad_24[0x8];
    float field_2C;
    unsigned char pad_30[0x30];
};

struct UnkStruct_D_004E0DC0 {
    float field_0;
};

struct UnkStruct_D_004E0DA8 {
    float field_0;
};

struct UnkStruct_001D1FD0_6 {
    unsigned char pad_0[0x133C];
    int field_133C;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E0DAC {
    float field_0;
};

struct UnkStruct_001D1FD0 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x1334];
    UnkStruct_001D1FD0_6 * field_13F4;
    unsigned char pad_13F8[0x8];
    int field_1400;
    int field_1404;
    float field_1408;
    unsigned char pad_140C[0x8];
    float field_1414;
    unsigned char pad_1418[0x10C];
    int field_1524;
    unsigned char pad_1528[0x2A];
    unsigned char field_1552;
    unsigned char pad_1553[0x15];
    UnkStruct_001D1FD0_2 * field_1568;
    float field_156C;
    unsigned char pad_1570[0x4];
    float field_1574;
};

extern UnkStruct_D_01E754FC D_01E754FC;
extern UnkStruct_D_004E0DC0 D_004E0DC0;
extern UnkStruct_D_004E0DA8 D_004E0DA8;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_004E0DAC D_004E0DAC;

extern "C" void func_001D28C0(UnkStruct_001D1FD0 *, float);

// 0x001D1FD0
extern "C" void func_001D1FD0(UnkStruct_001D1FD0 * self)
{
    u_long128 lc;
    u_long128 lb;
    u_long128 la;
    float one = 1.0f;
    UnkStruct_001D1FD0_2 * t0 = self->field_1568;
    float mm0 = (((-t0->field_23B0) * D_01E754FC.field_0) / 180.0f);
    self->field_1408 = GtMath::Min(GtMath::Max(mm0, -1.0f), one);
    if ((unsigned int)(self->field_1524 + -1) >= (unsigned int)2) {
        self->field_1524 = 4;
    }
    la = self->field_B0;
    int flag = 0;
    if (self->field_1568->field_23B4 - ((float *)&la)[3] <= one) {
        lb = self->field_B0;
        float t6 = D_004E0DC0.field_0;
        if (self->field_1568->field_23B4 - ((float *)&lb)[3] < t6) {
            func_001D28C0(self, one);
            flag = 1;
            if (self->field_1568->field_23B4 < D_004E0DA8.field_0) {
                self->field_1552 = 1;
            }
        } else {
            if (self->field_13F4->field_133C != 0) {
                self->field_1400 = 0;
                self->field_1414 = 0.0f;
            }
            self->field_1404 = 0;
        }
    } else {
        self->field_1414 = 1.0f;
        self->field_1400 = 0x3F800000;
        self->field_1404 = 0;
    }
    if (flag != 0) {
        return;
    }
    float t8 = D_00522680.field_0;
    float t9 = self->field_1574;
    float v14;
    if (t9 <= t8) {
        v14 = 1.0f;
    } else {
        v14 = (1.0f - ((t9 - t8) / 2.0f));
    }
    float t10 = *(float *)&self->field_1400;
    if (!(t10 == self->field_156C)) {
        if (1.0f == t10) {
            lc = self->field_B0;
            if (!(((float *)&lc)[3] < D_004E0DAC.field_0)) {
                self->field_1574 = (D_00522680.field_0 + (2.0f * v14));
            } else {
                *(int *)&self->field_1574 = 0xBF800000;
            }
        } else {
            self->field_1574 = (D_00522680.field_0 + (2.0f * v14));
        }
        v14 = (1.0f - v14);
    }
    self->field_156C = *(float *)&self->field_1400;
    if (1.0f == *(float *)&self->field_1400) {
        *(float *)&self->field_1400 = v14;
        self->field_1414 = v14;
        return;
    }
    *(float *)&self->field_1400 = (1.0f - v14);
    self->field_1414 = (1.0f - v14);
}
