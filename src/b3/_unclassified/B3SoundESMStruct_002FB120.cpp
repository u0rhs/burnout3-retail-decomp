// CB3SoundESMGraphInputs::Construct(const CB3RaceCar*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near18: lit4 literals, W() lane read, nested-ternary clamp, single field_8 store, s/=50;s+=1 temp, static inline rad/s->rpm helper (FP numbering)).

// from build/vt/try_Construct__22CB3SoundESMGraphInputsFPC10_best.cpp
// CB3SoundESMGraphInputs::Construct(const CB3RaceCar*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3RaceCar;

class CB3SoundESMGraphInputs;
struct CB3RaceCar;
struct UnkStruct_002FB120_4;
struct UnkStruct_002FB120_7;
struct UnkStruct_002FB120_e0;
struct UnkStruct_D_004E06DC;
struct UnkStruct_D_004E0790;
struct UnkStruct_D_004E0798;
struct UnkStruct_D_0055EFEC;

struct CB3RaceCar {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_D_004E0790 {
    float field_0;
};

struct UnkStruct_002FB120_e0 {
    UnkStruct_002FB120_4 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_002FB120_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_002FB120_4 {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x1340];
    float field_1400;
    unsigned char pad_1404[0x40];
    unsigned char field_1444;
    unsigned char pad_1445[0x57];
    float field_149C;
    unsigned char pad_14A0[0x4];
    int field_14A4;
    unsigned char pad_14A8[0x20];
    int field_14C8;
};

struct UnkStruct_D_004E06DC {
    float field_0;
};

struct UnkStruct_002FB120_7 {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    unsigned char pad_10[0x10];
};

struct UnkStruct_D_004E0798 {
    float field_0;
};

class CB3SoundESMGraphInputs {
public:
    void Construct(const CB3RaceCar* p0, float p1);

    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
};

extern UnkStruct_D_004E0790 D_004E0790;
extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_004E06DC D_004E06DC;
extern UnkStruct_D_004E0798 D_004E0798;

// [G] inlined rad/s -> rpm conversion (unnamed helper)
static inline float func_002FB120_inl1(const UnkStruct_002FB120_4 *e) { return 9.549296379f * e->field_149C; }
// 0x002FB120
void CB3SoundESMGraphInputs::Construct(const CB3RaceCar* p0, float p1)
{
    signed char t0 = p0->field_19AC;
    UnkStruct_002FB120_4 * t1 = D_0055EFEC.field_0[t0].field_0;
    float s = (float)t0;
    s /= 50.0f;
    s += 1.0f;
    field_0 = s * func_002FB120_inl1(t1);
    field_4 = ((float)t1->field_14C8);
    float v;
    if (t1->field_14A4 != 0) {
        v = 0.0f;
    } else {
        v = t1->field_1400;
        if (t1->field_1444 != 0) {
            v = v < 0.8f ? 0.8f : (v > 1.0f ? 1.0f : v);
        }
    }
    field_8 = v;
    field_C = v;
    field_10 = v;
    field_14 = 2.236936331f * (float)t1->field_B0.W();  // [C] retail FPU form, not a VU lane op: 0x2FB1F0 lwc1 / 0x2FB1F4 mul.s (the cast keeps the port's PS2 float model)
    field_18 = p1;
}
