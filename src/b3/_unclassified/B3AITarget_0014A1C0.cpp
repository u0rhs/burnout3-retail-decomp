// CB3AITarget::GetDesiredDirection(GtMathPs2::CGtV3d*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (stabs2: header NormaliseGetLength (hdr15) replaces stale local stand-in + pad).

// stabs2: header NormaliseGetLength (hdr15 noreorder form) in place of the stale local pass2a_ngl stand-in, no N140 pad; Revenge order lrResult then the W lane read [L]
#include "b3/GtMathPs2.h"

class CB3AITargetSpline {
public:
    float GetDesiredDirection(GtMathPs2::CGtV3d * p0) const;
};

struct UnkStruct_0014A1C0_obj {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
};

struct UnkStruct_0014A1C0_car {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
    unsigned char pad_40[0x23F0];
    UnkStruct_0014A1C0_obj * field_2430;
};

class CB3AITarget {
public:
    float GetDesiredDirection(GtMathPs2::CGtV3d * p0) const;

    unsigned char pad_0[0x4];
    UnkStruct_0014A1C0_car * field_4;
    unsigned char pad_8[0x8];
    CB3AITargetSpline field_10;
    unsigned char pad_11[0x16F];
    GtMathPs2::CGtV3d field_180;
    unsigned char field_190;
};

// 0x0014A1C0
float CB3AITarget::GetDesiredDirection(GtMathPs2::CGtV3d * p0) const
{
    if (field_190 == 0) {
        return field_10.GetDesiredDirection(p0);
    }
    *p0 = field_180 - field_4->field_30;
    float r = p0->NormaliseGetLength();
    float w = field_4->field_2430->field_B0.W();
    if (w > 1.0f) {
        r = r / w;
    }
    return r;
}
