// func_00338190 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C5850.h"
#include "b3/classes/UnkStruct_D_004C5968.h"
#include "b3/classes/UnkStruct_D_004C59D8.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

struct UnkStruct_00338190;

struct UnkStruct_00338190 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x4C7];
    int field_5E8;
    int field_5EC;
    int field_5F0;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C59D8 D_004C59D8;
extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_D_004C5850 D_004C5850;
extern "C" void GetGameNewsCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::GetGameNewsCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" int LobbyApiInfoPtr(int, int);
extern "C" int TagFieldFind(int, void *);
extern "C" void TagFieldGetString(int, UnkStruct_003362B0_1 *, int, void *);
extern "C" void TagFieldSetNumber(UnkStruct_003362B0_1 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, void *, UnkStruct_00338190 *);

// 0x00338190
extern "C" void func_00338190(UnkStruct_00338190 * self, int p0, int p1, int p2)
{
    if (self->field_104 == 0) return;
    self->field_5EC = p1;
    self->field_5F0 = p2;
    self->field_5E8 = p0;
    int r0 = LobbyApiInfoPtr(self->field_104, 0x636F6E66);
    int r1 = TagFieldFind(r0, &D_004C59D8);
    TagFieldGetString(r1, D_004E2DAC.field_0, 1024, &D_004C5968);
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5850, self->field_5E8);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    LobbyApiRequestCB(self->field_104, 0x6E657773, D_004E2DAC.field_0, (void *)&GetGameNewsCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
}
