// func_0022B8E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ControllerMapping.h"
#include "b3/classes/CB3InputManager.h"

struct UnkStruct_0022B8E0;
struct UnkStruct_0022B8E0_1;
struct UnkStruct_0022B8E0_4;

struct UnkStruct_0022B8E0_1 {
    UnkStruct_0022B8E0_4 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

struct UnkStruct_0022B8E0_4 {
    unsigned char pad_0[0x8];
    int field_8;
};

struct UnkStruct_0022B8E0 {
    unsigned char pad_0[0xFE0];
    unsigned char field_FE0;
    unsigned char field_FE1[1];  // [G] element count unknown
};

extern "C" void GetAvailableControllers__15CB3InputManagerFPP20CB3ControllerMappingSc(void *, void *, signed char);  // CB3InputManager::GetAvailableControllers(CB3ControllerMapping**,signed char)
extern "C" void SetPause__15CB3InputManagerFb(UnkStruct_0022B8E0 *, int);
extern "C" int func_0012EF20(UnkStruct_0022B8E0_4 *);
extern "C" void func_00442900(void *, float, float);
extern "C" void func_00213F00(UnkStruct_0022B8E0 *);

// 0x0022B8E0
extern "C" void func_0022B8E0(UnkStruct_0022B8E0 * self)
{
    UnkStruct_0022B8E0_1 local;  // [G] the frame's one local (size: up to the frame top)
    if (self->field_FE0 != 0) {
        SetPause__15CB3InputManagerFb(self, 0);
    }
    for (signed char i = 0; (i < 2); i++) {
        self->field_FE1[i] = 1;
        GetAvailableControllers__15CB3InputManagerFPP20CB3ControllerMappingSc(self, (CB3ControllerMapping**)&local, i);
        for (signed char i1 = 0; (i1 < 2); i1++) {
            UnkStruct_0022B8E0_4 * t0 = local.field_0[i1];
            if (t0 != 0) {
                int r2 = func_0012EF20(t0);
                if (r2 != 0) {
                    func_00442900((void *)(local.field_0[i1]->field_8), 0.0f, 1.0f);
                }
            }
        }
    }
    func_00213F00(self);
}
