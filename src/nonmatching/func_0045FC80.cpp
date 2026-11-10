// NONMATCHING: func_0045FC80 -- retail 154 / ours 155 instructions, 100 in changed runs
// fresh2: 155 vs 154, 100 in changed runs, frame 0xB0 vs 0xC0. Logic believed right (texture-find inline as CB3GraphicsManagerBase::Prepare, two CGt2dObjectImage::Prepare + func_003824D0 with CGtV2d temporaries, switch case 0 / case 1,2). Key open point: retail computes (float)610 once into f20 (li/mtc1/cvt.s.w) and keeps it across three calls; ours rematerialises it after each call (int local, (float)610 literal, const int all the same; opt_propagation off keeps it but spills f21-f24)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_0045FC80 -- hand-written from the lifted draft (fresh2).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to. Callee signatures from proven callers
// (B3OnlineLobbyPage_003113C0.cpp: CGt2dObjectImage::Prepare; B3HUDEscapeDistance_003D8BC0.cpp: func_003824D0).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGtTexture;
struct UnkStruct_0045FC80_e0;

struct UnkStruct_0045FC80_dic {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0045FC80_e0 * field_C;
};

struct UnkStruct_0045FC80_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0045FC80_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

struct UnkStruct_D_0051A868 {
    UnkStruct_0045FC80_dic * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [L] D_01E90240: CB3MenuPageManager (BRIEF big2); field_40/50/110 are colours.
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
    CGtV4d field_50;
    unsigned char pad_60[0xB0];
    CGtV4d field_110;
};

struct UnkStruct_0045FC80_o {
    float field_0;
};

struct UnkStruct_0045FC80 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x8];
    int field_18;
    unsigned char pad_1C[0x4];
    unsigned long field_20[1];  // [G] element count unknown
    unsigned char pad_28[0x118];
    int field_140[1];  // [G] element count unknown
    unsigned char pad_144[0x8C];
    unsigned long field_1D0[1];  // [G] element count unknown
    unsigned char pad_1D8[0x318];
    int field_4F0[1];  // [G] element count unknown
    unsigned char pad_4F4[0x18C];
    void * field_680;
    void * field_684;
    UnkStruct_0045FC80_o * field_688;
};

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01E90240 D_01E90240;
extern char D_004D39C8[];
extern const CGtV2d D_004D39A0;
extern const CGtV2d D_004D39A8;
extern const CGtV2d D_004D39B0;
extern const CGtV2d D_004D39B8;
extern const CGtV2d D_004D39C0;
extern char D_0051BA44[];

extern "C" int strcasecmp(const char *, const char *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    void *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, void *, int, float, float);
extern "C" int func_00271A00(void *, int);

static inline CGtTexture * func_0045FC80_inl1(UnkStruct_0045FC80_dic * t0, const char * name)
{
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0045FC80_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0045FC80
extern "C" unsigned long func_0045FC80(UnkStruct_0045FC80 * self)
{
    CGtTexture * tex = func_0045FC80_inl1(D_0051A868.field_0, D_004D39C8);
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    int w = 610;
    float x = (float)w;
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        self->field_684, CGtV2d(x, 96.0f), CGtV2d(1.0f, 0.5f), D_004D39A0, mgr->field_110, tex, D_004D39B0, D_004D39B8, 0);
    unsigned long r;
    int text;
    switch (self->field_C) {
    case 0:
        text = func_00271A00(D_0051BA44, self->field_140[self->field_18]);
        r = self->field_20[self->field_18];
        break;
    case 1:
    case 2:
        text = func_00271A00(D_0051BA44, self->field_4F0[self->field_18]);
        r = self->field_1D0[self->field_18];
        break;
    }
    func_003824D0(self->field_688, CGtV2d(x - (8.0f + D_004D39A0.marValues[0]), 96.0f), CGtV2d(1.0f, 0.5f), 26.0f, mgr->field_40, mgr->field_50, (void *)(text), 33, 1.5f, 3.402823466e+38f);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        self->field_680, CGtV2d(self->field_688->field_0 - 8.0f, 96.0f), CGtV2d(1.0f, 0.5f), D_004D39A0, mgr->field_110, tex, D_004D39A8, D_004D39C0, 0);
    return r;
}

