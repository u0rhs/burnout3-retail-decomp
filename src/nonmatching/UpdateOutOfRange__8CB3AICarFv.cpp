// NONMATCHING: UpdateOutOfRange__8CB3AICarFv -- retail 1310 / ours 1311 instructions, 537 in changed runs
// draftC: 1310/1311, calls and branch senses identical except the RollingStart tail (retail lays the diff<-lim call inline, ours out of line); every VU/FPU op count equal. Left: OrthoNormalise X<=0/Y<=0 rebuild blocks inline (retail: at the end; header layout, queued by draftA), frame 0x1320 vs 0x1AD0 (retail keeps more 16-byte temps), CRM/SinCosFast lui scheduling. Stand-ins: IsZero raw test, NormaliseFast (func_001CB780_inl1 form), ACosDeg/AngleBetweenVectors [G]; named zero for retail's adda.s/madd.s [G]; kYAxis through a local y gives retail's over-a cross product
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every call, argument, store and branch condition decoded from retail asm (calls identical but one layout swap; op counts equal); helper set from the B3O0PCH emission queue after CB3AICar::UpdateOutOfRange

// draftC: UpdateOutOfRange__8CB3AICarFv (0x1423E0, 0x1478) -- CB3AICar::UpdateOutOfRange()
// [C] name: retail symbol table. Decoded from retail asm; helper order from the B3O0PCH map queue after
// CB3AICar::UpdateOutOfRange (OrthoNormalise, Abs, AngleBetweenVectors, ACosDeg, ACosRad, CosAngleBetweenNormalisedVectors,
// XAxisType copy, NormaliseFast, IsZero) [C map / L use].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [G] lane node pair record (4 bytes) and segment link record (10 bytes)
struct UnkStruct_001423E0_node { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_001423E0_seg { unsigned char pad_0[4]; unsigned char field_4; unsigned char field_5; unsigned short field_6; unsigned short field_8; };
struct UnkStruct_001423E0_ld { UnkStruct_001423E0_node *field_0; unsigned char pad_4[4]; UnkStruct_001423E0_seg *field_8; };
class CB3AILane { public: unsigned char pad_0[4]; UnkStruct_001423E0_ld *field_4; };
// [L] CB3RaceCarPhysics (RollingStart / SetInitialMatrix callee names, E map)
struct UnkStruct_001423E0_phys {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x7B0];
    float field_870;
    unsigned char pad_874[0xB60];
    float field_13D4;
};

class CB3AICar {
public:
    void UpdateOutOfRange();
    CGtMatrix3x4 field_0;
    unsigned char pad_40[0x1874];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0xF6];
    CGtV3d field_19B0;
    CGtV3d field_19C0;
    unsigned char pad_19D0[0x7D0];
    CGtV3d field_21A0;
    unsigned char pad_21B0[0x204];
    float field_23B4;
    unsigned char pad_23B8[0x78];
    UnkStruct_001423E0_phys *field_2430;
    float field_2434;
    unsigned char pad_2438[4];
    float field_243C;
};

// [G] size: absolute addressing needs > 8 bytes (N50)
struct UnkStruct_001423E0_f16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_001423E0_p16 { CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_001423E0_p16 D_0064D354;   // [G] lane node positions
extern CGtV3d kYAxis;
extern UnkStruct_001423E0_f16 D_0052267C;   // [C] frame time (other units)
extern UnkStruct_001423E0_f16 D_01E754E0;
extern UnkStruct_001423E0_f16 D_01E754E4;
extern "C" bool LaneIsDriveable__9CB3AILaneFUsUs(CB3AILane *, unsigned short, unsigned short);
extern "C" bool LaneIsDriveable__9CB3AILaneFUcUsUs(unsigned char, unsigned short, unsigned short);
extern "C" CB3AILane *WalkDrivableLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short *, const CGtV3d *);
extern "C" unsigned int IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUsf(CB3AILane *, const CGtV3d *, unsigned short, float);
extern "C" void GetRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
extern "C" void GetLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
extern "C" CB3AILane *FindConnectedDrivableLane__9CB3AILaneFPUs18EAISegmentLinkType(CB3AILane *, unsigned short *, int);
extern "C" void func_001AB610(UnkStruct_001423E0_phys *, const CGtMatrix3x4 *);   // [L] CB3CollidingBody::SetInitialMatrix (E map)
extern "C" void func_001BED00(UnkStruct_001423E0_phys *, float);                 // [L] CB3RaceCarPhysics::RollingStart (E map)
extern "C" float func_0011E328(float);                                           // [L] acosf (E_B3DEBUG map: LIBM.A wf_acos.o)

// [L] N185 stand-in for CGtV3d::NormaliseFast() (B3O0PCH map name; no header body): normalise on a compiler-chosen
// register that also forms 1.0*Q (as func_001CB780_inl1, proven).
static inline void func_001423E0_inl1(CGtV3d &v)
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
// [L] N185: XAxisType -> float without the address-taken read (as func_001CB780_inl2).
static inline float func_001423E0_inl2(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }
// [G] stand-in for GtMath::ACosDeg(float) (B3O0PCH map name): 57.29578f * acosf.
static inline float func_001423E0_inl3(float x) { return 57.29578f * func_0011E328(x); }
// [G] stand-in for GtMathPs2::AngleBetweenVectors(CGtV3d, CGtV3d) (B3O0PCH map name, 0xD0): both normalised, clamped cosine, ACosDeg.
static inline float func_001423E0_inl4(CGtV3d a, CGtV3d b)
{
    func_001423E0_inl1(a);
    func_001423E0_inl1(b);
    return func_001423E0_inl3(func_001423E0_inl2(CosAngleBetweenNormalisedVectors(a, b)));
}

