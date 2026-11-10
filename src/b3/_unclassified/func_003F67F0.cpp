// AddFakeResults__23CB3OnlineEndOfRaceStateFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_003F67F0_1;
struct UnkStruct_003F67F0_2;

struct UnkStruct_003F67F0_1 {
    int field_0;
    unsigned char pad_4[0x10];
    unsigned char field_14;
    unsigned char pad_15[0x2B];
    int field_40;
    int field_44;
    unsigned char pad_48[0x4];
    unsigned char field_4C;
};

struct UnkStruct_003F67F0_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10();
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetPlayerRecordByID(int)
extern "C" UnkStruct_003F67F0_1 * GetEmptyPlayerRecord__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetEmptyPlayerRecord()
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" UnkStruct_003F67F0_2 * func_002366D0(void *, int);
extern "C" int func_0022FBB0(UnkStruct_003F67F0_2 *);

// 0x003F67F0
extern "C" void AddFakeResults__23CB3OnlineEndOfRaceStateFv(void *a0 /* passed by every caller, not read here */)
{
    int t0 = D_01E32B08.field_0;
    for (int i = 0; (i < t0); i++) {
        UnkStruct_003F67F0_2 * r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 != 0) {
            int r1 = func_0022FBB0(r0);
            int r2 = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, r1);
            if (r2 == 0) {
                UnkStruct_003F67F0_1 * r3 = GetEmptyPlayerRecord__17CB3NetworkManagerFv(&D_01E32AE0);
                int r4 = func_0022FBB0(r0);
                r3->field_0 = r4;
                int r5 = r0->vfunc_10();
                strncpy((char *)((char *)r3 + 0x4), (const char *)r5, 16);
                r3->field_4C = 1;
                r3->field_14 = 1;
                r3->field_40 = -1;
                r3->field_44 = -1;
            }
        }
    }
}
