// NONMATCHING: func_003A7F20 -- retail 404 / ours 405 instructions, 349 in changed runs
// draftAL C-first: [L] CB3SatNavComponent zoom-transition frame: five time stages (0.3 / 0.70000005 / 0.90000004 / 1.7, folded literals kept bit-exact) giving the stage ratio and blend weights (eased sin / 1-cos zoom by the flag), map frame scale/position, four cross-hair boxes (positions, SetA alphas 0.35/0.15), func_003ADD80 / func_003A7CB0 / func_003AB430, backdrop slide 656->400, highlight box (lit only in the hold stage); 405/404, calls identical, float op counts equal
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; each stage's register assignments (f20..f25, the two corner pairs, the hold flag) traced, every store (frame, 4 positions, 4 colours, backdrop) and all 10 calls' argument lists

// func_003A7F20 -- draftAL (C-first draft). 0x3A7F20, 0x650. Unnamed in every table: placeholder with C linkage. [L] a
// CB3SatNavComponent member (its callers: CB3SatNavComponent::Prepare, archived, as func_003A7F20(this, 1, 0) / (this, 0, 2.1)).
// Written from the retail asm; declarations after the Prepare archive and the proven ZoomIn (func_003A89A0.cpp).
// What it does [L]: one frame of the sat-nav map's zoom transition at time t (seconds): five stages (t <= 0.3: lead-in,
// <= 0.7: the map box slides from the (1548, 1030) / (-12, -6) corners to the stage's two map corners (func_003F5A20 /
// func_003F5940), <= 0.9: hold, <= 1.7: zoom with an eased curve (flag: sin rise, else 1 - cos), after: settle), each giving
// a stage ratio r and the blend weights; then the map frame scale/position, the four cross-hair boxes' positions and alphas
// (0.35 / 0.15 x fade), the cross-hair update (func_003ADD80), the stage step (func_003A7CB0), the backdrop slide
// (656 -> 400), func_003AB430, and the highlight box (field_214) over the stage area: lit (D_004CA000) during the hold,
// transparent otherwise. Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003A7F20_fr { CGtV2d field_0; CGtV2d field_8; };   // [L] the map frame: scale, position
struct UnkStruct_003A7F20 {                 // [L] CB3SatNavComponent (layout as the Prepare archive)
    unsigned char pad_0[0x10];
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGt2dObject * field_30[4];              // cross-hair boxes
    unsigned char pad_40[0x1D4];
    void * field_214;                       // highlight box (CGt2dObjectBox)
    unsigned char pad_218[0x10];
    UnkStruct_003A7F20_fr * field_228;
    unsigned char pad_22C[0x20];
    CGtV2d * field_24C;                     // backdrop position
    unsigned char pad_250[0x4];
    int field_254;                          // region
    unsigned char pad_258[0x24];
    int field_27C;                          // stage
    unsigned char pad_280[0x664];
    signed char field_8E4;                  // mode
    unsigned char pad_8E5[0x3];
    unsigned char field_8E8;
};
struct UnkStruct_003A7F20_D { unsigned char pad_0[0x10]; };
extern UnkStruct_003A7F20_D D_01E7A800;
extern const CGtV4d D_004C9F80;             // cross-hair colour
extern const CGtV4d D_004CA000;             // highlight colour
extern "C" float sinf(float);
extern "C" CGtV2d func_003F5A20(int, int);
extern "C" CGtV2d func_003F5940(int, int);
extern "C" void func_002850F0(void *);
extern "C" void func_00284F50(void *);
extern "C" void func_003ADD80(UnkStruct_003A7F20 *, float);
extern "C" void func_003A7CB0(UnkStruct_003A7F20 *, float);
extern "C" void func_003AB430(UnkStruct_003A7F20 *, float);
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);

// [G] linear blend a -> b (retail keeps the 0 + 90 r of the first use unfolded: an inline's parameter)
static inline float func_003A7F20_inl1(float a, float b, float r) { return a + (b - a) * r; }

