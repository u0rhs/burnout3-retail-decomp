// func_0045A050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3D390.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

struct UnkStruct_0045A050_1;
struct UnkStruct_func_00459640;

struct UnkStruct_0045A050_1 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_func_00459640 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_00459640 func_00459640;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0045A9F0(void *);
extern "C" int BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0035FBC0(void *, void *);

// 0x0045A050
// n0 is a pointer [G]: `n0 + 4` as an int add scheduled differently
extern "C" void func_0045A050(char * n0)
{
    int r0 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
    int r = func_0032B2C0(&D_01E898E8, 0, ((r0 != 0) ^ 1));
    if (r == 4) {
        D_01E7A800.FESelect();
        if (BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, n0 + 4, &func_00459640, n0) == 0) {
            func_0035FBC0(&D_01E3D390, n0 + 4);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 0, 55, 15, 0);
        } else {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 57, 0, 0);
        }
    } else if (r == 0) {
        D_01E7A800.FESelect();
        func_0045A9F0(n0);
    } else if (r == 5) {
        func_0045A9F0(n0);
        D_01E7A800.FEBack();
    }
}
