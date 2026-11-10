// NONMATCHING: func_00380A50 -- retail 302 / ours 302 instructions, 18 in changed runs
// v304: 302/302 instrs, 18 changed: s0/s1 swapped (&verts[0].y vs &verts[1]) and frame 0x1B0 vs 0x190 -- the explicit guard form of the 4 function-local statics (sA = kA * size) leaves one dead return-copy slot each; a real local static gives retail's frame but goes $gp/.sbss; placement new adds a null test. Sprite 3's two dead r-stores reproduced by overwritten verts[0]/verts[1] assignments.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00380A50 -- [L] DNAT: CB3DPad2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*)
// (research/proto/new_names.csv, medium); installed by Prepare__15CB3DPad2dObject (func_00380F10).
// Placeholder with C linkage (the asm label); file and Area not evidenced, so _unclassified/.
// [L] D_004C9430..D_004C9450 are function-local statics (guard bytes D_004E2E64..74: lb guard; beqz init;
// sb 1), written out here as explicit guard tests on the retail objects [G]. D_004C9410..28 and the
// D_004C93B0..E0 UV pairs are file-scope objects built by the static initialiser (sinit 0x4D9890).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [G] the button-state block at CGt2dObject +0x20 (Prepare__15CB3DPad2dObject writes 0/1 per button).
struct UnkStruct_00380A50_d {
    char field_0;
    char field_1;
    char field_2;
    char field_3;
};

struct UnkStruct_D_01EA46E4 {
    CGtTexture * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] declared without a size so the references stay absolute (lui/lo), as retail's are.
extern CGtV2d D_004C9410[];
extern CGtV2d D_004C9418[];
extern CGtV2d D_004C9420[];
extern CGtV2d D_004C9428[];
extern CGtV2d D_004C9430[];
extern CGtV2d D_004C9438[];
extern CGtV2d D_004C9440[];
extern CGtV2d D_004C9448[];
extern CGtV2d D_004C9450[];
#define kC D_004C9410[0]
#define kD D_004C9418[0]
#define kA D_004C9420[0]
#define kB D_004C9428[0]
#define sA D_004C9430[0]
#define sB D_004C9438[0]
#define sC D_004C9440[0]
#define sD D_004C9448[0]
#define sE D_004C9450[0]


extern UnkStruct_D_01EA46E4 D_01EA46E4;
extern CB3MenuPageManager D_01E90240;
extern CGtV2d D_004C93B0[2];
extern CGtV2d D_004C93C0[2];
extern CGtV2d D_004C93D0[2];
extern CGtV2d D_004C93E0[2];
extern char D_004E2E64;
extern char D_004E2E68;
extern char D_004E2E6C;
extern char D_004E2E70;
extern char D_004E2E74;

// 0x00380A50
extern "C" void func_00380A50(const CGt2dObject::CGt2dObjectSpace & s, const void * p)
{
    CB3MenuPageManager * mgr = &D_01E90240;
    const UnkStruct_00380A50_d * d = (const UnkStruct_00380A50_d *)p;
    if (!D_004E2E64) { sA = kA * s.mSize; D_004E2E64 = 1; }
    if (!D_004E2E68) { sB = kB * s.mSize; D_004E2E68 = 1; }
    if (!D_004E2E6C) { sC = kC * s.mSize; D_004E2E6C = 1; }
    if (!D_004E2E70) { sD = kD * s.mSize; D_004E2E70 = 1; }
    if (!D_004E2E74) { sE.Set(0.0f, 0.0f); D_004E2E74 = 1; }
    CGtV4d cols[2];
    CGtV2d verts[8];
    cols[0] = (&mgr->field_D0)[1] * s.mColour;
    cols[1] = mgr->field_D0 * s.mColour;
    for (int i = 0; i < 8; i++) {
        verts[i] = s.mTopLeftPos + CGtV2d(sB.X(), 0.0f);
        verts[1] = verts[0] + sD;
    }
    Gt2dRenderer::SetTexture(D_01EA46E4.field_0);
    verts[0] = CGtV2d(sB.X(), 0.0f);
    verts[1] = verts[0] + sD;
    Gt2dRenderer::RenderSpritesTex(cols[d->field_0], s.mTopLeftPos, 1, verts, D_004C93D0);
    verts[0] = sB;
    verts[1] = verts[0] + sD;
    Gt2dRenderer::RenderSpritesTex(cols[d->field_1], s.mTopLeftPos, 1, verts, D_004C93E0);
    verts[0] = s.mTopLeftPos + CGtV2d(0.0f, sA.X());
    verts[1] = s.mTopLeftPos + kC * s.mSize;
    verts[0] = CGtV2d(0.0f, sA.Y());
    verts[1] = verts[0] + sC;
    Gt2dRenderer::RenderSpritesTex(cols[d->field_2], s.mTopLeftPos, 1, verts, D_004C93C0);
    verts[0] = sA;
    verts[1] = verts[0] + sC;
    Gt2dRenderer::RenderSpritesTex(cols[d->field_3], s.mTopLeftPos, 1, verts, D_004C93B0);

}

