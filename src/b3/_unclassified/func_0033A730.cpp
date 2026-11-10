// func_0033A730 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004C5968.h"
#include "b3/classes/UnkStruct_D_004C5AC8.h"

struct UnkStruct_0033A730;
struct UnkStruct_0033A730_1;

struct UnkStruct_0033A730_1 {
    unsigned char pad_0[0x80];
};

struct UnkStruct_0033A730 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x52C];
    int field_634;
};

extern UnkStruct_D_004C5AC8 D_004C5AC8;
extern UnkStruct_D_004C5968 D_004C5968;
extern "C" int LobbyApiInfoPtr(int, int);
extern "C" int TagFieldFind(int, void *);
extern "C" void TagFieldGetString(int, UnkStruct_0033A730_1 *, int, void *);
extern "C" int snprintf(int, int, UnkStruct_0033A730_1 *, int);

// 0x0033A730
extern "C" int func_0033A730(UnkStruct_0033A730 * self, void *p0_, int p1)
{
    int p0 = (int)p0_;
    UnkStruct_0033A730_1 local;  // [G] the frame's one local (size: up to the frame top)
    int r0 = LobbyApiInfoPtr(self->field_104, 0x636F6E66);
    int r1 = TagFieldFind(r0, &D_004C5AC8);
    TagFieldGetString(r1, &local, 128, &D_004C5968);
    return snprintf(p0, p1, &local, self->field_634);
}
