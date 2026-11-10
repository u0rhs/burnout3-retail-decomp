// GtSoundBankManager.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtSoundBankManager.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundBankManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundBankManager.h"

struct UnkStruct_00384330;
struct UnkStruct_00384330_e0;
struct UnkStruct_00384400_1;
struct UnkStruct_00384380;
struct UnkStruct_00384380_e0;

struct UnkStruct_00384330_e0 {
    int field_0;
    unsigned char pad_4[0x4];
    unsigned char field_8;
    unsigned char pad_9[0x3];
};

struct UnkStruct_00384330 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00384330_e0 * field_C;
    unsigned char pad_10[0x8];
    int field_18;
};

struct UnkStruct_00384400_1 {
    int field_0;
};

struct UnkStruct_00384380_e0 {
    int field_0;
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[0x3];
};

struct UnkStruct_00384380 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00384380_e0 * field_C;
    unsigned char pad_10[0x8];
    int field_18;
};

extern "C" void Destruct__12CGtSoundBankFv(void *);  // CGtSoundBank::Destruct()
extern "C" void RwaWaveDictLoaderDestroy(int);

// CGtSoundBankManager::Update() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBankManager.cpp.
// 0x00384320
void CGtSoundBankManager::Update()
{
}

// func_00384330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00384330
extern "C" void func_00384330(UnkStruct_00384330 * self)
{
    for (int i = 0; (i < self->field_18); i++) {
        self->field_C[i].field_0 = 0;
        self->field_C[i].field_8 = 0;
    }
    self->field_8 = 0;
}

// Prepare__19CGtSoundBankManagerFPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00384380
extern "C" int Prepare__19CGtSoundBankManagerFPv(UnkStruct_00384380 * self, void *p0_)
{
    int p0 = (int)p0_;
    int i;
    if (self->field_8 == 0) {
        self->field_8 = p0;
    }
    int m0 = self->field_8;
    for (i = 0; (i < self->field_18); i++) {
        self->field_C[i].field_8 = 0;
        self->field_C[i].field_0 = m0;
        m0 = (m0 + self->field_C[i].field_4);
    }
    return 1;
}

// CGtSoundBankManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBankManager.cpp.
// 0x00384400
void CGtSoundBankManager::Destruct()
{
    UnkStruct_00384400_1 * m0 = (UnkStruct_00384400_1 *)field_38;
    while (m0 != 0) {
        Destruct__12CGtSoundBankFv(((char *)m0 + 0x8));
        m0 = (UnkStruct_00384400_1 *)m0->field_0;
    }
    RwaWaveDictLoaderDestroy(field_0);
}
