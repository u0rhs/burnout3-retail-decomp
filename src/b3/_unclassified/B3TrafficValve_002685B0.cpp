// CB3TrafficValve::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficValve;
struct UnkStruct_002685B0_e0;
struct UnkStruct_002685B0_e1;

struct UnkStruct_002685B0_e0 {
    unsigned char pad_0[0x8];
    void * field_8;
    unsigned char pad_C[0x4];
    int field_10;
};

struct UnkStruct_002685B0_e1 {
    unsigned char pad_0[0x2];
};

class CB3TrafficValve {
public:
    void Construct();

    UnkStruct_002685B0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_2[0x3A];
    UnkStruct_002685B0_e0 field_3C[1];  // [G] element count unknown
};

extern "C" void * memset(void *, int, unsigned int);

// 0x002685B0
void CB3TrafficValve::Construct()
{
    memset(((char *)this + 0x94), 0, 8);
    for (int i = 0; (i < 4); i++) {
        field_3C[i].field_10 = 2;
        field_3C[i].field_8 = ((char *)&field_0[i] + 0x94);
    }
}
