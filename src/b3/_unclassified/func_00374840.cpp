// Action__26CB3PlayerCameraStateEditorF14EGtStateActionPvPvPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3CameraEditor.h"
#include "b3/classes/CB3EditorParams.h"
#include "b3/classes/UnkStruct_D_0051BAC8.h"
#include "b3/classes/UnkStruct_D_01E86530.h"

struct UnkStruct_00374840;
struct UnkStruct_00374840_a3;

struct UnkStruct_00374840_a3 {
    unsigned long field_0;
};

struct UnkStruct_00374840 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
};

extern UnkStruct_D_01E86530 D_01E86530;
extern UnkStruct_D_0051BAC8 D_0051BAC8;
extern CB3CameraEditor D_01E86500;
extern "C" void func_004471A0(int, float);

// 0x00374840
extern "C" void Action__26CB3PlayerCameraStateEditorF14EGtStateActionPvPvPv(UnkStruct_00374840 * self, int p0, int p1, UnkStruct_00374840_a3 * p2, int p3)
{
    switch (p0) {
    case 3:
        self->field_10 = p2->field_0;
        D_01E86500.Prepare((CB3EditorParams*)p3);
        break;
    case 4:
        if ((unsigned int)(D_01E86530.field_0 + -2) < (unsigned int)2) {
            func_004471A0((p1 + 80), D_0051BAC8.field_0);
            return;
        }
        D_01E86500.Update();
        break;
    case 2:
        D_01E86500.Release();
        break;
    case 1:
        break;
    default:
        break;
    }
}
