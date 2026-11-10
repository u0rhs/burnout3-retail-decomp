// NONMATCHING: func_00435100 -- retail 326 / ours 326 instructions, 66 in changed runs
// L270: logic/frame/text calls exact; left: image loop -- loop-2 s-register colouring (retail i=s3, self+4i=s0, table1=s1, found2=s1) and float load order of pos/size (retail loads all 8 floats before the first temp store)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (L270): a two-gauge HUD/menu component's Prepare (sibling of func_00434DD0's update, same member layout).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_00435100 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C[2];
    CGt2dObject * field_14[2];
    CGt2dObject * field_1C[2];
    float field_24[2];
    float field_2C[2];
    CGt2dFrame * field_34;
    CGt2dFrame * field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    signed char field_3E;
};

struct UnkStruct_00435100_2;
struct UnkStruct_00435100_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_00435100_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00435100_e0 * field_C;
};
struct UnkStruct_D_0051A868 {
    UnkStruct_00435100_2 * field_0;
    unsigned char pad_4[0xC];
};
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, func_00427080).
struct UnkStruct_00435100_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
struct UnkStruct_D_00665ED0 {
    unsigned char pad_0[0x8];
    void * field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_D_01E90240 {
    CGtV4d field_0;
    unsigned char pad_10[0x10];
};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_01E90240 D_01E90240;
extern CGt2dScene D_01E903E0;
extern UnkStruct_P16 D_0051BA44;
extern CGtV2d D_01ECDD90[2];
extern const CGtV2d D_004D1A48;
extern const CGtV2d D_004D1A50;
extern const CGtV2d D_004D1A58;
extern const CGtV2d D_004D1A80;
extern const CGtV2d D_004D1A88;
extern const CGtV2d D_004D1A90;
extern const CGtV2d D_004D1A98;
extern const CGtV2d D_004D1AA0;
extern const CGtV2d D_004D1AA8;
extern const CGtV2d D_004D1AB0;
extern const CGtV4d D_004D1AC0;
extern const CGtV4d D_004D1AD0;
extern const char D_004D1AE0[];

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" int strcasecmp(const char *, const char *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_0033D650(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, const void *, void *,
                              const unsigned short *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const void *colour,
    void *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

static inline void * func_00435100_inl1(const char * name)
{
    int i;
    UnkStruct_00435100_2 * t0 = D_0051A868.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00435100_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

// 0x00435100
extern "C" bool func_00435100(UnkStruct_00435100 * self, signed char p1)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    CGt2dScene * const scene = &D_01E903E0;
    int i;
    CGt2dFrame * root = scene->field_14;
    self->field_34 = root->ConstructChild();
    self->field_34->field_0.SetIdentity();
    self->field_3E = p1;
    for (i = 0; i < 2; i++) {
        self->field_1C[i] = scene->ConstructObject(self->field_8, self->field_34);
        self->field_C[i] = scene->ConstructObject(self->field_8 + 1, self->field_34);
        self->field_14[i] = scene->ConstructObject(self->field_8 + 2, self->field_34);
    }
    self->field_38 = root->ConstructChild();
    self->field_38->field_0.SetIdentity();
    self->field_38->field_0.field_0 = D_004D1AA8;
    self->field_38->field_0.field_8 = D_004D1AB0;
    for (i = 0; i < 3; i++) {
        scene->field_2c[self->field_8 + i].field_c = self->field_38;
    }
    CGtV4d colour = D_01E90240.field_0;
    const unsigned short * s0 = func_00271A00(&D_0051BA44, 0x183);
    func_0033D650(self->field_1C[0], D_004D1A90 + D_01ECDD90[0] * D_004D1AA0, D_004D1A48, 20.0f, &colour,
                  D_00665ED0.field_8, s0);
    const unsigned short * s1 = func_00271A00(&D_0051BA44, 0x185);
    func_0033D650(self->field_1C[1], D_004D1A90 + D_01ECDD90[1] * D_004D1AA0, D_004D1A48, 20.0f, &colour,
                  D_00665ED0.field_8, s1);
    for (i = 0; i < 2; i++) {
        CGt2dObjectImage_Prepare(self->field_C[i], D_004D1A98 + D_01ECDD90[i] * D_004D1AA0, D_004D1A50,
                                 D_004D1A58 * D_004D1AA0, &D_004D1AD0, func_00435100_inl1(D_004D1AE0),
                                 D_004D1A80, D_004D1A88, 0);
        CGt2dObjectImage_Prepare(self->field_14[i], D_004D1A98 + D_01ECDD90[i] * D_004D1AA0, D_004D1A50,
                                 D_004D1A58 * D_004D1AA0, &D_004D1AC0, func_00435100_inl1(D_004D1AE0),
                                 D_004D1A80, D_004D1A88, 0);
    }
    self->field_3C = 0;
    self->field_3D = 0;
    return true;
}
