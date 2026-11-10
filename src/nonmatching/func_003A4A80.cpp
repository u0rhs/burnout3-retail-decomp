// NONMATCHING: func_003A4A80 -- retail 368 / ours 357 instructions, 122 in changed runs
// a152: logic complete (357 vs 368 instrs, 122 changed): 4 loops of CGt2dObjectText/Image rows; remaining: retail spills args to sp+0xDC..0xEC and an sq spill of i*4 at sp+0xC0 (register pressure), 'lw zero,0x180(sp)' stack-arg touch, name[16] buffer at sp+0x160 above the pos/anchor temp slots (ours below), loop counters/obj-pointer register split per loop, f22 168.0 hoist before loop 2; constants: 127.5f, 168.0f, 25/20/10 sizes
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003A4A80 -- [L] DNAT: CB3TabbedDisplayComponent::SetRecordsContentPanelContents (research/proto/new_names.csv, exact/verified; retail takes 4 more args)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dObject;
class CGt2dFrame;
class CGtTexture;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    CGt2dFrame * field_14;
};
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_V2 { CGtV2d v; unsigned char pad_8[0x8]; };
struct UnkStruct_3A4A80_e {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_3A4A80_t {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_3A4A80_e * field_C;
};
struct UnkStruct_D_0051A868 {
    UnkStruct_3A4A80_t * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_3A4A80_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x10];
    CGtV4d field_30;
    unsigned char pad_40[0xD0];
    CGtV4d field_110;
};
struct UnkStruct_3A4A80 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xC6];
    CGt2dFrame * field_D0;
    CGt2dFrame * field_D4;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_F D_004C9E28, D_004C9E38, D_004C9E48;
extern UnkStruct_V2 D_004C9E88;
extern CGtV4d D_004C9EF0;
extern char D_004C9F08[];
extern "C" CGt2dObject * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV4d &, void *, void *, float);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int strcasecmp(const char *, const char *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);

static inline CGtTexture * func_003A4A80_inl1(const char * name)
{
    UnkStruct_3A4A80_t * t0 = D_0051A868.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_3A4A80_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x003A4A80
extern "C" void func_003A4A80(UnkStruct_3A4A80 * self, int n, int n2, int * texts, int ** p4, int ** p5, int * vehicles, int * variants, int ** names2)
{
    float cols[3];
    char name[16];
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    CGt2dFrame * root = self->field_D4;
    cols[0] = D_004C9E28.field_0;
    cols[1] = D_004C9E38.field_0;
    cols[2] = D_004C9E48.field_0;
    if (root == 0) {
        root = self->field_D0;
    }
    int i;
    for (i = 0; i < n; i++) {
        *(CGt2dObject **)((char *)self + 0x80 + i * 4) = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        func_001D6C40(*(CGt2dObject **)((char *)self + 0x80 + i * 4), CGtV2d(cols[i], 127.5f), CGtV2d(0.0f, 0.0f), mgr->field_30, (void *)(D_00665ED8.field_0), (void *)(texts[i]), 25.0f);
    }
    for (i = 1; i <= n2; i++) {
        *(CGt2dObject **)((char *)self + 0x80 + i * 12) = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        func_001D6C40(*(CGt2dObject **)((char *)self + 0x80 + i * 12), CGtV2d(cols[0], 0.0f + 168.0f + (float)(i - 1) * 32.0f), CGtV2d(0.0f, 0.0f), mgr->field_10, (void *)(D_00665ED8.field_0), (void *)((int)p4[i - 1]), 20.0f);
    }
    for (i = 1; i <= n2; i++) {
        *(CGt2dObject **)((char *)self + 0x84 + i * 12) = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        func_001D6C40(*(CGt2dObject **)((char *)self + 0x84 + i * 12), CGtV2d(cols[1], 0.0f + 168.0f + (float)(i - 1) * 32.0f), CGtV2d(0.0f, 0.0f), mgr->field_10, (void *)(D_00665ED8.field_0), (void *)((int)p5[i - 1]), 20.0f);
    }
    float base = 168.0f;
    if (names2 == 0) {
        base = base + 100.0f / 2.0f;
    }
    for (i = 1; i <= n2; i++) {
        *(CGt2dObject **)((char *)self + 0x88 + i * 12) = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        if (names2 != 0) {
            func_001D6C40(*(CGt2dObject **)((char *)self + 0x88 + i * 12), CGtV2d(cols[2], 0.0f + base + (float)(i - 1) * 32.0f), CGtV2d(0.0f, 0.0f), mgr->field_10, (void *)(D_00665ED8.field_0), (void *)((int)names2[i - 1]), 20.0f);
        } else {
            func_0021AB40(GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(vehicles[i - 1]), name);
            CGtTexture * tex = func_003A4A80_inl1(name);
            if (tex == 0) {
                tex = func_003A4A80_inl1(D_004C9F08);
            }
            int v;
            CGtV4d col;
            if (variants[i - 1] == -999) {
                v = 0;
                col = D_004C9EF0;
            } else {
                col = mgr->field_110;
                unsigned char cnt = ((unsigned char *)tex)[0xA0];
                if (cnt >= 2) {
                    v = variants[i - 1] % cnt;
                } else {
                    v = 0;
                }
            }
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(*(CGt2dObject **)((char *)self + 0x88 + i * 12), CGtV2d(cols[2] - 10.0f, 0.0f + base + (float)(i - 1) * 32.0f), CGtV2d(0.0f, 0.0f), D_004C9E88.v, col, tex, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), v);
        }
    }
}
