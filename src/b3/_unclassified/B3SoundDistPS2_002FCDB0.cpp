// CB3SoundDistortion::CalculateDistance(GtMathPs2::CGtV3d*,GtMathPs2::CGtV3d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near27: header (*a - *b).GetLength() replaces the VU stand-ins; per-arm field_1848 tails with explicit returns (else-if chain d > f8 / d < fc / main); negate block via goto at the end).

// CB3SoundDistortion::CalculateDistance(CGtV3d*, CGtV3d*) -- hand-matched (near27).
// [C] name: the mangled symbol in retail's tables. Class declared locally with only the touched fields; field
// names are placeholders, types [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3SoundDistortion {
public:
    void CalculateDistance(CGtV3d *a, CGtV3d *b);
    unsigned char pad_0[0x1848];
    int field_1848;
    unsigned char pad_184C[0x90];
    float field_18DC;
    unsigned char pad_18E0[0x10];
    float field_18F0;
    float field_18F4;
    float field_18F8;
    float field_18FC;
};
// 0x002FCDB0
void CB3SoundDistortion::CalculateDistance(CGtV3d *a, CGtV3d *b)
{
    field_18F4 = field_18F0;
    float q;
    float d = (*a - *b).GetLength();
    field_18F0 = d;
    if (d > field_18F8) {
        field_18DC = 0.0f;
        field_1848 = (int)(65536.0f * field_18DC);
        return;
    } else if (d < field_18FC) {
        field_18DC = 1.0f;
        field_1848 = (int)(65536.0f * field_18DC);
        return;
    } else {
        field_18DC = (field_18F8 - field_18FC) * (d / field_18F8);
        q = field_18DC / field_18F8;
        field_18DC = q;
        if (q < 0.0f) goto neg;  // [G] goto: retail lays the negate block out of line at the end
    back:
        field_18DC = 1.0f - field_18DC;
        field_1848 = (int)(65536.0f * field_18DC);
        return;
    }
neg:
    field_18DC = -q;
    goto back;
}
