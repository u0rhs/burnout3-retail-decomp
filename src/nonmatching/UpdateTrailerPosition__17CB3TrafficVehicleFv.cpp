// NONMATCHING: UpdateTrailerPosition__17CB3TrafficVehicleFv -- retail 505 / ours 508 instructions, 165 in changed runs
// draftAE C-first: 508/505, 22 mnemonic hunks (31 instrs); calls identical; op counts agree except one vmove + one fewer 1.0 (header operator-/+ on hard-coded $vf1/$vf2 where retail's sub/add are compiler-chosen) and the hitch passed to MoveToSegmentCentre through a by-value copy (retail passes the lvalue's address: queued by-value gap); rest: axle-copy store order, the race-car loop's materialised i (sibling InitaliseTrailerPosition's residue), frame 0x100 vs 0x140
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every branch, call, store and constant accounted for (rigid-attach copy with the axle's last byte kept, hitch/axle placement, cat 8/9 front axle + segment centring, matrix rebuild fallbacks, wheel spin wrap at +-200 pi, guarded near/far/all tables, reflected negation); header NormaliseGetLength/CrossProduct/GetLength/SetGtV3d/operators

// UpdateTrailerPosition__17CB3TrafficVehicleFv -- draftAE (0x172070, 0x7E4) -- CB3TrafficVehicle::UpdateTrailerPosition()
// Written from the retail asm (Ghidra as reading aid). Revenge STABS locals lpCabMatrix / lpMatrix / lTempVector / lrResult [L]
// guided the names; layout as the archived siblings InitaliseTrailerPosition / UpdatePosition (draftAD). [L] the trailer follows
// its tractor (field_10C): unless it is rigidly attached (field_17A & 1: matrix and rear axle copied from the tractor), it hangs at
// the hitch point (tractor mPos + mAt * field_134), its rear axle trails along the hitch direction (AdjustAxleHeight; special
// categories 8/9 also place the front axle at the hitch and centre both on the segment), the matrix is rebuilt from the axles
// with zero-length fallbacks, and the wheel spin advances by the axle's travel (wrapped at +-200 pi). Then, unless field_174 & 2,
// its distance to every race car is recorded in the per-car near/far/all tables; categories 8/9 face backwards (mAt, mRight
// negated). Types and field meanings [G] (instruction widths, use).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3TrafficLane;
class CB3TrafficVehicle;
class CB3TrafficAxle {
public:
    int AdjustAxleHeight(CB3TrafficLane *, int);
    void MoveToSegmentCentre(CGtV3d p);
    CGtV3dPlus field_0;     // position
    CGtV3d field_10;        // ground normal [G]
    short field_20;
    short field_22;
    short field_24;
    short field_26;
    int field_28;
    short field_2C;
    unsigned char field_2E;
    unsigned char field_2F;
};
struct UnkStruct_00172070_car { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_D_00522660 {                    // [G] six rows (race cars) per table, as InitaliseTrailerPosition's archive
    unsigned char pad_0[0x39234];
    float field_39234[6][0xFE];
    unsigned char field_3AA04[6][0xFE];
    unsigned char field_3AFF8[6][0x19];
    unsigned char field_3B08E[6][0x8];
    unsigned char pad_3B0BE[0x72];
    unsigned char field_3B130[6];
    unsigned char field_3B136[6];
    unsigned char field_3B13C[6];
    unsigned char pad_3B142[0xEFBE6];
    UnkStruct_00172070_car * field_12AD28[6];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D37C D_0064D37C;          // [G] race car count
struct UnkStruct_00172070_b0 { unsigned char pad_0[0xD]; signed char field_D; };

class CB3TrafficVehicle {
public:
    void UpdateTrailerPosition();

    CB3TrafficAxle field_0;
    CB3TrafficAxle field_30;
    CGtV3d field_60;
    CGtMatrix3x4 field_70;
    UnkStruct_00172070_b0 * field_B0;
    unsigned char pad_B4[0x10];
    float field_C4;            // speed
    unsigned char field_C8;
    unsigned char pad_C9[0x43];
    CB3TrafficVehicle * field_10C;   // [G] tractor
    unsigned char pad_110[0x10];
    float field_120;           // wheel radius [G]
    unsigned char pad_124[0x4];
    float field_128;           // wheel spin
    unsigned char pad_12C[0x8];
    float field_134;           // hitch distance
    float field_138;           // body offset from the hitch
    unsigned char pad_13C[0x10];
    float field_14C;           // rear axle offset
    unsigned char pad_150[0x23];
    signed char field_173;     // category
    unsigned char field_174;   // flags
    unsigned char field_175;
    unsigned char pad_176;
    unsigned char field_177;   // traffic index
    unsigned char pad_178[0x2];
    unsigned char field_17A;
    unsigned char field_17B;
};

// as InitaliseTrailerPosition's func_00172860_inl2
static inline bool func_00172070_inl1(CB3TrafficVehicle * v)
{
    if (!(v->field_174 & 4)) return false;
    if (v->field_10C == 0) return false;
    if ((unsigned)(v->field_173 - 8) < 2) return true;
    return false;
}

void CB3TrafficVehicle::UpdateTrailerPosition()
{
    bool lbIsReflectedTrailer = func_00172070_inl1(this);
    CGtMatrix3x4 * lpCabMatrix = &field_10C->field_70;
    field_17A = field_10C->field_17A;
    field_175 = field_10C->field_175;
    field_17B = field_10C->field_17B;
    field_C4 = field_10C->field_C4;
    field_C8 = field_10C->field_C8;
    CGtMatrix3x4 * lpMatrix = &field_70;
    if (!(field_17A & 1)) {
        // [C] retail rewrites field_70's rows read-modify-write (0x172368 lq / 0x1723AC sq 0x70; 0x1723EC lq / 0x172430 sq
        // 0x80; 0x17281C / 0x172828 lqc2 -> sqc2 0xA0 / 0x70), so their w lanes survive this block (port lane vu0, hybrid
        // culprit #7). 0x172154 sqc2 vf1, 0x20(s1) is the main path's lpMatrix->mAt below (w = field_30.field_0's) [C].
        const float lrRightW = ((const float *)&field_70.mRight)[3];
        const float lrUpW = ((const float *)&field_70.mUp)[3];
        const float lrAtW = ((const float *)&field_70.mAt)[3];
        CGtV3d lOldPos = CGtV3d(field_30.field_0.mData);
        CGtV3d lHitch = lpCabMatrix->mPos;
        lHitch += lpCabMatrix->mAt * field_10C->field_134; // [C] w = the cab's mPos.w: 0x172130 lqc2 vf1, 0x30(s3); 0x172138 vadd.xyz vf1,
        // vf1, vf2; 0x17213C sqc2 vf1, 0x130(sp) -- `a + b` took the cab's mAt.w
        lpMatrix->mAt = lHitch - CGtV3d(field_30.field_0.mData);
        ((float *)&lpMatrix->mAt)[3] = ((const float *)&field_30.field_0)[3]; // [C] 0x17214C lqc2 vf1, 0x30(s0) (field_30.field_0);
        // 0x172150 vsub.xyz vf1, vf2, vf1 keeps its w; 0x172154 sqc2 vf1, 0x20(s1) -- `a - b` took lHitch's w
        if (lpMatrix->mAt.NormaliseGetLength() == 0.0f)
            lpMatrix->mAt = lpCabMatrix->mAt;
        lpMatrix->mPos = lHitch + lpMatrix->mAt * field_138;
        field_30.field_0.SetGtV3d(lpMatrix->mPos + lpMatrix->mAt * field_14C);
        if (!field_30.AdjustAxleHeight(0, -1))
            field_30.field_10 = lpCabMatrix->mUp;
        if (lbIsReflectedTrailer) {
            field_0.field_0.SetGtV3d(lHitch);
            if (!field_30.AdjustAxleHeight(0, -1))
                field_0.field_10 = lpCabMatrix->mUp;
            field_0.MoveToSegmentCentre(lHitch);
            field_30.MoveToSegmentCentre(CGtV3d(field_0.field_0.mData));
        }
        field_70.mAt = lHitch - CGtV3d(field_30.field_0.mData);
        if (field_70.mAt.NormaliseGetLength() == 0.0f)
            field_70.mAt.SetZ(1.0f);
        field_70.mPos = lHitch;
        field_70.mPos += field_70.mAt * field_138; // [C] w = lHitch.w: 0x1722A0 lqc2 vf2, 0x130(sp); 0x1722B0 vadd.xyz vf2, vf2, vf3;
        // 0x1722B4 sqc2 vf2, 0xA0(s0) -- `a + b` took field_70.mAt's w
        field_70.mUp = lpCabMatrix->mUp + field_30.field_10;
        if (field_70.mUp.NormaliseGetLength() == 0.0f)
            field_70.mUp.SetY(1.0f);
        field_70.mRight = CrossProduct(field_70.mUp, field_70.mAt);
        if (field_70.mRight.NormaliseGetLength() == 0.0f)
            field_70.mRight.SetX(1.0f);
        field_70.mUp = CrossProduct(field_70.mAt, field_70.mRight);
        if (field_70.mUp.NormaliseGetLength() == 0.0f)
            field_70.mUp.SetY(1.0f);
        ((float *)&field_70.mRight)[3] = lrRightW;
        ((float *)&field_70.mUp)[3] = lrUpW;
        ((float *)&field_70.mAt)[3] = lrAtW;
        float lrResult = (CGtV3d(field_30.field_0.mData) - lOldPos).GetLength();
        if (field_B0->field_D > 0) {
            field_128 = field_128 + lrResult / field_120;
            if (field_128 > 628.31854f)
                field_128 = field_128 - 628.31854f;
            else if (field_128 < -628.31854f)
                field_128 = field_128 + 628.31854f;
        }
    } else {
        field_70 = field_10C->field_70;
        unsigned char b = field_30.field_2F;
        field_30 = field_10C->field_30;
        field_30.field_2F = b;
    }
    int lnNumRaceCars = D_0064D37C.field_0;
    if (field_174 & 2)
        return;
    for (int leRaceCarIndex = 0; leRaceCarIndex < lnNumRaceCars; leRaceCarIndex++) {
        CGtV3d lTempVector = field_70.mPos - D_00522660.field_12AD28[leRaceCarIndex]->field_30;
        lTempVector.SetY(0.0f);
        float lrDist = lTempVector.GetLength();
        D_00522660.field_39234[leRaceCarIndex][field_177] = lrDist;
        if (lrDist < 16.0f) {
            unsigned char n = D_00522660.field_3B13C[leRaceCarIndex];
            if (n < 8) {
                D_00522660.field_3B08E[leRaceCarIndex][n] = field_177;
                D_00522660.field_3B13C[leRaceCarIndex]++;
            }
        }
        if (lrDist < 100.0f) {
            unsigned char n = D_00522660.field_3B136[leRaceCarIndex];
            if (n < 25) {
                D_00522660.field_3AFF8[leRaceCarIndex][n] = field_177;
                D_00522660.field_3B136[leRaceCarIndex]++;
            }
        }
        D_00522660.field_3AA04[leRaceCarIndex][D_00522660.field_3B130[leRaceCarIndex]] = field_177;
        D_00522660.field_3B130[leRaceCarIndex]++;
    }
    if (lbIsReflectedTrailer) {
        lpMatrix->mAt = -lpMatrix->mAt;
        lpMatrix->mRight = -lpMatrix->mRight;
    }
}
