// CB3DirectionalBlurBase::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DirectionalBlur.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3DirectionalBlurBase.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"

extern UnkStruct_D_004F50A0 D_004F50A0;

// 0x00426030
int CB3DirectionalBlurBase::Prepare()
{
    field_0.Zero();
    field_10 = 0.5f;
    field_14 = 0.5f;
    field_18 = 0.9999f;
    field_1C = 0.9999f;
    field_20 = 0;
    field_24 = D_004F50A0.field_0;
    return 1;
}
