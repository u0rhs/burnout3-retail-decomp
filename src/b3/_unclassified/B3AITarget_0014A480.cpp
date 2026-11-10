// CB3AITarget::LaneIsUndesirable(const CB3AILane*,unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AITarget has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (element-pointer segment read + return r in the t!=5 arm + scoped opt_repositioncode off [G]).

// CB3AITarget::LaneIsUndesirable(const CB3AILane*, unsigned short) const
struct UnkStruct_0014A480_e {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_0014A480_1 {
    unsigned char pad_0[0x8];
    UnkStruct_0014A480_e * field_8;
};

class CB3AILane {
public:
    unsigned char pad_0[0x4];
    UnkStruct_0014A480_1 * field_4;
};

struct UnkStruct_0014A480_2 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

class CB3AITarget {
public:
    unsigned int LaneIsUndesirable(const CB3AILane * p0, unsigned short p1) const;

    unsigned char pad_0[0x4];
    UnkStruct_0014A480_2 * field_4;
    unsigned char pad_8[0x1E8];
    unsigned char field_1F0;
    unsigned char field_1F1;
    unsigned char pad_1F2[0xA];
    int field_1FC;
    unsigned char pad_200[0x91];
    unsigned char field_291;
    unsigned char field_292;
};

// near19: element-pointer local for the segment read; `return r;` at the end of the t != 5 arm; scoped
// opt_repositioncode off ([G], N182 pragma policy) keeps retail's inline small arm and the `b; nop` join relay.
#pragma push
#pragma opt_repositioncode off
// 0x0014A480
unsigned int CB3AITarget::LaneIsUndesirable(const CB3AILane * p0, unsigned short p1) const
{
    const UnkStruct_0014A480_e * e = &p0->field_4->field_8[p1];
    unsigned int t = e->field_3 & 7;
    unsigned int r = 0;
    if (t != 5) {
        if (field_4->field_1914 == 0) {
            if (t == 4) r |= 1;
        } else {
            if (field_1F1 == 0 && t == 4) {
                if (field_291 != 0) { r |= 1; } else { r |= 4; }
            }
            if (field_1F0 == 0 && (t == 1 || t == 3) && field_1FC != 0) {
                if (field_292 != 0) { r |= 1; } else { r |= 4; }
            }
        }
        return r;
    } else {
        r = 4;
    }
    return r;
}
#pragma pop
