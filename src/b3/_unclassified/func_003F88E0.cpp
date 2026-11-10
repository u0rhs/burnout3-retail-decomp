// Hand-written; the lifter refused it (near15: name selection as two static inlines with structured if/else (goto form had 10 off)).

// func_003F88E0 -- hand-written (near15): builds a path string with sprintf from a mode-dependent name. The mode
// comes from the menu's vfunc_98 (7 = remapped through vfunc_9C). The name selection is written as two static
// inlines (func_003F88E0_inl1/inl2, placeholders [G]); their structured if/else gives retail's block layout, where
// the earlier goto form did not. Types are placeholders [G].

struct UnkStruct_Menu {
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
    virtual int vfunc_98();
    virtual int vfunc_9C();
};
struct UnkStruct_Rec2 { unsigned char pad_0[0x38]; int field_38; };
struct UnkStruct_Rec { unsigned char pad_0[4]; int field_4; UnkStruct_Rec2 * field_8; };
struct UnkStruct_Game { unsigned char pad_0[0x1B4]; UnkStruct_Menu * field_1B4; UnkStruct_Rec * field_1B8; };
struct UnkStruct_D_0051BA88 { UnkStruct_Game * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D3A4 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D3A4 D_0064D3A4;
extern int D_004E2918;
extern char * D_004E1EC8;
extern char * D_004E1ED8;
extern char * D_004A55D0[];
extern char D_004CE958[];
extern char D_004CE968[];
extern char D_004CE970[];
extern char D_004CE978[];
extern char D_004CE980[];
extern char D_004CE988[];
extern char D_004CE990[];
extern char D_004CE998[];
extern "C" int sprintf(char *, const char *, ...);
static inline bool func_003F88E0_inl2()
{
    UnkStruct_Rec * r = D_0051BA88.field_0->field_1B8;
    bool a = false;
    if (r->field_4 == 1) {
        a = r->field_8->field_38 >= 2;
    }
    return a;
}

static inline const char * func_003F88E0_inl1(int s)
{
    const char * t0 = 0;
    switch (s) {
    case 0:
        if (D_0064D3A4.field_0 == 1) {
            t0 = D_004CE998;
        } else if (func_003F88E0_inl2()) {
            t0 = D_004CE968;
        } else {
            t0 = D_004CE970;
        }
        break;
    case 1: t0 = D_004CE978; break;
    case 3: t0 = D_004CE980; break;
    case 4: t0 = D_004CE988; break;
    case 6: t0 = D_004CE990; break;
    }
    return t0;
}

// 0x003F88E0
extern "C" void func_003F88E0(void * self, char * out)
{
    UnkStruct_Menu * m = D_0051BA88.field_0->field_1B4;
    int s = m->vfunc_98();
    if (s == 7) {
        switch (m->vfunc_9C()) {
        case 0: s = 0; break;
        case 1: s = 2; break;
        case 2: s = 3; break;
        case 3: case 4: case 5: default: s = 6; break;
        }
    }
    const char * t0 = func_003F88E0_inl1(s);
    sprintf(out, D_004CE958, D_004E1EC8, D_004A55D0[D_004E2918], t0, D_004E1ED8);
}
