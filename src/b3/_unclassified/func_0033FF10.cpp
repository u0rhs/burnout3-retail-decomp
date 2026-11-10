// Hand-written; the lifter refused it (table component prepare: N24 label loop (start 1, or 0 by the flag); GetRowPos/GetRowSize results read through a Y() accessor on a CGtV2d subclass (stand-in for CGtV2d::Y(), not in GtMathPs2.h); find-by-name as a static inline helper (N113). Uses fp: diff_vs_retail.py needs an s8/fp alias).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_0033FF10_4;
struct UnkStruct_0033FF10_e0;

struct UnkStruct_D_0051A868 {
    UnkStruct_0033FF10_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0033FF10_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0033FF10_e0 * field_C;
};

struct UnkStruct_0033FF10_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0033FF10_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

class CGt2dObjectTableData {
public:
    unsigned char pad_0[0x8];
    int field_8;
};

// [G] stands for CGtV2d with its Y() accessor (B3O0PCH map: GtMathPs2::CGtV2d::Y()), which GtMathPs2.h doesn't
// define yet.
struct UnkStruct_0033FF10_v2 : public CGtV2d {
    float Y() const { return marValues[1]; }
};

class CGt2dObjectTable : public CGt2dObject {
public:
    void Prepare(const CGt2dObjectTableData *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
    UnkStruct_0033FF10_v2 GetRowPos(int);   // [G] return type: an 8-byte result through a0 (hidden pointer)
    UnkStruct_0033FF10_v2 GetRowSize(int);  // [G] as GetRowPos
};

class CB3HUDBackground2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
};

struct UnkStruct_0033FF10 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObjectTable * field_C;
    unsigned char pad_10[0x8];
    CGt2dObject ** field_18;
    int field_1C;
    const CGt2dObjectTableData * field_20;
    unsigned char pad_24[0xC];
    int field_30;
    CGt2dObject * field_34;
    CGt2dObject * field_38;
};

extern UnkStruct_D_0051A868 D_0051A868;
extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern int D_004E2DB0;
extern char D_004C5C20[];
extern const CGtV2d D_004C5BD8;
extern const CGtV2d D_004C5BE0;
extern const CGtV2d D_004C5BE8;
extern const CGtV2d D_004C5BF0;
extern const CGtV2d D_004C5BF8;
extern const CGtV2d D_004C5C00;
extern const CGtV2d D_004C5C08;

extern "C" int strcasecmp(const char *, const char *);
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
// CGt2dObjectImage::Prepare by its link name, with retail's 8th stack argument (N68).
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

static inline CGtTexture * func_0033FF10_inl1(const char * name)
{
    UnkStruct_0033FF10_4 * t0 = D_0051A868.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0033FF10_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0033FF10
extern "C" int func_0033FF10(UnkStruct_0033FF10 * self, const CGtV2d & pos, const CGtV2d & p2, const CGtV2d & p3,
                             bool flag, const CGt2dObjectTableData * data, CGt2dObject ** objs, int p7)
{
    int i = 1;
    D_004E2DB0 = p7;
    Prepare__20CB3MenuComponentBaseFv(self);
    CGt2dScene * const scene = &D_01E903E0;
    CB3MenuPageManager * const mgr = &D_01E90240;
    CGt2dFrame * root = scene->field_14;
    self->field_30 = 0;
    self->field_30 |= 1;
    self->field_30 |= 8;
    if (flag) {
        self->field_30 |= 0x10;
        i = 0;
    }
    self->field_1C = 0;
    self->field_C = (CGt2dObjectTable *)scene->ConstructObject(self->field_8 + 1, root);
    self->field_C->Prepare(data, pos, p2, p3, mgr->field_100);
    self->field_18 = objs;
    self->field_20 = data;
    goto test;
body:
    {
        CGtV2d size;
        CGtV2d at;
        at.marValues[0] = pos.marValues[0];
        at.marValues[1] = self->field_C->GetRowPos(i).Y();
        size = p3;
        size.marValues[1] = self->field_C->GetRowSize(i).Y();
        self->field_18[i] = scene->ConstructObject(self->field_8, root);
        ((CB3HUDBackground2dObject *)self->field_18[i])->Prepare(at, CGtV2d(0.0f, 0.0f), size, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), 3);
    }
    i++;
test:
    if (i < self->field_20->field_8) goto body;
    if (D_004E2DB0 != 0) {
        CGtTexture * tex = func_0033FF10_inl1(D_004C5C20);
        self->field_34 = 0;
        self->field_38 = 0;
        self->field_34 = scene->ConstructObject(self->field_8 + 1, root);
        self->field_38 = scene->ConstructObject(self->field_8 + 1, root);
        CGt2dObjectImage_Prepare(self->field_34,
                                 CGtV2d(5.0f + (self->field_18[0]->mObjectSpace.mTopLeftPos.marValues[0] + self->field_18[0]->mObjectSpace.mSize.marValues[0]),
                                        self->field_C->mObjectSpace.mTopLeftPos.marValues[1]),
                                 D_004C5BD8, D_004C5BE8, mgr->field_110, tex, D_004C5BF0, D_004C5C08, 0);
        CGt2dObjectImage_Prepare(self->field_38,
                                 CGtV2d(5.0f + (self->field_18[0]->mObjectSpace.mTopLeftPos.marValues[0] + self->field_18[0]->mObjectSpace.mSize.marValues[0]),
                                        self->field_C->mObjectSpace.mTopLeftPos.marValues[1] + self->field_C->mObjectSpace.mSize.marValues[1]),
                                 D_004C5BE0, D_004C5BE8, mgr->field_110, tex, D_004C5C00, D_004C5BF8, 0);
    }
    return 1;
}
