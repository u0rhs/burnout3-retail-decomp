// CB3MenuInputButton::Update(float,float,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuInput.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuInputButton.h"

// 0x0021A9B0
void CB3MenuInputButton::Update(float p0, float p1, int p2)
{
    field_0 = 0;
    if (field_2 == 0) {
        if (field_4 < 0.03f && !(p0 < 0.03f)) {
            field_0 = 1;
            field_2 = 1;
            field_8 = 0.67f;
        }
    } else if (p0 > 0.01f) {
        if (p2 != 0) {
        if (p0 <= 0.4f) {
            field_8 -= p1;
        } else if (p0 < 0.9f) {
            field_8 -= p1 * (1.0f + 2.0f * ((p0 - 0.4f) / 0.49999997f));
        } else {
            field_8 -= 3.0f * p1;
        }
        if (field_8 < 0.0f) {
            field_0 = 1;
            field_8 += 0.2f;
            if (field_8 < 0.0f) {
                field_8 = 0.0f;
            }
        }
        }
    } else {
        field_2 = 0;
    }
    field_4 = p0;
}
