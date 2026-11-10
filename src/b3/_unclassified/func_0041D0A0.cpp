// func_0041D0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_0041D0A0;
struct UnkStruct_0041D0A0_5;
struct UnkStruct_0041D0A0_6;

struct UnkStruct_0041D0A0_5 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_0041D0A0_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0041D0A0 {
    unsigned char pad_0[0xCC];
    int field_CC;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetErrorString(int)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_0041C900(UnkStruct_0041D0A0 *);
extern "C" int func_0032B2C0(void *, int, int);

// 0x0041D0A0
extern "C" void func_0041D0A0(UnkStruct_0041D0A0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_CC) {
    case 0:
        int r0 = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        if (r0 == 0) {
            break;
        }
        switch (r0) {
        case 1:
            self->field_CC = 2;
            int r1 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            int r3 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r1);
            func_0032D080(&D_01E898E8, 2, r3, 0, 0);
            break;
        case 2:
            self->field_CC = 1;
            func_0041C900(self);
            break;
        }
        break;
    case 1:
        int r6 = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        if (r6 == 0) {
            break;
        }
        switch (r6) {
        case 1:
            self->field_CC = 2;
            int r7 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            int r9 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r7);
            func_0032D080(&D_01E898E8, 2, r9, 0, 0);
            break;
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        }
        break;
    case 2:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        break;
    }
}
