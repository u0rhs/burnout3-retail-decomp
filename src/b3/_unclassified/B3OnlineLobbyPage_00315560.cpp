// CB3OnlineLobbyPage::UpdateNormalPageMode() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (page confirm switch; int h38 loaded in both arms of the 2C guard (fixes out-of-line guard block layout)).

// Hand-written (a147).
class CB3InputManager { public: int GetMenuConfirm(signed char); unsigned char pad_0[0x10]; };
class CB3HUDSoundManager { public: void FESelect(); unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(void *); virtual void vfunc_B4(); virtual void vfunc_B8(void *);
    virtual void vfunc_BC(void *);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_00315560_sel { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00315560_loc { unsigned char pad_0[0x14]; unsigned int field_14; unsigned char pad_18[0x24]; };
struct UnkStruct_00315560_loc2 { unsigned char pad_0[0x14]; unsigned int field_14; unsigned char pad_18[0xC]; };
struct UnkStruct_00315560 {
    unsigned char pad_0[0x1284];
    UnkStruct_00315560_sel field_1284;
    unsigned char pad_1288[0x4];
    unsigned char field_128C[0x34];
    int field_12C0[8];
    unsigned char pad_12E0[0x3C];
    UnkStruct_00315560_loc2 field_131C;
    unsigned char pad_133C[0x60];
    int field_13A0;
    unsigned char pad_13A4[0x8];
    signed char field_13AC;
};
extern CB3InputManager D_004F50C0;
extern signed char D_004F6061[];
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_byte D_01E3D58A;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" void func_00316640(UnkStruct_00315560 *);
extern "C" int func_00319330(UnkStruct_00315560_sel *);
extern "C" int func_00319360(UnkStruct_00315560_sel *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" bool AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" void LeaveGameImmediately__20CGtLobbyPS2DirtySockFv(void *);

// 0x00315560
extern "C" void func_00315560(UnkStruct_00315560 * self)
{
    UnkStruct_00315560_loc loc70;
    UnkStruct_00315560_loc2 loc40;
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&loc70);
    int h38;
    if (*(short *)(ctrl + 0x2C) != 0) {
        if (func_00319360(&self->field_1284) != 0) return;
        h38 = *(short *)(ctrl + 0x38);
    } else {
        h38 = *(short *)(ctrl + 0x38);
    }
    if (h38 != 0) {
        if (func_00319330(&self->field_1284) != 0) return;
    }
    int sel;
    if (D_004F50C0.GetMenuConfirm(0) != 0 && self->field_128C[(sel = self->field_1284.field_0) * 8] == 0) {
        D_01E7A800.FESelect();
        switch (self->field_12C0[sel]) {
        case 0:
            LeaveGameImmediately__20CGtLobbyPS2DirtySockFv(&D_01E3CD44);
            self->field_13AC = 0x11;
            break;
        case 1:
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&self->field_131C);
            self->field_131C.field_14 &= ~1;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(&self->field_131C);
            self->field_13AC = 0xD;
            func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
            self->field_13A0 = 0x1E;
            break;
        case 2:
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC((char *)self + 0x12E0);
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&self->field_131C);
            self->field_131C.field_14 &= ~1;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(&self->field_131C);
            self->field_13AC = 0xD;
            func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
            self->field_13A0 = 0x23;
            break;
        case 3:
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&self->field_131C);
            if (D_01E3D58A.field_0 != 0) self->field_131C.field_14 &= ~2;
            else self->field_131C.field_14 |= 2;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(&self->field_131C);
            self->field_13AC = 0xD;
            func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
            self->field_13A0 = 0x4E;
            break;
        case 4:
            break;
        case 5:
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&loc40);
            loc40.field_14 &= ~1;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(&loc40);
            self->field_13AC = 0xD;
            func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
            self->field_13A0 = 0x24;
            break;
        case 6:
            self->field_13AC = 9;
            if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) == 1) {
                func_0032D080(&D_01E898E8, 7, 0x54, 5, 0);
            } else {
                func_0032D080(&D_01E898E8, 7, 0x3B6, 5, 0);
            }
            break;
        default:
            break;
        }
    } else {
        if (*(short *)(ctrl + 0x5C) != 0) {
            if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2) func_00316640(self);
        }
    }
}
