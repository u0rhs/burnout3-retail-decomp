// NONMATCHING: RenderNearMissData__15CB3TrafficDebugFv -- retail 304 / ours 301 instructions, 181 in changed runs
// logic complete, frame 0x3A0 exact; left: player index kept in s4 (retail doesn't fold 0), ctor temps at 0xC0 vs retail 0x1C0 (16 dead slots below them), VU colouring of corners (retail c0..c3 = vf7/vf4/vf2/vf1) and loop corner 0 used in place (vf19, no copy to vf1); TransformPoint here has rows hard-coded in vf5..vf2 (not the header body); SetX/SetZ(axis) must read the argument through its address for the frame (header gap)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrafficDebug::RenderNearMissData() -- [C] name: the mangled symbol in retail's tables.
// File: B3TrafficDebug.cpp (retail_names.csv). Fields are placeholders; every type is [G] (instruction widths).
// Hand-written (lifter refused: vaddx.x): the player's box (y = 0) through its matrix, 4 debug lines; then each
// near-miss traffic vehicle's box shrunk by gmrMaxNearMissDistance, 4 lines.

typedef unsigned int u_long128 __attribute__((mode(TI)));
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;
using GtMathPs2::CGtMatrix3x4;
using GtMathPs2::XAxisType;
using GtMathPs2::ZAxisType;

