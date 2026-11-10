// CB3AIAvoidanceMap::CalcRiskOfPosition(const CB3AILane*,unsigned short,GtMathPs2::CGtV3d,float*,float*,float*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Ghidra draft; SetY(0)/Normalise/vsub stand-ins, header DotProduct, mfc1 bit test, pmaxw/pminw/pextlw clamp, right before side + one N140 pad).

// CB3AIAvoidanceMap::CalcRiskOfPosition(const CB3AILane*, unsigned short, CGtV3d, float*, float*, float*) const --
// hand-written (ghvu7) from the Ghidra draft. [C] name: the mangled symbol in retail's tables. Field names are
// placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EAIAvoidanceRisk {};
class CB3AILane {
public:
    float GetTotalWidth(unsigned short p0, unsigned short p1) const;
    void GetSidePosition(unsigned short, int, CGtV3d *) const;
    void GetAvgRightwardsVector(unsigned short, CGtV3d *) const;
};
struct UnkStruct_0013DD30_car {
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
};
class CB3AIAvoidanceMap {
public:
    unsigned char pad_0[0x40];
    signed char field_40[0x404];
    float field_444;
    unsigned char pad_448[4];
    float field_44C;
    unsigned char pad_450[4];
    UnkStruct_0013DD30_car *field_454;
    void GetChannelRisk(int p0, float *p1, float *p2, float *p3) const;
    EAIAvoidanceRisk CalcRiskOfPosition(const CB3AILane *, unsigned short, CGtV3d, float *, float *, float *) const;
};

// [L] integer clamp helpers (MMI, as B3HUDManager_001A0020.cpp): pmaxw / pminw, then zero-extended with pextlw.
static inline int func_0013DD30_inl1(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_0013DD30_inl2(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_0013DD30_inl3(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
// [L] N185: CGtV3d::SetY(float) on a compiler-chosen register (the scalar by its own "=j" statement).
static inline void func_0013DD30_inl4(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// [L] N185: Normalise on a compiler-chosen register, the result moved out .i (as func_001419F0's near20_norm).
static inline void func_0013DD30_inl5(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v.mData));
    asm(".set reorder");
    v.mData = t;
}
// [L] N185: CGtV3d::operator- on compiler-chosen registers.
static inline CGtV3d func_0013DD30_inl6(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }

// N140 pad: one dead 16-byte frame slot retail keeps [G].
struct UnkStruct_0013DD30_pad { int x[4]; UnkStruct_0013DD30_pad() {} ~UnkStruct_0013DD30_pad() {} };
// 0x0013DD30
EAIAvoidanceRisk CB3AIAvoidanceMap::CalcRiskOfPosition(const CB3AILane *lane, unsigned short seg, CGtV3d pos, float *p1, float *p2, float *p3) const
{
    CGtV3d pc = pos;
    CGtV3d right;
    CGtV3d side;
    UnkStruct_0013DD30_pad pad;
    *p1 = 0.0f;
    *p2 = 0.0f;
    *p3 = 0.0f;
    if (field_444 == 0.0f) return (EAIAvoidanceRisk)0;
    float w = lane->GetTotalWidth(seg, seg);
    unsigned int bits;
    asm("mfc1 %0, %1" : "=r"(bits) : "f"(w));
    if ((bits & 0x7F800000) <= 0x37800000) return (EAIAvoidanceRisk)0;
    float w2;
    if (seg == field_454->field_18B8 && lane == field_454->field_18B4) {
        w2 = w;
    } else {
        w2 = field_454->field_18B4->GetTotalWidth(field_454->field_18B8, field_454->field_18B8);
    }
    lane->GetSidePosition(seg, 1, &side);
    lane->GetAvgRightwardsVector(seg, &right);
    func_0013DD30_inl4(right, 0.0f);
    func_0013DD30_inl5(right);
    float d = DotProduct(func_0013DD30_inl6(pc, side), right);
    // [G] retail negates, then subtracts the constant -128 (neg.s; sub.s with 0xC3000000).
    int ch = (int)(-(5.0f * (w2 * (d / w - (field_444 - field_44C) / field_444))) - -128.0f);
    unsigned int c = func_0013DD30_inl3(func_0013DD30_inl2(func_0013DD30_inl3(func_0013DD30_inl1(ch, 0)), 255));
    GetChannelRisk(c, p1, p2, p3);
    return (EAIAvoidanceRisk)field_40[c];
}
