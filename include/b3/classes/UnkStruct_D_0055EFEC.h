// UnkStruct_D_0055EFEC -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_0055EFEC_H
#define B3_CLASSES_UNKSTRUCT_D_0055EFEC_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

struct UnkStruct_00150E20_3;
struct UnkStruct_00150E20_e0;
struct UnkStruct_0038C360_5;
struct UnkStruct_D_0055EFEC;
struct UnkStruct_00395A00_a1;

struct UnkStruct_00150E20_3 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(UnkStruct_00395A00_a1 *, signed char);
    unsigned char pad_4[0x15C];
    GtMathPs2::CGtV3d field_160;
    GtMathPs2::CGtV3d field_170;
    unsigned char pad_180[0x10];
    short field_190;
    unsigned char pad_192[0x2];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x68];
    int field_204;
    unsigned char pad_208[0xA];
    unsigned char field_212;
    unsigned char pad_213[0xAB1];
    UnkStruct_0038C360_5 * field_CC4;
    unsigned char pad_CC8[0x68B];
    unsigned char field_1353;
};

struct UnkStruct_00150E20_e0 {
    UnkStruct_00150E20_3 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_0038C360_5 {
    unsigned char pad_0[0x1015];
    unsigned char field_1015;
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_00150E20_e0 field_0[1];  // [G] element count unknown
};

#endif
