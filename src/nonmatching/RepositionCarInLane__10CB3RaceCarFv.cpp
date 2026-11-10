// NONMATCHING: RepositionCarInLane__10CB3RaceCarFv -- retail 188 / ours 189 instructions, 63 in changed runs
// mat1 (N239): retail's matrix staging reproduced with real CGtMatrix3x4 copies: GetAvgForwardsVector writes m3.mAt (sp+0x120 = m3 row 2), header Normalise, then a look-at inline (local m at 0x60, mPos unwritten) assigns out = m into m2 (row-0 sq + three lb/sb loops), m3 = m2 (lq/sq), m3.mPos = interpolate; named up(0,1,0) + one N140 pad give frame 0x140 exact. Stand-ins: cross with qmfc2.i round trip (both crosses exact), interpolate in the CGtV4d shape (a/t compiler-chosen, b on $vf1: retail's vf1/vf2), in-place normalise. Left 62: head scheduling (retail re-zero-extends seg with andi and reloads lane->field_4 after the switch; mfc1 of w hoisted), second normalise's square on vf1 (retail vf2), m.mUp stored through a held pointer. Header note: Interpolate(CGtV3d) body folds b's qmtc2.ni into lqc2 here and puts a on vf3 (retail: lq + qmtc2, a on vf1) | N266-N268 header APIs (gapH)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3RaceCar::RepositionCarInLane() -- hand-written from the Ghidra draft (ghvu11).
// [C] name: the mangled symbol in retail's tables (high). Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00151160_e { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00151160_s { unsigned char pad_0[3]; unsigned char field_3; unsigned char pad_4[6]; };
struct UnkStruct_00151160_l2 { UnkStruct_00151160_e *field_0; unsigned char pad_4[4]; UnkStruct_00151160_s *field_8; };
class CB3AILane {
public:
    unsigned char pad_0[4];
    UnkStruct_00151160_l2 *field_4;
};
struct UnkStruct_D_0064D354 { CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_D_0055EFEC_r { void *field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_D_0055EFEC_r D_0055EFEC[];
extern "C" void GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(const CB3AILane *, unsigned short, CGtV3d *);
extern "C" void func_001AB610(void *, const CGtMatrix3x4 *);
// [L] N185: the in-place normalise (vmulq on a compiler-chosen register; the header Normalise uses $vf1)
static inline void func_00151160_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" : : "r"(l.lVector));
    asm(".set reorder");
    u_long128 t, x = v.mData;
    asm("vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(x));
    v.mData = t;
}
// [L] N185: CrossProduct with the result moved out through a GPR (.i keeps the qmfc2/qmtc2 round trip retail has)
static inline CGtV3d func_00151160_inl2(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// [L] N185: Interpolate(CGtV3d, CGtV3d, float) in the CGtV4d Interpolate's shape on the xyz lanes (a and t compiler-chosen,
// b moved into $vf1 inside a noreorder region): retail's a on $vf1 / t on $vf2; the header body puts a on $vf3 here
static inline CGtV3d func_00151160_inl3(CGtV3d a, CGtV3d b, float t)
{
    u_long128 tv, r;
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyz $ACC, %1, %0x" : "=&j"(tv) : "j"(a.mData), "r"(t));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddx.xyz $vf1, $vf1, %2x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(b.mData), "j"(tv));
    asm(".set reorder");
    return CGtV3d(r);
}
// [G] a look-at block (right = Normalise(up x at), up = at x right, mPos untouched; the E map's Matrix3x4SetLookAt(CGtV3d,
// CGtV3d) would fit) -- placeholder. Its local m sits below the caller's named up (retail frame: m 0x60, up 0xA0/0xB0)
static inline void func_00151160_inl6(CGtMatrix3x4 &out, const CGtV3d &at, const CGtV3d &up)
{
    CGtMatrix3x4 m;
    m.mAt = at;
    m.mRight = func_00151160_inl2(up, m.mAt);
    func_00151160_inl1(m.mRight);
    m.mUp = func_00151160_inl2(m.mAt, m.mRight);
    out = m;
}
struct UnkStruct_00151160_pad { int x[4]; UnkStruct_00151160_pad() {} ~UnkStruct_00151160_pad() {} };

class CB3RaceCar {
public:
    void RepositionCarInLane();
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[2];
    float field_18BC;
    unsigned char pad_18C0[0x10];
    CGtV3d field_18D0;
    unsigned char pad_18E0[0xCC];
    signed char field_19AC;
};

// 0x00151160
void CB3RaceCar::RepositionCarInLane()
{
    unsigned short seg = field_18B8;
    CB3AILane *lane = field_18B4;
    float w;
    switch (lane->field_4->field_8[seg].field_3 >> 6) {
    default: case 3: w = 0.5f; break;
    case 1: w = 0.2f; break;
    case 2: w = 0.8f; break;
    }
    float t = field_18BC;
    UnkStruct_00151160_e *e = &lane->field_4->field_0[seg];
    CGtV3d *p = D_0064D354.field_0;
    CGtMatrix3x4 m3;
    CGtMatrix3x4 m2;
    UnkStruct_00151160_pad pad0;
    CGtV3d i1 = func_00151160_inl3(p[e[1].field_0], p[e[1].field_2], w);
    CGtV3d i0 = func_00151160_inl3(p[e[0].field_0], p[e[0].field_2], w);
    GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, seg, &m3.mAt);
    m3.mAt.Normalise();
    field_18D0 = m3.mAt;
    m3 = Matrix3x4SetLookAt(m3.mAt);
    m3.mPos = func_00151160_inl3(i1, i0, t);
    func_001AB610(D_0055EFEC[field_19AC].field_0, &m3);
}
