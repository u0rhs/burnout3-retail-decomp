// Hand-written; the lifter refused it (a157: [L] DNAT SingleEvent Update; switch(mode){case 0..; case 1: else-if chain}, Back block 'if(back){call; return;} break;').

// [L] DNAT: CB3SingleEventGameOptionsPage::Update() (research/proto/new_names.csv, exact/verified)
struct CB3MenuInput {
    enum EMenuControls { EMenuControls_Unk0 };
};
enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};
class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuKeyboardShift(signed char);
    int GetMenuKeyboardCapsLock(signed char);
    int GetMenuButton(CB3MenuInput::EMenuControls, signed char);
    unsigned char pad_0[0x10];
};
class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);
    void SetAllowableCharacters(EGlobalStrings);
    void SetDisplayText(unsigned short *, bool);
    void SelectNextLeft();
    void SelectNextRight();
    void SelectNextUp();
    void SelectNextDown();
    void Select();
    void SelectShift();
    void SelectCapsLock();
    void SelectSymbols();
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_00434550 {
    unsigned char pad_0[0x40];
    unsigned short *field_40;
    unsigned short *field_44;
    unsigned short field_48;
    unsigned char pad_4A[2];
    unsigned char field_4C;
};
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8CBCC { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00516DF4 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00516E18 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89544 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern CB3InputManager D_004F50C0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_00516DF4 D_00516DF4;
extern UnkStruct_D_00516E18 D_00516E18;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8954E D_01E8954E;
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0013B6D0(int, int, unsigned short *);
extern "C" unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(void *, int, unsigned short *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

// 0x00434550
extern "C" void func_00434550(UnkStruct_00434550 * self)
{
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_4C) {
    case 0:
        if ((D_004F50C0.GetMenuUp(0) && func_00319360((char *)self + 0x48)) || (D_004F50C0.GetMenuDown(0) && func_00319330((char *)self + 0x48))) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            return;
        }
        if (D_004F50C0.GetMenuConfirm(0)) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            switch (self->field_48) {
            case 0:
                self->field_4C = 1;
                if (D_01E8954E.field_0 != 0) {
                    ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
                }
                D_01E899C0.Show(1, 0);
                D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x295);
                D_01E899C0.SetDisplayText(self->field_40, 1);
                D_01E8CBCC.field_0 = 9;
                break;
            case 1:
                self->field_4C = 1;
                if (D_01E8954E.field_0 != 0) {
                    ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
                }
                D_01E899C0.Show(1, 0);
                D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x295);
                D_01E899C0.SetDisplayText(self->field_44, 1);
                D_01E8CBCC.field_0 = 9;
                break;
            case 2: {
                CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, self->field_40);
                CopyN__10CGtUnicodeFPUsiPCUs(&D_00516E18, 9, self->field_44);
                int prof = D_0051BF9C.field_0;
                if (prof != 0) {
                    func_0013B6D0(prof, 0, self->field_40);
                    func_0013B6D0(prof, 1, self->field_44);
                }
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
                break;
            }
            }
        }
        if (D_004F50C0.GetMenuBack(0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        }
        break;
    case 1:
        if (D_004F50C0.GetMenuLeft(0)) {
            D_01E899C0.SelectNextLeft();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuRight(0)) {
            D_01E899C0.SelectNextRight();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuUp(0)) {
            D_01E899C0.SelectNextUp();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuDown(0)) {
            D_01E899C0.SelectNextDown();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuConfirm(0)) {
            D_01E899C0.Select();
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuKeyboardShift(0)) {
            D_01E899C0.SelectShift();
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuKeyboardCapsLock(0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectCapsLock();
        } else if (D_004F50C0.GetMenuButton((CB3MenuInput::EMenuControls)14, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectSymbols();
        } else if (D_004F50C0.GetMenuButton((CB3MenuInput::EMenuControls)15, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (D_004F50C0.GetMenuBack(0)) {
            FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (self->field_4C == 1) {
                self->field_4C = 0;
                D_01E899C0.Show(0, 0);
            }
        }
        break;
    }
}
