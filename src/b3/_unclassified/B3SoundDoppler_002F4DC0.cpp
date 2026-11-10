// CB3SoundDoppler::CalculateVolume(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDoppler.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (compound-assignment arithmetic (a*=f20; b*=1-r; c*=r; a*=r; return a+(b+c)) and p0/=t0; v1=1; v1-=p0 (else moves to end)).

// lifter variant 0
// CB3SoundDoppler::CalculateVolume(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDoppler.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundDoppler;

class CB3SoundDoppler {
public:
    float CalculateVolume(float p0, float p1);

    unsigned char pad_0[0x8];
    float field_8;
    float field_C;
    float field_10;
    unsigned char pad_14[0x4];
    float field_18;
    float field_1C;
    float field_20;
    int field_24;
    int field_28;
};

// 0x002F4DC0
float CB3SoundDoppler::CalculateVolume(float p0, float p1)
{
    float t0 = field_C;
    float v1;
    if (p0 <= t0) {
        p0 /= t0;
        v1 = 1.0f;
        v1 -= p0;
    } else {
        v1 = 0.0f;
    }
    int t1 = field_24;
    float m0 = v1;
    for (int i = 0; (i < t1); i++) {
        m0 = (m0 * m0);
    }
    int t2 = field_28;
    float m1 = v1;
    for (int i1 = 0; (i1 < t2); i1++) {
        m1 = (m1 * m1);
    }
    float a = m1 * field_8;
    float b = v1 * field_18;
    float c = m0 * field_1C;
    a *= field_20;
    float r = p1 / field_10;
    b *= 1.0f - r;
    c *= r;
    a *= r;
    return a + (b + c);
}
