// CB3HUDScore::UpdateScoreObject(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDScore.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near6: func_003824D0 7th param const unsigned short* (callee param type rule)).

// CB3HUDScore::UpdateScoreObject(float) -- hand-written (a189); the lifter refused it (pmaxw).
// near6: matched from the a189/a201 archive -- func_003824D0's 7th parameter typed `const unsigned short *` (near2 rule)
// fixed the &field_E8 argument scheduling; two N140 frame pads (a201).
// [C] name: the mangled symbol in retail's tables. Layout [G] from instruction widths; field names are placeholders.
#include "b3/GtMathPs2.h"

struct UnkStruct_001A1CD0_pad {
    int x[4];
    UnkStruct_001A1CD0_pad() {}
    ~UnkStruct_001A1CD0_pad() {}
};

class CGt2dFrame;
class CGt2dObject;

struct UnkStruct_001A1CD0_c { unsigned char pad_0[0x4C]; int field_4C; };
struct UnkStruct_001A1CD0_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_001A1CD0_o {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
};
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0x20];
    GtMathPs2::CGtV4d field_40;
    unsigned char pad_50[0x10];
    GtMathPs2::CGtV4d field_60;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };

class CB3HUDScore {
public:
    void UpdateScoreObject(float p0);

    unsigned char pad_0[0x4];
    UnkStruct_001A1CD0_e1 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_001A1CD0_o * field_20;
    UnkStruct_001A1CD0_o * field_24;
    void * field_28;
    unsigned char pad_2C[0xA0];
    UnkStruct_001A1CD0_c * field_CC;
    unsigned char pad_D0[0x14];
    int field_E4;
    unsigned short field_E8[16];
    int field_108;
    int field_10C;
    float field_110;
};

extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern float D_004E08A8;
extern float D_004E0924;
extern float D_004E0940;
extern float D_004E0944;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, unsigned int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, GtMathPs2::CGtV4d, GtMathPs2::CGtV4d, const unsigned short *, int, float, float);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);

static inline int func_001A1CD0_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int func_001A1CD0_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_001A1CD0_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x001A1CD0
void CB3HUDScore::UpdateScoreObject(float p0)
{
    field_10C = field_CC->field_4C - field_E4;
    field_108 += func_001A1CD0_zx(func_001A1CD0_max((field_10C - field_108) / 20, 1));
    field_108 = func_001A1CD0_zx(func_001A1CD0_min(field_108, field_10C));
    field_110 = field_110 - p0;
    float t = field_110;
    if (t < 0.0f) {
        if (field_20 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject((char *)&field_4[field_1C] + 0x14, field_10 + 1, field_20);
            DestructObject__10CGt2dSceneFiP11CGt2dObject((char *)&field_4[field_1C] + 0x14, field_10 + 1, field_24);
            field_20 = 0;
            field_24 = 0;
            DestructObject__10CGt2dSceneFiP11CGt2dObject((char *)&field_4[field_1C] + 0x14, field_10 + 1, field_28);
            field_28 = 0;
        }
        return;
    }
    float a;
    if (t < D_004E0924) {
        a = 1.0f - (D_004E0924 - t) / D_004E0924;
    } else if (t < D_004E0940) {
        a = 1.0f;
    } else {
        a = (D_004E0944 - t) / D_004E0924;
    }
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    if (field_20 == 0) {
        void * scene = (char *)&field_4[field_1C] + 0x14;
        field_20 = (UnkStruct_001A1CD0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_10 + 1, (void *)field_8);
        field_24 = (UnkStruct_001A1CD0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_10 + 1, (void *)field_8);
        int text = func_00271A00(&D_0051BA44, 0x7F0);
        func_003824D0(field_20, GtMathPs2::CGtV2d(7.0f, 14.0f), GtMathPs2::CGtV2d(1.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, (const unsigned short *)text, 9, 1.0f, D_004E08A8);
        field_28 = (void *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_10 + 1, (void *)field_8);
        Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(field_28, GtMathPs2::CGtV2d(0.0f, 14.0f), GtMathPs2::CGtV2d(0.5f, 0.5f), GtMathPs2::CGtV2d(190.0f, 27.0f), mgr->field_10, 3);
    }
    UnkStruct_001A1CD0_pad g0, g1;
    GtMathPs2::CGtV4d c;
    c = mgr->field_40;
    c.SetA(a);
    field_20->field_10 = c;
    PrintInt__10CGtUnicodeFPUsii(field_E8, field_108, 0, 0);
    func_003824D0(field_24, GtMathPs2::CGtV2d(14.0f, 14.0f), GtMathPs2::CGtV2d(0.0f, 0.5f), 30.0f, mgr->field_10, mgr->field_60, field_E8, 0x41, 1.0f, D_004E08A8);
    field_24->field_10 = GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, a);
}
