// NONMATCHING: CalculateNearEdgePosition__11CB3AITargetFUsUsiPQ29GtMathPs26CGtV3dPUcPUs -- retail 294 / ours 285 instructions, 105 in changed runs
// draftAN fork C C-first: from the target's lane at seg on the wanted side, walk outwards across neighbour lanes while the lane beyond is driveable / not undesirable over 8 segments (retail tests the neighbour, then in the loop the neighbour's neighbour, stepping one lane: kept), output lane id and segment, edge point = own side vertex + the lane's across vector (degenerate segment stepped: 0 -> 1, else -1; retail's blez on the masked index) normalised * clamp(field_298 / D_01E7557C, 0, 1) * field_4->field_2434 (zero below 2^-32); a2 never read; 285/294, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: side selection (s4 = 0 for side 1), link record offsets (+4+side, +6+2*side), the 8-segment count wrap, the loop's break/step order, the signed vertex reads, the min/max clamp and both vector orders traced

// CalculateNearEdgePosition__11CB3AITargetFUsUsiPQ29GtMathPs26CGtV3dPUcPUs -- draftAN fork C (C-first draft). 0x14B010, 0x498.
// [C] name: the mangled symbol in retail's tables. Revenge CalculateNearEdgePosition__11CB4AITargetPC16CB4AILaneSegmentT1iP19
// CB4AITargetPosition (0x2C0, B4AITarget.cpp; stabs lxSideWanted, lnFlags, leLinkSideWanted, lSidewaysVec, lrOffset) [L]: local
// names from it. Lane structs as the archived siblings (LaneIsDriveable, FindNextCorner, IsInSegment): the lanes are the 8-byte
// CB3AILane objects at D_00522660 + 0x2C (id byte, lane info at +4); a lane info has the vertex pairs (+0), the 10-byte link
// records (+8: neighbour lane ids at +4/+5, neighbour segments at +6/+8, left/right) and the segment count (+0xC).
// What it does [L]: from this target's lane (field_1D4) at segment seg, on side lxSideWanted (1 = the field_0 / left link, else
// right), walks outwards across neighbouring lanes while the lane beyond the next one is driveable and not undesirable over the
// next 8 segments (LaneIsDriveable / LaneIsUndesirable bit 4) -- [C] retail tests the neighbour first, then in the loop the
// neighbour's neighbour and steps one lane (the walk ends on the lane whose second-next lane failed: kept as retail); outputs that
// lane's id and segment, then the edge point = the start lane's own side vertex + the lane's across vector (stepped off a
// degenerate segment: seg 0 -> 1, else seg - 1) normalised and scaled by clamp(field_298 / D_01E7557C, 0, 1) * field_4->field_2434
// (zero below 2^-32 squared length). [C] the second unsigned short argument (a2) is never read (retail overwrites a2 first).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_0014B010_v { short field_0; short field_2; };          // left / right vertex index (lh: signed)
struct UnkStruct_0014B010_link {                                         // 10 bytes
    unsigned char pad_0[4];
    unsigned char field_4[2];                                            // neighbour lane id, [0] left / [1] right
    unsigned short field_6[2];                                           // neighbour segment, left / right
};
struct UnkStruct_0014B010_info {
    UnkStruct_0014B010_v *field_0;
    unsigned char pad_4[4];
    UnkStruct_0014B010_link *field_8;
    unsigned short field_C;                                              // segment count
};
class CB3AILane {
public:
    static bool LaneIsDriveable(unsigned char p0, unsigned short p1, unsigned short p2);
    unsigned char field_0;                                               // lane id
    unsigned char pad_1[3];
    UnkStruct_0014B010_info *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];                                               // [G] count unknown
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_0014B010_e9 { CGtV3d field_0; };
struct UnkStruct_D_0064D354 { UnkStruct_0014B010_e9 *field_0; };
extern UnkStruct_D_0064D354 D_0064D354;
extern float D_01E7557C;
struct UnkStruct_0014B010_own { unsigned char pad_0[0x2434]; float field_2434; };   // [G] lane half-width
class CB3AITarget {
public:
    void CalculateNearEdgePosition(unsigned short seg, unsigned short p2, int lxSideWanted, CGtV3d *pos, unsigned char *lane,
                                   unsigned short *outSeg);
    int LaneIsUndesirable(const CB3AILane *p0, unsigned short p1, unsigned short p2) const;
    unsigned char pad_0[4];
    UnkStruct_0014B010_own *field_4;
    unsigned char pad_8[0x1CC];
    CB3AILane *field_1D4;                                                // current lane
    unsigned char pad_1D8[0xC0];
    float field_298;
};

