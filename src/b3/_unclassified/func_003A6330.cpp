// Hand-written; the lifter refused it (v302: menu tab Prepare (DNAT CB3TabbedDisplayComponent::Prepare, low); 0 < n guard + int i = 0 before it, ps = &scale declared before i; y before scale stores; one N140 pad).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] DNAT: CB3TabbedDisplayComponent::Prepare(ETabbedDisplayPrepareType,unsigned long,int) (research/proto/new_names.csv, low);
// retail reads five argument registers (a1-t1), so the June signature is not used.
struct UnkStruct_003A6330_frame { float field_0; float field_4; unsigned char pad_8[0x8]; CGtV4d field_10; };
struct UnkStruct_003A6330 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    unsigned long field_10;
    unsigned char pad_18[0x18];
    void * field_30;
    void * field_34[4];
    unsigned char pad_44[0x14];
    int field_58;
    unsigned char pad_5C[0x4];
    int field_60;
    int field_64;
    void * field_68[4];
    unsigned char pad_78[0x50];
    int field_C8;
    unsigned short * field_CC;
    UnkStruct_003A6330_frame * field_D0;
    UnkStruct_003A6330_frame * field_D4;
    unsigned char pad_D8[0x28];
    float field_100;
    int field_104;
    int field_108;
    unsigned char field_10C;
    unsigned char field_10D;
};
struct UnkStruct_003A6330_pad { int x[4]; UnkStruct_003A6330_pad() {} ~UnkStruct_003A6330_pad() {} };  // N140 pad [G]: retail's dead 16-byte slot (0xD0) between the CGtV2d locals and strs[]
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00665ED0 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void * field_14; unsigned char pad_18[0x8]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; CGtV4d field_10; unsigned char pad_20[0x10]; CGtV4d field_30; };
extern UnkStruct_D_01E90240 D_01E90240;
extern CGtV4d D_01E90350;
extern UnkStruct_D_Pad16 D_01E90438, D_0051BA44, D_01ECD9F0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern unsigned char D_004E2EDC;
extern const float D_004C9E00;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" int func_003F5FD0(int);
extern "C" unsigned char func_0042ECF0(void *, int, int, int);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const unsigned short *, const CGtV2d *, int);
extern "C" void func_003A5A00(UnkStruct_003A6330 *, int);

// 0x003A6330
extern "C" bool func_003A6330(UnkStruct_003A6330 * self, int type, unsigned long id, int sel, int alloc, int p5)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    CGtV2d p;
    CGtV2d pos;
    CGtV2d anchor;
    CGtV2d scale;
    UnkStruct_003A6330_pad pad;
    unsigned short * strs[4];
    CGtV4d col;
    col = D_01E90350;
    self->field_100 = -1.0f;
    self->field_D0 = (UnkStruct_003A6330_frame *)ConstructChild__10CGt2dFrameFv(scene->field_14);
    col.SetA(0.0f);
    self->field_D0->field_10 = col;
    UnkStruct_003A6330_frame * frame = self->field_D0;
    if (alloc != 0)
        self->field_CC = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x60);
    self->field_C8 = type;
    self->field_10 = id;
    self->field_104 = type;
    self->field_58 = 0;
    self->field_108 = p5;
    self->field_10C = 1;
    if (sel < 0)
        self->field_64 = 0;
    else
        self->field_64 = sel;
    switch (type) {
    case 4:
        self->field_D4 = (UnkStruct_003A6330_frame *)ConstructChild__10CGt2dFrameFv(self->field_D0);
        frame = self->field_D4;
        self->field_100 = 0.0f;
        self->field_10D = func_0042ECF0(&D_01ECD9F0, self->field_64, self->field_64 * 5 - 1, D_004E2EDC);
    case 3: {
        self->field_60 = 4;
        for (int i = 0; i < self->field_60; i++) {
            UnkStruct_003A6330_frame * f;
            if (self->field_64 == i)
                f = frame;
            else
                f = self->field_D0;
            self->field_34[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, f);
            self->field_68[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, f);
            strs[i] = func_00271A00(&D_0051BA44, func_003F5FD0(i));
        }
        p.marValues[0] = 0.0f;
        p.marValues[1] = 25.0f;
        *(CGtV2d *)self->field_D0 = p;
        break;
    }
    case 0:
        self->field_60 = 4;
        for (int i = 0; i < self->field_60; i++) {
            self->field_34[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, self->field_D0);
            self->field_68[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_D0);
        }
        strs[0] = func_00271A00(&D_0051BA44, 0x2A8);
        strs[1] = func_00271A00(&D_0051BA44, 0x2A7);
        strs[2] = func_00271A00(&D_0051BA44, 0x2AB);
        strs[3] = func_00271A00(&D_0051BA44, 0x2AC);
        break;
    case 1:
        self->field_60 = 1;
        for (int i = 0; i < self->field_60; i++) {
            self->field_34[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, self->field_D0);
            self->field_68[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_D0);
        }
        strs[0] = func_00271A00(&D_0051BA44, 0xA00);
        break;
    case 2:
        self->field_60 = 1;
        for (int i = 0; i < self->field_60; i++) {
            self->field_34[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, self->field_D0);
            self->field_68[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, self->field_D0);
        }
        strs[0] = func_00271A00(&D_0051BA44, 0xA00);
        break;
    }
    self->field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, frame);
    CGtV2d * ps;
    int i = 0;
    if (0 < self->field_60) {
    ps = &scale;
    for (; i < self->field_60; i++) {
        float y = 136.0f + 50.0f * (float)i;
        scale.marValues[0] = 2.0f;
        scale.marValues[1] = 2.0f;
        const CGtV4d * c;
        if (i == self->field_64)
            c = &mgr->field_10;
        else
            c = &mgr->field_30;
        anchor.marValues[0] = 0.5f;
        anchor.marValues[1] = 0.5f;
        pos.marValues[1] = y;
        pos.marValues[0] = D_004C9E00;
        func_0033D4E0(self->field_68[i], pos, anchor, 25.0f, c, D_00665ED0.field_0, strs[i], ps, 1);
    }
    }
    func_003A5A00(self, self->field_64);
    return 1;
}
