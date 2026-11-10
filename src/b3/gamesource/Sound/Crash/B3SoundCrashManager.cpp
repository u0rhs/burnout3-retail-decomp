// B3SoundCrashManager.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3SoundCrashManager.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Sound/Crash, [L] Revenge (SLUS_212.42) GameSource/Sound/Crash/B4SoundCrashManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3SoundCrashManager.h"
#include "b3/classes/UnkStruct_D_004BEE98.h"
#include "b3/classes/UnkStruct_D_004BEEA8.h"
#include "b3/classes/UnkStruct_D_004BEEB8.h"
#include "b3/classes/UnkStruct_D_004BEEC8.h"
#include "b3/classes/UnkStruct_D_004BEED8.h"
#include "b3/classes/UnkStruct_D_004BEEE8.h"
#include "b3/classes/UnkStruct_D_004BEEF8.h"
#include "b3/classes/UnkStruct_D_004BEF08.h"
#include "b3/classes/UnkStruct_D_004BEF18.h"
#include "b3/classes/UnkStruct_D_004BEF28.h"
#include "b3/classes/UnkStruct_D_004BEF38.h"
#include "b3/classes/UnkStruct_D_004BEF48.h"
#include "b3/classes/UnkStruct_D_004BEF58.h"
#include "b3/classes/UnkStruct_D_004BEF68.h"
#include "b3/classes/UnkStruct_D_004BEF78.h"
#include "b3/classes/UnkStruct_D_004BEF88.h"
#include "b3/classes/UnkStruct_D_004BEF98.h"
#include "b3/classes/UnkStruct_D_004BEFA8.h"
#include "b3/classes/UnkStruct_D_004BEFB8.h"
#include "b3/classes/UnkStruct_D_004BEFC8.h"
#include "b3/classes/UnkStruct_D_004BEFD8.h"
#include "b3/classes/UnkStruct_D_004BEFE8.h"
#include "b3/classes/UnkStruct_D_004BEFF8.h"
#include "b3/classes/UnkStruct_D_004BF008.h"
#include "b3/classes/UnkStruct_D_004BF018.h"
#include "b3/classes/UnkStruct_D_004BF028.h"
#include "b3/classes/UnkStruct_D_004BF038.h"
#include "b3/classes/UnkStruct_D_004BF048.h"
#include "b3/classes/UnkStruct_D_004BF058.h"
#include "b3/classes/UnkStruct_D_004BF068.h"
#include "b3/classes/UnkStruct_D_004BF078.h"
#include "b3/classes/UnkStruct_D_004BF088.h"
#include "b3/classes/UnkStruct_D_004BF098.h"
#include "b3/classes/UnkStruct_D_004BF0A8.h"
#include "b3/classes/UnkStruct_D_0064D370.h"

struct UnkStruct_00281890;

struct UnkStruct_0027D240_2 {
    GtMathPs2::CGtV3d field_0;
    unsigned char pad_10[0x10];
};

struct UnkStruct_00281890 {
    unsigned char pad_0[0x8C1];
    unsigned char field_8C1;
};

extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_004BEE98 D_004BEE98;
extern UnkStruct_D_004BEEA8 D_004BEEA8;
extern UnkStruct_D_004BEEB8 D_004BEEB8;
extern UnkStruct_D_004BEEC8 D_004BEEC8;
extern UnkStruct_D_004BEED8 D_004BEED8;
extern UnkStruct_D_004BEEE8 D_004BEEE8;
extern UnkStruct_D_004BEEF8 D_004BEEF8;
extern UnkStruct_D_004BEF08 D_004BEF08;
extern UnkStruct_D_004BEF18 D_004BEF18;
extern UnkStruct_D_004BEF28 D_004BEF28;
extern UnkStruct_D_004BEF38 D_004BEF38;
extern UnkStruct_D_004BEF48 D_004BEF48;
extern UnkStruct_D_004BEF58 D_004BEF58;
extern UnkStruct_D_004BEF68 D_004BEF68;
extern UnkStruct_D_004BEF78 D_004BEF78;
extern UnkStruct_D_004BEF88 D_004BEF88;
extern UnkStruct_D_004BEF98 D_004BEF98;
extern UnkStruct_D_004BEFA8 D_004BEFA8;
extern UnkStruct_D_004BEFB8 D_004BEFB8;
extern UnkStruct_D_004BEFC8 D_004BEFC8;
extern UnkStruct_D_004BEFD8 D_004BEFD8;
extern UnkStruct_D_004BEFE8 D_004BEFE8;
extern UnkStruct_D_004BEFF8 D_004BEFF8;
extern UnkStruct_D_004BF008 D_004BF008;
extern UnkStruct_D_004BF018 D_004BF018;
extern UnkStruct_D_004BF028 D_004BF028;
extern UnkStruct_D_004BF038 D_004BF038;
extern UnkStruct_D_004BF048 D_004BF048;
extern UnkStruct_D_004BF058 D_004BF058;
extern UnkStruct_D_004BF068 D_004BF068;
extern UnkStruct_D_004BF078 D_004BF078;
extern UnkStruct_D_004BF088 D_004BF088;
extern UnkStruct_D_004BF098 D_004BF098;
extern UnkStruct_D_004BF0A8 D_004BF0A8;
extern "C" void func_0027CF30(void *, UnkStruct_0027D240_2 *, float);
extern "C" void func_0027CC20(void *, UnkStruct_0027D240_2 *, float);
extern "C" unsigned long GtIDCompress__FPCc(void *);

