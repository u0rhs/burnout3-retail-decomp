// NONMATCHING: func_003B9880 -- retail 183 / ours 182 instructions, 32 in changed runs
// left: retail builds the loop's CGtV2d(0,0) temp with mtc1 zero + swc1 (ours sw zero; likely the GtMathPs2 ctor body, N149-style header gap) which shifts the float-constant schedule; plus template lq a1/a3 swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// from build/vt\try_func_003B9880_best.cpp
// func_003B9880 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

class CB3TableComponent;
struct UnkStruct_003B9880;
struct UnkStruct_003B9880_13;
struct UnkStruct_003B9880_e0;
struct UnkStruct_003B9880_e1;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0064D37C;
struct UnkStruct_D_01EA5630;
struct UnkStruct_D_01EA5638;
struct UnkStruct_D_01EA563C;
struct UnkStruct_D_01EA56C0;
struct UnkStruct_D_01EA56C4;
struct UnkStruct_D_01EA56CC;
struct UnkStruct_D_01EA56D0;
struct UnkStruct_D_01EA56D8;
struct UnkStruct_D_01EA56DC;
struct UnkStruct_D_01EA56E4;
struct UnkStruct_D_01EA56E8;
struct UnkStruct_D_01EA56F0;
struct UnkStruct_D_01EA56F4;
struct UnkStruct_D_01EA5A80;
struct UnkStruct_D_01EA6890;
struct UnkStruct_D_01EA6AF0;
struct UnkStruct_D_01EA6B00;
struct UnkStruct_D_01EA6B10;
struct UnkStruct_D_01EA6B20;
struct UnkStruct_D_01EA6B28;
struct UnkStruct_D_01EA6B30;
struct UnkStruct_D_01EA6B34;
struct UnkStruct_D_01EA6B38;
struct UnkStruct_D_01EA6B3C;
struct UnkStruct_D_01EA6B40;

class CB3TableComponent {
public:
    void RecalculateSize();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA5638 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56C4 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56C0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56D0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56CC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56DC {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56D8 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56E8 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56E4 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56F0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA563C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA56F4 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B9880_13 {
    float field_0;
    float field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
};

struct UnkStruct_D_01EA6AF0 {
    u_long128 field_0;
};

struct UnkStruct_003B9880_el {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    unsigned long field_30;  // [G] a CGtV2d copied as one doubleword
    unsigned long field_38;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_003B9880_e0 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    float field_30;
    float field_34;
    unsigned long field_38;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
};

struct UnkStruct_D_01EA5A80 {
    UnkStruct_003B9880_el field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_01EA6B00 {
    u_long128 field_0;
};

struct UnkStruct_D_01EA6B28 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B10 {
    u_long128 field_0;
};

struct UnkStruct_D_01EA6B38 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B20 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B30 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B34 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B3C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B9880_e1 {
    void * field_0;
    void * field_4;
    void * field_8;
};

struct UnkStruct_D_01EA6890 {
    UnkStruct_003B9880_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_C[0x4];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA5630 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B9880 {
    unsigned char pad_0[0x8];
    CGtV2d field_8;
    CGtV2d field_10;
    CGtV2d field_18;
};


extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_01EA5638 D_01EA5638;
extern UnkStruct_D_01EA56C4 D_01EA56C4;
extern UnkStruct_D_01EA56C0 D_01EA56C0;
extern UnkStruct_D_01EA56D0 D_01EA56D0;
extern UnkStruct_D_01EA56CC D_01EA56CC;
extern UnkStruct_D_01EA56DC D_01EA56DC;
extern UnkStruct_D_01EA56D8 D_01EA56D8;
extern UnkStruct_D_01EA56E8 D_01EA56E8;
extern UnkStruct_D_01EA56E4 D_01EA56E4;
extern UnkStruct_D_01EA56F0 D_01EA56F0;
extern UnkStruct_D_01EA563C D_01EA563C;
extern UnkStruct_D_01EA56F4 D_01EA56F4;
extern UnkStruct_003B9880_el D_01EA6AF0;
extern UnkStruct_D_01EA5A80 D_01EA5A80;
extern UnkStruct_D_01EA6B00 D_01EA6B00;
extern UnkStruct_D_01EA6B28 D_01EA6B28;
extern UnkStruct_D_01EA6B10 D_01EA6B10;
extern UnkStruct_D_01EA6B38 D_01EA6B38;
extern UnkStruct_D_01EA6B20 D_01EA6B20;
extern UnkStruct_D_01EA6B30 D_01EA6B30;
extern UnkStruct_D_01EA6B34 D_01EA6B34;
extern UnkStruct_D_01EA6B3C D_01EA6B3C;
extern UnkStruct_D_01EA6890 D_01EA6890;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern CB3TableComponent D_01E8D450;
extern UnkStruct_D_01EA5630 D_01EA5630;
extern UnkStruct_D_01EA6B40 D_01EA6B40;

extern "C" void RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);  // CGt2dObjectTable::RenderItalicText(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned short*,const CGt2dFrame&,const void*), its address taken
extern "C" void GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);  // CGt2dObjectTable::GetItalicTextSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*), its address taken
extern "C" void func_003C1FC0(UnkStruct_003B9880 *);
extern "C" void func_003B9B60(UnkStruct_003B9880 *);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0033FF10(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, bool, void *, void *, int);
extern "C" void func_003B90E0(UnkStruct_003B9880 *, int);

extern "C" void func_003B9880(UnkStruct_003B9880 * self)
{
    func_003C1FC0(self);
    D_01EA5638.field_0 = (D_0064D37C.field_0 + 1);
    func_003B9B60(self);
    D_01EA56C4.field_0 = 110.0f;
    D_01EA56C0.field_0 = -110.0f;
    D_01EA56D0.field_0 = 40.0f;
    D_01EA56CC.field_0 = 0;
    D_01EA56DC.field_0 = 120.0f;
    D_01EA56D8.field_0 = 5.0f;
    D_01EA56E8.field_0 = 140.0f;
    D_01EA56E4.field_0 = 5.0f;
    D_01EA56F0.field_0 = 5.0f;
    D_01EA56F4.field_0 = 80.0f;
    for (int i = 2; i < D_01EA563C.field_0; i++) {
        UnkStruct_003B9880_el &e = D_01EA5A80.field_0[i];
        CGtV2d &p30 = *(CGtV2d *)&e.field_30;
        int &p48 = e.field_48;
        e = D_01EA6AF0;
        if (i == 3) {
            p48 = func_00271A00(&D_0051BA44, 764);
        } else if (i == 4) {
            p48 = func_00271A00(&D_0051BA44, 768);
        } else {
            p48 = 0;
        }
        p30 = CGtV2d(0.0f, 0.0f);
        if (p48 != 0) {
            D_01EA6890.field_0[i].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890.field_0[i].field_8 = &e;
            D_01EA6890.field_0[i].field_4 = (void *)&GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        }
    }
    self->field_8 = CGtV2d(180.0f, 95.0f);
    self->field_10 = CGtV2d(0.0f, 0.0f);
    self->field_18 = CGtV2d(430.0f, 305);
    func_0033FF10(&D_01E8D450, CGtV2d(180.0f, 95.0f), CGtV2d(0.0f, 0.0f), CGtV2d(430.0f, 305), 0, &D_01EA5630, &D_01EA6B40, 0);
    D_01E8D450.RecalculateSize();
    func_003B90E0(self, 1);
}
