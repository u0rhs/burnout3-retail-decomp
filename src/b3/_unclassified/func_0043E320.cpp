// func_0043E320 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Hand-written: three-table stat getter as a static inline switch (returns, default 0) used four times, ustr buffer walk with unsigned short pointers, scene/manager as const pointer locals (mgr declared before the frame), CGtV2d temporaries, image Prepare stack argument (N68), string id fetched into a local before func_003824D0).

// func_0043E320 -- hand-written from the retail structure (lifted draft compiled but far: a three-way stat
// getter inlined four times, CGtV2d temporaries).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dFrame;
class CGtTexture;

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    CGt2dFrame * field_14;
};

struct UnkStruct_D_01EA465C {
    CGtTexture * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x40];
    unsigned char field_40[0x10];
    unsigned char field_50[0xC0];
    CGtV4d field_110;
};

struct UnkStruct_0043E320 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    void * field_C;
    unsigned char pad_10[0x54];
    unsigned short * field_64[3][3];
    unsigned short * field_88[3][3];
    void * field_AC;
    unsigned char pad_B0[0x24];
    int field_D4;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01EA465C D_01EA465C;
extern char D_01E90438[];
extern unsigned short D_004D20E8[];
extern UnkStruct_D_01E90240 D_01E90240;
extern char D_0051BA44[];
extern unsigned short D_004D20E0[];

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);  // CGt2dObjectImage::Prepare(...), plus retail's stack argument (N68)
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int func_0013AB80(void *, int, int);
extern "C" int func_0013AA10(void *, int, int);
extern "C" int func_0013A8A0(void *, int, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const unsigned short *, const CGtV2d &, void *, void *, void *, int, float, float, float);
extern "C" void func_0043E6F0(UnkStruct_0043E320 *);

// [G] inlined stat getter, placeholder name: one of three tables by category i
static inline int func_0043E320_inl1(int stats, int i, int kind, int j)
{
    switch (i) {
    case 0:
        return func_0013AB80((void *)(stats), kind, j);
    case 1:
        return func_0013AA10((void *)(stats), kind, j);
    case 2:
        return func_0013A8A0((void *)(stats), kind, j);
    }
    return 0;
}

// 0x0043E320
extern "C" int func_0043E320(UnkStruct_0043E320 * self, int p0)
{
    int stats = D_0051BF9C.field_0;
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_D4 = p0;
    unsigned short * buf = AllocUTF16String__19CB3MenuStringBufferFi(D_01E90438, 128);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a = func_0043E320_inl1(stats, i, 1, j);
            int b = func_0043E320_inl1(stats, i, 3, j);
            b += func_0043E320_inl1(stats, i, 2, j);
            PrintInt__10CGtUnicodeFPUsii(buf, a + b, 1, 0);
            self->field_64[i][j] = buf;
            buf += Length__10CGtUnicodeFPCUs(buf) + 1;
            int c = func_0043E320_inl1(stats, i, 4, j);
            PrintInt__10CGtUnicodeFPUsii(Append__10CGtUnicodeFPUsPCUs(buf, D_004D20E8), c, 1, 0);
            self->field_88[i][j] = buf;
            buf += Length__10CGtUnicodeFPCUs(buf) + 1;
        }
    }
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    CGt2dFrame * frame = scene->field_14;
    CGtTexture * tex = D_01EA465C.field_0;
    self->field_C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, frame);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_C, CGtV2d(240.0f, 96.0f), CGtV2d(0.0f, 0.0f), CGtV2d(368.0f, 240.0f), mgr->field_110, tex, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    self->field_AC = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 2, frame);
    int str = func_00271A00(D_0051BA44, 2496);
    func_003824D0(self->field_AC, D_004D20E0, CGtV2d(1.0f, 0.0f), mgr->field_40, mgr->field_50, (void *)(str), 33, 26.0f, 1.5f, 3.402823466e+38f);
    func_0043E6F0(self);
    return 1;
}
