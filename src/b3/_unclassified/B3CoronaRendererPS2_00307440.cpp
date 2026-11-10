// CB3CoronaDynamicArray::EndUpdate() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (inline-asm CGtV4d::SetW(0.0f) body (vsubw.w/vaddx.w) local; header lacks SetW(float)).

#include "b3/GtMathPs2.h"
class CB3CoronaDynamicArray;
struct UnkStruct_00307440_e {
    GtMathPs2::CGtV4d field_0;
    unsigned char pad_10[0x10];
};
class CB3CoronaDynamicArray {
public:
    void EndUpdate();
    unsigned char pad_0[0x20];
    UnkStruct_00307440_e * field_20;
    UnkStruct_00307440_e * field_24;
    short field_28;
    short field_2A[2];
    signed char field_2E[2];
    signed char field_30;
};
// 0x00307440
void CB3CoronaDynamicArray::EndUpdate()
{
    int n = ((int)field_24 - (int)field_20) / 32;
    field_2A[field_30] = field_28 - (short)n;
    if (field_2A[field_30] != 0 && field_20 < field_24) {
        u_long128 z;
        float zf = 0.0f;
        asm("qmtc2.ni %0, $vf2" : : "r"(zf));
        while (field_20 < field_24) {
            asm("vsubw.w %0, $vf0, $vf0w\n\tvaddx.w %0, %0, $vf2x" : "+j"(field_20->field_0.mData));
            field_20 = field_20 + 1;
        }
    }
    field_20 = 0;
    field_24 = 0;
    field_30 = -1;
}
