// CGtSoundListener::GetPos(GtMathPs2::CGtV3d*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (extern C void, hand).

#include "b3/GtMathPs2.h"
struct UnkStruct_a167_sl1 { unsigned char pad_0[0x8]; struct UnkStruct_a167_sl2 * field_8; };
struct UnkStruct_a167_sl2 { unsigned char pad_0[0x48]; float f0; float f1; float f2; };
struct UnkStruct_a167_sl3 { float field_0; float field_4; float field_8; unsigned char pad_C[4]; float field_10; float field_14; float field_18; unsigned char pad_1C[4]; };
extern "C" void GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(UnkStruct_a167_sl1 * self, GtMathPs2::CGtV3d * p0)
{
    UnkStruct_a167_sl3 local;
    UnkStruct_a167_sl2 * t0 = self->field_8;
    float t1 = t0->f0;
    float t2 = t0->f1;
    float t3 = t0->f2;
    local.field_0 = t1;
    local.field_4 = t2;
    local.field_8 = t3;
    u_long128 t4 = *(u_long128 *)&local.field_0;
    local.field_10 = t1;
    local.field_14 = t2;
    local.field_18 = t3;
    p0->mData = t4;
}
