// CGt2dObjectTable::GetRowSize(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectTable.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (psweep: scoped #pragma opt_arithtransformation off [G] (N182)).

// 11 instrs off: MWCC reassociates the float sum (f2+(f1+f0) won't hold); retail keeps sp slot direct (no addiu t2 pointer) and d in t0 (a1 reused as index)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
using GtMathPs2::CGtV2d;

struct UnkStruct_Gt2dObjectTable_row { float field_0; float field_4; float field_8; };
struct UnkStruct_Gt2dObjectTable_data {
    unsigned char pad_0[8];
    int field_8;
    int field_C;
    UnkStruct_Gt2dObjectTable_row *field_10;
    UnkStruct_Gt2dObjectTable_row *field_14;
};
struct UnkStruct_Gt2dObjectTable_self {
    float field_0; float field_4;
    unsigned char pad_8[0x28];
    UnkStruct_Gt2dObjectTable_data *field_30;
};

extern "C" CGtV2d GetRowSize__16CGt2dObjectTableFi(UnkStruct_Gt2dObjectTable_self *self, int row)
{
    UnkStruct_Gt2dObjectTable_data *d = self->field_30;
    if (d == 0) return CGtV2d(0.0f, 0.0f);
    if (row < 0 || row > d->field_8) return CGtV2d(0.0f, 0.0f);
    float s[2];  // [G] pass2b: a float pair kept in memory (address-taken array) gives retail's per-iteration reloads at 8(sp)
    s[1] = d->field_10[row].field_4;
    s[0] = d->field_14[0].field_4;
    int n = d->field_C;
    for (int j = 1; j < n; j++) {
        const UnkStruct_Gt2dObjectTable_row *e = &d->field_14[j];
        float a = e->field_0;
        float b = e->field_4;
        s[0] = a + s[0];
        s[0] = b + s[0];
    }
    return *(CGtV2d *)s;
}


#pragma pop
