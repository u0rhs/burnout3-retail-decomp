// CB3HUDScore::UpdateMessageAnimation(CB3HUDScore::CScoreMessage*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDScore.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near21: interpolate inline with (b - a) in its own local (v310) fixed FP numbering and the third branch's mul/sub).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

extern float D_004E08D4;
extern float D_004E06B8;
extern float D_004E0928;

static inline float func_001A12B0_inl1(float a, float b, float u)
{
    float d = b - a;  // [G] GtMath::Interpolate-style body (v310): d in its own local gives retail madd operand order
    return 0.0f + a + d * u;
}
struct UnkStruct_001A2100_obj {
    CGtV2d field_0;
    CGtV2d field_8;
};
class CB3HUDScore {
public:
    class CScoreMessage {
    public:
        unsigned char pad_0[0x4];
        UnkStruct_001A2100_obj * field_4;
        unsigned char pad_8[0x84];
        float field_8C;
    };
    void UpdateMessageAnimation(CScoreMessage * p0);

    unsigned char pad_0[0x13E];
    unsigned char field_13E;
};

// 0x001A2100
void CB3HUDScore::UpdateMessageAnimation(CScoreMessage * p0)
{
    float t = p0->field_8C;
    float x;
    if (t < D_004E08D4) {
        x = func_001A12B0_inl1(370.0f, 0.0f, 5.0f * (D_004E08D4 - t));
    } else if (t < D_004E06B8) {
        x = func_001A12B0_inl1(320.0f, 370.0f, 10.0f * (D_004E06B8 - t));
    } else if (t < D_004E0928) {
        x = 320.0f;
    } else if (t < 5.0f) {
        float u = 5.0f * (5.0f - t);
        u = 1.0f - u;
        x = func_001A12B0_inl1(320.0f, 640.0f, u);
    }
    CGtV2d pos;
    pos.marValues[0] = x - 320.0f;
    if (field_13E) {
        pos.marValues[1] = 55.0f;
    } else {
        pos.marValues[1] = 0.0f;
    }
    p0->field_4->field_0 = pos;
    p0->field_4->field_8 = CGtV2d(1.0f, 1.0f);
}
