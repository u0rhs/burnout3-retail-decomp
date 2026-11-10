// Hand-written; the lifter refused it (a150: Optimatch results rebuild; rec[9] member array at 0x60 (stride 80), idx-first via 'int ix' + member-array reads, buf declared in loop, 0x608 store base self+400*i, vec temps as call-arg temporaries).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_0037B770_rec {
    unsigned char pad_0[0x60];
    char field_60[0x38];
    int field_98;
    int field_9C;
    int field_A0;
    unsigned char pad_A4[0x4];
    int field_A8;
    unsigned char pad_AC[0x4];
};
struct UnkStruct_0037B770_c80 { unsigned char pad_0[0x50]; };
struct UnkStruct_0037B770_c608 { unsigned char pad_0[0x608]; void * field_608; };
struct UnkStruct_0037B770_q64 { u_long128 field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_0037B770_rec2 {
    char field_0[0x38];
    int field_38;
    int field_3C;
    int field_40;
    unsigned char pad_44[0x4];
    int field_48;
    unsigned char pad_4C[0x4];
};
struct UnkStruct_0037B770 {
    unsigned char pad_0[0x60];
    UnkStruct_0037B770_rec2 field_60[9];
    unsigned short field_330;
    unsigned short field_332;
    unsigned char pad_334[0x12E0 - 0x334];
    UnkStruct_0037B770_q64 field_12E0[8];
    unsigned char pad_14E0[0x1524 - 0x14E0];
    unsigned short * field_1524[10];
    unsigned short * field_154C[10];
    unsigned char pad_1574[0x4];
    CGtV2d field_1578;
    unsigned char pad_1580[0x1920 - 0x1580];
    int field_1920;
    unsigned char pad_1924[0x4];
    int field_1928;
    unsigned char pad_192C[0x1942 - 0x192C];
    unsigned char field_1942;
};
struct UnkStruct_D_01E90240 { u_long128 field_0; u_long128 field_10; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Ptr16 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_Byte16 D_01E8D4BA, D_01E8D45A, D_01E8D49A, D_01E8EB02;
extern UnkStruct_D_vt D_01E8D4B0, D_01E8D450, D_01E8D490, D_01E8EAF8;
extern UnkStruct_D_Ptr16 D_01E8D45C;
extern UnkStruct_D_Pad16 D_01E89800, D_0051BA44, D_004C9218, D_004C91C8, D_004C9148, D_004C9150, D_004C9158, D_004C9160, D_004C9168, D_004C9170, D_004C9178;
extern int D_004C9180[];
extern "C" void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern "C" int func_0037B6C0(const void *, const void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" void func_0037A360(void *, int, int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" void Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, void *, bool, bool);
extern "C" void Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(void *, int, void *, void *);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, const void *, const void *, float, const void *);

// 0x0037B770
extern "C" int func_0037B770(UnkStruct_0037B770 * self)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    int i;
    if (self->field_1920 == 0) {
        self->field_1942 = 2;
        if (D_01E8D4BA.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8D4B0)->vfunc_C();
        if (D_01E8D45A.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8D450)->vfunc_C();
        if (D_01E8D49A.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8D490)->vfunc_C();
        if (D_01E8EB02.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8EAF8)->vfunc_C();
        func_00351F00(&D_01E8D4B0, &D_004C9148, &D_004C9150, &D_004C9158, &D_004C9160, &D_004C9168, 0x64, 3, 0, 1, 0, 32.0f, 400.0f);
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x41 | ((unsigned long)0x40 << 32), 0);
        return 1;
    }
    if (self->field_1928 == 1) return 1;
    self->field_1942 = 1;
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8D4B0)->vfunc_C();
        CGtV2d va, vb, vc;
        Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(&D_01E8D450, (va.Set(48.0f, 112.0f), va), (vb.Set(0.0f, 0.0f), vb), (vc.Set(544.0f, 256.0f), vc), &self->field_1578, true, false);
        Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(&D_01E8D490, 1, D_01E8D45C.field_0, &self->field_330);
        RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
        Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C9170, &D_004C9178, 256.0f, &self->field_330);
    }
    qsort(self->field_60, self->field_1920, 0x50, func_0037B6C0);
    for (i = 0; i < self->field_1920; i++) {
#define R (&self->field_60[i])
#define ROW ((char *)self + i * 60)
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(R->field_0, self->field_154C[i], 0x20);
        func_0037A360(self, i, R->field_38);
        if (R->field_48 == -1) {
            *(void **)(ROW + 0x16B0) = 0;
            *(void **)(ROW + 0x16AC) = 0;
        } else {
            unsigned short * s = func_00271A00(&D_0051BA44, D_004C9180[R->field_48]);
            *(void **)((char *)self + i * 400 + 0x608) = s;
            *(void **)(ROW + 0x16B0) = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            *(void **)(ROW + 0x16AC) = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        }
        int a3v = R->field_3C;
        int t0v = R->field_40;
        if (a3v == -1) {
            *(void **)(ROW + 0x16B8) = 0;
            *(void **)(ROW + 0x16BC) = 0;
        } else {
            char buf[6];
            snprintf(buf, 6, (const char *)&D_004C91C8, a3v, t0v);
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_1524[i], 6);
            *(void **)(ROW + 0x16B8) = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            *(void **)(ROW + 0x16BC) = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        }
    }
    for (; i < 9; i++) {
        *(void **)(ROW + 0x1688) = 0;
        *(void **)(ROW + 0x168C) = 0;
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi((const char *)&D_004C9218, self->field_154C[i], 0x20);
        func_0037A360(self, i, 5);
        *(void **)(ROW + 0x16B0) = 0;
        *(void **)(ROW + 0x16AC) = 0;
        *(void **)(ROW + 0x16B8) = 0;
        *(void **)(ROW + 0x16BC) = 0;
    }
#undef R
#undef ROW
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    {
        int cur = self->field_330;
        int n = self->field_1920;
        if (cur < n) {
            self->field_330 = cur;
            self->field_332 = n;
        } else {
            self->field_330 = n - 1;
            self->field_332 = n;
        }
        if (cur != -1) {
            int j;
            for (j = 0; j < 5; j++) {
                *(u_long128 *)((char *)self + cur * 400 + j * 80 + 0x4F0) = mgr->field_0;
                *(u_long128 *)((char *)self + self->field_330 * 400 + j * 80 + 0x4F0) = mgr->field_10;
            }
            self->field_12E0[cur].field_0 = mgr->field_0;
            *(u_long128 *)((char *)self + self->field_330 * 64 + 0x12E0) = mgr->field_10;
        }
    }
    {
        int ix = self->field_330;
        int lo = self->field_60[ix].field_3C;
        int hi = self->field_60[ix].field_40;
        if (lo < hi) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
        } else {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x141, 3);
        }
    }
    return 1;
}
