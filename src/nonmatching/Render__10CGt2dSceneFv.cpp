// NONMATCHING: Render__10CGt2dSceneFv -- retail 201 / ours 198 instructions, 120 in changed runs
// retail 201 / ours 198 instrs, ~120 in changed runs: structure believed right (layer loop with entry jump, blend/filter/address switch on props^prev, clip region min/max, per-object space = frame.pos+frame.scale*pos, size*scale, min(colour*frame colour, white) via vmini asm, indirect mpfRender); left: saved-register assignment (retail s0=layer,s1=count,s2=diff,s3=link,s4=clip,s5=prev), the sltu/xori hide flag, clip-region load order, delay-slot lw s5. vmini has no GtMathPs2 helper (UnkMin4 asm here)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dSceneFrame {
    unsigned char pad_0[0x20];
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV4d field_30;
};
extern "C" void func_001D4780(CGt2dScene *);
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void End__12Gt2dRendererFv();
extern "C" void func_00217E70(int);
extern "C" void SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(int);
extern "C" void SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(int);
extern "C" void SetClipRegion__12Gt2dRendererFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(const CGtV2d&, const CGtV2d&);
extern "C" void ResetClipRegion__12Gt2dRendererFv();

static inline CGtV4d UnkMin4(const CGtV4d a, const CGtV4d b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}

void CGt2dScene::Render()
{
    int n = field_30;
    func_001D4780(this);
    unsigned int prev = 0x40;
    Begin__12Gt2dRendererFv();
    UnkStruct_Gt2dSceneFrame * clip = 0;
    UnkStruct_Gt2dScene_2C * layer = field_2c;
    goto test;
body:
    {
        unsigned int props = layer->field_0;
        bool hide = true;
        if (!(props & 1) && layer->field_4.field_4)
            hide = false;
        bool show = !hide;
        if (show == false)
            goto next;
        unsigned int diff = props ^ prev;
        if (diff & 0x66) {
            switch (props & 0x26) {
            case 2:
                func_00217E70(1);
                break;
            case 4:
                func_00217E70(2);
                break;
            case 0x20:
                func_00217E70(3);
                break;
            default:
                func_00217E70(0);
                break;
            }
        }
        if (diff & 0x48) {
            if (layer->field_0 & 8)
                SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(1);
            else
                SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(0);
        }
        if (diff & 0x50) {
            if (layer->field_0 & 0x10)
                SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(1);
            else
                SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(0);
        }
        UnkStruct_Gt2dSceneFrame * f = (UnkStruct_Gt2dSceneFrame *)layer->field_c;
        if (f != clip) {
            prev = layer->field_0;
            if (f) {
                CGtV2d sum = f->field_20 + f->field_28;
                CGtV2d lo(GtMath::Min(f->field_20.marValues[0], sum.marValues[0]), GtMath::Min(f->field_20.marValues[1], sum.marValues[1]));
                UnkStruct_Gt2dSceneFrame * g = (UnkStruct_Gt2dSceneFrame *)layer->field_c;
                CGtV2d hi(GtMath::Max(g->field_20.marValues[0], sum.marValues[0]), GtMath::Max(g->field_20.marValues[1], sum.marValues[1]));
                SetClipRegion__12Gt2dRendererFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(lo, hi);
            } else {
                ResetClipRegion__12Gt2dRendererFv();
            }
        } else {
            prev = layer->field_0;
        }
        CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
        CGtFreeListLink * link = layer->field_4.field_4;
        clip = (UnkStruct_Gt2dSceneFrame *)layer->field_c;
        while (link) {
            CGt2dObject * o = (CGt2dObject *)(link + 1);
            UnkStruct_Gt2dSceneFrame * fr = (UnkStruct_Gt2dSceneFrame *)o->mpFrame;
            CGt2dObject::CGt2dObjectSpace sp;
            sp.mTopLeftPos = fr->field_20 + fr->field_28 * o->mObjectSpace.mTopLeftPos;
            sp.mSize = o->mObjectSpace.mSize * fr->field_28;
            sp.mColour = UnkMin4(o->mObjectSpace.mColour * fr->field_30, white);
            o->mpfRender(sp, o->mauDataBlock);
            link = link->field_0;
        }
    }
next:
    layer++;
test:
    if (n-- != 0)
        goto body;
    End__12Gt2dRendererFv();
}
