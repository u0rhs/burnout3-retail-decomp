// func_00314CC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/CB3OnlineLobbyPage.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3D390.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

struct UnkStruct_00314CC0;
struct UnkStruct_00314CC0_1;

struct UnkStruct_00314CC0_1 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00314CC0 {
    unsigned char pad_0[0x50];
    unsigned char field_50[0x135C];  // [G] size
    unsigned char field_13AC;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" void _BanBuddyCallback__18CB3OnlineLobbyPageFbPv(bool, void*);  // CB3OnlineLobbyPage::_BanBuddyCallback(bool,void*), its address taken
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_00316640(UnkStruct_00314CC0 *);
extern "C" int BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, UnkStruct_00314CC0 *);
extern "C" int func_0035FBC0(void *, void *);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x00314CC0
extern "C" void func_00314CC0(UnkStruct_00314CC0 * self)
{
    int r1 = func_0032B2C0(&D_01E898E8, 0, (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) ^ 1);
    if (r1 == 4) {
        D_01E7A800.FESelect();
        if (BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_50, (void *)&_BanBuddyCallback__18CB3OnlineLobbyPageFbPv, self) == 0) {
            func_0035FBC0(&D_01E3D390, self->field_50);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 0, 55, 15, 0);
        } else {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 57, 0, 0);
        }
    } else if (r1 == 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        D_01E7A800.FESelect();
        func_00316640(self);
    } else if (r1 == 5) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        self->field_13AC = 3;
        D_01E7A800.FEBack();
    }
}
