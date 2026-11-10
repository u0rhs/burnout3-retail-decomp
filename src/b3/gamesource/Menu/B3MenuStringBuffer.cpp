// B3MenuStringBuffer.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3MenuStringBuffer.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Menu, [L] Revenge (SLUS_212.42) GameSource/Menu/B4MenuStringBuffer.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MenuStringBuffer.h"

struct UnkStruct_003B88E0;
struct UnkStruct_003B88E0_e0;

struct UnkStruct_003B88E0_e0 {
    unsigned char pad_0[0x2];
};

struct UnkStruct_003B88E0 {
    unsigned char pad_0[0x1800];
    UnkStruct_003B88E0_e0 * field_1800;
};

extern "C" void * memset(void *, int, unsigned int);

// AllocUTF16String__19CB3MenuStringBufferFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003B88E0
extern "C" UnkStruct_003B88E0_e0 * AllocUTF16String__19CB3MenuStringBufferFi(UnkStruct_003B88E0 * self, int p0)
{
    UnkStruct_003B88E0_e0 * t0 = self->field_1800;
    self->field_1800 = (UnkStruct_003B88E0_e0 *)&t0[p0];
    return t0;
}

// CB3MenuStringBuffer::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuStringBuffer.cpp.
// 0x003B8900
int CB3MenuStringBuffer::Prepare()
{
    field_1800 = (void *)this;
    memset(this, 0, 6144);
    return 1;
}