// [G] stand-in for CGtV3d::IsZero() returning the raw test (retail branches on the or-ed lanes directly, no xor/sltiu)
static inline bool func_001423E0_inl5(const CGtV3d &v)
{
    u_long128 r, t;
    asm("mtsab $0, 4" "\n\t" "qfsrv %1, %2, %2" "\n\t" "or %0, %2, %1" "\n\t" "qfsrv %1, %1, %1" "\n\t" "or %0, %0, %1" : "=r"(r), "=&r"(t) : "r"(v.mData));
    return ((unsigned long long)r & 0x7fffffffULL) == 0;
}
// 0x001423E0
void CB3AICar::UpdateOutOfRange()
{
    CB3AILane *lane = field_18B4;
    unsigned short seg = field_18B8;
    UnkStruct_001423E0_node *n = &field_18B4->field_4->field_0[field_18B8];
    int n0 = n[0].field_0;
    int n1 = n[1].field_0;
    CGtV3d v = field_19B0;
    field_19C0 = v;
    if (func_001423E0_inl5(v)) {
        field_19B0 = field_21A0;
    } else {
        float ang = func_001423E0_inl4(field_21A0, field_19C0);
        if (ang > D_01E754E4.field_0) {
            CGtMatrix3x4 lMat;
            CGtV3d y = kYAxis;
            if (DotProduct(CrossProduct(field_19C0, y), field_21A0) > 0.0f)
                lMat = CreateRotationMatrix3x4(y, 0.017453292f * -D_01E754E4.field_0);
            else
                lMat = CreateRotationMatrix3x4(y, 0.017453292f * D_01E754E4.field_0);
            field_19B0 = TransformPoint(lMat, field_19C0);
        } else {
            field_19B0 = field_21A0;
        }
    }
    CGtV3d dir = D_0064D354.field_0[n1] - D_0064D354.field_0[n0];
    func_002EBED0_inl1(dir);
    CGtV3d at = field_19B0;
    at.SetY(at.Y() + dir.Y());
    field_0.mAt = at;
    field_0.mPos.SetY((float)(field_0.mPos.Y() - field_243C) + field_2430->field_870);
    field_0.mUp = kYAxis;
    field_0.mRight = CrossProduct(field_0.mUp, field_0.mAt);
    field_0.mRight.Normalise();
    field_0.mUp = CrossProduct(field_0.mAt, field_0.mRight);
    field_0.mUp.Normalise();
    field_0.mPos += field_19B0 * ((float)field_2430->field_B0.W() * D_0052267C.field_0);
    if (!LaneIsDriveable__9CB3AILaneFUsUs(lane, seg, 1)) {
        seg = field_18B8;
        lane = FindConnectedDrivableLane__9CB3AILaneFPUs18EAISegmentLinkType(field_18B4, &seg, 0);
        if (!lane) {
            seg = field_18B8;
            lane = FindConnectedDrivableLane__9CB3AILaneFPUs18EAISegmentLinkType(field_18B4, &seg, 1);
        }
        if (!lane) lane = field_18B4;
    }
    CB3AILane *cur = WalkDrivableLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(lane, &seg, &field_0.mPos);
    unsigned int flags = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUsf(cur, &field_0.mPos, seg, -0.5f * field_2434);
    if ((flags & 1) && !LaneIsDriveable__9CB3AILaneFUcUsUs(cur->field_4->field_8[seg].field_4, cur->field_4->field_8[seg].field_6, 1)) {
        int node = cur->field_4->field_0[seg].field_0;
        CGtV3d left;
        GetLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(cur, seg, &left);
        left.Normalise();
        float d = DotProduct(left, field_0.mPos - D_0064D354.field_0[node]);
        float z = 0.0f;
        field_0.mPos += left * -(z + d + 0.5f * field_2434);
    } else if ((flags & 2) && !LaneIsDriveable__9CB3AILaneFUcUsUs(cur->field_4->field_8[seg].field_5, cur->field_4->field_8[seg].field_8, 1)) {
        int node = cur->field_4->field_0[seg].field_2;
        CGtV3d right;
        GetRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(cur, seg, &right);
        right.Normalise();
        float d = DotProduct(right, field_0.mPos - D_0064D354.field_0[node]);
        float z = 0.0f;
        field_0.mPos += right * -(z + d + 0.5f * field_2434);
    }
    field_0.OrthoNormalise();
    func_001AB610(field_2430, &field_0);
    float lim = field_2430->field_13D4 / 970;
    float diff = (float)field_2430->field_B0.W() - field_23B4;
    if (diff <= D_01E754E0.field_0) {
        if (diff < -lim)
            func_001BED00(field_2430, lim + (float)field_2430->field_B0.W());
        else
            func_001BED00(field_2430, field_23B4);
    } else
        func_001BED00(field_2430, (float)field_2430->field_B0.W() - D_01E754E0.field_0);
}
