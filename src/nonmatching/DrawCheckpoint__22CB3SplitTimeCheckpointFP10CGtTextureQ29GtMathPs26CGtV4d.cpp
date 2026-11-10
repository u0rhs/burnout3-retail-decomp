// NONMATCHING: DrawCheckpoint__22CB3SplitTimeCheckpointFP10CGtTextureQ29GtMathPs26CGtV4d -- retail 168 / ours 164 instructions, 166 in changed runs
// ghvu10 draft: logic from retail (cross(up,dir) normalised, up*D_004E1568 / side*D_004E156C, colour pack to a 4-byte struct copied to 4 vertices, 4 sums + ofs(0,11,0), UVs). 164/168, 166 changed: retail REUSES compiler-chosen VU registers (vf2 = SetW vertex, then the square, then o->pos; vf3 = vertex, normalised side, 128.0 scalar), which b119 never does; also 4 dead 16-byte temps 0xE0-0x110 and a 0x14C colour slot.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SplitTimeCheckpoint::DrawCheckpoint(CGtTexture*, GtMathPs2::CGtV4d) -- hand-written (ghvu10, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G]. D_004E1568 / D_004E156C are function statics
// (lrHeight / lrWidth in the name tables, no symbol form [medium]).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtTexture;
struct UnkStruct_0015E340_col { unsigned char r, g, b, a; };
// [L] N185: CGtV3dPlus::SetPlus(float) with the scalar moved by its own statement (as RenderSquare's stand-in).
static inline void func_0015E340_inl1(CGtV3dPlus &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d.mData) : "j"(s)); }
// [L] N185: CGtV4d::operator*(float) with the scalar moved by its own statement.
static inline CGtV4d func_0015E340_inl2(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
// [L] N185: Normalise on a compiler-chosen register that also forms 1.0*Q (as func_0027BCE0_inl1).
static inline void func_0015E340_inl3(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData), "=&r"(one) : "r"(l.lVector));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r.mData), "+r"(one) : "j"(v.mData));
    asm(".set reorder");
    v = r;
}
// [L] N185: CGtV3d::operator*(float) / + / - / unary - on compiler-chosen registers.
static inline CGtV3d func_0015E340_mul(const CGtV3d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV3d(t); }
static inline CGtV3d func_0015E340_add(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_0015E340_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_0015E340_neg(const CGtV3d &a) { u_long128 r; asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a.mData)); return CGtV3d(r); }

struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    float field_10;
    float field_14;
    UnkStruct_0015E340_col field_18;
    unsigned char pad_1C[4];
    CB3Im3dVertex() { func_0015E340_inl1(field_0, 0.0f); }
};
struct UnkStruct_0015E340_obj { CGtV3d field_0; CGtV3d field_10; };
class CB3SplitTimeCheckpoint {
public:
    void DrawCheckpoint(CGtTexture *, CGtV4d);
    UnkStruct_0015E340_obj *field_0;
};
extern float D_004E1568;
extern float D_004E156C;
extern "C" {
void BeginRendering__6B3Im3dFv();
void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
void SetAlphaTestThreshold__6B3Im3dFf(float);
void RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
void EndRendering__6B3Im3dFv();
}

// [L] N185: CrossProduct(a, b) with b and the result through GPRs (`.i` moves; cf. func_00147F50_inl1), a on a
// compiler-chosen register that stays live.
static inline CGtV3d func_0015E340_cross(const CGtV3d &a, u_long128 b)
{
    u_long128 t;
    asm("qmtc2.i %2, $vf1" "\n\t" "vopmula.xyz $ACC, %1, $vf1" "\n\t" "vopmsub.xyz $vf1, $vf1, %1" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(a.mData), "r"(b));
    return CGtV3d(t);
}
// [L] N185: SetGtV3d reading its argument through its address (v306: one dead slot per call).
static inline void func_0015E340_set(CGtV3dPlus &d, CGtV3d v) { asm("vadd.xyz %0, $vf0, %1" : "+j"(d.mData) : "j"(*(const u_long128 *)&v.mData)); }

// 0x0015E340
void CB3SplitTimeCheckpoint::DrawCheckpoint(CGtTexture *tex, CGtV4d colour)
{
    CB3Im3dVertex v[4];
    CGtV3d up(0.0f, 1.0f, 0.0f);
    CGtV3d ofs(0.0f, 11.0f, 0.0f);
    UnkStruct_0015E340_obj *o = field_0;
    CGtV3d side = func_0015E340_cross(up, o->field_10.mData);
    func_0015E340_inl3(side);
    up = func_0015E340_mul(up, D_004E1568);
    side = func_0015E340_mul(side, D_004E156C);
    CGtV4d s = func_0015E340_inl2(colour, 128.0f);
    u_long128 i, lim, m, h;
    unsigned int b;
    asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(s.mData));
    unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
    asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
    asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
    asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    UnkStruct_0015E340_col c;
    *(unsigned int *)&c = b;
    v[0].field_18 = c;
    v[1].field_18 = c;
    v[2].field_18 = c;
    v[3].field_18 = c;
    func_0015E340_set(v[0].field_0, func_0015E340_add(func_0015E340_add(func_0015E340_add(up, side), o->field_0), ofs));
    func_0015E340_set(v[1].field_0, func_0015E340_add(func_0015E340_add(func_0015E340_sub(up, side), o->field_0), ofs));
    func_0015E340_set(v[2].field_0, func_0015E340_add(func_0015E340_add(func_0015E340_add(func_0015E340_neg(up), side), o->field_0), ofs));
    func_0015E340_set(v[3].field_0, func_0015E340_add(func_0015E340_add(func_0015E340_sub(func_0015E340_neg(up), side), o->field_0), ofs));
    v[0].field_10 = 0.0f;
    v[0].field_14 = 0.0f;
    v[1].field_10 = 1.0f;
    v[1].field_14 = 0.0f;
    v[2].field_10 = 0.0f;
    v[2].field_14 = 1.0f;
    v[3].field_10 = 1.0f;
    v[3].field_14 = 1.0f;
    BeginRendering__6B3Im3dFv();
    SetTexture__6B3Im3dFP10CGtTexture(tex);
    SetAlphaTestThreshold__6B3Im3dFf(0.25f);
    RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(v, 4);
    EndRendering__6B3Im3dFv();
}
