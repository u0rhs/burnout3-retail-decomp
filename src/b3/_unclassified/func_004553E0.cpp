// Hand-written; the lifter refused it (a208: case 0 'return', explicit return after switch, shared 'done: return' for chain end -> separate b-exit stubs).


// Hand-written; the lifter refused it (options page input chain).
class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    int GetMenuBack(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_004553E0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned long field_8;
    unsigned long field_10;
    unsigned short field_18;
    unsigned char pad_1A[0x66];
    unsigned long field_80[8];
    unsigned char pad_C0[0xB8];
    unsigned long field_178[8];
    unsigned char pad_1B8[0x490];
    int field_648;
    int field_64C;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_01E7A800, D_01E90240, D_01E89800;
extern UnkStruct_D_01E89810 D_01E89810;
extern "C" int func_0022CBE0(void *, int);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_00455170(UnkStruct_004553E0 *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" unsigned long GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(unsigned long);

// 0x004553E0
extern "C" void func_004553E0(UnkStruct_004553E0 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0 && *((unsigned char *)self + self->field_18 * 20 + 0x2A) == 0) {
        int page = self->field_18;
        switch (page) {
        default:
            break;
        case 0:
            return;
        case 1:
            self->field_4 = page;
            self->field_8 = self->field_80[self->field_648];
            self->field_10 = 0;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0, 0);
            return;
        case 2:
            self->field_4 = page;
            self->field_10 = self->field_178[self->field_64C];
            self->field_8 = GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(self->field_10);
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0, 0);
            return;
        }
        return;
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
        return;
    } else if (func_0022CBE0(&D_004F50C0, 0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 0x24, false);
        goto done;
    } else if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360(&self->field_18) != 0) || (D_004F50C0.GetMenuDown(0) != 0 && func_00319330(&self->field_18) != 0)) {
        int page = self->field_18;
        if (*((unsigned char *)self + page * 20 + 0x2A) != 0 || page == 0) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~4UL, 3);
        } else {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 4, 3);
        }
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        return;
    } else {
        if (D_004F50C0.GetMenuLeft(0) != 0) goto call;
        if (D_004F50C0.GetMenuRight(0) != 0) goto call;
    }
done:
    return;
call:
    func_00455170(self);
    goto done;
}
