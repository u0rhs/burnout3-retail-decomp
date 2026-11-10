// CGtLobbyPS2DirtySock::LostPassword(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C5850.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern "C" void LostAccountCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::LostAccountCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetString(UnkStruct_003362B0_1 *, int, void *, char*);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, void *, CGtLobbyPS2DirtySock *);

// 0x003389B0
void CGtLobbyPS2DirtySock::LostPassword(char* p0)
{
    if (field_104 == 0) return;
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, p0);
    field_110 = 1;
    field_111 = 0;
    field_112 = 0;
    field_120 = 0;
    field_114 = 0;
    LobbyApiRequestCB(field_104, 0x6C6F7374, D_004E2DAC.field_0, (void *)&LostAccountCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
}
