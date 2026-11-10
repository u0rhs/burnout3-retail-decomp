// NONMATCHING: func_0019DD00 -- retail 661 / ours 615 instructions, 747 in changed runs
// draftAK C-first: [L] the loading-screen draw (a CB3GraphicsManager member that addresses the global D_00665EC0 itself; called by CB3LoadingScreenPage::Update): camera clear, four centred text lines (static CGtV2d positions and screen scale with guards D_004E26C0..D0), bar frame + black inset, two progress gradient strips up to the remembered progress (static D_004E26BC), four gradient rules, RwCameraEndUpdate, progress creep +0.01 below 0.75; 615/661, calls identical, no extra fused ops; left: retail reloads every static's address (lui per use) and reloads D_004E157C/D_004E1580 per use (4 more mul.s), frame 0x210 vs 0x200
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every colour constant, coordinate, strip vertex/colour order and call argument traced; retail never reads its a0 (kept as an unused self parameter for call identity)

// func_0019DD00 -- draftAK (C-first draft). 0x19DD00, 0xA54. Unnamed in every table, so the asm label with C linkage.
// [C] called by CB3LoadingScreenPage::Update with a0 = &D_00665EC0 (the graphics manager) and f12 = the progress; the body
// never reads a0 (it addresses D_00665EC0 itself), so [L] a CB3GraphicsManager member that uses the global instance.
// What it does [L]: draws the loading screen: clear, four centred text lines (static CGtV2d positions, scaled by a static
// screen scale (1, 0.9)), a bar frame (light then black inset), the progress bar as two gradient strips up to the
// remembered progress (static D_004E26BC, only raised by a positive argument, creeping +0.01 per call while below 0.75),
// and four horizontal gradient rules; then ends the camera update and drops the current viewport/camera globals.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; };
struct UnkStruct_D_00666228 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00666270_cam { unsigned char pad_0[0x58]; int field_58; };
struct UnkStruct_D_00665EC0;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_00666228 D_00666228;
extern UnkStruct_D_00666270_cam *D_00666270;   // [G] current camera
extern int D_00666274;
extern unsigned char D_0051A6A2;
extern unsigned char D_01E65489;
extern unsigned char D_004F50C0[];
extern unsigned short D_004B72D8[];         // [G] the four text lines (filled elsewhere)
extern unsigned short D_004B72E0[];
extern unsigned short D_004B72F0[];
extern unsigned short D_004B72F8[];
extern float D_004E0B70;                    // [L] variables, not literals (gp loads of 423.75 / 205.0 / 260.0: low half zero)
extern float D_004E157C;
extern float D_004E1580;
extern "C" void func_00214050(void *);
extern "C" void func_001E1FF0(int, void *, int);   // [L] the camera clear (camera, colour, mode 3)
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void RwCameraEndUpdate(int);

static float D_004E26BC;                    // [C] .sbss: the remembered progress

