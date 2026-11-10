// NONMATCHING: _Render__16CB3Score2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 209 / ours 209 instructions, 103 in changed runs
// v294: logic exact, 209/209, frame 0x1A0 (3 N140 pads; retail has 2 dead 8-byte slots 0x170/0x178 instead of the 3rd pad -> 8-byte temps 0x10 off); left: s0/s6 swap for &off.y (store vs load pointer), the two -off temporaries' f0/f1 numbering + store order, one addiu a0,s5,16 slot; not the N220 tail (space read in place)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3Score2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- hand-written (v294; the lifter refused the
// const-reference parameter). [C] name: the mangled symbol. A static render callback (no 'this': a0 = space, a1 = the data
// block), as CGt2dObjectText::_RenderDropShadow: builds the text batch, draws a black shadow at four offsets and the text,
// then scales the batch about the object's centre and draws it again additively [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectText_font {
    unsigned char pad_0[4];
    CGtTexture *field_4;       // [G] the font's texture (Gt2dFont.h field_4)
};
struct UnkStruct_003D5D00_data {
    UnkStruct_Gt2dObjectText_font *field_0;
    unsigned char pad_4[0x4];
    float field_8;             // [G] shadow x stretch
    float field_C;             // [G] glow alpha
    float field_10;            // [G] glow scale
};
// [G] one batch entry: two CGtV2d (16-byte stride)
struct UnkStruct_003D5D00_ent {
    CGtV2d field_0;
    CGtV2d field_8;
};

extern "C" int _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" void func_00217E70(int);   // [L] E map: Gt2dRenderer::SetBlendMode(EGt2dRendererBlend) (symbol_addrs_b3names.txt)

// [L] N185: stands in for a missing GtMathPs2 inline: a zero vector with w taken from another vector's w lane
// (`vsub.xyzw d,$vf0,$vf0; vmulw.w d,$vf0,cw`).
static inline CGtV4d v294_zerow(const CGtV4d &c)
{
    u_long128 r;
    asm("vsub.xyzw %0, $vf0, $vf0" : "=j"(r));
    asm("vmulw.w %0, $vf0, %1w" : "+j"(r) : "j"(c.mData));
    return CGtV4d(r);
}
// [G] N140 frame pad (retail's frame has two more 16-byte slots below the shadow colour)
struct UnkStruct_003D5D00_pad { int x[4]; UnkStruct_003D5D00_pad() {} ~UnkStruct_003D5D00_pad() {} };

// 0x003D5D00
extern "C" void _Render__16CB3Score2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_003D5D00_data *d = (const UnkStruct_003D5D00_data *)data;
    int n = _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(space, data);
    if (n == 0) {
        return;
    }
    {
        CGtV2d *batch = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
        CGtV2d *uvs = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
        CGtV4d shadow = v294_zerow(space.mColour);
        UnkStruct_003D5D00_pad pad1;
        UnkStruct_003D5D00_pad pad2;
        UnkStruct_003D5D00_pad pad3;
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        CGtV2d off(d->field_8 * (0.0625f * space.mSize.marValues[0]), 0.0625f * space.mSize.marValues[1]);
        Gt2dRenderer::RenderSpritesTex(shadow, off, n, batch, uvs);
        Gt2dRenderer::RenderSpritesTex(shadow, -off, n, batch, uvs);
        off.SetX(-off.X());
        Gt2dRenderer::RenderSpritesTex(shadow, off, n, batch, uvs);
        Gt2dRenderer::RenderSpritesTex(shadow, -off, n, batch, uvs);
        off.Set(0.0f, 0.0f);
        Gt2dRenderer::RenderSpritesTex(space.mColour, off, n, batch, uvs);
        CGtV2d centre = space.mTopLeftPos + space.mSize * 0.5f;
        UnkStruct_003D5D00_ent *e = (UnkStruct_003D5D00_ent *)batch;
        for (int i = 0; i < n; i++) {
            e->field_0 = centre + (e->field_0 - centre) * d->field_10;
            e->field_8 = centre + (e->field_8 - centre) * d->field_10;
            e++;
        }
        shadow = CGtV4d(1.0f, 1.0f, 1.0f, d->field_C * (float)shadow.W());  // [C] retail FPU form, not a VU lane op: 0x3D5FE4 lwc1 / 0x3D5FE8 mul.s (the cast keeps the port's PS2 float model)
        func_00217E70(1);
        Gt2dRenderer::RenderSpritesTex(shadow, off, n, batch, uvs);
        func_00217E70(0);
    }
}
