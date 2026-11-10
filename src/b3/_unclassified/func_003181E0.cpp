// func_003181E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E3D595.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_003181E0;
struct UnkStruct_003181E0_e0;

struct UnkStruct_003181E0_e0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
};

struct UnkStruct_003181E0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
    int field_10;
    unsigned short field_14;
    unsigned char pad_16[0x2];
    UnkStruct_003181E0_e0 field_18[1];  // [G] element count unknown
};

extern UnkStruct_D_01E3D595 D_01E3D595;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" bool func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x003181E0
extern "C" int func_003181E0(UnkStruct_003181E0 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        unsigned short t0 = self->field_14;
        if (self->field_18[t0].field_4 != 0) {
            if (t0 == 3) {
                func_0032D080(&D_01E898E8, 2, 105, 15, 0);
                self->field_10 = 2;
            }
        } else {
            self->field_4 = t0;
            if (self->field_4 == 3 && D_01E3D595.field_0 == 0) {
                D_01E3D595.field_0 = 1;
                self->field_10 = 0;
                func_0032D080(&D_01E898E8, 2, 3997, 15, 0);
                return 1;
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        }
        return 1;
    }
    if (D_004F50C0.GetMenuUp(0) == 0 || func_00319360((char *)self + 0x14) == 0) {
        if (D_004F50C0.GetMenuDown(0) == 0) {
            return 1;
        }
        func_00319330((char *)self + 0x14);
    }
    return 1;
}
