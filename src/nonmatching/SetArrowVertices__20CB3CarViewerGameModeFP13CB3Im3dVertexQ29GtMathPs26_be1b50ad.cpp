// NONMATCHING: SetArrowVertices__20CB3CarViewerGameModeFP13CB3Im3dVertexQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV4d -- retail 73 / ours 73 instructions, 23 in changed runs
// psweep: scoped #pragma opt_propagation off [G] improves 43 -> 23
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3CarViewerGameMode::SetArrowVertices(CB3Im3dVertex*, CGtV3d, CGtV3d, CGtV3d, CGtV3d, CGtV4d) -- hand-written (ghvu1,
// Ghidra-draft trial). [C] name: the mangled symbol in retail's tables. Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
using namespace GtMathPs2;
struct UnkStruct_0024D980_c { unsigned char field_0; unsigned char field_1; unsigned char field_2; unsigned char field_3; };
union UnkUnion_0024D980_c { unsigned int u; UnkStruct_0024D980_c c; };
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    UnkStruct_0024D980_c field_18;
    unsigned char pad_1C[4];
};
// [L] N185: CB3Im3dVertex::SetColour's packing (B3O0PCH map, 0x44; v242 / B3VehicleDeform_00460C20 stand-in): col * 128,
// to int, clamped to (255,255,255,128), packed to four bytes.
static inline unsigned int func_0024D980_inl1(const CGtV4d &c)
{
    u_long128 i, lim, m, h;
    unsigned int b;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vmulx.xyzw $vf1, $vf1, $vf2x" "\n\t" "vftoi0.xyzw $vf1, $vf1" "\n\t" "qmfc2 %0, $vf1" : "=r"(i) : "r"(c.mData), "r"(128.0f));
    unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
    asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
    asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
    asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    return b;
}
// [L] N185: CGtV3dPlus::SetGtV3d with the hard-coded $vf1 body (retail reloads each vertex into $vf1).
static inline void func_0024D980_inl2(CGtV3dPlus &d, const CGtV3d &v)
{
    u_long128 m;
    asm("qmtc2 %1, $vf1" "\n\t" "vadd.xyz $vf1, $vf0, %2" "\n\t" "qmfc2 %0, $vf1" : "=r"(m) : "r"(d.mData), "j"(v.mData));
    d.mData = m;
}
static inline void func_0024D980_inl3(CGtV3dPlus &d, u_long128 v)
{
    u_long128 m;
    asm("qmtc2 %1, $vf1" "\n\t" "vadd.xyz $vf1, $vf0, %2" "\n\t" "qmfc2 %0, $vf1" : "=r"(m) : "r"(d.mData), "j"(v));
    d.mData = m;
}
class CB3CarViewerGameMode {
public:
    void SetArrowVertices(CB3Im3dVertex *v, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d d, CGtV4d col);
};
// 0x0024D980
void CB3CarViewerGameMode::SetArrowVertices(CB3Im3dVertex *v, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d d, CGtV4d col)
{
    u_long128 qa = a.mData, qb = b.mData, qc = c.mData, qd = d.mData;
    UnkUnion_0024D980_c k;
    k.u = func_0024D980_inl1(col);
    func_0024D980_inl3(v[0].field_0, qa);
    v[0].field_18 = k.c;
    func_0024D980_inl3(v[1].field_0, qb);
    v[1].field_18 = k.c;
    func_0024D980_inl3(v[2].field_0, qc);
    v[2].field_18 = k.c;
    func_0024D980_inl3(v[3].field_0, qb);
    v[3].field_18 = k.c;
    func_0024D980_inl3(v[4].field_0, qb);
    v[4].field_18 = k.c;
    func_0024D980_inl3(v[5].field_0, qd);
    v[5].field_18 = k.c;
}

#pragma pop
