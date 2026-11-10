// NONMATCHING: DetectCrashNearMiss__8CB3ScoreFPCQ29GtMathPs212CGtMatrix3x4PC17CGtAxisAlignedBoxi -- retail 283 / ours 279 instructions, 76 in changed runs
// v300: logic complete (horizontal NormaliseGetLength in place, dot>=0.5 gate, 4 end-to-end GetLength tests vs gmrCrashEscapeRadius, min-distance record into field_4A0[i]); goto-form + scoped opt_repositioncode off [G] gives retail block order. Left: record helper's store inline (retail: out-of-line swc1 + b back), nops our asm assembler inserts around mtc1/sqrt.s/mfc1 (retail none, N217 open), VU numbering (mPos vf7 / d vf3 in retail)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3Score::DetectCrashNearMiss(const CGtMatrix3x4*,const CGtAxisAlignedBox*,int) -- hand-written (v300); the lifter
// refused it (sqrt.s). [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/. Field names are placeholders; every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtAxisAlignedBox {
public:
    CGtV3d field_0;
    CGtV3d field_10;
};
struct UnkStruct_00158260_prm {
    unsigned char pad_0[0xE80];
    CGtV3d field_E80;
    CGtV3d field_E90;
};
struct UnkStruct_00158260_car {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    CGtV3d field_30;
    UnkStruct_00158260_prm *field_40;
    unsigned char pad_44[0x1968];
    signed char field_19AC;
};
struct UnkStruct_00158260_oth {
    unsigned char pad_0[0xC0];
    CGtV3d field_C0;
};
struct UnkStruct_D_0055EFEC_e {
    UnkStruct_00158260_oth *field_0;
    unsigned char pad_4[0x2C];
};
extern UnkStruct_D_0055EFEC_e D_0055EFEC[];

// [L] N185: v * s.z (lane-scaled product, compiler-chosen)
static inline CGtV3d func_00158260_inl2(const CGtV3d &v, const CGtV3d &s)
{
    u_long128 t;
    asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(v.mData), "j"(s.mData));
    return CGtV3d(t);
}
// [L] N185: compiler-chosen a + b
static inline CGtV3d func_00158260_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 t;
    asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
// [L] N185: compiler-chosen a - b
static inline CGtV3d func_00158260_inl4(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}

// [L] N185: NormaliseGetLength in place on a compiler-chosen register (retail's in-place tail, N217)
static inline XAxisType func_00158260_inl5(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %0, $vf1" "\n\t" "mtc1 %0, %1" "\n\t" "sqrt.s %1, %1" "\n\t" "mfc1 %0, %1" "\n\t"
        "qmtc2 %0, $vf1" "\n\t" "qmfc2 %0, $vf1" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %2, %2, $Q" : "=&r"(r), "=&f"(f), "+j"(v.mData));
    asm(".set reorder");
    return XAxisType(r);
}
// [L] N185: Normalise in place on a compiler-chosen register
static inline void func_00158260_inl6(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}

class CB3Score {
public:
    bool DetectCrashNearMiss(const CGtMatrix3x4 *p0, const CGtAxisAlignedBox *p1, int p2);
    unsigned char pad_0[0xC8];
    UnkStruct_00158260_car *field_C8;
    unsigned char pad_CC[0x4A0 - 0xCC];
    float field_4A0[1];
    static float gmrCrashEscapeRadius;
};

// N182: `#pragma opt_repositioncode off` ([G] scoped to this function).
#pragma push
#pragma opt_repositioncode off
// [G] the closest-distance record shared by every hit
static inline bool func_00158260_inl1(CB3Score *s, int i, float d)
{
    int off = i * 4;
    float *p = &((CB3Score *)(off + (int)s))->field_4A0[0];
    if (*p == -1.0f) goto st;
    if (!(*p <= d)) goto st;
ret:
    return true;
st:
    *p = d;
    goto ret;
}

// 0x00158260
bool CB3Score::DetectCrashNearMiss(const CGtMatrix3x4 *p0, const CGtAxisAlignedBox *p1, int p2)
{
    UnkStruct_00158260_car *car = field_C8;
    CGtV3d d = func_00158260_inl4(p0->mPos, car->field_30);
    d.SetY(0.0f);
    float dist = func_00158260_inl5(d);
    CGtV3d v;
    CGtV3d f, b, of, ob, e;
    float l1, l2, l3, l4;
    if (!(dist <= 20.0f + gmrCrashEscapeRadius)) goto r0a;
    v = D_0055EFEC[car->field_19AC].field_0->field_C0;
    v.SetY(0.0f);
    func_00158260_inl6(v);
    if (DotProduct(d, v) < 0.5f) goto r0b;
    if (dist < gmrCrashEscapeRadius) goto h0;
    f = func_00158260_inl3(car->field_30, func_00158260_inl2(car->field_20, car->field_40->field_E80));
    b = func_00158260_inl3(car->field_30, func_00158260_inl2(car->field_20, car->field_40->field_E90));
    of = func_00158260_inl3(p0->mPos, func_00158260_inl2(p0->mAt, p1->field_0));
    ob = func_00158260_inl3(p0->mPos, func_00158260_inl2(p0->mAt, p1->field_10));
    e = func_00158260_inl4(b, ob);
    e.SetY(0.0f);
    l1 = e.GetLength();
    if (l1 < gmrCrashEscapeRadius) goto h1;
    e = func_00158260_inl4(b, of);
    e.SetY(0.0f);
    l2 = e.GetLength();
    if (l2 < gmrCrashEscapeRadius) goto h2;
    e = func_00158260_inl4(f, ob);
    e.SetY(0.0f);
    l3 = e.GetLength();
    if (l3 < gmrCrashEscapeRadius) goto h3;
    e = func_00158260_inl4(f, of);
    e.SetY(0.0f);
    l4 = e.GetLength();
    if (!(l4 < gmrCrashEscapeRadius)) goto r0c;
    return func_00158260_inl1(this, p2, l4);
r0a:
    return false;
r0b:
    return false;
h0:
    return func_00158260_inl1(this, p2, dist);
h1:
    return func_00158260_inl1(this, p2, l1);
h2:
    return func_00158260_inl1(this, p2, l2);
h3:
    return func_00158260_inl1(this, p2, l3);
r0c:
    return false;
}
#pragma pop
