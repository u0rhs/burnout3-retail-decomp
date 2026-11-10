// B3HardCodedRaceStageList.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3HardCodedRaceStageList.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HardCodedRaceStageList.h"
#include "b3/classes/UnkStruct_D_004CBF08.h"
#include "b3/classes/UnkStruct_kaB3HardCodedRaceChallengeList.h"

struct UnkStruct_003E9A60_0;

struct UnkStruct_003E9A60_0 {
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

extern UnkStruct_kaB3HardCodedRaceChallengeList kaB3HardCodedRaceChallengeList;
extern UnkStruct_D_004CBF08 D_004CBF08;
extern unsigned char kabB3HardCodedRaceChallengeNumTracksUnlockedList[];  // [G] element count unknown
extern "C" void func_0021ADF0(unsigned long, UnkStruct_003E9A60_0 *);
extern "C" unsigned long GtIDCompress__FPCc(UnkStruct_003E9A60_0 *, signed char, signed char, void *, signed char, void *, void *);

// CB3HardCodedRaceStageList::GetStageTrackID(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedRaceStageList.cpp.
// 0x003E9A60
// w64 (2026-11-02): static, returns GtIDCompress__FPCc's 64-bit result [C retail: v0 from GtIDCompress__FPCc reaches the return
// unchanged; callers use it as a 64-bit id]; the id is p0 in a0 (was read as `this`).
unsigned long CB3HardCodedRaceStageList::GetStageTrackID(unsigned long p0)
{
    UnkStruct_003E9A60_0 local;  // [G] the frame's one local (size: up to the frame top)
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

// func_003E9AD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E9AD0
extern "C" int func_003E9AD0(unsigned long n0)
{
    if (kaB3HardCodedRaceChallengeList.field_58 == n0) {
        return 1;
    }
    if (kaB3HardCodedRaceChallengeList.field_C0 == n0) {
        return 2;
    }
    if (kaB3HardCodedRaceChallengeList.field_130 == n0) {
        return 3;
    }
    int v0;
    if (kaB3HardCodedRaceChallengeList.field_1B8 == n0) {
        v0 = 4;
    } else {
        v0 = 8;
    }
    return v0;
}

// func_003E9C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E9C90
extern "C" int func_003E9C90(int n0, int a1 /* passed by every caller, not read here */)
{
    return D_004CBF08.field_0[n0].field_0;
}

// CB3HardCodedRaceStageList::DoesChallengeUnlockTracks(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedRaceStageList.cpp.
// 0x003EA070
unsigned char CB3HardCodedRaceStageList::DoesChallengeUnlockTracks(int p0)
{
    return kabB3HardCodedRaceChallengeNumTracksUnlockedList[p0];
}
