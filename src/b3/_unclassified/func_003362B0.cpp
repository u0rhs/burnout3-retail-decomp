// func_003362B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

struct UnkStruct_003362B0;

struct UnkStruct_003362B0 {
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

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::DefaultCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, void *, UnkStruct_003362B0 *);

// 0x003362B0
extern "C" void func_003362B0(UnkStruct_003362B0 * self)
{
    D_004E2DAC.field_0->field_0 = 0;
    LobbyApiRequestCB(self->field_104, 0x6D6F7665, D_004E2DAC.field_0, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    self->vfunc_14();
}
