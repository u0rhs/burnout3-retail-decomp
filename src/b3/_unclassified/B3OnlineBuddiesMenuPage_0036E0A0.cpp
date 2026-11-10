// CB3OnlineBuddiesMenuPage::UpdateSearch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineBuddiesMenuPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a169: matched; goto-form entry-jump search loop (N24), i++ placed before strcasecmp for the delay slot, cases 7 and 9 duplicated, early exits via goto out).

// Hand-written (a169): CB3OnlineBuddiesMenuPage::UpdateSearch -- lifter refused; written from cfgmap + asm.
extern "C" char *strcpy(char *, const char *);
extern "C" int strcasecmp(const char *, const char *);
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Int16 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_vt D_01E898E8, D_01E8970C, D_01E8D670, D_01E8EAF8;
extern UnkStruct_D_Byte16 D_01E8D67A, D_01E89716, D_01E8EB02;
extern UnkStruct_D_Int16 D_01E3D460;
extern UnkStruct_Pad16 D_01E7A800, D_01E3D390, D_01E89800, D_004C8158, D_004C8160, D_004F50C0, D_01E899C0;
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_0036B700(void *, bool);
extern "C" int GetFoundBuddyName__22CGtBuddiesPS2DirtySockFiPc(void *, int, char *);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void Select__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);
extern "C" void SetFocus__24CB3BuddyDisplayComponentFb(void *, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
struct UnkStruct_a169 {
    unsigned char pad_0[4];
    char field_4[0x28];
    unsigned char pad_2C[0x30];
    unsigned char field_5C[0x70];
    int field_CC;
    unsigned char pad_D0[0x38];
    char field_108[0x14];
    unsigned char field_11C;
    unsigned char pad_11D[1];
    unsigned char field_11E;
    unsigned char pad_11F[5];
    int field_124;
    int field_128;
};
static inline void a169_open(UnkStruct_a169 *self)
{
    self->field_CC = 2;
    if (D_01E8D67A.field_0 == 0) {
        Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
    }
    SetFocus__24CB3BuddyDisplayComponentFb(&D_01E8D670, true);
    if (D_01E89716.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8970C)->vfunc_C();
    }
    if (D_01E8EB02.field_0 == 0) {
        Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, self->field_5C, 272.0f);
    }
    unsigned long v = 0x105 | ((unsigned long)4 << 32);
    if (D_01E3D460.field_0 == 6) {
        v |= (unsigned long)2 << 32;
    } else {
        v |= (unsigned long)1 << 32;
    }
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
}
extern "C" void UpdateSearch__24CB3OnlineBuddiesMenuPageFv(UnkStruct_a169 *self)
{
    if (self->field_CC == 10) {
        if (self->field_11E != 0) {
            self->field_11E = 0;
            if (self->field_11C != 0) {
                char buf[0x10];
                self->field_11C = 0;
                int i = 0;
                goto test;
            body:
                i++;
                if (strcasecmp(buf, self->field_4) == 0) {
                    self->field_11C = 1;
                    strcpy(self->field_4, buf);
                }
            test:
                if (GetFoundBuddyName__22CGtBuddiesPS2DirtySockFiPc(&D_01E3D390, i, buf) == 0) goto body;
            }
            if (self->field_11C != 0) {
                ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 2, 0x3B, 0, 0);
            } else {
                ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 2, 0x3C, 0, 0);
            }
        }
        if (func_0032B2C0(&D_01E898E8, 0, 1) != 0) goto out;
        if (self->field_11C != 0) {
            self->field_11C = 0;
            strcpy(self->field_108, self->field_4);
            self->field_CC = 3;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            if (D_01E8D67A.field_0 != 0) {
                ((UnkStruct_D_vt *)&D_01E8D670)->vfunc_C();
                ((UnkStruct_D_vt *)&D_01E8EAF8)->vfunc_C();
            }
            func_0036B700(self, true);
        } else {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            a169_open(self);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
    } else {
        if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardShift__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardCapsLock__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xE, 0)) {
            SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else {
            if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0) == 0) goto out;
            switch (self->field_CC) {
            case 7:
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
                a169_open(self);
                break;
            case 9:
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
                a169_open(self);
                break;
            }
            FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
    }
out:
    return;
}
