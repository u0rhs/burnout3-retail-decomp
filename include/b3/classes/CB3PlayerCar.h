// CB3PlayerCar -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PLAYERCAR_H
#define B3_CLASSES_CB3PLAYERCAR_H

#include "b3/GtMath.h"

#include "b3/classes/CB3CrashCombo.h"

class CB3PlayerCar;
struct UnkStruct_00150820_1;
struct UnkStruct_00150BE0_1;
struct UnkStruct_00150BE0_2;

struct UnkStruct_00150820_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual int vfunc_8(unsigned long, int);
};

struct UnkStruct_00150BE0_1 {
    UnkStruct_00150BE0_2 * field_0;
};

struct UnkStruct_00150BE0_2 {
    unsigned char pad_0[0x40];
    int field_40;
};

class CB3PlayerCar {
public:
    void Construct(int p0);
    int Prepare();
    int PrepareSound();

    unsigned char pad_0[0x1338];
    void * field_1338;
    unsigned char pad_133C[0x44C];
    UnkStruct_00150BE0_1 * field_1788;
    unsigned char pad_178C[0x188];
    int field_1914;
    UnkStruct_00150820_1 * field_1918;
    unsigned char pad_191C[0x44];
    unsigned long field_1960;
    unsigned char pad_1968[0x44];
    signed char field_19AC;
    unsigned char pad_19AD[0xAB7];
    unsigned char field_2464;
    unsigned char field_2465;
    unsigned char field_2466;
    unsigned char pad_2467[0x9];
    CB3CrashCombo field_2470;
    unsigned char pad_269C[0x124];
    int field_27C0;
    float field_27C4;
    unsigned char field_27C8;
    unsigned char field_27C9;
};

#endif
