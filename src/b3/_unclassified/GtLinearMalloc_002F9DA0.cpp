// CGtLinearMalloc::Create(void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLinearMalloc.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLinearMalloc;
struct UnkStruct_002F9DA0_e0;

struct UnkStruct_002F9DA0_e0 {
    unsigned char pad_0[0x1];
};

class CGtLinearMalloc {
public:
    void Create(void* p0, unsigned int p1);

    unsigned char field_0;
    unsigned char pad_1[0x7];
    UnkStruct_002F9DA0_e0 * field_8;
    int field_C;
    int field_10;
};

// 0x002F9DA0
void CGtLinearMalloc::Create(void* p0, unsigned int p1)
{
    field_8 = (UnkStruct_002F9DA0_e0 *)p0;
    field_C = (int)&field_8[p1];
    field_10 = (int)field_8;
    field_0 = 1;
}
