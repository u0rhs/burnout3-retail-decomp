// func_004663A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC4.h"

struct UnkStruct_func_00465FF0;
struct UnkStruct_func_00466100;

struct UnkStruct_func_00466100 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00465FF0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;
extern UnkStruct_func_00466100 func_00466100;
extern UnkStruct_func_00465FF0 func_00465FF0;
extern "C" int func_004636E0(void *, int, int, int);
extern "C" int func_00465320(int);
extern "C" int func_004641F0(void *, int, int, int, int);

// 0x004663A0
extern "C" void func_004663A0()
{
    D_004E2FC4.field_0->field_100 = &func_00466100;
    D_004E2FC4.field_0->field_104 = &func_00465FF0;
    int r0 = func_004636E0(((char *)D_004E2FC4.field_0 + 0x148), D_004E2FC4.field_0->field_144, 17, 0);
    int r1 = func_00465320(r0);
    if (r1 == 0) {
        int r2 = func_004641F0(((char *)D_004E2FC4.field_0 + 0x48), 0x41434354, 0, D_004E2FC4.field_0->field_148, 17);
        func_00465320(r2);
    }
}
