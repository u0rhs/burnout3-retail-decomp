// GtSoundStreamManager.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> GtSoundStreamManager.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundStreamManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundStream.h"
#include "b3/classes/CGtSoundStreamManager.h"

struct UnkStruct_003869D0_1;
struct UnkStruct_00386A10_1;
struct UnkStruct_00386C50_1;
struct UnkStruct_00386C90;
struct UnkStruct_00386CB0_1;
struct UnkStruct_00386CF0;
struct UnkStruct_00386CF0_e0;
struct UnkStruct_00386CF0_e1;

struct UnkStruct_003869D0_1 {
    int field_0;
};

struct UnkStruct_00386A10_1 {
    int field_0;
};

struct UnkStruct_00386C50_1 {
    int field_0;
};

struct UnkStruct_00386C90 {
    unsigned char pad_0[0x1C];
    int field_1C;
    unsigned char pad_20[0x4];
    int field_24;
};

struct UnkStruct_00386CB0_1 {
    int field_0;
};

struct UnkStruct_00386CF0_e0 {
    int field_0;
    unsigned char field_4;
    unsigned char pad_5[0x3];
};

struct UnkStruct_00386CF0_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00386CF0 {
    unsigned char pad_0[0x1C];
    int field_1C;
    int field_20;
    UnkStruct_00386CF0_e0 * field_24;
    int field_28;
};

extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" void Pause__14CGtSoundStreamFb(void *, bool);  // CGtSoundStream::Pause(bool)
extern "C" void Destruct__14CGtSoundStreamFv(void *);  // CGtSoundStream::Destruct()
extern "C" void * memset(void *, int, unsigned int);
extern "C" void Update__14CGtSoundStreamFv(void *);  // CGtSoundStream::Update()

// CGtSoundStreamManager::StopAll() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStreamManager.cpp.
// 0x003869D0
void CGtSoundStreamManager::StopAll()
{
    UnkStruct_003869D0_1 * m0 = (UnkStruct_003869D0_1 *)field_18;
    while (m0 != 0) {
        Stop__14CGtSoundStreamFv(((char *)m0 + 0x8));
        m0 = (UnkStruct_003869D0_1 *)m0->field_0;
    }
}

// CGtSoundStreamManager::PauseAll(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStreamManager.cpp.
// 0x00386A10
void CGtSoundStreamManager::PauseAll(bool p0)
{
    UnkStruct_00386A10_1 * m0 = (UnkStruct_00386A10_1 *)field_18;
    while (m0 != 0) {
        Pause__14CGtSoundStreamFb(((char *)m0 + 0x8), p0);
        m0 = (UnkStruct_00386A10_1 *)m0->field_0;
    }
}

// CGtSoundStreamManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStreamManager.cpp.
// 0x00386C50
void CGtSoundStreamManager::Destruct()
{
    UnkStruct_00386C50_1 * m0 = (UnkStruct_00386C50_1 *)field_18;
    while (m0 != 0) {
        Destruct__14CGtSoundStreamFv(((char *)m0 + 0x8));
        m0 = (UnkStruct_00386C50_1 *)m0->field_0;
    }
}

// func_00386C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386C90
extern "C" void func_00386C90(UnkStruct_00386C90 * self)
{
    memset((void *)self->field_24, 0, (self->field_1C << 3));
}

// CGtSoundStreamManager::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStreamManager.cpp.
// 0x00386CB0
void CGtSoundStreamManager::Update()
{
    UnkStruct_00386CB0_1 * m0 = (UnkStruct_00386CB0_1 *)field_18;
    while (m0 != 0) {
        Update__14CGtSoundStreamFv(((char *)m0 + 0x8));
        m0 = (UnkStruct_00386CB0_1 *)m0->field_0;
    }
}

// Prepare__21CGtSoundStreamManagerFPvii -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386CF0
extern "C" int Prepare__21CGtSoundStreamManagerFPvii(UnkStruct_00386CF0 * self, UnkStruct_00386CF0_e1 * p0, int p1, int p2)
{
    self->field_28 = (int)p0;
    self->field_20 = p2;
    int i;
    int m0 = 0;
    for (i = 0; i < self->field_1C; i++) {
        self->field_24[i].field_0 = (int)&p0[m0];
        self->field_24[i].field_4 = 0;
        m0 = (m0 + p2);
    }
    return 1;
}
