// CB3AIArbitrator::Update(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (L265: per-site risk checks (s && x > A) || (!s && x > B) with explicit returns, &field_200 passed as const void* (CalcRiskOfPosition link-name), 4-byte N140 pad at sp+0x70).

// CB3AIArbitrator::Update(bool) -- hand-written (L265; lifter refused): per-lane risk checks written out per site
// with `(s && x > A) || (!s && x > B)` tests and explicit returns; fail/success actions as static inlines (placeholders).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

class CB3AILane;
class CB3AIAvoidanceMap {
public:
    void GetChannelRisk(int, float *, float *, float *) const;
};
// CB3AIAvoidanceMap::CalcRiskOfPosition(const CB3AILane*, unsigned short, CGtV3d, float*, float*, float*) const:
// the by-value CGtV3d travels as a pointer (retail passes &field_200 with no copy).
extern "C" void CalcRiskOfPosition__17CB3AIAvoidanceMapCFPC9CB3AILaneUsQ29GtMathPs26CGtV3dPfPfPf(const CB3AIAvoidanceMap *, const CB3AILane *, unsigned short, const void *, float *, float *, float *);
class CB3AIAvoidance : public CB3AIAvoidanceMap {
public:
    void Update();
    unsigned char pad_0[0x470];
};
class CB3AITargetSpline {
public:
    unsigned char IsSquareCorner();
    GtMathPs2::CGtV3d GetTargetPosition();
};
struct UnkStruct_0019D6D0_phys {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
};
struct UnkStruct_0019D6D0_cp {
    unsigned char pad_0[0x204];
    UnkStruct_0019D6D0_phys * field_204;
};
struct UnkStruct_0019D6D0_car {
    unsigned char pad_0[0x18B4];
    const CB3AILane * field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x146];
    CB3AITargetSpline field_1A00;
    unsigned char pad_1A01[0xA2F];
    UnkStruct_0019D6D0_cp * field_2430;
};
class CB3AIArbitrator {
public:
    void Update(bool p1);

    unsigned char pad_0[0x1D0];
    float field_1D0;
    const CB3AILane * field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x1E];
    int field_1F8;
    int field_1FC;
    GtMathPs2::CGtV3d field_200;
    unsigned short field_210;
    unsigned char field_212;
    unsigned char pad_213[0x9D];
    CB3AIAvoidance field_2B0;
    GtMathPs2::CGtV3d field_720;
    unsigned char pad_730[0x4];
    float field_734;
    float field_738;
    unsigned char pad_73C[0x4];
    float field_740;
    float field_744;
    float field_748;
    float field_74C;
    unsigned char pad_750[0xC];
    signed char field_75C;
    unsigned char pad_75D;
    unsigned char field_75E;
    unsigned char pad_75F;
    UnkStruct_0019D6D0_car * field_760;
    unsigned char pad_764[0xC];
    GtMathPs2::CGtV3d field_770;
    float field_780;
    float field_784;
    unsigned char field_788;
    unsigned char field_789;
    unsigned char pad_78A[0xE];
    unsigned char field_798;
};
struct UnkStruct_D_float16 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_float16 D_01E75504;
extern UnkStruct_D_float16 D_01E75508;
extern UnkStruct_D_float16 D_01E7550C;
extern UnkStruct_D_float16 D_01E75510;
extern UnkStruct_D_float16 D_01E75514;
extern UnkStruct_D_float16 D_01E75518;
extern "C" void Update__11CB3AITargetFv(CB3AIArbitrator *);  // CB3AITarget::Update()
extern "C" float GetDesiredDirection__11CB3AITargetCFPQ29GtMathPs26CGtV3d(const CB3AIArbitrator *, GtMathPs2::CGtV3d *);  // CB3AITarget::GetDesiredDirection(CGtV3d*) const
extern "C" void CalculateCatchup__15CB3AIArbitratorFv(CB3AIArbitrator *);
extern "C" void CalculateSpeedMatch__15CB3AIArbitratorFv(CB3AIArbitrator *);

static inline bool func_0019D6D0_inl1(int v)
{
    bool r = true;
    if (v != 1 && v != 2) r = false;
    return r;
}

static inline void func_0019D6D0_inl2(CB3AIArbitrator * self)
{
    self->field_789 = 0;
    self->field_788 = 0;
    self->field_770 = self->field_720;
    self->field_784 = self->field_734;
}

