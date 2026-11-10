// CB3SoundESMGraphInputs::ApplyLag(const CB3SoundESMGraphInputs&,const CB3SoundESMInputLag*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (float fields; void; nested inline clamp: lo test outer, inner (a > b) ? b : a).

class CB3SoundESMGraphInputs;
struct CB3SoundESMInputLag;

struct CB3SoundESMInputLag {
    float field_0;
    float field_4;
    unsigned char pad_8[0x8];
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
};

class CB3SoundESMGraphInputs {
public:
    void ApplyLag(const CB3SoundESMGraphInputs& p0, const CB3SoundESMInputLag* p1);

    float field_0;
    unsigned char pad_4[0x4];
    float field_8;
    float field_C;
    float field_10;
    float field_14;
};
// [G] inlined clamp helpers (placeholder names; the real GtMath/Criterion names are unknown).
static inline float func_002FAFB0_inl1(float a, float b) { return (a > b) ? b : a; }
static inline float func_002FAFB0_inl2(float a, float lo, float hi) { return (a < lo) ? lo : func_002FAFB0_inl1(a, hi); }

// 0x002FAFB0
void CB3SoundESMGraphInputs::ApplyLag(const CB3SoundESMGraphInputs& p0, const CB3SoundESMInputLag* p1)
{
    field_0 = p0.field_0 + func_002FAFB0_inl2(field_0 - p0.field_0, p1->field_0, p1->field_4);
    field_8 = p0.field_8 + func_002FAFB0_inl2(field_8 - p0.field_8, p1->field_10, p1->field_14);
    field_C = p0.field_C + func_002FAFB0_inl2(field_C - p0.field_C, p1->field_18, p1->field_1C);
    field_10 = p0.field_10 + func_002FAFB0_inl2(field_10 - p0.field_10, p1->field_20, p1->field_24);
    field_14 = p0.field_14 + func_002FAFB0_inl2(field_14 - p0.field_14, p1->field_28, p1->field_2C);
}
