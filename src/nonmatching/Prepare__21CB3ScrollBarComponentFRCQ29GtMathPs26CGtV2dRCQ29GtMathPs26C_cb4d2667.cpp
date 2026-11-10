// NONMATCHING: Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData -- retail 214 / ours 219 instructions, 144 in changed runs
// a156: 219 vs 214 instrs, 144 changed. Logic complete (field_28=CGtV2d(10,f); field_20=pos-field_28*size; 3 ConstructObject; 2 colour picks via sel->field_0 / count-1 ([0] vs [2] of D_01E90240 colour array); 2 Image::Prepare with D_01EA4790+0xF0/+0x100 uv rows; Box::Prepare thumb). Left: (1) saved-reg assignment (retail mgr=s7 via lui in prologue, sel=s6, size=s3, layer=s0, frame=s1; ours mgr=s3/sel=s7); (2) retail builds the UV row pointer as daddiu v1,0xF0 + addu (variable-offset form) once and t3=t2+8, ours folds to lui/addiu twice (+4 instrs); (3) 2nd colour read is a fresh lui/addiu D_01E90240 (a0) shared by both arms, ours duplicates lui per arm. Header include/b3/classes/CB3ScrollBarComponent.h lacks fields 0xC,0x20..0x38 and Prepare (conflict: none, just incomplete).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a156): CB3ScrollBarComponent::Prepare -- builds the up/down arrow images and the thumb box.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGtTexture;
class CGt2dFrame;

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern CGtTexture *D_01EA46B0[0x38];
struct UnkStruct_D_01EA4790 {
    CGtV2d uv;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01EA4790 D_01EA4790;


class CB3ScrollBarComponent {
public:
    bool Prepare(const CGtV2d &, const CGtV2d &, float, const CB3MenuComponentSelectionData *);
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    const CB3MenuComponentSelectionData * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    CGt2dObject * field_18;
    unsigned char pad_1C[0x4];
    CGtV2d field_20;
    CGtV2d field_28;
    int field_30;
    int field_34;
    float field_38;
};

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour);

bool CB3ScrollBarComponent::Prepare(const CGtV2d & pos, const CGtV2d & size, float anchorY, const CB3MenuComponentSelectionData * sel)
{
    CB3MenuPageManager * const mgr = &D_01E90240;
    CGt2dScene * const scene = &D_01E903E0;
    CGt2dFrame * frame = (CGt2dFrame *)scene->field_14;
    int layer = field_8;
    Prepare__20CB3MenuComponentBaseFv(this);
    field_C = sel;
    field_28 = CGtV2d(10.0f, anchorY);
    field_20 = pos - field_28 * size;
    field_30 = -1;
    field_34 = field_C->field_2;
    field_14 = scene->ConstructObject(layer, frame);
    field_18 = scene->ConstructObject(layer, frame);
    field_10 = scene->ConstructObject(layer, frame);
    CGtV4d c0;
    CGtV4d * const cols = mgr->field_0;
    if (field_C->field_0 != 0) {
        c0 = cols[0];
    } else {
        c0 = cols[2];
    }
    CGt2dObjectImage_Prepare(field_14, CGtV2d(field_20.X(), 8.0f + field_20.Y()), CGtV2d(0.0f, 0.5f), CGtV2d(10.0f, 10.0f), c0,
                             D_01EA46B0[0], *(const CGtV2d *)((char *)&D_01EA4790 + 0xF0), *(const CGtV2d *)((char *)&D_01EA4790 + 0xF8), 0);
    CGtV4d c1;
    CB3MenuPageManager * const q = &D_01E90240;
    if (field_C->field_0 != field_C->field_2 - 1) {
        c1 = q->field_0[0];
    } else {
        c1 = q->field_0[2];
    }
    CGt2dObjectImage_Prepare(field_18, CGtV2d(field_20.X(), (field_20.Y() + field_28.Y()) - 8.0f), CGtV2d(0.0f, 0.5f), CGtV2d(10.0f, 10.0f), c1,
                             D_01EA46B0[0], *(const CGtV2d *)((char *)&D_01EA4790 + 0x100), *(const CGtV2d *)((char *)&D_01EA4790 + 0x108), 0);
    float h = (field_28.Y() - 32.0f) / (float)field_34;
    field_38 = h;
    if (h < 10.0f) {
        h = 10.0f;
        field_38 = field_38 - 10.0f / (float)field_34;
    }
    Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
        field_10, CGtV2d(field_20.X(), 0.0f + (16.0f + field_20.Y()) + field_38 * (float)field_C->field_0), CGtV2d(0.0f, 0.0f), CGtV2d(10.0f, h),
        mgr->field_0[2]);
    return true;
}
