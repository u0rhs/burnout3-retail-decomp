// func_00382CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004C9530.h"
#include "b3/classes/UnkStruct_D_004C95C0.h"
#include "b3/classes/UnkStruct_D_004C9620.h"
#include "b3/classes/UnkStruct_D_004C9680.h"
#include "b3/classes/UnkStruct_D_01EA49A0.h"
#include "b3/classes/UnkStruct_D_01EA4A50.h"

struct UnkStruct_00382CF0_0;

struct UnkStruct_00382CF0_0 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned long field_18;
    unsigned long field_20;
    unsigned long field_28;
    unsigned long field_30;
    unsigned long field_38;
    unsigned long field_40;
    unsigned long field_48;
    unsigned long field_50;
    unsigned long field_58;
};

extern UnkStruct_D_004C95C0 D_004C95C0;
extern UnkStruct_D_004C9530 D_004C9530;
extern UnkStruct_D_01EA49A0 D_01EA49A0;
extern UnkStruct_D_004C9680 D_004C9680;
extern UnkStruct_D_004C9620 D_004C9620;
extern UnkStruct_D_01EA4A50 D_01EA4A50;
extern "C" void _CalculateUV__15CB3MenuImageUVsFffffffUi(void *, float, float, float, float, float, float, unsigned int);  // CB3MenuImageUVs::_CalculateUV(float,float,float,float,float,float,unsigned int)

// 0x00382CF0
extern "C" void func_00382CF0()
{
    UnkStruct_00382CF0_0 local;  // [G] the frame's one local (size: up to the frame top)
    for (int i = 0; (i < 11); i++) {
        if (i != 5) {
            if (i == 8) {
                _CalculateUV__15CB3MenuImageUVsFffffffUi(((char *)&local + 0x30), D_004C95C0.field_0[i].field_0, D_004C95C0.field_0[i].field_4, D_004C9530.field_0[i].field_0, D_004C9530.field_0[i].field_4, 64.0f, 32.0f, 0);
                unsigned long t0 = local.field_38;
                D_01EA49A0.field_0[i].field_0 = local.field_30;
                D_01EA49A0.field_0[i].field_8 = t0;
                _CalculateUV__15CB3MenuImageUVsFffffffUi(((char *)&local + 0x20), D_004C9680.field_0[i].field_0, D_004C9680.field_0[i].field_4, D_004C9620.field_0[i].field_0, D_004C9620.field_0[i].field_4, 64.0f, 32.0f, 0);
                unsigned long t1 = local.field_28;
                D_01EA4A50.field_0[i].field_0 = local.field_20;
                D_01EA4A50.field_0[i].field_8 = t1;
            } else {
                _CalculateUV__15CB3MenuImageUVsFffffffUi(((char *)&local + 0x10), D_004C95C0.field_0[i].field_0, D_004C95C0.field_0[i].field_4, D_004C9530.field_0[i].field_0, D_004C9530.field_0[i].field_4, 128.0f, 64.0f, 0);
                unsigned long t2 = local.field_18;
                D_01EA49A0.field_0[i].field_0 = local.field_10;
                D_01EA49A0.field_0[i].field_8 = t2;
                _CalculateUV__15CB3MenuImageUVsFffffffUi(&local, D_004C9680.field_0[i].field_0, D_004C9680.field_0[i].field_4, D_004C9620.field_0[i].field_0, D_004C9620.field_0[i].field_4, 128.0f, 64.0f, 0);
                unsigned long t3 = local.field_8;
                D_01EA4A50.field_0[i].field_0 = local.field_0;
                D_01EA4A50.field_0[i].field_8 = t3;
            }
        } else {
            _CalculateUV__15CB3MenuImageUVsFffffffUi(((char *)&local + 0x50), D_004C95C0.field_0[i].field_0, D_004C95C0.field_0[i].field_4, D_004C9530.field_0[i].field_0, D_004C9530.field_0[i].field_4, 64.0f, 32.0f, 0);
            unsigned long t4 = local.field_58;
            D_01EA49A0.field_0[i].field_0 = local.field_50;
            D_01EA49A0.field_0[i].field_8 = t4;
            _CalculateUV__15CB3MenuImageUVsFffffffUi(((char *)&local + 0x40), D_004C9680.field_0[i].field_0, D_004C9680.field_0[i].field_4, D_004C9620.field_0[i].field_0, D_004C9620.field_0[i].field_4, 64.0f, 32.0f, 0);
            unsigned long t5 = local.field_48;
            D_01EA4A50.field_0[i].field_0 = local.field_40;
            D_01EA4A50.field_0[i].field_8 = t5;
        }
    }
}
