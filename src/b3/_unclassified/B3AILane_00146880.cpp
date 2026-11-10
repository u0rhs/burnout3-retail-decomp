// CB3AILane::GetSidePosition(unsigned short,int,GtMathPs2::CGtV3d*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling FindSideLane loop body (held element base t0), int pt, 16-byte D_0064D354 wrapper, declaration-order sweep).

// CB3AILane::GetSidePosition(unsigned short,int,GtMathPs2::CGtV3d*) const -- archived a162 draft, matched by s315:
// loop body in the proven sibling FindSideLane's shape (element base `t0` held, link read again through the lane),
// `int pt` (no re-masking at the final index), D_0064D354 as a 16-byte wrapper (lui/lw), top declarations ordered
// for retail's registers (sreg sweep). [C] name: retail's tables; Area not evidenced, so _unclassified/.
#include "b3/GtMathPs2.h"
struct UnkStruct_00146880_p {
    unsigned short field_0[2];
};
struct UnkStruct_00146880_e {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct CB3AILaneStruct {
    UnkStruct_00146880_p *field_0;
    unsigned char pad_4[4];
    UnkStruct_00146880_e *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    void GetSidePosition(unsigned short, int, GtMathPs2::CGtV3d *) const;
    static bool LaneIsDriveable(unsigned char id, unsigned short seg, unsigned short n);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 { GtMathPs2::CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
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
// 0x00146880
void CB3AILane::GetSidePosition(unsigned short seg, int side, GtMathPs2::CGtV3d *out) const
{
    const CB3AILane *lane;
    unsigned char link;
    unsigned short s;
    int pt;
    int idx;
    idx = 1;
    if (side == 1) {
        idx = 0;
        pt = field_4->field_0[seg].field_0[0];
    } else {
        pt = field_4->field_0[seg].field_0[1];
    }
    link = field_4->field_8[seg].field_4[idx];
    s = field_4->field_8[seg].field_6[idx];
    while (LaneIsDriveable(link, s, 1)) {
        lane = &D_00522660.field_2C[link];
        if (side == 1) {
            pt = lane->field_4->field_0[s].field_0[0];
        } else {
            pt = lane->field_4->field_0[s].field_0[1];
        }
        UnkStruct_00146880_e *const t0 = lane->field_4->field_8;
        link = lane->field_4->field_8[s].field_4[idx];
        s = t0[s].field_6[idx];
    }
    *out = D_0064D354.field_0[pt];
}
