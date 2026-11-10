// NONMATCHING: UpdateCurrentSegment__11CB3AITargetFv -- retail 535 / ours 534 instructions, 367 in changed runs
// son9 first archive (535/534 instrs, 367 changed): logic/control flow/layout close; left: register renumbering (retail s5=this early, s4 found-flag, s6 for a), frame 0xF0 vs 0xD0 (retail keeps separate pos stack copies for each FindClosest call + dead mtsab/qfsrv rotate pair after the pos lq/sq), lane-array address recompute
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AITarget::UpdateCurrentSegment() / Update() -- son9 first archive. Layout [G] from instruction widths.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

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
    unsigned char pad_0[4];
    UnkStruct_0014A980_c * field_4;
    unsigned char pad_8[0x1CC];
    CB3AILane * field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x1E];
    int field_1F8;
    int field_1FC;
    CGtV3d field_200;
};

extern "C" {
void FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(CB3AILane **, unsigned short *, signed char *, const void *, signed char);
bool LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(UnkStruct_0014A980_ls *, unsigned short, unsigned short);
bool LaneIsDriveable__9CB3AILaneFUcUsUs(unsigned char, unsigned short, unsigned short);
long LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs(CB3AITarget *, CB3AILane *, unsigned short, unsigned short);
void ResetCornerStatus__11CB3AITargetFv(CB3AITarget *);
unsigned long IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(CB3AILane *, const void *, unsigned short);
void GetAvgLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
}

