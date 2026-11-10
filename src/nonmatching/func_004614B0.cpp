// NONMATCHING: func_004614B0 -- retail 191 / ours 191 instructions, 36 in changed runs
// near33: 52->36. D_004E0AE4 is .lit4 FLT_MAX -> literal; proven signatures for func_003D0710 (obj,pos&,anchor&,colour,int,int,int,(void *)(font),float,float,(void *)(text),int) and func_0033D4E0 (obj,pos&,anchor&,float,colour,(void *)(font),(void *)(text),scale*,int) -> 0033D4E0 call exact; type declared before mgr. Left: s-regs (retail mgr s2 / slot ptr s0, ours s0 / s1-s2; sreg run found nothing) and 003D0710 arg scheduling (retail t2=0 early, t1=t0 copy in jal slot; f12 lookup before the pos.y store)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_004614B0 -- retail 191 / ours 191 instructions, 49 in changed runs
// control flow, layout, registers and frame exact (pooled-object inline helper with field_C as void* array, if (p1 != 4005) {...} else { switch (type) { case 10: ... } }, scene via cast). Left: argument-setup scheduling for func_003D0710 and func_0033D4E0 (load order of D_004D3A70[type] / D_004D3AA0[type] / D_004D3A6C), 39 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_004614B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

class CGt2dFrame;
class CGtTexture;

struct UnkStruct_004614B0;
struct UnkStruct_004614B0_3;
struct UnkStruct_004614B0_e3;
struct UnkStruct_D_004D3A6C;
struct UnkStruct_D_004E0AE4;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00665ED0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01EA46B8;
struct UnkStruct_D_01EA4790;
struct UnkStruct_D_01EA4798;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_004614B0_3 {
    float field_0;
    float field_4;
    float field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    int field_24;
    float field_28;
    float field_2C;
    float field_30;
    int field_34;
    float field_38;
    float field_3C;
};

struct UnkStruct_D_004D3A6C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E0AE4 {
    float field_0;
};

struct UnkStruct_D_01EA46B8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004614B0_e3 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01E90240 {
    UnkStruct_004614B0_e3 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x100];
    GtMathPs2::CGtV4d field_110;
};

struct UnkStruct_D_01EA4790 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4798 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004614B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    void * field_C[1];  // [G] element count unknown
    unsigned char pad_10[0x7C];
    int field_8C;
    unsigned char pad_90[0x4];
    int field_94;
    int field_98;
    unsigned char pad_9C[0x4];
    float field_A0;
    float field_A4;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_004D3A6C D_004D3A6C;
extern int D_004D3AA0[];  // [G] element count unknown
extern float D_004D3A70[];  // [G] element count unknown
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_004E0AE4 D_004E0AE4;
extern UnkStruct_D_01EA46B8 D_01EA46B8;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01EA4790 D_01EA4790;
extern UnkStruct_D_01EA4798 D_01EA4798;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const void *, const void *, const void *, GtMathPs2::CGtV4d, void *, const void *, const void *, int);  // passed 1 more argument(s) [G]; CGt2dObjectImage::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,CGtTexture*,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)
extern "C" int func_00271A00(void *, int);
extern "C" void func_003D0710(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const void *, int, int, int, void *, float, float, void *, int);
extern "C" void func_0033D4E0(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, const void *, void *, void *, const GtMathPs2::CGtV2d *, int);

// [G] inlined helper (name unknown): takes the next of the 32 pooled objects, constructing it on first use
static inline void func_004614B0_next(UnkStruct_004614B0 * self)
{
    UnkStruct_D_01E903E0 * scene = (UnkStruct_D_01E903E0 *)&D_01E903E0;
    int root = scene->field_14;
    int i = self->field_98++ % 32;
    if (self->field_C[i] == 0) {
        self->field_C[i] = (void *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, (void *)root);
    }
    self->field_8C = (int)self->field_C[i];
}

// 0x004614B0
extern "C" int func_004614B0(UnkStruct_004614B0 * self, int p0, int p1)
{
    GtMathPs2::CGtV2d pos1;
    GtMathPs2::CGtV2d anchor1;
    GtMathPs2::CGtV2d pos2;
    GtMathPs2::CGtV2d anchor2;
    GtMathPs2::CGtV2d scale2;
    GtMathPs2::CGtV2d pos3;
    GtMathPs2::CGtV2d anchor3;
    GtMathPs2::CGtV2d size3;
    int type = (unsigned char)p0;
    UnkStruct_D_01E90240 * mgr = &D_01E90240;
    int r = 0;
    if (p1 != 4005) {
        func_004614B0_next(self);
        if ((unsigned int)(type - 8) < 2) {
            int text = func_00271A00(&D_0051BA44, p1);
            anchor1.Set(0.5f, 0);
            pos1.Set(320.0f, D_004D3A6C.field_0);
            func_003D0710((void *)self->field_8C, pos1, anchor1, &mgr->field_110, 1, 1, 0, (void *)(D_00665ED0.field_0), D_004D3A70[type], 3.402823466e+38f, (void *)(text), 0);
        } else {
            scale2.Set(2.0f, 2.0f);
            int text = func_00271A00(&D_0051BA44, p1);
            anchor2.Set(0.5f, 0);
            pos2.Set(320.0f, D_004D3A6C.field_0);
            func_0033D4E0((void *)self->field_8C, pos2, anchor2, D_004D3A70[type], &mgr->field_0[D_004D3AA0[type]], (void *)(D_00665ED0.field_0), (void *)(text), &scale2, 2);
        }
        r = self->field_8C;
    } else {
        switch (type) {
        case 10:
                func_004614B0_next(self);
                size3.Set(400.0f, 100.0f);
                anchor3.Set(0.5f, 0);
                pos3.Set(320.0f, D_004D3A6C.field_0);
                Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)self->field_8C, &pos3, &anchor3, &size3, mgr->field_110, (void *)D_01EA46B8.field_0, &D_01EA4790, &D_01EA4798, 0);
                r = self->field_8C;
            break;
        }
    }
    self->field_94++;
    if (self->field_94 >= 706) {
        self->field_94 = -1;
        self->field_A0 = 160.0f / self->field_A4;
    }
    return r;
}

