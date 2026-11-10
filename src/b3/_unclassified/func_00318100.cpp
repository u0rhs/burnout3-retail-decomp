// Update__18CB3ClassSelectPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_00318100;

struct UnkStruct_00318100 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_003181E0(UnkStruct_00318100 *);
extern "C" int func_0032B2C0(void *, int, int);

// 0x00318100
extern "C" void Update__18CB3ClassSelectPageFv(UnkStruct_00318100 * self)
{
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_10) {
    case 1:
        func_003181E0(self);
        break;
    case 0:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        }
        break;
    case 2:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        self->field_10 = 1;
        }
        break;
    }
}
