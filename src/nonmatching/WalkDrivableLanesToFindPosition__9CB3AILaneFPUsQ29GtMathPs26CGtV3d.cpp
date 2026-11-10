// NONMATCHING: WalkDrivableLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d -- retail 217 / ours 216 instructions, 2 in changed runs
// a162: 216 vs 217 instrs, 2 changed. Retail materialises addiu v1,sp,0x60 early then 'move a1,v1' at the first IsInSegment call; ours addiu a1,sp,0x60 at the call (same unsolved gap as WalkLanesToFindPosition). Everything else matches incl. the two driveable-lookup inlines (func_00146F20_inl1 with unsigned short& s, s=cur only when driveable) and the by-value CGtV3d copy via extern C IsInSegment(lane,&p,cur). Tried pointer locals (q/pp), const p, decl orders.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (inlc: LaneIsDriveable inline = while(n--) helper taking the lane (keeps the constant 1 unfolded, rotated loop); lookup reads l->field_4->field_8[s] twice).

#include "b3/GtMathPs2.h"
extern "C" int IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(const void *, const void *, unsigned short);
enum EAISegmentLinkType {};
struct UnkStruct_00146DB0_e {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct CB3AILaneStruct {
    unsigned char pad_0[8];
    UnkStruct_00146DB0_e *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    CB3AILane *WalkDrivableLanesToFindPosition(unsigned short *, GtMathPs2::CGtV3d);
    CB3AILane *UpdateDrivableSegmentIndex(unsigned short *, signed char);
    bool LaneIsDriveable(unsigned short seg, unsigned short n);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
// [L] inlc: LaneIsDriveable(seg, n)'s body (0x148D60) as a helper that takes the lane and reads its road struct
// itself. `while (n--)` makes MWCC rotate the inlined loop, so a constant n stays in a register
// (`daddiu t1,zero,1; beqz t1`) as in retail; taking the lane (not field_4) keeps the caller's own field_4 load
// un-CSE'd.
static inline bool func_00148D60_inl1(const CB3AILane *l, unsigned short seg, unsigned short n)
{
    const CB3AILaneStruct *r = l->field_4;
    while (n--) {
        if ((r->field_8[seg].field_3 & 7) == 5) {
            return false;
        }
        seg++;
        if (seg >= r->field_C) {
            if (r->field_E == 0) {
                break;
            }
            seg = 0;
        }
    }
    return true;
}

inline bool CB3AILane::LaneIsDriveable(unsigned short seg, unsigned short n)
{
    return func_00148D60_inl1(this, seg, n);
}
static inline CB3AILane *func_00146DB0_inl1(CB3AILane *l, unsigned short &s, EAISegmentLinkType type)
{
    unsigned char link = l->field_4->field_8[s].field_4[type];
    if (link == 255) {
        return 0;
    }
    s = l->field_4->field_8[s].field_6[type];
    return &D_00522660.field_2C[link];
}
static inline CB3AILane *func_00146F20_inl1(CB3AILane *l, unsigned short &s, EAISegmentLinkType type)
{
    unsigned short cur = s;
    CB3AILane *lane = func_00146DB0_inl1(l, cur, type);
    if (lane != 0) {
        if (lane->LaneIsDriveable(cur, 1)) {
            s = cur;
            return lane;
        }
    }
    return 0;
}
// 0x001461D0
CB3AILane *CB3AILane::WalkDrivableLanesToFindPosition(unsigned short *seg, GtMathPs2::CGtV3d pos)
{
    CB3AILane *lane = this;
    GtMathPs2::CGtV3d p = pos;
    unsigned short cur = *seg;
    int last = 16;
    int count = 0;
    unsigned short local = cur;
    int r = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &p, cur);
    while (r != 0) {
        count++;
        if (count == 128) {
            break;
        }
        if ((r & 4) != 0) {
            if (last == 8) {
                break;
            }
            CB3AILane *n = lane->UpdateDrivableSegmentIndex(&local, 1);
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 4;
        } else if ((r & 8) != 0) {
            if (last == 4) {
                break;
            }
            CB3AILane *n = lane->UpdateDrivableSegmentIndex(&local, -1);
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 8;
        } else if ((r & 1) != 0) {
            if (last == 2) {
                break;
            }
            CB3AILane *n = func_00146F20_inl1(lane, local, (EAISegmentLinkType)0);
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 1;
        } else if ((r & 2) != 0) {
            if (last == 1) {
                break;
            }
            CB3AILane *n = func_00146F20_inl1(lane, local, (EAISegmentLinkType)1);
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 2;
        }
        r = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &p, cur);
    }
    *seg = cur;
    return lane;
}
