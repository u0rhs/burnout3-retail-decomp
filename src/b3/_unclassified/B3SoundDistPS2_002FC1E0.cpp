// CB3SoundDistortion::CalculateGainPair(float,float,bool,float*,float*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a146: bool flags plain tests, temps for cosf products).

class CB3SoundDistortion {
public:
    void CalculateGainPair(float a, float b, bool c, float *outL, float *outR);
    unsigned char pad_0[0x184D];
    unsigned char field_184D;
    unsigned char field_184E;
    unsigned char pad_184F[0x9D];
    float field_18EC;
};
extern "C" float cosf(float);
extern float D_004E0F74;

// 0x002FC1E0
void CB3SoundDistortion::CalculateGainPair(float a, float b, bool c, float *outL, float *outR)
{
    if (c) {
        bool s1 = false;
        bool s0 = false;
        bool s5 = false;
        float x1 = 90.0f * (0.5f + a / 2.0f);
        float x2 = 90.0f * (0.5f + b / 2.0f);
        float c1, c2;
        if (b <= 0.0f) {
            float t = D_004E0F74 * x2;
            float p = cosf(t);
            { float q = cosf(D_004E0F74 * x1); c1 = q * p; }
            float t2 = cosf(t);
            { float q = cosf(D_004E0F74 * (90.0f - x1)); c2 = q * t2; }
        } else {
            float t = D_004E0F74 * (90.0f - x2);
            float p = cosf(t);
            { float q = cosf(D_004E0F74 * x1); c1 = q * p; }
            float t2 = cosf(t);
            { float q = cosf(D_004E0F74 * (90.0f - x1)); c2 = q * t2; }
        }
        unsigned char u = field_184D;
        if (u != 0 || field_184E != 0) s1 = true;
        if (field_18EC <= 0.0f) {
            if (b > 0.0f) {
                s0 = true;
            } else {
                if (s1) s5 = true;
            }
        } else {
            if (b > 0.0f) {
                if (!s1) s0 = true;
            } else {
                s5 = true;
            }
        }
        if (s0) {
            if (c1 < c2) {
                if (field_184E != 0) field_184D = 0; else field_184D = 1;
            } else {
                if (u != 0) field_184E = 0; else field_184E = 1;
            }
        } else if (s5) {
            if (c1 < c2) {
                if (field_184E != 0) field_184D = 1; else field_184D = 0;
            } else {
                if (u != 0) field_184E = 1; else field_184E = 0;
            }
        }
        if (field_184D != 0) c1 = c1 * -1.0f;
        if (field_184E != 0) c2 = c2 * -1.0f;
        *outL = c1;
        *outR = c2;
        field_18EC = b;
    } else {
        if (a > 0.0f) {
            *outR = 0.75f * (1.0f - a);
            *outL = 0.0f + 0.75f + 0.25f * a;
        } else {
            float t = 0.0f + 0.75f - 0.25f * a;
            *outR = t;
            *outL = 0.75f * (1.0f + a);
        }
    }
}
