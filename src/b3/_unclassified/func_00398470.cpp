// Hand-written; the lifter refused it (a85: OpenLobbyPage::Prepare; local char buffers declared highest-address first (buf110, bufA0, buf30)).

// [L] DNAT: CB3OnlineOpenLobbyPage::Prepare() (research/proto/new_names.csv, medium); presence/strings tail as in func_003242F0
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3BackgroundType.h"

typedef int EB3ChatDisplayOrientation_;
enum EGtBuddyPresence {};

struct UnkStruct_00398470 {
    unsigned char pad_0[0x430];
    int field_430[9];
    int field_454;
    int field_458;
};
struct UnkStruct_D_01E90438 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004E2918 { int field_0; };
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC(int, int);
    virtual void vfunc_D0();
    virtual unsigned short * vfunc_D4();
    virtual void vfunc_D8();
    unsigned char pad_4[0xC];
};
class CGtBuddiesPS2DirtySock {
public:
    void SetPresence(EGtBuddyPresence, bool);
    unsigned char pad_0[0x10];
};

extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_P D_01E89518;
extern UnkStruct_P D_01E88A80;
extern UnkStruct_P D_01E89800;
extern UnkStruct_P D_01E894FC;
extern UnkStruct_P D_01E8CBE0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_P D_01E3D390_;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_D_004E2918 D_004E2918;
extern char * D_004D1B70[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, void *, int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(void *, void *, int);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void Prepare__23CB3ChatDisplayComponentF25EB3ChatDisplayOrientation(void *, int);
extern "C" int ChatMessageCallback__22CB3OnlineOpenLobbyPageFPcPcPv(int, int);
extern "C" int func_003517F0(void *);
extern "C" void func_00396E50(UnkStruct_00398470 *);
extern "C" void SetupTable__22CB3OnlineOpenLobbyPageFv(UnkStruct_00398470 *);
extern "C" void * func_00271A00(void *, int);
extern "C" void func_00310180(void *, void *, void *);
extern "C" void SetPresenceDetail__10CGtBuddiesFPcPcPc(void *, char *, char *, char *);

// 0x00398470
extern "C" int func_00398470(UnkStruct_00398470 * self)
{
    char buf110[0xCC];
    char bufA0[100];
    char buf30[100];
    unsigned short * presence;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int i = 0;
    do {
        self->field_430[i] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
        i++;
    } while (i < 9);
    self->field_454 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_458 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D4(), (void *)self->field_458, 32);
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(self->field_458), 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x145, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__23CB3ChatDisplayComponentF25EB3ChatDisplayOrientation(&D_01E8CBE0, 1);
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_CC((int)ChatMessageCallback__22CB3OnlineOpenLobbyPageFPcPcPv, (int)self);
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    func_00396E50(self);
    SetupTable__22CB3OnlineOpenLobbyPageFv(self);
    presence = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D4();
    func_00310180(buf110, func_00271A00(&D_0051BA44, 0xC06), &presence);
    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(buf110, bufA0, 100);
    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 0xC08), buf30, 100);
    SetPresenceDetail__10CGtBuddiesFPcPcPc(&D_01E3D390, bufA0, buf30, D_004D1B70[D_004E2918.field_0]);
    D_01E3D390.SetPresence((EGtBuddyPresence)1, 0);
    return 1;
}
