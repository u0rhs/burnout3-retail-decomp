// NONMATCHING: DrawPositionMarker__15CB3RacePositionFQ29GtMathPs26CGtV3dPCUsiP10CB3RaceCarP10CB3RaceCarfbbbf -- retail 950 / ours 992 instructions, 928 in changed runs
// draftAJ C-first: view projection + near/far/screen culling, near-arrow hysteresis per slot, colour per race mode (duel/revenge) or points steps, distance/close-up fades, arrow / text / bar / label / points box through a stack CGt2dObject; 992/950, calls identical (jalr targets via the object's render callback); left: block layout (mode cases, fade blocks), CGtV2d temps via swc1 vs retail sqc2 lane copies, frame 0xB40 vs 0xA10
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); retail's real argument list (an int points value where the E name says bool; third bool unread), SetZ's near/far arguments, every cull/fade threshold (ELF .lit4), colour choice and store traced; uninitialised colour for an unknown race mode kept; one operator-(float, ZAxisType) stand-in (queued)

// CB3RacePosition::DrawPositionMarker(CGtV3d, const unsigned short*, int, CB3RaceCar*, CB3RaceCar*, float, bool, bool, bool,
// float) -- draftAJ (C-first draft; the lifter refused it). 0x1531C0, 0xED8. [C] name: retail's tables. Written from the retail
// asm (Ghidra's draft as a reading aid). Argument list [C] from the registers retail reads (as the Draw archive's call): the
// first "bool" is used as an int (compared with 2501 / 10001: a points value), the third bool (stack) is never read; so the
// definition goes through the link name with retail's real list.
// What it does [L]: draws the floating marker over a car (or a points popup when `points` mode is on):
//  - project the world position through the active view (D_00666270), cull against its near/far planes and the screen
//    edges (with a margin of half the marker size); the marker size grows with distance (1 + (z-1)/74) and is capped at 320;
//  - near/far state per car slot (field_0[index], 35 m hysteresis, only while field_18 == 1);
//  - colour by race mode (this->field_20: 1 blue, 2/4 duel/revenge colours, 3 red/blue by the car's field_16B4, 5
//    white/red), fading out with distance (split-screen limits 100..125, else 175..200) and in close up (2 .. 2.7);
//  - points mode: colour by the points (2501 / 10001 steps), alpha ramps over 1.75 s;
//  - then an arrow triangle (near) or the name text, an optional bar (mode 3, the car's field_16B4 fill), the car's own
//    label text (field_1974), and in points mode a second text and a box.
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;


class CGt2dFont;
class CB3RaceCar;
class CB3Score {
public:
    bool CheckIfNeedRevenge(const CB3Score *) const;
    unsigned char pad_0[0x8];
};
class CB3ScoreBonus {
public:
    CB3RaceCar *GetDuellingCar();
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C8[0x98];
    bool field_1160;
    unsigned char pad_1161[0x83];
    CB3ScoreBonus field_11E4;
    unsigned char pad_11E5[0x157];
    int field_133C;                         // [G] state (3 = ...)
    unsigned char pad_1340[0x374];
    float field_16B4;                       // [G] a 0..1 meter (bar fill)
    unsigned char pad_16B8[0x25C];
    int field_1914;
    unsigned char pad_1918[0x5C];
    unsigned short field_1974[0x12];        // the car's label text
    bool field_1998;                        // [G] visible
};

struct UnkStruct_001531C0_view {            // *D_00666270: the active view
    CGtMatrix3x4 field_0;                   // world -> camera
    unsigned char pad_40[0x8];
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    unsigned char pad_58[0x20];
    int field_78;                           // screen width
    int field_7C;                           // screen height
    unsigned char pad_80[0x4];
    float field_84;                         // near
    float field_88;                         // far
};
extern UnkStruct_001531C0_view *D_00666270;
extern CGtV4d D_0066A4C0[8];                // HUD colour table
extern CGtV4d kHDRColourScale;
extern CGtV4d kColourPosMarkerOrange;
extern CGtV4d kColourPosMarkerRed;
extern CGtV4d kColourPosMarkerWhite;
extern CGtV4d kColourPosMarkerBlue;
extern CGtV4d D_004B6280;                   // [G] a function static: opaque black (bar background)
extern signed char D_004E26AC;              // its guard
extern float D_004E26A8;
struct UnkStruct_D_00665ED0 { CGt2dFont *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED0 D_00665ED0;     // the HUD font
struct UnkStruct_D_01E65499 { bool field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E65499 D_01E65499;     // [G] split screen
extern unsigned short D_0051D740[];         // the points-mode second text

// text Prepare kinds (proven func_0033D4E0: italic text; func_001D6AD0 as B3BuddyReadMailComponent_00372600.cpp)
extern "C" void func_0033D4E0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, const CGtV4d, const CGt2dFont *,
                              const unsigned short *, const CGtV2d &, int);
extern "C" void func_001D6AD0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, const CGtV4d, const CGt2dFont *,
                              const unsigned short *, const CGtV2d &, int);

