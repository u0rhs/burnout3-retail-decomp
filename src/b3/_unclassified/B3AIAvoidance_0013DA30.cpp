// CB3AIAvoidanceMap::GetChannelRisk(int,float*,float*,float*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (N182 pragma match (lead): archive source + scoped optimiser pragma).

#include "b3/GtMath.h"

// N182: retail compiled this function with `#pragma opt_pulloutconstants off` ([G] scoped to this function).
#pragma push
#pragma opt_pulloutconstants off

class CB3AIAvoidanceMap;

class CB3AIAvoidanceMap {
public:
    void GetChannelRisk(int p0, float* p1, float* p2, float* p3) const;

    unsigned char pad_0[0x40];
    signed char field_40[0x100];  // [G] element count from the next field
    unsigned char field_140[0x300];  // [G] element count from the next field
    unsigned char field_440;
    unsigned char field_441;
    unsigned char field_442;
    unsigned char pad_443[0x1];
    float field_444;
};

// [G] placeholder inline: a cell's safety, 8 minus its risk byte scaled by 8/255
static inline float func_0013DA30_inl1(const CB3AIAvoidanceMap * m, int i)
{
    return 8.0f - 0.03137255f * (int)m->field_140[i];
}

// 0x0013DA30
void CB3AIAvoidanceMap::GetChannelRisk(int p0, float* p1, float* p2, float* p3) const
{
    *p1 = 0.0f;
    *p2 = 0.0f;
    *p3 = 0.0f;
    if (0.0f == field_444) {
        return;
    }
    if (p0 < 128) {
        unsigned char n = field_440;
        if (n == 0) {
            *p1 = func_0013DA30_inl1(this, p0);
        } else {
            for (int i = 0; i < n; i++) {
                float v = func_0013DA30_inl1(this, p0 + i);
                if (field_40[p0 + i] == 7) {
                    v = 0.0f;
                }
                *p1 += v;
                *p3 = GtMath::Max(*p3, v);
            }
            *p1 /= n;
        }
        for (int i = field_442; i >= p0; i--) {
            float r = 0.03137255f * (int)field_140[i];
            if (r < 2.0f && field_40[p0 + i] != 7) {
                *p2 += 8.0f - r;
            }
        }
    } else {
        unsigned char n = field_440;
        if (n == 0) {
            *p1 = func_0013DA30_inl1(this, p0);
        } else {
            for (int i = 0; i < n; i++) {
                float v = func_0013DA30_inl1(this, p0 - i);
                if (field_40[p0 - i] == 7) {
                    v = 0.0f;
                }
                *p1 += v;
                *p3 = GtMath::Max(*p3, v);
            }
            *p1 /= n;
        }
        for (int i = field_441; i <= p0; i++) {
            float r = 0.03137255f * (int)field_140[i];
            if (r < 2.0f && field_40[p0 + i] != 7) {
                *p2 += 8.0f - r;
            }
        }
    }
}

#pragma pop
