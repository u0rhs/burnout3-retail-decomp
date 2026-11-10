// func_00436880 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuFlowFSM.h"
#include "b3/classes/UnkStruct_D_01ECD584.h"

struct UnkStruct_00436880;

struct UnkStruct_00436880 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01ECD584 D_01ECD584;
extern CB3MenuFlowFSM D_01EA2970;
extern "C" void func_004365B0(UnkStruct_00436880 *, int);

// 0x00436880
extern "C" void func_00436880(UnkStruct_00436880 * self, int p0, int p1)
{
    switch (self->field_4) {
    case 0:
        switch (p0) {
        case 49:
            func_004365B0(self, 1);
            self->field_4 = 1;
            break;
        case 46:
        case 50:
            D_01EA2970.ApplyEvent(1, 0);
            break;
        case 56:
        case 57:
            int t0 = D_01ECD584.field_0;
            int v0 = (t0 / 1024);
            if (v0 < 94) {
                func_004365B0(self, 3);
                self->field_4 = 2;
            } else {
                D_01EA2970.ApplyEvent(1, 0);
            }
            break;
        case 58:
            func_004365B0(self, 4);
            self->field_4 = 3;
            break;
        case 47:
            func_004365B0(self, 2);
            self->field_4 = 2;
            break;
        }
        break;
    case 1:
        switch (p0) {
        case 46:
        case 50:
        case 56:
        case 57:
            D_01EA2970.ApplyEvent(1, 0);
            break;
        case 47:
            func_004365B0(self, 2);
            self->field_4 = 2;
            break;
        case 58:
            func_004365B0(self, 4);
            self->field_4 = 3;
            break;
        }
        break;
    case 2:
        switch (p0) {
        case 46:
        case 50:
        case 56:
        case 57:
            D_01EA2970.ApplyEvent(1, 0);
            break;
        case 49:
            func_004365B0(self, 1);
            self->field_4 = 1;
            break;
        case 58:
            func_004365B0(self, 4);
            self->field_4 = 3;
            break;
        }
        break;
    }
}
