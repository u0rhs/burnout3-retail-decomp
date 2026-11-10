// func_00461F40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004B12A0.h"
#include "b3/classes/UnkStruct_D_004D3AD0.h"

struct UnkStruct_00461F40_c0 {
    int field_0[16];
};

struct UnkStruct_00461F40_c1 {
    int field_0[12];
};

struct UnkStruct_00461F40_c2 {
    int field_0[12];
};

struct UnkStruct_00461F40_s {
    char field_0[6];
    short field_6;
    unsigned char pad_8[0x4];
    int field_C;
    UnkStruct_00461F40_c0 field_10;
    UnkStruct_00461F40_c1 field_50;
    UnkStruct_00461F40_c2 field_80;
    float field_B0[4];
    char field_C0[0x44];
    char field_104[0x40];
    char field_144[0x40];
    char field_184[0x240];
};

struct UnkStruct_00461F40_r {
    int field_0;
    int field_4;
    UnkStruct_00461F40_s field_8;
    int field_3CC;
};

struct UnkStruct_00461F40_0 {
    float field_0[4];
    UnkStruct_00461F40_c2 field_10;
    UnkStruct_00461F40_c1 field_40;
    UnkStruct_00461F40_c0 field_70;
    UnkStruct_00461F40_r field_B0;
};

extern UnkStruct_00461F40_c0 D_004B1200;
extern UnkStruct_00461F40_c1 D_004B1240;
extern UnkStruct_00461F40_c2 D_004B1270;
extern UnkStruct_D_004B12A0 D_004B12A0;
extern UnkStruct_D_004B12A0 D_004B12A4;
extern UnkStruct_D_004B12A0 D_004B12A8;
extern UnkStruct_D_004B12A0 D_004B12AC;
extern UnkStruct_D_004D3AD0 D_004D3AD0;
extern UnkStruct_D_004D3AD0 D_004D3AD8;
extern UnkStruct_D_004D3AD0 D_004D3AE8;
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcpy(char *, const char *);
extern "C" unsigned int strlen(const char *);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_00466E80(const char *, char *);
extern "C" int func_00463800(UnkStruct_00461F40_r *);
extern "C" int func_00465320(int);

// 0x00461F40
extern "C" int func_00461F40(int n0)
{
    UnkStruct_00461F40_0 local;  // [G] the frame's one local
    int r = 0;
    // [G] byte-offset copies keep MWCC from holding the table addresses in saved registers for the memcpys.
    *(UnkStruct_00461F40_c0 *)((char *)&local + 0x70) = D_004B1200;
    *(UnkStruct_00461F40_c1 *)((char *)&local + 0x40) = D_004B1240;
    *(UnkStruct_00461F40_c2 *)((char *)&local + 0x10) = D_004B1270;
    local.field_0[0] = D_004B12A0.field_0;
    local.field_0[1] = D_004B12A4.field_0;
    local.field_0[2] = D_004B12A8.field_0;
    local.field_0[3] = D_004B12AC.field_0;
    // [G] retail places the r = 7 block after the r == 0 test (beqz to an out-of-line `b back; li v0,7`);
    // no structured if/else/switch form reproduced that layout, so it is written as a goto (cf. N24).
    if (n0 == 0) goto bad;
back:
    if (r == 0) {
        memset(&local.field_B0.field_8, 0, sizeof(local.field_B0.field_8));
        strcpy(local.field_B0.field_8.field_0, D_004D3AD0.field_0);
        func_00466E80(D_004D3AD8.field_0, local.field_B0.field_8.field_C0);
        local.field_B0.field_8.field_6 = strlen(D_004D3AD8.field_0) * 2;
        local.field_B0.field_8.field_C = 0x60;
        memcpy(&local.field_B0.field_8.field_10, &local.field_70, sizeof(local.field_70));
        memcpy(&local.field_B0.field_8.field_50, &local.field_40, sizeof(local.field_40));
        memcpy(&local.field_B0.field_8.field_80, &local.field_10, sizeof(local.field_10));
        memcpy(local.field_B0.field_8.field_B0, local.field_0, sizeof(local.field_0));
        strcpy(local.field_B0.field_8.field_104, D_004D3AE8.field_0);
        strcpy(local.field_B0.field_8.field_144, D_004D3AE8.field_0);
        strcpy(local.field_B0.field_8.field_184, D_004D3AE8.field_0);
        local.field_B0.field_4 = 0x296E;
        // [G] byte-offset form: through local.field_B0.field_0 MWCC reuses the call's a0 as the store base.
    *(int *)((char *)&local + 0xB0) = n0;
        local.field_B0.field_3CC = 34;
        r = func_00465320(func_00463800(&local.field_B0));
    }
    return r;
bad:
    r = 7;
    goto back;
}
