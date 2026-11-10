// CB3BuddyReadMailComponent::Prepare(char*,char*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyReadMailComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a150: text Prepare calls with named pos/zero/shadow CGtV2d locals assigned in retail order; &CGtV2d(2,2) temps unused; D_01EA48F0.field_0 = CGtV2d(0,0) first; 8-byte CGtV2d copies for field_18/frame pos).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_0372600_obj { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_00372600 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    unsigned short * field_C;
    unsigned short * field_10;
    unsigned short * field_14;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    void * field_30;
    UnkStruct_0372600_obj * field_34;
    UnkStruct_0372600_obj * field_38;
    void * field_3C;
    void * field_40;
    UnkStruct_0372600_obj * field_44;
    UnkStruct_0372600_obj * field_48;
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00665ED0 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA48F0 {
    CGtV2d field_0;
    float field_8;
    float field_C;
    int field_10;
    short field_14;
    short field_16;
};
struct UnkStruct_D_kMail { CGtV2d field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void * field_14; unsigned char pad_18[0x8]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; unsigned char field_10[0x10]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_Pad16 D_01E90438, D_0051BA44, D_004C8F28, D_004C8F30;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_01EA48F0 D_01EA48F0;
extern UnkStruct_D_kMail kB3MailDisplayPos;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" void func_001D6AD0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const unsigned short *, const CGtV2d *, int);
extern "C" void func_002F9690(void *, const CGtV2d &, const CGtV2d &, const void *, const unsigned short *, void *, int, int, float);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);

extern "C" bool Prepare__25CB3BuddyReadMailComponentFPcPcPc(UnkStruct_00372600 * self, char * p0, char * p1, char * p2)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    void * parent = scene->field_14;
    self->field_C = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
    self->field_10 = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 11);
    self->field_14 = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 200);
    self->field_18 = kB3MailDisplayPos.field_0;
    CGtV2d vz(0.0f, 0.0f);
    CGtV2d vs(320.0f, 272.0f);
    self->field_20 = vz;
    self->field_28 = vs;
    self->field_48 = (UnkStruct_0372600_obj *)ConstructChild__10CGt2dFrameFv(parent);
    *(CGtV2d *)self->field_48 = self->field_18;
    self->field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, self->field_48);
    self->field_34 = (UnkStruct_0372600_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_48);
    self->field_38 = (UnkStruct_0372600_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_48);
    self->field_3C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_48);
    self->field_40 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_48);
    self->field_44 = (UnkStruct_0372600_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_48);
    {
        CGtV2d pos;
        CGtV2d zero;
        CGtV2d shadow;
        shadow.marValues[0] = 2.0f;
        shadow.marValues[1] = 2.0f;
        const unsigned short * txt = func_00271A00(&D_0051BA44, 0x1F);
        zero.marValues[0] = 0.0f;
        zero.marValues[1] = 0.0f;
        pos.marValues[0] = 3.0f;
        pos.marValues[1] = 25.0f;
        func_001D6AD0(self->field_34, pos, zero, 24.0f, mgr, D_00665ED0.field_0, txt, &shadow, 1);
    }
    {
        CGtV2d pos;
        CGtV2d zero;
        CGtV2d shadow;
        shadow.marValues[0] = 2.0f;
        shadow.marValues[1] = 2.0f;
        const unsigned short * txt = func_00271A00(&D_0051BA44, 0x20);
        zero.marValues[0] = 0.0f;
        zero.marValues[1] = 0.0f;
        pos.marValues[0] = 3.0f;
        pos.marValues[1] = 0.0f;
        func_001D6AD0(self->field_38, pos, zero, 24.0f, mgr, D_00665ED0.field_0, txt, &shadow, 1);
    }
    if (p0[0] != 0) {
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(p0, self->field_C, 16);
    } else {
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi((const char *)&D_004C8F28, self->field_C, 16);
    }
    {
        CGtV2d pos;
        CGtV2d zero;
        CGtV2d shadow;
        shadow.marValues[0] = 2.0f;
        shadow.marValues[1] = 2.0f;
        zero.marValues[0] = 0.0f;
        zero.marValues[1] = 0.0f;
        UnkStruct_0372600_obj * o = self->field_34;
        float yy = o->field_4;
        pos.marValues[0] = 5.0f + (o->field_0 + o->field_8);
        pos.marValues[1] = yy;
        func_001D6AD0(self->field_3C, pos, zero, 24.0f, mgr->field_10, D_00665ED0.field_0, self->field_C, &shadow, 1);
    }
    if (p1[0] != 0) {
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(p1, self->field_10, 11);
    } else {
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi((const char *)&D_004C8F28, self->field_10, 11);
    }
    {
        CGtV2d pos;
        CGtV2d zero;
        CGtV2d shadow;
        shadow.marValues[0] = 2.0f;
        shadow.marValues[1] = 2.0f;
        zero.marValues[0] = 0.0f;
        zero.marValues[1] = 0.0f;
        UnkStruct_0372600_obj * o = self->field_38;
        float yy = o->field_4;
        pos.marValues[0] = 5.0f + (o->field_0 + o->field_8);
        pos.marValues[1] = yy;
        func_001D6AD0(self->field_40, pos, zero, 24.0f, mgr->field_10, D_00665ED0.field_0, self->field_10, &shadow, 1);
    }
    D_01EA48F0.field_0 = CGtV2d(0.0f, 0.0f);
    D_01EA48F0.field_10 = D_00665ED8.field_0;
    D_01EA48F0.field_C = 1.0f;
    D_01EA48F0.field_8 = 24.0f;
    D_01EA48F0.field_14 = -1;
    D_01EA48F0.field_16 = -1;
    if (p2[0] != 0) {
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(p2, self->field_14, 200);
    } else {
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi((const char *)&D_004C8F30, self->field_14, 200);
    }
    func_002F9690(self->field_44, CGtV2d(16.0f, 1.0f + (24.0f + self->field_34->field_4)), CGtV2d(0.0f, 0.0f), mgr, self->field_14, &D_01EA48F0, 0x65, 0, 288.0f);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_30, CGtV2d(0.0f, self->field_44->field_4), self->field_20, CGtV2d(self->field_28.marValues[0], self->field_28.marValues[1] - self->field_44->field_4), 0x1F, 0);
    return true;
}
