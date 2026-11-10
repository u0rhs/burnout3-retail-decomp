// func_0028CD10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3SoundRaceCar.h"
#include "b3/classes/CB3SoundTurboModel.h"
#include "b3/classes/UnkStruct_D_004E1BAC.h"

struct UnkStruct_0028CD10;

struct UnkStruct_0028CD10 {
    unsigned char pad_0[0xBE];
    unsigned char field_BE;
    unsigned char pad_BF[0x85];
    CB3SoundTurboModel field_144;
};

extern UnkStruct_D_004E1BAC D_004E1BAC;
extern "C" void Construct__15CB3SoundRaceCarFv(void *);  // CB3SoundRaceCar::Construct()

// 0x0028CD10
extern "C" void func_0028CD10(UnkStruct_0028CD10 * self)
{
    Construct__15CB3SoundRaceCarFv(self);
    self->field_144.Construct();
    self->field_BE = 1;
    if (D_004E1BAC.field_0 == -1) {
        D_004E1BAC.field_0 = 0;
    }
}
