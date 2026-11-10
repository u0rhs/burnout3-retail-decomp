// Prepare__15CB3DPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGtV2d size/pos with GtMathPs2 ops; s=&self->field_20 declared first; subtraction in a static inline (temp slot order)).

#include "b3/GtMathPs2.h"

struct UnkStruct_00380F10;
struct UnkStruct_00380F10_0;
struct UnkStruct_00380F10_a1;
struct UnkStruct_00380F10_a2;
struct UnkStruct_D_01E90350;
struct UnkStruct_func_00380A50;

struct UnkStruct_00380F10_0 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    unsigned long field_18;
    int field_20;
    int field_24;
};

struct UnkStruct_00380F10_a2 {
    float field_0;
    float field_4;
};

struct UnkStruct_00380F10_a1 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01E90350 {
    GtMathPs2::CGtV4d field_0;
};

struct UnkStruct_func_00380A50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00380F10_s20 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
};

struct UnkStruct_00380F10 {
    unsigned char pad_0[0x20];
    UnkStruct_00380F10_s20 field_20;
};

extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_00380A50 func_00380A50;

extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const void *, const void *, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)

// [G] placeholder inline: the subtraction sits in its own inline so its temp is allocated below the multiply temp (retail slot order).
static inline GtMathPs2::CGtV2d func_00380F10_inl1(const GtMathPs2::CGtV2d & a, const GtMathPs2::CGtV2d & b) { return a - b; }
// 0x00380F10
extern "C" void Prepare__15CB3DPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(UnkStruct_00380F10 * self, const GtMathPs2::CGtV2d & p0, const GtMathPs2::CGtV2d & p1, int p2)
{
    UnkStruct_00380F10_s20 * s = &self->field_20;
    GtMathPs2::CGtV2d size(32.0f, 32.0f);
    s->field_0 = 0;
    s->field_1 = 0;
    s->field_2 = 0;
    s->field_3 = 0;
    if (p2 & 1) s->field_0 = 1;
    if (p2 & 2) s->field_1 = 1;
    if (p2 & 4) s->field_2 = 1;
    if (p2 & 8) s->field_3 = 1;
    GtMathPs2::CGtV2d pos = func_00380F10_inl1(p0, size * p1);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, &pos, &size, D_01E90350.field_0, (const void *)&func_00380A50, 64, 4);
}
