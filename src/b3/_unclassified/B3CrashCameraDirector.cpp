// B3CrashCameraDirector.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3CrashCameraDirector.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashCameraDirector.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_0051BAD6.h"

struct UnkStruct_00354F70;
struct UnkStruct_00354F70_1;
struct UnkStruct_00356680;
struct UnkStruct_00356680_1;
struct UnkStruct_00356680_a1;
struct UnkStruct_00355A90;
struct UnkStruct_00355A90_1;

struct UnkStruct_00354F70_1 {
    unsigned char pad_0[0xB80];
    unsigned long field_B80;
};

struct UnkStruct_00354F70 {
    unsigned char pad_0[0xC];
    UnkStruct_00354F70_1 * field_C;
    unsigned char pad_10[0x23];
    unsigned char field_33;
};

struct UnkStruct_00356680_1 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
};

struct UnkStruct_00356680_a1 {
    unsigned char field_0;
};

struct UnkStruct_00356680 {
    unsigned char pad_0[0x60];
    UnkStruct_00356680_1 * field_60;
};

struct UnkStruct_00355A90_1 {
    unsigned char pad_0[0x1038];
    int field_1038;
    unsigned char pad_103C[0xC];
    unsigned char field_1048;
};

struct UnkStruct_00355A90 {
    unsigned char pad_0[0x8];
    UnkStruct_00355A90_1 * field_8;
    unsigned char pad_C[0x24];
    unsigned char field_30;
};

extern UnkStruct_D_0051BAD6 D_0051BAD6;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131F60(void *);
extern "C" int func_00131E40(void *);
extern "C" int func_003550F0(UnkStruct_00355A90 *, void *, void *, void *, int, int, float, float, float);

// CB3CrashCameraDirector::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCameraDirector.cpp.
// 0x00354F60
void CB3CrashCameraDirector::Destruct()
{
}

// func_00354F70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00354F70
extern "C" void func_00354F70(UnkStruct_00354F70 * self)
{
    int r0 = func_00131F60(&D_004EE040);
    if (r0 != 0) {
        if ((self->field_C->field_B80 & 1024) != 0) {
            D_0051BAD6.field_0 = 1;
        }
    }
    self->field_33 = 0;
}

// func_00355A90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00355A90
extern "C" int func_00355A90(UnkStruct_00355A90 * self, void *p0, void *p1, void *p2, int p3, int p4)
{
    int t1 = self->field_8->field_1038;
    float a;
    float b;
    float c;
    if (self->field_30 != 0 || t1 >= 6) {
        a = 4.5f;
        b = 14.0f;
        c = 45.0f;
    } else if (t1 < 3) {
        if (func_00131E40(&D_004EE040) == 0 && self->field_8->field_1048 != 0) {
            a = 2.5f;
            b = 8.0f;
            c = 60.0f;
        } else {
            a = 1.5f;
            b = 6.0f;
            c = 60.0f;
        }
    } else {
        a = 2.5f;
        b = 8.0f;
        c = 60.0f;
    }
    return func_003550F0(self, (void *)(p0), (void *)(p1), (void *)(p2), p3, p4, a, b, c);
}

// func_00356680 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00356680
extern "C" int func_00356680(UnkStruct_00356680 * self, UnkStruct_00356680_a1 * p0)
{
    if (((((((self->field_60->field_4 & 255) == 34) || ((self->field_60->field_4 & 255) == 35)) || ((self->field_60->field_4 & 255) == 36)) || ((self->field_60->field_4 & 255) == 32)) || (((self->field_60->field_4 & 2048) != 0) != false)) || (((self->field_60->field_4 & 1024) != 0) != false)) {
        return 1;
    }
    p0->field_0 = 1;
    return 1;
}

// CB3CrashCameraDirector::Prepare(bool) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CrashCameraDirector.cpp.
// 0x00357520
int CB3CrashCameraDirector::Prepare(bool p0)
{
    field_18 = 0;
    field_1C = 0;
    field_20 = 0;
    field_2C = 0;
    field_30 = 0;
    field_31 = p0;
    field_33 = 1;
    return 1;
}