// [G] the lane beyond (id, segment) checked over the next 8 segments (count wrapped by the lane's segment count)
static inline int func_0014B010_inl1(const CB3AITarget *self, unsigned char id, unsigned short s)
{
    unsigned short e = s + 8;
    int n = e - s;
    if (n < 0) n += D_00522660.field_2C[id].field_4->field_C;
    if (CB3AILane::LaneIsDriveable(id, s, n))
        return self->LaneIsUndesirable(&D_00522660.field_2C[id], s, e);
    return 4;
}

// 0x0014B010
void CB3AITarget::CalculateNearEdgePosition(unsigned short seg, unsigned short p2, int lxSideWanted, CGtV3d *pos,
                                            unsigned char *lane, unsigned short *outSeg)
{
    int side = 1;
    int lnNearVertex;
    if (lxSideWanted == 1) {
        side = 0;
        lnNearVertex = (unsigned short)field_1D4->field_4->field_0[seg].field_0;
    } else {
        lnNearVertex = (unsigned short)field_1D4->field_4->field_0[seg].field_2;
    }
    unsigned char lnLane = field_1D4->field_0;
    CB3AILane *cur = field_1D4;
    unsigned short curSeg = seg;
    UnkStruct_0014B010_link *rec = &cur->field_4->field_8[seg];
    int lnFlags = func_0014B010_inl1(this, rec->field_4[side], rec->field_6[side]);
    while (!(lnFlags & 4)) {
        rec = &cur->field_4->field_8[curSeg];
        unsigned char nid = rec->field_4[side];
        unsigned short nseg = rec->field_6[side];
        CB3AILane *next = &D_00522660.field_2C[nid];
        UnkStruct_0014B010_link *rec2 = &next->field_4->field_8[nseg];
        lnFlags = func_0014B010_inl1(this, rec2->field_4[side], rec2->field_6[side]);
        if (lnFlags & 4) break;
        curSeg = nseg;
        cur = next;
        lnLane = nid;
    }
    *lane = lnLane;
    *outSeg = curSeg;
    UnkStruct_0014B010_v *v = cur->field_4->field_0;
    short l = v[curSeg].field_0;
    short r = v[curSeg].field_2;
    if (r == l) {
        if ((int)curSeg > 0) curSeg = curSeg - 1;
        else curSeg = curSeg + 1;
        r = v[curSeg].field_2;
        l = v[curSeg].field_0;
    }
    float lrOffset = GtMath::Min(GtMath::Max(field_298 / D_01E7557C, 0.0f), 1.0f);
    CGtV3d lSidewaysVec;
    // [C] w = the subtrahend's w: 0x14B318 / 0x14B354 lqc2 vf1 (subtrahend), lqc2 vf2 (minuend); 0x14B320 / 0x14B35C
    // vsub.xyz vf1, vf2, vf1 keeps vf1's w; 0x14B328 / 0x14B360 sqc2 vf1, 0x130(sp) -- `a - b` took the minuend's w
    if (lxSideWanted == 1) {
        lSidewaysVec = D_0064D354.field_0[r].field_0 - D_0064D354.field_0[l].field_0;
        ((float *)&lSidewaysVec)[3] = ((const float *)&D_0064D354.field_0[l].field_0)[3];
    } else {
        lSidewaysVec = D_0064D354.field_0[l].field_0 - D_0064D354.field_0[r].field_0;
        ((float *)&lSidewaysVec)[3] = ((const float *)&D_0064D354.field_0[r].field_0)[3];
    }
    CGtV3d off;
    if (lSidewaysVec.GetSquaredLength() < 2.3283064e-10f) {
        off.Zero();
    } else {
        lSidewaysVec.Normalise();
        off = lSidewaysVec * (lrOffset * field_4->field_2434);
    }
    *pos = off + D_0064D354.field_0[lnNearVertex].field_0;
}
