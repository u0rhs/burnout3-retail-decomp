// func_00439110 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (psweep: scoped #pragma opt_arithtransformation off [G] (N182)).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off

class CGt2dFrame;

struct UnkStruct_00439110;
struct UnkStruct_00439110_0;
struct UnkStruct_00439110_2;
struct UnkStruct_00439110_4;
struct UnkStruct_00439110_6;
struct UnkStruct_00439110_e0;
struct UnkStruct_D_004D1C50;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_00518688;
struct UnkStruct_func_00439620;

struct UnkStruct_00439110_0 {
    int field_0;
    float field_4;
    float field_8;
    float field_C;
    int field_10;
    float field_14;
    float field_18;
    float field_1C;
    GtMathPs2::CGtV4d field_20;
    unsigned char pad_30[0x20];
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
};

struct UnkStruct_00439110_2 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
};

struct UnkStruct_D_00518688 {
    UnkStruct_00439110_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00439110_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00439110_e0 * field_C;
};

struct UnkStruct_00439110_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_00439110_6 {
    unsigned char pad_0[0x20];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
};

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00439620 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1C50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00439110 {
    unsigned char pad_0[0x14];
    UnkStruct_00439110_2 * field_14;
    unsigned char pad_18[0x1C];
    UnkStruct_00439110_6 * field_34;
    float field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_func_00439620 func_00439620;
extern UnkStruct_D_004D1C50 D_004D1C50;

extern "C" void Prepare__10CGt2dSceneFv(void *);  // CGt2dScene::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)
extern "C" int strcasecmp(const char *, const char *);
struct UnkStruct_00439110_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

static inline int func_00439110_inl1(const char * name)
{
    int i;
    UnkStruct_00439110_4 * t0 = D_00518688.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00439110_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return t2;
        }
    }
    return 0;
}

// N140 frame pad [G]: retail keeps two dead 16-byte slots (0x90/0xA0) above the colour argument copy
struct UnkStruct_00439110_pad { int x[8]; UnkStruct_00439110_pad() {} ~UnkStruct_00439110_pad() {} };
// 0x00439110
extern "C" int func_00439110(UnkStruct_00439110 * self)
{
    Prepare__10CGt2dSceneFv(self);
    UnkStruct_00439110_pad pad;
    GtMathPs2::CGtV4d grey(0.5f, 0.5f, 0.5f, 1.0f);
    self->field_14->field_10 = grey;
    self->field_34 = (UnkStruct_00439110_6 *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self, 0, (CGt2dFrame*)self->field_14);
    UnkStruct_00439110_6 * o = self->field_34;
    int *q = &o->field_20;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, GtMathPs2::CGtV2d(26.0f, 400.0f), GtMathPs2::CGtV2d(330.0f, 64.0f), GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), (const void *)&func_00439620, 64, 24);
    q[0] = func_00439110_inl1((const char *)&D_004D1C50);
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    q[4] = 0;
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
    self->field_38 = D_004F50A0.field_0;
    self->field_3C = 0;
    return 1;
}

#pragma pop
