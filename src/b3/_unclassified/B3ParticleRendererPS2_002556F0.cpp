// CB3ParticleArray::CB3ParticleBank::Update(CB3ParticleArray*,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near20: natural loop (one p++), min(n,60) clamp as goto stub after the else body, target read before field_20 store, decrease arm re-reads field_24 via const pun).

struct UnkStruct_D_004E137C { float field_0; };
extern UnkStruct_D_004E137C D_004E137C;
class CB3ParticleArray {
public:
    class CB3ParticleBank {
    public:
        void Update(CB3ParticleArray *, float, float);
        void * field_0;
        unsigned char pad_4[0x10];
        int field_14;
        unsigned char pad_18[4];
        float * field_1C;
        float field_20;
        float field_24;
        unsigned int field_28;
    };
    unsigned char pad_0[0x140];
    float field_140;
    float field_144;
};
// 0x002556F0
void CB3ParticleArray::CB3ParticleBank::Update(CB3ParticleArray * arr, float t, float dt)
{
    if (field_0 == 0) return;
    unsigned int bit = 1;
    float * p;
    int alive = 0;
    unsigned int off = 0;
    float thr = t - field_24;
    field_28 = 0;
    p = field_1C;
    while (off < field_14) {
        if (!(*p <= thr)) {
            field_28 = field_28 | bit;
            unsigned int n = field_14 - off;
            if (n > 60) goto clamp;
        add:
            alive += n;
            goto next;
        clamp:
            n = 60;
            goto add;
        }
    next:
        p++;
        bit = bit + bit;
        off += 60;
    }
    float frac = (float)alive / (float)field_14;
    float target;
    if (frac < 0.25f) {
        target = *(const float *)&arr->field_144;
        field_20 = 1.0f;
    } else {
        float f3 = D_004E137C.field_0 * (frac - 0.25f);
        field_20 = 0.0f + 1.0f - 0.75f * f3;
        target = 0.0f + arr->field_140 + f3 * (arr->field_144 - arr->field_140);
    }
    if (field_24 > target) {
        float v = 0.0f + *(const float *)&field_24 - 0.5f * dt * (arr->field_144 - arr->field_140);
        field_24 = v;
        if (v < target) {
            field_24 = target;
        }
    } else {
        float v = 0.0f + field_24 + 0.5f * dt * (arr->field_144 - arr->field_140);
        field_24 = v;
        if (v > target) {
            field_24 = target;
        }
    }
}
