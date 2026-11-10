// NONMATCHING: func_003B78D0 -- retail 530 / ours 530 instructions, 103 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a174: 530/530 instrs, frame equal, 113 changed. Left: CGtV4d(1,1,1,1) by-value arg slot placement (retail ctor temps 0xC0-0xF0, copies 0x100-0x130, ours 16B lower) and store/lq scheduling of V2d/V4d temporaries before the 9-arg Prepare (9th arg = 0 stack); scene/mgr const locals, 9th arg, sep char b
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003B78D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

class CGt2dFrame;
class CGt2dObject;
class CGtTexture;

class CB3Globe2dObject;
struct UnkStruct_003B78D0;
struct UnkStruct_003B78D0_17;
struct UnkStruct_003B78D0_18;
struct UnkStruct_003B78D0_19;
struct UnkStruct_003B78D0_20;
struct UnkStruct_003B78D0_21;
struct UnkStruct_003B78D0_22;
struct UnkStruct_003B78D0_23;
struct UnkStruct_003B78D0_24;
struct UnkStruct_003B78D0_25;
struct UnkStruct_003B78D0_5;
struct UnkStruct_D_004CA160;
struct UnkStruct_D_004CA168;
struct UnkStruct_D_004CA170;
struct UnkStruct_D_004CA178;
struct UnkStruct_D_004CA180;
struct UnkStruct_D_004CA188;
struct UnkStruct_D_004CA190;
struct UnkStruct_D_004CA198;
struct UnkStruct_D_004CA1A0;
struct UnkStruct_D_004CA1B8;
struct UnkStruct_D_004CA1C0;
struct UnkStruct_D_004CA1C8;
struct UnkStruct_D_004CA1D0;
struct UnkStruct_D_004CA1D8;
struct UnkStruct_D_004CA1E0;
struct UnkStruct_D_004CA1E8;
struct UnkStruct_D_004CA1F0;
struct UnkStruct_D_004CA1F8;
struct UnkStruct_D_004CA200;
struct UnkStruct_D_004CA208;
struct UnkStruct_D_004CA210;
struct UnkStruct_D_004CA218;
struct UnkStruct_D_0051A870;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_00665ED0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01EA455C;
struct UnkStruct_D_01EA4620;

