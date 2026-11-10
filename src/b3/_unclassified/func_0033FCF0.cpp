// Hand-written; the lifter refused it (a84: CB3TableComponent::PrepareRowBackgrounds [L] DNAT; modeled on func_0033FF10 (N24 goto loop, GetRowPos/Size Y(), temps at call), i assigned after the table Prepare).

// func_0033FCF0 -- CB3TableComponent::PrepareRowBackgrounds(...) [L] DNAT (research/proto/new_names.csv, medium)
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
extern CGtV4d D_01E90340;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);

// [L] DNAT: CB3TableComponent::PrepareRowBackgrounds(...) (research/proto/new_names.csv, medium)
// 0x0033FCF0
extern "C" int func_0033FCF0(UnkStruct_0033FF10 * self, const CGtV2d & pos, const CGtV2d & p2, const CGtV2d & p3,
                             const CGt2dObjectTableData * data, CGt2dObject * panel, CGt2dObject ** objs)
{
    int i;
    Prepare__20CB3MenuComponentBaseFv(self);
    CGt2dScene * const scene = &D_01E903E0;
    CGt2dFrame * root = scene->field_14;
    self->field_30 = 0;
    self->field_30 |= 1;
    self->field_30 |= 8;
    self->field_30 |= 0x10;
    self->field_C = (CGt2dObjectTable *)scene->ConstructObject(self->field_8 + 1, root);
    self->field_C->Prepare(data, pos, p2, p3, D_01E90340);
    self->field_18 = objs;
    i = 0;
    self->field_1C = (int)panel;
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
        if (i == 0) {
            self->field_1C = (int)scene->ConstructObject(self->field_8, root);
            Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi((void *)self->field_1C, at, CGtV2d(0.0f, 0.0f), size, 27, 0);
        } else {
            self->field_18[i - 1] = scene->ConstructObject(self->field_8, root);
            ((CB3HUDBackground2dObject *)self->field_18[i - 1])->Prepare(at, CGtV2d(0.0f, 0.0f), size, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), 3);
        }
    }
    i++;
test:
    if (i < self->field_20->field_8) goto body;
    return 1;
}