class CGtLine {
public:
    CGtV3d field_0;
    CGtV3d field_10;
};
class CB3DebugManager {
public:
    unsigned char pad_0[0x10];
    void DrawLine(const CGtLine &, CGtV4d);
};
class CB3Score {
public:
    static float gmrMaxNearMissDistance;
};
class CB3TrafficDebug {
public:
    void RenderNearMissData();
};
struct UnkStruct_002EFE00_m {
    unsigned char pad_0[0xE80];
    CGtV3d field_E80;
    CGtV3d field_E90;
};
struct UnkStruct_002EFE00_p {
    CGtMatrix3x4 field_0;
    UnkStruct_002EFE00_m * field_40;
};
struct UnkStruct_002EFE00_tv {
    unsigned char pad_0[0x70];
    UnkStruct_002EFE00_p field_70;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
extern CB3DebugManager D_004EB1E0;
extern unsigned char D_0055D79C[];
extern UnkStruct_002EFE00_p * D_0064D388[];
extern UnkStruct_D_00522660 D_00522660;

// [L] N185: stand-ins for missing GtMathPs2 inlines (operator +/-(XAxisType/ZAxisType, float), B3O0PCH map, 80 bytes;
// operator -(YAxisType, float)'s body on lanes x/z).
static inline XAxisType func_002EFE00_inl1(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.lVector), "j"(s)); return XAxisType(r); }
static inline XAxisType func_002EFE00_inl2(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.lVector), "j"(s)); return XAxisType(r); }
static inline ZAxisType func_002EFE00_inl3(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.lVector), "j"(s)); return ZAxisType(r); }
static inline ZAxisType func_002EFE00_inl4(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.z %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.lVector), "j"(s)); return ZAxisType(r); }
// [L] N185: stands in for the TransformPoint(const CGtMatrix3x4&, CGtV3d) retail inlines here (B3O0PCH map, 112 bytes): rows
// moved into compiler-chosen VU registers (shared by consecutive calls), the point through $vf1.
// [L] N129-style probe: CGtV3d::SetX(XAxisType)/SetZ(ZAxisType) with the argument read through its address.
static inline void func_002EFE00_inl6(CGtV3d & v, XAxisType a) { asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(*(const u_long128 *)&a.lVector)); }
static inline void func_002EFE00_inl7(CGtV3d & v, ZAxisType a) { asm("vaddz.z %0, $vf0, %1z" : "+j"(v.mData) : "j"(*(const u_long128 *)&a.lVector)); }
static inline CGtV3d func_002EFE00_inl5(const CGtMatrix3x4 & m, CGtV3d v) {
    u_long128 t;
    asm("qmtc2.i %0, $vf1" : : "r"(*(const u_long128 *)&v.mData));
    asm("qmtc2.i %1, $vf5" "\n\t" "vmulax.xyz $ACC, $vf5, $vf1x" "\n\t" "qmtc2.i %2, $vf4" "\n\t"
        "vmadday.xyz $ACC, $vf4, $vf1y" "\n\t" "qmtc2.i %3, $vf3" "\n\t" "vmaddaz.xyz $ACC, $vf3, $vf1z" "\n\t"
        "qmtc2.i %4, $vf2" "\n\t" "vmaddw.xyz $vf1, $vf2, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "r"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}

// 0x002EFE00
void CB3TrafficDebug::RenderNearMissData()
{
    int player = 0;
    int n = D_0055D79C[player];
    CGtLine line;
    CGtV3d box[4];
    CGtV3d pts[4];
    CGtV4d red(1.0f, 0.0f, 0.0f, 1.0f);
    CGtV4d green(0.0f, 1.0f, 0.0f, 1.0f);
    UnkStruct_002EFE00_p * p = D_0064D388[player];
    func_002EFE00_inl6(box[0], p->field_40->field_E80.X());
    box[0].SetY(0.0f);
    func_002EFE00_inl7(box[0], p->field_40->field_E80.Z());
    func_002EFE00_inl6(box[1], p->field_40->field_E80.X());
    box[1].SetY(0.0f);
    func_002EFE00_inl7(box[1], p->field_40->field_E90.Z());
    func_002EFE00_inl6(box[2], p->field_40->field_E90.X());
    box[2].SetY(0.0f);
    func_002EFE00_inl7(box[2], p->field_40->field_E90.Z());
    func_002EFE00_inl6(box[3], p->field_40->field_E90.X());
    box[3].SetY(0.0f);
    func_002EFE00_inl7(box[3], p->field_40->field_E80.Z());
    pts[0] = func_002EFE00_inl5(p->field_0, box[0]);
    pts[1] = func_002EFE00_inl5(p->field_0, box[1]);
    pts[2] = func_002EFE00_inl5(p->field_0, box[2]);
    pts[3] = func_002EFE00_inl5(p->field_0, box[3]);
    line.field_0 = pts[0];
    line.field_10 = pts[1];
    D_004EB1E0.DrawLine(line, green);
    line.field_0 = pts[1];
    line.field_10 = pts[2];
    D_004EB1E0.DrawLine(line, green);
    line.field_0 = pts[2];
    line.field_10 = pts[3];
    D_004EB1E0.DrawLine(line, green);
    line.field_0 = pts[3];
    line.field_10 = pts[0];
    D_004EB1E0.DrawLine(line, green);
    unsigned char * row = (unsigned char *)&D_00522660 + player * 8;
    for (int i = 0; i < n; i++) {
        unsigned char id = row[i + 0x3B08E];
        UnkStruct_002EFE00_tv * tv = (UnkStruct_002EFE00_tv *)((char *)&D_00522660 + id * 0x180 + 0x175B0);
        float d = CB3Score::gmrMaxNearMissDistance;
        UnkStruct_002EFE00_m * m = tv->field_70.field_40;
        func_002EFE00_inl6(box[0], func_002EFE00_inl1(m->field_E80.X(), d));
        box[0].SetY(0.0f);
        func_002EFE00_inl7(box[0], func_002EFE00_inl3(m->field_E80.Z(), d));
        func_002EFE00_inl6(box[1], func_002EFE00_inl1(m->field_E80.X(), d));
        box[1].SetY(0.0f);
        func_002EFE00_inl7(box[1], func_002EFE00_inl4(m->field_E90.Z(), d));
        func_002EFE00_inl6(box[2], func_002EFE00_inl2(m->field_E90.X(), d));
        box[2].SetY(0.0f);
        func_002EFE00_inl7(box[2], func_002EFE00_inl4(m->field_E90.Z(), d));
        func_002EFE00_inl6(box[3], func_002EFE00_inl2(m->field_E90.X(), d));
        box[3].SetY(0.0f);
        func_002EFE00_inl7(box[3], func_002EFE00_inl3(m->field_E80.Z(), d));
        pts[0] = func_002EFE00_inl5(tv->field_70.field_0, box[0]);
        pts[1] = func_002EFE00_inl5(tv->field_70.field_0, box[1]);
        pts[2] = func_002EFE00_inl5(tv->field_70.field_0, box[2]);
        pts[3] = func_002EFE00_inl5(tv->field_70.field_0, box[3]);
        line.field_0 = pts[0];
        line.field_10 = pts[1];
        D_004EB1E0.DrawLine(line, red);
        line.field_0 = pts[1];
        line.field_10 = pts[2];
        D_004EB1E0.DrawLine(line, red);
        line.field_0 = pts[2];
        line.field_10 = pts[3];
        D_004EB1E0.DrawLine(line, red);
        line.field_0 = pts[3];
        line.field_10 = pts[0];
        D_004EB1E0.DrawLine(line, red);
    }
}