// CB3SoundCrashManager::SetPlayerCarSpeed(float) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// 0x0027B760
void CB3SoundCrashManager::SetPlayerCarSpeed(float p0)
{
    field_8A8 = p0;
}

// CB3SoundCrashManager::FadeOutCrashStream() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// 0x0027BEF0
void CB3SoundCrashManager::FadeOutCrashStream()
{
    field_8DD = 1;
}

// func_0027D240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0027D240
extern "C" void func_0027D240(void *n0, GtMathPs2::CGtV3d p0, float f, int p1)
{
    UnkStruct_0027D240_2 v;
    UnkStruct_0027D240_2 * pv = &v;
    pv->field_0 = p0;
    if (p1 == 0) {
        func_0027CF30((void *)(n0), pv, f);
    } else {
    }
    if (p1 == 1) {
        func_0027CF30((void *)(n0), &v, f);
    } else {
    }
    if (p1 == 2) {
        func_0027CC20((void *)(n0), &v, f);
    } else {
    }
    if (p1 == 3) {
        func_0027CC20((void *)(n0), &v, f);
    } else {
    }
    if (p1 == 4) {
        func_0027CF30((void *)(n0), &v, f);
    } else {
    }
    if (p1 == 5) {
        func_0027CF30((void *)(n0), &v, f);
    } else {
    }
    if (p1 == 6) {
        func_0027CC20((void *)(n0), &v, f);
    }
}

// func_0027E540 -- tiny-function batch (tools/tiny_batch.py, hand-written vararg template).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0027E540
extern "C" void func_0027E540(int, ...)
{
}

// func_00281890 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00281890
extern "C" void func_00281890(UnkStruct_00281890 * self)
{
    unsigned long t0 = D_0064D370.field_0;
    if (t0 == GtIDCompress__FPCc(&D_004BEE98) || t0 == GtIDCompress__FPCc(&D_004BEEA8)) {
        self->field_8C1 = 0;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEEB8) || t0 == GtIDCompress__FPCc(&D_004BEEC8)) {
        self->field_8C1 = 1;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEED8) || t0 == GtIDCompress__FPCc(&D_004BEEE8)) {
        self->field_8C1 = 2;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEEF8) || t0 == GtIDCompress__FPCc(&D_004BEF08)) {
        self->field_8C1 = 10;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEF18) || t0 == GtIDCompress__FPCc(&D_004BEF28)) {
        self->field_8C1 = 11;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEF38) || t0 == GtIDCompress__FPCc(&D_004BEF48)) {
        self->field_8C1 = 12;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEF58) || t0 == GtIDCompress__FPCc(&D_004BEF68)) {
        self->field_8C1 = 3;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEF78) || t0 == GtIDCompress__FPCc(&D_004BEF88)) {
        self->field_8C1 = 4;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEF98) || t0 == GtIDCompress__FPCc(&D_004BEFA8)) {
        self->field_8C1 = 5;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEFB8) || t0 == GtIDCompress__FPCc(&D_004BEFC8)) {
        self->field_8C1 = 6;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEFD8) || t0 == GtIDCompress__FPCc(&D_004BEFE8)) {
        self->field_8C1 = 13;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BEFF8) || t0 == GtIDCompress__FPCc(&D_004BF008)) {
        self->field_8C1 = 14;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BF018) || t0 == GtIDCompress__FPCc(&D_004BF028)) {
        self->field_8C1 = 15;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BF038) || t0 == GtIDCompress__FPCc(&D_004BF048)) {
        self->field_8C1 = 7;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BF058) || t0 == GtIDCompress__FPCc(&D_004BF068)) {
        self->field_8C1 = 8;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BF078) || t0 == GtIDCompress__FPCc(&D_004BF088)) {
        self->field_8C1 = 9;
        return;
    }
    if (t0 == GtIDCompress__FPCc(&D_004BF098) || t0 == GtIDCompress__FPCc(&D_004BF0A8)) {
        self->field_8C1 = 16;
        return;
    }
}
