// CB3GameData::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3CrashRamp.h"
#include "b3/classes/CB3GameData.h"
#include "b3/classes/CB3SplitTimeCheckpoint.h"
#include "b3/classes/CB3StartFinishLine.h"
#include "b3/classes/CB3StartPoint.h"
#include "b3/classes/UnkStruct_D_0064D344.h"
#include "b3/classes/UnkStruct_D_0064D348.h"
#include "b3/classes/UnkStruct_D_0064D34C.h"
#include "b3/classes/UnkStruct_D_0064D350.h"
#include "b3/classes/UnkStruct_D_0064D354.h"
#include "b3/classes/UnkStruct_D_0064D358.h"
#include "b3/classes/UnkStruct_D_0064D35C.h"
#include "b3/classes/UnkStruct_D_0064D360.h"
#include "b3/classes/UnkStruct_D_0064D364.h"
#include "b3/classes/UnkStruct_D_0064D368.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_0014EDD0_e1;
struct UnkStruct_0014EDD0_e2;
struct UnkStruct_0014EDD0_e3;

struct UnkStruct_0014EDD0_e1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_0014EDD0_e2 {
    unsigned char pad_0[0x8];
};

struct UnkStruct_0014EDD0_e3 {
    unsigned char pad_0[0x70];
};

extern UnkStruct_D_0064D344 D_0064D344;
extern UnkStruct_D_0064D354 D_0064D354;
extern UnkStruct_D_0064D348 D_0064D348;
extern UnkStruct_D_0064D34C D_0064D34C;
extern UnkStruct_D_0064D364 D_0064D364;
extern UnkStruct_D_0064D350 D_0064D350;
extern UnkStruct_D_0064D358 D_0064D358;
extern UnkStruct_D_0064D35C D_0064D35C;
extern UnkStruct_D_0064D368 D_0064D368;
extern UnkStruct_D_0064D360 D_0064D360;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void Release__13CB3StartPointFv(void *);  // CB3StartPoint::Release()
extern "C" void Release__18CB3StartFinishLineFv(void *);  // CB3StartFinishLine::Release()
extern "C" void Release__22CB3SplitTimeCheckpointFv(void *);  // CB3SplitTimeCheckpoint::Release()
extern "C" void Release__12CB3CrashRampFv(void *);  // CB3CrashRamp::Release()
extern "C" void Release__14CB3CrashPickupFv(void *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// 0x0014EDD0
void CB3GameData::Release()
{
    if (field_589 != 0) {
        if (field_58A != 0) {
            field_560 = 0;
            field_584 = 24;
            field_589 = 0;
            field_58A = 0;
            D_0064D344.field_0 = 0;
            D_0064D354.field_0 = 0;
            D_0064D348.field_0 = 0;
            D_0064D34C.field_0 = 0;
            D_0064D364.field_0 = 0;
            D_0064D350.field_0 = 0;
            D_0064D358.field_0 = 0;
            D_0064D35C.field_0 = 0;
            D_0064D368.field_0 = 0;
            D_0064D360.field_0 = 0;
            for (int i = 0; (i < 6); i++) {
                Release__13CB3StartPointFv(((char *)&field_0[i] + 0x370));
            }
            for (int i1 = 0; (i1 < 2); i1++) {
                Release__18CB3StartFinishLineFv(((char *)((char *)this + (i1 << 4)) + 0x388));
            }
            for (int i2 = 0; (i2 < 2); i2++) {
                Release__18CB3StartFinishLineFv(((char *)((char *)this + (i2 << 4)) + 0x3A8));
            }
            for (int i3 = 0; (i3 < 12); i3++) {
                Release__22CB3SplitTimeCheckpointFv(((char *)((char *)this + (i3 << 3)) + 0x3C8));
            }
            for (int i4 = 0; (i4 < 20); i4++) {
                Release__14CB3CrashPickupFv(((char *)this + (i4 << 4)));
            }
            for (int i5 = 0; (i5 < 5); i5++) {
                Release__12CB3CrashRampFv(((char *)((char *)this + (((i5 << 3) - i5) << 4)) + 0x140));
            }
            ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 9, 0);
        }
    }
}
