// B3MenuChoices.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3MenuChoices.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu, [L] Revenge (SLUS_212.42) GameSource/Menu/B4MenuChoices.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MenuChoices.h"
#include "b3/classes/CB3StageDataStruct.h"
#include "b3/classes/UnkStruct_D_0051A86C.h"
#include "b3/classes/UnkStruct_D_01E900B4.h"
#include "b3/classes/UnkStruct_D_01E900B8.h"
#include "b3/classes/UnkStruct_D_01E900BC.h"
#include "b3/classes/UnkStruct_D_01E900C0.h"

struct UnkStruct_0030CE20_e0;
struct UnkStruct_0030CE20_e1;

struct UnkStruct_0030CE20_e0 {
    unsigned char pad_0[0x390];
    unsigned long field_390;
    unsigned long field_398;
    unsigned char pad_3A0[0x40];
};

struct UnkStruct_0030CE20_e1 {
    unsigned char pad_0[0x3E0];
};

extern UnkStruct_D_0051A86C D_0051A86C;
extern UnkStruct_D_01E900B4 D_01E900B4;
extern UnkStruct_D_01E900C0 D_01E900C0;
extern UnkStruct_D_01E900B8 D_01E900B8;
extern UnkStruct_D_01E900BC D_01E900BC;

// CB3MenuChoices::GetGameStageData(CB3StageDataStruct*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuChoices.cpp.
// 0x0030CE20
void * CB3MenuChoices::GetGameStageData(CB3StageDataStruct* p0)
{
    UnkStruct_0030CE20_1 * t0 = D_0051A86C.field_0;
    UnkStruct_0030CE20_e0 *e = (UnkStruct_0030CE20_e0 *)((char *)t0 + 0x278);
    int t1 = t0->field_260;
    for (int i = 0; (i < t1); i++) {
        if (e->field_398 == p0->field_8) {
            if (e->field_390 == p0->field_0) {
                return e;
            }
        }
        e++;
    }
    return 0;
}

// func_0030CE80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030CE80
extern "C" int func_0030CE80(void *a0 /* passed by every caller, not read here */)
{
    if ((D_01E900B4.field_0 != 3) || (D_01E900C0.field_0 != 1)) {
        return 1;
    }
    return 0;
}

// func_0030CEC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030CEC0
extern "C" int func_0030CEC0(void *a0 /* passed by every caller, not read here */)
{
    int t = D_01E900B4.field_0;
    if (t == 0 && D_01E900B8.field_0 == 3) return 1;
    if (t == 1 && D_01E900B8.field_0 == 3) return 1;
    if (t == 2 && (unsigned)(D_01E900BC.field_0 - 2) < 3) return 1;
    if (t == 3 && (unsigned)(D_01E900C0.field_0 - 2) < 3) return 1;
    if (t == 4) return 1;
    return 0;
}
