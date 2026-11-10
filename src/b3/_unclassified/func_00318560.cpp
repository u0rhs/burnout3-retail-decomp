// Hand-written; the lifter refused it (fresh3: prompts/help-bar update; 64-bit prompt mask (unsigned long, pcpyld masks), bool r = !func_0042B6A0(..), f declared before cur, vcall through cast pointer).

struct UnkStruct_00318560 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
    unsigned char pad_18[0x1D];
    unsigned char field_35;
};

struct UnkStruct_D_01E8EE68 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00318560_ul { unsigned long value; unsigned char pad_8[0x8]; };
struct UnkStruct_00318560_int { int value; unsigned char pad_4[0xC]; };
struct UnkStruct_00318560_blk { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01E8EE68 D_01E8EE68;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_00318560_blk D_01E8EC30;
extern UnkStruct_00318560_blk D_0051BA44;
extern UnkStruct_00318560_blk D_01E89800;
extern UnkStruct_00318560_ul D_01E89810;
extern UnkStruct_00318560_int D_01E89818;

extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" int func_0042BC70(void *);
extern "C" unsigned long func_0042B700(void *, int);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAEA0(int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0042C240(void *);
extern "C" int func_0042C270(void *);
extern "C" int func_0042C160(void *);
extern "C" int func_0042C1A0(void *);
extern "C" int func_0042C100(void *);
extern "C" int func_0042B6A0(void *, int);
// 0x00318560
extern "C" void func_00318560(UnkStruct_00318560 *self)
{
    if (D_01E8EE68.field_0 != 0) {
        self->field_35 = 1;
        return;
    }
    if (self->field_35 != 0) {
        if (self->field_10 == 0) {
            ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
            bool r = !func_0042B6A0(&D_01E8EC30, func_0042BC70(&D_01E8EC30));
            if (r) {
                Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, func_003EAEA0(func_003EB060(func_0042B700(&D_01E8EC30, func_0042BC70(&D_01E8EC30))))), 0, 80.0f);
            } else {
                Prepare__19CB3HelpBarComponentFv(&D_01E89788);
            }
        }
        self->field_35 = 0;
    }
    unsigned long f;
    unsigned long cur = D_01E89810.value;
    unsigned int curb = D_01E89818.value;
    unsigned int b = 0;
    if (func_0042C270(&D_01E8EC30)) b |= 2;
    if (func_0042C240(&D_01E8EC30)) b |= 1;
    if (func_0042C1A0(&D_01E8EC30)) b |= 8;
    if (func_0042C160(&D_01E8EC30)) b |= 4;
    if (func_0042C100(&D_01E8EC30)) f = cur | 0x4000000;
    else f = cur & ~0x4000000UL;
    if (self->field_10 == 0 && !func_0042B6A0(&D_01E8EC30, func_0042BC70(&D_01E8EC30))) {
        f &= ~0x14UL;
    } else if (self->field_10 != 0) {
        f |= 0x10;
    } else {
        f |= 4;
    }
    if (b == 0) f &= ~0x100UL;
    else f |= 0x100;
    if (cur != f || curb != b) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, f, b);
    }
}
