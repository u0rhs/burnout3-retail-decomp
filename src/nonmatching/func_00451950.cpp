// NONMATCHING: func_00451950 -- retail 389 / ours 389 instructions, 22 in changed runs
// near33: 48->22, 389=389. 'float f = 20.0f; f += field_0;' (FP numbering); g += field_0 + z*field_8 (named z, no extra add -> adda/madd); ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi via 'buf = Alloc(); src = x + 4; x = buf; ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(src, buf, 16)'; pos.x as 'g + o' with 'float o = -30.0f'. Left: PrepareCommonData arg scheduling only -- retail stores anchor (1.0/0.5) and pos.y before loading col (lq a0 from s4, sq 0xC0 last); ours loads col (named copy 'col = *pc') first into t0. Passing *pc directly elides the copy (frame -0x10; with an N140 pad 29 off); CGtV4d(*pc) temp adds 6 instrs. NB: the archive's UnkStruct_00451950_pad is a real struct (field_1B4) -- rename it (e.g. _gm) before adding any N140 pad
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// NONMATCHING: func_00451950 -- retail 389 / ours 390 instructions, 48 in changed runs
// a227: 48 off (was 63). N186 fix: the CGtV2d scale result goes through a static inline with a local r (inl2(dst,a,b){CGtV2d r=a/b; dst=r;}) -> frame slots now match retail. left: 20.0f/x0 float reg order, move a1,v0/move s2,v0 order, PrepareCommonData arg scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: func_00451950 -- retail 389 / ours 390 instructions, 63 in changed runs
// a179: logic complete, 389 vs 390 instrs, 63 changed. Left: frame slot of scale-CGtV2d result temp (retail D8 beside inline local r at D0 below the image temps; ours 0x108 in arg-temp order), f20 20.0f/x0 float reg order (f1/f0), ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi 'move a1,v0; move s2,v0' order, PCD col lq reg (a0 vs t0). s6 is bool np + separate int id; online is int; x uninitialised char* shared by rec/str
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;
    unsigned char pad_0[0x10];
};
struct UnkStruct_00451950_vo {
        virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual int vfunc_F0();
};
struct UnkStruct_00451950_pad { unsigned char pad_0[0x1B4]; UnkStruct_00451950_vo * field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_00451950_pad * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00451950_rec { unsigned char pad_0[0x44]; int field_44; };
struct UnkStruct_00451950_fr { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_00451950_txt {
    unsigned char pad_0[8];
    CGtV2d field_8;
    unsigned char pad_10[0x1C];
    int field_2C;
    CGtV2d field_30;
};
struct UnkStruct_00451950_row {
    UnkStruct_00451950_fr * field_0;
    unsigned char pad_4[4];
    void * field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    void * field_18;
    UnkStruct_00451950_txt * field_1C;
    void * field_20;
};
struct UnkStruct_00451950 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_00451950_row field_C[8];
    unsigned char pad_12C[0x14];
    const unsigned short * field_140[16];
    int field_180[8];
    int field_1A0[8];
    signed char field_1C0[8];
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern CGtNetworkPlayerManager D_01E32AE0;
extern "C" void func_00453680(void *, int, int, int);
extern "C" void *func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" UnkStruct_00451950_rec * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);
extern "C" int func_003900E0(void *, int, int);
extern "C" int func_003C28A0(void *, int);
extern "C" void func_0044CF90(void *, int, float);
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_byte D_01E65499;
extern UnkStruct_D_byte D_01ECDAC9;
extern int D_01EA4B80[];
extern int D_0051BA00[];
extern int D_0051B9E0[];
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_0051B988;
extern UnkStruct_Pad16 D_0051BA44;
extern UnkStruct_Pad16 D_01E903E0;
extern UnkStruct_Pad16 D_01E90438;
extern CGtV4d D_01E903C0;
extern CGtV4d D_01E90250;
extern CGtV4d D_01E90350;
extern int D_00665ED0[4];
struct UnkStruct_D_4D3130 { CGtV2d field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_4D3130 D_004D3130;
extern UnkStruct_Pad16 D_0064ED24;
extern int D_01EA4738[];
extern int D_01EA4758[];
extern UnkStruct_Pad16 D_01EA4790;
extern UnkStruct_Pad16 D_01EA4798;
extern "C" void * func_00271A00(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const void *, void *, int);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const void *, const CGtV2d *, int);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, void *, const void *, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const void *, const void *, unsigned int);
extern "C" void func_00453980(void *, const void *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);

static inline CGtV2d func_00451950_inl1(const CGtV2d &a, const CGtV2d &b)
{
    CGtV2d r = a / b;
    return r;
}
static inline void func_00451950_inl2(CGtV2d &dst, const CGtV2d &a, const CGtV2d &b)
{
    CGtV2d r = a / b;
    dst = r;
}
// 0x00451950
extern "C" void func_00451950(UnkStruct_00451950 *self, int i, int j, int k)
{
    CGtV4d col;
    func_00453680(self, i, 6, 4);
    int online = D_01E65499.field_0;
    bool np = true;
    int id;
    char *x;
    int s1;
    if (online != 0) {
        UnkStruct_00451950_vo *vo = D_0051BA88.field_0->field_1B4;
        void *pl = func_002366D0(&D_01E32AE0, k);
        if (pl != 0) {
            id = func_0022FBB0(pl);
            x = (char *)GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
            if (x == 0) {
                s1 = D_01EA4B80[k];
            } else {
                s1 = ((UnkStruct_00451950_rec *)x)->field_44;
                if (s1 < 0) s1 = D_01EA4B80[k];
            }
            np = false;
            self->field_1C0[j] = func_003900E0(vo, s1, id);
        } else {
            s1 = vo->vfunc_F0();
            self->field_1C0[j] = func_003900E0(vo, s1, GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0));
        }
        int *pk = &D_01EA4B80[k];
        self->field_180[j] = *pk;
        if (s1 != 0) {
            self->field_1A0[j] = s1;
        } else {
            self->field_1A0[j] = self->field_180[j];
        }
        *pk = self->field_1A0[j];
    } else {
        self->field_1C0[j] = func_003C28A0(&D_0051B988, k);
        self->field_1A0[j] = D_0051BA00[k];
        self->field_180[j] = self->field_1A0[j] - D_0051B9E0[k];
    }
    func_0044CF90(self, j, 0.0f);
    UnkStruct_00451950_row *e = &self->field_C[i];
    float f = 20.0f;
    f += e->field_0->field_0;
    e->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
    const unsigned short *str = (const unsigned short *)func_00271A00(&D_0051BA44, j + 0x260);
    const CGtV4d * const pc = &D_01E903C0;
    func_0033D4E0(e->field_10, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 28.0f, pc, (void *)(D_00665ED0[0]), str, &D_004D3130.field_0, 2);
    float g;
    int sid;
    if (D_01ECDAC9.field_0 != 0) {
        g = 60.0f;
        sid = k + 0x257;
    } else {
        sid = k + 0x309;
        g = 60.0f;
    }
    if (online != 0) {
        if (np) {
            x = (char *)&D_0064ED24;
        } else if (x != 0) {
            char *buf = (char *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
            char *src = x + 4;
            x = buf;
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(src, buf, 16);
        } else {
            x = (char *)func_00271A00(&D_0051BA44, 0x26B);
        }
    } else {
        x = (char *)func_00271A00(&D_0051BA44, sid);
    }
    str = (const unsigned short *)x;
    float z = 0.0f;
    g += e->field_0->field_0 + z * e->field_0->field_8;
    e->field_14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
    func_0033D4E0(e->field_14, CGtV2d(g, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &D_01E90250, (void *)(D_00665ED0[0]), str, &D_004D3130.field_0, 2);
    const unsigned short *sub = self->field_140[j];
    if (sub != 0) {
        float g = e->field_0->field_0 + e->field_0->field_8;
        e->field_1C = (UnkStruct_00451950_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
        col = *pc;
        float o = -30.0f;
        UnkStruct_00451950_txt *t = e->field_1C;
        PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, CGtV2d(g + o, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, col, (void *)(D_00665ED0[0]), sub, (void *)func_00453980);
        func_00451950_inl2(t->field_30, D_004D3130.field_0, t->field_8);
        t->field_2C = 0;
    }
    if (D_01ECDAC9.field_0 != 0) {
        int k2 = k * 2;
        e->field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(e->field_20, CGtV2d(270.0f, 0.0f), CGtV2d(0.5f, 0.5f), CGtV2d(80.0f, 40.0f), D_01E90350, (void *)(D_01EA4738[k2]), &D_01EA4790, &D_01EA4798, D_01EA4758[k2]);
        k = k2 + 1;
    }
    e->field_18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(e->field_18, CGtV2d(370.0f, 0.0f), CGtV2d(0.5f, 0.5f), CGtV2d(80.0f, 40.0f), D_01E90350, (void *)(D_01EA4738[k]), &D_01EA4790, &D_01EA4798, D_01EA4758[k]);
}
