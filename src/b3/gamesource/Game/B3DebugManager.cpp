// B3DebugManager.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3DebugManager.cpp.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4DebugManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3AIDebug.h"
#include "b3/classes/CB3DebugManager.h"
#include "b3/classes/CB3DebugMipMaps.h"
#include "b3/classes/CB3PhysicsManagerDebug.h"
#include "b3/classes/CB3TrafficDebug.h"

struct UnkStruct_00130A00;
struct UnkStruct_00130980;

struct UnkStruct_00130A00 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
};

struct UnkStruct_00130980 {
    unsigned char pad_0[0x10];
    CB3AIDebug field_10;
    unsigned char pad_11[0x6FF];
    CB3PhysicsManagerDebug field_710;
    unsigned char pad_711[0x1EDF];
    CB3TrafficDebug field_25F0;
};

// func_00130970 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130970
extern "C" void func_00130970()
{
}

// Destruct__15CB3DebugManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130980
extern "C" void Destruct__15CB3DebugManagerFv(UnkStruct_00130980 * self)
{
    self->field_10.Destruct();
    self->field_710.Destruct();
    self->field_25F0.Destruct();
    CB3DebugMipMaps::Destruct();
}

// UpdateStartOfFrame__15CB3DebugManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130A00
extern "C" void UpdateStartOfFrame__15CB3DebugManagerFv(UnkStruct_00130A00 * self)
{
    if (CB3DebugManager::gmbRequestStopAll != 0) {
        self->field_2 = 1;
        self->field_3 = 1;
        self->field_0 = 0;
        self->field_1 = 0;
    }
    if (CB3DebugManager::gmbRequestStopUpdate != 0) {
        self->field_2 = 1;
        self->field_0 = 0;
    }
    if (CB3DebugManager::gmbRequestPlayAll != 0) {
        self->field_2 = 0;
        self->field_3 = 0;
        self->field_0 = 1;
        self->field_1 = 1;
    }
    if (CB3DebugManager::gmbRequestPlayCameras != 0) {
        self->field_3 = 0;
        self->field_1 = 1;
    }
    if (self->field_2 != 0) {
        if (CB3DebugManager::gmbRequestStepAll != 0) {
            self->field_0 = 1;
            CB3DebugManager::gmbRequestStepCameras = 1;
        } else {
            self->field_0 = 0;
            CB3DebugManager::gmbRequestStepCameras = 0;
        }
    }
    if (self->field_3 != 0) {
        if (CB3DebugManager::gmbRequestStepCameras != 0) {
            self->field_1 = 1;
        } else {
            self->field_1 = 0;
        }
    }
    CB3DebugManager::gmbRequestStopAll = 0;
    CB3DebugManager::gmbRequestStopUpdate = 0;
    CB3DebugManager::gmbRequestStepAll = 0;
    CB3DebugManager::gmbRequestStepCameras = 0;
    CB3DebugManager::gmbRequestPlayAll = 0;
    CB3DebugManager::gmbRequestPlayCameras = 0;
}
