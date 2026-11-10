// NONMATCHING: func_002F2A00 -- retail 180 / ours 185 instructions, 52 in changed runs
// v287: logic exact (OBB per-axis clamp; non-const box ptr for retail's extents reloads). Left: Y/Z lane reads (header copy ctor + lane) compute &t+4 into a register where retail uses lwc1 K(sp); frame 0x360 vs 0x4F0 (retail lane temps start at sp+0x60 with 2 dead slots per +/- arm; an N140 pad fixes size but not temp offsets); 5 extra instrs from those addiu. Stand-ins: CGtV3d*X/Y/ZAxisType, X/Y/Z unary minus in place (retail vsub.z, not the header's -1.0 vmulx.z)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_002F2A00 -- hand-written (the lifter refused it). Placeholder name; no table name at this address.
// Fields are placeholders and types [G]. Returns a CGtV3d through the hidden result pointer (a0) [C asm].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F2A00 {
    unsigned char pad_0[0x20];
    CGtMatrix3x4 field_20;          // rows at +0x20/+0x30/+0x40, position at +0x50 [G]
    CGtV3d field_60;                // per-axis half extents [G]
};
// [L] N185 stand-ins for GtMathPs2 inlines missing from the header (B3O0PCH map names: CGtV3d::operator*(XAxisType/
// YAxisType/ZAxisType), XAxisType::operator-())
static inline CGtV3d func_002F2A00_inl1(const CGtV3d &v, XAxisType a) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(t); }
static inline CGtV3d func_002F2A00_inl2(const CGtV3d &v, YAxisType a) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(t); }
static inline CGtV3d func_002F2A00_inl3(const CGtV3d &v, ZAxisType a) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(t); }
static inline XAxisType func_002F2A00_inl4(XAxisType a) { asm("vsub.x %0, $vf0, %0" : "+j"(a.lVector)); return XAxisType(a.lVector); }
static inline YAxisType func_002F2A00_inl5(YAxisType a) { asm("vsub.y %0, $vf0, %0" : "+j"(a.lVector)); return YAxisType(a.lVector); }
static inline ZAxisType func_002F2A00_inl6(ZAxisType a) { asm("vsub.z %0, $vf0, %0" : "+j"(a.lVector)); return ZAxisType(a.lVector); }
// 0x002F2A00
extern "C" CGtV3d func_002F2A00(UnkStruct_002F2A00 *b, CGtV3d p, float *out)
{
    CGtV3d r = b->field_20.mPos;
    CGtV3d x = b->field_20.mRight;
    CGtV3d y = b->field_20.mUp;
    CGtV3d z = b->field_20.mAt;
    float dx = DotProduct(p, x);
    float dy = DotProduct(p, y);
    float dz = DotProduct(p, z);
    if (dx < -0.001f) {
        r += func_002F2A00_inl1(x, b->field_60.X());
        out[0] = b->field_60.X() * -2.0f;
        out[1] = 0.0f;
    } else if (dx > 0.001f) {
        r -= func_002F2A00_inl1(x, b->field_60.X());
        out[0] = 0.0f;
        out[1] = b->field_60.X() * 2.0f;
    } else {
        out[0] = func_002F2A00_inl4(b->field_60.X());
        out[1] = b->field_60.X();
    }
    if (dy < -0.001f) {
        r += func_002F2A00_inl2(y, b->field_60.Y());
        out[2] = b->field_60.Y() * -2.0f;
        out[3] = 0.0f;
    } else if (dy > 0.001f) {
        r -= func_002F2A00_inl2(y, b->field_60.Y());
        out[2] = 0.0f;
        out[3] = b->field_60.Y() * 2.0f;
    } else {
        out[2] = func_002F2A00_inl5(b->field_60.Y());
        out[3] = b->field_60.Y();
    }
    if (dz < -0.001f) {
        r += func_002F2A00_inl3(z, b->field_60.Z());
        out[4] = b->field_60.Z() * -2.0f;
        out[5] = 0.0f;
    } else if (dz > 0.001f) {
        r -= func_002F2A00_inl3(z, b->field_60.Z());
        out[4] = 0.0f;
        out[5] = b->field_60.Z() * 2.0f;
    } else {
        out[4] = func_002F2A00_inl6(b->field_60.Z());
        out[5] = b->field_60.Z();
    }
    return r;
}
