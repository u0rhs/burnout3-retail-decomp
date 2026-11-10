// func_0033A600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004C5968.h"
#include "b3/classes/UnkStruct_D_004C5AA8.h"
#include "b3/classes/UnkStruct_D_004C5AB8.h"

struct UnkStruct_0033A600;
struct UnkStruct_0033A600_a3;

struct UnkStruct_0033A600_a3 {
    int field_0;
};

struct UnkStruct_0033A600 {
    unsigned char pad_0[0x104];
    int field_104;
};

extern UnkStruct_D_004C5AA8 D_004C5AA8;
extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_D_004C5AB8 D_004C5AB8;
extern "C" int LobbyApiInfoPtr(int, int);
extern "C" int TagFieldFind(int, void *);
extern "C" void TagFieldGetString(int, int, int, void *);
extern "C" int TagFieldGetNumber(int, int);

// 0x0033A600
extern "C" void func_0033A600(UnkStruct_0033A600 * self, void *p0_, int p1, UnkStruct_0033A600_a3 * p2)
{
    int p0 = (int)p0_;
    int r0 = LobbyApiInfoPtr(self->field_104, 0x636F6E66);
    int r1 = TagFieldFind(r0, &D_004C5AA8);
    TagFieldGetString(r1, p0, p1, &D_004C5968);
    int r3 = TagFieldFind(r0, &D_004C5AB8);
    int r4 = TagFieldGetNumber(r3, -1);
    p2->field_0 = r4;
}
