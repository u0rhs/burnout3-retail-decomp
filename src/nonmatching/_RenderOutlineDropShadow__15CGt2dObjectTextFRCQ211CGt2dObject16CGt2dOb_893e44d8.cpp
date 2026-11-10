// NONMATCHING: _RenderOutlineDropShadow__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 159 / ours 159 instructions, 8 in changed runs
// L284: 8 off, logic/schedule/frame exact (4 N140 pads + W*W product in a placeholder inline puts the ctor temp at 0xA0); left: size lanes f5/f3 vs retail f4(x)/f5(y) in the two products
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CGt2dObjectText::_RenderOutlineDropShadow(const CGt2dObject::CGt2dObjectSpace&,const void*) -- hand-written (L284; the lifter
// refused vmulw.w). [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectText.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). A static (no 'this': a0 = space, a1 = data block), as _RenderOutline /
// _RenderDropShadow. Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

// [L] N185: stands in for a missing GtMathPs2 inline -- operator *(WAxisType, WAxisType) ([C] API: B3O0PCH map, 0x50 bytes).
static inline WAxisType MulWW(WAxisType a, WAxisType b) { u_long128 r; asm("vmulw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
// [L] N185: stands in for CGtV4d::SetA(WAxisType) ([C] API: B3O0PCH map, 0x38 bytes): w = vf0.w * a.w.
static inline void SetAW(CGtV4d &v, WAxisType a) { asm("vmulw.w %0, $vf0, %1w" : "+j"(v.mData) : "j"(a.lVector)); }

struct UnkStruct_Gt2dObjectText_font {
    unsigned char pad_0[4];
    CGtTexture *field_4;
};
struct UnkStruct_001D6170_ods {          // [G] outline / drop-shadow style
    CGtV4d field_0;                      // colour
    CGtV2d field_10;
    CGtV2d field_18;
};
struct UnkStruct_001D6170_data {
    UnkStruct_Gt2dObjectText_font *field_0;
    unsigned char pad_4[0x8];
    const UnkStruct_001D6170_ods *field_C;
    CGtV2d field_10;
};

extern "C" int _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);
struct UnkStruct_001D6170_pad { int x[4]; UnkStruct_001D6170_pad() {} ~UnkStruct_001D6170_pad() {} };
// [G] placeholder inline (N148): the shadow alpha (colour alpha squared), evaluated inside a helper (its temporaries sit below
// the CGtV4d constructor's local, as retail's frame has them).
static inline float func_001D6170_inl1(const CGtV4d &c) { return MulWW(c.W(), c.W()); }
static inline WAxisType func_001D6170_inl2(const CGtV4d &c) { return MulWW(c.W(), c.W()); }

extern "C" void _RenderOutlineDropShadow__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_001D6170_data *d = (const UnkStruct_001D6170_data *)data;
    const UnkStruct_001D6170_ods *s = d->field_C;
    CGtV2d size = d->field_10 * space.mSize;
    CGtV4d shadow(0.0f, 0.0f, 0.0f, func_001D6170_inl1(space.mColour));
    CGtV2d off = s->field_10 * size;
    CGtV2d drop = s->field_18 * size;
    CGtV4d col;
    col = s->field_0;
    UnkStruct_001D6170_pad p0, p1, p2, p3;
    int n = _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(space, data);
    if (n > 0) {
        SetAW(col, MulWW(col.W(), shadow.W()));
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        for (int j = 0; j < 2; j++) {
            Gt2dRenderer::RenderSpritesTex(col, off + drop, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                           (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
            Gt2dRenderer::RenderSpritesTex(col, off - drop, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                           (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
            drop.marValues[0] = -drop.marValues[0];
        }
        for (int j = 0; j < 2; j++) {
            Gt2dRenderer::RenderSpritesTex(shadow, drop, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                           (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
            Gt2dRenderer::RenderSpritesTex(shadow, -drop, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                           (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
            drop.marValues[0] = -drop.marValues[0];
        }
        Gt2dRenderer::RenderSpritesTex(space.mColour, CGtV2d(0.0f, 0.0f), n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
    }
}