class CB3RacePosition {
public:
    int field_0[6];                         // per car slot: drawn as the near arrow
    int field_18;
    unsigned char pad_1C[0x4];
    int field_20;                           // race mode
};


// [G] draw a 2D object prepared on the stack: copy its object space and call its render callback
static inline void func_001531C0_inl1(CGt2dObject &o)
{
    CGt2dObject::CGt2dObjectSpace s = o.mObjectSpace;
    o.Render(s);
}

// 0x001531C0
extern "C" void DrawPositionMarker__15CB3RacePositionFQ29GtMathPs26CGtV3dPCUsiP10CB3RaceCarP10CB3RaceCarfbbbf(
    CB3RacePosition *self, const CGtV3d &worldPos, const unsigned short *text, int index, CB3RaceCar *car,
    CB3RaceCar *player, float time, int points, bool pointsMode, bool unused, float anchorX)
{
    CGtV3d pos = worldPos;
    bool drawBar = false;                   // s7
    bool drawLabel = false;                 // s2
    bool nearArrow;                         // s1
    UnkStruct_001531C0_view *view = D_00666270;
    float k54 = view->field_54;
    CGtMatrix3x4 m = view->field_0;
    float k50 = view->field_50;
    float k4C = view->field_4C;
    float k48 = view->field_48;
    float sw = (float)view->field_78;
    float sh = (float)view->field_7C;
    CGtV2d zero;
    zero.marValues[0] = 0.0f;
    zero.marValues[1] = 0.0f;
    float aspect = sh / sw * k54 * k48;
    (void)k4C;
    if (car != 0 && !car->field_1998) return;
    if (car != 0 && car->field_133C == 0) return;
    CGtV3d p = TransformPoint(m, pos);
    if ((float)p.Z() <= view->field_84) return;
    if (!((float)p.Z() < view->field_88)) return;
    if (pointsMode) {
        nearArrow = false;
    } else {
        int *slot = &self->field_0[index];
        if (*slot == 0) {
            nearArrow = true;
            if ((float)p.Z() < 35.0f && self->field_18 == 1) {
                *slot = 1;
                nearArrow = false;
            }
        } else {
            nearArrow = false;
            if (!((float)p.Z() <= 35.0f) && self->field_18 == 1) {
                *slot = 0;
                nearArrow = true;
            }
        }
    }
    // project
    float one = 1.0f;
    CGtV3d q = p;
    q.SetZ(q.Z() - 1.0f);
    float inv = one / (float)p.Z();
    CGtV3d s = p;
    s.SetX(p.X() * inv * sw);
    s.SetY(s.Y() * inv * sh);
    float size = 0.5f * (sw * (inv * (1.5f * (1.0f + (float)q.Z() / 74.0f))) * k50);
    if (!(size <= 320.0f)) size = 320.0f;
    float height = aspect * (0.33333334f * size);
    float half = 0.5f * (sh * (D_004E26A8 * inv) * k54);
    CGtV3d sp = s;
    sp.SetY(sp.Y() - height);
    if ((float)sp.X() < 0.5f * -size) return;
    if ((float)sp.Y() < 0.5f * -height) return;
    if (!((float)sp.X() <= sw + 0.5f * size)) return;
    if (!((float)sp.Y() <= sh + 0.5f * height)) return;
    Gt2dRenderer::SetZ(sp.Z(), view->field_84, view->field_88);
    float alpha = one;
    CGtV4d colour;
    CGtV4d colour2;
    if (pointsMode) {
        if (points < 2501) {
            colour = D_0066A4C0[4] * kHDRColourScale;
        } else if (points < 10001) {
            colour = kColourPosMarkerOrange;
        } else {
            colour = D_0066A4C0[6] * kHDRColourScale;
        }
        colour2 = kColourPosMarkerWhite;
        if (time < 1.75f) {
            if (time < 0.5f) alpha = 2.0f * time;
            if (!(time <= 1.25f)) alpha = 2.0f * (1.75f - time);
            if (alpha < 0.1f) alpha = 0.0f;
        } else {
            alpha = 0.0f;
        }
        colour2.SetA(alpha);
        drawBar = false;
        drawLabel = false;
    } else {
        switch (self->field_20) {
        case 3:
            drawBar = !nearArrow;
            nearArrow = true;
            if (car->field_16B4 <= 0.1f) {
                colour = kColourPosMarkerRed;
            } else {
                colour = kColourPosMarkerBlue;
            }
            break;
        case 5:
            if (car->field_133C == 3) nearArrow = true;
            if (car->field_1160) {
                drawLabel = true;
                nearArrow = drawLabel;
                colour = kColourPosMarkerRed;
            } else {
                drawLabel = true;
                colour = kColourPosMarkerWhite;
            }
            break;
        case 4: {
            if (car->field_133C == 3) nearArrow = true;
            bool duel = car == player->field_11E4.GetDuellingCar();
            if (player->field_10C0.CheckIfNeedRevenge(&car->field_10C0)) {
                colour = kColourPosMarkerRed;
            } else if (duel) {
                colour = kColourPosMarkerOrange;
            } else {
                colour = D_0066A4C0[2] * kHDRColourScale;
            }
            drawLabel = true;
            break;
        }
        case 2: {
            if (car->field_133C == 3) nearArrow = true;
            if (car->field_1914 == 0) drawLabel = true;
            bool duel = car == player->field_11E4.GetDuellingCar();
            if (player->field_10C0.CheckIfNeedRevenge(&car->field_10C0)) {
                colour = kColourPosMarkerRed;
            } else if (duel) {
                colour = kColourPosMarkerOrange;
            } else {
                colour = D_0066A4C0[2] * kHDRColourScale;
            }
            break;
        }
        case 1:
            nearArrow = true;
            colour = kColourPosMarkerBlue;
            if (car->field_1914 == 0) drawLabel = nearArrow;
            break;
        }
        // fade with distance
        CGtV3d d = sp;
        if (D_01E65499.field_0) {
            if (!((float)d.Z() <= 125.0f)) return;
            if (!((float)d.Z() <= 100.0f)) alpha = (one - (d.Z() - 100.0f) * 0.04f);
        } else {
            if (!((float)d.Z() <= 200.0f)) return;
            if (!((float)d.Z() <= 175.0f)) alpha = (one - (d.Z() - 175.0f) * 0.04f);
        }
        if ((float)sp.Z() < 2.7f) {
            if ((float)sp.Z() < 2.0f) return;
            alpha = alpha * (float)((sp.Z() - 2.0f) * 1.4285713f);
        }
        if (!(alpha <= one)) alpha = one;
    }
    colour.SetA(alpha);
    CGt2dObject obj;
    if (nearArrow) {
        // a downward triangle
        float a = 0.3f * size;
        float b = 0.5f * height;
        CGtV2d tri[3];
        tri[0].marValues[0] = sp.X() - a;
        tri[0].marValues[1] = sp.Y() - b;
        tri[1].marValues[0] = sp.X() + a;
        tri[1].marValues[1] = sp.Y() - b;
        tri[2].marValues[0] = sp.X();
        tri[2].marValues[1] = sp.Y() + b;
        Gt2dRenderer::RenderTriStripFlatUntex(colour, zero, 3, tri);
    } else {
        if (size < 20.0f) size = 20.0f;
        if (height < 7.0f) height = 7.0f;
        CGtV2d tp;
        tp.marValues[0] = sp.X();
        tp.marValues[1] = sp.Y() - height;
        CGtV2d shadow;
        if (pointsMode) {
            shadow.marValues[0] = 0.9f;
            shadow.marValues[1] = 0.9f;
        } else {
            shadow.marValues[0] = 0.03f;
            shadow.marValues[1] = 0.03f;
        }
        CGtV2d anchor;
        anchor.marValues[0] = anchorX;
        anchor.marValues[1] = 0.0f;
        func_0033D4E0(&obj, tp, anchor, 2.0f * height, colour, D_00665ED0.field_0, text, shadow, 2);
        func_001531C0_inl1(obj);
    }
    if (pointsMode) {
        // the second points text and a box behind it
        float h2 = 2.0f * height;
        CGtV2d tp;
        tp.marValues[0] = sp.X();
        tp.marValues[1] = sp.Y() - height;
        CGtV2d shadow;
        shadow.marValues[0] = 0.9f;
        shadow.marValues[1] = 0.9f;
        CGtV2d anchor;
        anchor.marValues[0] = 0.0f;
        anchor.marValues[1] = one;
        func_0033D4E0(&obj, tp, anchor, h2, colour2, D_00665ED0.field_0, D_0051D740, shadow, 2);
        func_001531C0_inl1(obj);
        CGtV2d bsize;
        bsize.marValues[0] = 4.0f;
        bsize.marValues[1] = h2 + (half + height);
        CGtV2d banchor;
        banchor.marValues[0] = 0.0f;
        banchor.marValues[1] = 0.0f;
        CGtV2d bp;
        bp.marValues[0] = (float)(sp.X() - 10.0f) - 0.45f;
        bp.marValues[1] = (float)((sp.Y() - height) - 0.9f * h2) - 0.45f;
        ((CGt2dObjectBox &)obj).Prepare(bp, banchor, bsize, colour2);
        func_001531C0_inl1(obj);
    }
    if (drawBar) {
        if (!D_004E26AC) {
            D_004E26AC = 1;
            D_004B6280 = CGtV4d(0.0f, 0.0f, 0.0f, one);
        }
        float k = size / 64.0f;
        if (k < 0.5f) k = 0.5f;
        CGtV3d bpos = sp;
        bpos.SetY(bpos.Y() + 16.0f * k);
        float by = bpos.Y();
        CGtV4d bc;
        if (car->field_16B4 <= 0.1f) {
            bc = kColourPosMarkerRed;
        } else {
            bc = D_0066A4C0[2] * kHDRColourScale;
        }
        CGtV2d rect[2];
        CGtV2d z0;
        z0.marValues[0] = 0.0f;
        z0.marValues[1] = 0.0f;
        float x0 = sp.X() - 16.5f * k;
        rect[0].marValues[0] = x0;
        rect[0].marValues[1] = by - k;
        rect[1].marValues[1] = by + 5.0f * k;
        rect[1].marValues[0] = x0 + 34.0f * k;
        Gt2dRenderer::RenderSpritesUntex(D_004B6280, z0, 1, rect);
        float x1 = x0 + k;
        rect[0].marValues[1] = by;
        rect[0].marValues[0] = x1;
        rect[1].marValues[1] = by + 4.0f * k;
        CGtV2d z1;
        z1.marValues[0] = 0.0f;
        z1.marValues[1] = 0.0f;
        rect[1].marValues[0] = x1 + k * (32.0f * car->field_16B4);
        Gt2dRenderer::RenderSpritesUntex(bc, z1, 1, rect);
    }
    if (drawLabel) {
        float w2 = size;                    // [C] retail compares it with 20 and keeps nothing
        if (w2 < 20.0f) w2 = 20.0f;
        (void)w2;
        if (height < 7.0f) height = 7.0f;
        CGtV2d tp;
        tp.marValues[0] = sp.X();
        float h2 = 2.0f * height;
        if (nearArrow) {
            tp.marValues[1] = sp.Y() - (0.5f * height - one);
        } else {
            tp.marValues[1] = sp.Y() - (0.5f * h2 - one);
        }
        CGtV2d shadow;
        shadow.marValues[0] = 0.03f;
        shadow.marValues[1] = 0.03f;
        CGtV2d anchor;
        anchor.marValues[0] = 0.5f;
        anchor.marValues[1] = one;
        func_001D6AD0(&obj, tp, anchor, h2, colour, D_00665ED0.field_0, car->field_1974, shadow, 2);
        func_001531C0_inl1(obj);
    }
}
