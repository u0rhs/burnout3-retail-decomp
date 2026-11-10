// CGtLobbyPS2DirtySock::LaunchComplete() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C5850.h"
#include "b3/classes/UnkStruct_D_004C5858.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5858 D_004C5858;
extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::DefaultCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetString(UnkStruct_003362B0_1 *, int, void *, void *);
extern "C" void TagFieldSetNumber(UnkStruct_003362B0_1 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, void *, CGtLobbyPS2DirtySock *);

// 0x00338D60
void CGtLobbyPS2DirtySock::LaunchComplete()
{
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, ((char *)this + 0x444));
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5858, (field_134->field_114 & 0xFFF7FFFF));
    LobbyApiRequestCB(field_104, 0x67736574, D_004E2DAC.field_0, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
}
