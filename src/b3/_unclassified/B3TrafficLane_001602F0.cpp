// CB3TrafficLane::GetSignedForwardDistBetweenParams(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a93: inline helper per param, im=i-1 local).

class CB3TrafficLane;
struct UnkStruct_001602F0_1;
struct UnkStruct_001602F0_e0;

struct UnkStruct_001602F0_1 {
    unsigned char pad_0[0x4];
    UnkStruct_001602F0_e0 * field_4;
    unsigned char pad_8[0x8];
    int field_10;
};

struct UnkStruct_001602F0_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};

class CB3TrafficLane {
public:
    float GetSignedForwardDistBetweenParams(float p0, float p1);

    UnkStruct_001602F0_1 * field_0;
};
static inline float func_001602F0_inl1(UnkStruct_001602F0_1 *t0, float p)
{
    int t1 = t0->field_10;
    UnkStruct_001602F0_e0 *t2 = t0->field_4;
    int i = (int)p;
    if (t1 < i) {
        i = t1;
    }
    int im = i - 1;
    float v1;
    if (im >= 0) {
        v1 = t2[im].field_0;
    } else {
        v1 = 0.0f;
    }
    if (i < t1) {
        v1 = v1 + (p - (float)i) * (t2[i].field_0 - v1);
    }
    return v1;
}
// 0x001602F0
float CB3TrafficLane::GetSignedForwardDistBetweenParams(float p0, float p1)
{
    float a = func_001602F0_inl1(field_0, p0);
    float b = func_001602F0_inl1(field_0, p1);
    return a - b;
}
