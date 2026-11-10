// func_003A6E80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (s321: archive + const p3/p4 pointers (prologue load schedule)).

// func_003A6E80 -- tiny-function batch (tools/tiny_batch.py, lifted). s321: p3/p4 taken as const pointers (loads hoist past the stores; near1 rule).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_003A6E80;
struct UnkStruct_003A6E80_6;
struct UnkStruct_003A6E80_a1;
struct UnkStruct_003A6E80_a2;
struct UnkStruct_003A6E80_a3;
struct UnkStruct_003A6E80_t0;
struct UnkStruct_003A6E80_t1;
struct UnkStruct_D_01E90240;
struct UnkStruct_func_003A6DE0;
struct UnkStruct_func_003A6E30;

struct UnkStruct_003A6E80_t0 {
    float field_0;
    float field_4;
};

struct UnkStruct_003A6E80_t1 {
    float field_0;
    float field_4;
};

struct UnkStruct_003A6E80_a3 {
    float field_0;
    float field_4;
};

struct UnkStruct_003A6E80_a2 {
    float field_0;
    float field_4;
};

struct UnkStruct_003A6E80_a1 {
    float field_0;
    float field_4;
};

struct UnkStruct_003A6E80_6 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned long field_28;
    float field_30;
    float field_34;
    unsigned long field_38;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0xF0];
    GtMathPs2::CGtV4d field_F0;
    unsigned char pad_100[0x10];
    GtMathPs2::CGtV4d field_110;
};

struct UnkStruct_func_003A6E30 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_003A6DE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A6E80 {
    unsigned char pad_0[0x20];
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
};

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_func_003A6E30 func_003A6E30;
union UnkUnion_003A6E80_v { unsigned long l; struct { float x, y; } f; };
extern UnkStruct_func_003A6DE0 func_003A6DE0;

extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const void *, const void *, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);

// 0x003A6E80
extern "C" void func_003A6E80(UnkStruct_003A6E80 * self, UnkStruct_003A6E80_a1 * p0, UnkStruct_003A6E80_a2 * p1, UnkStruct_003A6E80_a3 * p2, const UnkStruct_003A6E80_t0 * p3, const UnkStruct_003A6E80_t1 * p4, int p5, float f0, float f1)
{
    UnkUnion_003A6E80_v d0, b0, d1, b1, a0, c0, a1, c1;
    UnkStruct_D_01E90240 * const gd = &D_01E90240;
    float t0 = p3->field_0;
    float t1 = p3->field_4;
    float t2 = p4->field_0;
    self->field_30 = f0;
    self->field_34 = f1;
    float t3 = p4->field_4;
    self->field_20 = t0;
    self->field_24 = t1;
    self->field_28 = t2;
    self->field_2C = t3;
    switch (p5) {
    case 0:
        {
            a0.f.x = p2->field_0 * p1->field_0;
            a0.f.y = p2->field_4 * p1->field_4;
            b0.l = a0.l;
            c0.f.x = p0->field_0 - b0.f.x;
            c0.f.y = p0->field_4 - b0.f.y;
            d0.l = c0.l;
            Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, &d0, p2, gd->field_110, (const void *)&func_003A6E30, 64, 24);
        }
        break;
    case 1:
        {
            a1.f.x = p2->field_0 * p1->field_0;
            a1.f.y = p2->field_4 * p1->field_4;
            b1.l = a1.l;
            c1.f.x = p0->field_0 - b1.f.x;
            c1.f.y = p0->field_4 - b1.f.y;
            d1.l = c1.l;
            Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, &d1, p2, gd->field_F0, (const void *)&func_003A6DE0, 64, 24);
        }
        break;
    default:
        break;
    }
}
