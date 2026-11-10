// CB3AILane::GetTotalWidth(unsigned short,unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (s318: FindSideLane/N178 LaneIsDriveable clone; (int)p1-(int)p0; [L] N185 compiler-chosen vsub + SetY stand-in).

// CB3AILane::GetTotalWidth(unsigned short,unsigned short) const -- s318 (2026-10-27), cloned from the proven sibling
// FindSideLane__9CB3AILane (B3AILane_00146C20.cpp: LaneIsDriveable / N178 helper). [C] name: retail's tables.
// Walks the side links (field_4[0]/field_6[0], then [1]) while the next lane is driveable, tracking the vertex pair
// at the same offset (p1 - p0), then returns the XZ distance between the two edge vertices.
#include "b3/GtMathPs2.h"

struct UnkStruct_00148140_v { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00146DB0_e {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct CB3AILaneStruct {
    UnkStruct_00148140_v *field_0;
    unsigned char pad_4[4];
    UnkStruct_00146DB0_e *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    float GetTotalWidth(unsigned short p0, unsigned short p1) const;
    static bool LaneIsDriveable(unsigned char id, unsigned short seg, unsigned short n);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_00148140_e9 { GtMathPs2::CGtV3d field_0; };
struct UnkStruct_D_0064D354 {
    UnkStruct_00148140_e9 *field_0;
    unsigned char pad_4[0xC];
};
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

// 0x00148140
float CB3AILane::GetTotalWidth(unsigned short p0, unsigned short p1) const
{
    int d = (int)p1 - (int)p0;
    unsigned short lv = field_4->field_0[p0 + d].field_0;
    unsigned short rv = field_4->field_0[p0 + d].field_2;
    unsigned char link = field_4->field_8[p0].field_4[0];
    unsigned short s = field_4->field_8[p0].field_6[0];
    while (LaneIsDriveable(link, s, 1)) {
        const CB3AILaneStruct *l = D_00522660.field_2C[link].field_4;
        lv = l->field_0[s + d].field_0;
        link = l->field_8[s].field_4[0];
        s = l->field_8[s].field_6[0];
    }
    link = field_4->field_8[p0].field_4[1];
    s = field_4->field_8[p0].field_6[1];
    while (LaneIsDriveable(link, s, 1)) {
        const CB3AILaneStruct *l = D_00522660.field_2C[link].field_4;
        rv = l->field_0[s + d].field_2;
        link = l->field_8[s].field_4[1];
        s = l->field_8[s].field_6[1];
    }
    // [L] N185: stands in for missing GtMathPs2 inlines -- the compiler-chosen vsub form (N198) and SetY(0.0f)
    // with its zero moved in between the operand loads (VU numbering as retail: vf2/vf3 operands, vf4 zero).
    u_long128 b = D_0064D354.field_0[rv].field_0.mData;
    u_long128 a = D_0064D354.field_0[lv].field_0.mData;
    u_long128 z; asm("qmtc2.ni %1, %0" : "=j"(z) : "r"(0.0f));
    u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a), "j"(b));
    asm("vaddx.y %0, $vf0, %1x" : "+j"(t) : "j"(z));
    GtMathPs2::CGtV3d v(t);
    return v.GetLength();
}
