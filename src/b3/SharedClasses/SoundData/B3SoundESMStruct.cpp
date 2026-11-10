// B3SoundESMStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundESMStruct.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/SharedClasses/SoundData, [L] Revenge (SLUS_212.42) SharedClasses/SoundData/B4SoundESMStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundESMGraphInputs.h"

struct UnkStruct_002FB240;
struct UnkStruct_002FB240_e0;
struct UnkStruct_002FB240_e1;

struct UnkStruct_002FB240_e0 {
    unsigned char pad_0[0x8];
    UnkStruct_002FB240_e1 * field_8;
    unsigned char field_C;
    unsigned char pad_D[0x3];
};

struct UnkStruct_002FB240_e1 {
    void * field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_002FB240 {
    unsigned char pad_0[0x3C];
    UnkStruct_002FB240_e0 * field_3C;
    unsigned char field_40;
};

// CB3SoundESMGraphInputs::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// 0x002FB220
void CB3SoundESMGraphInputs::Construct()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
}

// func_002FB240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002FB240
extern "C" void func_002FB240(UnkStruct_002FB240 * self)
{
    int i;
    int j;
    if (self->field_3C != 0) {
        self->field_3C = (UnkStruct_002FB240_e0 *)((int)self->field_3C + (int)self);
        for (i = 0; i < self->field_40; i++) {
            UnkStruct_002FB240_e0 * e = &self->field_3C[i];
            if (e->field_8 != 0) {
                e->field_8 = (UnkStruct_002FB240_e1 *)((int)e->field_8 + (int)e);
                for (j = 0; j < e->field_C; j++) {
                    UnkStruct_002FB240_e1 * f = &e->field_8[j];
                    if (f->field_0 != 0) {
                        f->field_0 = (void *)((int)f->field_0 + (int)f);
                    }
                }
            }
        }
    }
}
