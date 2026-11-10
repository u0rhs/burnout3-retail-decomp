// NONMATCHING: func_00456780 -- retail 75 / ours 75 instructions, 13 in changed runs
// a117: 75/75 instrs, 14 changed; logic right (9-arg component Prepare, loop of ConstructObject + CGt2dObjectImage::Prepare); remaining: stack-arg sd zero hoisted above the lw t1 in ours, i*8 temp t3 vs a0, s0/s1 swap (slot ptr vs i*4) | mwperm: 14 -> 13 (+'// N182: `#pragma opt_propagation off` ([G] scoped to this function; found by mw'; +'const CGtV2d * v1 = uv0; CGt2dFrame * root; const CGtV2d * v0; const int * v2 = '; +'v0 = size;'; +'int i;'; 'CGt2dFrame * root = scene->field_14; for (int i = 0; i < sel' -> 'root = scene->field_14; i = 0; goto loop0_t; loop0: CGt2dObject ** slot = &self-')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_01EA4070 {
    unsigned char pad_0[0x400];
    CGtTexture * field_400[1];
    unsigned char pad_404[0x10];
};
struct UnkStruct_00456780 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C[4];
    int field_1C;
};

extern CGt2dScene D_01E903E0;
extern UnkStruct_D_01EA4070 D_01EA4070;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// N182: `#pragma opt_propagation off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_propagation off
extern "C" int func_00456780(UnkStruct_00456780 * self, const int * tex, const CGtV2d * pos, const CGtV2d * anchor,
                             const CGtV2d * size, const CGtV4d * colour, const CGtV2d * uv0, const CGtV2d * uv1, int count)
{
    const CGtV2d * v1 = uv0;
    CGt2dFrame * root;
    const CGtV2d * v0;
    const int * v2 = tex;
    Prepare__20CB3MenuComponentBaseFv(self);
    v0 = size;
    CGt2dScene * const scene = &D_01E903E0;
    int i;
    self->field_1C = count;
    root = scene->field_14;
    i = 0;
    goto loop0_t;
loop0:
    CGt2dObject ** slot = &self->field_C[i];
    *slot = scene->ConstructObject(self->field_8, root);
    CGtTexture * t0 = D_01EA4070.field_400[v2[i]];
    CGt2dObjectImage_Prepare(*slot, pos[i], anchor[i], size[i], colour[i], t0, v1[i], uv1[i], 0);
    i = (int)((unsigned int)i + (unsigned int)1);
loop0_t:
    if (!(i < self->field_1C)) {
    } else {
        goto loop0;
    }
    return 1;
}
