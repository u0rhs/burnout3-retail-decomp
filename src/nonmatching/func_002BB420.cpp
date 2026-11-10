// NONMATCHING: func_002BB420 -- retail 260 / ours 260 instructions, 29 in changed runs
// near37: t-selection arms reordered to retail's layout (z>1700 arm first with the x-3415 block after it; B arm 1.0 first), floats declared c,a,b, the two degree->radian products as locals kb then ka: 68 -> 29. Left: frame 0x40 vs 0xB0 (7 dead slots), SinCosFast2/CosFast4 constant lui/ori hoisting and GPR choice (header GtMathPs2Trig.h), lane stand-ins vmuly.w/vmulx.w numbering vf1/vf3 swapped
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// happly1: hdr14 reroute (N232 header + GtMathPs2Trig.h) 93 -> 68; frame 0x40 vs retail 0xB0 still open
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// v289: logic complete, 260/260 instrs, 102 in changed runs (mostly frame 0x40 vs 0xB0 and constant/GPR scheduling). Inlined GtMathPs2::SinCosFast2(float,float) -> CosFast4(CGtV4d) (B3O0PCH map names, 632/520 bytes; no header API): file-local stand-ins reproduce retail's op sequence exactly (I-reg constants via ctc2 $vi21, vmulai/vmsubai/vmaddai rounding, abs/0.25 fold, odd polynomial t*(2pi) + -41.34t^3 + 81.6t^5 - 76.7t^7 + 39.71t^9 through ACC); .i moves keep retail's GPR round trips. b119's inline assembler REJECTS vmaddai/vmaddaq in every operand form (opcode table entry present): written as .word 0x4BE00A3F / 0x4BE01A3F. Open: retail hoists the stage-1 constants (a0=-1/2pi, a2=0.5, v1=1.5*2^23) right after the abs input move; ours hoists them above SinCosFast2's vsubi and picks a2/a0/v1 (operand order and local declaration order inert, 48+12 variants); SinCosFast2 vector GPR a3 vs a0; frame needs ~7 dead 16-byte slots (by-value CGtV4d / lane-read temporaries of the inlines; N140 pads not added).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_002BB420 -- hand-written (v289).
// [L] the inlined GtMathPs2::SinCosFast2(float,float) (B3O0PCH map, 632 bytes) and CosFast4(CGtV4d) (520 bytes): no header
// API, so file-local stand-ins reproduce retail's sequence (I-register constants through `ctc2 r,$vi21`, vmulai/vmsubai/
// vmaddai, values passed through GPRs between steps).
// vmaddai is written as .word: b119's inline assembler rejects every vmaddai/vmaddaq operand form (v289 probe).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct UnkStruct_002BB420_out {
    CGtV3d field_0;
    unsigned char pad_10[0x1C];
    float field_2C;
};
extern float D_004C1C40[];
extern float D_004C1C44[];
extern float D_004C1C48[];

// [L] GtMath::Interpolate(float,float,float) (map 0x14CCF0): z + a + t*(b-a) gives retail's adda.s/madd.s
static inline float func_002BB420_inl1(float a, float b, float t) { return a + t * (b - a); }

// [L] stand-ins (B3O0PCH map names): operator*(WAxisType,YAxisType), operator*(WAxisType,XAxisType), CGtV3d::SetX(WAxisType),
// CGtV3d::SetY(ZAxisType), CGtV3d::SetZ(WAxisType) on compiler-chosen registers
static inline u_long128 func_002BB420_inl4(u_long128 a) { u_long128 r; asm("vmuly.w %0, %1, %1y" : "=j"(r) : "j"(a)); return r; }
static inline u_long128 func_002BB420_inl5(u_long128 a) { u_long128 r; asm("vmulx.w %0, %1, %1x" : "=j"(r) : "j"(a)); return r; }
static inline void func_002BB420_inl6(CGtV3d &v, u_long128 a) { asm("vaddw.x %0, $vf0, %1w" : "+j"(v.mData) : "j"(a)); }
static inline void func_002BB420_inl7(CGtV3d &v, u_long128 a) { asm("vaddz.y %0, $vf0, %1z" : "+j"(v.mData) : "j"(a)); }
static inline void func_002BB420_inl8(CGtV3d &v, u_long128 a) { asm("vaddw.z %0, $vf0, %1w" : "+j"(v.mData) : "j"(a)); }

// 0x002BB420
extern "C" void func_002BB420(CGtV3d p, UnkStruct_002BB420_out * out)
{
    float x = p.X();
    float z = p.Z();
    float t = 0.0f;
    int from;
    int to;
    if (!(x <= t)) {
        from = 1;
        to = 0;
        if (!(z <= 1700)) {
            if (!(x <= 3575)) {
                t = 1.0f;
            } else if (!(x <= 3410)) {
                t = 0.007751937956f * (z - 2009);
            }
        } else {
            t = 0.004081632476f * (x - 3415);
        }
    } else {
        from = 2;
        to = 1;
        if (!(z <= 1350)) {
            t = 1.0f;
        } else {
            t = 0.002499999944f * (x - -700.0f);
        }
    }
    float c, a, b;
    if (t <= 0.0f) {
        a = D_004C1C40[from * 3];
        b = D_004C1C44[from * 3];
        c = D_004C1C48[from * 3];
    } else if (t < 1.0f) {
        a = func_002BB420_inl1(D_004C1C40[from * 3], D_004C1C40[to * 3], t);
        b = func_002BB420_inl1(D_004C1C44[from * 3], D_004C1C44[to * 3], t);
        c = func_002BB420_inl1(D_004C1C48[from * 3], D_004C1C48[to * 3], t);
    } else {
        a = D_004C1C40[to * 3];
        b = D_004C1C44[to * 3];
        c = D_004C1C48[to * 3];
    }
    float kb = 0.01745329238f * b;
    float ka = 0.01745329238f * a;
    CGtV4d sc = SinCosFast2(ka, kb);
    func_002BB420_inl6(out->field_0, func_002BB420_inl4(sc.mData));
    func_002BB420_inl7(out->field_0, sc.mData);
    func_002BB420_inl8(out->field_0, func_002BB420_inl5(sc.mData));
    out->field_2C = c;
}
