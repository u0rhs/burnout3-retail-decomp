// CB3MenuInput::Update(float,CB3ControllerMapping*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuInput.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near6: single-store clamp for field_0 + const gaeMenubuttons (load hoists above store)).

// CB3MenuInput::Update(float, CB3ControllerMapping *) -- hand-matched (near6, from the a139 / mwperm archive).
// [C] name: the mangled symbol in retail's tables. Layout [G] from instruction widths; field names are placeholders.
// near6: field_0 clamped like field_4 (one store after the clamp join) and gaeMenubuttons declared const, so the
// gaeMenubuttons[2] load hoists above the field_0 store (sdra rule, N206 / a85: const tables).
struct UnkStruct_0021A5F0_btn { unsigned char pad_0[0xC]; };
struct UnkStruct_0021A5F0 {
    float field_0;
    float field_4;
    UnkStruct_0021A5F0_btn field_8[0x17];
};
extern const int gaeMenubuttons[];
extern "C" float func_0012FC30(void *, int, int);
extern "C" void Update__18CB3MenuInputButtonFffi(void *, float, float, int);

static inline float fa(float v) { if (v < 0.0f) return -v; return v; }
extern "C" void Update__12CB3MenuInputFfP20CB3ControllerMapping(UnkStruct_0021A5F0 * self, float p0, void * m)
{
    void * v4 = m;
    void * v2 = v4;
    void * v1 = v2;
    float t;
    bool t0;
    float t9;
    float t3;
    float v0 = p0;
    bool t6;
    float t2;
    float d;
    float v;
    float z;
    float x = func_0012FC30(m, 0x18, 0);
    float y;
    int t8;
    y = func_0012FC30(m, 0x19, 0);
    float ay;
    ay = !(y >= 0.0f) ? -y : y;
    const bool t4 = x >= 0.0f;
    t0 = (t4 ? x : -x) > ay;
    float k;
    if (t0) y = 0.0f;
    else x = 0.0f;
    {
        float a = func_0012FC30(m, gaeMenubuttons[1], 0);
        float b = func_0012FC30(m, gaeMenubuttons[0], 0);
        d = a - b;
    }
    if (x < -0.75f) {
        k = 0.75f;
        t = k + x; float t17 = t * 4.0f;
        t = t17;
        float t10 = 0.0f + d;
        d = t10 - t * t;
    } else {
        k = 0.75f;
        t6 = x > k;
        if (t6) {
            t = x - k; const float t7 = 4.0f * t;
            t = t7;
            float t15 = t * t;
            float t18 = 0.0f + d + t15;
            d = t18;
        }
    }
    if (d < -1.0f) d = -1.0f;
    else if (d > 1.0f) d = 1.0f;
    self->field_0 = d;
    {
        float a = func_0012FC30(m, gaeMenubuttons[2], 0);
        t8 = gaeMenubuttons[3];
        float b = func_0012FC30(v1, gaeMenubuttons[3], 0);
        d = a - b;
    }
    bool t14 = y < -0.75f;
    if (t14) {
        float t16 = k + y;
        t = (t16); t9 = 4.0f * t;
        t = t9;
        d = 0.0f + d - t * t;
    } else if (y > k) {
        t = y - k; float t19 = t * 4.0f;
        t = t19;
        d = 0.0f + d + t * t;
    }
    if (d < -1.0f) d = -1.0f;
    else if (d > 1.0f) d = 1.0f;
    self->field_4 = d;
    Update__18CB3MenuInputButtonFffi(&self->field_8[0], -self->field_0, p0, 1);
    Update__18CB3MenuInputButtonFffi(&self->field_8[1], self->field_0, p0, 1);
    float t5 = self->field_4;
    Update__18CB3MenuInputButtonFffi(&self->field_8[2], t5, v0, 1);
    t3 = self->field_4;
    t2 = t3;
    Update__18CB3MenuInputButtonFffi(&self->field_8[3], -self->field_4, p0, 1);
    int i = 4;
    do {
        v = func_0012FC30(m, gaeMenubuttons[i], 0);
        Update__18CB3MenuInputButtonFffi(&self->field_8[i], v, p0, i == 8);
        i++;
    } while (i < 0x17);
}