class CB3Globe2dObject {
public:
    int Prepare();
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B78D0_5 {
    int field_0;
    float field_4;
    float field_8;
    int field_C;
    unsigned char pad_90[0x10];
    float field_A0;
    float field_A4;
    float field_A8;
    float field_AC;
    float field_B0;
    float field_B4;
    int field_B8;
    int field_BC;
    float field_C0;
    float field_C4;
    float field_C8;
    float field_CC;
    float field_D0;
    float field_D4;
    float field_D8;
    float field_DC;
    float field_E0;
    float field_E4;
    int field_E8;
    int field_EC;
    float field_F0;
    float field_F4;
    float field_F8;
    float field_FC;
    float field_100;
    float field_104;
    unsigned long field_108;
    unsigned long field_110;
    float field_118;
    float field_11C;
};

struct UnkStruct_D_004CA1D0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1D8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1E0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1E8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1F0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1F8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4620 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA455C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B78D0_17 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_18 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_19 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_20 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_21 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_22 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_23 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_24 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003B78D0_25 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_D_0051A870 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA198 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1C8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA210 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA1B8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA200 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA218 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA208 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA160 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA168 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA170 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA178 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA188 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA190 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA180 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B78D0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x16];
    CB3Globe2dObject * field_20;
    unsigned char pad_24[0xC];
    UnkStruct_003B78D0_17 * field_30;
    UnkStruct_003B78D0_18 * field_34;
    UnkStruct_003B78D0_19 * field_38;
    UnkStruct_003B78D0_20 * field_3C;
    UnkStruct_003B78D0_21 * field_40;
    UnkStruct_003B78D0_22 * field_44;
    UnkStruct_003B78D0_23 * field_48;
    UnkStruct_003B78D0_24 * field_4C;
    UnkStruct_003B78D0_25 * field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    unsigned char pad_64[0xC];
    int field_70[1];  // [G] element count unknown
    unsigned char pad_74[0x8];
    int field_7C[1];  // [G] element count unknown
    unsigned char pad_80[0x8];
    int field_88;
    int field_8C;
    char field_90[0xC];
    char field_9C[0xC];
    char field_A8[0xC];
    char field_B4[0xC];
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004CA1D0 D_004CA1D0;
extern UnkStruct_D_004CA1D8 D_004CA1D8;
extern UnkStruct_D_004CA1E0 D_004CA1E0;
extern UnkStruct_D_004CA1E8 D_004CA1E8;
extern UnkStruct_D_004CA1F0 D_004CA1F0;
extern UnkStruct_D_004CA1F8 D_004CA1F8;
extern UnkStruct_D_01EA4620 D_01EA4620;
extern UnkStruct_D_01EA455C D_01EA455C;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051A870 D_0051A870;
extern UnkStruct_D_004CA198 D_004CA198;
extern UnkStruct_D_004CA1A0 D_004CA1A0;
extern UnkStruct_D_004CA1C0 D_004CA1C0;
extern UnkStruct_D_004CA1C8 D_004CA1C8;
extern UnkStruct_D_004CA210 D_004CA210;
extern UnkStruct_D_004CA1B8 D_004CA1B8;
extern UnkStruct_D_004CA200 D_004CA200;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_004CA218 D_004CA218;
extern UnkStruct_D_004CA208 D_004CA208;
extern UnkStruct_D_004CA160 D_004CA160;
extern UnkStruct_D_004CA168 D_004CA168;
extern UnkStruct_D_004CA170 D_004CA170;
extern UnkStruct_D_004CA178 D_004CA178;
extern UnkStruct_D_004CA188 D_004CA188;
extern UnkStruct_D_004CA190 D_004CA190;
extern UnkStruct_D_004CA180 D_004CA180;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const void *, const void *, const void *, GtMathPs2::CGtV4d, void *, const void *, const void *, unsigned int);  // CGt2dObjectImage::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,CGtTexture*,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)
extern "C" void func_003B5420(CB3Globe2dObject *);
extern "C" void func_00324EB0(void *);
extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);
extern "C" int Prepare__16CB3Globe2dObjectFv(void *);
extern "C" void Release__16CB3Globe2dObjectFv(void *);
extern "C" int func_0013AD30(void *, int, int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" void func_0045B460(UnkStruct_003B78D0_17 *, void *, void *, int, float);
extern "C" void sprintf(void *, void *, int);
extern "C" void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(void *, void *, int);
extern "C" void func_001D6AD0(void *, void *, void *, void *, void *, void *, void *, int, float);

// 0x003B78D0
extern "C" int func_003B78D0(UnkStruct_003B78D0 * self, int p0)
{
    UnkStruct_003B78D0_5 local;  // [G] the frame's one local
    Prepare__20CB3MenuComponentBaseFv(self);
    char b_12C[4]; char b_128[4]; char b_124[4]; char b_120[4];
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    char * const mgr = (char *)&D_01E90240;
    int t0 = scene->field_14;
    int r1 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, (CGt2dFrame*)t0);
    self->field_20 = (CB3Globe2dObject *)r1;
    int r2 = Prepare__16CB3Globe2dObjectFv(self->field_20);
    if (r2 == 0) {
        Release__16CB3Globe2dObjectFv(self->field_20);
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, (CGt2dObject*)self->field_20);
        self->field_20 = 0;
    }
    self->field_54 = 0;
    self->field_58 = p0;
    self->field_5C = p0;
    self->field_60 = 0;
    func_00324EB0(&D_0051A870);
    int t1 = D_0051BF9C.field_0;
    for (int i = 0; (i < 3); i++) {
        self->field_70[i] = 0;
        self->field_7C[i] = 0;
        self->field_88 = 0;
        self->field_8C = 0;
        for (int i1 = 0; (i1 < 73); i1++) {
            self->field_8C = (self->field_8C + 1);
            int r6 = IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(i, i1);
            if (r6 != 0) {
                self->field_7C[i] = (self->field_7C[i] + 1);
                int r7 = func_0013AD30((void *)(t1), i1, 1);
                if (r7 == 3) {
                    self->field_70[i] = (self->field_70[i] + 1);
                    self->field_88 = (self->field_88 + 1);
                }
            } else {
                int r8 = func_0013AD30((void *)(t1), i1, 1);
                if (r8 == 3) {
                    self->field_88 = (self->field_88 + 1);
                }
            }
        }
        for (int i2 = 0; (i2 < 100); i2++) {
            self->field_8C = (self->field_8C + 1);
            int r9 = IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(i, i2);
            if (r9 != 0) {
                self->field_7C[i] = (self->field_7C[i] + 1);
                int r10 = func_0013AD30((void *)(t1), i2, 0);
                if (r10 == 3) {
                    self->field_70[i] = (self->field_70[i] + 1);
                    self->field_88 = (self->field_88 + 1);
                }
            } else {
                int r11 = func_0013AD30((void *)(t1), i2, 0);
                if (r11 == 3) {
                    self->field_88 = (self->field_88 + 1);
                }
            }
        }
    }
    if (self->field_30 == 0) {
        local.field_118 = 320.0f;
        local.field_11C = ((float)345);
        int r12 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 1), (CGt2dFrame*)t0);
        self->field_30 = (UnkStruct_003B78D0_17 *)r12;
        local.field_100 = 0.5f;
        local.field_104 = 0.5f;
        func_0045B460(self->field_30, ((char *)&local + 0x98), ((char *)&local + 0x80), 7, 500.0f);
    }
    if (self->field_34 == 0) {
        switch (p0) {
        case 0:
            unsigned long t2 = D_004CA1D8.field_0;
            local.field_110 = D_004CA1D0.field_0;
            local.field_108 = t2;
            break;
        case 1:
            unsigned long t3 = D_004CA1E8.field_0;
            local.field_110 = D_004CA1E0.field_0;
            local.field_108 = t3;
            break;
        case 2:
            unsigned long t4 = D_004CA1F8.field_0;
            local.field_110 = D_004CA1F0.field_0;
            local.field_108 = t4;
            break;
        }
        short v10 = self->field_8;
        int r14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (v10 + 2), (CGt2dFrame*)t0);
        self->field_34 = (UnkStruct_003B78D0_18 *)r14;
        local.field_F8 = 0.5f;
        local.field_FC = 0.5f;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_34, &D_004CA198, ((char *)&local + 0x78), &D_004CA1A0, GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), (CGtTexture*)D_01EA4620.field_0, ((char *)&local + 0x90), ((char *)&local + 0x88), 0);
    }
    if (self->field_38 == 0) {
        int r16 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_38 = (UnkStruct_003B78D0_19 *)r16;
        local.field_F0 = 0.5f;
        local.field_F4 = 0.5f;
        local.field_E0 = 1.0f;
        local.field_E4 = 1.0f;
        local.field_E8 = 0;
        local.field_EC = 0;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_38, &D_004CA1C0, ((char *)&local + 0x70), &D_004CA1C8, GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), (CGtTexture*)D_01EA455C.field_0, ((char *)&local + 0x68), ((char *)&local + 0x60), 0);
    }
    if (self->field_3C == 0) {
        int r18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_3C = (UnkStruct_003B78D0_20 *)r18;
        sprintf(b_12C, &D_004CA210, self->field_70[p0]);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(b_12C, self->field_90, 6);
        int t7 = D_00665ED0.field_0;
        local.field_D8 = 0.8f;
        local.field_DC = 0.8f;
        func_001D6AD0(self->field_3C, &D_004CA1B8, &D_004CA200, (mgr + 0x110), (void *)(t7), self->field_90, ((char *)&local + 0x58), 2, 36.0f);
    }
    if (self->field_40 == 0) {
        int r22 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_40 = (UnkStruct_003B78D0_21 *)r22;
        sprintf(b_128, &D_004CA218, self->field_7C[p0]);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(b_128, self->field_9C, 6);
        local.field_D4 = 0.5f;
        local.field_D0 = 0.8f;
        func_001D6AD0(self->field_40, &D_004CA1B8, &D_004CA208, mgr, (void *)(D_00665ED0.field_0), self->field_9C, ((char *)&local + 0x50), 2, 25.0f);
    }
    if (self->field_44 == 0) {
        int r26 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_44 = (UnkStruct_003B78D0_22 *)r26;
        local.field_C8 = 0.5f;
        local.field_CC = 0.5f;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_44, &D_004CA160, ((char *)&local + 0x48), &D_004CA168, GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), (CGtTexture*)D_01EA4620.field_0, &D_004CA170, &D_004CA178, 0);
    }
    if (self->field_48 == 0) {
        int r28 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_48 = (UnkStruct_003B78D0_23 *)r28;
        local.field_C0 = 0.5f;
        local.field_C4 = 0.5f;
        local.field_B0 = 1.0f;
        local.field_B4 = 1.0f;
        local.field_B8 = 0;
        local.field_BC = 0;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_48, &D_004CA188, ((char *)&local + 0x40), &D_004CA190, GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), (CGtTexture*)D_01EA455C.field_0, ((char *)&local + 0x38), ((char *)&local + 0x30), 0);
    }
    if (self->field_4C == 0) {
        int r30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_4C = (UnkStruct_003B78D0_24 *)r30;
        sprintf(b_124, &D_004CA210, self->field_88);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(b_124, self->field_A8, 6);
        int t10 = D_00665ED0.field_0;
        local.field_A8 = 0.8f;
        local.field_AC = 0.8f;
        func_001D6AD0(self->field_4C, &D_004CA180, &D_004CA200, (mgr + 0x110), (void *)(t10), self->field_A8, ((char *)&local + 0x28), 2, 36.0f);
    }
    if (self->field_50 == 0) {
        int r34 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, (self->field_8 + 2), (CGt2dFrame*)t0);
        self->field_50 = (UnkStruct_003B78D0_25 *)r34;
        sprintf(b_120, &D_004CA218, self->field_8C);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(b_120, self->field_B4, 6);
        local.field_A4 = 0.5f;
        local.field_A0 = 0.8f;
        func_001D6AD0(self->field_50, &D_004CA180, &D_004CA208, mgr, (void *)(D_00665ED0.field_0), self->field_B4, ((char *)&local + 0x20), 2, 25.0f);
        local.field_C = 0;
        local.field_0 = 0x3F800000;
        local.field_4 = 1.0f;
        local.field_8 = 1.0f;
        u_long128 t11 = *(u_long128 *)&local.field_0;
        self->field_30->field_10 = t11;
        self->field_34->field_10 = t11;
        self->field_38->field_10 = t11;
        self->field_3C->field_10 = t11;
        self->field_40->field_10 = t11;
        self->field_44->field_10 = t11;
        self->field_48->field_10 = t11;
        self->field_4C->field_10 = t11;
        self->field_50->field_10 = t11;
    }
    return 1;
}


