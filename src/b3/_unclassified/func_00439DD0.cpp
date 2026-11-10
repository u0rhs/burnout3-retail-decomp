// func_00439DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"

extern UnkStruct_D_01E88A80 D_01E88A80;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)

// 0x00439DD0
extern "C" int func_00439DD0(void *n0_)
{
    int n0 = (int)n0_;
    Prepare__15CB3MenuPageBaseFb((void *)n0, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)3);
    return 1;
}
