// B3HardCodedCrashStageList.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3HardCodedCrashStageList.cpp, 3 by a medium-confidence name confirmed by a neighbour, 4 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HardCodedCrashStageList.h"

struct UnkStruct_003E8FC0_0;
struct UnkStruct_003E9240_2;

struct UnkStruct_003E8FC0_0 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
    unsigned char field_5;
    signed char field_6;
    signed char field_7;
    signed char field_8;
    signed char field_9;
    signed char field_A;
    signed char field_B;
    unsigned char pad_C[0x4];
};
struct UnkStruct_003E9240_2 {
    unsigned char pad_0[0x6];
    signed char field_6;
    unsigned char pad_7[0x9];
};

extern unsigned long kaB3HardCodedCrashStageList[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, void *);
extern "C" unsigned long GtIDCompress__FPCc(UnkStruct_003E8FC0_0 *, signed char, signed char, void *, signed char, void *, void *);

// CB3HardCodedCrashStageList::GetCrashStageTrackID(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HardCodedCrashStageList.cpp.
// 0x003E8FC0
// w64 (2026-11-02): static, returns GtIDCompress__FPCc's 64-bit result [C retail: v0 from GtIDCompress__FPCc reaches the return
// unchanged; callers use it as a 64-bit id]; the id is p0 in a0 (was read as `this`).
unsigned long CB3HardCodedCrashStageList::GetCrashStageTrackID(unsigned long p0)
{
    UnkStruct_003E8FC0_0 local;  // [G] the frame's one local (size: up to the frame top)
    func_0021ADF0(p0, &local);
    signed char t0 = local.field_6;
    signed char t1 = local.field_7;
    signed char t2 = local.field_8;
    signed char t3 = local.field_9;
    local.field_2 = 95;
    local.field_5 = 95;
    local.field_0 = t0;
    signed char t4 = local.field_A;
    signed char t5 = local.field_B;
    local.field_1 = t1;
    local.field_3 = t2;
    local.field_4 = t3;
    local.field_8 = 0;
    local.field_6 = t4;
    local.field_7 = t5;
    return GtIDCompress__FPCc(&local, t3, t2, ((char *)&local + 0x8), t1, ((char *)&local + 0x7), ((char *)&local + 0x6));
}

// IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E9240
extern "C" bool IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int n0, int p0)
{
    UnkStruct_003E9240_2 local;  // [G] the frame's one local (size: up to the frame top)
    func_0021ADF0(kaB3HardCodedCrashStageList[p0], &local);
    switch (n0) {
    case 0:
        return (local.field_6 == 85);
    case 1:
        return (local.field_6 == 69);
    case 2:
        return (local.field_6 == 65);
    }
    return 0;
}

// func_003E9490 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E9490
extern "C" int func_003E9490(int n0, int p0)
{
    int v1;
    if (n0 >= 0) {
        int v0;
        if (p0 != 0) {
            v0 = (n0 + 1374);
        } else {
            v0 = (n0 + 1474);
        }
        v1 = v0;
    } else {
        v1 = 1168;
    }
    return v1;
}

// FindCrashStageName__26CB3HardCodedCrashStageListFUl -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E94C0
// [L] the search loop is CB3HardCodedCrashStageList::FindCrashStage(unsigned long) (0x3E9540) inlined; the
// result mapping matches func_003E9490 (index + 1374, else 1168).
extern "C" int FindCrashStageName__26CB3HardCodedCrashStageListFUl(unsigned long n0)
{
    int i;
    for (i = 0; i < 100; i++) {
        if (n0 == kaB3HardCodedCrashStageList[i]) {
            goto found;
        }
    }
    i = -1;
found:
    if (i >= 0) {
        return i + 1374;
    }
    return 1168;
}

// CB3HardCodedCrashStageList::GetCrashStageGtID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HardCodedCrashStageList.cpp.
// 0x003E9520
unsigned long CB3HardCodedCrashStageList::GetCrashStageGtID(int p0)
{
    return kaB3HardCodedCrashStageList[p0];
}

// CB3HardCodedCrashStageList::FindCrashStage(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HardCodedCrashStageList.cpp.
// 0x003E9540
int CB3HardCodedCrashStageList::FindCrashStage(unsigned long p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (p0 == kaB3HardCodedCrashStageList[i]) {
            return i;
        }
    }
    i++;
loop0_test:
    if (i < 100) goto loop0_body;
    return -1;
}
