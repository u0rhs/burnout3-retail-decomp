// NONMATCHING: DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d -- retail 86 / ours 84 instructions, 25 in changed runs
// stabs3: score 43 -> 33 (86/84, 25 changed). Revenge-driven: colour packed by an inline returning the RwRGBA by value (Revenge lPackedColour, not address-taken), no CGtV3d point copy (Revenge has none) -> pack/VU schedule right. Left: frame 0x50 vs 0x60 and retail reads colour bytes 1..3 through address registers (sp+0x5D..0x5F); address-taken forms keep that but break the schedule (43-55)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (logic unchanged)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185: file-local stand-ins (retail's non-hoisted forms: 1.0 parked in a GPR, compiler-chosen VU registers)
static inline float a210_abs(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline u_long128 a210_one() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
static inline u_long128 a210_dot(u_long128 a, u_long128 b)
{
    u_long128 one = a210_one();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %2" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a), "j"(b));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return d;
}
static inline u_long128 a210_sqlen(u_long128 a)
{
    u_long128 one = a210_one();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return d;
}
static inline void a210_sety(u_long128 &v, float y)
{
    asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v) : "r"(y));
}
static inline u_long128 a210_sub(u_long128 a, u_long128 b)
{
    asm("vsub.xyz %0, %1, %0" : "+j"(b) : "j"(a));
    return b;
}
static inline u_long128 a210_neg(u_long128 a)
{
    u_long128 t;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsub.x $vf1, $vf0, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a));
    return t;
}
static inline u_long128 a210_norm(u_long128 a)
{
    u_long128 l = a210_sqlen(a);
    u_long128 t, v = a;
    asm volatile("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t"
        "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v) : "r"(l));
    return t;
}
static inline float a210_f(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }
static inline u_long128 a210_cross(u_long128 a, u_long128 b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b) : "j"(a));
    return t;
}
static inline u_long128 a210_xsubf(u_long128 a, float f)
{
    asm("qmtc2.ni %1, $vf2" "\n\t" "vsubx.x %0, %0, $vf2x" : "+j"(a) : "r"(f));
    return a;
}
static inline u_long128 a210_len(u_long128 a)
{
    u_long128 l = a210_sqlen(a);
    u_long128 one, r;
    asm("qmtc2.i %2, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r), "=&r"(one) : "r"(l));
    return r;
}
class CGtTexture;
class CB3Im3dVertex;
struct UnkStruct_00130750_rgba { unsigned char r, g, b, a; };
struct UnkStruct_dl_vtx { CGtV3dPlus field_0; unsigned char pad_10[8]; UnkStruct_00130750_rgba field_18; unsigned char pad_1C[4]; };
struct CGtLine { CGtV3d field_0; CGtV3d field_10; };
class B3Im3d {
public:
    static void BeginRendering();
    static void SetTexture(CGtTexture*);
    static void RenderLinelist(const CB3Im3dVertex*, int);
    static void EndRendering();
};
struct UnkStruct__gnDebugNumPoints { int field_0; };
struct UnkStruct__gnDebugMaxNumPoints { int field_0; };
struct UnkStruct__gaDebugPointsArray { UnkStruct_dl_vtx field_0[1]; unsigned char pad[0x10]; };
extern UnkStruct__gnDebugNumPoints _gnDebugNumPoints;
extern UnkStruct__gnDebugMaxNumPoints _gnDebugMaxNumPoints;
extern UnkStruct__gaDebugPointsArray _gaDebugPointsArray;
class CB3DebugManager {
public:
    void DrawLine(const CGtLine &line, CGtV4d col);
};
static inline u_long128 a210_ftoi(u_long128 x) { u_long128 r; asm("vftoi0.xyzw %0, %1" : "=j"(r) : "j"(x)); return r; }
static inline u_long128 a210_pminw(u_long128 a, u_long128 b) { u_long128 r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline u_long128 a210_pextlh0(unsigned long a) { u_long128 r; asm("pextlh %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
static inline unsigned int a210_pack(u_long128 a) { u_long128 r; unsigned int s; asm("ppach %0, $0, %1" : "=r"(r) : "r"(a)); asm("ppacb %0, $0, %1" : "=r"(s) : "r"(r)); return s; }
static inline u_long128 a210_scale(u_long128 v, float s) { u_long128 r; asm("qmtc2.ni %2, $vf1" "\n\t" "vmulx.xyzw %0, %1, $vf1x" : "=j"(r) : "j"(v), "r"(s)); return r; }
static inline CGtV4d func_00130750_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
static inline unsigned int func_00130750_col(CGtV4d c) {
    CGtV4d s(a210_scale(c.mData, 128.0f));
    u_long128 i, lim, m, h;
    unsigned int b;
    asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(s.mData));
    unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
    asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
    asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
    asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    return b;
}
static inline UnkStruct_00130750_rgba func_00130750_rgba(CGtV4d c) {
    UnkStruct_00130750_rgba r;
    *(unsigned int *)&r = func_00130750_col(c);
    return r;
}
void CB3DebugManager::DrawLine(const CGtLine &line, CGtV4d col)
{
    if (_gnDebugNumPoints.field_0 > _gnDebugMaxNumPoints.field_0 - 1) {
        if (_gnDebugNumPoints.field_0 % 2 > 0) {
            _gnDebugNumPoints.field_0 = _gnDebugNumPoints.field_0 - 1;
        }
        B3Im3d::BeginRendering();
        B3Im3d::SetTexture(0);
        B3Im3d::RenderLinelist((const CB3Im3dVertex *)&_gaDebugPointsArray, _gnDebugNumPoints.field_0);
        B3Im3d::EndRendering();
        _gnDebugNumPoints.field_0 = 0;
    }
    UnkStruct_00130750_rgba rgba = func_00130750_rgba(col);
    int n0 = _gnDebugNumPoints.field_0;
    UnkStruct_dl_vtx *v0 = &_gaDebugPointsArray.field_0[n0];
    int n = n0 + 1;
    UnkStruct_dl_vtx *v1 = &_gaDebugPointsArray.field_0[n];
    _gnDebugNumPoints.field_0 = n + 1;
    v0->field_0.SetGtV3d(line.field_0);
    v0->field_18 = rgba;
    v1->field_0.SetGtV3d(line.field_10);
    v1->field_18 = rgba;
}

