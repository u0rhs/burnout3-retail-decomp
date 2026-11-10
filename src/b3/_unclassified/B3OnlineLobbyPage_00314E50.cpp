// CB3OnlineLobbyPage::UpdateBuddyDetailsPageMode() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (buddy page confirm switch; int h38 in both guard arms; field_50[0]==0 as if/else).

// Hand-written (a147).
enum EGlobalStrings {};
class CB3InputManager { public: int GetMenuConfirm(signed char); unsigned char pad_0[0x10]; };
class CB3HUDSoundManager { public: void FESelect(); unsigned char pad_0[0x10]; };
class CB3OnScreenKeyboardComponent { public: void Show(bool, bool); void SetAllowableCharacters(EGlobalStrings); unsigned char pad_0[0x10]; };
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
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E3D390 { unsigned char pad_0[0x10]; };
struct UnkStruct_00314E50_sel { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00314E50_loc { unsigned char pad_0[0x14]; unsigned int field_14; unsigned char pad_18[0xC]; };
struct UnkStruct_00314E50_rec { unsigned char pad_0[0x12C]; };
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
struct UnkStruct_00314E50 {
    unsigned char pad_0[0x50];
    char field_50[0x1234];
    UnkStruct_00314E50_sel field_1284;
    unsigned char pad_1288[0x4];
    unsigned char field_128C[0x34];
    int field_12C0[8];
    unsigned char pad_12E0[0xC0];
    int field_13A0;
    unsigned char pad_13A4[0x8];
    signed char field_13AC;
};
extern CB3InputManager D_004F50C0;
extern signed char D_004F6061[];
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern CB3HUDSoundManager D_01E7A800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void func_00316640(UnkStruct_00314E50 *);
extern "C" int func_00319330(UnkStruct_00314E50_sel *);
extern "C" int func_00319360(UnkStruct_00314E50_sel *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, void *);
extern "C" void _AddUserCallback__18CB3OnlineLobbyPageFbPv(bool, void *);

// 0x00314E50
extern "C" void func_00314E50(UnkStruct_00314E50 * self)
{
    UnkStruct_00314E50_loc loc;
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if (self->field_50[0] == 0) {
        func_00316640(self);
    } else {
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
        if (D_004F50C0.GetMenuConfirm(0) != 0 && self->field_128C[self->field_1284.field_0 * 8] == 0) {
            D_01E7A800.FESelect();
            switch (self->field_12C0[self->field_1284.field_0] - 7) {
            case 0:
                self->field_13AC = 4;
                if (BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_50, (void *)&_AddUserCallback__18CB3OnlineLobbyPageFbPv, self) == 0) {
                    func_0032D080(&D_01E898E8, 0, 0x40, 0xF, 0);
                } else {
                    func_0032D080(&D_01E898E8, 2, 0x42, 0, 0);
                }
                break;
            case 1:
                self->field_13AC = 5;
                D_01E899C0.Show(true, true);
                D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x293);
                break;
            case 2: {
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&loc);
                loc.field_14 &= ~1;
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(&loc);
                self->field_13AC = 0xD;
                func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
                self->field_13A0 = 0x2C;
                break;
            }
            case 3:
                self->field_13AC = 7;
                func_0032D080(&D_01E898E8, 7, 0x36, 5, 0);
                break;
            case 5:
                self->field_13AC = 8;
                func_0032D080(&D_01E898E8, 7, 0x3B9, 5, 0);
                break;
            case 4: {
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&loc);
                loc.field_14 &= ~1;
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(&loc);
                self->field_13AC = 0xD;
                func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
                self->field_13A0 = 0x2A;
                break;
            }
            default:
                break;
            }
        } else {
            if (*(short *)(ctrl + 0x5C) != 0) func_00316640(self);
        }
    }
}
