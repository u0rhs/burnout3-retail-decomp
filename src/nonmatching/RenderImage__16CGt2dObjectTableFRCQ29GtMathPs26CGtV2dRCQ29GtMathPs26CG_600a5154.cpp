// NONMATCHING: RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv -- retail 92 / ours 92 instructions, 36 in changed runs
// near2: 36 off, stack offsets only (instructions identical) -- RenderBox's twin, same note: exact text siblings' tail (ObjectSpace/WorldPos/WorldScale/WorldColour/Min); left: white's ctor-temp copy kept without Min's by-value dead slot.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectTable_img {
    CGtV4d field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtTexture *field_30;
};
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d &colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
struct UnkStruct_Gt2dObjectTable_frame {
    unsigned char pad_0[0x20];
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV4d field_30;
};

// [L] N185: stands in for GtMathPs2::Min(CGtV4d, CGtV4d) (B3O0PCH map, 0x50 bytes; not in our header)
static inline CGtV4d v241_min(const CGtV4d &a, const CGtV4d b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}

// [L] stand in for CGt2dObject::Pos() / Size() / Colour() (B3O0PCH map: 0x18 / 0x1C / 0x34 bytes; not in our header)
static inline CGtV2d func_0033DF50_inl1(const CGt2dObject &o) { return o.mObjectSpace.mTopLeftPos; }
static inline CGtV2d func_0033DF50_inl2(const CGt2dObject &o) { return o.mObjectSpace.mSize; }
static inline CGtV4d func_0033DF50_inl3(const CGt2dObject &o) { return o.mObjectSpace.mColour; }
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(
    const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_Gt2dObjectTable_img *d = (const UnkStruct_Gt2dObjectTable_img *)data;
    const UnkStruct_Gt2dObjectTable_frame *f = (const UnkStruct_Gt2dObjectTable_frame *)&frame;
    CGt2dObjectImage box;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        &box, pos + size * d->field_18, d->field_18, d->field_10, d->field_0, d->field_30, d->field_20, d->field_28, 0);
    sp = box.ObjectSpace();
    sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
    sp.mSize = sp.mSize * frame.WorldScale();
    sp.mColour = v241_min(sp.mColour * frame.WorldColour(), white);
    box.Render(sp);
}



