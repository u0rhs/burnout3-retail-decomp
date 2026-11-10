// PrepareSound__13CB3NetworkCarFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3SoundRaceCarManager.h"
#include "b3/classes/EB3RaceCarType.h"

struct UnkStruct_00150090;
struct UnkStruct_00150090_1;

struct UnkStruct_00150090_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual int vfunc_8(unsigned long, int);
};

struct UnkStruct_00150090 {
    unsigned char pad_0[0x1918];
    UnkStruct_00150090_1 * field_1918;
    unsigned char pad_191C[0x44];
    unsigned long field_1960;
    unsigned char pad_1968[0x44];
    signed char field_19AC;
};

extern CB3SoundRaceCarManager D_01E77550;

// 0x00150090
extern "C" int PrepareSound__13CB3NetworkCarFv(UnkStruct_00150090 * self)
{
    if (self->field_1918 == 0) {
        int r0 = D_01E77550.RequestRaceCar((EB3RaceCarType)2);
        self->field_1918 = (UnkStruct_00150090_1 *)r0;
    }
    if (self->field_1918 == 0) {
        return 1;
    }
    int r1 = self->field_1918->vfunc_8(self->field_1960, self->field_19AC);
    return r1;
}
