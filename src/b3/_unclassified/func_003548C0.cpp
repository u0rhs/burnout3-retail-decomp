// func_003548C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (W() read into its own float local before the k product; racer=true as an out-of-line goto block (pass3a)).

// from build/vt\try_func_003548C0_best.cpp
// func_003548C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3Score;

class CB3Score;
struct UnkStruct_003548C0;
struct UnkStruct_003548C0_1;
struct UnkStruct_003548C0_3;
struct UnkStruct_003548C0_5;
struct UnkStruct_003548C0_7;
struct UnkStruct_003548C0_8;
struct UnkStruct_003548C0_9;
struct UnkStruct_003548C0_a1;
struct UnkStruct_D_004E0D6C;
struct UnkStruct_D_004EE040;

class CB3Score {
public:
    int IsAheadOfIgnoringLaps(CB3Score*);
    float GetTotalRaceDistFromStartPos();
};

struct UnkStruct_D_004E0D6C {
    float field_0;
};

struct UnkStruct_003548C0_1 {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    float field_10;
    unsigned char pad_14[0x8];
    float field_1C;
    unsigned char pad_20[0x20];
};

struct UnkStruct_003548C0_a1 {
    unsigned char pad_0[0x40];
    UnkStruct_003548C0_3 * field_40;
    unsigned char pad_44[0xC];
    float field_50;
    float field_54;
};

struct UnkStruct_003548C0_3 {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x150];
    unsigned char field_210;
    unsigned char pad_211[0x4];
    signed char field_215;
    unsigned char pad_216[0x11DE];
    UnkStruct_003548C0_9 * field_13F4;
};

struct UnkStruct_003548C0_5 {
    unsigned char pad_0[0x13F4];
    UnkStruct_003548C0_7 * field_13F4;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003548C0_7 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

struct UnkStruct_003548C0_8 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

struct UnkStruct_003548C0_9 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

struct UnkStruct_003548C0 {
    unsigned char pad_0[0x1000];
    UnkStruct_003548C0_5 * field_1000;
    unsigned char pad_1004[0x44];
    unsigned char field_1048;
};

extern UnkStruct_D_004E0D6C D_004E0D6C;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131E40(void *);


// 0x003548C0
extern "C" float func_003548C0(UnkStruct_003548C0 * self, UnkStruct_003548C0_a1 * p0)
{
    UnkStruct_003548C0_3 * car = p0->field_40;
    float k = 2.236936331f;
    float w = car->field_B0.W();
    float v = k * w;
    bool racer;
    switch (car->field_215) {
    case 4:
    case 3:
    case 2:
    case 1:
        goto rtrue;
    }
    racer = false;
rtest:
    if (racer && !(p0->field_50 <= 0.0f) && p0->field_54 < 1.0f) {
        v = v + 2.0f * (k * (float)car->field_B0.W());  // [C] retail FPU form, not a VU lane op: 0x354988 lwc1 / 0x35498C mul.s + 0x354990 madd.s (the cast keeps the port's PS2 float model)
    }
    if (p0->field_40 == (void *)self->field_1000) {
        v += 100.0f;
    } else {
    switch (p0->field_40->field_215) {
    case 1:
    case 2:
    case 3:
        if (func_00131E40(&D_004EE040) != 0) {
            v = 100.0f;
        } else {
            v = 0.0f;
            UnkStruct_003548C0_9 * other = p0->field_40->field_13F4;
            if (self->field_1000->field_13F4->field_10C0.IsAheadOfIgnoringLaps(&other->field_10C0)) {
                if (p0->field_40->field_210 == 0) {
                    float d = self->field_1000->field_13F4->field_10C0.GetTotalRaceDistFromStartPos() - other->field_10C0.GetTotalRaceDistFromStartPos();
                    if (d < 500.0f) {
                        self->field_1048 = 1;
                        float t = d / 500.0f;
                        v = v + (float)10000 * (2.0f * t - t * t);
                    }
                }
            }
        }
        break;
    case 4:
        v = 50.0f;
        break;
    case 7:
        v = 12.5f;
        break;
    }
    }
    return v;
rtrue:
    racer = true;
    goto rtest;
}
