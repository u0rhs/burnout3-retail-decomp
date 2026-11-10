// B3BehaviourEffect.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3BehaviourEffect.cpp, 2 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Camera/Behaviours, [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourEffect.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BehaviourEffect.h"
#include "b3/classes/CB3CameraBehaviour.h"
#include "b3/classes/CB3PlayerCameraManager.h"
#include "b3/classes/UnkStruct_D_004A4AA4.h"
#include "b3/classes/UnkStruct_D_004A4B24.h"
#include "b3/classes/UnkStruct_D_004E1D24.h"

struct UnkStruct_0032ED50;
struct UnkStruct_0032EC90;

struct UnkStruct_0032ED30 {
    unsigned char pad_0[0x8];
    CB3PlayerCameraManager * field_8;
    unsigned char pad_C[0xC];
    int field_18;
    int field_1C;
};

struct UnkStruct_0032ED50 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0xC];
    int field_18;
    int field_1C;
};

struct UnkStruct_0032EC90 {
    unsigned char pad_0[0xC];
    float field_C;
    float field_10;
    float field_14;
    int field_18;
};

extern UnkStruct_D_004E1D24 D_004E1D24;
extern UnkStruct_D_004A4AA4 D_004A4AA4;
extern UnkStruct_D_004A4B24 D_004A4B24;
extern "C" void Construct__18CB3CameraBehaviourFv(void *);  // CB3CameraBehaviour::Construct()

// CB3BehaviourEffect::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourEffect.cpp.
// 0x0032D1E0
void CB3BehaviourEffect::Destruct()
{
}

// CB3BehaviourEffect::Release(void*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourEffect.cpp.
// 0x0032D1F0
void CB3BehaviourEffect::Release(void* p0)
{
}

// func_0032EC90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0032EC90
extern "C" int func_0032EC90(UnkStruct_0032EC90 * self)
{
    self->field_C = 0.0f;
    switch (self->field_18) {
    case 0:
        self->field_10 = D_004E1D24.field_0;
        self->field_14 = 1.0f;
        break;
    case 1:
        self->field_10 = D_004A4AA4.field_0;
        self->field_14 = 1.0f;
        break;
    case 2:
        self->field_10 = -1.0f;
        self->field_14 = 0.0f;
        break;
    case 3:
        self->field_10 = D_004A4B24.field_0;
        self->field_14 = 1.0f;
        break;
    }
    return 1;
}

// func_0032ED30 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0032ED30
extern "C" void func_0032ED30(UnkStruct_0032ED30 *self, int p0, int p1)
{
    self->field_18 = p0;
    self->field_1C = p1;
    self->field_8->ActivateBehaviour(15);
}

// Construct__18CB3BehaviourEffectFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0032ED50
extern "C" void Construct__18CB3BehaviourEffectFv(UnkStruct_0032ED50 * self)
{
    Construct__18CB3CameraBehaviourFv(self);
    self->field_8 = 0;
    self->field_18 = 2;
    self->field_1C = 0;
}

// CB3BehaviourEffect::Construct(CB3PlayerCameraManager*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourEffect.cpp.
// 0x0032ED90
void CB3BehaviourEffect::Construct(CB3PlayerCameraManager* p0)
{
    Construct__18CB3CameraBehaviourFv(this);
    field_8 = (CB3PlayerCameraManager *)p0;
}
