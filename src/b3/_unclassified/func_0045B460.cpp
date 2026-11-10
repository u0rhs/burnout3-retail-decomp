// func_0045B460 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGtV2d math: size.Set per branch, pos from a static inline helper holding a named off = s * m then return a - off (helper locals allocated after the caller's, giving retail's slot order)).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dObject;

struct UnkStruct_D_01E90350 {
    CGtV4d field_0;
};

struct UnkStruct_func_0045B510 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045B460 {
    unsigned char pad_0[0x20];
    int field_20;
};

extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_0045B510 func_0045B510;

extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)
#define CGt2dObject_Prepare Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi

static inline CGtV2d func_0045B460_inl(const CGtV2d & a, const CGtV2d & s, const CGtV2d & m) { CGtV2d off = s * m; return a - off; }  // [G] helper, name unknown

// 0x0045B460
extern "C" void func_0045B460(UnkStruct_0045B460 * self, const CGtV2d & p0, const CGtV2d & p1, int p2, float f0)
{
    CGtV2d size;
    if (p2 & 4) size.Set(f0, 64.0f);
    else size.Set(f0, 32.0f);
    self->field_20 = p2;
    CGtV2d pos = func_0045B460_inl(p0, size, p1);
    CGt2dObject_Prepare(self, pos, size, D_01E90350.field_0, &func_0045B510, 64, 4);
}
