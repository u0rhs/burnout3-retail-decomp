// GtInputDevicePS2DualShock.cpp -- translation unit regrouped by tools/tu_merge.py from 7 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtInputDevicePS2DualShock.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Input/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2DualShock.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtInputDevicePS2DualShock.h"

struct UnkStruct_00217060;
struct UnkStruct_002171D0;

struct UnkStruct_00217060 {
    unsigned char pad_0[0x46];
    unsigned char field_46;
};
struct UnkStruct_002171D0 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char pad_9[0x3C];
    unsigned char field_45;
};
struct UnkStruct_00217200 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char pad_9[0x43 - 0x9];
    unsigned char field_43;
};

// CGtInputDevicePS2DualShock::UnbindFromPort() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// 0x00216FF0
void CGtInputDevicePS2DualShock::UnbindFromPort()
{
    if (field_E4 == 0) return;
    field_E8 = -1;
    field_E4 = 0;
}

// SetPause__26CGtInputDevicePS2DualShockFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00217060
extern "C" void SetPause__26CGtInputDevicePS2DualShockFb(UnkStruct_00217060 * self, int p0)
{
    self->field_46 = ((p0 != 0) ^ 1);
}

// func_002171D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002171D0
extern "C" void func_002171D0(UnkStruct_002171D0 * self, int p0)
{
    if (self->field_8 == 0) return;
    if (p0 != 0) {
        self->field_45 = 1;
    } else {
        self->field_45 = 0;
    }
}

// Hand-written; the lifter refused it (hand-written: bool v range test (0<=f<1) via nested ifs; (unsigned char)(255.0f*f)).
// 0x00217200
extern "C" void func_00217200(UnkStruct_00217200 * self, float f0)
{
    bool v = false;
    if (f0 < 1.0f) {
        if (!(f0 < 0.0f)) {
            v = true;
        }
    }
    if (self->field_8 != 0 && v != false) {
        self->field_43 = (unsigned char)(255.0f * f0);
    }
}

// CGtInputDevicePS2DualShock::GetPort() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// 0x002172B0
int CGtInputDevicePS2DualShock::GetPort()
{
    return field_E8;
}

// CGtInputDevicePS2DualShock::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// 0x00217350
int CGtInputDevicePS2DualShock::Prepare()
{
    unsigned char t0 = field_8;
    if (t0 != 0) {
        if ((t0 & 255) != 0) {
            field_45 = 0;
        }
        if (field_8 != 0) {
            field_43 = 0;
        }
    } else {
        field_42 = 0;
        field_43 = 0;
        field_44 = 0;
        field_45 = 0;
    }
    field_46 = 1;
    for (int i = 0; (i < 28); i++) {
        field_A[i] = 0;
        field_26[i] = 0;
        field_48[i] = 0;
    }
    field_4 = 3;
    return 1;
}

// CGtInputDevicePS2DualShock::IsConnected() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// 0x002173E0
unsigned char CGtInputDevicePS2DualShock::IsConnected()
{
    return field_8;
}
