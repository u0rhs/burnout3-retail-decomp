// CB3HUDTakedowns::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDTakedowns.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDTakedowns.h"

struct UnkStruct_003A2510_2;

struct UnkStruct_003A2510_2 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x64];
    int field_74;
    unsigned char pad_78[0x8];
    int field_80;
};

// 0x003A2510
void CB3HUDTakedowns::Update(float p0)
{
    int v0;
    UnkStruct_003A2510_2 * t0;
    if (field_95 != 0) {
        t0 = (UnkStruct_003A2510_2 *)field_34;
        v0 = field_34->field_68;
    } else {
        // [G] byte-offset pun in one arm: keeps retail's duplicated field_34 loads (identical arms get merged otherwise)
        t0 = (UnkStruct_003A2510_2 *)field_34;
        v0 = *(int *)((char *)field_34 + 0x68);
    }
    if (field_94 != 0 && field_98 != t0->field_74) {
        if (!(t0->field_C <= 0.0f)) {
            field_40 = 0.1f;
        }
        PrepareTakedownsObjects();
    } else {
        float t1 = field_40;
        if (!(t1 <= 0.0f)) {
            field_40 = (t1 - p0);
            PrepareTakedownsObjects();
        } else if (field_38 != v0 || field_3C != t0->field_80) {
            PrepareTakedownsObjects();
        }
    }
}
