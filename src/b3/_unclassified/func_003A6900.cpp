// Update__24CB3ReplaySymbolComponentFf -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (case 2/3/4 falls into default SetA; case 5 first; 1-arg func_00131CA0; const &D_01E90240; six CGtV2d-sized stack pairs in lifter store order).

// from build/vt\try_func_003A6900_best.cpp
// Update__24CB3ReplaySymbolComponentFf -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_003A6900;
struct UnkStruct_003A6900_5;
struct UnkStruct_003A6900_6;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90350;
struct UnkStruct_D_01E90420;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E90350 {
    u_long128 field_0;
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A6900_v2 {  // [G] GtMathPs2::CGtV2d-sized pair (the Prepare args), fields unnamed
    float field_0;
    float field_4;
};

struct UnkStruct_D_01E90420 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A6900_5 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003A6900_6 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x100];
    GtMathPs2::CGtV4d field_100;
};

struct UnkStruct_003A6900 {
    unsigned char pad_0[0xC];
    UnkStruct_003A6900_5 * field_C;
    UnkStruct_003A6900_6 * field_10;
    int field_14;
    int field_18;
};

extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const void *, const void *, const void *, GtMathPs2::CGtV4d);  // CGt2dObjectBox::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d)
extern "C" int func_00131CA0(void *);  // one arg, as in B3ReplaySymbolComponent_003A6840.cpp

// 0x003A6900
extern "C" void Update__24CB3ReplaySymbolComponentFf(UnkStruct_003A6900 * self)
{
    GtMathPs2::CGtV4d c;
    c.mData = D_01E90350.field_0;
    switch (D_01E90424.field_0) {
    case 5:
        break;
    case 2:
    case 3:
    case 4:
        {
            float t2 = D_01E90420.field_0;
            UnkStruct_D_01E90240 * const g = &D_01E90240;
            if (func_00131CA0(&D_004EE040) == 0) {
                UnkStruct_003A6900_v2 a0;
                UnkStruct_003A6900_v2 b0;
                UnkStruct_003A6900_v2 c0;
                UnkStruct_003A6900_v2 a1;
                UnkStruct_003A6900_v2 b1;
                UnkStruct_003A6900_v2 c1;
                b0.field_0 = 0;
                c0.field_0 = 640.0f;
                a0.field_0 = 0;
                c0.field_4 = 64.0f;
                a0.field_4 = 0;
                b0.field_4 = 1.0f - t2;
                Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d((void *)self->field_14, &a0, &b0, &c0, g->field_100);
                b1.field_0 = 0;
                c1.field_0 = 640.0f;
                b1.field_4 = t2;
                a1.field_0 = 0;
                c1.field_4 = 64.0f;
                a1.field_4 = 480.0f;
                Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d((void *)self->field_18, &a1, &b1, &c1, g->field_100);
            }
        }
    default:
        c.SetA(0.0f);
        break;
    }
    self->field_C->field_10 = c.mData;
    self->field_10->field_10 = c.mData;
}
