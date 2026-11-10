// NONMATCHING: func_003A5040 -- retail 624 / ours 625 instructions, 200 in changed runs
// a179: logic complete (all 5 modes incl. 0/1/2 record lists, 3/4 string table), 625 vs 624 instrs, 200 changed -- nearly all s-register numbering inside the case bodies (retail reuses scene's s2 as loop index i in case 1/2/0, ours picks s0=mgr); block layout, frame size 0x1E0 (arrays declared t1D0,t170,a150,a130,a110,aF0,aD0,c0 = first declared highest) and temp slot order already match. Decl order mgr, f, scene fixes s0/s2; f/i swap (retail f=s1,i=s3) not reachable by declaration order. Pieces: Compare is the static Compare(PUs,PUs) taking func_003D0B60(&records) result; p->field_18 read as int (ustrFromInt) and float (func_003B8750/8670); field_CC is a char* base + (i<<5).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_003A5040_rec {
    unsigned char pad_0[0x12];
    unsigned char field_12;
    unsigned char field_13;
    unsigned char pad_14[4];
    int field_18;
};
struct UnkStruct_003A5040 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[6];
    unsigned long field_10;
    unsigned char pad_18[0x44];
    void * field_5C;
    unsigned char pad_60[0x20];
    void * field_80[6][3];
    int field_C8;
    char * field_CC;
    void * field_D0;
    void * field_D4;
};
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x120]; CGtV4d field_120; CGtV4d field_130; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_F16 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_Pad16 D_01E903E0;
extern UnkStruct_Pad16 D_01EA7810;
extern UnkStruct_Pad16 D_0051BA44;
extern UnkStruct_F16 D_004C9E28;
extern UnkStruct_F16 D_004C9E98;
extern unsigned short D_004C9EC0[];
extern unsigned short D_004C9ED8[];
extern unsigned short D_004C9EE0[];
extern unsigned short D_01EA4CC0[][9];
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Prepare__19CGt2dObjectVignetteFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4dQ219CGt2dObjectVignette13EVignetteType(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtV4d, void *);
extern "C" UnkStruct_003A5040_rec * func_003D1000(void *, unsigned long);
extern "C" UnkStruct_003A5040_rec * GetTrackRecords__10CB3RecordsFUl(void *, unsigned long);
extern "C" const unsigned short * func_003D0B60(void *);
extern "C" int Compare__15CGtUnicodeUtilsFPUsPUs(const unsigned short *, const unsigned short *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" unsigned short * func_003A3D30(void *, int, int, const unsigned short *);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" void ustrFromInt(unsigned short *, int, int, int);
extern "C" unsigned short *func_003B8670(unsigned short *, float);
extern "C" void func_003B8750(unsigned short *, float);
extern "C" int func_003F5FB0(int);
extern "C" void func_003A46A0(void *, int, int, const unsigned short **);
extern "C" void func_003A4A80(void *, int, int, const unsigned short **, const unsigned short **, const unsigned short **, const int *, const int *, unsigned long);

// 0x003A5040
extern "C" void func_003A5040(UnkStruct_003A5040 *self, int p1)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    const unsigned short *t1D0[3];
    const unsigned short *t170[5];
    int a150[8];
    int a130[8];
    const unsigned short *a110[8];
    const unsigned short *aF0[8];
    const unsigned short *aD0[8];
    unsigned char c0;
    void *f = self->field_D4;
    UnkStruct_Pad16 * const scene = &D_01E903E0;
    if (f == 0) f = self->field_D0;
    int i;
    for (i = 0; i < 6; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            void **p = &self->field_80[i][j];
            if (*p != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, *p);
                *p = 0;
            }
        }
    }
    if (self->field_5C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_5C);
        self->field_5C = 0;
    }
    switch (self->field_C8) {
    case 1: {
        UnkStruct_003A5040_rec *r = func_003D1000(&D_01EA7810, self->field_10);
        self->field_5C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, f);
        Prepare__19CGt2dObjectVignetteFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4dQ219CGt2dObjectVignette13EVignetteType(self->field_5C, CGtV2d(D_004C9E28.field_0 - 5.0f, 160.0f), CGtV2d(0.0f, 0.5f), CGtV2d(D_004C9E98.field_0, 2.0f), mgr->field_130, mgr->field_120, (void *)(0));
        t1D0[0] = func_00271A00(&D_0051BA44, 0x299);
        t1D0[2] = func_00271A00(&D_0051BA44, 0x29B);
        t1D0[1] = func_00271A00(&D_0051BA44, 0x9AC);
        for (i = 0; i < 5; i++) {
            UnkStruct_003A5040_rec *p = (UnkStruct_003A5040_rec *)((char *)r + i * 0x1C);
            a110[i] = (const unsigned short *)p;
            a150[i] = p->field_12;
            a130[i] = p->field_13;
            if (Compare__15CGtUnicodeUtilsFPUsPUs(func_003D0B60(&D_01EA7810), a110[i]) == 0) {
                Copy__10CGtUnicodeFPUsPCUs((unsigned short *)(self->field_CC + (i << 5)), D_004C9ED8);
                unsigned short *s = D_01EA4CC0[i];
                Copy__10CGtUnicodeFPUsPCUs(s, D_004C9EE0);
                a110[i] = s;
                a130[i] = -999;
            } else {
                a110[i] = func_003A3D30(self, 0, i, a110[i]);
                ustrFromInt((unsigned short *)(self->field_CC + (i << 5)), p->field_18, 1, 0);
            }
            aF0[i] = (const unsigned short *)(self->field_CC + (i << 5));
        }
        func_003A4A80(self, 3, 5, t1D0, a110, aF0, a150, a130, 0);
        break;
    }
    case 2: {
        UnkStruct_003A5040_rec *r = func_003D1000(&D_01EA7810, self->field_10);
        self->field_5C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, f);
        Prepare__19CGt2dObjectVignetteFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4dQ219CGt2dObjectVignette13EVignetteType(self->field_5C, CGtV2d(D_004C9E28.field_0 - 5.0f, 160.0f), CGtV2d(0.0f, 0.5f), CGtV2d(D_004C9E98.field_0, 2.0f), mgr->field_130, mgr->field_120, (void *)(0));
        t1D0[0] = func_00271A00(&D_0051BA44, 0x1B9);
        t1D0[1] = func_00271A00(&D_0051BA44, 0x1BA);
        t1D0[2] = func_00271A00(&D_0051BA44, 0x9AC);
        char *base = (char *)r + 0x8C;
        for (i = 0; i < 5; i++) {
            UnkStruct_003A5040_rec *p = (UnkStruct_003A5040_rec *)(base + i * 0x30);
            a110[i] = (const unsigned short *)p;
            a150[i] = p->field_12;
            a130[i] = p->field_13;
            if (Compare__15CGtUnicodeUtilsFPUsPUs(func_003D0B60(&D_01EA7810), a110[i]) == 0) {
                Copy__10CGtUnicodeFPUsPCUs((unsigned short *)(self->field_CC + (i << 5)), D_004C9ED8);
                unsigned short *s = D_01EA4CC0[i];
                Copy__10CGtUnicodeFPUsPCUs(s, D_004C9EE0);
                aF0[i] = s;
                a110[i] = s;
            } else {
                a110[i] = func_003A3D30(self, 0, i, a110[i]);
                ustrFromInt((unsigned short *)(self->field_CC + (i << 5)), p->field_18, 1, 0);
                const unsigned short *a3 = (const unsigned short *)((char *)p + 0x1C);
                aF0[i] = a3;
                aF0[i] = func_003A3D30(self, 1, i, a3);
            }
            aD0[i] = (const unsigned short *)(self->field_CC + (i << 5));
        }
        func_003A4A80(self, 3, 5, t1D0, a110, aF0, a150, a130, (unsigned long)aD0);
        break;
    }
    case 0: {
        UnkStruct_003A5040_rec *r = GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, self->field_10);
        c0 = 0;
        int fp = 0;
        self->field_5C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, f);
        Prepare__19CGt2dObjectVignetteFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4dQ219CGt2dObjectVignette13EVignetteType(self->field_5C, CGtV2d(D_004C9E28.field_0 - 5.0f, 160.0f), CGtV2d(0.0f, 0.5f), CGtV2d(D_004C9E98.field_0, 2.0f), mgr->field_130, mgr->field_120, (void *)(0));
        t1D0[0] = func_00271A00(&D_0051BA44, 0x299);
        t1D0[2] = func_00271A00(&D_0051BA44, 0x29B);
        char *base;
        switch (p1) {
        case 0:
            base = (char *)r;
            t1D0[1] = func_00271A00(&D_0051BA44, 0x29A);
            fp = 1;
            break;
        case 1:
            base = (char *)r + 0x8C;
            t1D0[1] = func_00271A00(&D_0051BA44, 0x2BD);
            c0 = 1;
            break;
        case 2:
            base = (char *)r + 0x118;
            t1D0[1] = func_00271A00(&D_0051BA44, 0x2BF);
            break;
        case 3:
            base = (char *)r + 0x1A4;
            t1D0[1] = func_00271A00(&D_0051BA44, 0x2BF);
            break;
        }
        for (i = 0; i < 5; i++) {
            UnkStruct_003A5040_rec *p = (UnkStruct_003A5040_rec *)(base + i * 0x1C);
            a110[i] = (const unsigned short *)p;
            a150[i] = p->field_12;
            a130[i] = p->field_13;
            if (c0 != 0) {
                if (Compare__15CGtUnicodeUtilsFPUsPUs(func_003D0B60(&D_01EA7810), a110[i]) == 0) {
                    Copy__10CGtUnicodeFPUsPCUs((unsigned short *)(self->field_CC + (i << 5)), D_004C9EE0);
                    unsigned short *s = D_01EA4CC0[i];
                    Copy__10CGtUnicodeFPUsPCUs(s, D_004C9EE0);
                    a110[i] = s;
                    a130[i] = -999;
                } else {
                    a110[i] = func_003A3D30(self, 0, i, a110[i]);
                    ustrFromInt((unsigned short *)(self->field_CC + (i << 5)), p->field_18, 1, 0);
                }
            } else if (Compare__15CGtUnicodeUtilsFPUsPUs(func_003D0B60(&D_01EA7810), a110[i]) == 0) {
                if (fp != 0) {
                    Copy__10CGtUnicodeFPUsPCUs((unsigned short *)(self->field_CC + (i << 5)), D_004C9EC0);
                } else {
                    Copy__10CGtUnicodeFPUsPCUs((unsigned short *)(self->field_CC + (i << 5)), D_004C9EE0);
                }
                unsigned short *s = D_01EA4CC0[i];
                Copy__10CGtUnicodeFPUsPCUs(s, D_004C9EE0);
                a110[i] = s;
                a130[i] = -999;
            } else {
                a110[i] = func_003A3D30(self, 0, i, a110[i]);
                if (fp != 0) {
                    func_003B8750((unsigned short *)(self->field_CC + (i << 5)), *(float *)&p->field_18);
                } else {
                    func_003B8670((unsigned short *)(self->field_CC + (i << 5)), *(float *)&p->field_18);
                }
            }
            aF0[i] = (const unsigned short *)(self->field_CC + (i << 5));
        }
        func_003A4A80(self, 3, 5, t1D0, a110, aF0, a150, a130, 0);
        break;
    }
    case 4:
    case 3: {
        int n = p1 * 5;
        t170[0] = func_00271A00(&D_0051BA44, func_003F5FB0(n));
        t170[1] = func_00271A00(&D_0051BA44, func_003F5FB0(n + 1));
        t170[2] = func_00271A00(&D_0051BA44, func_003F5FB0(n + 2));
        t170[3] = func_00271A00(&D_0051BA44, func_003F5FB0(n + 3));
        t170[4] = func_00271A00(&D_0051BA44, func_003F5FB0(n + 4));
        func_003A46A0(self, p1, 5, t170);
        break;
    }
    }
}
