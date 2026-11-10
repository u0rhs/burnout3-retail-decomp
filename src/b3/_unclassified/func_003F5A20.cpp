// func_003F5A20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (returns CGtV2d by value (hidden result ptr): named local r(x, y); one 6-byte short table).

// func_003F5A20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths). [G] returns an 8-byte CGtV2d by value (hidden result pointer in a0).

#include "b3/GtMathPs2.h"

struct UnkStruct_003F5A20_e0 {
    short field_0;
    short field_2;
    short field_4;
};

extern UnkStruct_003F5A20_e0 D_004CE2E0[];

// 0x003F5A20
extern "C" GtMathPs2::CGtV2d func_003F5A20(int p0, int p1)
{
    int v0;
    switch (p0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    GtMathPs2::CGtV2d r(D_004CE2E0[p1 + v0].field_0, D_004CE2E0[p1 + v0].field_2);
    return r;
}
