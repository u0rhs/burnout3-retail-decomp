// func_0026C0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004BCA40.h"
#include "b3/classes/UnkStruct_D_004E19F0.h"

struct UnkStruct_0026C0A0;
struct UnkStruct_0026C0A0_0;

struct UnkStruct_0026C0A0_0 {
    unsigned char pad_0[0x48];
    int field_48;
    int field_4C;
    unsigned char pad_50[0x10];
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    unsigned char pad_70[0x24];
    int field_94;
    int field_98;
    int field_9C;
};

struct UnkStruct_0026C0A0 {
    unsigned char pad_0[0x329D4];
    int field_329D4;
    int field_329D8;
    unsigned char pad_329DC[0x18];
    int field_329F4;
    int field_329F8;
};

extern UnkStruct_D_004E19F0 D_004E19F0;
extern UnkStruct_D_004BCA40 D_004BCA40;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" char * strcpy(char *, const char *);
extern "C" void DirtyDnasInit(int, int);
extern "C" void _dnasexports(UnkStruct_0026C0A0_0 *, int);

// 0x0026C0A0
extern "C" int func_0026C0A0(UnkStruct_0026C0A0 * self)
{
    UnkStruct_0026C0A0_0 local;  // [G] the frame's one local (size: up to the frame top)
    memset(&local, 0, 160);
    local.field_6C = 0;
    local.field_48 = self->field_329D8;
    local.field_4C = 0x10000;
    local.field_64 = self->field_329F8;
    local.field_9C = 2;
    local.field_68 = 0x3C33608A;
    memcpy(((char *)&local + 0x50), &D_004E19F0, 8);
    local.field_60 = 8;
    local.field_98 = 3;
    local.field_94 = 0;
    memcpy(((char *)&local + 0x74), ((char *)self + 0x9B6C), 6);
    strcpy((char *)((char *)&local + 0x84), (const char *)&D_004BCA40);
    DirtyDnasInit(self->field_329D4, self->field_329F4);
    _dnasexports(&local, 1);
    return 1;
}
