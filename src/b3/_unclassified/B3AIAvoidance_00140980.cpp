// CB3AIAvoidanceMap::Prepare(CB3AICar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bool return; loop clamp = Min(Max(hi,lo),hi)*32767/hi with locals; Zero() x4).

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3AICar;
class CB3AIAvoidanceMap {
public:
    bool Prepare(CB3AICar *);
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    unsigned char field_40[256];
    unsigned char field_140[256];
    short field_240[256];
    unsigned char field_440;
    unsigned char field_441;
    unsigned char field_442;
    unsigned char pad_443;
    int field_444;
    int field_448;
    int field_44C;
    int field_450;
    CB3AICar *field_454;
};
// 0x00140980
bool CB3AIAvoidanceMap::Prepare(CB3AICar *car)
{
    field_454 = car;
    for (int i = 0; i < 256; i++) {
        field_140[i] = 0xFF;
        float hi = 500.0f;
        float lo = -500.0f;
        field_240[i] = (short)(32767.0f * GtMath::Min(GtMath::Max(hi, lo), hi) / hi);
        field_40[i] = 0;
    }
    field_10.Zero();
    field_0.Zero();
    field_20.Zero();
    field_444 = 0;
    field_448 = 0;
    field_44C = 0;
    field_30.Zero();
    field_440 = 0;
    field_441 = 0;
    field_442 = 0;
    field_450 = 0;
    return true;
}
