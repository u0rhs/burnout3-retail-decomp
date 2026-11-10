// B3AICarPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3AICarPhysics.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4AICarPhysics.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_D_00522680.h"

struct UnkStruct_001D17B0;
struct UnkStruct_001D28C0;

struct UnkStruct_001D17B0 {
    unsigned char pad_0[0x1570];
    float field_1570;
};

struct UnkStruct_001D28C0 {
    unsigned char pad_0[0x1400];
    float field_1400;
    float field_1404;
    unsigned char pad_1408[0xC];
    int field_1414;
    unsigned char pad_1418[0xB0];
    int field_14C8;
    unsigned char pad_14CC[0xA4];
    float field_1570;
};

struct UnkStruct_001D2D10 {
    unsigned char pad_0[0x215];
    unsigned char field_215;
};

extern UnkStruct_D_00522680 D_00522680;
extern int _gnAIPhysicsMonitorID;
extern unsigned char _gbRegistered;
extern "C" void func_001C6EF0(void *);

// func_001D17B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D17B0
extern "C" void func_001D17B0(UnkStruct_001D17B0 * self, float f0)
{
    self->field_1570 = (f0 + D_00522680.field_0);
}

// func_001D28C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D28C0
extern "C" void func_001D28C0(UnkStruct_001D28C0 * self, float f0)
{
    float t0 = self->field_1570;
    if (!(-1.0f == t0)) {
        if (!(D_00522680.field_0 < t0)) {
            self->field_1570 = -1.0f;
        }
    }
    int t1 = self->field_14C8;
    if (t1 == -1) {
        self->field_1404 = 0.0f;
        self->field_1400 = f0;
        self->field_1414 = 0;
    } else {
        if (t1 != 0) {
            self->field_1404 = f0;
            self->field_1400 = 0.0f;
            self->field_1414 = 0;
        }
    }
}

// CB3AICarPhysics::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICarPhysics.cpp.
// 0x001D2D10
extern "C" void Construct__15CB3AICarPhysicsFv(UnkStruct_001D2D10 *self)
{
    func_001C6EF0(self);
    self->field_215 = 2;
    if (_gnAIPhysicsMonitorID == -1) {
        _gnAIPhysicsMonitorID = 0;
    }
    if (_gbRegistered == 0) {
        _gbRegistered = 1;
    }
}
