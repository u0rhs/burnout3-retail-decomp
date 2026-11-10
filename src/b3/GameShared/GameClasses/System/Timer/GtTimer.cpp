// GtTimer.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> GtTimer.cpp.
// Area: src/b3/GameShared/GameClasses/System/Timer, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Timer/GtTimer.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtTimer.h"

struct UnkStruct_001D3C10;
struct UnkStruct_001D3CE0;
struct UnkStruct_001D3C50;

struct UnkStruct_001D3C10 {
    unsigned char pad_0[0x28];
    unsigned char field_28;
};

struct UnkStruct_001D3CE0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
};

struct UnkStruct_001D3C50 {
    unsigned char pad_0[0x28];
    unsigned char field_28;
};

extern "C" void Update__8CGtTimerFv(void *);

// CGtTimer::SetSlowMo(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTimer.cpp.
// 0x001D3A50
void CGtTimer::SetSlowMo(int p0)
{
    field_24 = p0;
}

// Stop__8CGtTimerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D3C10
extern "C" void Stop__8CGtTimerFv(UnkStruct_001D3C10 * self)
{
    if (self->field_28 != 0) {
        Update__8CGtTimerFv(self);
        self->field_28 = 0;
    }
}

// Start__8CGtTimerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D3C50
extern "C" void Start__8CGtTimerFv(UnkStruct_001D3C50 * self)
{
    if (self->field_28 == 0) {
        Update__8CGtTimerFv(self);
        self->field_28 = 1;
    }
}

// Construct__8CGtTimerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D3CE0
extern "C" void Construct__8CGtTimerFv(UnkStruct_001D3CE0 * self)
{
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = CGtTimer::mguFrames;
    self->field_18 = 1;
    self->field_24 = 1;
    self->field_28 = 0;
    self->field_1C = 0;
    self->field_20 = 0;
}

// func_001D3D20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D3D20
extern "C" void func_001D3D20()
{
    CGtTimer::mguFrames = (CGtTimer::mguFrames + 1);
}

// PrepareTimerServices__8CGtTimerFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D3D30
extern "C" int PrepareTimerServices__8CGtTimerFi(int n0)
{
    CGtTimer::mguFrames = 0;
    CGtTimer::mgnBaseTimestepMilliSeconds = (1000 / n0);
    CGtTimer::mgrBaseTimestepSeconds = (1.0f / ((float)n0));
    return 1;
}
