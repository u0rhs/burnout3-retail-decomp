// CB3AILane::FindConnectedDrivableLane(unsigned short*,EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (inlc: LaneIsDriveable inline = while(n--) helper taking the lane (keeps the constant 1 unfolded, rotated loop); lookup reads l->field_4->field_8[s] twice).

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
    CB3AILane *FindConnectedDrivableLane(unsigned short *, EAISegmentLinkType);
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
// 0x00146DB0
CB3AILane *CB3AILane::FindConnectedDrivableLane(unsigned short *seg, EAISegmentLinkType type)
{
    unsigned short cur = *seg;
    CB3AILane *lane = func_00146DB0_inl1(this, cur, type);
    while (lane != 0) {
        if (lane->LaneIsDriveable(cur, 1)) {
            *seg = cur;
            return lane;
        }
        lane = func_00146DB0_inl1(lane, cur, type);
    }
    return 0;
}
