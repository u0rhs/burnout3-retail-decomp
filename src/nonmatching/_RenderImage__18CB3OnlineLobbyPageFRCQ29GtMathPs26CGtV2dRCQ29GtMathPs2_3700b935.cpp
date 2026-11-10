// NONMATCHING: _RenderImage__18CB3OnlineLobbyPageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv -- retail 275 / ours 228 instructions, 379 in changed runs
// draftAN fork B C-first (shape of the archived CGt2dObjectTable::RenderImage): two 9x11 CGt2dObjectImage halves (texture D_01EA46F8, palette colour D_01E90240[0]) either side of the cell centre (anchor (0,0.5) at centre.x - 9 - 1, UVs D_01EA47B0..BC; anchor (1,0.5) at centre.x + 9 + 1, UVs D_01EA47C0..CC), each moved into the frame (WorldPos + WorldScale*pos, size*scale, Min(colour*WorldColour, 1)) and rendered through its callback; 228/275, calls identical (callback through t9 vs v1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid): both Prepare argument lists (incl. the 9th stack 0), the constants (9, 11, 0/1, 0.5, the unfolded -9-1 / +9+1), the frame transform and the render call traced

// CB3OnlineLobbyPage::_RenderImage(const CGtV2d&, const CGtV2d&, unsigned short*, const CGt2dFrame&, const void*) -- draftAN fork B
// (C-first draft). 0x311440, 0x44C. [C] name: the mangled symbol in retail's tables (a table-cell render callback, static: no this).
// Shape from the archived CGt2dObjectTable::RenderImage (0x33DF50): a local CGt2dObjectImage prepared, its object space moved into the
// frame (WorldPos + WorldScale x pos, size x WorldScale, colour = Min(colour x WorldColour, 1)) and rendered through its callback.
// What it draws [L]: two 9 x 11 images with texture D_01EA46F8 in palette colour D_01E90240[0], centred vertically in the cell:
// the left one anchored (0, 0.5) at centre.x - 9 - 1 with UVs D_01EA47B0..BC, the right one anchored (1, 0.5) at centre.x + 9 + 1
// with UVs D_01EA47C0..CC ([G] two arrow halves either side of the cell centre). The text and data arguments are not read.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
using namespace GtMathPs2;

extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d &colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);   // [C] 9th stack argument (N68), 0 here
extern CGtV4d D_01E90240[];                 // the menu colour palette (as the RoundedPanel / heading sources); [0] used
extern CGtTexture *D_01EA46F8;              // [G] texture pointer (lui/%lo)
// [C] texture-atlas UVs, one symbol per float in retail (lui/%lo each)
extern float D_01EA47B0, D_01EA47B4, D_01EA47B8, D_01EA47BC;
extern float D_01EA47C0, D_01EA47C4, D_01EA47C8, D_01EA47CC;

// [L] N185: stands in for GtMathPs2::Min(CGtV4d, CGtV4d) (B3O0PCH map; as the RenderImage archive)
static inline CGtV4d func_00311440_inl1(const CGtV4d &a, const CGtV4d b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}

class CB3OnlineLobbyPage {
public:
    static void _RenderImage(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);
};

// 0x00311440
void CB3OnlineLobbyPage::_RenderImage(const CGtV2d & pos, const CGtV2d & size, unsigned short * text, const CGt2dFrame & frame,
                                      const void * data)
{
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    {
        CGt2dObjectImage img;
        CGt2dObject::CGt2dObjectSpace sp;
        CGtV2d lAnchor(0.0f, 0.5f);
        CGtV2d lSize(9.0f, 11.0f);
        CGtV4d lColour(D_01E90240[0].mData);
        CGtV2d lUV0(D_01EA47B0, D_01EA47B4);
        CGtV2d lUV1(D_01EA47B8, D_01EA47BC);
        CGtV2d lPos = pos + size * 0.5f;
        lPos.Set(lPos.X() - lSize.X() - 1.0f, lPos.Y());
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
            &img, lPos, lAnchor, lSize, lColour, D_01EA46F8, lUV0, lUV1, 0);
        sp = img.ObjectSpace();
        sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
        sp.mSize = sp.mSize * frame.WorldScale();
        sp.mColour = func_00311440_inl1(sp.mColour * frame.WorldColour(), white);
        img.Render(sp);
    }
    {
        CGt2dObjectImage img;
        CGt2dObject::CGt2dObjectSpace sp;
        CGtV2d lAnchor(1.0f, 0.5f);
        CGtV2d lSize(9.0f, 11.0f);
        CGtV4d lColour(D_01E90240[0].mData);
        CGtV2d lUV0(D_01EA47C0, D_01EA47C4);
        CGtV2d lUV1(D_01EA47C8, D_01EA47CC);
        CGtV2d lPos = pos + size * 0.5f;
        lPos.Set(lPos.X() + lSize.X() + 1.0f, lPos.Y());
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
            &img, lPos, lAnchor, lSize, lColour, D_01EA46F8, lUV0, lUV1, 0);
        sp = img.ObjectSpace();
        sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
        sp.mSize = sp.mSize * frame.WorldScale();
        sp.mColour = func_00311440_inl1(sp.mColour * frame.WorldColour(), white);
        img.Render(sp);
    }
}
