// func_003F0CE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2F10.h"
#include "b3/classes/UnkStruct_D_004E2F18.h"
#include "b3/classes/UnkStruct_D_004E2F20.h"
#include "b3/classes/UnkStruct_D_004E2F28.h"
#include "b3/classes/UnkStruct_D_004E2F30.h"
#include "b3/classes/UnkStruct_D_01E8F940.h"
#include "b3/classes/UnkStruct_D_01E8F94A.h"
#include "b3/classes/UnkStruct_D_01EB5CF0.h"

struct UnkStruct_003F0CE0_2;

struct UnkStruct_003F0CE0_2 {
    int field_0;
};

extern UnkStruct_D_01E8F94A D_01E8F94A;
extern UnkStruct_D_01E8F940 D_01E8F940;
extern UnkStruct_D_004E2F10 D_004E2F10;
extern UnkStruct_D_004E2F18 D_004E2F18;
extern UnkStruct_D_004E2F20 D_004E2F20;
extern UnkStruct_D_01EB5CF0 D_01EB5CF0;
extern UnkStruct_D_004E2F28 D_004E2F28;
extern UnkStruct_D_004E2F30 D_004E2F30;
extern "C" int func_00456780(void *, UnkStruct_003F0CE0_2 *, void *, void *, void *, void *, void *, void *, int);

// 0x003F0CE0
extern "C" void func_003F0CE0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    UnkStruct_003F0CE0_2 local;  // [G] the frame's one local (size: up to the frame top)
    if (D_01E8F94A.field_0 != 0) {
        ((UnkStruct_D_01E8F940 *)&D_01E8F940)->vfunc_C();
    } else {
    }
    switch (p0) {
    case 0:
        local.field_0 = 138;
        func_00456780(&D_01E8F940, &local, &D_004E2F10, &D_004E2F18, &D_004E2F20, &D_01EB5CF0, &D_004E2F28, &D_004E2F30, 1);
        break;
    case 1:
        local.field_0 = 139;
        func_00456780(&D_01E8F940, &local, &D_004E2F10, &D_004E2F18, &D_004E2F20, &D_01EB5CF0, &D_004E2F28, &D_004E2F30, 1);
        break;
    case 2:
        local.field_0 = 140;
        func_00456780(&D_01E8F940, &local, &D_004E2F10, &D_004E2F18, &D_004E2F20, &D_01EB5CF0, &D_004E2F28, &D_004E2F30, 1);
        break;
    case 3:
        local.field_0 = 141;
        func_00456780(&D_01E8F940, &local, &D_004E2F10, &D_004E2F18, &D_004E2F20, &D_01EB5CF0, &D_004E2F28, &D_004E2F30, 1);
        break;
    case 4:
        local.field_0 = 142;
        func_00456780(&D_01E8F940, &local, &D_004E2F10, &D_004E2F18, &D_004E2F20, &D_01EB5CF0, &D_004E2F28, &D_004E2F30, 1);
        break;
    }
}
