// func_00220450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (struct assignment D_0067D5A0 = b->field_0 (u_long128[6] -> 3-pass pair loop) through a const base pointer, then the four quads).

#include "b3/GtMathPs2.h"
struct UnkStruct_00220450_c0 { u_long128 field_0[6]; };
struct UnkStruct_D_00666330 { UnkStruct_00220450_c0 field_0; u_long128 field_60; u_long128 field_70; u_long128 field_80; u_long128 field_90; };
struct UnkStruct_D_0067D600 { u_long128 field_0; };
struct UnkStruct_D_0067D610 { u_long128 field_0; };
struct UnkStruct_D_0067D620 { u_long128 field_0; };
struct UnkStruct_D_0067D630 { u_long128 field_0; };
extern UnkStruct_D_00666330 D_00666330;
extern UnkStruct_D_0067D600 D_0067D600;
extern UnkStruct_D_0067D610 D_0067D610;
extern UnkStruct_D_0067D620 D_0067D620;
extern UnkStruct_D_0067D630 D_0067D630;
extern UnkStruct_00220450_c0 D_0067D5A0;
// 0x00220450
extern "C" void func_00220450(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_D_00666330 * const b = &D_00666330;
    D_0067D5A0 = b->field_0;
    D_0067D600.field_0 = b->field_60;
    D_0067D610.field_0 = b->field_70;
    D_0067D620.field_0 = b->field_80;
    D_0067D630.field_0 = b->field_90;
}
