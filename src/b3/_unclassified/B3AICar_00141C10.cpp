// CB3AICar::OnSetActive(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu3: Ghidra draft + func_00333740's invert stand-ins [L] N185, (float)-100000 SetY, N140 pad 0xF0).

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. Inactive: the car's matrix copied to its body, the
// body's matrix copied to field_70 and inverted in place (orthonormal: transpose, pos = -(r0*p.x + r1*p.y + r2*p.z)),
// the same inlined code as func_00333740 (whose [L] N185 stand-ins are reused here).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00141C10_b {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x154];
    CGtMatrix3x4 * field_204;
};
extern "C" void ResetTarget__11CB3AITargetFv(void *);  // CB3AITarget::ResetTarget()
struct UnkStruct_D_0064D37A { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064D37A D_0064D37A;
class CB3AICar;
extern "C" void func_00150E20(CB3AICar *, bool);
extern "C" void func_00143860(CB3AICar *, unsigned char);
class CB3AICar {
public:
    void OnSetActive(bool b);
    CGtMatrix3x4 field_0;
    unsigned char pad_40[0x1970];
    CGtV3d field_19B0;
    CGtV3d field_19C0;
    unsigned char pad_19D0[0x20];
    unsigned char field_19F0[0xA40];
    UnkStruct_00141C10_b * field_2430;
    unsigned char pad_2434[0x1A];
    unsigned char field_244E;
};
// [L] N185 stand-ins (as func_00333740): operator+= (vadd.xyz d,d,s), lane-scaled products, per-row transpose lane copies
static inline void func_00141C10_inl2(CGtV3d &a, const CGtV3d &b) { asm("vadd.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }
static inline CGtV3d func_00141C10_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00141C10_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00141C10_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00141C10_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00141C10_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00141C10_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
// [G] N140 pad: retail's frame is 0xF0 larger with no stack access (dead slots of the inlined matrix code, as func_00333740)
struct UnkStruct_00141C10_pad { int x[60]; UnkStruct_00141C10_pad() {} ~UnkStruct_00141C10_pad() {} };
// 0x00141C10
void CB3AICar::OnSetActive(bool b)
{
    func_00150E20(this, b);
    if (!b) {
        UnkStruct_00141C10_pad pad;
        field_0.mPos.SetY(((float)-100000));
        UnkStruct_00141C10_b *body = field_2430;
        *body->field_204 = field_0;
        body->field_70 = *body->field_204;
        CGtMatrix3x4 &r = body->field_70;
        CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
        func_00141C10_r0(r.mRight, b, c);
        func_00141C10_r1(r.mUp, a, c);
        func_00141C10_r2(r.mAt, a, b);
        CGtV3d p = r.mPos;
        CGtV3d z = func_00141C10_inl5(r.mAt, p);
        CGtV3d x = func_00141C10_inl3(r.mRight, p);
        CGtV3d t = x + func_00141C10_inl4(r.mUp, p);
        func_00141C10_inl2(t, z);
        r.mPos = -t;
    } else {
        field_19B0.Zero();
        field_19C0.Zero();
        ResetTarget__11CB3AITargetFv(((char *)this + 0x19F0));
        func_00143860(this, D_0064D37A.field_0);
        field_244E = 1;
    }
}
