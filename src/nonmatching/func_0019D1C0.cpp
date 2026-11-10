// NONMATCHING: func_0019D1C0 -- retail 158 / ours 158 instructions, 74 in changed runs
// ghvu9: CB3WrongWayWall::AddTristrip [L DNAT]; logic believed exact (158/158), frame exact with an N140 pad per inlined SetColour. 74 off = scheduling/VU numbering: retail lq's the four positions first (p0 before the 128.0 qmtc2), puts the first vftoi0 on a new register (vf5) and the others in place, and reads field_1F84 after the first colour store.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_0019D1C0 -- hand-written from the Ghidra draft (ghvu9).
// [L] DNAT: CB3WrongWayWall::AddTristrip(CGtV3d, CGtV3d, CGtV3d, CGtV3d, CGtV4d, CGtV4d, CGtV4d, CGtV4d)
// (research/proto/new_names.csv, exact/verified, B3WrongWayWall.cpp): append four vertices (position, packed colour, the
// first two with w = 1.0039...) to the wall's 84-vertex array at +0x1500 when they fit. Fields are placeholders, types [G].

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_0019D1C0_rgba {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
};

// [L] CB3Im3dVertex::SetColour(CGtV4d) (B3O0PCH map) body as RenderSquare__16CB3VehicleDeform's (v242): col * 128, to int,
// clamped to (255, 255, 255, 128), packed to bytes
// [G] N140 pad: one dead 16-byte slot per inlined SetColour (retail frame 0x90)
struct UnkStruct_0019D1C0_pad { int x[4]; UnkStruct_0019D1C0_pad() {} ~UnkStruct_0019D1C0_pad() {} };
static inline unsigned int func_0019D1C0_inl1(CGtV4d c)
{
    UnkStruct_0019D1C0_pad pad;
    u_long128 s, t, i, lim, m, h;
    unsigned int b;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(128.0f));
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(c.mData), "j"(s));
    asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(t));
    unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
    asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
    asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
    asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    return b;
}

struct UnkStruct_0019D1C0_v {
    CGtV3dPlus field_0;
    unsigned char pad_10[0x8];
    UnkStruct_0019D1C0_rgba field_18;
    unsigned char pad_1C[0x4];
};

class CB3WrongWayWall {
public:
    unsigned char pad_0[0x1500];
    UnkStruct_0019D1C0_v field_1500[0x54];
    unsigned char pad_1F80[0x4];
    int field_1F84;
};

// 0x0019D1C0
extern "C" void func_0019D1C0(CB3WrongWayWall * self, CGtV3d p0, CGtV3d p1, CGtV3d p2, CGtV3d p3, CGtV4d c0, CGtV4d c1,
                              CGtV4d c2, CGtV4d c3)
{
    u_long128 q3 = p3.mData, q2 = p2.mData, q1 = p1.mData, q0 = p0.mData;
    union { unsigned int u; UnkStruct_0019D1C0_rgba c; } k0, k1, k2, k3;
    k0.u = func_0019D1C0_inl1(c0);
    k1.u = func_0019D1C0_inl1(c1);
    k2.u = func_0019D1C0_inl1(c2);
    k3.u = func_0019D1C0_inl1(c3);
    if (!(self->field_1F84 + 4 > 0x54)) {
        self->field_1500[self->field_1F84].field_0.SetGtV3d(CGtV3d(q0));
        self->field_1500[self->field_1F84].field_18 = k0.c;
        self->field_1500[self->field_1F84].field_0.SetPlus(1.003906011581421f);
        self->field_1F84++;
        self->field_1500[self->field_1F84].field_0.SetGtV3d(CGtV3d(q1));
        self->field_1500[self->field_1F84].field_18 = k1.c;
        self->field_1500[self->field_1F84].field_0.SetPlus(1.003906011581421f);
        self->field_1F84++;
        self->field_1500[self->field_1F84].field_0.SetGtV3d(CGtV3d(q2));
        self->field_1500[self->field_1F84].field_18 = k2.c;
        self->field_1F84++;
        self->field_1500[self->field_1F84].field_0.SetGtV3d(CGtV3d(q3));
        self->field_1500[self->field_1F84].field_18 = k3.c;
        self->field_1F84++;
    }
}


