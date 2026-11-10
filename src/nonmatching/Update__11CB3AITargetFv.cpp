// NONMATCHING: Update__11CB3AITargetFv -- retail 531 / ours 501 instructions, 388 in changed runs
// psweep: scoped #pragma inline_depth(3) [G] improves 516 -> 508
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AITarget::UpdateCurrentSegment() / Update() -- son9 first archive. Layout [G] from instruction widths.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;
extern float D_01E75570;
extern float D_01E75574;
extern float D_01E75578;

struct UnkStruct_0014A980_seg {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char field_5;
    unsigned short field_6;
    unsigned short field_8;
};
struct UnkStruct_0014A980_ls {
    unsigned short ** field_0;
    unsigned char pad_4[4];
    UnkStruct_0014A980_seg * field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    unsigned char pad_0[4];
    UnkStruct_0014A980_ls * field_4;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x2C]; CB3AILane field_2C[1]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 { CGtV3d * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;

struct UnkStruct_0014A980_s { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_0014A980_r { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x144]; UnkStruct_0014A980_s * field_204; };
struct UnkStruct_0014A980_o { unsigned char pad_0[0x2430]; UnkStruct_0014A980_r * field_2430; };
struct UnkStruct_0014A980_c {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x1874];
    CB3AILane * field_18B4;
    unsigned short field_18B8;
    unsigned char field_18BA;
    unsigned char pad_18BB[0xB75];
    UnkStruct_0014A980_r * field_2430;
};

class CB3AITarget {
public:
    bool UpdateCurrentSegment();
    void Update();
    unsigned char pad_0[0x4];
    UnkStruct_0014A980_c * field_4;
    unsigned char pad_8[0x1CC];
    CB3AILane * field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x6];
    float field_1E0;
    unsigned char pad_1E4[0x8];
    float field_1EC;
    unsigned char pad_1F0[0x8];
    int field_1F8;
    int field_1FC;
    CGtV3d field_200;
    unsigned char pad_210[0x2];
    unsigned char field_212;
    unsigned char pad_213[0x1];
    unsigned short field_214;
    unsigned short field_216;
    unsigned short field_218;
    unsigned char pad_21A[0x66];
    CGtV3d field_280;
    signed char field_290;
    unsigned char pad_291[0x5];
    unsigned char field_296;
    unsigned char pad_297[0x1];
    float field_298;
};

extern "C" {
void FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(CB3AILane **, unsigned short *, signed char *, const void *, signed char);
bool LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(UnkStruct_0014A980_ls *, unsigned short, unsigned short);
bool LaneIsDriveable__9CB3AILaneFUcUsUs(unsigned char, unsigned short, unsigned short);
long LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs(CB3AITarget *, CB3AILane *, unsigned short, unsigned short);
long SegmentAIsInfrontOfSegmentB__9CB3AILaneCFUsUs(CB3AILane *, unsigned short, unsigned short);
void GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
float GetFwdFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, const void *);
void func_0014D280(CB3AITarget *);
void CalculateSplineVectors__17CB3AITargetSplineFv(void *);
void func_00330370(void *);
void CalculateNextTargetPosition__11CB3AITargetFv(CB3AITarget *);
void ResetCornerStatus__11CB3AITargetFv(CB3AITarget *);
unsigned long IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(CB3AILane *, const void *, unsigned short);
void GetAvgLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
}

static inline void func_0014D420_inl1(CB3AITarget * t)
{
    if (t->field_1FC == 0) {
        if (t->field_1F8 == 1 || t->field_1F8 == 2) {
            if (t->field_1EC <= t->field_298 || ((CGtV4d)t->field_4->field_2430->field_B0).f[3] <= D_01E75578) {
                t->field_212 = 0;
            } else {
                t->field_212 = 1;
            }
        } else {
            t->field_212 = 0;
        }
    } else {
        t->field_212 = 0;
    }
}

