// func_00452ED0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (default: placed first in both switches (BRIEF default-first rule) removes the hop blocks).


#include "b3/classes/UnkStruct_D_0051BA88.h"
// func_00452ED0 -- hand-written (a158): format one statistics string (mask a1: 1/2/4/8 track records, 0x10/0x20 totals), online or offline source.
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_ulong { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_00522660_ent { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12C410]; UnkStruct_00522660_ent field_12C410[2]; };
struct UnkStruct_00452ED0_s1 {
    unsigned char pad_0[0x3C];
    float field_3C;
    int field_40;
    unsigned char pad_44[0x18];
    float field_5C;
    unsigned char pad_60[4];
    float field_64;
    int field_68;
    unsigned char pad_6C[0x2C];
    int field_98;
};
struct UnkStruct_00452ED0_s2 {
    unsigned char pad_0[0x20];
    float field_20;
    int field_24;
    unsigned char pad_28[0x18];
    int field_40;
};
struct UnkStruct_00452ED0_s5 { unsigned char pad_0[0x40]; int field_40; };
extern UnkStruct_D_byte D_01E65499;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_P16 D_01EA7810;
extern UnkStruct_P16 D_01E90438;
extern UnkStruct_P16 D_01E32AE0;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_D_int D_006512D8;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned long D_004E2EE8;
extern unsigned long D_004E2EF0;
extern float D_004E0C14;
extern unsigned short D_004E2640;
extern "C" UnkStruct_00452ED0_s5 *GetTrackRecords__10CB3RecordsFUl(void *, unsigned long);
extern "C" int func_003D1000(void *, unsigned long);
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" unsigned short *func_003B8670(void *, float);
extern "C" void *func_003B8550(void *, float);
extern "C" void *func_003B84F0(void *, int);
extern "C" signed char func_003D25E0(void *, int);
extern "C" signed char func_003D1C50(void *, int);
extern "C" void *func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" int func_0026C8C0(void *);
extern "C" UnkStruct_00452ED0_s2 *GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);

// 0x00452ED0
extern "C" void *func_00452ED0(void *p0, unsigned int mask, int idx, signed char *out)
{
    UnkStruct_00452ED0_s2 *s2;
    UnkStruct_00452ED0_s1 *s1;
    UnkStruct_00452ED0_s5 *s5 = 0;
    void *s0 = 0;
    int s7;
    int i;
    int a1;
    int fp = D_01E65499.field_0;
    if (fp != 0) goto online;
    s1 = (UnkStruct_00452ED0_s1 *)&D_00522660.field_12C410[idx];
    s2 = 0;
main:
    if ((mask & 0xF) != 0) {
        int v1;
        s5 = GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, D_004E2EE8);
        switch (mask) {
        default:
            return 0;
        case 1:
            if (s1 == 0) goto c1_s2;
            if (s1->field_3C < D_004E0C14) goto c1_fmt1;
            s0 = &D_004E2640;
        c1_join:
            v1 = 0;
            break;
        case 2:
            void *t2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
            s0 = t2;
            if (s1 == 0) goto c2_s2;
            PrintInt__10CGtUnicodeFPUsii(t2, s1->field_68, 1, 0);
        c2_join:
            v1 = 1;
            break;
        case 4:
            if (s1 != 0) {
                func_003B8670(s0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10), s1->field_64);
            }
            v1 = 2;
            break;
        case 8:
            if (s1 != 0) {
                func_003B8670(s0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10), s1->field_5C);
            }
            v1 = 3;
            break;
        }
        *out = func_003D25E0((char *)s5 + v1 * 140, idx);
    } else {
    s7 = func_003D1000(&D_01EA7810, D_004E2EF0);
    switch (mask) {
    default:
        return 0;
    case 0x10:
        if (s1 == 0) goto c10_s2;
        s0 = func_003B84F0(&D_01E90438, s1->field_98);
    c10_join:
        *out = func_003D25E0((void *)s7, idx);
        break;
    case 0x20: {
        if (idx != 0) goto ret0;
        if (fp != 0) {
            if (s5 == 0) goto a1m1;
            a1 = s1->field_98 + s5->field_40;
        } else {
            a1 = s1->field_98 + D_006512D8.field_0;
        }
    a1_test:
        if (a1 != -1) {
            s0 = func_003B84F0(&D_01E90438, a1);
            *out = func_003D1C50((char *)s7 + 0x8C, idx);
        }
        break;
    }
    }
    }
    return s0;
online:
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 4) {
        if (func_0026C8C0(&D_01E32AE0) == 0 || *((unsigned char *)D_0051BA88.field_0->field_1B4 + 0x73) == 0) {
            s2 = 0;
            s5 = 0;
            s1 = 0;
            goto main;
        }
    }
    if (idx == 1) {
        s7 = -1;
        for (i = 0; i < D_01E32B08.field_0; i++) {
            void *pl = func_002366D0(&D_01E32AE0, i);
            if (pl != 0) s7 = func_0022FBB0(pl);
        }
        s1 = 0;
        s2 = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, s7);
        goto main;
    }
    s2 = 0;
    s7 = -1;
    s1 = (UnkStruct_00452ED0_s1 *)&D_00522660.field_12C410[idx];
    if (D_01E32B08.field_0 == 2) {
        for (i = 0; i < D_01E32B08.field_0; i++) {
            void *pl = func_002366D0(&D_01E32AE0, i);
            if (pl != 0) s7 = func_0022FBB0(pl);
        }
        s5 = (UnkStruct_00452ED0_s5 *)GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, s7);
    }
    goto main;
c1_fmt1:
    s0 = func_003B8550(&D_01E90438, s1->field_3C);
    goto c1_join;
c1_s2:
    if (s2 == 0) goto c1_join;
    if (s2->field_20 < D_004E0C14) goto c1_fmt2;
    s0 = &D_004E2640;
    goto c1_join;
c1_fmt2:
    s0 = func_003B8550(&D_01E90438, s2->field_20);
    goto c1_join;
c2_s2:
    if (s2 == 0) goto c2_join;
    PrintInt__10CGtUnicodeFPUsii(s0, s2->field_24, 1, 0);
    goto c2_join;
c10_s2:
    if (s2 != 0) s0 = func_003B84F0(&D_01E90438, s2->field_40);
    goto c10_join;
ret0:
    return 0;
a1m1:
    a1 = -1;
    goto a1_test;
}
