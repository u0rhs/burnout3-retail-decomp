// NONMATCHING: func_00441100 -- retail 169 / ours 169 instructions, 5 in changed runs
// near32: 5 off -- only the constant 1 lives in t8 (retail s2); the table at +0x18 is 5 x 0x18 entries {name,int,int,lo,hi} written by a static inline setter, then 3 x 0xC {name,uchar} entries (fixed the whole store schedule, 45 -> 5). Tried an int one local, return one, decl orders, sreg (2 rounds)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// a135: 45 instrs; loops/tail exact in shape (n = field_12C test reuse, char b[2]={0,0} after the Alloc, element address after the call); prologue store block only: retail keeps constant 1 in s2 (callee-saved) and hoists lui of D_004D2250/func_004407B0/D_0064D37C before the stores in a different order; ours uses t8 and interleaves the lui/addiu differently (pure scheduling/regalloc of ~40 constant stores)

#include "b3/classes/CB3PromptBarComponent.h"
enum EB3BackgroundType {};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_Obj {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};
struct UnkStruct_Row { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_00441100_e { void *field_0; int field_4; int field_8; int field_C; int field_10; unsigned char pad_14[4]; };
struct UnkStruct_00441100_f { void *field_0; float field_4; int field_8; float field_C; float field_10; unsigned char pad_14[4]; };
struct UnkStruct_00441100_b { void *field_0; unsigned char field_4; unsigned char pad_5[3]; int pad_8; };
struct UnkStruct_00441100 {
    unsigned char pad_0[8];
    void *field_8;
    void *field_C;
    void *field_10;
    unsigned char pad_14[4];
    UnkStruct_00441100_e field_18[5];
    UnkStruct_00441100_b field_90[3];
    void *field_B4;
    unsigned char field_B8;
    unsigned char pad_B9[3];
    short field_BC;
    short field_BE;
    UnkStruct_Row field_C0[8];
    unsigned char pad_100[8];
    UnkStruct_Obj *field_108[8];
    int field_128;
    int field_12C;
    int *field_130[1];
};
static inline void func_00441100_inl1(UnkStruct_00441100_e *e, void *n, int a, int b, int lo, int hi)
{
    e->field_0 = n;
    e->field_4 = a;
    e->field_8 = b;
    e->field_C = lo;
    e->field_10 = hi;
}
static inline void func_00441100_inl2(UnkStruct_00441100_b *e, void *n, unsigned char v)
{
    e->field_0 = n;
    e->field_4 = v;
}
extern UnkStruct_I D_0064D37C;
extern UnkStruct_B D_0051B38C;
extern unsigned char D_004E2F88;
extern unsigned char D_004E2F8C;
extern unsigned char D_004E2F90;
extern UnkStruct_P16 D_004D2250;
extern UnkStruct_P16 D_004D2268;
extern UnkStruct_P16 D_004D2278;
extern UnkStruct_P16 D_004D2288;
extern UnkStruct_P16 D_004D2298;
extern UnkStruct_P16 D_004D22A8;
extern UnkStruct_P16 D_004D22C0;
extern UnkStruct_P16 D_004D22D8;
extern UnkStruct_P16 D_004D22E8;
extern UnkStruct_P16 D_004D22F8;
extern UnkStruct_P16 D_004D21F0;
extern UnkStruct_P16 D_01E90438;
extern UnkStruct_P16 D_01E89544;
extern UnkStruct_P16 D_01E89518;
extern UnkStruct_P16 D_01E89800;
extern UnkStruct_P16 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void func_004407B0(void *);
extern "C" void func_00440A20(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void Copy__10CGtUnicodeFPUsPCUs(void *, void *);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

extern "C" int func_00441100(UnkStruct_00441100 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_8 = &D_004D2250;
    self->field_C = (void *)func_004407B0;
    self->field_10 = self;
    func_00441100_inl1(&self->field_18[0], &D_004D2268, 1, 1, D_0064D37C.field_0, 1);
    func_00441100_inl1(&self->field_18[1], &D_004D2278, 0, 0, 0x7FFFFFFF, 100);
    func_00441100_inl1(&self->field_18[2], &D_004D2288, 0, 0, 0x7FFFFFFF, 1000);
    func_00441100_inl1(&self->field_18[3], &D_004D2298, 0, 0, 0x7FFFFFFF, 1);
    {
        UnkStruct_00441100_f *f = (UnkStruct_00441100_f *)&self->field_18[4];
        f->field_0 = &D_004D22A8;
        f->field_4 = 60.0f;
        f->field_8 = 0;
        f->field_C = 3600.0f;
        f->field_10 = 1.0f;
    }
    func_00441100_inl2(&self->field_90[0], &D_004D22C0, !D_0051B38C.field_0);
    func_00441100_inl2(&self->field_90[1], &D_004D22D8, D_004E2F88);
    func_00441100_inl2(&self->field_90[2], &D_004D22E8, D_004E2F8C);
    self->field_B4 = &D_004D22F8;
    self->field_B8 = D_004E2F90;
    self->field_12C = 0;
    func_00440A20(self);
    int i;
    int n;
    for (i = 0; i < (n = self->field_12C); i++) {
        int *r = (int *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
        self->field_130[i] = r;
        char b[2] = {0, 0};
        Copy__10CGtUnicodeFPUsPCUs(self->field_130[i], b);
    }
    self->field_BC = 0;
    self->field_BE = n;
    for (i = 0; i < self->field_12C; i++) {
        self->field_108[i]->vfunc_14((int)self->field_130[i]);
        self->field_C0[i].field_0 = (int)self->field_130[i];
        self->field_C0[i].field_4 = 0;
        self->field_C0[i].field_5 = 0;
    }
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &self->field_BC, &self->field_C0[0], 640.0f);
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, &D_004D21F0, 5);
    func_0031ECD0(&D_01E89800, 261, 15);
    D_01E894FC.Prepare();
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)7);
    return 1;
}
