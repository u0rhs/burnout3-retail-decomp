// GtSoundManager.cpp -- translation unit regrouped by tools/tu_merge.py from 7 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtSoundManager.cpp, 4 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundManager.h"
#include "b3/classes/CGtSoundVoiceManager.h"

struct UnkStruct_00385090;

struct UnkStruct_00384EB0 {
    unsigned char pad_0[0x1EE1];
    unsigned char field_1EE1;
};
struct UnkStruct_00384FD0_pad {
    unsigned char field_0[0x4];
    UnkStruct_00384FD0_pad() {}
    ~UnkStruct_00384FD0_pad() {}
};
struct UnkStruct_00384FF0_pad {
    unsigned char field_0[0x4];
    UnkStruct_00384FF0_pad() {}
    ~UnkStruct_00384FF0_pad() {}
};
struct UnkStruct_00385090 {
    unsigned char pad_0[0x1EDC];
    int field_1EDC;
};

extern "C" void PauseAll__20CGtSoundVoiceManagerFv(void *, int);  // CGtSoundVoiceManager::PauseAll(), passed 1 more argument(s) [G]
extern "C" void RwaCoreUpdateFinish();
extern "C" void RwaCoreUpdateStart();
extern "C" bool Prepare__19CGtSoundBankManagerFPv(void *, void *);
extern "C" bool Prepare__21CGtSoundStreamManagerFPvii(void *, void *, int, int);

// IsPaused__15CGtSoundManagerFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00384EB0
extern "C" unsigned char IsPaused__15CGtSoundManagerFv(UnkStruct_00384EB0 *self)
{
    return self->field_1EE1;
}

// CGtSoundManager::Unpause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundManager.cpp.
// 0x00384EC0
void CGtSoundManager::Unpause()
{
    PauseAll__20CGtSoundVoiceManagerFv(((char *)this + 0x5C), 0);
    field_1EA0.PauseAll(0);
    field_1EE1 = 0;
}

// CGtSoundManager::Pause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundManager.cpp.
// 0x00384F00
void CGtSoundManager::Pause()
{
    PauseAll__20CGtSoundVoiceManagerFv(((char *)this + 0x5C), 1);
    field_1EA0.PauseAll(1);
    field_1EE1 = 1;
}

// CGtSoundManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundManager.cpp.
// 0x00384F40
void CGtSoundManager::Destruct()
{
    field_48.Destruct();
    field_5C.Destruct();
    field_8.Destruct();
    field_1EA0.Destruct();
}

// func_00384FD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00384FD0
extern "C" void func_00384FD0(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_00384FD0_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    RwaCoreUpdateFinish();
}

// func_00384FF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00384FF0
extern "C" void func_00384FF0(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_00384FF0_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    RwaCoreUpdateStart();
}

// Prepare__15CGtSoundManagerFPvPvii -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00385090
extern "C" int Prepare__15CGtSoundManagerFPvPvii(UnkStruct_00385090 * self, void *p0, void *p1, int p2, int p3)
{
    switch (self->field_1EDC) {
    default:
        break;
    case 1:
    case 24:
        if (Prepare__19CGtSoundBankManagerFPv((char *)self + 0x8, p0) == 0) {
            break;
        }
        self->field_1EDC = 2;
    case 2:
        if (Prepare__21CGtSoundStreamManagerFPvii((char *)self + 0x1EA0, (void *)(p1), p2, p3) == 0) {
            break;
        }
        self->field_1EDC = 23;
    case 23:
        return 1;
    }
    return 0;
}
