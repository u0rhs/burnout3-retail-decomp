// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_00427080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGt2dObject-style Prepare: texture lookup = GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi's body as a static inline (char name[13] at sp+0xE8; was [12], one byte short of the 13 written), find-by-name blk->field_18 (N113); const CGtV4d by-value colour; CGtV2d operators for pos/reciprocal size. Only diff in try.py is objdump s8 vs spimdisasm fp naming).

// func_00427080 -- hand-finished. Unnamed in every table, so a placeholder with C linkage; file and Area
// unknown, so _unclassified/. Structs declare only the fields touched; every type is [G].
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EB3MenuCarClasses {};

class CB3VehicleList {
public:
    unsigned long GetCarID(EB3MenuCarClasses, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00427080_2;
struct UnkStruct_00427080_e0;

struct UnkStruct_D_0051A868 {
    UnkStruct_00427080_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00427080_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00427080_e0 * field_C;
};

struct UnkStruct_00427080_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_01EA46FC {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4710 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00427080_1 {
    unsigned char pad_0[0x10];
};

// [G] the object's data block at +0x20 (CGt2dObject::mauDataBlock).
struct UnkStruct_00427080_20 {
    CGtV2d field_0;
    void * field_8;
    unsigned char field_C;
    unsigned char field_D;
    signed char field_E;
    unsigned char field_F;
    unsigned char field_10;
    unsigned char field_11;
};

struct UnkStruct_00427080 {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    UnkStruct_00427080_20 field_20;
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3SunRendererPS2_0024D390).
struct UnkStruct_00427080_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01EA46FC D_01EA46FC;
extern UnkStruct_D_01EA4710 D_01EA4710;
extern CB3VehicleList D_005186A0;

extern "C" void func_004272A0(const void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, void (*)(const void *, const void *), unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int strcasecmp(const char *, const char *);

static inline void * func_00427080_inl1(const char * name)
{
    UnkStruct_00427080_2 * t0 = D_0051A868.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00427080_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

// [G] the body of GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi, inlined here.
static inline void * func_00427080_inl2(int n0, int p0)
{
    // [C] 13 bytes: func_0021AB40 writes out[0..12] (GtID.cpp: out[12] = 0); char[12] overran by one natively. Retail's
    // buffer is sp+0xE8 (0x4271E8/0x427208) with the next slot at sp+0xF8, so 13..15 keep the object byte-identical
    // (tiny_compile + obj_same); char[0x10] grows the frame (a1 spill 0xC0 -> 0xD0).
    char local[13];
    if (p0 == -1) return D_01EA4710.field_0;
    unsigned long r0 = D_005186A0.GetCarID((EB3MenuCarClasses)n0, p0);
    if (r0 == 0) return 0;
    func_0021AB40(r0, local);
    void * v = func_00427080_inl1(local);
    if (v == 0) v = D_01EA46FC.field_0;
    return v;
}

// 0x00427080
extern "C" void func_00427080(UnkStruct_00427080 * self, const CGtV2d & p0, const CGtV2d & p1, const CGtV2d & p2, const CGtV4d p3, int p4, int p5, int p6)
{
    UnkStruct_00427080_20 & d = self->field_20;
    d.field_C = 0;
    d.field_D = 4;
    d.field_E = -1;
    d.field_8 = func_00427080_inl2(p4, p5);
    d.field_F = p4;
    d.field_10 = p5;
    d.field_11 = p6;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(
        self, p0 - p2 * p1, p2, p3, func_004272A0, 64, 24);
    d.field_0 = CGtV2d(1.0f, 1.0f) / self->field_8;
}
