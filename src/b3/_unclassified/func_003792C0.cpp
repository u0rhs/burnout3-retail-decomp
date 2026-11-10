// ShowSelectionBar__20CB3PageTextComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (scene = &D_01E90240.field_1A0 local; three GtMathPs2::CGtV2d locals (pos, zero, size declared in that order) filled with Set()).

// ShowSelectionBar__20CB3PageTextComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

class CGt2dFrame;

struct UnkStruct_003792C0;
struct UnkStruct_003792C0_4;
struct UnkStruct_D_01E903E0;
struct UnkStruct_kB3PageTextBorder;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_kB3PageTextBorder {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003792C0_4 {
    float field_0;
    unsigned char pad_4[0x4];
    float field_8;
};

struct UnkStruct_003792C0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x16];
    UnkStruct_003792C0_4 * field_20;
    int field_24;
    float field_28;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;  // = D_01E903E0 (N65)
};

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_kB3PageTextBorder kB3PageTextBorder;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUif(void *, const void *, const void *, const void *, unsigned int, float);  // CB3Panel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int,float)

// 0x003792C0
extern "C" void ShowSelectionBar__20CB3PageTextComponentFv(UnkStruct_003792C0 * self)
{
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    int root = scene->field_14;
    if (self->field_24 == 0) {
        self->field_24 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, (CGt2dFrame*)root);
    }
    float border = kB3PageTextBorder.field_0;
    GtMathPs2::CGtV2d pos;
    GtMathPs2::CGtV2d zero;
    GtMathPs2::CGtV2d size;
    size.Set(self->field_20->field_8 - border, 27.0f);
    zero.Set(0, 0);
    pos.Set(self->field_20->field_0 + 0.5f * border, self->field_28);
    Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUif((void *)self->field_24, &pos, &zero, &size, 32, 0.0f);
}
