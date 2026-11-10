// CB3AIControlData::GetNumCarsDoingCatchup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIControlData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pointer local p=&D_0064D3B0, guards merged with ||).

// CB3AIControlData::GetNumCarsDoingCatchup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIControlData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3AIControlData;
struct UnkStruct_D_0064D3B0;

struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x1970];
    int field_1970;
};

class CB3AIControlData {
public:
    int GetNumCarsDoingCatchup();
};

extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern int _kanNumCarsDoingCatchup[];  // [G] element count unknown

// 0x00143F50
int CB3AIControlData::GetNumCarsDoingCatchup()
{
    UnkStruct_D_0064D3B0 *p = &D_0064D3B0;
    if (p == 0 || p->field_1970 == 8) {
        return 2;
    }
    return _kanNumCarsDoingCatchup[p->field_1970];
}
