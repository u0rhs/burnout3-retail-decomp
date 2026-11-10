// CB3AILane::UpdateSegmentIndex(unsigned short*,signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near15: sibling FindConnectedDrivableLane's link-follow inline for both probes; wrap arm as early return).

// CB3AILane::UpdateSegmentIndex(unsigned short*, signed char) -- hand-written (a67 + near15): steps the segment index;
// past either end it wraps on a looping lane, else follows link 0, then link 1, of the segment to a connected lane
// (the sibling FindConnectedDrivableLane's link-follow inline). Types and fields are placeholders [G].

class CB3AILane;
struct UnkStruct_00147180_2;
struct UnkStruct_00147180_e0;
struct UnkStruct_D_00522660;

struct UnkStruct_00147180_e0 {  // [G] 10-byte segment link record
    unsigned char pad_0[0x4];
    unsigned char field_4[2];
    unsigned short field_6[2];
};

struct UnkStruct_00147180_2 {
    unsigned char pad_0[0x8];
    UnkStruct_00147180_e0 * field_8;
    unsigned short field_C;
    unsigned char field_E;
};

struct UnkStruct_00147180_e3 {
    unsigned char pad_0[0x8];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    UnkStruct_00147180_e3 field_2C[1];  // [G] element count unknown
};

class CB3AILane {
public:
    CB3AILane * UpdateSegmentIndex(unsigned short* p0, signed char p1);

    unsigned char pad_0[0x4];
    UnkStruct_00147180_2 * field_4;
};

extern UnkStruct_D_00522660 D_00522660;

// [L] the link-follow inline of the proven sibling CB3AILane::FindConnectedDrivableLane (func_00146DB0_inl1, 0x146DB0):
// the connected lane through link `type` of segment s (null for 255), s moved to the linked segment.
static inline CB3AILane *func_00147180_inl1(CB3AILane *l, unsigned short &s, int type)
{
    unsigned char link = l->field_4->field_8[s].field_4[type];
    if (link == 255) {
        return 0;
    }
    s = l->field_4->field_8[s].field_6[type];
    return (CB3AILane *)&D_00522660.field_2C[link];
}

// 0x00147180
CB3AILane * CB3AILane::UpdateSegmentIndex(unsigned short* p0, signed char p1)
{
    unsigned short t0 = *p0;
    int n = t0 + p1;
    if (n >= 0 && n < field_4->field_C) {
        *p0 = n;
        return this;
    }
    UnkStruct_00147180_2 * s = field_4;
    if (s->field_E != 0) {
        *p0 = (n + s->field_C) % s->field_C;
        return this;
    }
    unsigned short seg = t0;
    CB3AILane * r = func_00147180_inl1(this, seg, 0);
    if (r == 0) {
        r = func_00147180_inl1(this, seg, 1);
        if (r == 0) {
            return 0;
        }
    }
    return r;
}
