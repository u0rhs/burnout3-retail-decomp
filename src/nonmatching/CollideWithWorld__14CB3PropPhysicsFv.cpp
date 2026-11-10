// NONMATCHING: CollideWithWorld__14CB3PropPhysicsFv -- retail 170 / ours 172 instructions, 18 in changed runs
// ghvu10: logic complete (cache-sphere test, scratchpad rebuild + memcpy save, TestPosition fallback). 172/170, 18 changed: retail loads field_560 once with lqc2 (vf3) for the vsub and stores that VU value for the Radius() copy (sqc2); ours loads it with lq into a GPR (WAxisType copy ctor's "r") and qmtc2s it (+2 instrs). Frame 0x160 vs 0x1C0 (6 dead 16-byte slots not yet padded). Tried const&/copy/pointer-pun/sphere-inline forms for the subtract.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3PropPhysics::CollideWithWorld() -- hand-written (ghvu10, Ghidra draft; CacheWorldTriangles 0x1ABE70 as the field guide).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3PropPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001BDF60_cache { int field_0; void *field_4; void *field_8; };
struct UnkStruct_001BDF60_mat { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_001BDF60_trk { unsigned char pad_0[0x1CC]; };
struct UnkStruct_D_00522660_cwt { unsigned char pad_0[0x12A348]; UnkStruct_001BDF60_trk field_12A348[2]; };
struct UnkStruct_D_0051BA88 { void *field_0; unsigned char pad_4[0xC]; };
class CB3PropPhysics {
public:
    void CollideWithWorld();
    unsigned char pad_0[0x1C0];
    CGtSphere field_1C0;
    unsigned char pad_1D0[0x30];
    UnkStruct_001BDF60_cache *field_200;
    UnkStruct_001BDF60_mat *field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    signed char field_216;
    signed char field_217;
    unsigned char pad_218[0x18];
    int field_230;
    unsigned char pad_234[0x32C];
    CGtSphere field_560;
};
extern UnkStruct_D_00522660_cwt D_00522660;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned char D_0051AEC0[];
extern float krPropCacheSphereRadiusIncrement;
extern "C" signed char TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(UnkStruct_001BDF60_trk *, const CGtV3d *);
extern "C" void CacheWorldTriangles__16CB3CollidingBodyFv(CB3PropPhysics *);
extern "C" void CollideWithWorld__16CB3CollidingBodyFv(CB3PropPhysics *);
extern "C" void func_001AB010(CB3PropPhysics *);
extern "C" void *memcpy(void *, const void *, unsigned);

// [L] N185: a sphere's w lane plus a scalar moved into $vf2 (retail `qmtc2.ni s,$vf2; vaddx.w D,D,$vf2x`).
static inline CGtSphere func_001BDF60_inl1(const CGtSphere &s, float f) { u_long128 t = s.mData; asm("qmtc2.ni %1, $vf2\n\tvaddx.w %0, %0, $vf2x" : "+j"(t) : "r"(f)); CGtSphere r; r.mData = t; return r; }
// [L] N185: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers.
static inline CGtV3d func_001BDF60_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: XAxisType -> float without the address-taken read.
static inline float func_001BDF60_inl4(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }

// 0x001BDF60
void CB3PropPhysics::CollideWithWorld()
{
    UnkStruct_001BDF60_cache *saved = field_200;
    int old = field_216;
    if (field_230 != -1) {
        float d = func_001BDF60_inl4(func_001BDF60_inl3(field_560.Position(), field_204->field_30).GetLength());
        if (func_001BDF60_inl1(field_1C0, d).Radius() > field_560.Radius()) field_230 = -1;
    }
    if (field_230 == -1) {
        field_560.SetPosition(field_204->field_30);
        field_560.SetRadius(func_001BDF60_inl1(field_1C0, krPropCacheSphereRadiusIncrement).Radius());
        float r = field_1C0.Radius();
        field_1C0.SetRadius(field_560.Radius());
        field_200 = (UnkStruct_001BDF60_cache *)0x70002000;
        UnkStruct_001BDF60_cache *p = field_200;
        p->field_0 = 0;
        p->field_4 = (char *)p + 0x10;
        p->field_8 = (char *)p + 0x1810;
        CacheWorldTriangles__16CB3CollidingBodyFv(this);
        if (field_200->field_0 <= 12) {
            saved->field_0 = field_200->field_0;
            memcpy(saved->field_4, field_200->field_4, saved->field_0 << 6);
            memcpy(saved->field_8, field_200->field_8, saved->field_0 << 1);
        }
        field_1C0.SetRadius(r);
    } else {
        field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(&D_00522660.field_12A348[field_217], &field_204->field_30);
        if (D_0051BA88.field_0 == D_0051AEC0 && field_216 == -1) {
            field_217 = 1 - field_217;
            field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(&D_00522660.field_12A348[field_217], &field_204->field_30);
        }
    }
    if (old == -1 && field_216 != -1) func_001AB010(this);
    if (field_216 != -1) CollideWithWorld__16CB3CollidingBodyFv(this);
    field_200 = saved;
}