extern "C" void func_0019DD00(void *self, float progress)
{
    CGtV4d half(0.5f, 0.5f, 0.5f, 1.0f);
    CGtV2d zero(0.0f, 0.0f);
    static CGtV2d sScale(1.0f, 0.9f);       // D_004B7300 (guard D_004E26C0)
    static CGtV2d sLine1(320.0f, 160.0f);   // D_004B7308 (D_004E26C4)
    static CGtV2d sLine2(320.0f, 210.0f);   // D_004B7310 (D_004E26C8)
    static CGtV2d sLine3(320.0f, 260.0f);   // D_004B7318 (D_004E26CC)
    static CGtV2d sLine4(320.0f, 310.0f);   // D_004B7320 (D_004E26D0)
    if (!(progress <= 0.0f))
        D_004E26BC = progress;

    if (D_0051A6A2 != 0 && D_01E65489 == 0)
        func_00214050(D_004F50C0);
    char clear[4] = {0};
    func_001E1FF0(D_00666228.field_0, clear, 3);
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, 0);
    Gt2dRenderer::Begin();

    CGtV4d textCol = CGtV4d(0.36f, 0.6f, 0.75f, 1.0f) * half;
    float textScale = 40.0f * sScale.Y();
    if (D_004B72D8[0] != 0) {
        float w;
        float hw;
        w = D_00665ED0.pFont->GetStringWidth(D_004B72D8);
        hw = textScale * w;
        hw *= 0.5f;                         // [C] split so the centring stays mul.s + sub.s as retail (one expression fuses to msub)
        D_00665ED0.pFont->RenderString(D_004B72D8, (320.0f - hw) * sScale.X(), sLine1.Y() * sScale.Y(),
                                       textScale, textCol);
    }
    if (D_004B72E0[0] != 0) {
        float w;
        float hw;
        w = D_00665ED0.pFont->GetStringWidth(D_004B72E0);
        hw = textScale * w;
        hw *= 0.5f;                         // [C] split so the centring stays mul.s + sub.s as retail (one expression fuses to msub)
        D_00665ED0.pFont->RenderString(D_004B72E0, (320.0f - hw) * sScale.X(), sLine2.Y() * sScale.Y(),
                                       textScale, textCol);
    }
    if (D_004B72F0[0] != 0) {
        float w;
        float hw;
        w = D_00665ED0.pFont->GetStringWidth(D_004B72F0);
        hw = textScale * w;
        hw *= 0.5f;                         // [C] split so the centring stays mul.s + sub.s as retail (one expression fuses to msub)
        D_00665ED0.pFont->RenderString(D_004B72F0, (320.0f - hw) * sScale.X(), sLine3.Y() * sScale.Y(),
                                       textScale, textCol);
    }
    if (D_004B72F8[0] != 0) {
        float w;
        float hw;
        w = D_00665ED0.pFont->GetStringWidth(D_004B72F8);
        hw = textScale * w;
        hw *= 0.5f;                         // [C] split so the centring stays mul.s + sub.s as retail (one expression fuses to msub)
        D_00665ED0.pFont->RenderString(D_004B72F8, (320.0f - hw) * sScale.X(), sLine4.Y() * sScale.Y(),
                                       textScale, textCol);
    }

    CGtV2d pts[4];
    float x0 = 0.0f;                        // [C] retail multiplies 0.0 by the scale at run time
    CGtV4d cols[4];
    int barBottom = 435;                    // [C] retail converts it at run time (li 0x1B3; cvt.s.w)
    cols[0] = CGtV4d(0.62f, 0.769f, 0.969f, 1.0f) * half;
    pts[0].SetX(240.0f * sScale.X());
    pts[1].SetX(400.0f * sScale.X());
    pts[0].SetY(420.0f * sScale.Y());
    pts[1].SetY((float)barBottom * sScale.Y());
    Gt2dRenderer::RenderSpritesUntex(cols[0], zero, 1, pts);
    cols[0] = CGtV4d(0.0f, 0.0f, 0.0f, 1.0f);
    float px = 1.0f / sScale.X();
    float py = 1.0f / sScale.Y();
    pts[0].SetX((240.0f + px) * sScale.X());
    pts[1].SetX((400.0f - px) * sScale.X());
    pts[0].SetY((420.0f + py) * sScale.Y());
    pts[1].SetY(((float)barBottom - py) * sScale.Y());
    Gt2dRenderer::RenderSpritesUntex(cols[0], zero, 1, pts);

    CGtV4d colA = CGtV4d(0.0f, 0.0f, 0.1f, 1.0f) * half;
    CGtV4d colB = CGtV4d(0.36f, 0.6f, 0.75f, 1.0f) * half;
    cols[0] = colA;
    cols[1] = colB;
    cols[2] = colA;
    cols[3] = colB;
    float left = 240.0f + 2.0f / sScale.X();
    float width = 160.0f - 4.0f / sScale.X();
    pts[0].SetY((420.0f + 2.0f / sScale.Y()) * sScale.Y());
    pts[2].SetY(pts[0].Y());
    pts[0].SetX(left * sScale.X());
    pts[1].SetX(pts[0].X());
    pts[2].SetX((0.0f + left + D_004E26BC * width) * sScale.X());
    pts[3].SetX(pts[2].X());
    pts[1].SetY(D_004E0B70 * sScale.Y());
    pts[3].SetY(pts[1].Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, cols);

    cols[0] = colB;
    cols[1] = colA;
    cols[2] = colB;
    cols[3] = colA;
    pts[0].SetY(D_004E0B70 * sScale.Y());
    pts[2].SetY(pts[0].Y());
    left = 240.0f + 2.0f / sScale.X();
    pts[1].SetY(((float)barBottom - 2.0f / sScale.Y()) * sScale.Y());
    pts[3].SetY(pts[1].Y());
    width = 160.0f - 4.0f / sScale.X();
    pts[0].SetX(left * sScale.X());
    pts[1].SetX(pts[0].X());
    pts[2].SetX((0.0f + left + D_004E26BC * width) * sScale.X());
    pts[3].SetX(pts[2].X());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, cols);

    // the four rules: (x0, x1) = (0, 320) / (320, 640), top y = D_004E157C / D_004E1580, 2 high
    cols[0] = colA;
    cols[1] = colA;
    cols[2] = colB;
    cols[3] = colB;
    pts[0].SetX(x0 * sScale.X());
    pts[1].SetX(pts[0].X());
    pts[2].SetX(320.0f * sScale.X());
    pts[3].SetX(pts[2].X());
    pts[1].SetY((2.0f + D_004E157C) * sScale.Y());
    pts[3].SetY(pts[1].Y());
    pts[0].SetY(D_004E157C * sScale.Y());
    pts[2].SetY(D_004E157C * sScale.Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, cols);
    pts[0].SetX(x0 * sScale.X());
    pts[1].SetX(pts[0].X());
    pts[2].SetX(320.0f * sScale.X());
    pts[3].SetX(pts[2].X());
    pts[1].SetY((2.0f + D_004E1580) * sScale.Y());
    pts[3].SetY(pts[1].Y());
    pts[0].SetY(D_004E1580 * sScale.Y());
    pts[2].SetY(D_004E1580 * sScale.Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, cols);
    cols[0] = colB;
    cols[1] = colB;
    cols[2] = colA;
    cols[3] = colA;
    pts[0].SetX(320.0f * sScale.X());
    pts[1].SetX(pts[0].X());
    pts[2].SetX(640.0f * sScale.X());
    pts[3].SetX(pts[2].X());
    pts[1].SetY((2.0f + D_004E157C) * sScale.Y());
    pts[3].SetY(pts[1].Y());
    pts[0].SetY(D_004E157C * sScale.Y());
    pts[2].SetY(D_004E157C * sScale.Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, cols);
    pts[0].SetX(320.0f * sScale.X());
    pts[1].SetX(pts[0].X());
    pts[2].SetX(640.0f * sScale.X());
    pts[3].SetX(pts[2].X());
    pts[1].SetY((2.0f + D_004E1580) * sScale.Y());
    pts[3].SetY(pts[1].Y());
    pts[0].SetY(D_004E1580 * sScale.Y());
    pts[2].SetY(D_004E1580 * sScale.Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, cols);

    Gt2dRenderer::End();
    RwCameraEndUpdate(D_00666270->field_58);
    float p = D_004E26BC;
    D_00666274 = 0;
    D_00666270 = 0;
    if (p < 0.75f)
        D_004E26BC = p + 0.01f;
}
