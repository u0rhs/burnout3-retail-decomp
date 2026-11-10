// B3CrashScore.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3CrashScore.cpp, 5 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4CrashScore.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashScore.h"
#include "b3/classes/ECrashModePickupType.h"

struct UnkStruct_003CCFB0;
struct UnkStruct_003CD080;
struct UnkStruct_003CD080_e1;

struct UnkStruct_003CCFB0 {
    unsigned char pad_0[0x4FA];
    unsigned char field_4FA;
};

struct UnkStruct_003CD080_e1 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x10];
};

struct UnkStruct_003CD080 {
    unsigned char pad_0[0x438];
    UnkStruct_003CD080_e1 field_438[1];  // [G] element count unknown
    unsigned char pad_44C[0xA6];
    unsigned char field_4F2[1];  // [G] element count unknown
};

// CB3CrashScore::AddCrashScore(ECrashModePickupType,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashScore.cpp.
// 0x003CCE90
void CB3CrashScore::AddCrashScore(ECrashModePickupType p0, int p1)
{
    unsigned char t0 = field_4F2[p1];
    if (t0 >= 5) return;
    field_438[p1].field_0[t0] = p0;
    field_4F2[p1] = (field_4F2[p1] + 1);
}

// func_003CCFB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003CCFB0
extern "C" int func_003CCFB0(UnkStruct_003CCFB0 * self, unsigned char a, unsigned char b)
{
    if ((a & 1) == 1) {
        return 4;
    }
    if (self->field_4FA != 0) {
        if ((b & 1) == 1) {
            return 4;
        }
        if ((a & 4) == 4 && (b & 4) == 4) {
            return 6;
        }
        if ((a & 2) == 2 && (b & 2) == 2) {
            return 5;
        }
        return 9;
    }
    if ((a & 4) == 4) {
        return 6;
    }
    return ((a & 2) == 2) ? 5 : 9;
}

// GetTotalPickupScore__13CB3CrashScoreFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003CD080
extern "C" int GetTotalPickupScore__13CB3CrashScoreFi(UnkStruct_003CD080 * self, int p0)
{
    float m0 = 0.0f;
    for (int m1 = 0; m1 < self->field_4F2[p0]; m1++) {
        switch (self->field_438[p0].field_0[m1]) {
        case 1: m0 += (float)5000; break;
        case 2: m0 += (float)10000; break;
        case 3: m0 += (float)20000; break;
        }
    }
    return ((int)m0);
}

// Destruct__13CB3CrashScoreFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003CD5E0
extern "C" void Destruct__13CB3CrashScoreFv()
{
}

// Release__13CB3CrashScoreFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003CD5F0
extern "C" void Release__13CB3CrashScoreFv()
{
}

// Update__13CB3CrashScoreFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003CD600
extern "C" void Update__13CB3CrashScoreFv()
{
}
