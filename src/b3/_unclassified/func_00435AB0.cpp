// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// Hand-written; the lifter refused it (HUD component prepare: find-by-name as a static inline helper (N113); &D_0066A4C0 as a const pointer; shadow declared before scene but assigned after it (register order + schedule); scene elements 0x70 bytes; GetString by its label func_00271A00).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EHUDAlign {};

struct UnkStruct_00435AB0_4;
struct UnkStruct_00435AB0_e0;

class CB3HUDComponent {
public:
    static CGt2dObjectText::COutlineDropShadow maOutlineDropShadow[3];
};

struct UnkStruct_D_00518688 {
    UnkStruct_00435AB0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00435AB0_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00435AB0_e0 * field_C;
};

struct UnkStruct_00435AB0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_00435AB0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

struct UnkStruct_00435AB0_s {
    unsigned char pad_0[0x14];
    CGt2dScene field_14;
    unsigned char pad_end[0x70 - 0x14 - sizeof(CGt2dScene)];
};

struct UnkStruct_00435AB0 {
    unsigned char pad_0[0x4];
    UnkStruct_00435AB0_s * field_4;
    CGt2dFrame * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    CGt2dObject * field_20[2];
    unsigned char pad_28[0x28];
    CGtTexture * field_50;
    void * field_54;
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
};

struct UnkStruct_D_00665ED0 {
    CGt2dFont * field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01EA46F8 {
    void * field_0;
    unsigned char pad_4[0xC];
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01EA46F8 D_01EA46F8;
extern char D_004D1B10[];
extern const CGtV2d D_004D1AF0;

extern "C" int strcasecmp(const char *, const char *);
// 0x00271A00: CB3Strings::GetString(int) [L] (B3Strings.h); called by its asm label as the sibling units do.
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);  // CB3HUDComponent::AdjustScalingForSplitScreen()
// 0x001D6970: CGt2dObjectText::Prepare(const CGtV2d&,const CGtV2d&,float,CGtV4d,const CGt2dFont*,const unsig... (name
// truncated in retail's tables); [G] the last two parameters from the registers (t1 a string, t2 an outline/shadow).
extern "C" void func_001D6970(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *,
                              const unsigned short *, const CGt2dObjectText::COutlineDropShadow *);
// CGt2dObjectImage::Prepare by its link name, with retail's 8th stack argument (N68).
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

static inline CGtTexture * func_00435AB0_inl1(const char * name)
{
    UnkStruct_00435AB0_4 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00435AB0_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x00435AB0
extern "C" int func_00435AB0(UnkStruct_00435AB0 * self, int p0, int p1, int p2)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 2, 1, p0, (EHUDAlign)p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(self);
    UnkStruct_D_0066A4C0 * const g = &D_0066A4C0;
    const CGt2dObjectText::COutlineDropShadow * shadow;
    CGt2dScene * scene = &self->field_4[self->field_1C].field_14;
    shadow = &CB3HUDComponent::maOutlineDropShadow[1];
    int layer = self->field_10;
    self->field_50 = func_00435AB0_inl1(D_004D1B10);
    self->field_54 = D_01EA46F8.field_0;
    for (int i = 0; i < 2; i++) {
        self->field_20[i] = scene->ConstructObject(layer, self->field_8);
    }
    const unsigned short * text = func_00271A00(&D_0051BA44, 0x84);
    func_001D6970(self->field_20[1], CGtV2d(-10.0f, -70.0f), CGtV2d(1.0f, 0.5f), 22.0f, g->field_40,
                  D_00665ED0.field_0, text, shadow);
    CGt2dObjectImage_Prepare(self->field_20[0], CGtV2d(self->field_20[1]->mObjectSpace.mTopLeftPos.marValues[0] - 10.0f, -70.0f),
                             CGtV2d(1.0f, 0.5f), D_004D1AF0, g->field_40, self->field_50,
                             CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    return 1;
}
