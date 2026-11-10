// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_00434DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element-pointer locals in loop 1; loop 2 store order C,4,0 then obj stores via one load, obj reloaded into a local before local.field_8 store (delay-slot store); tail as one if-block).

// lifter variant 0
// func_00434DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00434DD0;
struct UnkStruct_00434DD0_13;
struct UnkStruct_00434DD0_4;
struct UnkStruct_00434DD0_e3;
struct UnkStruct_D_004D1A58;
struct UnkStruct_D_004D1A5C;
struct UnkStruct_D_004D1A80;
struct UnkStruct_D_004D1A88;
struct UnkStruct_D_004D1A8C;
struct UnkStruct_D_004D1AA0;
struct UnkStruct_D_004D1AA4;
struct UnkStruct_D_01E8EE68;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_004D1AA0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00434DD0_4 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004D1A58 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1AA4 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1A5C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1A80 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1A8C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1A88 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00434DD0_13 {
    unsigned char pad_0[0x8];
    float field_8;
    float field_C;
};

struct UnkStruct_D_01E8EE68 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x2C];
    UnkStruct_00434DD0_e3 * field_2C;
};

struct UnkStruct_00434DD0_e3 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_00434DD0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xA];
    UnkStruct_00434DD0_13 * field_14[1];  // [G] element count unknown
    unsigned char pad_18[0xC];
    float field_24[1];  // [G] element count unknown
    unsigned char pad_28[0x4];
    float field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0xC];
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
};

extern UnkStruct_D_004D1AA0 D_004D1AA0;
extern UnkStruct_D_004D1A58 D_004D1A58;
extern UnkStruct_D_004D1AA4 D_004D1AA4;
extern UnkStruct_D_004D1A5C D_004D1A5C;
extern UnkStruct_D_004D1A80 D_004D1A80;
extern UnkStruct_D_004D1A8C D_004D1A8C;
extern UnkStruct_D_004D1A88 D_004D1A88;
extern UnkStruct_D_01E8EE68 D_01E8EE68;
extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void SetUVs__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const void *, const void *);  // CGt2dObjectImage::SetUVs(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)

// 0x00434DD0
extern "C" void func_00434DD0(UnkStruct_00434DD0 * self, float f0)
{
    UnkStruct_D_01E903E0 * const g = &D_01E903E0;
    float step = 3.0f * f0;
    for (int i = 0; i < 2; i++) {
        float * cur = &self->field_24[i];
        float * tgt = &self->field_2C[i];
        if (!(*tgt <= *cur)) {
            *cur = *cur + step;
            if (!(*cur <= *tgt)) {
                *cur = *tgt;
            }
        } else if (*tgt < *cur) {
            *cur = *cur - step;
            if (*cur < 0.1f) {
                *cur = 0.1f;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        float t4 = D_004D1AA0.field_0;
        float t5 = self->field_24[i];
        float t6 = D_004D1A58.field_0;
        float t7 = D_004D1AA4.field_0;
        float t8 = D_004D1A5C.field_0;
        float t9 = D_004D1A80.field_0;
        float t10 = D_004D1A8C.field_0;
        float t11 = D_004D1A88.field_0;
        float q = 0.1f * (float)(int)(10.0f * (0.0001f + t5));
        float sx = q * (t4 * t6);
        float sy = t7 * t8;
        UnkStruct_00434DD0_4 local;
        local.field_C = sy;
        local.field_0 = t9 + q * (t11 - t9);
        local.field_4 = t10;
        UnkStruct_00434DD0_13 * o = self->field_14[i];
        o->field_8 = sx;
        o->field_C = sy;
        UnkStruct_00434DD0_13 * o2 = self->field_14[i];
        local.field_8 = sx;
        SetUVs__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(o2, &D_004D1A80, &local);
    }
    if (D_01E8EE68.field_0 == 0 && self->field_3C != self->field_3D) {
        bool b = !self->field_3C || self->field_3E;
        for (int i = 0; i < 3; i++) {
            g->field_2C[self->field_8 + i].field_0 = !b;
        }
        self->field_3D = self->field_3C;
    }
}
