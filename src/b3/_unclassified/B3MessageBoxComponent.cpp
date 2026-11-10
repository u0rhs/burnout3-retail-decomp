// B3MessageBoxComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3MessageBoxComponent.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MessageBoxComponent.h"
#include "b3/classes/UnkStruct_D_004A4A10.h"
#include "b3/classes/UnkStruct_D_004A4A14.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"

extern UnkStruct_D_004A4A10 D_004A4A10;
extern int D_004A49D0[];  // [G] element count unknown
extern UnkStruct_D_004A4A14 D_004A4A14;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" int func_0032CC00(void *, int, int, int, int, int, int);
extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// func_0032CF60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0032CF60
extern "C" void func_0032CF60(void *n0, int p0, int p1, int p2, int p3)
{
    int v0 = 0;
    int v2 = 0;
    int t0 = D_004A4A10.field_0[p0].field_0;
    if (t0 <= 9) {
        v0 = func_00271A00(&D_0051BA44, D_004A49D0[t0]);
    }
    int t1 = D_004A4A14.field_0[p0].field_0;
    if (t1 < 10) {
        v2 = func_00271A00(&D_0051BA44, D_004A49D0[t1]);
    }
    func_0032CC00(n0, p0, p1, v0, v2, p2, p3);
}

// func_0032D080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0032D080
extern "C" void func_0032D080(void *n0, int p0, int p1, int p2, int p3)
{
    int r0 = func_00271A00(&D_0051BA44, p1);
    int v1 = 0;
    int v4 = 0;
    int t0 = D_004A4A10.field_0[p0].field_0;
    if (t0 <= 9) {
        v1 = func_00271A00(&D_0051BA44, D_004A49D0[t0]);
    }
    int t1 = D_004A4A14.field_0[p0].field_0;
    if (t1 < 10) {
        v4 = func_00271A00(&D_0051BA44, D_004A49D0[t1]);
    }
    func_0032CC00(n0, p0, r0, v1, v4, p2, p3);
}

// CB3MessageBoxComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MessageBoxComponent.cpp.
// 0x0032D1B0
void CB3MessageBoxComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 2);
    field_80 = 0;
    field_84 = 0;
}
