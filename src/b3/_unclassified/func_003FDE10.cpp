// func_003FDE10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F50C0.h"
#include "b3/classes/UnkStruct_D_004F6061.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_003FDE10;

struct UnkStruct_003FDE10 {
    unsigned char pad_0[0x40];
    int field_40;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_01E89788 D_01E89788;
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" void func_003C1390(UnkStruct_003FDE10 *, void *);

// 0x003FDE10
extern "C" void func_003FDE10(UnkStruct_003FDE10 * self)
{
    if (D_01E90424.field_0 != 5) return;
    func_003C1390(self, ((char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48));
    UnkStruct_00154A30_4 * t0 = D_0051BA88.field_0;
    if (t0 == 0) return;
    UnkStruct_00154A30_5 * t1 = t0->field_1B4;
    if (t1 != 0) {
        int r1 = t1->vfunc_4C();
        if (self->field_40 != r1) {
            self->field_40 = r1;
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)self->field_40, 1, 0, 140.0f);
        }
    }
}
