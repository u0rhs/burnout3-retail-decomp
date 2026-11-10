// NONMATCHING: DoWheelLineCollision__17CB3VehiclePhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPiPf -- retail 169 / ours 169 instructions, 12 in changed runs
// ghvu10: 169/169, frame 0xE0 exact (two N140 pads), 12 changed: only the per-iteration field_200 value sits in a1 where retail has v1 (cascades into the a0/a1/v1 temps of the dot-product and call blocks). Tried s local / no local / s=field_200 in the test, unsigned char type, 15-pragma sweep, sreg 2 rounds.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehiclePhysics::DoWheelLineCollision(CGtV3d, CGtV3d, int*, float*) -- hand-written (ghvu10, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G].

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtLine { public: CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_001CE1A0_tri { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_001CE1A0_ty { unsigned char field_0; unsigned char field_1; };
struct UnkStruct_001CE1A0_set { int field_0; UnkStruct_001CE1A0_tri *field_4; UnkStruct_001CE1A0_ty *field_8; };
struct UnkStruct_001CE1A0_204 { unsigned char pad_0[0x10]; CGtV3d field_10; };
struct UnkStruct_001CE1A0_cc4 { unsigned char pad_0[0x324]; float field_324; };
class CB3VehiclePhysics {
public:
    bool DoWheelLineCollision(CGtV3d, CGtV3d, int *, float *);
    unsigned char pad_0[0x200];
    UnkStruct_001CE1A0_set *field_200;
    UnkStruct_001CE1A0_204 *field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211[4];
    signed char field_215;
    unsigned char pad_216[0xAAE];
    UnkStruct_001CE1A0_cc4 *field_CC4;
};
extern "C" int IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(
    const CGtLine *, const void *, const void *, const void *, float *, float *, float *);

static inline bool func_001CE1A0_inl1(int t) { bool r; if (t >= 0 && t <= 11) r = true; else r = false; return r; }
static inline bool func_001CE1A0_inl2(int t) { bool r; if (t >= 12 && t <= 20) r = true; else r = false; return r; }
// [L] N185: XAxisType -> float without the address-taken read (operator float's N129 slot).
static inline float func_001CE1A0_inl3(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }
// [L] N185: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers.
static inline CGtV3d func_001CE1A0_inl4(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }

struct UnkStruct_001CE1A0_pad { int x[4]; UnkStruct_001CE1A0_pad() {} ~UnkStruct_001CE1A0_pad() {} };
// 0x001CE1A0
bool CB3VehiclePhysics::DoWheelLineCollision(CGtV3d a, CGtV3d b, int *idx, float *dist)
{
    CGtV3d pa = a;
    CGtV3d pb = b;
    CGtLine line;
    bool chk = (unsigned)(field_215 - 1) < 3;
    line.field_0 = a;
    line.field_10 = b;
    UnkStruct_001CE1A0_pad g0;  // N140 [G]: two 16-byte frame slots retail keeps below the line
    UnkStruct_001CE1A0_pad g1;
    *dist = 999;
    *idx = -1;
    for (int i = 0; i < field_200->field_0; i++) {
        int type = field_200->field_8[i].field_0;
        bool test;
        if (!chk || field_210 != 0) {
            test = true;
        } else {
            if (type == 0x26 || func_001CE1A0_inl1(type) || func_001CE1A0_inl2(type)) test = true;
            else test = false;
        }
        if (field_210 != 0) {
            if (func_001CE1A0_inl3(DotProduct(field_200->field_4[i].field_30, field_204->field_10)) < 0.25f) test = false;
        }
        if (test) {
            float t, u, v;
            if (IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(
                    &line, &field_200->field_4[i].field_0, &field_200->field_4[i].field_10, &field_200->field_4[i].field_20, &t, &u, &v) && t < *dist) {
                *dist = t;
                *idx = i;
            }
        }
        if (type == 0x26) {
            field_CC4->field_324 = 0.2f;
        } else {
            float &f = field_CC4->field_324;
            if (0.2f == f) f = 1.2f;
        }
    }
    *dist *= func_001CE1A0_inl3(func_001CE1A0_inl4(pa, pb).GetLength());
    return *idx >= 0;
}
