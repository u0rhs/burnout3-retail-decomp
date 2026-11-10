// Hand-written; the lifter refused it (a131: [L] DNAT CB3CrashNavPage::UpdateHeadingAndHelpBar(bool,bool); int params, bool f = func_003A6FD0 then s1 before the if).

#include "b3/classes/UnkStruct_D_01E89522.h"
#include "b3/classes/UnkStruct_D_01E89538.h"

struct UnkStruct_003C43E0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x6];
    unsigned char field_12;
};
struct UnkStruct_D_01E89792_x { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0051BA44_x { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E88AF0_x { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89518_x { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89788_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E89522 D_01E89522;
extern UnkStruct_D_01E89538 D_01E89538;
extern UnkStruct_D_01E89792_x D_01E89792;
extern UnkStruct_D_0051BA44_x D_0051BA44;
extern UnkStruct_D_01E88AF0_x D_01E88AF0;
extern UnkStruct_D_01E89518_x D_01E89518;
extern UnkStruct_D_01E89788_x D_01E89788;
extern unsigned short D_004CA358[];
extern "C" int func_003A70B0(void *);
extern "C" bool func_003A6FD0(void *);
extern "C" int func_003E8C20(int);
extern "C" int func_003E9690(int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short *, bool, bool, float);

// 0x003C43E0
extern "C" void func_003C43E0(UnkStruct_003C43E0 * self, int p0, int p1)
{
    int s1;
    int s0;
    self->field_12 = p0;
    if (p0 == 0) {
        switch (self->field_4) {
        case 0:
            s1 = 0xF8;
            s0 = 0xF9;
            break;
        case 1:
            s1 = 0xFD;
            switch (self->field_8) {
            case 0: s0 = 0xFF; break;
            case 1: s0 = 0x100; break;
            case 2: s0 = 0x101; break;
            }
            break;
        case 2:
            s0 = func_003A70B0(&D_01E88AF0);
            bool f = func_003A6FD0(&D_01E88AF0);
            s1 = 0x10A;
            if (f) {
                s0 += 0xA2A;
            } else {
                s0 = func_003E8C20(s0);
            }
            break;
        case 4:
            s0 = func_003A70B0(&D_01E88AF0);
            bool r = func_003A6FD0(&D_01E88AF0);
            s1 = 0x10A;
            s0 = func_003E9690(s0, r);
            break;
        }
        s1 = func_00271A00(&D_0051BA44, s1);
        s0 = func_00271A00(&D_0051BA44, s0);
    } else {
        s1 = (int)D_004CA358;
        s0 = s1;
    }
    if (p1 != 0) {
        if (D_01E89522.field_0 == 0) {
            Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(s1), 0xE);
        } else {
            D_01E89538.field_0 = s1;
        }
    }
    if (D_01E89792.field_0 != 0) {
        SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)s0, true, false, 80.0f);
    } else {
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)s0, false, 80.0f);
    }
}
