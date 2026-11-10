// NONMATCHING: func_003AEC70 -- retail 210 / ours 222 instructions, 96 in changed runs
// v287: [L] DNAT CB3SatNavComponent::Update(float). Control flow/calls/switch order exact. Left (+12 instrs): per-object alpha fade inline -- retail keeps the colour in one VU reg (lqc2 once, vsubx.w into another reg, SetA in place, sqc2) where ours reloads the colour after the W-lane temp store; frame 0x140 vs 0x220 (trailing fades have 3 slots each in retail, loop ones 1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003AEC70 -- hand-written (the lifter refused it).
// [L] DNAT: CB3SatNavComponent::Update(float) (research/proto/new_names.csv, exact/verified). Placeholder name kept.
// Fields are placeholders, types [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
struct UnkStruct_003AEC70_o { unsigned char pad_0[0x10]; CGtV4d field_10; };   // a 2d object: colour at +0x10 [G]
struct UnkStruct_003AEC70_r { UnkStruct_003AEC70_o *field_0[3]; int field_C; };
class CB3SatNavComponent {
public:
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[0x36];
    UnkStruct_003AEC70_r field_40[4];
    UnkStruct_003AEC70_o *field_80;
    UnkStruct_003AEC70_o *field_84;
    UnkStruct_003AEC70_o *field_88;
    UnkStruct_003AEC70_o *field_8C;
    unsigned char pad_90[0x198];
    UnkStruct_003AEC70_o *field_228;
    unsigned char pad_22C[0x6B8];
    signed char field_8E4;
};
struct UnkStruct_D_0051A6A8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051A870 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051A9A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051A9A4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90420 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_0051A870 D_0051A870;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_D_0051A9A4 D_0051A9A4;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_01E90424 D_01E90424;
extern void *D_004E2E9C;
extern "C" void UpdateCustomLeadIn__18CB3SatNavComponentFf(CB3SatNavComponent *, float);
extern "C" void func_003A74D0(CB3SatNavComponent *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130C30(void *, int);
extern "C" void func_00130D50(void *);
extern "C" void func_00324EB0(void *);
// [L] N185 stand-ins: operator-(WAxisType, float) (as the header's YAxisType one) and CGtV4d::SetA(float) on a compiler-chosen scalar
static inline WAxisType func_003AEC70_inl1(WAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return WAxisType(r);
}
static inline void func_003AEC70_inl2(CGtV4d &c, float a)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(c.mData) : "j"(s));
}
static inline void func_003AEC70_inl3(UnkStruct_003AEC70_o *o, float d)
{
    if (o != 0) {
        float a = GtMath::Max(func_003AEC70_inl1(o->field_10.W(), d), 0.0f);
        func_003AEC70_inl2(o->field_10, a);
    }
}
// 0x003AEC70
extern "C" void func_003AEC70(CB3SatNavComponent *self, float dt)
{
    if (self->field_8E4 == 0) {
        UpdateCustomLeadIn__18CB3SatNavComponentFf(self, dt);
        return;
    }
    switch (D_01E90424.field_0) {
    case 5:
        func_003A74D0(self);
        break;
    case 3:
    case 4: {
        float d = 2.5f * dt;
        for (int i = 0; i < 4; i++) {
            UnkStruct_003AEC70_r *r = &self->field_40[i];
            func_003AEC70_inl3(r->field_0[0], d);
            func_003AEC70_inl3(r->field_0[1], d);
            func_003AEC70_inl3(r->field_0[2], d);
        }
        func_003AEC70_inl3(self->field_84, d);
        func_003AEC70_inl3(self->field_88, d);
        func_003AEC70_inl3(self->field_8C, d);
        func_003AEC70_inl3(self->field_80, d);
        if (D_0051A9A4.field_0 != 0x1A) {
            if (D_004E2E9C != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, self->field_8 + 8, D_004E2E9C);
                D_004E2E9C = 0;
            }
            func_00130C70(&D_0051A6A8);
            func_00130D00(&D_0051A6A8);
            func_00130C30(&D_0051A6A8, 0x1A);
            while (D_0051A9A0.field_0 != 0x17)
                func_00130D50(&D_0051A6A8);
        }
        func_00324EB0(&D_0051A870);
    }
    case 2:
        self->field_228->field_10.SetA(D_01E90420.field_0);
        break;
    }
}
