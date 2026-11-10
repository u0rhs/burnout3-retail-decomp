// Hand-written; the lifter refused it (ghvu5: Ghidra draft; N185 lane-mul stand-ins, dead dir copy + N140 pads for the 0x110 frame).

// func_002F2CD0 -- hand-written (ghvu5, Ghidra-draft). Unnamed: placeholder with C linkage.
// [G] an oriented box (axes at +0x20/+0x30/+0x40, centre +0x50, half extents +0x60); returns the box corner picked
// by the signs of dir's projections ([L] neighbour of BoxWorldCollision, B3BoundingBox.cpp in DNAT).
// [L] CGtV3d returned through the hidden pointer in a0 (retail `sq v1,0(a0)`).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F2CD0 { unsigned char pad_0[0x20]; CGtV3d field_20; CGtV3d field_30; CGtV3d field_40; CGtV3d field_50; CGtV3d field_60; };
// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV3d * lane (vmulx/vmuly/vmulz.xyz, broadcast from a lane type)
static inline CGtV3d func_002F2CD0_inl1(const CGtV3d &v, XAxisType s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
static inline CGtV3d func_002F2CD0_inl2(const CGtV3d &v, YAxisType s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
static inline CGtV3d func_002F2CD0_inl3(const CGtV3d &v, ZAxisType s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
// N140: unused locals reserving retail's dead 16-byte frame slots: nine below the named vectors, three per projection
// (stand-ins for temporaries of the original inlines that b119 drops) [G]
struct UnkStruct_002F2CD0_pad { int x[4]; UnkStruct_002F2CD0_pad() {} ~UnkStruct_002F2CD0_pad() {} };
static inline float func_002F2CD0_inl4(const CGtV3d &d, const CGtV3d &a)
{
    UnkStruct_002F2CD0_pad p0;
    UnkStruct_002F2CD0_pad p1;
    UnkStruct_002F2CD0_pad p2;
    return DotProduct(d, a);
}
// 0x002F2CD0
extern "C" CGtV3d func_002F2CD0(const UnkStruct_002F2CD0 *box, const CGtV3d &dir)
{
    CGtV3d d = dir;   // [G] dead copy: its slot is retail's top frame slot (0x100)
    CGtV3d r = box->field_50;
    CGtV3d ax = box->field_20;
    CGtV3d ay = box->field_30;
    CGtV3d az = box->field_40;
    float dx = func_002F2CD0_inl4(d, ax);
    float dy = func_002F2CD0_inl4(d, ay);
    float dz = func_002F2CD0_inl4(d, az);
    if (dx < -0.001f) r += func_002F2CD0_inl1(ax, box->field_60.X());
    else if (dx > 0.001f) r -= func_002F2CD0_inl1(ax, box->field_60.X());
    if (dy < -0.001f) r += func_002F2CD0_inl2(ay, box->field_60.Y());
    else if (dy > 0.001f) r -= func_002F2CD0_inl2(ay, box->field_60.Y());
    if (dz < -0.001f) r += func_002F2CD0_inl3(az, box->field_60.Z());
    else if (dz > 0.001f) r -= func_002F2CD0_inl3(az, box->field_60.Z());
    return r;
}
