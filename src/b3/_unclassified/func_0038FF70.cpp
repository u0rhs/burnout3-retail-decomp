// func_0038FF70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/CGtNetworkPlayerManager.h"
#include "b3/classes/UnkStruct_D_0064EA7C.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_0038FF70_1;
struct UnkStruct_0038FF70_2;
struct UnkStruct_0038FF70_e0;
struct UnkStruct_func_003902C0;

struct UnkStruct_0038FF70_1 {
    unsigned char pad_0[0x1C];
    float field_1C;
};

struct UnkStruct_0038FF70_e0 {
    unsigned char pad_0[0x4];
    float field_4;
    int field_8;
};

struct UnkStruct_0038FF70_2 {
    UnkStruct_0038FF70_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_C[0x54];
};

struct UnkStruct_func_003902C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_0064EA7C D_0064EA7C;
extern CGtNetworkPlayerManager D_01E32AE0;
extern UnkStruct_func_003902C0 func_003902C0;
extern "C" UnkStruct_0038FF70_1 * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetPlayerRecordByID(int)
extern "C" void * func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" void qsort(UnkStruct_0038FF70_2 *, int, int, void *);

// 0x0038FF70
extern "C" int func_0038FF70(void *n0_, int p0, float f0)
{
    int n0 = (int)n0_;
    UnkStruct_0038FF70_2 local;  // [G] the frame's one local (size: up to the frame top)
    int m0 = 0;
    for (int i = 0; (i < D_01E32B08.field_0); i++) {
        void * r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 != 0) {
            int r1 = func_0022FBB0(r0);
            UnkStruct_0038FF70_1 * r2 = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, r1);
            if (r2 != 0) {
                local.field_0[m0].field_4 = r2->field_1C;
                int r3 = func_0022FBB0(r0);
                local.field_0[m0].field_8 = r3;
                m0 = (m0 + 1);
            }
        }
    }
    local.field_0[m0].field_4 = D_0064EA7C.field_0;
    int r4 = D_01E32AE0.GetMyPlayerID();
    local.field_0[m0].field_8 = r4;
    qsort(&local, (m0 + 1), 12, &func_003902C0);
    for (int i1 = 0; (i1 < (m0 + 1)); i1++) {
        if (f0 == local.field_0[i1].field_4) {
            if (p0 != local.field_0[i1].field_8) {
                continue;
            }
            return i1;
        }
    }
    return 7;
}
