// NONMATCHING: UpdateWheelStates__17CB3RaceCarPhysicsFv -- retail 260 / ours 263 instructions, 42 in changed runs
// v289: logic complete; 42 changed + frame 0xE0 vs 0x110. Retail was compiled with repositioning ON: FP constant numbering (f24=0.8,f23=0.0 before f22=2.24,f21=29,f20=0.99) needs the 1524 block textually BEFORE the main block, yet retail lays it out after the loop back-edge with the main arm (incl. speed>29/Normalise else-if) inline and the B3 skip as beqz->shared inc. No ON-mode source shape found (36+16 polarity/nesting variants: blk stays inline, the speed>29 arm moves out, inc gets tail-duplicated). This archive uses scoped opt_repositioncode off + goto blocks (layout exact, FP regs off). Also open: v in vf2/B0 in vf3 (ours swapped) so retail's 2nd field_B0.W() reuses vf3; len in f3; 3 extra 16-byte frame slots. Map: CB3RaceCar::IsFishtailing() (B3O0PCH, emitted right after) is inlined here, probably the field_13F4->field_199B test.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3RaceCarPhysics::UpdateWheelStates() -- hand-matched (v289).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

enum EB3CollisionSurface {};
struct UnkStruct_001BF170_w {
    unsigned char pad_0[0x10];
    CGtV3d field_10;
    unsigned char pad_20[0x30];
    float field_50;
    unsigned char pad_54[0x8];
    float field_5C;
    unsigned char pad_60[0x18];
    int field_78;
    unsigned char pad_7C[0x34];
    unsigned char field_B0;
    unsigned char pad_B1[0x2];
    unsigned char field_B3;
    unsigned char pad_B4[0xC];
};
struct UnkStruct_001BF170_b {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
};
struct UnkStruct_001BF170_c {
    unsigned char pad_0[0x178C];
    int field_178C;
    unsigned char pad_1790[0x20B];
    unsigned char field_199B;
};
struct UnkStruct_001BF170_self {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;
    unsigned char pad_E0[0x124];
    UnkStruct_001BF170_b * field_204;
    unsigned char pad_208[0x618];
    UnkStruct_001BF170_w field_820[1];
    unsigned char pad_8E0[0x889];
    signed char field_1169;
    unsigned char pad_116A[0x242];
    float field_13AC;
    unsigned char pad_13B0[0x24];
    float field_13D4;
    unsigned char pad_13D8[0x1C];
    UnkStruct_001BF170_c * field_13F4;
    unsigned char pad_13F8[0x24];
    float field_141C;
    float field_1420;
    float field_1424;
    unsigned char pad_1428[0xA0];
    int field_14C8;
    unsigned char pad_14CC[0x34];
    CGtV3d field_1500;
    unsigned char pad_1510[0x14];
    int field_1524;
    unsigned char pad_1528[0x1];
    unsigned char field_1529;
};

extern "C" void DoPhysicalEffects__17CB3RaceCarPhysicsF19EB3CollisionSurface(UnkStruct_001BF170_self * self, EB3CollisionSurface s);

// [L] N185 stand-ins: vsub / CrossProduct on compiler-chosen registers
static inline CGtV3d v289_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d v289_cross(CGtV3d a, CGtV3d b) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vopmula.xyz $ACC, $vf1, $vf2" "\n\t" "vopmsub.xyz $vf1, $vf2, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a.mData), "r"(b.mData));
    return CGtV3d(t);
}

// 0x001BF170
// N182: [G] scoped to this function -- opt_repositioncode off; the out-of-line blocks are written as goto targets in retail's order.
#pragma push
#pragma opt_repositioncode off
extern "C" void UpdateWheelStates__17CB3RaceCarPhysicsFv(UnkStruct_001BF170_self * self)
{
    float speed = self->field_B0.W();
    int i;
    int j;
    UnkStruct_001BF170_w * w;
    if (self->field_13F4->field_178C == 0) goto other;
    {
        bool slow = speed < 1609 * self->field_13AC / 3600.0f || self->field_14C8 == -1;
        for (i = 0;; i++) {
            if (!(i < self->field_1169)) return;
            self->field_820[i].field_78 = 0;
            w = &self->field_820[i];
            if (w->field_B3) {
                CGtV3d v = v289_cross(self->field_D0, v289_sub(w->field_10, self->field_204->field_30));
                v += CGtV3d(self->field_B0.mData);
                float len = v.GetLength();
                if (slow) {
                    if (fabsf(w->field_5C * w->field_50) - len > 2.0f)
                        w->field_78 = 2;
                } else if (self->field_13F4->field_199B != 0) {
                    goto six;
                } else if ((unsigned)(self->field_1524 - 1) <= 1) {
                    goto blk;
                } else if (2.236936331f * (float)self->field_B0.W() < self->field_13D4 - 2.0f && fabsf(w->field_5C * w->field_50) - len > 2.0f) {  // [C] retail FPU form, not a VU lane op: 0x1BF34C mul.s (the cast keeps the port's PS2 float model)
                    w->field_78 = 3;
                } else if (speed > 29.0f && i < 2) {
                    CGtV3d n = v;
                    n.Normalise();
                    if (DotProduct(self->field_1500, n) < 0.99f)
                        w->field_78 = 4;
                }
            call:
                DoPhysicalEffects__17CB3RaceCarPhysicsF19EB3CollisionSurface(self, (EB3CollisionSurface)w->field_B0);
            }
        }
    six:
        w->field_78 = 6;
        goto call;
    blk:
        w->field_78 = 4;
        if (self->field_1420 <= 0.8f) {
            if (i < 2) {
                if (self->field_1524 == 1) goto one;
            two:
                if (self->field_1524 == 2 && !(self->field_1424 <= 0.0f)) {
                three:
                    w->field_78 = 3;
                }
            } else if (!(self->field_141C <= 0.8f)) {
                w->field_78 = 3;
            }
        } else {
            w->field_78 = 3;
        }
        goto call;
    one:
        if (self->field_1424 < 0.0f) goto three;
        goto two;
    }
join:
    return;
other:
    self->field_1529 = 0;
    for (j = 0; j < self->field_1169; j++) {
        if (!(fabsf(self->field_820[j].field_5C * self->field_820[j].field_50) <= 2.0f)) goto set;
    inc:;
    }
    goto join;
set:
    self->field_820[j].field_78 = 1;
    self->field_1529 = 1;
    goto inc;
}
#pragma pop
