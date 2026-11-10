// NONMATCHING: func_003B8EC0 -- retail 135 / ours 135 instructions, 49 in changed runs
// 135/135, 49 changed: func_0033E220/func_003C1990 render-through-frame tail in a loop + CGt2dObjectImage::Prepare link name (8th arg 0); scoped usefloatacc off [G] stops MWCC fusing p.x + i*w into adda/madd (first 0x118 bytes exact). Left: the frame-transform tail's schedule -- retail loads the object pos/size (ld/sd copies) and the size*scale product before the colour vmul; statement reorders did not move it.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003B8EC0 -- hand-written (fresh1). [L] DNAT: CB3RoadRageResultsPage::RenderMultipleImages(const CGtV2d&, const CGtV2d&,
// unsigned short*, const CGt2dFrame&, const void*) (research/proto/new_names.csv, high): a CGt2dObjectTable cell render
// callback drawing field_40 copies of one image side by side, each rendered through the frame (func_0033E220's tail).
// Data-block layout [G] from the loads.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_003B8EC0 {
    CGtV4d field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtTexture *field_30;
    unsigned char pad_34[0xC];
    int field_40;
};
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);

// [L] N185: stand-in for GtMathPs2::Min(CGtV4d, CGtV4d), both operands by reference (as func_0033E220's).
static inline CGtV4d func_003B8EC0_min(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}

// N182: [G] scoped to this function
#pragma push
#pragma usefloatacc off
// 0x003B8EC0
extern "C" void func_003B8EC0(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame,
                              const void *data)
{
    CGtV2d p;
    const UnkStruct_003B8EC0 *d = (const UnkStruct_003B8EC0 *)data;
    CGt2dObject img;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    for (int i = 0; i < d->field_40; i++) {
        p = pos + size * d->field_18 + CGtV2d((float)i * d->field_10.marValues[0], 0.0f);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
            &img, p, d->field_18, d->field_10, d->field_0, d->field_30, d->field_20, d->field_28, 0);
        sp = img.ObjectSpace();
        sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
        sp.mSize = sp.mSize * frame.WorldScale();
        sp.mColour = func_003B8EC0_min(sp.mColour * frame.WorldColour(), white);
        img.Render(sp);
    }
}
#pragma pop