// 0x0014D420
void CB3AITarget::Update()
{
    bool b = field_296 != 0;
    if (b) field_296 = 0;
    if (!UpdateCurrentSegment()) return;
    CB3AILane * lane = field_1D4;
    unsigned int seg = field_1D8;
    CB3AILane * target = field_4->field_18B4;
    bool found = false;
    if (lane != target) {
        unsigned short s3 = field_4->field_18B8;
        if (LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs(this, target, s3, s3 + 8) == 0) {
            field_1D4 = field_4->field_18B4;
            field_1D8 = field_4->field_18B8;
            field_290 = field_4->field_18BA;
            ResetCornerStatus__11CB3AITargetFv(this);
            b = true;
        } else {
            if (!LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(field_4->field_18B4->field_4, field_4->field_18B8, 1)) {
                do {
                    UnkStruct_0014A980_seg * sg = &lane->field_4->field_8[seg];
                    unsigned char id = sg->field_4;
                    if (id == 0xFF) goto l1;
                    seg = sg->field_6;
                    lane = &D_00522660.field_2C[id];
                } while (lane != field_4->field_18B4);
                found = true;
l1:
                if (!found) {
                    lane = field_1D4;
                    unsigned short u = field_1D8;
                    do {
                        UnkStruct_0014A980_seg * sg = &lane->field_4->field_8[u];
                        unsigned char id = sg->field_5;
                        if (id == 0xFF) goto l2;
                        u = sg->field_8;
                        lane = &D_00522660.field_2C[id];
                    } while (lane != field_4->field_18B4);
                    found = true;
                }
            } else {
                UnkStruct_0014A980_seg * sg = &lane->field_4->field_8[seg];
                unsigned short u = sg->field_6;
                unsigned char id = sg->field_4;
                while (LaneIsDriveable__9CB3AILaneFUcUsUs(id, u, 1)) {
                    lane = &D_00522660.field_2C[id];
                    if (lane == field_4->field_18B4) { found = true; break; }
                    UnkStruct_0014A980_seg * nx = &D_00522660.field_2C[id].field_4->field_8[u];
                    id = nx->field_4;
                    u = nx->field_6;
                }
                if (!found) {
                    lane = field_1D4;
                    sg = &lane->field_4->field_8[field_1D8];
                    u = sg->field_8;
                    id = sg->field_5;
                    while (LaneIsDriveable__9CB3AILaneFUcUsUs(id, u, 1)) {
                        lane = &D_00522660.field_2C[id];
                        if (lane == field_4->field_18B4) { found = true; break; }
                        UnkStruct_0014A980_seg * nx = &D_00522660.field_2C[id].field_4->field_8[u];
                        id = nx->field_5;
                        u = nx->field_8;
                    }
                }
            }
l2:
            if (!found) {
                if (LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(field_4->field_18B4->field_4, field_4->field_18B8, 1)) {
                    field_1D4 = field_4->field_18B4;
                    field_1D8 = field_4->field_18B8;
                    field_290 = field_4->field_18BA;
                } else {
                    UnkStruct_0014A980_seg * sg = &lane->field_4->field_8[field_4->field_18B8];
                    unsigned char id = sg->field_4;
                    unsigned short u = sg->field_6;
                    if (LaneIsDriveable__9CB3AILaneFUcUsUs(id, u, 1)) {
                        field_1D4 = &D_00522660.field_2C[id];
                        field_1D8 = u;
                        field_290 = field_4->field_18BA;
                    } else {
                        sg = &lane->field_4->field_8[field_4->field_18B8];
                        id = sg->field_5;
                        u = sg->field_8;
                        if (LaneIsDriveable__9CB3AILaneFUcUsUs(id, u, 1)) {
                            field_1D4 = &D_00522660.field_2C[id];
                            field_1D8 = u;
                            field_290 = field_4->field_18BA;
                        }
                    }
                }
                ResetCornerStatus__11CB3AITargetFv(this);
                b = true;
            }
        }
    }
    CGtV3d diff = field_200 - field_4->field_2430->field_204->field_30;
    if (diff.GetLength() < D_01E75570) b = true;
    CGtV3d fwd;
    GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(field_1D4, field_1D8, &fwd);
    fwd.SetY(0.0f);
    fwd.Normalise();
    float dp = DotProduct(fwd, diff);
    if (dp < D_01E75574 && -D_01E75574 < dp) b = true;
    int st = field_1F8;
    if (st == 2) {
        if (b || SegmentAIsInfrontOfSegmentB__9CB3AILaneCFUsUs(field_1D4, field_1D8, field_218) != 0) {
            field_1F8 = 4;
            field_1FC = 2;
            CalculateNextTargetPosition__11CB3AITargetFv(this);
            func_0014D420_inl1(this);
        }
    } else if (st == 1) {
        if (b || SegmentAIsInfrontOfSegmentB__9CB3AILaneCFUsUs(field_1D4, field_1D8, field_216) != 0) {
            field_1F8 = 2;
            CalculateNextTargetPosition__11CB3AITargetFv(this);
            func_0014D420_inl1(this);
        }
    } else if (st == 0) {
        if (b || SegmentAIsInfrontOfSegmentB__9CB3AILaneCFUsUs(field_1D4, field_1D8, field_214) != 0) {
            field_1F8 = 1;
            CalculateNextTargetPosition__11CB3AITargetFv(this);
            func_0014D420_inl1(this);
        }
    }
    field_280 = field_200 - field_4->field_2430->field_204->field_30;
    field_1E0 = GetFwdFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3d(field_1D4, field_1D8, &field_4->field_2430->field_204->field_30);
    func_0014D280(this);
    CalculateSplineVectors__17CB3AITargetSplineFv((char *)this + 0x10);
    func_00330370((char *)this + 0x170);
}

#pragma pop
