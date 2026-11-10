// CB3SoundDoppler::Update(float,float,float,float,float*,float*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDoppler.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (abs.s asm helper fabsf; Calculate* called as members; f13 passes p1 through).

static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
class CB3SoundDoppler {
public:
    void Update(float, float, float, float, float *, float *);
    float CalculatePitch(float, float);
    float CalculateVolume(float, float);
    unsigned char pad_0[8];
    float field_8;
};
// 0x002F4EA0
void CB3SoundDoppler::Update(float p0, float p1, float p2, float p3, float *pitch, float *vol)
{
    field_8 = p3;
    *pitch = CalculatePitch(p0, p1);
    *vol = CalculateVolume(fabsf(p0), fabsf(p2));
}
