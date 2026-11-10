// func_004242C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_0051BA39.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_004242C0;
struct UnkStruct_004242C0_e2;

struct UnkStruct_004242C0_e2 {
    unsigned char pad_0[0x4];
    int field_4[1];  // [G] element count unknown
    unsigned char pad_8[0x6C];
};

struct UnkStruct_004242C0 {
    unsigned char pad_0[0x4];
    int field_4[1];  // [G] element count unknown
    unsigned char pad_8[0x6C];
    UnkStruct_004242C0_e2 field_74[1];  // [G] element count unknown
    unsigned char pad_E8[0x78];
    int field_160[1];  // [G] element count unknown
    unsigned char pad_164[0x4];
    int field_168[1];  // [G] element count unknown
    unsigned char pad_16C[0x4];
    float field_170;
    unsigned char field_174;
    unsigned char field_175;
    unsigned char field_176;
    unsigned char field_177;
    unsigned char field_178;
    unsigned char field_179;
};

extern UnkStruct_D_0051BA39 D_0051BA39;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_00131CA0(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00131D90(void *);
extern "C" int func_00271A00(void *, int);
extern "C" bool func_0031BF40(void *, void *, void *);

// 0x004242C0
extern "C" int func_004242C0(UnkStruct_004242C0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int r1 = func_00131CA0(&D_004EE040);
    self->field_178 = r1;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)8);
    func_0031ECD0(&D_01E89800, 16, 3);
    D_01E894FC.Prepare();
    int r5 = func_00131D90(&D_004EE040);
    int v1;
    if (r5 != 0) {
        v1 = D_0051BA39.field_0;
    } else {
        v1 = 0;
    }
    if (self->field_178 != 0) {
        int r6 = func_00271A00(&D_0051BA44, ((v1 << 1) + 778));
        int r7 = func_00271A00(&D_0051BA44, ((v1 << 1) + 777));
        func_0031BF40(&D_01E89788, (void *)(r7), (void *)(r6));
    } else {
        int r9 = func_00271A00(&D_0051BA44, (v1 + 777));
        func_0031BF40(&D_01E89788, (void *)(r9), (void *)(0));
    }
    self->field_170 = -1.0f;
    self->field_176 = 0;
    self->field_177 = 0;
    self->field_179 = 0;
    for (int i = 0; (i < 2); i++) {
        self->field_160[i] = 0;
        self->field_168[i] = 0;
        for (int i1 = 0; (i1 < 29); i1++) {
            self->field_74[i].field_4[i1] = 0;
        }
    }
    for (int i2 = 0; (i2 < 29); i2++) {
        self->field_4[i2] = 21;
    }
    self->field_175 = 0;
    self->field_174 = 0;
    return 1;
}
