// CMemoryDevicePS2::Write(const char*,unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (if/else with result var -> early returns: if (call(...) == 0) return 1; <reset>; return 0;).

class CMemoryDevicePS2 {
public:
    int Write(const char* p0, unsigned int p1, unsigned int p2);

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
extern "C" int func_00242348(int, void *, const char*, unsigned int, unsigned int);

int CMemoryDevicePS2::Write(const char* p0, unsigned int p1, unsigned int p2)
{
    if ((field_4C & 2) == 0) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        return 0;
    }
    if (func_00242348(field_54, (char *)this + 4, p0, p2, p1) == 0) {
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
