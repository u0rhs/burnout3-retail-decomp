// NONMATCHING: func_00458AE0 -- retail 666 / ours 657 instructions, 502 in changed runs
// draftAK C-first: [L] a HUD icon _Render callback (installed by the matched func_004589B0): per-flag time curves (pop-in glow, cos squash, bounce, pulse, rising label, strike shrink-in, fade-out), icon / additive glow / HUD_Strikeout sprites, then the number (or 1/2) label as font glyph sprites with a 4-way black outline; 657/666, calls identical, float op counts equal (CGtV2d product operators keep retail's unfused mul/add); left: frame 0x330 vs 0x4A0 (CGtV2d temporaries), block order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every curve constant (ELF .lit4 bits), branch, sprite argument and glyph store traced; retail reads q[-1] (before the batch buffer) when the label emits no glyph -- kept

// func_00458AE0 -- draftAK (C-first draft). 0x458AE0, 0xA68. Unnamed in every table, so the asm label with C linkage.
// [C] a CGt2dObject render callback (installed by the matched func_004589B0: (const CGt2dObjectSpace&, const void*)); data at
// the object's +0x20: field_0 texture, field_4 number (or -1), field_8 time, field_C effect flags, field_D bit 0 "strike".
// What it does [L]: an animated HUD icon: per effect flag a time-driven scale / alpha curve (1 pop-in with an additive glow
// copy, 2 squash by cos, 4 bounce, 8 pulse, 0x10 a rising "x/y" label, 0x20 shrink-in of the strike icon, 0x40 fade-out);
// draws the icon, the additive glow, the "HUD_Strikeout" texture over it when field_D bit 0 is set, and the label (the
// number, or "1/2" for -1) as glyph sprites from the HUD font with a 4-way black outline.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;

struct UnkStruct_00458AE0_d {               // the object's data block (as func_004589B0 fills it)
    CGtTexture *field_0;
    int field_4;
    float field_8;
    unsigned char field_C;
    unsigned char field_D;
};
struct UnkStruct_00458AE0_blk { unsigned char pad_0[0x18]; char field_18[1]; };   // [G] the texture name (+0x90 +0x18)
struct UnkStruct_00458AE0_ent { unsigned char pad_0[0x8]; CGtTexture *field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_00458AE0_dic { unsigned char pad_0[0x8]; int field_8; UnkStruct_00458AE0_ent *field_C; };
struct UnkStruct_D_00518688 { UnkStruct_00458AE0_dic *field_0; unsigned char pad_4[0xC]; };   // [G] texture dictionary
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; };
extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern const char D_004D3590[];             // [C] "HUD_Strikeout"
extern "C" int strcasecmp(const char *, const char *);
extern "C" float cosf(float);
extern "C" void PrintUInt__10CGtUnicodeFPUsUii(unsigned short *, unsigned int, int);
extern "C" void func_00217E70(int);         // [L] the 2D blend mode (0 normal, 1 additive)

// [L] find-by-name in the texture dictionary (as B3HUDComponent_0019F790.cpp's inline).
static inline CGtTexture *func_00458AE0_inl1(UnkStruct_00458AE0_dic *t0, const char *name)
{
    for (int i = 0; i < t0->field_8; i++) {
        CGtTexture *t = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00458AE0_blk *)((char *)t + 0x90))->field_18, name) == 0)
            return t;
    }
    return 0;
}

