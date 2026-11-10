// CB3GameData::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3CrashPickup.h"
#include "b3/classes/CB3CrashRamp.h"
#include "b3/classes/CB3GameData.h"
#include "b3/classes/CB3SplitTimeCheckpoint.h"
#include "b3/classes/CB3StartFinishLine.h"
#include "b3/classes/CB3StartPoint.h"

struct UnkStruct_0014FF70_e1;
struct UnkStruct_0014FF70_e2;
struct UnkStruct_0014FF70_e3;

struct UnkStruct_0014FF70_e1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_0014FF70_e2 {
    unsigned char pad_0[0x8];
};

struct UnkStruct_0014FF70_e3 {
    unsigned char pad_0[0x70];
};

extern "C" void Construct__13CB3StartPointFv(void *);  // CB3StartPoint::Construct()
extern "C" void Construct__18CB3StartFinishLineFv(void *);  // CB3StartFinishLine::Construct()
extern "C" void Construct__22CB3SplitTimeCheckpointFv(void *);  // CB3SplitTimeCheckpoint::Construct()
extern "C" void Construct__14CB3CrashPickupFv(void *);  // CB3CrashPickup::Construct()
extern "C" void Construct__12CB3CrashRampFv(void *);  // CB3CrashRamp::Construct()

// 0x0014FF70
void CB3GameData::Construct()
{
    field_588 = 0;
    field_589 = 0;
    field_58A = 0;
    field_58B = 0;
    field_584 = 1;
    for (int i = 0; (i < 6); i++) {
        Construct__13CB3StartPointFv(((char *)&field_0[i] + 0x370));
    }
    for (int i1 = 0; (i1 < 2); i1++) {
        Construct__18CB3StartFinishLineFv(((char *)((char *)this + (i1 << 4)) + 0x388));
    }
    for (int i2 = 0; (i2 < 2); i2++) {
        Construct__18CB3StartFinishLineFv(((char *)((char *)this + (i2 << 4)) + 0x3A8));
    }
    for (int i3 = 0; (i3 < 12); i3++) {
        Construct__22CB3SplitTimeCheckpointFv(((char *)((char *)this + (i3 << 3)) + 0x3C8));
    }
    for (int i4 = 0; (i4 < 20); i4++) {
        Construct__14CB3CrashPickupFv(((char *)this + (i4 << 4)));
    }
    for (int i5 = 0; (i5 < 5); i5++) {
        Construct__12CB3CrashRampFv(((char *)((char *)this + (((i5 << 3) - i5) << 4)) + 0x140));
    }
}
