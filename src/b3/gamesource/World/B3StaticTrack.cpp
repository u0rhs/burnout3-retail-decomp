// B3StaticTrack.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3StaticTrack.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4StaticTrack.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CAsyncLoadManager.h"
#include "b3/classes/CB3BackdropObject.h"
#include "b3/classes/CB3StaticTrack.h"
#include "b3/classes/UnkStruct_gVdbDatabase.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_00332D70;

struct UnkStruct_00332D70 {
    unsigned char field_0;
    unsigned char pad_1[0x3];
    int field_4;
    int field_8;
    int field_C;
};

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern CAsyncLoadManager D_004F6100;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void RenderStaticObject__14CB3StaticTrackFRC20CB3StaticTrackObject(void *, const void *);  // CB3StaticTrack::RenderStaticObject(const CB3StaticTrackObject&)
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, void *);

// CB3StaticTrack::RenderBackdrop(const CB3BackdropObject&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrack.cpp.
// 0x00332D00
void CB3StaticTrack::RenderBackdrop(const CB3BackdropObject& p0)
{
    for (int i = 0; (i < p0.field_0); i++) {
        RenderStaticObject__14CB3StaticTrackFRC20CB3StaticTrackObject(this, &p0.field_4[i]);
    }
}

// Release__14CB3StaticTrackFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00332D70
extern "C" void Release__14CB3StaticTrackFv(UnkStruct_00332D70 * self)
{
    int t0 = self->field_C;
    if (t0 != 0) {
        D_004F6100.Abort(t0);
        self->field_C = 0;
    }
    self->field_0 = 0;
    self->field_4 = 0;
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 5, 0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)self + 0x10));
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)self + 0x14));
    self->field_8 = 24;
}

// CB3StaticTrack::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrack.cpp.
// 0x00333110
void CB3StaticTrack::Destruct()
{
    field_8 = 25;
}

// CB3StaticTrack::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrack.cpp.
// 0x00333120
void CB3StaticTrack::Construct()
{
    field_0 = 0;
    field_4 = 0;
    field_C = 0;
    field_8 = 1;
}