static inline void func_0019D6D0_inl4(CB3AIArbitrator * self)
{
    self->field_789 = 1;
    self->field_788 = self->field_212;
    self->field_784 = GetDesiredDirection__11CB3AITargetCFPQ29GtMathPs26CGtV3d(self, &self->field_770);
}

// [G] frame-slot pad (N140/N186): retail's frame keeps an unused 4-byte slot at sp+0x70 between the risk outputs.
struct UnkStruct_0019D6D0_pad {
    int x;
    UnkStruct_0019D6D0_pad() {}
    ~UnkStruct_0019D6D0_pad() {}
};

// 0x0019D6D0
void CB3AIArbitrator::Update(bool p1)
{
    Update__11CB3AITargetFv(this);
    field_2B0.Update();
    if (field_798 != 0) {
        field_780 = field_1D0;
    } else {
        field_780 = GtMath::Min(field_1D0, field_738);
    }
    CalculateCatchup__15CB3AIArbitratorFv(this);
    CalculateSpeedMatch__15CB3AIArbitratorFv(this);
    bool s = false;
    if (field_1FC == 0 && func_0019D6D0_inl1(field_1F8)) {
        s = true;
    }
    if (p1) {
        func_0019D6D0_inl4(this);
        return;
    }
    float r7C;
    float r78;
    float r74;
    UnkStruct_0019D6D0_pad pad;
    GtMathPs2::CGtV3d pos = field_760->field_2430->field_204->field_30;
    CalcRiskOfPosition__17CB3AIAvoidanceMapCFPC9CB3AILaneUsQ29GtMathPs26CGtV3dPfPfPf(&field_2B0, field_760->field_18B4, field_760->field_18B8, &pos, &r7C, &r74, &r78);
    if ((s && r78 > D_01E75518.field_0) || (!s && r78 > D_01E7550C.field_0)) {
        func_0019D6D0_inl2(this);
        return;
    }
    if (!field_760->field_1A00.IsSquareCorner()) {
        CalcRiskOfPosition__17CB3AIAvoidanceMapCFPC9CB3AILaneUsQ29GtMathPs26CGtV3dPfPfPf(&field_2B0, field_1D4, field_210, &field_200, &r7C, &r74, &r78);
    } else {
        GtMathPs2::CGtV3d tp = field_760->field_1A00.GetTargetPosition();
        CalcRiskOfPosition__17CB3AIAvoidanceMapCFPC9CB3AILaneUsQ29GtMathPs26CGtV3dPfPfPf(&field_2B0, field_1D4, field_1D8, &tp, &r7C, &r74, &r78);
        r7C *= 0.5f;
        r74 *= 0.5f;
        r78 *= 0.5f;
    }
    if (field_75C == 1) {
        if ((s && r7C - field_740 > D_01E75510.field_0) || (!s && r7C - field_740 > D_01E75504.field_0)) {
            func_0019D6D0_inl2(this);
            return;
        }
        if ((s && r74 - field_748 > D_01E75514.field_0) || (!s && r74 - field_748 > D_01E75508.field_0)) {
            func_0019D6D0_inl2(this);
            return;
        }
        func_0019D6D0_inl4(this);
        return;
    } else if (field_75C == 2) {
        if ((s && r7C - field_744 > D_01E75510.field_0) || (!s && r7C - field_744 > D_01E75504.field_0)) {
            func_0019D6D0_inl2(this);
            return;
        }
        if ((s && r74 - field_74C > D_01E75514.field_0) || (!s && r74 - field_74C > D_01E75508.field_0)) {
            func_0019D6D0_inl2(this);
            return;
        }
        func_0019D6D0_inl4(this);
        return;
    } else {
        float r6C;
        float r68;
        float r64;
        field_2B0.GetChannelRisk(field_75E, &r6C, &r64, &r68);
        if ((s && r7C - r6C > D_01E75510.field_0) || (!s && r7C - r6C > D_01E75504.field_0)) {
            func_0019D6D0_inl2(this);
            return;
        }
        if ((s && r74 - r64 > D_01E75514.field_0) || (!s && r74 - r64 > D_01E75508.field_0)) {
            func_0019D6D0_inl2(this);
            return;
        }
        func_0019D6D0_inl4(this);
    }
}
