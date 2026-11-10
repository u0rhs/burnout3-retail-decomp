// NONMATCHING: func_00449B70 -- retail 231 / ours 233 instructions, 30 in changed runs
// psweep: scoped #pragma usefloatacc off [G] improves 40 -> 38
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// registers and control flow exact (scene as &D_01E90240.field_1A0, p0 reused for the item count, flags declared after scene). Left: stack slots -- retail zero-fills a separate CGtV2d at sp+0xE0 and copies func_00448930's result (temp 0xD8) to sp+0xE8; ours zero-fills and copies into one local; pos/anchor slots; float scheduling in the last block

// func_00449B70 -- hand-finished from the lifted source. Unnamed in every table, so a placeholder
// with C linkage; file and Area unknown, so _unclassified/. Every type is [G] (instruction widths); `self` is
// whatever a0 points to. Calls func_00448930, which returns a CGtV2d by value.

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma usefloatacc off

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    void * field_14;
};

// [G] the page manager instance; the scene sits at +0x1A0 (N63: taken as a member address)
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D30C0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00449B70_7 {
    unsigned char pad_0[0x4];
    float field_4;
};

struct UnkStruct_D_004D30D8 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00449B70_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E90438 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90350 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00449B70 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    unsigned short field_C;
    unsigned char pad_E[0x2A];
    UnkStruct_00449B70_10 * field_38[5];
    int field_4C;
    int field_50;
    unsigned char pad_54[0x10];
    float field_64;
    int field_68;
    unsigned char field_6C;
    unsigned char pad_6D[0x3];
    unsigned char field_70[0x4];
    int field_74;
    float field_78;
    float field_7C;
    int field_80;
    short field_84;
    short field_86;
    UnkStruct_00449B70_7 * field_88;
    int field_8C;
    signed char field_90;
    unsigned char pad_91[0x63];
    float field_F4;
    unsigned char pad_F8[0x4E4];
    int field_5DC;
};

extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_004D30C0 D_004D30C0;
extern UnkStruct_D_004D30D8 D_004D30D8;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E90438 D_01E90438;
struct UnkStruct_D_004D30B8 {
    GtMathPs2::CGtV2d field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004D30B8 D_004D30B8;
extern UnkStruct_D_01E90350 D_01E90350;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const GtMathPs2::CGtV2d *, const GtMathPs2::CGtV2d *, const GtMathPs2::CGtV2d *, unsigned int, int);  // CB3RoundedPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int), passed 1 more argument(s) [G]
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int func_00448BB0(UnkStruct_00449B70 *, int);
extern "C" GtMathPs2::CGtV2d func_00448930(UnkStruct_00449B70 *, int, int);
extern "C" void func_00449050(UnkStruct_00449B70 *, int, int, float);
extern "C" void func_002F9690(void *, GtMathPs2::CGtV2d *, GtMathPs2::CGtV2d *, void *, void *, void *, int, int, float);
extern "C" void func_004482A0(UnkStruct_00449B70 *, int);
extern "C" void func_00372400(void *, GtMathPs2::CGtV2d *, GtMathPs2::CGtV2d *, void *, float, float, float);

extern "C" int func_00449B70(UnkStruct_00449B70 * self, int p0, int p1, int p2, int p3, int p4)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    unsigned int flags = 27;
    void * root = scene->field_14;
    UnkStruct_D_01E90240 * mgr = &D_01E90240;
    self->field_F4 = 0.0f;
    self->field_90 = p0;
    self->field_6C = p3;
    self->field_88 = (UnkStruct_00449B70_7 *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, root);
    if (self->field_90 != 5) {
        self->field_8C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
    }
    if (self->field_90 == 6) {
        self->field_5DC = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    }
    *(int *)self->field_70 = 0;
    self->field_74 = 0;
    GtMathPs2::CGtV2d size;
    size = GtMathPs2::CGtV2d(0, 0);
    self->field_80 = D_00665ED0.field_0;
    self->field_7C = 1.0f;
    self->field_78 = 30.0f;
    self->field_84 = -1;
    self->field_86 = -1;
    for (int i = 0; i < 5; i++) {
        self->field_38[i] = 0;
    }
    p0 = func_00448BB0(self, p2);
    self->field_50 = -1;
    self->field_64 = -1.0f;
    size = func_00448930(self, p1, p0);
    if (p4 != 0) {
        flags |= 0x100;
    }
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_88, &D_004D30B8.field_0, &GtMathPs2::CGtV2d(0.5f, 0.5f), &size, flags, 0);
    for (int j = 0; j < p0; j++) {
        self->field_38[j] = (UnkStruct_00449B70_10 *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        func_00449050(self, j, 0, 320.0f);
    }
    if (self->field_90 != 5 && self->field_90 != 6) {
        func_002F9690((void *)(self->field_8C), &GtMathPs2::CGtV2d(320.0f, 16.0f + self->field_88->field_4), &GtMathPs2::CGtV2d(0.5f, 0), mgr, (void *)(p1), self->field_70, 3, 0, D_004D30C0.field_0);
    }
    if (self->field_90 == 6) {
        func_004482A0(self, self->field_68);
    }
    self->field_4C = 0;
    if (p0 > 0) {
        self->field_4C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        int sel = self->field_C;
        float w = D_004D30D8.field_0;
        float t = 0.0f;
        float x = 640.0f + t * ((w + self->field_38[sel]->field_8) - 640.0f);
        func_00372400((void *)(self->field_4C), &GtMathPs2::CGtV2d(0, ((self->field_F4 + self->field_88->field_4) + 15.0f) + 32.0f * (float)sel), &GtMathPs2::CGtV2d(0, 0.5f), &D_01E90350, 640.0f, (w / 2.0f + (640.0f - x)) / 2.0f, x);
    }
    return 1;
}


#pragma pop
