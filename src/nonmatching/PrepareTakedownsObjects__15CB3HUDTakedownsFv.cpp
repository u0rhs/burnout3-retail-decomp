// NONMATCHING: PrepareTakedownsObjects__15CB3HUDTakedownsFv -- retail 212 / ours 212 instructions, 14 in changed runs
// 14 off: s2/s3 swap only (retail mgr=&D_0066A4C0 in s3, layer scene pointer in s2; ours reversed); logic and schedule exact otherwise
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3HUDTakedowns::PrepareTakedownsObjects() -- [C] name: the mangled symbol in retail's tables.
// Area not evidenced, so _unclassified/. Fields are placeholders; every type is [G] (instruction widths).
// Hand-written (fresh5): lifter refused. Siblings: CB3HUDTakedowns::Prepare (B3HUDTakedowns_003A25F0.cpp),
// the inlined layer-visibility store from B3HUDComponent_0019F4B0.cpp (field_2C re-read for the store).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dFont;

struct UnkStruct_003A21C0_layer {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_003A21C0_scene {
    unsigned char pad_0[0x2C];
    UnkStruct_003A21C0_layer * field_2C;
    unsigned char pad_30[0x2C];
};
struct UnkStruct_003A21C0_hud {
    unsigned char pad_0[0x14];
    UnkStruct_003A21C0_scene field_14;
};
struct UnkStruct_003A21C0_obj { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_003A21C0_stats {
    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0x8];
    int field_74;
    unsigned char pad_78[0x8];
    int * field_80;
};
struct UnkStruct_003A21C0_font { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_D_00665ED0 { UnkStruct_003A21C0_font *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };

class CB3HUDTakedowns {
public:
    void PrepareTakedownsObjects();

    unsigned char pad_0[0x4];
    UnkStruct_003A21C0_hud * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_003A21C0_obj * field_20;
    UnkStruct_003A21C0_obj * field_24;
    UnkStruct_003A21C0_obj * field_28;
    UnkStruct_003A21C0_obj * field_2C;
    unsigned char pad_30[0x4];
    UnkStruct_003A21C0_stats * field_34;
    int field_38;
    int * field_3C;
    float field_40;
    unsigned short field_44[8];
    unsigned short field_54[0x20];
    unsigned char field_94;
    bool field_95;
    unsigned char pad_96[0x2];
    int field_98;
};

extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern int _kaeMedalNames[];
extern char D_004C9CB0[];

extern "C" unsigned short *PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" char *strcpy(char *, const char *);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void func_003824D0(UnkStruct_003A21C0_obj *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
extern "C" void func_001D6AD0(UnkStruct_003A21C0_obj *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const UnkStruct_003A21C0_font *, const unsigned short *, const CGtV2d *, int);

static inline float func_003A21C0_inl2(const UnkStruct_003A21C0_obj *o)
{
    return (float)(int)(o->field_0 + o->field_8);
}

static inline float func_003A21C0_inl1(float a, float b, float t)
{
    float d = b - a;
    return 0.0f + a + d * t;
}

// 0x003A21C0
void CB3HUDTakedowns::PrepareTakedownsObjects()
{
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    if (field_95)
        field_38 = field_34->field_68;
    else
        field_38 = *(int *)((char *)field_34 + 0x68);
    PrintInt__10CGtUnicodeFPUsii(field_44, field_38, 0, 0);
    field_3C = field_34->field_80;
    float t = 0.75f;
    func_003824D0(field_24, CGtV2d(8.0f + (field_20->field_0 + field_20->field_8), 47.0f), CGtV2d(0.0f, D_00665ED0.field_0->field_10), 56.0f, mgr->field_60, GtMathPs2::Interpolate(mgr->field_60, mgr->field_30, t), field_44, 1, 1.5f, 3.402823466e+38f);
    if (field_94 != 0) {
        UnkStruct_003A21C0_scene * scene = &field_4[field_1C].field_14;
        int layer = field_10 + 1;
        int cur = field_34->field_74;
        int next = 4;
        if (cur == 4)
            next = 0;
        else if (cur != 2)
            next = cur + 1;
        field_98 = cur;
        if (next != 4 && field_3C != 0) {
            char buf[0x10];
            unsigned short wbuf[0x10];
            const unsigned short *text = func_00271A00(&D_0051BA44, _kaeMedalNames[next]);
            int v = field_34->field_80[next];
            float size = func_003A21C0_inl1(20.0f, 30.0f, field_40 / 0.1f);
            strcpy(buf, D_004C9CB0);
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, wbuf, 0xF);
            PrintInt__10CGtUnicodeFPUsii(Copy__10CGtUnicodeFPUsPCUs(field_54, wbuf), v, 0, 0);
            float y = 2.0f + (field_20->field_4 + field_20->field_C);
            func_001D6AD0(field_28, CGtV2d(0.0f, y), CGtV2d(0.0f, 0.0f), size, mgr->field_20, D_00665ED0.field_0, text, &CGtV2d(2.0f, 2.0f), 2);
            float x = func_003A21C0_inl2(field_28);
            func_001D6AD0(field_2C, CGtV2d(x, y), CGtV2d(0.0f, 0.0f), size, mgr->field_20, D_00665ED0.field_0, field_54, &CGtV2d(2.0f, 2.0f), 2);
            int f = scene->field_2C[layer].field_0;
            (*(UnkStruct_003A21C0_layer * const *)&scene->field_2C)[layer].field_0 = f & -2;
        } else {
            int f = scene->field_2C[layer].field_0;
            (*(UnkStruct_003A21C0_layer * const *)&scene->field_2C)[layer].field_0 = f | 1;
        }
    }
}
