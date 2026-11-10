// GtSoundBank.cpp -- translation unit regrouped by tools/tu_merge.py from 7 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> GtSoundBank.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundBank.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundWave.h"

struct UnkStruct_00383C00;

struct UnkStruct_00383EC0 {
    unsigned char pad_0[0x3AA];
    unsigned char field_3AA;
};

extern "C" void Destruct__12CGtSoundWaveFv(void *);  // CGtSoundWave::Destruct()
extern "C" void RwaWaveDictDestroy(int);

// func_00383C00 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00383C00
extern "C" void * func_00383C00(UnkStruct_00383C00 *self)
{
    return (char *)self + 0x370;
}

// CGtSoundBank::Unload() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// 0x00383C10
void CGtSoundBank::Unload()
{
    if (field_398 != 0) {
        for (int i = 0; (i < field_3A9); i++) {
            Destruct__12CGtSoundWaveFv(&field_0[i]);
        }
        RwaWaveDictDestroy(field_398);
        field_398 = 0;
    }
    field_3A4 = 1;
    field_39C = 0;
}

// CGtSoundBank::IsGlobal() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// 0x00383EB0
unsigned char CGtSoundBank::IsGlobal()
{
    return field_3AA;
}

// func_00383EC0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00383EC0
extern "C" void func_00383EC0(UnkStruct_00383EC0 *self, int p0)
{
    self->field_3AA = (unsigned char)p0;
}

// CGtSoundBank::GetReferenceCount() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// 0x00383ED0
unsigned char CGtSoundBank::GetReferenceCount()
{
    return field_3A8;
}

// CGtSoundBank::SetReferenceCount(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// 0x00383EE0
void CGtSoundBank::SetReferenceCount(int p0)
{
    field_3A8 = (unsigned char)p0;
}

// CGtSoundBank::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// 0x00383EF0
void CGtSoundBank::Destruct()
{
}
