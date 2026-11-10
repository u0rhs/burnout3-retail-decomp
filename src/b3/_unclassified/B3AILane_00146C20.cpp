// CB3AILane::FindSideLane(unsigned short*,EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: +'const EAISegmentLinkType v0 = type;'; 's = D_00522660.field_2C[best].field_4->field_8[bestSeg].fiel' -> 'UnkStruct_00146DB0_e *const  t0 = D_00522660.field_2C[best].field_4->field_8; li').

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
    CB3AILane *FindSideLane(unsigned short *, EAISegmentLinkType);
    static bool LaneIsDriveable(unsigned char id, unsigned short seg, unsigned short n);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
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
inline bool CB3AILane::LaneIsDriveable(unsigned char id, unsigned short seg, unsigned short n)
{
    if (id == 255) {
        return false;
    }
    return func_00148D60_inl1(&D_00522660.field_2C[id], seg, n);
}
// 0x00146C20
CB3AILane *CB3AILane::FindSideLane(unsigned short *seg, EAISegmentLinkType type)
{
    const EAISegmentLinkType v0 = type;
    unsigned char best = 255;
    unsigned short bestSeg = 0xFFFF;
    unsigned char link = field_4->field_8[*seg].field_4[type];
    unsigned short s = field_4->field_8[*seg].field_6[type];
    while (LaneIsDriveable(link, s, 1)) {
        best = link;
        bestSeg = s;
        UnkStruct_00146DB0_e *const  t0 = D_00522660.field_2C[best].field_4->field_8;
        link = D_00522660.field_2C[best].field_4->field_8[bestSeg].field_4[v0];
        s = t0[bestSeg].field_6[v0];
    }
    if (best == 255) {
        return this;
    }
    *seg = bestSeg;
    return &D_00522660.field_2C[best];
}
