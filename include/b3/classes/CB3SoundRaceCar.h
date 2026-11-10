// CB3SoundRaceCar -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDRACECAR_H
#define B3_CLASSES_CB3SOUNDRACECAR_H

#include "b3/GtMath.h"

#include "b3/classes/CB3SoundSkidModel.h"

class CB3SoundRaceCar;
struct UnkStruct_0028D7C0_1;
struct UnkStruct_0028DA00_1;

struct UnkStruct_0028D7C0_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

struct UnkStruct_0028DA00_1 {
    unsigned char pad_0[0x2C];
    unsigned char field_2C;
};

class CB3SoundRaceCar {
public:
    void Destruct();
    void Release();
    void Unregister();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    UnkStruct_0028D7C0_1 * field_4;
    CB3SoundSkidModel field_8;
    unsigned char pad_9[0x5F];
    UnkStruct_0028DA00_1 * field_68;
    unsigned char pad_6C[0x51];
    unsigned char field_BD;
    unsigned char pad_BE[0x1];
    unsigned char field_BF;
};

#endif
