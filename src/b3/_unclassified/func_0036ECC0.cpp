// Hand-written; the lifter refused it (audit1: BuddyInvite's missing 4th argument (self in a3) restored; byte-identical).

enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};
struct UnkStruct_0036ECC0 {
    unsigned char pad_0[0x4];
    char field_4[0x5C];
    unsigned short field_60;
    unsigned char pad_62[0x6A];
    int field_CC;
    int field_D0;
    int field_D4[13];
    char field_108[0x15];
    unsigned char field_11D;
};
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0x10 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
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
    virtual void vfunc_98(void *, void *);
    unsigned char pad_4[0xC];
};

extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_0x10 D_01E899C0, D_01E90240, D_01E3D390;
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0036BD90(int, char *, int, int, int, int, int, void *);
extern "C" void func_0036C370(bool, void *);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, EGlobalStrings);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, void *);   // audit1: (this, name, callback, callback data) -- the mangled (char *, void (*)(bool, void *), void *) after this
extern "C" char * strncpy(char *, const char *, unsigned int);

// 0x0036ECC0
extern "C" void func_0036ECC0(UnkStruct_0036ECC0 * self)
{
    switch (self->field_D4[self->field_60]) {
    case 0:
        self->field_CC = 4;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_98(self->field_108, (void *)&func_0036BD90);
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 0, 0x19, 0xF, 0);
        return;
    case 1:
        self->field_CC = 7;
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, true, false);
        SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, (EGlobalStrings)0x293);
        break;
    case 2:
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x25, 0);
        break;
    case 3:
        strncpy(self->field_4, self->field_108, 0x10);
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x2C, 0);
        break;
    case 4:
        self->field_CC = 0xC;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x36, 5, 0);
        break;
    case 5:
        self->field_CC = 0xD;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0xC40, 5, 0);
        break;
    case 6:
        self->field_D0 = 0;
        self->field_11D = 0;
        self->field_CC = 0xB;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x22, 5, 0);
        break;
    case 8:
        self->field_CC = 0xF;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x26, 5, 0);
        break;
    case 9:
        self->field_CC = 0x10;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x2A, 5, 0);
        break;
    case 10:
        self->field_CC = 0x11;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x2E, 5, 0);
        break;
    case 11:
        self->field_D0 = 0;
        self->field_CC = 0x13;
        if (BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&func_0036C370, self) != 0) {
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            func_0032D080(&D_01E898E8, 2, 0x42, 0, 0);
        } else {
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            func_0032D080(&D_01E898E8, 0, 0x40, 0xF, 0);
        }
        break;
    case 12:
        self->field_D0 = 0;
        self->field_11D = 0;
        self->field_CC = 0xB;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x22, 5, 0);
        break;
    case 7:
        self->field_CC = 0xE;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 7, 0x32, 5, 0);
        break;
    }
}
