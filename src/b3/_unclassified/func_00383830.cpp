// Hand-written; the lifter refused it (a130: [L] DNAT CB3OnlineLobbySelectPage::Prepare (retail takes (int,bool)); int v = Alloc() before the two array stores; vcalls via ((UnkStruct_D_01E3CD44*)&D)->vfunc_9C/A0/D8).

enum EB3BackgroundType {};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
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
    virtual void vfunc_9C(void *, void *);
    virtual void vfunc_A0(int);
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
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00383830_ent { int field_0; unsigned char field_4; unsigned char pad_5[3]; };
struct UnkStruct_00383830 {
    unsigned char pad_0[4];
    int field_4;
    unsigned char pad_8[0x12C8 - 8];
    int field_12C8[100];
    int field_1458;
    UnkStruct_00383830_ent field_145C[100];
    short field_177C;
    short field_177E;
    int field_1780;
    int field_1784;
    int field_1788;
    unsigned char field_178C;
};
extern UnkStruct_D_Pad16 D_01E90438, D_01E89518, D_01E88A80, D_01E89800, D_0051BA44, D_01E8970C, D_01E7A800, D_01E89788, D_01E894FC, D_01E8E7E0, D_01E898E8, D_01E32AE0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void func_00336320(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" int PrepareSpinning__17CB3GlobeComponentFv(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_0039C150(void *, void *, void *);
extern "C" int ForEachLobby__24CB3OnlineLobbySelectPageFiPciibPv(int, char *, int, int, bool, void *);
// 0x00383830
extern "C" int func_00383830(UnkStruct_00383830 *self, int p0, int p1)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    for (int i = 0; i < 100; i++) {
        int v = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        self->field_12C8[i] = v;
        self->field_145C[i].field_0 = self->field_12C8[i];
        self->field_145C[i].field_4 = 0;
    }
    self->field_1458 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    func_00319C80(&D_01E89518, 92, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    if (p0 == -1) {
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 95), 1, 80.0f);
        Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
        PrepareSpinning__17CB3GlobeComponentFv(&D_01E8E7E0);
        func_0031ECD0(&D_01E89800, 325, 3);
        self->field_178C = 1;
        self->field_1780 = 0;
        self->field_1784 = 0;
        self->field_177C = 0;
        self->field_177E = 1;
        self->field_1784 = 0;
        self->field_1788 = 0;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_9C((void *)&ForEachLobby__24CB3OnlineLobbySelectPageFiPciibPv, self);
        func_0039C150(&D_01E8970C, &self->field_177C, self->field_145C);
    } else {
        self->field_4 = p0;
        if (p1 != 0) {
            func_0032D080(&D_01E898E8, 3, 25, 1, 0);
            self->field_178C = 2;
            self->field_4 = p0;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_A0(self->field_4);
        } else {
            self->field_178C = 0;
            if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() != 0) {
                ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
                func_00336320(&D_01E3CD44);
            }
            func_0032D080(&D_01E898E8, 0, 774, 15, 0);
        }
    }
    return 1;
}
