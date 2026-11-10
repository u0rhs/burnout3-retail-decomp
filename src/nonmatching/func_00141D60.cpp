// NONMATCHING: func_00141D60 -- retail 150 / ours 149 instructions, 20 in changed runs
// draftAO (2026-11-01): reviewed complete against retail; scored under its member symbol (the archive scored 0 as a symbol mismatch: nonmatch.py now diffs label=<our symbol> as try.py) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 750 -> 24
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: calls identical, branches and stores checked against retail



// func_00141D60 -- hand-written (ghvu9), cloned from CB3AICar::OnSetActive (B3AICar_00141C10.cpp).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;
struct UnkStruct_00141D60_b {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x154];
    CGtMatrix3x4 * field_204;
};
extern "C" void ResetTarget__11CB3AITargetFv(void *);  // CB3AITarget::ResetTarget()
struct UnkStruct_D_0064D37A { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064D37A D_0064D37A;
class CB3AICar;
extern "C" void func_00143860(CB3AICar *, unsigned char);
struct UnkStruct_00141D60_seg {
    short field_0;
    unsigned char pad_2[0x2];
    unsigned char field_4;
    unsigned char pad_5;
    unsigned short field_6;
    unsigned char pad_8[0x2];
};
struct UnkStruct_00141D60_ld {
    unsigned char pad_0[0x8];
    UnkStruct_00141D60_seg * field_8;
    unsigned short field_C;
    unsigned char field_E;
};
struct UnkStruct_00141D60_lane {
    unsigned char pad_0[0x4];
    UnkStruct_00141D60_ld * field_4;
};
struct UnkStruct_D_0064D368 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D378 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064D368 D_0064D368;
extern UnkStruct_D_0064D378 D_0064D378;
extern char D_00522660[];
extern "C" void func_001AB010(UnkStruct_00141D60_b *);
extern "C" void StopImmediately__16CB3CollidingBodyFv(void *);  // CB3CollidingBody::StopImmediately()
class CB3AICar {
public:
    void ResetCarInSlice(int slice, CGtMatrix3x4 * m);
    unsigned char pad_0[0x18B4];
    UnkStruct_00141D60_lane * field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x6];
    int field_18C0;
    unsigned char pad_18C4[0xEC];
    CGtV3d field_19B0;
    CGtV3d field_19C0;
    unsigned char pad_19D0[0x20];
    unsigned char field_19F0[0xA40];
    UnkStruct_00141D60_b * field_2430;
    unsigned char pad_2434[0x16];
    short field_244A;
};
// [L] N185 stand-ins (as func_00333740): operator+= (vadd.xyz d,d,s), lane-scaled products, per-row transpose lane copies
static inline void func_00141D60_inl2(CGtV3d &a, const CGtV3d &b) { asm("vadd.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }
static inline CGtV3d func_00141D60_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00141D60_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00141D60_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00141D60_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00141D60_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00141D60_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
// [G] N140 pad: retail's frame is 0xF0 larger with no stack access (dead slots of the inlined matrix code, as func_00333740)
struct UnkStruct_00141D60_pad { int x[60]; UnkStruct_00141D60_pad() {} ~UnkStruct_00141D60_pad() {} };
// 0x00141D60
// [L] DNAT: CB3AICar::ResetCarInSlice(int, GtMathPs2::CGtMatrix3x4*) (research/proto/new_names.csv, exact/verified, B3AICar.cpp)
void CB3AICar::ResetCarInSlice(int slice, CGtMatrix3x4 * m)
{
    if (m) {
        UnkStruct_00141D60_pad pad;
        UnkStruct_00141D60_b *body = field_2430;
        *body->field_204 = *m;
        body->field_70 = *body->field_204;
        CGtMatrix3x4 &r = body->field_70;
        CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
        func_00141D60_r0(r.mRight, b, c);
        func_00141D60_r1(r.mUp, a, c);
        func_00141D60_r2(r.mAt, a, b);
        CGtV3d p = r.mPos;
        CGtV3d z = func_00141D60_inl5(r.mAt, p);
        CGtV3d x = func_00141D60_inl3(r.mRight, p);
        CGtV3d t = x + func_00141D60_inl4(r.mUp, p);
        func_00141D60_inl2(t, z);
        r.mPos = -t;
    }
    field_18C0 = slice;
    if (field_18C0 >= D_0064D368.field_0) {
        if (D_0064D378.field_0) {
            field_18C0 = D_0064D368.field_0 - 1;
        } else {
            field_18C0 = field_18C0 % D_0064D368.field_0;
        }
    }
    field_244A = field_18C0;
    UnkStruct_00141D60_lane * lane = field_18B4;
    int seg = field_18B8;
    unsigned short n;
    unsigned char l;
    l = lane->field_4->field_8[seg].field_4;
    n = lane->field_4->field_8[seg].field_6;
    while (l != 0xFF) {
        lane = (UnkStruct_00141D60_lane *)(D_00522660 + l * 8 + 0x2C);
        seg = n;
        l = lane->field_4->field_8[seg].field_4;
        n = lane->field_4->field_8[seg].field_6;
    }
    short o = lane->field_4->field_8[seg].field_0;
    field_18B4 = lane;
    UnkStruct_00141D60_ld * ld = lane->field_4;
    int s = seg + (field_18C0 - o);
    if (ld->field_E) {
        if (s < 0) {
            s += ld->field_C;
        }
        if (s > ld->field_C) {
            s -= ld->field_C;
        }
    } else {
        if (s < 0) {
            s = 0;
        }
        if (s > ld->field_C) {
            s = ld->field_C - 1;
        }
    }
    field_18B8 = s;
    func_001AB010(field_2430);
    field_19B0.Zero();
    field_19C0.Zero();
    ResetTarget__11CB3AITargetFv(((char *)this + 0x19F0));
    func_00143860(this, D_0064D37A.field_0);
    StopImmediately__16CB3CollidingBodyFv(field_2430);
}


#pragma pop
