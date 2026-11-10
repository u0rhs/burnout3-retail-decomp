// func_0043B4A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E90438.h"

struct UnkStruct_0043B4A0;

struct UnkStruct_0043B4A0 {
    unsigned char pad_0[0x5C];
    int field_5C[1];  // [G] element count unknown
    unsigned char pad_60[0x5AC];
    int field_60C[1];  // [G] element count unknown
    unsigned char pad_610[0x250];
    int field_860[1];  // [G] element count unknown
    unsigned char pad_864[0x3A0];
    short field_C04;
    short field_C06;
    int field_C08;
    unsigned char field_C0C;
    unsigned char field_C0D;
    unsigned char pad_C0E[0x2];
    int field_C10;
    unsigned char field_C14;
    unsigned char field_C15;
    unsigned char pad_C16[0x2];
    int field_C18;
    unsigned char field_C1C;
};

extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, float, int);  // CB3VSelectComponent::Prepare(bool,float,float,float,float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_00336640(void *, int);

// 0x0043B4A0
extern "C" int func_0043B4A0(UnkStruct_0043B4A0 * self, void *p0_)
{
    int p0 = (int)p0_;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    for (int i = 0; (i < 6); i++) {
        int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        self->field_5C[i] = r1;
    }
    for (int i1 = 0; (i1 < 7); i1++) {
        int r2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 24);
        self->field_60C[i1] = r2;
        int r3 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 44);
        self->field_860[i1] = r3;
    }
    int r4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_C18 = r4;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p0, self->field_C18, 32);
    self->field_C04 = 0;
    self->field_C06 = 2;
    int r6 = func_00271A00(&D_0051BA44, 458);
    self->field_C08 = r6;
    self->field_C0C = 0;
    self->field_C0D = 0;
    int r7 = func_00271A00(&D_0051BA44, 63);
    self->field_C10 = r7;
    self->field_C14 = 0;
    self->field_C15 = 0;
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 84.0f, 240.0f, 30.0f, 40.0f, (const CB3MenuComponentSelectionData*)((char *)self + 0xC04), (CB3VSelectComponentEntryData*)((char *)self + 0xC08), 156.0f, 0);
    func_00319C80(&D_01E89518, 227, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    int r13 = func_00271A00(&D_0051BA44, 237);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r13, 0, 80.0f);
    func_0032D080(&D_01E898E8, 0, 2462, 15, 0);
    self->field_C1C = 0;
    int r16 = func_00336640(&D_01E3CD44, p0);
    if (r16 == 1) {
        self->field_C1C = 3;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        if (D_01E8954E.field_0 != 0) {
            ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
        }
        if (D_01E8D45A.field_0 != 0) {
            ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 2, 2535, 0, 0);
    }
    return 1;
}
