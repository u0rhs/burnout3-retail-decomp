// NONMATCHING: func_003FD850 -- retail 299 / ours 299 instructions, 133 in changed runs
// a156: 299/299 instrs, 133 in changed runs. Layout/control flow/switch exact (jtbl case order 0..6 = 0,2F0,2F2,2F1,2F3,2F4,field_48 test). Left: (1) retail's by-value CGtV2d call args are separate sw/swc1 constant copies (0xF8/F0/E8 and 0xC8/C0/B8) from literal temps (0x110/108/100, 0xE0/D8/D0) while ours does ld/sd copies of named locals; (2) constant-register choice in the 140.0/5.0 stores (a1/a0 vs a0/v1); (3) template-copy load scheduling (lq/ld/lwc1 order); (4) lq 0x10(s7) colour copy ordering
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a156): options/menu page setup -- sets the page layout globals, builds seven row records from a
// template, then prepares the table component.
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_Wf { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Wi { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_003FD850_e {   // [G] 0x190-byte row record; first 0x50 bytes are a template copy
    CGtV4d field_0;
    CGtV4d field_10;
    CGtV4d field_20;
    unsigned long field_30;
    unsigned long field_38;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
    unsigned char pad_50[0x190 - 0x50];
};
struct UnkStruct_003FD850_f { void *field_0; void *field_4; void *field_8; unsigned char pad_C[0x30]; };
struct UnkStruct_003FD850_t {  // [G] the 0x50 template
    CGtV4d field_0; CGtV4d field_10; CGtV4d field_20; unsigned long field_30; unsigned long field_38; float field_40; int field_44; int field_48; int field_4C;
};
struct UnkStruct_003FD850 {
    unsigned char pad_0[0x8];
    CGtV2d field_8;
    CGtV2d field_10;
    CGtV2d field_18;
    unsigned char pad_20[0x28];
    unsigned char field_48;
    unsigned char field_49;
};
struct UnkStruct_D_01EA5650 { float field_0; int field_4; int field_8; };

extern UnkStruct_Wi D_01EA5638;
extern UnkStruct_D_01EA5650 D_01EA5650[7];
extern UnkStruct_Wf D_01EA56C0;
extern UnkStruct_Wf D_01EA56C4;
extern UnkStruct_Wf D_01EA56CC;
extern UnkStruct_Wf D_01EA56D0;
extern UnkStruct_Wi D_01EA56D8;
extern UnkStruct_Wi D_01EA56DC;
extern UnkStruct_Wf D_01EA56E4;
extern UnkStruct_Wf D_01EA56E8;
extern UnkStruct_003FD850_e D_01EA5A80[7];
extern UnkStruct_003FD850_f D_01EA6890[7];
struct UnkStruct_Wq { CGtV4d field_0; };
struct UnkStruct_Wl { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_Wfl { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_Wq D_01EA6AF0;
extern UnkStruct_Wq D_01EA6B00;
extern UnkStruct_Wq D_01EA6B10;
extern UnkStruct_Wl D_01EA6B20;
extern UnkStruct_Wl D_01EA6B28;
extern UnkStruct_Wfl D_01EA6B30;
extern UnkStruct_Wi D_01EA6B34;
extern UnkStruct_Wi D_01EA6B38;
extern UnkStruct_Wi D_01EA6B3C;
extern UnkStruct_Pad16 D_01EA5630;
extern UnkStruct_Pad16 D_01EA6B40;
extern UnkStruct_Pad16 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;
extern float D_004E0C74;
class CB3TableComponent {
public:
    void RecalculateSize();
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
extern CB3TableComponent D_01E8D450;
extern "C" void func_003C1FC0();
extern "C" int func_00271A00(void *, int);
extern "C" int func_0033FF10(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, int, void *, void *, int);
extern "C" void RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

extern "C" void func_003FD850(UnkStruct_003FD850 * self)
{
    int i;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    func_003C1FC0();
    D_01EA5638.field_0 = 7;
    for (i = 0; i < 7; i++) {
        D_01EA5650[i].field_0 = 10.0f;
    }
    int flag;
    if (self->field_49 != 0) {
        D_01EA56C4.field_0 = 150.0f;
        D_01EA56C0.field_0 = 40.0f;
        D_01EA56D0.field_0 = 140.0f;
        D_01EA56CC.field_0 = 5.0f;
        flag = 0;
        D_01EA56DC.field_0 = 0;
        D_01EA56D8.field_0 = 0;
        D_01EA56E8.field_0 = 140.0f;
        D_01EA56E4.field_0 = 5.0f;
    } else {
        D_01EA56C4.field_0 = 150.0f;
        D_01EA56C0.field_0 = 40.0f;
        flag = 1;
        D_01EA56D0.field_0 = 140.0f;
        D_01EA56CC.field_0 = 5.0f;
    }
    for (i = 0; i < D_01EA5638.field_0; i++) {
        UnkStruct_003FD850_e * e = &D_01EA5A80[i];
        bool keep = true;
        CGtV4d * col = &e->field_20;
        CGtV2d * anc = (CGtV2d *)&e->field_30;
        int * id = &e->field_48;
        float * sz = &e->field_40;
        e->field_0 = D_01EA6AF0.field_0;
        e->field_10 = D_01EA6B00.field_0;
        e->field_20 = D_01EA6B10.field_0;
        e->field_30 = D_01EA6B20.field_0;
        e->field_38 = D_01EA6B28.field_0;
        e->field_40 = D_01EA6B30.field_0;
        e->field_44 = D_01EA6B34.field_0;
        e->field_48 = D_01EA6B38.field_0;
        e->field_4C = D_01EA6B3C.field_0;
        {
            switch (i) {
            case 0:
                *id = 0;
                keep = false;
                break;
            case 1:
                *id = func_00271A00(&D_0051BA44, 0x2F0);
                break;
            case 2:
                *id = func_00271A00(&D_0051BA44, 0x2F2);
                break;
            case 3:
                *id = func_00271A00(&D_0051BA44, 0x2F1);
                break;
            case 4:
                *id = func_00271A00(&D_0051BA44, 0x2F3);
                break;
            case 5:
                *id = func_00271A00(&D_0051BA44, 0x2F4);
                break;
            case 6:
                if (self->field_48 == 0) {
                    *id = 0;
                    keep = false;
                } else {
                    *id = func_00271A00(&D_0051BA44, 0x304);
                }
                break;
            }
        }
        if (keep) {
            CGtV2d half(0.0f, 0.5f);
            *anc = half;
            D_01EA6890[i].field_0 = (void *)RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[i].field_4 = (void *)GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            D_01EA6890[i].field_8 = e;
            *col = mgr->field_10;
            *sz = 20.0f;
        } else {
            D_01EA6890[i].field_0 = 0;
            D_01EA6890[i].field_4 = 0;
            D_01EA6890[i].field_8 = 0;
        }
    }
    if (self->field_49 != 0) {
        CGtV2d a(70.0f, 95.0f);
        CGtV2d b(0.0f, 0.0f);
        CGtV2d c(500.0f, 305.0f);
        self->field_8 = a;
        self->field_10 = b;
        self->field_18 = c;
        func_0033FF10(&D_01E8D450, CGtV2d(a), CGtV2d(b), CGtV2d(c), flag, &D_01EA5630, &D_01EA6B40, 0);
    } else {
        CGtV2d a(D_004E0C74, 95.0f);
        CGtV2d b(0.0f, 0.0f);
        CGtV2d c(355.0f, 305.0f);
        self->field_8 = a;
        self->field_10 = b;
        self->field_18 = c;
        func_0033FF10(&D_01E8D450, CGtV2d(a), CGtV2d(b), CGtV2d(c), flag, &D_01EA5630, &D_01EA6B40, 0);
    }
    D_01E8D450.RecalculateSize();
}
