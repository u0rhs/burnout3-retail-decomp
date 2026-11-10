// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// Hand-written; the lifter refused it (menu component prepare: three child frames set by CGtV2d temporaries (565 as an int argument: kept cvt.s.w); find-by-name per name as a static inline helper (N113); [2][5] sub-objects prepared by func_00458AD0).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_0043DC30_4;
struct UnkStruct_0043DC30_e0;

struct UnkStruct_D_00518688 {
    UnkStruct_0043DC30_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043DC30_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0043DC30_e0 * field_C;
};

struct UnkStruct_0043DC30_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0043DC30_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

struct UnkStruct_0043DC30_7C {
    int field_0;
};

struct UnkStruct_0043DC30 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    unsigned char field_10[0x60];
    CGt2dFrame * field_70;
    CGt2dFrame * field_74;
    CGt2dFrame * field_78;
    UnkStruct_0043DC30_7C field_7C[2][5];
    int field_A4[8];
    int field_C4[2];
    int field_CC[2];
    int field_D4;
    unsigned char pad_D8[0x4];
    int field_DC;
};

struct UnkStruct_D_01E903F4 {
    CGt2dFrame * field_0;
    unsigned char pad_4[0xC];
};

extern UnkStruct_D_00518688 D_00518688;
extern CGt2dScene D_01E903E0;
extern UnkStruct_D_01E903F4 D_01E903F4;
extern const char * D_004B03B0[8];

extern "C" int strcasecmp(const char *, const char *);
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" void func_00458880(void *, CGt2dScene *, int, int);
extern "C" void func_00458AD0(UnkStruct_0043DC30_7C *);

static inline int func_0043DC30_inl1(const char * name)
{
    UnkStruct_0043DC30_4 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0043DC30_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return t2;
        }
    }
    return 0;
}

// 0x0043DC30
extern "C" int func_0043DC30(UnkStruct_0043DC30 * self)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    func_00458880(self->field_10, &D_01E903E0, self->field_8 + 1, self->field_8);
    CGt2dFrame * root = D_01E903F4.field_0;
    self->field_70 = root->ConstructChild();
    self->field_70->field_0.field_0 = CGtV2d(320.0f, 170.0f);
    self->field_70->field_0.field_8 = CGtV2d(0.8f, 0.8f);
    self->field_74 = root->ConstructChild();
    self->field_74->field_0.field_0 = CGtV2d(35.0f, 344.0f);
    self->field_74->field_0.field_8 = CGtV2d(1.0f, 1.0f);
    self->field_78 = root->ConstructChild();
    self->field_78->field_0.field_0 = CGtV2d(565, 344.0f);
    self->field_78->field_0.field_8 = CGtV2d(1.0f, 1.0f);
    for (int i = 0; i < 8; i++) {
        self->field_A4[i] = func_0043DC30_inl1(D_004B03B0[i]);
    }
    for (int k = 0; k < 2; k++) {
        self->field_C4[k] = 0;
        self->field_CC[k] = 0;
        for (int m = 0; m < 5; m++) {
            func_00458AD0(&self->field_7C[k][m]);
        }
    }
    self->field_D4 = 0;
    self->field_DC = -1;
    return 1;
}
