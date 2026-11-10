// CB3AiCarPreRaceRpmSpike::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scoped opt_dead_assignments off [G] orders the else arm's two sub.s).

#include "b3/classes/UnkStruct_D_0052267C.h"

class CB3AiCarPreRaceRpmSpike {
public:
    void Update();

    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    unsigned char field_18;
};

extern UnkStruct_D_0052267C D_0052267C;

// [G] unnamed inlined helpers: a clamped smoothstep and an a + t*(b - a) blend ([L] GtMath::Interpolate(float,float,float),
// E map 0x14CCF0).
static inline float func_001D2D70_inl1(float t, float e0, float e1)
{
    if (t < e0) return 0.0f;
    if (!(t < e1)) return 1.0f;
    float x = (t - e0) / (e1 - e0);
    return (3.0f - 2.0f * x) * (x * x);
}
static inline float func_001D2D70_inl2(float a, float b, float t) { float d = b - a; return a + t * d; }

// N182: `#pragma opt_dead_assignments off` ([G] scoped to this function): orders the else arm's two
// independent sub.s (1 - q before 0 - field_8) as retail.
#pragma push
#pragma opt_dead_assignments off
// 0x001D2D70
void CB3AiCarPreRaceRpmSpike::Update()
{
    if (field_14 > 0.0f) field_14 -= D_0052267C.field_0;
    if (field_18 != 0) {
        if (!(field_4 <= 0.0f)) {
            float s = func_001D2D70_inl1(1.0f - field_4 / field_C, 0.0f, 1.0f);
            field_0 = func_001D2D70_inl2(0.0f, field_8, s);
            field_4 -= D_0052267C.field_0;
        } else {
            field_18 = 0;
            field_4 = field_10;
            field_0 = field_8;
        }
    } else {
        if (!(field_4 <= 0.0f)) {
            float t = 1.0f - field_4 / field_10;
            field_0 = func_001D2D70_inl2(field_8, 0.0f, t);
            field_4 -= D_0052267C.field_0;
        }
    }
}
#pragma pop
