// NONMATCHING: func_002622A0 -- retail 82 / ours 82 instructions, 27 in changed runs
// ghvu3: logic/structure right (quat at-axis via [L] N185 axis-product stand-ins); left: q*s on vf3 not vf1 and at on vf1 not vf3 (VU colouring), frame 0x1D0 vs retail 0x310, address-reg order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu3, Ghidra draft): a camera quaternion's "at" axis, then three corona arrays' BeginUpdate.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002622A0_cam { unsigned char pad_0[0x10]; CGtV4d field_10; CGtV3d field_20; };
struct UnkStruct_002622A0_g { unsigned char pad_0[0x68]; UnkStruct_002622A0_cam *field_68; };
extern UnkStruct_002622A0_g *D_00666270[4];
struct UnkStruct_002622A0_c { unsigned char pad_0[0x34]; };
class CB3CoronaDynamicArray { public: void BeginUpdate(int); };
struct UnkStruct_002622A0 { unsigned char pad_0[0xC]; UnkStruct_002622A0_c field_C[3]; unsigned char pad_A8[0x1F810 - 0xA8]; CGtV3d field_1F810; };
// [L] N185: stand-ins for GtMathPs2::operator*(XAxisType,XAxisType) etc. (B3O0PCH map, 80 bytes each): one partial-lane vmul
static inline XAxisType func_002622A0_inl1(XAxisType a, XAxisType b) { u_long128 r; asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline XAxisType func_002622A0_inl2(XAxisType a, ZAxisType b) { u_long128 r; asm("vmulz.x %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline YAxisType func_002622A0_inl3(YAxisType a, YAxisType b) { u_long128 r; asm("vmuly.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
static inline YAxisType func_002622A0_inl4(YAxisType a, ZAxisType b) { u_long128 r; asm("vmulz.y %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
static inline WAxisType func_002622A0_inl5(WAxisType a, XAxisType b) { u_long128 r; asm("vmulx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
static inline WAxisType func_002622A0_inl6(WAxisType a, YAxisType b) { u_long128 r; asm("vmuly.w %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
// 0x002622A0
// [L] N185: stands in for a compiler-chosen CGtV3d add (retail `vadd.xyz $vf1, $vf6, $vf1`; the header operator+ hard-codes $vf1/$vf2)
static inline CGtV3d func_002622A0_inl8(CGtV3d a, CGtV3d b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_002622A0_inl7(const CGtV4d &q0)
{
    CGtV4d q = q0 * 1.4142135f;
    XAxisType xx = func_002622A0_inl1(q.X(), q.X());
    XAxisType xz = func_002622A0_inl2(q.X(), q.Z());
    YAxisType yy = func_002622A0_inl3(q.Y(), q.Y());
    YAxisType yz = func_002622A0_inl4(q.Y(), q.Z());
    WAxisType wx = func_002622A0_inl5(q.W(), q.X());
    WAxisType wy = func_002622A0_inl6(q.W(), q.Y());
    CGtV3d at;
    at.Set((float)xz + (float)wy, (float)yz - (float)wx, 1.0f - (float)xx - (float)yy);
    return at;
}
extern "C" void func_002622A0(UnkStruct_002622A0 *self, int a1)
{
    UnkStruct_002622A0_cam *cam = D_00666270[0]->field_68;
    CGtV3d pos = cam->field_20;
    self->field_1F810 = func_002622A0_inl8(pos, func_002622A0_inl7(cam->field_10) * -2.0f);
    for (int i = 0; i < 3; i++) {
        ((CB3CoronaDynamicArray *)&self->field_C[i])->BeginUpdate(a1);
    }
}