// 0x0014CBF0
bool CB3AITarget::UpdateCurrentSegment()
{
    CGtV3d pos = field_4->field_2430->field_204->field_30;
    unsigned short s;
    if (field_1D8 == 0xFFFF) {
        CB3AILane * l = field_4->field_18B4;
        if (l != 0) {
        if (LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(l->field_4, field_4->field_18B8, 1)) {
            field_1D4 = field_4->field_18B4;
            field_1D8 = field_4->field_18B8;
        } else {
            UnkStruct_0014A980_seg * seg = &field_4->field_18B4->field_4->field_8[field_4->field_18B8];
            unsigned char id0 = seg->field_4;
            unsigned short s0 = seg->field_6;
            unsigned char id1 = seg->field_5;
            unsigned short s1 = seg->field_8;
            bool a = LaneIsDriveable__9CB3AILaneFUcUsUs(id0, s0, 1);
            bool b = LaneIsDriveable__9CB3AILaneFUcUsUs(id1, s1, 1);
            if (!a || b) {
                if (!a && b) {
                    field_1D4 = &D_00522660.field_2C[id1];
                    field_1D8 = s1;
                } else if (!a || !b) {
                    FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(&field_1D4, &field_1D8, (signed char *)((char *)this + 0x290), &pos, *((signed char *)this + 0x290));
                } else {
                    UnkStruct_0014A980_c * c = field_4;
                    unsigned short * q = c->field_18B4->field_4->field_0[c->field_18B8];
                    CGtV3d * pts = D_0064D354.field_0;
                    CGtV3d avg = (pts[q[0]] + pts[q[1]] + pts[q[2]] + pts[q[3]]) * 0.25f;
                    CGtV3d lw;
                    GetAvgLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(c->field_18B4, c->field_18B8, &lw);
                    if (DotProduct(c->field_30 - avg, lw) > 0.0f) {
                        field_1D4 = &D_00522660.field_2C[id0];
                        field_1D8 = s0;
                    } else {
                        field_1D4 = &D_00522660.field_2C[id1];
                        field_1D8 = s1;
                    }
                }
            } else {
                field_1D4 = &D_00522660.field_2C[id0];
                field_1D8 = s0;
            }
        }
        } else {
            FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(&field_1D4, &field_1D8, (signed char *)((char *)this + 0x290), &pos, *((signed char *)this + 0x290));
        }
    }
    s = field_1D8;
    if (LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs(this, field_1D4, s, s + 8) != 0) {
        bool found = false;
        UnkStruct_0014A980_seg * sg = &field_1D4->field_4->field_8[field_1D8];
        unsigned char id = sg->field_4;
        unsigned short n = sg->field_6;
        while (LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, 1)) {
            int d = (unsigned short)(n + 8) - n;
            if (d < 0) d += D_00522660.field_2C[id].field_4->field_C;
            long r;
            if (!LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, d & 0xFFFF)) r = 4;
            else r = LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs(this, &D_00522660.field_2C[id], n, n + 8);
            if (r == 0) {
                field_1D4 = &D_00522660.field_2C[id];
                field_1D8 = n;
                *((signed char *)this + 0x290) = 0;
                ResetCornerStatus__11CB3AITargetFv(this);
                found = true;
                break;
            }
            UnkStruct_0014A980_seg * nx = &D_00522660.field_2C[id].field_4->field_8[n];
            n = nx->field_6;
            id = nx->field_4;
        }
        if (!found) {
            sg = &field_1D4->field_4->field_8[field_1D8];
            id = sg->field_5;
            n = sg->field_8;
            while (LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, 1)) {
                int d = (unsigned short)(n + 8) - n;
                if (d < 0) d += D_00522660.field_2C[id].field_4->field_C;
                long r;
                if (!LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, d & 0xFFFF)) r = 4;
                else r = LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs(this, &D_00522660.field_2C[id], n, n + 8);
                if (r == 0) {
                    field_1D4 = &D_00522660.field_2C[id];
                    field_1D8 = n;
                    *((signed char *)this + 0x290) = 0;
                    ResetCornerStatus__11CB3AITargetFv(this);
                    break;
                }
                UnkStruct_0014A980_seg * nx = &D_00522660.field_2C[id].field_4->field_8[n];
                n = nx->field_8;
                id = nx->field_5;
            }
        }
    }
    unsigned long fl = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(field_1D4, &pos, field_1D8);
    if ((fl & 4) == 0) {
        if ((fl & 8) != 0) {
            if (field_1D8 == 0) {
                UnkStruct_0014A980_ls * ls = field_1D4->field_4;
                if (ls->field_E == 0) {
                    int got = 0;
                    unsigned char id = ls->field_8[0].field_4;
                    unsigned short n = ls->field_8[0].field_6;
                    if (LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, 1)) {
                        got = 1;
                        field_1D4 = &D_00522660.field_2C[id];
                        field_1D8 = n;
                    }
                    if (got == 0) {
                        UnkStruct_0014A980_seg * sg2 = &field_1D4->field_4->field_8[field_1D8];
                        id = sg2->field_5;
                        n = sg2->field_8;
                        if (LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, 1)) {
                            got = 1;
                            field_1D4 = &D_00522660.field_2C[id];
                            field_1D8 = n;
                        }
                    }
                    if (got == 0) {
                        field_1D8 = 0xFFFF;
                        CGtV3d p2 = field_4->field_2430->field_204->field_30;
                        FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(&field_1D4, &field_1D8, (signed char *)((char *)this + 0x290), &p2, *((signed char *)this + 0x290));
                    }
                    ResetCornerStatus__11CB3AITargetFv(this);
                } else {
                    field_1D8 = ls->field_C - 1;
                }
            } else {
                field_1D8 = field_1D8 - 1;
            }
        }
    } else {
        unsigned short cur = field_1D8;
        UnkStruct_0014A980_ls * ls = field_1D4->field_4;
        if ((unsigned int)cur == (unsigned int)(ls->field_C - 1)) {
            if (ls->field_E == 0) {
                int got = 0;
                UnkStruct_0014A980_seg * sg2 = &ls->field_8[cur];
                unsigned char id = sg2->field_4;
                unsigned short n = sg2->field_6;
                if (LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, 1)) {
                    got = 1;
                    field_1D4 = &D_00522660.field_2C[id];
                    field_1D8 = n;
                }
                if (got == 0) {
                    sg2 = &field_1D4->field_4->field_8[field_1D8];
                    id = sg2->field_5;
                    n = sg2->field_8;
                    if (LaneIsDriveable__9CB3AILaneFUcUsUs(id, n, 1)) {
                        got = 1;
                        field_1D4 = &D_00522660.field_2C[id];
                        field_1D8 = n;
                    }
                }
                if (got == 0) {
                    field_1D8 = 0xFFFF;
                    CGtV3d p2 = field_4->field_2430->field_204->field_30;
                    FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(&field_1D4, &field_1D8, (signed char *)((char *)this + 0x290), &p2, *((signed char *)this + 0x290));
                }
                ResetCornerStatus__11CB3AITargetFv(this);
            } else {
                field_1D8 = 0;
            }
        } else {
            field_1D8 = cur + 1;
        }
    }
    return true;
}
