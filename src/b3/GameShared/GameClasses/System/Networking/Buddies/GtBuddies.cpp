// GtBuddies.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtBuddies.cpp.
// Area: src/b3/GameShared/GameClasses/System/Networking/Buddies, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/Buddies/GtBuddies.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtBuddies.h"
#include "b3/classes/UnkStruct_D_004C7210.h"

extern UnkStruct_D_004C7210 D_004C7210;
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" char * strcpy(char *, const char *);

// CGtBuddies::SetPresenceDetail(char*,char*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddies.cpp.
// 0x0035F0A0
void CGtBuddies::SetPresenceDetail(char* p0, char* p1, char* p2)
{
    strncpy((char *)this, (const char *)p0, 100);
    strncpy((char *)((char *)this + 0x64), (const char *)p1, 100);
    strncpy((char *)((char *)this + 0xC8), (const char *)p2, 3);
}

// CGtBuddies::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddies.cpp.
// 0x0035F100
int CGtBuddies::Prepare()
{
    strcpy((char *)this, (const char *)&D_004C7210);
    strcpy((char *)((char *)this + 0x64), (const char *)&D_004C7210);
    strcpy((char *)((char *)this + 0xC8), (const char *)&D_004C7210);
    field_CB = 0;
    field_CC = 0;
    field_E0 = 0;
    field_E4 = 0;
    field_E8 = 0;
    field_EC = 0;
    field_F0 = 0;
    field_F4 = 0;
    field_100 = 0;
    field_104 = 0;
    field_110 = 0;
    field_114 = 0;
    field_D0 = 0;
    field_D4 = 0;
    return 1;
}
