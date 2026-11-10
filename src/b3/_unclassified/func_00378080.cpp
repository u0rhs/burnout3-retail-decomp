// func_00378080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedCrashStageList.h"
#include "b3/classes/CB3HardCodedTrackList.h"
#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"

struct UnkStruct_00378080;
struct UnkStruct_00378080_6;
struct UnkStruct_00378080_7;

struct UnkStruct_00378080_6 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_00378080_7 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00378080 {
    unsigned char pad_0[0xEE8];
    unsigned long field_EE8;
    unsigned char pad_EF0[0x14];
    signed char field_F04;
    unsigned char field_F05;
};

extern int D_004A4F70[];  // [G] element count unknown
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" int func_003369F0(void *, int, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x00378080
extern "C" void func_00378080(UnkStruct_00378080 * self)
{
    int v = 0;
    int r0 = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
    if (r0 == 0) {
        return;
    }
    switch (r0) {
    case 1:
        self->field_F05 = 5;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 2, 1262, 0, 0);
        break;
    case 2:
        if ((unsigned int)(self->field_F04 - 5) <= 1) {
            v = CB3HardCodedTrackList::FindTrack(self->field_EE8);
        } else if ((unsigned int)(self->field_F04 - 7) <= 1) {
            v = CB3HardCodedCrashStageList::FindCrashStage(self->field_EE8);
        }
        if (func_003369F0(&D_01E3CD44, 0, D_004A4F70[self->field_F04], v) == 1) {
            self->field_F05 = 5;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            func_0032D080(&D_01E898E8, 2, 1262, 0, 0);
        } else {
            self->field_F05 = 2;
        }
        break;
    }
}
