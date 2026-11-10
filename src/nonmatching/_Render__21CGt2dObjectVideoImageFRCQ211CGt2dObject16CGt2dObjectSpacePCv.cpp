// NONMATCHING: _Render__21CGt2dObjectVideoImageFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 227 / ours 227 instructions, 175 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a148: logic and control flow right, 227 vs 227 instrs but 175 in changed runs (frame 0x170 vs retail 0x180, scheduling/registers of the V2d temp chain). Structure: data=(uv step V2d@0, V2d@8, decoder@0x10, flag@0x14); flag!=0 does an extra RenderSpritesUntex pass (own ucorners[2]+zero temp) before t
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
struct UnkStruct_vi_img { unsigned char pad_0[0x4]; int field_4; int field_8; };
struct UnkStruct_vi_data { CGtV2d field_0; CGtV2d field_8; void *field_10; unsigned char field_14; };
struct UnkStruct_TC { unsigned char pad_0[0x10]; };
extern UnkStruct_TC gTextureCache;
extern "C" UnkStruct_vi_img *GetImage__15CGtVideoDecoderFv(void *);
extern "C" void SetZ__12Gt2dRendererFfff(float, float, float);
extern "C" void EnableZTest__12Gt2dRendererFb(bool);
extern "C" int func_00221420(void *, int, void *);
extern "C" void Suspend__12Gt2dRendererFv();
extern "C" void Resume__12Gt2dRendererFv();
extern "C" void SetTileTexture__13CGtVideoImageFii(void *, int, int);

static inline CGtV2d MinV(const CGtV2d & a, float s)
{
    CGtV2d r;
    r.marValues[0] = GtMath::Min(a.marValues[0], s);
    r.marValues[1] = GtMath::Min(a.marValues[1], s);
    return r;
}

extern "C" void _Render__21CGt2dObjectVideoImageFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace & space, const void * pdata)
{
    const UnkStruct_vi_data * data = (const UnkStruct_vi_data *)pdata;
    UnkStruct_vi_img * img = GetImage__15CGtVideoDecoderFv(data->field_10);
    if (img == 0) {
        return;
    }
    CGtV2d uvs[2];
    CGtV2d corners[2];
    uvs[0].Set(0.0f, 0.0f);
    int zi = 10000;
    SetZ__12Gt2dRendererFfff(0.1f, 0.1f, (float)zi);
    EnableZTest__12Gt2dRendererFb(true);
    func_00221420(&gTextureCache, 1, 0);
    if (data->field_14 != 0) {
        CGtV2d ucorners[2];
        CGtV2d e = data->field_8 * space.mSize;
        ucorners[0] = space.mTopLeftPos - e;
        CGtV2d f = space.mTopLeftPos + space.mSize;
        CGtV2d h = f + e;
        ucorners[1] = h;
        Gt2dRenderer::RenderSpritesUntex(space.mColour, CGtV2d(0.0f, 0.0f), 1, ucorners);
    }
    CGtV2d q = space.mSize / data->field_0;
    float one = 1.0f;
    for (int y = 0; y < img->field_8; y++) {
        for (int x = 0; x < img->field_4; x++) {
            CGtV2d d = data->field_0 - CGtV2d((float)x, (float)y);
            CGtV2d m = MinV(d, one);
            CGtV2d off = q * CGtV2d((float)x, (float)y);
            CGtV2d sz = q * m;
            CGtV2d uv1 = CGtV2d(1.0f, 1.0f) * m;
            corners[0] = space.mTopLeftPos + off;
            CGtV2d p1 = corners[0] + sz;
            corners[1] = p1;
            uvs[1] = uv1;
            Suspend__12Gt2dRendererFv();
            SetTileTexture__13CGtVideoImageFii(img, x, y);
            Resume__12Gt2dRendererFv();
            Gt2dRenderer::RenderSpritesTex(space.mColour, CGtV2d(0.0f, 0.0f), 1, corners, uvs);
        }
    }
    SetZ__12Gt2dRendererFfff(0.1f, 0.1f, (float)zi);
    EnableZTest__12Gt2dRendererFb(false);
    func_00221420(&gTextureCache, 0, 0);
}
