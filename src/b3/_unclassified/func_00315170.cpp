// Hand-written; the lifter refused it ([G] volatile read of D_01E32B08.field_0 in lim = D_004E2D5C + n (fixes addu operand/register coupling); FEVerticalMove__...Fv extern with retail's extra a1=1, SetAllowableCharacters(EGlobalStrings)).

// Hand-written (a147).
enum EGlobalStrings {};
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
class CB3InputManager { public: int GetMenuConfirm(signed char); unsigned char pad_0[0x10]; };
class CB3HUDSoundManager { public: void FESelect();  unsigned char pad_0[0x10]; };
class CB3OnScreenKeyboardComponent { public: void Show(bool, bool); void SetAllowableCharacters(EGlobalStrings); unsigned char pad_0[0x10]; };
struct UnkStruct_D_vt { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_ptr { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_str { char field_0[0x10]; };
struct UnkStruct_00315170_sel { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00315170_ent { unsigned char pad_0[0x4B8]; char field_4B8[0x10]; };
struct UnkStruct_00315170 {
    unsigned char pad_0[4];
    UnkStruct_00315170_sel field_4;
    unsigned char pad_8[0x48];
    char field_50[0x1230];
    UnkStruct_00315170_sel field_1280;
    unsigned char pad_1284[0x104];
    int field_1388;
    unsigned char pad_138C[0x4];
    int field_1390;
    unsigned char pad_1394[0x18];
    signed char field_13AC;
};
extern CB3InputManager D_004F50C0;
extern signed char D_004F6061[];
extern int D_004E2D5C;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_D_byte D_01E32AE0;
extern CB3HUDSoundManager D_01E7A800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_vt D_01E8D450;
extern UnkStruct_D_vt D_01E8D490;
extern UnkStruct_D_vt D_01E89544;
extern UnkStruct_D_vt D_01E8EAF8;
extern UnkStruct_D_vt D_01E898E8;
extern UnkStruct_D_byte D_01E8D49A;
extern UnkStruct_D_byte D_01E8954E;
extern UnkStruct_D_byte D_01E8EB02;
extern UnkStruct_D_int D_01E8CBCC;
extern UnkStruct_D_ptr D_01E8D45C;
extern UnkStruct_D_str D_01E3D558;
extern "C" int func_00319330(UnkStruct_00315170_sel *);
extern "C" int func_00319360(UnkStruct_00315170_sel *);
extern "C" void func_00312420(UnkStruct_00315170 *);
extern "C" void func_00315CE0(UnkStruct_00315170 *);
extern "C" void func_00316210(UnkStruct_00315170 *);
extern "C" UnkStruct_00315170_ent * func_002366D0(void *, int);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" bool AmIHost__17CB3NetworkManagerFv(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(void *, int, void *, UnkStruct_00315170_sel *);

// 0x00315170
extern "C" void func_00315170(UnkStruct_00315170 * self)
{
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if (D_01E8D49A.field_0 == 0) {
        Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(&D_01E8D490, 1, D_01E8D45C.field_0, &self->field_4);
    }
    // [G] volatile read: the only form that gives retail's addu operand/register order (pass3b)
    int lim = D_004E2D5C + *(volatile int *)&D_01E32B08.field_0;
    if (*(short *)(ctrl + 0x2C) != 0) {
        if (func_00319360(&self->field_4) != 0) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            func_00312420(self);
        } else if (self->field_1390 > 0) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            self->field_1390 = self->field_1390 - 1;
            func_00312420(self);
        }
    }
    if (*(short *)(ctrl + 0x38) != 0) {
        if (func_00319330(&self->field_4) != 0) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            func_00312420(self);
        } else if (self->field_1390 < lim - 6) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            self->field_1390 = self->field_1390 + 1;
            func_00312420(self);
        }
    } else if (D_004F50C0.GetMenuConfirm(0) != 0) {
        UnkStruct_00315170_ent * e = func_002366D0(&D_01E32AE0, self->field_1390 + self->field_4.field_0);
        D_01E7A800.FESelect();
        if (e == 0) {
            strncpy(self->field_50, D_01E3D558.field_0, 0x10);
        } else {
            strncpy(self->field_50, e->field_4B8, 0x10);
        }
        func_00315CE0(self);
    }
    if (*(short *)(ctrl + 0x5C) != 0 && GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2) {
        self->field_13AC = 9;
        if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) == 1) {
            func_0032D080(&D_01E898E8, 7, 0x54, 5, 0);
        } else {
            func_0032D080(&D_01E898E8, 7, 0x3B6, 5, 0);
        }
    } else {
        if (*(short *)(ctrl + 0x8C) != 0) {
            func_00316210(self);
        } else {
            if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0x12, 0) != 0 && self->field_13AC == 1) {
                self->field_13AC = 2;
                D_01E899C0.Show(true, true);
                D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x293);
                D_01E8CBCC.field_0 = 0x40;
                ((UnkStruct_D_vt *)&D_01E8D450)->vfunc_C();
                if (D_01E8D49A.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8D490)->vfunc_C();
                if (D_01E8954E.field_0 != 0) ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
                if (D_01E8EB02.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8EAF8)->vfunc_C();
            }
        }
    }
    int pos = self->field_4.field_0;
    pos = (int)((unsigned)self->field_1390 + (unsigned)pos);
    int cnt = self->field_1388;
    if (pos >= cnt) {
        self->field_1280.field_0 = cnt - 1;
        self->field_1280.field_2 = cnt;
    } else {
        self->field_1280.field_0 = pos;
        self->field_1280.field_2 = cnt;
    }
}
