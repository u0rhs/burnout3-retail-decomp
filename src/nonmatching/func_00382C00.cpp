// NONMATCHING: func_00382C00 -- retail 58 / ours 58 instructions, 24 in changed runs
// same size/stack slots; scale = D_004C94A0[p2] copy: retail loads y before x, holds &scale (t3) and &scale.y (v1) and reloads y through v1 for the div and mul -- looks like a CGtV2d copy-ctor/accessor shape GtMathPs2.h lacks (N149-type)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// from build/vt\try_func_00382C00_best.cpp
// func_00382C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00382C00;
struct UnkStruct_00382C00_2;
struct UnkStruct_00382C00_a1;
struct UnkStruct_00382C00_a2;
struct UnkStruct_00382C00_e0;
struct UnkStruct_D_004C94A0;
struct UnkStruct_D_01E90350;
struct UnkStruct_func_00382950;

struct UnkStruct_00382C00_e0 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_004C94A0 {
    GtMathPs2::CGtV2d field_0[2];  // [G] element count unknown
};

struct UnkStruct_00382C00_2 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    unsigned long field_20;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
};

struct UnkStruct_00382C00_a2 {
    float field_0;
    float field_4;
};

struct UnkStruct_00382C00_a1 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01E90350 {
    GtMathPs2::CGtV4d field_0;
};

struct UnkStruct_func_00382950 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00382C00 {
    unsigned char pad_0[0x20];
    float field_20;
    float field_24;
    int field_28;
};

extern UnkStruct_D_004C94A0 D_004C94A0;
extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_00382950 func_00382950;

extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)


struct UnkStruct_00382C00b {
    unsigned char pad_0[0x20];
    GtMathPs2::CGtV2d field_20;
    int field_28;
};
// 0x00382C00
extern "C" void func_00382C00(UnkStruct_00382C00b * self, const GtMathPs2::CGtV2d * p0, const GtMathPs2::CGtV2d * p1, int p2)
{
    GtMathPs2::CGtV2d scale = D_004C94A0.field_0[p2];
    self->field_20 = GtMathPs2::CGtV2d(1.0f, 1.0f) / scale;
    self->field_28 = p2;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, *p0 - scale * *p1, scale, D_01E90350.field_0, &func_00382950, 64, 16);
}
