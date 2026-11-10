// func_0033A2E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C5A40.h"

struct UnkStruct_0033A2E0_a1;
struct UnkStruct_0033A2E0_a2;

struct UnkStruct_0033A2E0_a1 {
    unsigned char pad_0[0xC];
    CGtLobbyPS2DirtySock * field_C;
};

struct UnkStruct_0033A2E0_a2 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char pad_111[0x1];
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x7];
    unsigned char field_11F;
};

extern UnkStruct_D_004C5A40 D_004C5A40;
extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::DefaultCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void LobbyApiRequestCB(int, int, void *, void *, UnkStruct_0033A2E0_a2 *);

// 0x0033A2E0
extern "C" void func_0033A2E0(int n0, UnkStruct_0033A2E0_a1 * p0, UnkStruct_0033A2E0_a2 * p1)
{
    CGtLobbyPS2DirtySock * t0 = p0->field_C;
    if (t0 == 0) {
        LobbyApiRequestCB(p1->field_104, 0x73656C65, &D_004C5A40, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, p1);
        p1->field_11F = 1;
    } else {
        int r1 = t0->ConvertDirtySockError((int)p0);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r1;
        p1->field_11F = 0;
    }
}
