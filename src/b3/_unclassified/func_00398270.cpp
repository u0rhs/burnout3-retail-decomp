// Hand-written; the lifter refused it (a85: OpenLobbyPage::Update; inner switch cases written 2,1,0 gives retail's beqz-first test order).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_00398270 {
    unsigned char pad_0[0x45D];
    unsigned char field_45D;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3HUDSoundManager D_01E7A800;
extern "C" void func_00397FA0(UnkStruct_00398270 *);
extern "C" void UpdateChat__22CB3OnlineOpenLobbyPageFv(UnkStruct_00398270 *);
extern "C" void func_003978C0(UnkStruct_00398270 *);
extern "C" void func_00397520(UnkStruct_00398270 *);
extern "C" void func_003963E0(UnkStruct_00398270 *);
extern "C" void func_00396670(UnkStruct_00398270 *);
extern "C" void func_00396E50(UnkStruct_00398270 *);
extern "C" void func_00396A90(UnkStruct_00398270 *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

// 0x00398270
extern "C" void func_00398270(UnkStruct_00398270 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_45D) {
    case 0:
    case 9:
        func_00397FA0(self);
        break;
    case 1:
        UpdateChat__22CB3OnlineOpenLobbyPageFv(self);
        break;
    case 2:
        func_003978C0(self);
        break;
    case 3:
        func_00397520(self);
        break;
    case 4:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            if (D_01E8954E.field_0 != 0) {
                ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
            }
            func_00396E50(self);
        }
        break;
    case 5:
        func_003963E0(self);
        break;
    case 6:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_00396A90(self);
            D_01E7A800.FESelect();
        }
        break;
    case 7:
        func_00396670(self);
        break;
    case 8: {
        int r0 = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (r0) {
        case 2:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        case 1:
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        case 0:
            break;
        default:
            break;
        }
        break;
    }
    }
}
