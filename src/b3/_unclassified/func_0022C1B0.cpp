// func_0022C1B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ControllerMapping.h"
#include "b3/classes/CB3InputManager.h"
#include "b3/classes/UnkStruct_D_00665E53.h"
#include "b3/classes/UnkStruct_D_01E90430.h"

struct UnkStruct_0022C1B0;
struct UnkStruct_0022C1B0_6;
struct UnkStruct_0022C1B0_8;

struct UnkStruct_0022C1B0_6 {
    UnkStruct_0022C1B0_8 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

struct UnkStruct_0022C1B0_8 {
    unsigned char pad_0[0x8];
    int field_8;
};

struct UnkStruct_0022C1B0 {
    unsigned char pad_0[0xFA1];
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x3];
    unsigned char field_FA5[1];  // [G] element count unknown
    unsigned char pad_FA6[0x1A];
    float field_FC0[1];  // [G] element count unknown
    unsigned char pad_FC4[0x1C];
    unsigned char field_FE0;
};

extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_01E90430 D_01E90430;
extern "C" void GetAvailableControllers__15CB3InputManagerFPP20CB3ControllerMappingSc(void *, void *, signed char);  // CB3InputManager::GetAvailableControllers(CB3ControllerMapping**,signed char)
extern "C" int func_0012EF20(UnkStruct_0022C1B0_8 *);
extern "C" void func_00442AE0(void *, float, float);

// 0x0022C1B0
extern "C" void func_0022C1B0(UnkStruct_0022C1B0 * self, signed char p0, int p1, float f0, float f1)
{
    UnkStruct_0022C1B0_6 local;  // [G] the frame's one local (size: up to the frame top)
    if (self->field_FE0 != 0) {
        return;
    }
    if (D_00665E53.field_0 != 0) {
        return;
    }
    if (D_01E90430.field_0 != 0) {
        return;
    }
    if (self->field_FA5[self->field_FA1[((signed char)p0)]] == 0) {
        return;
    }
    if ((p1 & 1) != 0) {
        if (!(f0 <= self->field_FC0[((signed char)p0)])) {
            self->field_FC0[((signed char)p0)] = f0;
        }
    }
    if ((p1 & 2) != 0) {
        GetAvailableControllers__15CB3InputManagerFPP20CB3ControllerMappingSc(self, (CB3ControllerMapping**)&local, p0);
        for (signed char i = 0; (i < 2); i++) {
            UnkStruct_0022C1B0_8 * t0 = local.field_0[i];
            if (t0 != 0) {
                int r1 = func_0012EF20(t0);
                if (r1 != 0) {
                    func_00442AE0((void *)(local.field_0[i]->field_8), f0, f1);
                }
            }
        }
    }
}
