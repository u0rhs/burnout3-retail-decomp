// NONMATCHING: AddCarToMap__17CB3AIAvoidanceMapF16EAIAvoidanceRiskfffQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox -- retail 1216 / ours 1239 instructions, 306 in changed runs
// hard1 C-first: segment search (ahead/6 segments on from our own, wrap on looped lanes, then the WalkDrivableLanesToFindPosition-shaped walk with inline segment steps), lane connectivity (our lane, else left then right link chains from our segment), lateral positions of the two points (linked: across GetWidth sums; else from the lane side 2, or side 1 past half the map width from +0x448, scaled by our lane's total width), box half extents (forward x 0.5, right x 0.3), the cell range fill (FillInNoGoData's loop, inlined in both arms as retail); 1239/1216 (incl. 9 cvt.w.s retail lists as .word), calls identical, every FPU op count and compare/branch sense equal, 10/10 non-stack stores; left: frame 0x7E0 vs 0x900, two extra beq / one lbu+lhu in the link walks
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm region by region (Ghidra as a reading aid): every call with retail's argument registers, every branch sense, FPU op counts and the non-stack (cell) stores checked against retail; retail's dead GetLength of the far-side unit vector and its +0x44C/+0x448 asymmetry kept; unset oseg only read on the linked path

// CB3AIAvoidanceMap::AddCarToMap(EAIAvoidanceRisk, float, float, float, CGtV3d, CGtV3d, CGtV3d, CGtV3d, const CGtAxisAlignedBox&)
// -- hard1 (C-first draft; deferred-hard by draftAF). 0x13F550, 0x1300. [C] name: the mangled symbol in retail's tables.
// Written from the retail asm region by region (Ghidra's draft as a reading aid); the segment walk follows the archived
// CB3AILane::WalkDrivableLanesToFindPosition, the map fill FillInNoGoData's loop. Meanings [G], types [G].
// What it does [L]: marks another car in the avoidance map (256 lateral cells of 0.2 around the map centre +0x44C):
//  - finds the car's lane segment: from our own lane / segment (field_454 +0x18B4/+0x18B8), `ahead / 6` segments on (wrapping on
//    looped lanes), then walks lanes (IsInSegment's 1/2/4/8 = left/right link, next/previous segment; 128 steps at most);
//  - if the car is on our lane, or a lane reachable sideways from our segment (left links, then right links), its lateral
//    positions are measured across the drivable lanes in between (GetWidth sums); otherwise relative to the lane's own side
//    (side 2, or side 1 past half the map width +0x444, measured from +0x448), scaled by our lane's total width;
//  - the car's half extent across the lane from its box and the two orientations (forward x 0.5, right x 0.3);
//  - the cells between the two positions (+- extents) take the risk, a distance byte 255 x d / 8 and a time short
//    32767 x clamp(1.5 t, +-500) / 500 where they are nearer than what is there (d, t blended towards 8 / 500 by +0x450).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

