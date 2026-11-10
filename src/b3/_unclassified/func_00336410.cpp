// func_00336410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C5920.h"
#include "b3/classes/UnkStruct_D_004C5928.h"
#include "b3/classes/UnkStruct_D_004C5930.h"
#include "b3/classes/UnkStruct_D_004C5938.h"
#include "b3/classes/UnkStruct_D_004C5940.h"
#include "b3/classes/UnkStruct_D_004C5948.h"
#include "b3/classes/UnkStruct_D_004C5950.h"
#include "b3/classes/UnkStruct_D_01EA32B0.h"
#include "b3/classes/UnkStruct_D_01EA33D4.h"
#include "b3/classes/UnkStruct_D_01EA33D8.h"
#include "b3/classes/UnkStruct_D_01EA346C.h"

struct UnkStruct_00336410;
struct UnkStruct_00336410_3;
struct UnkStruct_00336410_a2;

struct UnkStruct_00336410_a2 {
    unsigned char field_0;
};

struct UnkStruct_00336410_3 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_00336410 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
};

extern UnkStruct_D_01EA33D4 D_01EA33D4;
extern UnkStruct_D_01EA346C D_01EA346C;
extern UnkStruct_D_004C5920 D_004C5920;
extern UnkStruct_D_004C5928 D_004C5928;
extern UnkStruct_D_004C5930 D_004C5930;
extern UnkStruct_D_01EA33D8 D_01EA33D8;
extern UnkStruct_D_004C5938 D_004C5938;
extern UnkStruct_D_004C5940 D_004C5940;
extern UnkStruct_D_01EA32B0 D_01EA32B0;
extern UnkStruct_D_004C5948 D_004C5948;
extern UnkStruct_D_004C5950 D_004C5950;
extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::DefaultCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetEpoch(UnkStruct_00336410_a2 *, int, void *, int);
extern "C" void TagFieldSetString(UnkStruct_00336410_a2 *, int, void *, void *);
extern "C" void TagFieldSetNumber(UnkStruct_00336410_a2 *, int, void *, int);
extern "C" void sprintf(UnkStruct_00336410_3 *, void *, int);
extern "C" void strncat(UnkStruct_00336410_a2 *, int, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_00336410_a2 *, void *, UnkStruct_00336410 *);

// 0x00336410
extern "C" void func_00336410(UnkStruct_00336410 * self, int p0, UnkStruct_00336410_a2 * p1, int p2)
{
    UnkStruct_00336410_3 local;  // [G] the frame's one local (size: up to the frame top)
    p1->field_0 = 0;
    TagFieldSetEpoch(p1, p2, &D_004C5920, D_01EA33D4.field_0);
    TagFieldSetString(p1, p2, &D_004C5928, ((char *)self + 0x4A4));
    TagFieldSetString(p1, p2, &D_004C5930, &D_01EA33D8);
    TagFieldSetNumber(p1, p2, &D_004C5938, 0);
    for (int i = 0; (i < D_01EA346C.field_0); i++) {
        sprintf(&local, &D_004C5940, i);
        TagFieldSetString(p1, p2, &local, ((char *)&D_01EA32B0.field_0[i] + 0x1C4));
        sprintf(&local, &D_004C5948, i);
        TagFieldSetNumber(p1, p2, &local, i);
        sprintf(&local, &D_004C5950, i);
        TagFieldSetNumber(p1, p2, &local, 0);
    }
    strncat(p1, p0, p2);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    LobbyApiRequestCB(self->field_104, 0x72616E6B, p1, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
    self->vfunc_14();
}
