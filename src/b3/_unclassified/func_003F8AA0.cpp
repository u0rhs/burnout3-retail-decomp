// func_003F8AA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E1ED4.h"
#include "b3/classes/UnkStruct_D_004E1ED8.h"
#include "b3/classes/UnkStruct_D_004E2918.h"

struct UnkStruct_003F8AA0_a3 {
    int field_0;
};

struct UnkStruct_003F8AA0_t0 {
    int field_0;
};

extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_004E1ED4 D_004E1ED4;
extern UnkStruct_D_004E1ED8 D_004E1ED8;
extern int D_004A55D0[];  // [G] element count unknown
extern char D_004CE8E8[];  // [G] strings (strcpy/strcat/sprintf sources)
extern char D_004CE9B8[];
extern char D_004CE9C0[];
extern char D_004CE958[];
extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" char * strncat(char *, const char *, int);
extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" int sprintf(int, const char *, ...);

// 0x003F8AA0
// [L] two separate stack buffers: a 0x10-byte one at sp+0x90 that func_0021ADF0 fills (pieces at +0, +3, +6
// are appended; +7 is overwritten with '1') and the 0x20-byte result string at sp+0x70. Declared in this
// order so MWCC lays them out as retail does, and as one struct MWCC caches &buf in a saved register.
extern "C" void func_003F8AA0(void *n0_, unsigned long p0, void *p1_, UnkStruct_003F8AA0_a3 * p2, UnkStruct_003F8AA0_t0 * p3, int p4, int p5)
{
    int n0 = (int)n0_;
    int p1 = (int)p1_;
    char d[0x10];
    char s[0x20];
    strcpy(s, D_004CE8E8);
    func_0021ADF0(p0, d);
    strncat(s, d, 2);
    strcat(s, D_004CE9B8);
    strncat(s, d + 3, 2);
    strcat(s, D_004CE9C0);
    d[7] = 49;
    strncat(s, d + 6, 2);
    strcat(s, D_004CE9B8);
    sprintf(p1, D_004CE958, s, D_004A55D0[D_004E2918.field_0], D_004E1ED4.field_0, D_004E1ED8.field_0);
    if (p4 == 0) {
        p2->field_0 = 0;
        p3->field_0 = 22;
    } else if (p5 != 0) {
        p2->field_0 = 22;
        p3->field_0 = 30;
    } else {
        p2->field_0 = 30;
        p3->field_0 = 38;
    }
}
