// Hand-written; the lifter refused it (a86: CB3ImageReward2dObject::Prepare; sibling func_00427080 shape + GetTexture (GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei) switch inlined, if/else field_C stores).

// func_00427560 -- [L] DNAT: CB3ImageReward2dObject::Prepare(const CGtV2d&,const CGtV2d&,const CGtV2d&,CGtV4d,EB3RewardImageType,int,...) (research/proto/new_names.csv, high)
// Sibling of func_00427080 (same Prepare shape); the texture lookup here is the body of GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei inlined [G].
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_01EA4710 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00427560_1 {
    unsigned char pad_0[0x10];
};

// [G] the object's data block at +0x20 (CGt2dObject::mauDataBlock).
struct UnkStruct_00427560_20 {
    CGtV2d field_0;
    void * field_8;
    unsigned char field_C;
    unsigned char field_D;
    signed char field_E;
    unsigned char field_F;
    unsigned char field_10;
    unsigned char field_11;
};

struct UnkStruct_00427560 {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    UnkStruct_00427560_20 field_20;
};

extern UnkStruct_D_01EA4710 D_01EA4710;
extern void * D_01EA4470[];

extern "C" void func_004272A0(const void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, void (*)(const void *, const void *), unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)
extern "C" int func_003F5F10(int);

// [G] the body of GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei, inlined here.
static inline void * func_00427560_inl0(int type, int idx)
{
    int v;
    if (idx == -1) return D_01EA4710.field_0;
    switch (type) {
    case 0:
        v = idx + 0x15;
        break;
    case 1:
        v = idx + 0x25;
        break;
    case 2:
        v = func_003F5F10(idx);
        break;
    case 3:
        v = idx + 0x20;
        break;
    }
    return D_01EA4470[v];
}

// 0x00427560
extern "C" void func_00427560(UnkStruct_00427560 * self, const CGtV2d & p0, const CGtV2d & p1, const CGtV2d & p2, const CGtV4d p3, int p4, int p5, int p6)
{
    UnkStruct_00427560_20 & d = self->field_20;
    if (p4 == 1) {
        d.field_C = 15;
    } else {
        d.field_C = 0;
    }
    d.field_D = p4;
    d.field_E = p5;
    d.field_8 = func_00427560_inl0(p4, p5);
    d.field_11 = p6;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(
        self, p0 - p2 * p1, p2, p3, func_004272A0, 64, 24);
    d.field_0 = CGtV2d(1.0f, 1.0f) / self->field_8;
}
