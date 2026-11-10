// NONMATCHING: func_00454D80 -- retail 178 / ours 178 instructions, 2 in changed runs
// fresh4: 2 off -- the D_01E900B4 == 2 compare constant lands in v1, retail a0; all else exact (tried operand order, switch, int/enum/unsigned, else-if chain, 8 pragmas, sreg run)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_00454D80 -- hand-written from scratch (the lifter refused it). Unnamed, so a placeholder with C linkage.
// Layout and types are [G] (instruction widths). [L] a menu page Prepare (CB3MenuPageBase::Prepare first, a list of
// 100 crash stages "<n><sep><name>", heading, list component, background, prompt bar; returns 1).

struct UnkStruct_00454D80_it { const unsigned short *field_0; unsigned char field_4; unsigned char pad_5[3]; };
struct UnkStruct_00454D80 {
    unsigned char pad_0[4];
    int field_4;
    bool field_8;
    unsigned char pad_9;
    short field_A;
    short field_C;
    unsigned char pad_E[2];
    UnkStruct_00454D80_it field_10[101];
    unsigned short *field_338[101];
};
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E900B4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E900BC { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E900B4 D_01E900B4;
extern UnkStruct_D_01E900BC D_01E900BC;
extern unsigned char D_0051BA44[];
extern unsigned char D_01E90438[];
extern unsigned char D_01E89518[];
extern unsigned char D_01E8970C[];
extern unsigned char D_01E88A80[];
extern unsigned char D_01E89800[];
extern unsigned char D_01E894FC[];
extern const unsigned short D_004D3410[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int func_003E9490(int, int);
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" unsigned short *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" unsigned short *PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int func_0013AD70(void *, int, int);
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" void func_00319C80(void *, int, int);
extern "C" void *func_001A3AA0(unsigned short *, const unsigned short *, int *);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, const unsigned short *, int);
extern "C" int func_0039BCD0(void *, void *, void *, int, int, float);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);

extern "C" int func_00454D80(UnkStruct_00454D80 *self, bool p1, int p2, unsigned long p3);

// 0x00454D80
int func_00454D80(UnkStruct_00454D80 *self, bool p1, int p2, unsigned long p3)
{
    int s7 = D_0051BF9C.field_0;
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_4 = 0;
    self->field_8 = p1;
    int i;
    int n = 0;
    if (self->field_8) {
        self->field_338[0] = func_00271A00(D_0051BA44, 0x2E0);
        n++;
        self->field_10[0].field_0 = self->field_338[0];
        self->field_10[0].field_4 = 0;
    }
    for (i = 0; i < 100; i++, n++) {
        unsigned short *name = func_00271A00(D_0051BA44, func_003E9490(i, 0));
        unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(D_01E90438, Length__10CGtUnicodeFPCUs(name) + 6);
        Append__10CGtUnicodeFPUsPCUs(Append__10CGtUnicodeFPUsPCUs(PrintInt__10CGtUnicodeFPUsii(s, i + 1, 0, 0), D_004D3410), name);
        self->field_338[n] = s;
        int r = func_0013AD70((void *)(s7), i, 0);
        self->field_10[n].field_0 = self->field_338[n];
        self->field_10[n].field_4 = r;
        if (GetCrashStageGtID__26CB3HardCodedCrashStageListFi(i) == p3) {
            self->field_4 = n;
        }
    }
    if (p2 == -1) {
        if (D_01E900B4.field_0 == 2) {
            if (D_01E900BC.field_0 != 3) {
                func_00319C80(D_01E89518, 0x162, 14);
            } else {
                func_00319C80(D_01E89518, 0x163, 14);
            }
        } else {
            func_00319C80(D_01E89518, 0x16D, 14);
        }
    } else {
        unsigned short *fmt = func_00271A00(D_0051BA44, 0xB39);
        unsigned short *s = AllocUTF16String__19CB3MenuStringBufferFi(D_01E90438, Length__10CGtUnicodeFPCUs(fmt) + 4);
        int v = p2 + 1;
        func_001A3AA0(s, fmt, &v);
        Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(D_01E89518, s, 14);
    }
    self->field_A = self->field_4;
    self->field_C = n;
    func_0039BCD0(D_01E8970C, &self->field_A, self->field_10, 0, 1, 516.0f);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(D_01E88A80, 0);
    func_0031ECD0(D_01E89800, 0x111, 3);
    Prepare__21CB3PromptBarComponentFv(D_01E894FC);
    return 1;
}
