// CB3TrafficParam::CalculateTargetParamMatrix() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficParam;
struct UnkStruct_00161B20_e0;
struct UnkStruct_D_00522660;

struct UnkStruct_00161B20_e0 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00161B20_e0 field_0[1];  // [G] element count unknown
};

class CB3TrafficParam {
public:
    void CalculateTargetParamMatrix();

    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x15];
    unsigned char field_49;
};

extern UnkStruct_D_00522660 D_00522660;

extern "C" void func_001618C0(CB3TrafficParam *, void *, float);

// 0x00161B20
void CB3TrafficParam::CalculateTargetParamMatrix()
{
    func_001618C0(this, ((char *)&D_00522660.field_0[field_49] + 0x34210), field_30);
}
