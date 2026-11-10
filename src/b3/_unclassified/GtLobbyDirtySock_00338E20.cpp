// CGtLobbyPS2DirtySock::BroadcastLaunch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C5850.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

struct UnkStruct_func_00338E10;

struct UnkStruct_func_00338E10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_func_00338E10 func_00338E10;
extern "C" void TagFieldSetString(UnkStruct_003362B0_1 *, int, void *, void *);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, void *, CGtLobbyPS2DirtySock *);

// 0x00338E20
void CGtLobbyPS2DirtySock::BroadcastLaunch()
{
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, ((char *)this + 0x444));
    LobbyApiRequestCB(field_104, 0x67737461, D_004E2DAC.field_0, &func_00338E10, this);
}