enum EAIAvoidanceRisk { EAIAvoidanceRisk_0 };
class CGtAxisAlignedBox {
public:
    CGtV3d field_0;
    CGtV3d field_10;
};
struct UnkStruct_0013F550_pt { unsigned short field_0; unsigned short field_2; };   // segment point indices
struct UnkStruct_0013F550_ds { float field_0; unsigned char pad_4[0x4]; };          // segment start distance
struct UnkStruct_0013F550_lk {                  // segment links (10 bytes)
    unsigned char pad_0[0x4];
    unsigned char field_4;                      // left lane
    unsigned char field_5;                      // right lane
    unsigned short field_6;                     // left segment
    unsigned short field_8;                     // right segment
};
struct CB3AILaneStruct {
    UnkStruct_0013F550_pt *field_0;
    UnkStruct_0013F550_ds *field_4;
    UnkStruct_0013F550_lk *field_8;
    unsigned short field_C;                     // segment count
    unsigned char field_E;                      // looped
};
class CB3AILane {
public:
    unsigned char pad_0[0x4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x2C]; CB3AILane field_2C[1]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 { CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_0013F550_own {
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;                      // our lane
    unsigned short field_18B8;                  // our segment
};
class CB3AIAvoidanceMap {
public:
    void AddCarToMap(EAIAvoidanceRisk, float, float, float, CGtV3d, CGtV3d, CGtV3d, CGtV3d, const CGtAxisAlignedBox &);
    unsigned char pad_0[0x40];
    unsigned char field_40[0x100];              // risk per cell
    unsigned char field_140[0x100];             // distance byte per cell
    short field_240[0x100];                     // time per cell
    unsigned char pad_440[0x4];
    float field_444;                            // map width [G]
    float field_448;
    float field_44C;                            // map centre (lateral)
    float field_450;                            // blend towards the far values
    UnkStruct_0013F550_own *field_454;
};
// callees by link name; by-value CGtV3d passed as addresses
extern "C" int IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(const CB3AILane *, const CGtV3d *, unsigned short);
extern "C" int LaneIsDriveable__9CB3AILaneFUcUsUs(unsigned char, unsigned short, unsigned short);
extern "C" int LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(const CB3AILaneStruct *, unsigned short, unsigned short);
extern "C" void GetSidePosition__9CB3AILaneCFUsiPQ29GtMathPs26CGtV3d(const CB3AILane *, unsigned short, int, CGtV3d *);
extern "C" void GetAvgLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(const CB3AILane *, unsigned short, CGtV3d *);
extern "C" void GetAvgRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(const CB3AILane *, unsigned short, CGtV3d *);
extern "C" void GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(const CB3AILane *, unsigned short, CGtV3d *);
extern "C" float GetTotalWidth__9CB3AILaneCFUsUs(const CB3AILane *, unsigned short, unsigned short);
extern "C" float GetWidth__9CB3AILaneCFUs(const CB3AILane *, unsigned short);

static inline CB3AILane *func_0013F550_inl1(unsigned char l) { return &D_00522660.field_2C[l]; }
// a flat (y = 0) unit vector
static inline void func_0013F550_inl2(CGtV3d &v) { v.SetY(0.0f); v.Normalise(); }
// the box's half extent across the lane for an orientation
static inline float func_0013F550_inl3(const CGtAxisAlignedBox &box, const CGtV3d &fwd, const CGtV3d &right, const CGtV3d &dir)
{
    float kf = 0.5f * GtMath::Abs((float)DotProduct(fwd, dir));
    float kr = 0.3f * GtMath::Abs((float)DotProduct(right, dir));
    return (float)((box.field_0.Z() - box.field_10.Z()) * kr) +
           (float)((box.field_0.X() - box.field_10.X()) * kf);
}
// the cells lo..hi (FillInNoGoData's loop)
// (inlined in both arms of the caller: retail has two copies)
static inline void func_0013F550_inl4(CB3AIAvoidanceMap *m, int lo, int hi, EAIAvoidanceRisk risk, float d, float t)
{
    if (lo < 0) lo = 0;
    if (!(hi < 256)) hi = 255;
    for (int i = lo; i <= hi; i++) {
        if (d < 0.03137255f * (float)(int)m->field_140[i]) {
            m->field_140[i] = (int)((255.0f * d) / 8.0f);
            m->field_40[i] = risk;
        }
        if (t < 0.015259255f * (float)m->field_240[i])
            m->field_240[i] = (int)(((float)32767 * GtMath::Min(GtMath::Max(t, -500.0f), 500.0f)) / 500.0f);
    }
}

// 0x0013F550
void CB3AIAvoidanceMap::AddCarToMap(EAIAvoidanceRisk risk, float ahead, float t, float d, CGtV3d pos_, CGtV3d pos2_,
                                    CGtV3d dir_, CGtV3d dir2_, const CGtAxisAlignedBox &box)
{
    // the by-value vectors copied at entry, as retail (lq/sq of all four first)
    CGtV3d dir2 = dir2_;
    CGtV3d pos2 = pos2_;
    CGtV3d dir = dir_;
    CGtV3d pos = pos_;
    CB3AILane *lane = field_454->field_18B4;
    unsigned short seg = field_454->field_18B8;
    if (!(ahead <= 0.0f)) seg = seg + (int)(ahead / 6.0f);
    if (!(seg < lane->field_4->field_C)) {
        if (lane->field_4->field_E)
            seg = seg - lane->field_4->field_C;
        else
            seg = lane->field_4->field_C - 1;
    }
    // walk to the car's segment
    int last = 16;
    int count = 0;
    int r = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &pos, seg);
    while (r != 0) {
        count++;
        if (count == 128) break;
        if (r & 4) {
            if (last == 8) break;
            seg = seg + 1;
            if (!(seg < lane->field_4->field_C)) {
                if (!lane->field_4->field_E) {
                    seg = lane->field_4->field_C - 1;
                    break;
                }
                seg = seg - lane->field_4->field_C;
            }
            last = 4;
        } else if (r & 8) {
            if (last == 4) break;
            if (seg == 0) {
                if (!lane->field_4->field_E) break;
                seg = lane->field_4->field_C - 1;
            } else {
                seg = seg - 1;
            }
            last = 8;
        } else if (r & 1) {
            if (last == 2) break;
            UnkStruct_0013F550_lk *e = &lane->field_4->field_8[seg];
            unsigned char l = e->field_4;
            unsigned short s = e->field_6;
            if (!LaneIsDriveable__9CB3AILaneFUcUsUs(l, s, 1)) break;
            seg = s;
            last = 1;
            lane = func_0013F550_inl1(l);
        } else if (r & 2) {
            if (last == 1) break;
            UnkStruct_0013F550_lk *e = &lane->field_4->field_8[seg];
            unsigned char l = e->field_5;
            unsigned short s = e->field_8;
            if (!LaneIsDriveable__9CB3AILaneFUcUsUs(l, s, 1)) break;
            seg = s;
            last = 2;
            lane = func_0013F550_inl1(l);
        }
        r = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &pos, seg);
    }
    // is the car's lane our lane, or reachable sideways from our segment?
    int linked = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &pos, seg) == 0;
    unsigned short oseg;                        // [C] unset unless linked (only read then)
    if (linked) {
        linked = 0;
        if (field_454->field_18B4 == lane) {
            oseg = field_454->field_18B8;
            linked = 1;
        }
        if (!linked) {
            UnkStruct_0013F550_lk *e = &field_454->field_18B4->field_4->field_8[field_454->field_18B8];
            unsigned short s = e->field_6;
            unsigned char l = e->field_4;
            while (LaneIsDriveable__9CB3AILaneFUcUsUs(l, s, 1)) {
                if (func_0013F550_inl1(l) == lane) {
                    oseg = s;
                    linked = 1;
                    break;
                }
                e = &func_0013F550_inl1(l)->field_4->field_8[s];
                l = e->field_4;
                s = e->field_6;
            }
        }
        if (!linked) {
            UnkStruct_0013F550_lk *e = &field_454->field_18B4->field_4->field_8[field_454->field_18B8];
            unsigned short s = e->field_8;
            unsigned char l = e->field_5;
            while (LaneIsDriveable__9CB3AILaneFUcUsUs(l, s, 1)) {
                if (func_0013F550_inl1(l) == lane) {
                    oseg = s;
                    linked = 1;
                    break;
                }
                e = &func_0013F550_inl1(l)->field_4->field_8[s];
                l = e->field_5;
                s = e->field_8;
            }
        }
    }
    float y1, y2, e1, e2;                       // lateral positions (map coordinates) and half extents of the two points
    if (linked) {
        CGtV3d sp = D_0064D354.field_0[lane->field_4->field_0[seg].field_2];
        CGtV3d left;
        GetAvgLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, seg, &left);
        func_0013F550_inl2(left);
        CGtV3d dp = pos - sp;
        dp.SetY(0.0f);
        float a = DotProduct(dp, left);
        float w = GetWidth__9CB3AILaneCFUs(lane, seg);
        float wo = GetWidth__9CB3AILaneCFUs(lane, oseg);
        float x;
        if (GtMath::IsEffectivelyZero(w) || GtMath::IsEffectivelyZero(wo))
            x = 0.0f;
        else
            x = wo * (a / w);
        // the drivable lanes to the right of the car's
        UnkStruct_0013F550_lk *e = &lane->field_4->field_8[oseg];
        unsigned short s = e->field_8;
        unsigned char l = e->field_5;
        float sum = 0.0f;
        while (LaneIsDriveable__9CB3AILaneFUcUsUs(l, s, 1)) {
            CB3AILane *n = func_0013F550_inl1(l);
            sum = sum + GetWidth__9CB3AILaneCFUs(n, s);
            e = &n->field_4->field_8[s];
            l = e->field_5;
            s = e->field_8;
        }
        y1 = (x + sum) - field_44C;
        CGtV3d fwd, right;
        GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, seg, &fwd);
        GetAvgRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, seg, &right);
        right.SetY(0.0f);
        fwd.SetY(0.0f);
        fwd.Normalise();
        right.Normalise();
        e1 = func_0013F550_inl3(box, fwd, right, dir);
        CGtV3d dp2 = pos2 - sp;
        dp2.SetY(0.0f);
        float a2 = DotProduct(dp2, left);
        float w2 = GetWidth__9CB3AILaneCFUs(lane, seg);
        float wo2 = GetWidth__9CB3AILaneCFUs(lane, oseg);
        float x2;
        if (GtMath::IsEffectivelyZero(w2) || GtMath::IsEffectivelyZero(wo2))
            x2 = 0.0f;
        else
            x2 = wo2 * (a2 / w2);
        y2 = (x2 + sum) - field_44C;
        e2 = func_0013F550_inl3(box, fwd, right, dir2);
    } else {
        unsigned short s = seg;
        if (!LaneIsDriveable__9CB3AILaneFPC15CB3AILaneStructUsUs(lane->field_4, seg, 1)) {
            // run on along the lane, using up the distance ahead, to the end or 16 segments
            for (int k = 0; k < 16; k++) {
                if (ahead < 0.0f) break;
                if (s > 0)
                    ahead = ahead - (lane->field_4->field_4[s].field_0 - lane->field_4->field_4[s - 1].field_0);
                else
                    ahead = ahead - lane->field_4->field_4[0].field_0;
                s = s + 1;
                if (!(s < lane->field_4->field_C)) {
                    if (lane->field_4->field_E) {
                        s = s - lane->field_4->field_C;
                    } else {
                        // the end of an open lane: step sideways onto a drivable neighbour
                        s = lane->field_4->field_C - 1;
                        int moved = 0;
                        UnkStruct_0013F550_lk *e = &lane->field_4->field_8[s];
                        unsigned char l = e->field_4;
                        unsigned short ls = e->field_6;
                        if (LaneIsDriveable__9CB3AILaneFUcUsUs(l, ls, 1)) {
                            s = ls;
                            moved = 1;
                            lane = func_0013F550_inl1(l);
                        }
                        if (!moved) {
                            e = &lane->field_4->field_8[s];
                            l = e->field_5;
                            ls = e->field_8;
                            if (LaneIsDriveable__9CB3AILaneFUcUsUs(l, ls, 1)) {
                                s = ls;
                                lane = func_0013F550_inl1(l);
                            }
                        }
                    }
                }
            }
        }
        CGtV3d sp;
        GetSidePosition__9CB3AILaneCFUsiPQ29GtMathPs26CGtV3d(lane, s, 2, &sp);
        CGtV3d left;
        GetAvgLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, s, &left);
        func_0013F550_inl2(left);
        CGtV3d dp = pos - sp;
        dp.SetY(0.0f);
        float a = DotProduct(dp, left);
        if (!(a <= field_444 / 2.0f)) {
            // past half the map: from the lane's other side
            CGtV3d sp1;
            GetSidePosition__9CB3AILaneCFUsiPQ29GtMathPs26CGtV3d(lane, s, 1, &sp1);
            CGtV3d rt;
            GetAvgRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, s, &rt);
            func_0013F550_inl2(rt);
            CGtV3d dq = pos - sp1;
            dq.SetY(0.0f);
            float b = DotProduct(dq, rt);
            float unused = rt.GetLength();      // [C] retail computes the unit vector's length and never reads it
            (void)unused;
            float w = GetTotalWidth__9CB3AILaneCFUsUs(lane, s, s);
            float x;
            if (GtMath::IsEffectivelyZero(w))
                x = 0.0f;
            else
                x = (b / w) * GetTotalWidth__9CB3AILaneCFUsUs(field_454->field_18B4, field_454->field_18B8, field_454->field_18B8);
            y1 = field_448 - x;
        } else {
            float w = GetTotalWidth__9CB3AILaneCFUsUs(lane, s, s);
            float x;
            if (GtMath::IsEffectivelyZero(w))
                x = 0.0f;
            else
                x = (a / w) * GetTotalWidth__9CB3AILaneCFUsUs(field_454->field_18B4, field_454->field_18B8, field_454->field_18B8);
            y1 = x - field_44C;
        }
        CGtV3d fwd, right;
        GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, s, &fwd);
        GetAvgRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(lane, s, &right);
        right.SetY(0.0f);
        fwd.SetY(0.0f);
        fwd.Normalise();
        right.Normalise();
        e1 = func_0013F550_inl3(box, fwd, right, dir);
        CGtV3d dp2 = pos2 - sp;
        dp2.SetY(0.0f);
        float a2 = DotProduct(dp2, left);
        float w2 = GetTotalWidth__9CB3AILaneCFUsUs(lane, s, s);
        float x2;
        if (GtMath::IsEffectivelyZero(w2))
            x2 = 0.0f;
        else
            x2 = (a2 / w2) * GetTotalWidth__9CB3AILaneCFUsUs(field_454->field_18B4, field_454->field_18B8, field_454->field_18B8);
        y2 = x2 - field_44C;                    // [C] from the map centre also on the far-side path (y1 uses +0x448 there)
        e2 = func_0013F550_inl3(box, fwd, right, dir2);
    }
    // blend towards the far values and fill the cells between the two positions
    d = d + field_450 * (8.0f - d);
    float tb = t + field_450 * (500.0f - t);
    if (!(y1 <= y2)) {
        int hi = (int)(5.0f * (y1 + e1)) + 128;
        if (hi < 0) return;
        int lo = (int)(5.0f * (y2 - e2)) + 128;
        if (!(lo < 256)) return;
        func_0013F550_inl4(this, lo - 1, hi + 1, risk, d, 1.5f * tb);
    } else {
        int hi = (int)(5.0f * (y2 + e2)) + 128;
        if (hi < 0) return;
        int lo = (int)(5.0f * (y1 - e1)) + 128;
        if (!(lo < 256)) return;
        func_0013F550_inl4(this, lo - 1, hi + 1, risk, d, 1.5f * tb);
    }
}
