// Hand-written; the lifter refused it (case 3 not-confirmed exit is break (joins the switch-end block), no default: -> the switch join stays an unthreaded 'b epi; nop' and case 3's SLOF return is the first epilogue branch (gets ld ra) (sdra rule 2)).

// func_00382FC0 -- CB3OnlineLobbySelectPage::Update()
// [L] DNAT: CB3OnlineLobbySelectPage::Update() (research/proto/new_names.csv, medium)

enum EB3MenuFlowFSMEvents {};

class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01E898E8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
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
    virtual int vfunc_58();
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
    unsigned char pad_4[0xC];
};

struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

struct UnkStruct_003835C0_e0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    char field_C[0x24];
};
struct UnkStruct_003835C0_e1 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x28];
};

struct UnkStruct_Page {
    UnkStruct_003835C0_e0 field_0[1];
    UnkStruct_003835C0_e1 field_30[1];
    unsigned char pad_60[0x13F8];
    int field_1458;
    unsigned char pad_145C[0x320];
    unsigned short field_177C;
    short field_177E;
    int field_1780;
    int field_1784;
    int field_1788;
    signed char field_178C;
};

extern UnkStruct_I D_01E90424;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_B D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898E8 D_01E89800;
extern UnkStruct_P D_01E89788;
extern UnkStruct_P D_0051BA44;
extern CB3InputManager D_004F50C0;

extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" int func_0022CBE0(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" int PrintInt__10CGtUnicodeFPUsii(int, int, int, int);
extern "C" int AppendN__10CGtUnicodeFPUsiPCUs(int, int, int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short *, bool, bool, float);
extern "C" int ForEachLobby__24CB3OnlineLobbySelectPageFiPciibPv(int, char *, int, int, bool, void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

#define HIDE() ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C()

static inline void ShowError(UnkStruct_Page * self)
{
    self->field_178C = 3;
    if (D_01E898F2.field_0 != 0) {
        HIDE();
    }
    int e = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
    func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
}

// 0x00382FC0
extern "C" void func_00382FC0(UnkStruct_Page * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_178C) {
    case 0:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 1:
            ShowError(self);
            break;
        case 2:
            self->field_178C = 2;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_A0(self->field_0[0].field_4);
            break;
        case 0:
            return;
        }
        break;
    case 1:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 2:
            if (self->field_1780 == 0) {
                self->field_178C = 3;
                if (D_01E898F2.field_0 != 0) {
                    HIDE();
                }
                func_0032D080(&D_01E898E8, 2, 0x64, 0, 0);
            }
            break;
        case 0:
            break;
        case 1:
            ShowError(self);
            break;
        }
        if (D_01E898F2.field_0 != 0) {
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 1) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
                return;
            }
        }
        if (self->field_1780 > 0 && D_004F50C0.GetMenuConfirm(0)) {
            self->field_0[0].field_4 = self->field_0[self->field_177C].field_8;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_A0(self->field_0[0].field_4);
            self->field_178C = 2;
            ((UnkStruct_D_01E898E8 *)&D_01E89800)->vfunc_C();
        } else {
            if (D_004F50C0.GetMenuBack(0)) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
                return;
            }
            if ((D_004F50C0.GetMenuUp(0) && func_00319360(&self->field_177C)) || (D_004F50C0.GetMenuDown(0) && func_00319330(&self->field_177C))) {
                int r2 = PrintInt__10CGtUnicodeFPUsii(self->field_1458, self->field_30[self->field_177C].field_0, 1, 0);
                int r3 = func_00271A00(&D_0051BA44, 933);
                int r4 = AppendN__10CGtUnicodeFPUsiPCUs(r2, 32, r3);
                PrintInt__10CGtUnicodeFPUsii(r4, self->field_30[self->field_177C].field_4, 1, 0);
                SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)self->field_1458, 0, 0, 80.0f);
                return;
            }
            if (func_0022CBE0(&D_004F50C0, 0)) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x24, 0);
                return;
            }
        }
        if (self->field_1788 != 0) {
            self->field_1788--;
            if (self->field_1788 == 0) {
                self->field_1784 = 0;
                self->field_1788 = 0;
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_9C((void *)ForEachLobby__24CB3OnlineLobbySelectPageFiPciibPv, self);
            }
        }
        break;
    case 2:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        case 0:
            return;
        case 1:
            ShowError(self);
            break;
        }
        break;
    case 3:
        if (D_004F50C0.GetMenuConfirm(0) == 0) {
            break;
        }
        if (self->field_1780 == 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        }
        self->field_178C = 1;
        HIDE();
        func_0031ECD0(&D_01E89800, 0x145, 3);
        return;
    }
}
