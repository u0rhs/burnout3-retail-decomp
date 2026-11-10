// func_003A2100 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E33A8C.h"
#include "b3/classes/UnkStruct_D_01E900B0.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90430.h"
#include "b3/classes/UnkStruct_D_01E9583C.h"

extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_D_01E33A8C D_01E33A8C;
extern UnkStruct_D_01E9583C D_01E9583C;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" int func_0041E8A0(void *);
extern "C" void func_0041E9A0(void *);
extern "C" int func_0041E8B0(void *);
extern "C" int func_00321780(void *);

// 0x003A2100
extern "C" void func_003A2100(int n0, int p0)
{
    switch (p0) {
    case 3:
        if (func_0041E8A0(&D_01E33A8C) || func_0041E8B0(&D_01E33A8C)) {
            func_0041E9A0(&D_01E33A8C);
        }
        func_00321780(&D_01E9583C);
        break;
    case 5:
        break;
    case 2:
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        D_01E900B0.field_0 = 1;
        break;
    }
}
