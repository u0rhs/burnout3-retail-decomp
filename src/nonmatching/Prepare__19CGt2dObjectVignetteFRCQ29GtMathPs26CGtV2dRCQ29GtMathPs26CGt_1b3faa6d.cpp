// NONMATCHING: Prepare__19CGt2dObjectVignetteFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4dQ219CGt2dObjectVignette13EVignetteType -- retail 118 / ours 98 instructions, 158 in changed runs
// draftAO (2026-11-01): reviewed complete: the lane-to-byte conversions are retail's (lanes x,y,z,w of c*255 truncated to bytes +0x20..+0x23 / +0x24..+0x27 [C] 0x1D7410..0x1D7534; retail routes them through a 4-byte stack temp at sp+0x19C/0x198, same values); flow pos - size*anchor, white, mgapfRenderFunctions[type], 0x40, 8 checked; audit quiet | Before: retail 118 / ours 116 instrs, frame 416 vs 448: the lane reads (Y has no operator float; retail stores the in-register c*255 with sqc2 to three slots then lwc1) and the RGBA conversion are unmodelled; flow (pos - size*anchor, white CGtV4d, mgapfRenderFunctions[type], 0x40, 8) believed right
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: call identical, every byte store and argument traced


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

class CGt2dObjectVignette : public CGt2dObject {
public:
    static void _RenderVertical(const CGt2dObject::CGt2dObjectSpace&, const void*);
    static void _RenderHorizontal(const CGt2dObject::CGt2dObjectSpace&, const void*);
};
struct UnkStruct_Vignette_fn {
    CGt2dObject::UnkFn_RenderCallback field_0[4];
};
extern "C" UnkStruct_Vignette_fn mgapfRenderFunctions__19CGt2dObjectVignette;

extern "C" void Prepare__19CGt2dObjectVignetteFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4dQ219CGt2dObjectVignette13EVignetteType(
    CGt2dObjectVignette * self, const CGtV2d& pos, const CGtV2d& anchor, const CGtV2d& size, const CGtV4d c1,
    const CGtV4d c2, void *type_)
{
    unsigned int type = (unsigned int)type_;
    unsigned char * d = (unsigned char *)self->mauDataBlock;
    CGtV4d s1 = c1 * 255.0f;
    CGtV4d s2 = c2 * 255.0f;
    unsigned char r1 = (int)(float)s1.X();
    unsigned char g1 = (int)s1.f[1];
    unsigned char b1 = (int)(float)s1.Z();
    unsigned char a1 = (int)(float)s1.W();
    d[0] = r1;
    d[1] = g1;
    d[2] = b1;
    d[3] = a1;
    unsigned char r2 = (int)(float)s2.X();
    unsigned char g2 = (int)s2.f[1];
    unsigned char b2 = (int)(float)s2.Z();
    d[4] = r2;
    d[5] = g2;
    d[6] = b2;
    d[7] = (int)(float)s2.W();
    self->CGt2dObject::Prepare(pos - size * anchor, size, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f),
                               mgapfRenderFunctions__19CGt2dObjectVignette.field_0[type], 0x40, 8);
}
