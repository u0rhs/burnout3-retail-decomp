// Construct__20CB3MemCardControllerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CMemoryCardFileBase.h"
#include "b3/classes/UnkStruct_D_004CEB60.h"
#include "b3/classes/UnkStruct_D_004CEB68.h"
#include "b3/classes/UnkStruct_D_004E1F20.h"
#include "b3/classes/UnkStruct_D_004E1F24.h"
#include "b3/classes/UnkStruct_D_004E1F28.h"
#include "b3/classes/UnkStruct_D_004E25DC.h"
#include "b3/classes/UnkStruct_D_004F1040.h"

struct UnkStruct_003FDF90;

struct UnkStruct_003FDF90 {
    unsigned char pad_0[0xC];
    void * field_C;
    int field_10;
    int field_14;
    int field_18;
    void * field_1C;
    void * field_20;
    int field_24;
    int field_28;
    int field_2C;
    void * field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    unsigned char pad_5C[0x10];
    unsigned char field_6C;
    unsigned char field_6D;
    unsigned char field_6E;
    unsigned char field_6F;
    unsigned char pad_70[0x2];
    short field_72;
    unsigned char pad_74[0x8];
    int field_7C[1];  // [G] element count unknown
    unsigned char pad_80[0xC];
    int field_8C[1];  // [G] element count unknown
    unsigned char pad_90[0xC];
    int field_9C[1];  // [G] element count unknown
    unsigned char pad_A0[0xC];
    int field_AC[1];  // [G] element count unknown
    unsigned char pad_B0[0xC];
    int field_BC[1];  // [G] element count unknown
    unsigned char pad_C0[0xC];
    int field_CC[1];  // [G] element count unknown
    unsigned char pad_D0[0xC];
    float field_DC[1];  // [G] element count unknown
    unsigned char pad_E0[0xC];
    float field_EC[1];  // [G] element count unknown
    unsigned char pad_F0[0xC];
    float field_FC[1];  // [G] element count unknown
    unsigned char pad_100[0xC];
    float field_10C[1];  // [G] element count unknown
    unsigned char pad_110[0xC];
    float field_11C[1];  // [G] element count unknown
};

extern UnkStruct_D_004E1F24 D_004E1F24;
extern UnkStruct_D_004E1F28 D_004E1F28;
extern UnkStruct_D_004E1F20 D_004E1F20;
extern UnkStruct_D_004E25DC D_004E25DC;
extern UnkStruct_D_004CEB60 D_004CEB60;
extern UnkStruct_D_004CEB68 D_004CEB68;
extern UnkStruct_D_004F1040 D_004F1040;
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcpy(char *, const char *);
extern "C" void func_003FDED0(UnkStruct_003FDF90 *, void *, void *);
extern "C" int func_00421E40(int, int);
extern "C" void func_004215A0(UnkStruct_003FDF90 *, int);

// 0x003FDF90
extern "C" void Construct__20CB3MemCardControllerFv(UnkStruct_003FDF90 * self)
{
    memset(&self->field_6C, 0, 964);
    self->field_6C = 80;
    self->field_6D = 83;
    self->field_6E = 50;
    self->field_6F = 68;
    self->field_72 = 18;
    int m0 = 0;
    do {
        self->field_7C[(m0 & 255)] = 0;
        self->field_8C[(m0 & 255)] = 0;
        self->field_9C[(m0 & 255)] = 0;
        self->field_AC[(m0 & 255)] = 0;
        self->field_BC[(m0 & 255)] = 0;
        self->field_CC[(m0 & 255)] = 0;
        self->field_DC[(m0 & 255)] = -1.0f;
        self->field_EC[(m0 & 255)] = 1.0f;
        self->field_FC[(m0 & 255)] = 1.0f;
        self->field_10C[(m0 & 255)] = 1.0f;
        self->field_11C[(m0 & 255)] = 0.5f;
        m0 = ((m0 + 1) & 255);
    } while (m0 < 4);
    strcpy((char *)((char *)self + 0x170), (const char *)D_004E1F24.field_0);
    strcpy((char *)((char *)self + 0x1B0), (const char *)D_004E1F24.field_0);
    strcpy((char *)((char *)self + 0x1F0), (const char *)D_004E1F24.field_0);
    func_003FDED0(self, ((char *)self + 0x12C), (void *)(D_004E1F28.field_0));
    CMemoryCardFileBase::mgpacDirName = D_004E1F20.field_0;
    self->field_C = &D_004CEB60;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_18 = 0;
    self->field_1C = &D_004CEB68;
    self->field_20 = ((char *)self + 0x6C);
    self->field_24 = 964;
    self->field_28 = 0;
    self->field_2C = D_004E1F24.field_0;
    self->field_30 = &D_004F1040;
    self->field_34 = 15234;
    self->field_38 = 0;
    int r5 = func_00421E40(D_004E25DC.field_0, 0);
    self->field_3C = D_004E1F20.field_0;
    self->field_40 = r5;
    self->field_44 = 61772;
    self->field_48 = 0;
    int r6 = func_00421E40(D_004E25DC.field_0, 0);
    int t0 = D_004E1F20.field_0;
    self->field_4C = t0;
    self->field_50 = r6;
    self->field_54 = 61772;
    self->field_58 = 0;
    func_004215A0(self, t0);
}
