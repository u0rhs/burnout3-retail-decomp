// CB3CoronaDynamicArray::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pass2a: natural header CGtV4d::SetW(0.0f) x2 in a plain for loop (b119p hoists both scalar qmtc2s)).


#include "b3/GtMathPs2.h"
struct UnkStruct_00307560_e {
    GtMathPs2::CGtV4d field_0;
    unsigned char pad_10[0x10];
};
struct UnkStruct_00307560_p {
    UnkStruct_00307560_e * field_0;
    UnkStruct_00307560_e * field_4;
};
class CB3CoronaDynamicArray {
public:
    int Prepare();
    unsigned char pad_0[0x10];
    UnkStruct_00307560_p field_10[2];
    UnkStruct_00307560_e * field_20;
    UnkStruct_00307560_e * field_24;
    short field_28;
    short field_2A[2];
    signed char field_2E[2];
    signed char field_30;
};
// 0x00307560
int CB3CoronaDynamicArray::Prepare()
{
    for (int p = 0; p < 2; p++) {
        for (int i = 0; i < field_28; i++) {
            field_10[p].field_0[i].field_0.SetW(0.0f);
            field_10[p].field_4[i].field_0.SetW(0.0f);
        }
        field_2E[p] = 0;
        field_2A[p] = 0;
    }
    field_20 = 0;
    field_24 = 0;
    field_30 = -1;
    return 1;
}
