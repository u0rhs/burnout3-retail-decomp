// CB3AICarPhysics::GetDrivingControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (slot: speed test via CGtV4d::W() (N152 copy + source slot); the race-state bool as one && expression).

#include "b3/GtMathPs2.h"
struct UnkStruct_GDC_P {
    unsigned char pad_0[0x133C];
    int field_133C;
    unsigned char pad_1340[0x388];
    int field_16C8;
    unsigned char pad_16CC[0xC0];
    int field_178C;
    unsigned char pad_1790[0x208];
    unsigned char field_1998;
};
struct UnkStruct_GDC_self {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    unsigned char pad_C0[0x12FC];
    float field_13BC;
    unsigned char pad_13C0[0x34];
    UnkStruct_GDC_P * field_13F4;
    unsigned char pad_13F8[8];
    float field_1400;
    unsigned char pad_1404[4];
    float field_1408;
    unsigned char pad_140C[8];
    float field_1414;
    unsigned char pad_1418[0x20];
    int field_1438;
    unsigned char pad_143C[0x116];
    unsigned char field_1552;
};
struct UnkStruct_D_004EE040_gdc { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040_gdc D_004EE040;
extern float D_004E0C18;
extern "C" int func_00131E40(void *);
extern "C" void func_001D1FD0(void *);
extern "C" void GetRacingDrivingControls__15CB3AICarPhysicsFv(void *);
extern "C" void GetPreRaceDrivingControls__15CB3AICarPhysicsFv(void *);
extern "C" void GetDrivingControls__17CB3RaceCarPhysicsFv(void *);

extern "C" void GetDrivingControls__15CB3AICarPhysicsFv(UnkStruct_GDC_self * self)
{
    self->field_1552 = 0;
    bool b = self->field_13F4->field_16C8 == 2 && func_00131E40(&D_004EE040) != 0;
    if (self->field_13F4->field_1998 != 0 && b == false) {
        if (self->field_13F4->field_133C == 0) {
            func_001D1FD0(self);
        } else if (self->field_13F4->field_178C == 1) {
            GetRacingDrivingControls__15CB3AICarPhysicsFv(self);
        } else {
            GetPreRaceDrivingControls__15CB3AICarPhysicsFv(self);
        }
        if (self->field_B0.W() < D_004E0C18) self->field_1408 = 0.0f;   // W(): the 16-byte copy + its source slot (N152)
        self->field_1438 = 0;
    } else {
        self->field_1414 = 0.0f;
        self->field_1400 = 0.0f;
        self->field_1408 = 0.0f;
    }
    if (self->field_13F4->field_133C != 0) {
        float x = self->field_1414 * self->field_13BC;
        self->field_1400 = x;
        if (!(x <= 1.0f)) self->field_1400 = 1.0f;
    }
    GetDrivingControls__17CB3RaceCarPhysicsFv(self);
}
