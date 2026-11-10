// B3SoundHUDManager.cpp -- translation unit regrouped by tools/tu_merge.py from 9 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3SoundHUDManager.cpp, 3 by a medium-confidence name confirmed by a neighbour, 4 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Sound/Hud, [L] Revenge (SLUS_212.42) GameSource/Sound/Hud/B4SoundHUDManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E06A8.h"
#include "b3/classes/UnkStruct_D_004E08B0.h"
#include "b3/classes/UnkStruct_D_004E0AAC.h"
#include "b3/classes/UnkStruct_D_004E0B14.h"

struct UnkStruct_002854A0;
struct UnkStruct_002854E0;
struct UnkStruct_00285520;
struct UnkStruct_002859F0;

struct UnkStruct_002854A0 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

struct UnkStruct_002854E0 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

struct UnkStruct_00285520 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

struct UnkStruct_002859F0 {
    unsigned char pad_0[0x6C];
    unsigned char field_6C;
};

extern UnkStruct_D_004E0B14 D_004E0B14;
extern UnkStruct_D_004E08B0 D_004E08B0;
extern UnkStruct_D_004E06A8 D_004E06A8;
extern UnkStruct_D_004E0AAC D_004E0AAC;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// CB3HUDSoundManager::FEBack() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// 0x002852A0
void CB3HUDSoundManager::FEBack()
{
    if (field_12 != 0) return;
    field_12 = 1;
    if (field_0 != 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0x53706B33CF000000, (const CGtSoundBank*)field_78, D_004E0B14.field_0, 1.0f, 1, 0.0f);
    } else {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0x53706B33CF000000, (const CGtSoundBank*)field_7C, D_004E0B14.field_0, 1.0f, 0, 0.0f);
    }
}

// CB3HUDSoundManager::FESelect() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// 0x00285340
void CB3HUDSoundManager::FESelect()
{
    if (field_11 != 0) return;
    field_11 = 1;
    if (field_0 != 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0xB701A7E2A9E00000, 0, D_004E08B0.field_0, 1.0f, 1, 0.0f);
    } else {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0xB701A7E2A9E00000, 0, D_004E08B0.field_0, 1.0f, 0, 0.0f);
    }
}

// CB3HUDSoundManager::FEVerticalMove() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// 0x002853F0
void CB3HUDSoundManager::FEVerticalMove()
{
    if (field_10 != 0) return;
    field_10 = 1;
    if (field_0 != 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0xC87DF1D0C73E0000, (const CGtSoundBank*)field_78, D_004E06A8.field_0, 1.0f, 1, 0.0f);
    } else {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0xC87DF1D0C73E0000, (const CGtSoundBank*)field_7C, D_004E06A8.field_0, 1.0f, 0, 0.0f);
    }
}

// FEKeyboardSel__18CB3HUDSoundManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002854A0
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(UnkStruct_002854A0 * self)
{
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x88077E0F66D38000, (const CGtSoundBank*)self->field_7C, D_004E0AAC.field_0, 1.0f, 0, 0.0f);
}

// FEKeyboardMove__18CB3HUDSoundManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002854E0
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(UnkStruct_002854E0 * self)
{
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x880224A458A40000, (const CGtSoundBank*)self->field_7C, D_004E0AAC.field_0, 1.0f, 0, 0.0f);
}

// FEKeyboardDel__18CB3HUDSoundManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00285520
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(UnkStruct_00285520 * self)
{
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x87F985B778000000, (const CGtSoundBank*)self->field_7C, D_004E0AAC.field_0, 1.0f, 0, 0.0f);
}

// func_002859F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002859F0
extern "C" void func_002859F0(UnkStruct_002859F0 * self)
{
    if (self->field_6C == 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x5B5CED8476000000, 0, 0.25f, 1.0f, 0, 0.0f);
        self->field_6C = 2;
    }
}

// CB3HUDSoundManager::GeneralPopup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// 0x00285BC0
void CB3HUDSoundManager::GeneralPopup()
{
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(this, 0x79477E7C94566800, (const CGtSoundBank*)field_78, field_20, 1.0f, 0, 0.0f);
}

// CB3HUDSoundManager::FEOnlineUpdatePlayersInGame(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// 0x002870C0
void CB3HUDSoundManager::FEOnlineUpdatePlayersInGame(int p0)
{
    field_70 = p0;
}
