// ModifyEffect__23CB3StylisedText2dObjectFQ223CB3StylisedText2dObject19EStylisedTextEffect -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sub-struct at +0x20 via hoisted pointer; callback local left unset on the default path (t0 phantom param dropped)).

// ModifyEffect__23CB3StylisedText2dObjectFQ223CB3StylisedText2dObject19EStylisedTextEffect -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_003D0690;
struct UnkStruct_func_003CED40;
struct UnkStruct_func_003CF300;
struct UnkStruct_func_003CFE40;

struct UnkStruct_func_003CFE40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_003CF300 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_003CED40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003D0690_s20 {
    unsigned char pad_0[0xC];
    float field_C;
};

struct UnkStruct_003D0690 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
UnkStruct_003D0690_s20 field_20;
    unsigned char pad_30[0x1];
    unsigned char field_31;
};

extern UnkStruct_func_003CFE40 _RenderNormal__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern UnkStruct_func_003CF300 _RenderDistort__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern UnkStruct_func_003CED40 _RenderDisintegrate__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;

extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const void *, const void *, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)

// 0x003D0690
extern "C" void ModifyEffect__23CB3StylisedText2dObjectFQ223CB3StylisedText2dObject19EStylisedTextEffect(UnkStruct_003D0690 * self, void *p0_)
{
    int p0 = (int)p0_;
    UnkStruct_003D0690_s20 * s = &self->field_20;
    self->field_31 = p0;
    // pass1 [C] retail: an effect outside 0..3 tail-calls CGt2dObject::Prepare with t0 (the render callback, stored at
    // +0x3C) never written: the caller's t0 (UpdateWibbleAnimationOut's untouched entry t0). Not an argument; every
    // caller passes 0..3 [L]. Port: keep the previous callback or use _RenderNormal -- retail's value is undefined.
    void * v0;
    switch (p0) {
    case 0:
    case 1:
        s->field_C = 0.0f;
        v0 = &_RenderNormal__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
        break;
    case 2:
        s->field_C = 0.0f;
        v0 = &_RenderDistort__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
        break;
    case 3:
        s->field_C = 1.0f;
        v0 = &_RenderDisintegrate__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
        break;
    }
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, self, ((char *)self + 0x8), self->field_10, (const void *)v0, 64, 12);
}
