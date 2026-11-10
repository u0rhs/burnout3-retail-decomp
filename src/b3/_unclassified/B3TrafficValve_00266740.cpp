// CB3TrafficValve::GetFormationAfterLaneChange(bool,unsigned char,int,unsigned char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (lifter draft params were shifted: (this, bool, uchar, int idx, uchar*); slot pointer (UnkStruct**)((char*)this+0x20)+i).

class CB3TrafficValve;
struct UnkStruct_00266740_2 {
    unsigned char pad_0[0x10];
    int field_10;
};
class CB3TrafficValve {
public:
    UnkStruct_00266740_2 * GetFormationAfterLaneChange(bool p0, unsigned char p1, int p2, unsigned char* p3);

    unsigned char pad_0[0x20];
    UnkStruct_00266740_2 * field_20[1];  // [G] element count unknown
    unsigned char pad_24[0xE8];
    unsigned char field_10C[1];  // [G] element count unknown
};

// 0x00266740
UnkStruct_00266740_2 * CB3TrafficValve::GetFormationAfterLaneChange(bool p0, unsigned char p1, int p2, unsigned char* p3)
{
    int i;
    if (!p0) {
        i = p2 + p1;
    } else {
        i = p2 - p1;
    }
    UnkStruct_00266740_2 ** slot = (UnkStruct_00266740_2 **)((char *)this + 0x20) + i;
    if ((*slot)->field_10 <= 0) {
        *p3 = 255;
        return 0;
    }
    *p3 = field_10C[i];
    field_10C[i] = (field_10C[i] + 1);
    field_10C[i] = ((unsigned int)field_10C[i] % (unsigned int)(*slot)->field_10);
    if (*slot == 0) {
        *p3 = 255;
    }
    return *slot;
}
