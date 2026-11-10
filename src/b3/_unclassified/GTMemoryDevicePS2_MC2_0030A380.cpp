// CMemoryDevicePS2::Format() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (result var v0 (=1 / =0 in if/else) -> early returns: if (call(...) == 0) return 1; stores; return 0;).

// CMemoryDevicePS2::Format() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int Format();

    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    unsigned char pad_5C[0x74];
    int field_D0;
    int field_D4;
    int field_D8;
};

extern "C" int func_00241F98(int);

// 0x0030A380
int CMemoryDevicePS2::Format()
{
    if (field_D4 != 0) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        return 0;
    }
    if (func_00241F98(field_54) == 0) {
        return 1;
    }
    field_4C = 0;
    field_50 = 14;
    field_58 = 13;
    field_D0 = 0;
    field_D8 = -1;
    field_D4 = 1;
    return 0;
}