// 0x003A7F20
extern "C" void func_003A7F20(UnkStruct_003A7F20 * self, int flag, float t)
{
    CGtV2d lFar(1548, 1030);
    CGtV2d lMin = func_003F5A20(self->field_254, self->field_27C);
    CGtV2d lMax = func_003F5940(self->field_254, self->field_27C);
    self->field_8E8 = 1;
    bool lbHold = false;
    float r;                                // the stage ratio
    float lrFade;                           // f24: cross-hair alpha
    float lrA;                              // f23: func_003ADD80's weight
    float lrInset;                          // f21: cross-hair inset
    float lrZoom;                           // f25: frame zoom blend
    float lrB;                              // f20: func_003AB430's weight
    CGtV2d lCorner0;                        // cross-hair corner (far)
    CGtV2d lCorner1;                        // cross-hair corner (near)
    if (t <= 0.3f) {
        r = 3.3333333f * t;
        lrFade = 1.0f - r;
        lrInset = 0.5f;
        lrZoom = 0.0f;
        lCorner0 = lFar;
        lrB = lrZoom;
        lCorner1 = self->field_28;
        lrA = lrFade;
        if (self->field_8E4 == 5)
            func_002850F0(&D_01E7A800);
    } else if (t <= 0.70000005f) {
        r = 2.5f * (t - 0.3f);
        CGtV2d lStart(-12.0f, -6.0f);
        CGtV2d d0 = lMin - lFar;
        CGtV2d d1 = lMax - lStart;
        lrZoom = 0.0f;
        lrFade = 1.0f;
        lCorner1 = lStart + d1 * r;
        lCorner0 = lFar + d0 * r;
        lrA = lrZoom;
        lrInset = lrZoom;
        lrB = lrZoom;
        func_00284F50(&D_01E7A800);
    } else if (t <= 0.90000004f) {
        lbHold = true;
        lrZoom = 0.0f;
        lrA = lrZoom;
        lrFade = 1.0f;
        r = 5.0f * (t - 0.70000005f);
        lCorner1 = lMax;
        lCorner0 = lMin;
        lrInset = lrZoom;
        lrB = lrZoom;
    } else if (t <= 1.7f) {
        r = 1.25f * (t - 0.90000004f);
        if (flag)
            lrZoom = sinf(0.017453292f * func_003A7F20_inl1(0.0f, 90.0f, r));
        else
            lrZoom = 1.0f - sinf(0.017453292f * func_003A7F20_inl1(90.0f, 180.0f, r));
        lrA = 0.0f;
        lrFade = 1.0f - r;
        lCorner1 = lMax;
        lrInset = lrA;
        lrB = lrA;
        lCorner0 = lMin;
    } else {
        r = 2.5f * (t - 1.7f);
        lCorner1 = lMax;
        lCorner0 = lMin;
        lrFade = 0.0f;
        lrZoom = 1.0f;
        lrB = r;
        lrA = lrFade;
        lrInset = lrFade;
    }

    CGtV2d lRange = self->field_18 - self->field_10;
    CGtV2d lScale = self->field_20 * lrZoom;
    float x0 = lCorner0.X() - 12.0f;
    float y0 = lCorner0.Y() - 6.0f;
    CGtV2d lOffset = lRange * lrZoom;
    float x1 = lCorner1.X() - 12.0f * lrInset;
    float y1 = lCorner1.Y() - 6.0f * lrInset;
    float a = 0.35f * lrFade;
    float b = 0.15f * lrFade;
    CGtV2d lPos = self->field_10 + lOffset;
    self->field_228->field_8 = lPos;
    self->field_228->field_0 = lScale;
    self->field_30[0]->mObjectSpace.mTopLeftPos = CGtV2d(x1, 0.0f);
    self->field_30[1]->mObjectSpace.mTopLeftPos = CGtV2d(0.0f, y1);
    self->field_30[2]->mObjectSpace.mTopLeftPos = CGtV2d(x0, 0.0f);
    self->field_30[3]->mObjectSpace.mTopLeftPos = CGtV2d(0.0f, y0);
    CGtV4d c = D_004C9F80;
    c.SetA(a);
    self->field_30[0]->mObjectSpace.mColour = c;
    c.SetA(b);
    self->field_30[1]->mObjectSpace.mColour = c;
    CGtV4d c2 = D_004C9F80;
    c2.SetA(a);
    self->field_30[2]->mObjectSpace.mColour = c2;
    c2.SetA(b);
    self->field_30[3]->mObjectSpace.mColour = c2;
    func_003ADD80(self, lrA);
    func_003A7CB0(self, r);
    if (self->field_24C)
        *self->field_24C = CGtV2d(656.0f + lrZoom * (400.0f - 656.0f), 0.0f);
    func_003AB430(self, lrB);
    if (lbHold)
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
            self->field_214, lMin, CGtV2d(0.0f, 0.0f), lMax - lMin, D_004CA000);
    else
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
            self->field_214, lMin, CGtV2d(0.0f, 0.0f), lMax - lMin, CGtV4d(0.0f, 0.0f, 0.0f, 0.0f));
}
