// NONMATCHING: CheckForDrift__11CB3AIDriverFv -- retail 182 / ours 186 instructions, 44 in changed runs
// retune1 (N239): 0x60-byte N140 pad in first drift block restores frame 0x1E0; 47 -> 44
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: CheckForDrift__11CB3AIDriverFv -- retail 182 / ours 184 instructions, 37 in changed runs
// ghvu11: logic/layout right; 37 off: DotProduct's vmul result lands on vf1 (then GPR-moved to vf2) where retail writes vf2 directly; retail precomputes &car->field_20 (addiu v1,a1,0x20); frame 0x180 vs 0x1E0 (state4 d at 0x1C0 top, state2 d at sp+0 bottom -- maybe state2 block is an inline helper)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3AIDriver::CheckForDrift() -- hand-written from the Ghidra draft (ghvu11).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00145700_b { unsigned char pad_0[0xB0]; CGtV4d field_B0; };
struct UnkStruct_00145700_car {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    CGtV3d field_30;
    unsigned char pad_40[0x23F0];
    UnkStruct_00145700_b *field_2430;
};
struct UnkStruct_00145700_pad { int x[24]; UnkStruct_00145700_pad() {} ~UnkStruct_00145700_pad() {} };
struct UnkStruct_kYAxis { CGtV3d field_0; };
extern UnkStruct_kYAxis kYAxis;
struct UnkStruct_D_01E75580 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E75580 D_01E75580;
struct UnkStruct_D_01E754F8 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E754F8 D_01E754F8;
// [L] N185: CrossProduct on compiler-chosen registers, the result register compiler-chosen, moved out .i stand-in
static inline CGtV3d func_00145700_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r, t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %0, %2, %1" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    asm("qmfc2.i %0, %1" : "=r"(t) : "j"(r));
    return CGtV3d(t);
}
// [L] N185: compiler-chosen vsub stand-in
static inline CGtV3d func_00145700_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_00145700_inl4(const CGtV3d &a, const CGtV3d &b) { return func_00145700_inl1(a, b); }

class CB3AIDriver {
public:
    void CheckForDrift();
    unsigned char pad_0[0x1F4];
    int field_1F4;
    unsigned char pad_1F8[8];
    CGtV3d field_200;
    unsigned char pad_210[0x578];
    unsigned char field_788;
    unsigned char pad_789[0x17];
    UnkStruct_00145700_car *field_7A0;
    unsigned char pad_7A4[0x21C];
    float field_9C0;
    unsigned char pad_9C4[0x4F];
    unsigned char field_A13;
    unsigned char field_A14;
    unsigned char field_A15;
};

// 0x00145700
void CB3AIDriver::CheckForDrift()
{
    field_A13 = 0;
    field_A14 = 0;
    if (field_788 == 0) return;
    if (field_1F4 == 4 && field_9C0 < 0.0f) {
        field_A13 = 1;
        field_A14 = 0;
UnkStruct_00145700_pad pq;
        CGtV3d d;
        d = func_00145700_inl2(field_200, field_7A0->field_30);
        CGtV3d c = func_00145700_inl4(d, kYAxis.field_0);
        bool left = DotProduct(field_7A0->field_20, c) > 0.0f;
        float len = d.GetLength();
        float r = len / (float)field_7A0->field_2430->field_B0.W();  // [C] retail FPU form, not a VU lane op: 0x145820 / 0x145960 div.s (the cast keeps the port's PS2 float model)
        if (!left && (r < D_01E75580.field_0 || field_9C0 < -D_01E754F8.field_0)) field_A15 = 1;
        else field_A15 = 0;
    } else if (field_1F4 == 2 && field_9C0 > 0.0f) {
        field_A13 = 0;
        field_A14 = 1;
        CGtV3d d;
        d = func_00145700_inl2(field_200, field_7A0->field_30);
        CGtV3d c = func_00145700_inl4(kYAxis.field_0, d);
        bool left = DotProduct(field_7A0->field_20, c) > 0.0f;
        float len = d.GetLength();
        float r = len / (float)field_7A0->field_2430->field_B0.W();  // [C] retail FPU form, not a VU lane op: 0x145820 / 0x145960 div.s (the cast keeps the port's PS2 float model)
        if (!left && (r < D_01E75580.field_0 || field_9C0 < -D_01E754F8.field_0)) field_A15 = 1;
        else field_A15 = 0;
    }
}
