// B3OnlineBuddiesMenuPage.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3OnlineBuddiesMenuPage.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BuddyDisplayComponent.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"

struct UnkStruct_0036C760_a1;

struct UnkStruct_0036C760_a1 {
    unsigned char pad_0[0x11C];
    unsigned char field_11C;
    unsigned char pad_11D[0x1];
    unsigned char field_11E;
};

extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3BuddyDisplayComponent D_01E8D670;
extern "C" void func_0032D080(void *, int, int, int, int);

// func_0036C760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0036C760
extern "C" void func_0036C760(int n0, UnkStruct_0036C760_a1 * p0)
{
    p0->field_11C = n0;
    p0->field_11E = 1;
}

// func_0036C770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0036C770
extern "C" void func_0036C770(int n0, int p0, int p1)
{
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (n0 == 0) {
        if (p1 == 6) {
            func_0032D080(&D_01E898E8, 2, 208, 0, 0);
        } else {
            func_0032D080(&D_01E898E8, 2, 207, 0, 0);
        }
    } else {
        func_0032D080(&D_01E898E8, 2, 28, 0, 0);
    }
    D_01E8D670.MailSent(p0);
}