extern "C" void func_00458AE0(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData)
{
    const UnkStruct_00458AE0_d *d = (const UnkStruct_00458AE0_d *)lpData;
    unsigned char flags = d->field_C;
    float t = d->field_8;
    bool glow = false;                      // s2
    bool label = false;                     // s6
    bool strike = (d->field_D & 1) != 0;    // s0
    float scale = 1.0f;                     // f22, never changed
    float labelAlpha = scale;               // f21
    CGtV4d iconCol = space.mColour;         // 0x2F0
    CGtV4d strikeCol = space.mColour;       // 0x2D0
    CGtV4d glowCol = space.mColour;         // 0x2E0
    CGtV2d half = space.mSize * 0.5f;
    CGtV2d centre = half;                   // 0x498
    CGtV2d iconHalf = half;                 // 0x490
    CGtV2d strikeHalf = half;               // 0x480
    CGtV2d glowHalf = half;                 // 0x488
    CGtV2d labelOff = half;                 // 0x478

    if ((flags & 1) && t < 0.5f) {
        float k = 2.0f * t;
        float g = scale + k;
        glow = true;
        glowHalf.SetY(glowHalf.Y() * g);
        glowHalf.SetX(glowHalf.X() * g);
        glowCol.SetW(glowCol.W() * (scale - k) * scale);
    }
    if ((flags & 2) && t < 0.75f) {
        float u = 0.0f + 1.0f - 1.3333334f * t;
        u = u * u;
        u = u * u;
        iconHalf.SetX(cosf(15.707964f * u) * iconHalf.X());
    }
    if ((flags & 4) && t < 0.6f) {
        float v = 0.0f + 1.0f - 1.6666666f * t;
        float c = cosf(9.424778f * v);
        float s = 0.0f + 1.0f + 0.8f * (c * (v * v));
        iconHalf.SetX(iconHalf.X() * s);
        iconHalf.SetY(iconHalf.Y() * s);
        if (t < 0.2f)
            iconCol.SetW(iconCol.W() * (5.0f * t));
    }
    if ((flags & 8) && t < 0.5f) {
        float w = 4.0f * t - 1.0f;
        w = w * w;
        w = 1.0f - w;
        w = w * w;
        float s = 1.0f + 0.5f * w;
        iconHalf.SetX(iconHalf.X() * s);
        iconHalf.SetY(iconHalf.Y() * s);
    }
    if ((flags & 0x10) && d->field_4 != 0 && t < 1.0f) {
        float tt = t * t;
        label = true;
        labelAlpha = 1.0f - tt;
        labelOff.SetY(labelOff.Y() + space.mSize.Y() * (0.0f + -0.3f + tt * -0.99999994f));
    }
    if ((flags & 0x20) && t < 0.4f) {
        float m = 3.0f * (2.5f * t);
        float q = 4.0f - m;
        strikeHalf.SetX(strikeHalf.X() * q);
        strikeHalf.SetY(strikeHalf.Y() * q);
        if (t < 0.3f)
            strikeCol.SetW(strikeCol.W() * (3.3333333f * t));
    }
    if (flags & 0x40) {
        if (t < 1.0f) {
            float r = 1.0f - t;
            iconCol.SetW(iconCol.W() * r);
            strikeCol.SetW(strikeCol.W() * r);
        } else {
            iconCol.SetA(0.0f);
            strike = false;
        }
    }

    CGtV2d uv[2];
    CGtV2d pos[2];
    uv[0].Set(0.0f, 0.0f);
    uv[1].Set(1.0f, 1.0f);
    CGtV2d hi = centre + iconHalf;
    pos[0] = centre - iconHalf;
    pos[1] = hi;
    Gt2dRenderer::SetTexture(d->field_0);
    if (iconCol.W() > 0.0f)
        Gt2dRenderer::RenderSpritesTex(iconCol, space.mTopLeftPos, 1, pos, uv);
    if (glow) {
        hi = centre + glowHalf;
        pos[0] = centre - glowHalf;
        pos[1] = hi;
        func_00217E70(1);
        Gt2dRenderer::RenderSpritesTex(glowCol, space.mTopLeftPos, 1, pos, uv);
        func_00217E70(0);
    }
    if (strike) {
        CGtTexture *tex = func_00458AE0_inl1(D_00518688.field_0, D_004D3590);
        hi = centre + strikeHalf;
        pos[0] = centre - strikeHalf;
        pos[1] = hi;
        Gt2dRenderer::SetTexture(tex);
        Gt2dRenderer::RenderSpritesTex(strikeCol, space.mTopLeftPos, 1, pos, uv);
    }

    if (label) {
        CGt2dFont *font = D_00665ED0.pFont;
        CGtV2d *uvs = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
        CGtV2d *quads = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
        CGtV2d *q = quads;
        CGtV2d *u = uvs;
        unsigned short str[4];
        if (d->field_4 == -1) {
            str[0] = '1';
            str[1] = '/';
            str[2] = '2';
            str[3] = 0;
        } else {
            PrintUInt__10CGtUnicodeFPUsUii(str, d->field_4, 1);
        }
        CGtV2d fontScale = font->field_8;
        CGtV2d glyphSize = CGtV2d(space.mSize.X() * fontScale.X(), space.mSize.Y() * fontScale.Y()) * (0.7f * scale);
        CGtV2d cursor(0.0f, 0.0f);
        int n = 0;
        const unsigned short *s = str;
        UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
        for (;;) {
            if (!(g->field_0.X() < 0.0f)) {
                n++;
                CGtV2d p = cursor + g->field_10 * glyphSize;
                q[0] = p;
                u[0] = g->field_0;
                q[1] = p + glyphSize * g->field_8;
                u[1] = g->field_0 + g->field_8;
                q += 2;
                u += 2;
            }
            s++;
            if (*s == 0)
                break;
            cursor.SetX(0.0f + cursor.X() + g->field_18 * glyphSize.X());
            g = font->UnkInline_FindGlyph(*s);
        }

        CGtV4d textCol = space.mColour;
        textCol.SetW(textCol.W() * labelAlpha);
        CGtV4d shadowCol;
        shadowCol.Zero();
        shadowCol.SetW(space.mColour.W() * labelAlpha);
        CGtV2d o = space.mTopLeftPos + labelOff;
        CGtV2d textPos;
        textPos.SetY(0.35f * scale * space.mSize.Y());
        textPos.SetX(0.5f * (quads[0].X() + q[-1].X()));    // [C] first quad's left, last quad's right
        textPos = o - textPos;
        CGtV2d off(space.mSize.X() * 0.035f, space.mSize.Y() * 0.035f);
        Gt2dRenderer::SetTexture(font->field_4);
        for (int i = 0; i < 4; i++) {
            CGtV2d at = textPos + off;
            Gt2dRenderer::RenderSpritesTex(shadowCol, at, n, quads, uvs);
            if (i & 1)
                off.SetX(-off.X());
            else
                off.SetY(-off.Y());
        }
        Gt2dRenderer::RenderSpritesTex(textCol, textPos, n, quads, uvs);
    }
}
