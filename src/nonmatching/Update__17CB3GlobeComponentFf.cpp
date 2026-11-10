// NONMATCHING: Update__17CB3GlobeComponentFf -- retail 1296 / ours 1286 instructions, 382 in changed runs
// draftAJ C-first: globe FE state machine (intro reveal, highlight pulse, east/west region pans with longitude wrap, zoom-out, spin) + the region-panel re-prepare (2 images with per-region UVs, 2 sprintf texts); 1286/1296, calls the same set (one cosf block placed elsewhere: layout only); left: out-of-line block placement (case 2 ease, region-0 UV block, case 5 ease defaults), frame 0x2B0 vs 0x220
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every state, threshold (ELF .lit4 values), store, colour write (9 panel objects) and call argument traced, incl. Prepare's 9th stack argument and the uninitialised UVs for a region above 2; header CGtV3d::Set / Interpolate / CGtV4d::SetA
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// CB3GlobeComponent::Update(float) -- draftAJ (C-first draft; the lifter refused it). 0x3B63F0, 0x1440.
// [C] name: the mangled symbol in retail's tables; file B3GlobeComponent.cpp (E maps). Written from the retail asm (Ghidra's
// draft as a reading aid). What it does [L]: the front-end globe's state machine (field_54), timer field_60:
//  0 intro: the globe is revealed over 1.5 s (cosine ease), the panel objects fade in with it; then state 1;
//  1 all panel objects opaque, field_6C = 1.25, state 2;
//  2 idle on region field_58: the highlight pulses (eases in over 0.6 s, then a 0.6 s cosine cycle); the region panels fade
//    in over 0.25 s of field_6C;
//  3 / 4 pan from region field_58 to field_5C over 0.25 s (3 eastward, 4 westward: the longitude wraps by 360), panels
//    fading out; at the end the region panels are re-prepared for the new region (picture, map, "%d/" and "%d" texts);
//  5 / 6 zoom out (5 -> 6 after 0.15 s): globe alpha / shape / position eased toward krB3GlobeZoomEndPosition, everything
//    fades; then state 7 (hidden at the zoom end);
//  8 spinning (PrepareSpinning): the longitude advances 20 deg/s at latitude 10.
// Types and field meanings [G]; layouts from the accesses (as PrepareSpinning__17CB3GlobeComponentFv).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

extern "C" float cosf(float);
extern "C" float floorf(float);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);


class CGtTexture;
class CGt2dFrame;

class CGt2dObject {
public:
    unsigned char pad_0[0x10];
    CGtV4d field_10;                        // colour
};

class CB3Globe2dObject : public CGt2dObject {
public:
    bool Prepare();
    void Release();
    void SetGlobeLocation(float, float);    // latitude, longitude (degrees)
    void SetGlobeAlpha(float);
    void SetGlobeReveal(float);
    void SetHighlight(signed char, float);  // region (-1 = none), strength
    void SetShape(float, float);
};

class CGt2dScene {
public:
    CGt2dObject *ConstructObject(int, CGt2dFrame *);
    void DestructObject(int, CGt2dObject *);
    unsigned char pad_0[0x14];
    CGt2dFrame *field_14;                   // root frame
};

struct UnkStruct_D_01E90240 {               // [L] the menu page manager (as CB3BackgroundComponent::PrepareBorders)
    CGtV4d field_0;                         // a menu colour
    unsigned char pad_10[0x100];
    CGtV4d field_110;                       // another menu colour
};
extern UnkStruct_D_01E90240 D_01E90240;
extern CGt2dScene D_01E903E0;               // the menu scene (D_01E90240 + 0x1A0)

class CB3HUDSoundManager {
public:
    void FEGlobeHilight();
};
extern CB3HUDSoundManager D_01E7A800;

// CGt2dObjectImage::Prepare, by its link name with retail's 9th (stack) argument (as CB3BackgroundComponent::PrepareBorders)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d
// CB3Globe2dObject::SetPos(CGtV3d), by its link name: retail passes the address of field_10 itself (no temporary copy)
extern "C" void SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(CB3Globe2dObject *, const CGtV3d *);
// [L] a text object's Prepare (as B3BuddyReadMailComponent_00372600.cpp): pos, anchor, size, colour, font, text, shadow, mode
extern "C" void func_001D6AD0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, const CGtV4d *, void *,
                              const unsigned short *, const CGtV2d *, int);

extern CGtV3d krB3GlobeSpherePosition;      // [C] names: retail symbol table
extern CGtV3d krB3GlobeZoomEndPosition;
extern float karLocationLatitudes[3];
extern float karLocationLongitudes[3];
extern const CGtV2d D_004CA198, D_004CA1A0; // region picture: position, size
extern const CGtV2d D_004CA1C0, D_004CA1C8; // second image: position, size
extern const CGtV2d D_004CA1B8;             // text position
extern const CGtV2d D_004CA200, D_004CA208; // text anchors
extern const CGtV2d D_004CA1D0, D_004CA1D8; // region 0 picture UVs
extern const CGtV2d D_004CA1E0, D_004CA1E8; // region 1
extern const CGtV2d D_004CA1F0, D_004CA1F8; // region 2
extern CGtTexture *D_01EA4620;
extern CGtTexture *D_01EA455C;
struct UnkStruct_D_00665ED0 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED0 D_00665ED0;     // the menu font

class CB3GlobeComponent {
public:
    void Update(float);

    unsigned char pad_0[0x8];
    short field_8;                          // scene layer
    unsigned char pad_A[0x6];
    CGtV3d field_10;                        // globe position
    CB3Globe2dObject *field_20;
    unsigned char pad_24[0xC];
    CGt2dObject *field_30;
    CGt2dObject *field_34;                  // region picture (image)
    CGt2dObject *field_38;                  // image
    CGt2dObject *field_3C;                  // text "%d/"
    CGt2dObject *field_40;                  // text "%d"
    CGt2dObject *field_44;
    CGt2dObject *field_48;
    CGt2dObject *field_4C;
    CGt2dObject *field_50;
    int field_54;                           // state
    int field_58;                           // current region
    int field_5C;                           // target region
    float field_60;                         // state timer
    float field_64;                         // spin longitude
    unsigned char pad_68[0x4];
    float field_6C;                         // panel fade timer
    int field_70[3];                        // per region: first number
    int field_7C[3];                        // per region: second number
    unsigned char pad_88[0x8];
    unsigned short field_90[6];
    unsigned short field_9C[6];
};

static const float kDegToRad = 0.017453292f;

// [G] an ease 1 -> 0 over [0, e]
static inline float func_003B63F0_inl1(float t, float e)
{
    float r = 1.0f;
    if (t <= e) {
        if (!(t <= 0.0f)) r = 1.0f - t / e;
    } else {
        r = 0.0f;
    }
    return r;
}

// [G] an ease 1 -> 0 over [s, e] (the folded e - s is retail's 0.099999994 = 0.25f - 0.15f)
static inline float func_003B63F0_inl2(float t, float s, float e)
{
    float r = 1.0f;
    if (t <= e) {
        if (!(t <= s)) r = 1.0f - (t - s) / (e - s);
    } else {
        r = 0.0f;
    }
    return r;
}

// [G] an ease 0 -> 1 over [0, e]
static inline float func_003B63F0_inl3(float t, float e)
{
    float r = 0.0f;
    if (t <= e) {
        if (!(t <= 0.0f)) r = t / e;
    } else {
        r = 1.0f;
    }
    return r;
}

// [G] re-prepare the region panels for region field_58 (the end of a pan, states 3 and 4)
static inline void func_003B63F0_inl4(CB3GlobeComponent *self)
{
    UnkStruct_D_01E90240 *const mgr = &D_01E90240;
    if (self->field_34 != 0) {
        CGtV2d uv0, uv1;                    // [C] left unset for a region above 2 (retail passes the stack as it is)
        if (self->field_58 == 2) {
            uv0 = D_004CA1F0;
            uv1 = D_004CA1F8;
        } else if (self->field_58 == 1) {
            uv0 = D_004CA1E0;
            uv1 = D_004CA1E8;
        } else if (self->field_58 == 0) {
            uv0 = D_004CA1D0;
            uv1 = D_004CA1D8;
        }
        CGtV2d anchor;
        anchor.marValues[0] = 0.5f;
        anchor.marValues[1] = 0.5f;
        CGt2dObjectImage_Prepare(self->field_34, D_004CA198, anchor, D_004CA1A0, CGtV4d(1.0f, 1.0f, 1.0f, 0.0f),
                                 D_01EA4620, uv0, uv1, 0);
    }
    if (self->field_38 != 0) {
        CGtV2d anchor, uv0, uv1;
        anchor.marValues[0] = 0.5f;
        anchor.marValues[1] = 0.5f;
        uv0.marValues[0] = 0.0f;
        uv1.marValues[0] = 1.0f;
        uv1.marValues[1] = 1.0f;
        uv0.marValues[1] = 0.0f;
        CGt2dObjectImage_Prepare(self->field_38, D_004CA1C0, anchor, D_004CA1C8, CGtV4d(1.0f, 1.0f, 1.0f, 0.0f),
                                 D_01EA455C, uv0, uv1, 0);
    }
    if (self->field_3C != 0) {
        char buf[4];
        sprintf(buf, "%d/", self->field_70[self->field_58]);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(buf, self->field_90, 6);
        CGtV2d shadow;
        shadow.marValues[0] = 0.8f;
        shadow.marValues[1] = 0.8f;
        func_001D6AD0(self->field_3C, D_004CA1B8, D_004CA200, 36.0f, &mgr->field_110, D_00665ED0.field_0,
                      self->field_90, &shadow, 2);
    }
    if (self->field_40 != 0) {
        char buf[4];
        sprintf(buf, "%d", self->field_7C[self->field_58]);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(buf, self->field_9C, 6);
        CGtV2d shadow;
        shadow.marValues[1] = 0.5f;
        shadow.marValues[0] = 0.8f;
        func_001D6AD0(self->field_40, D_004CA1B8, D_004CA208, 25.0f, &mgr->field_0, D_00665ED0.field_0,
                      self->field_9C, &shadow, 2);
    }
    CGtV4d clear(1.0f, 1.0f, 1.0f, 0.0f);
    self->field_34->field_10 = clear;
    self->field_38->field_10 = clear;
    self->field_3C->field_10 = clear;
    self->field_40->field_10 = clear;
}

// 0x003B63F0
void CB3GlobeComponent::Update(float dt)
{
    CGt2dScene *const scene = &D_01E903E0;
    UnkStruct_D_01E90240 *const mgr = &D_01E90240;
    if (field_20 == 0) {
        field_20 = (CB3Globe2dObject *)scene->ConstructObject(field_8, scene->field_14);
        if (!field_20->Prepare()) {
            field_20->Release();
            scene->DestructObject(field_8, field_20);
            field_20 = 0;
            return;
        }
    }
    switch (field_54) {
    case 8:                                 // spinning
        field_60 = 0.0f;
        field_10.Set(-100.0f, 0.0f, 1000.0f);
        field_64 = field_64 + 20.0f * dt;
        if (!(field_64 <= 360.0f)) field_64 = field_64 - 360.0f;
        SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
        field_20->SetGlobeLocation(10.0f, field_64);
        field_20->SetGlobeAlpha(1.0f);
        field_20->SetGlobeReveal(1.0f);
        field_20->SetHighlight(-1, 1.0f);
        field_20->SetShape(1.0f, 0.0f);
        break;
    case 0: {                               // intro
        field_60 = field_60 + dt;
        field_10 = krB3GlobeSpherePosition;
        float lat = karLocationLatitudes[field_58];
        float lon = karLocationLongitudes[field_58];
        if (field_60 <= 1.5f) {
            float r = (1.0f + cosf(kDegToRad * (180.0f + 180.0f * (field_60 / 1.5f)))) / 2.0f;
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeLocation(lat, lon);
            field_20->SetGlobeAlpha(1.0f);
            field_20->SetGlobeReveal(r);
            field_20->SetHighlight(-1, 0.0f);
            field_20->SetShape(1.0f, 0.0f);
            CGtV4d c(1.0f, 1.0f, 1.0f, r);
            CGtV4d c2;
            c2 = mgr->field_0;
            c2.SetA(r);
            field_30->field_10 = c;
            field_34->field_10 = c;
            field_38->field_10 = c;
            field_3C->field_10 = c;
            field_40->field_10 = c2;
            field_44->field_10 = c;
            field_48->field_10 = c;
            field_4C->field_10 = c;
            field_50->field_10 = c2;
        } else {
            D_01E7A800.FEGlobeHilight();
            field_60 = 0.0f;
            field_54 = 1;
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeLocation(lat, lon);
            field_20->SetGlobeAlpha(1.0f);
            field_20->SetGlobeReveal(1.0f);
            field_20->SetHighlight(-1, 0.0f);
            field_20->SetShape(1.0f, 0.0f);
        }
        break;
    }
    case 1: {
        CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f);
        field_30->field_10 = c;
        field_34->field_10 = c;
        field_38->field_10 = c;
        field_3C->field_10 = c;
        field_40->field_10 = mgr->field_0;
        field_44->field_10 = c;
        field_48->field_10 = c;
        field_4C->field_10 = c;
        field_50->field_10 = mgr->field_0;
        field_6C = 1.25f;
        field_54 = 2;
        break;
    }
    case 2: {                               // idle on a region: pulsing highlight
        float t = field_60;
        float h;
        if (t <= 0.6f) {
            float r = t / 0.6f;
            h = 0.0f;
            if (!(r <= 0.0f)) {
                float e = (1.0f + cosf(kDegToRad * (180.0f + 180.0f * r))) / 2.0f;
                h = 1.0f + -0.75f * e;
            }
        } else {
            float r = (t - 0.6f) / 0.6f;
            float c = cosf(kDegToRad * (360.0f * (r - (float)(int)floorf(r))));
            h = 0.5f + (0.5f + 0.5f * c) * -0.25f;
        }
        if (field_6C < 0.25f) {
            float a = field_6C / 0.25f;
            CGtV4d c(1.0f, 1.0f, 1.0f, a);
            CGtV4d c2;
            c2 = mgr->field_0;
            c2.SetA(a);
            field_34->field_10 = c;
            field_38->field_10 = c;
            field_3C->field_10 = c;
            field_40->field_10 = c2;
        } else {
            CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f);
            field_34->field_10 = c;
            field_38->field_10 = c;
            field_3C->field_10 = c;
            field_40->field_10 = mgr->field_0;
        }
        field_6C = field_6C + dt;
        field_60 = field_60 + dt;
        field_10 = krB3GlobeSpherePosition;
        float lat = karLocationLatitudes[field_58];
        float lon = karLocationLongitudes[field_58];
        SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
        field_20->SetGlobeLocation(lat, lon);
        field_20->SetGlobeAlpha(1.0f);
        field_20->SetGlobeReveal(1.0f);
        field_20->SetHighlight((signed char)field_58, h);
        field_20->SetShape(1.0f, 0.0f);
        break;
    }
    case 3: {                               // pan to field_5C (eastward)
        float t = field_60 + dt;
        field_60 = t;
        if (t <= 0.25f) {
            float s = (1.0f + cosf(kDegToRad * (180.0f * t / 0.25f))) / 2.0f;
            float u = 1.0f - s;
            float lat = s * karLocationLatitudes[field_58] + u * karLocationLatitudes[field_5C];
            float lon0 = karLocationLongitudes[field_58];
            float lon1 = karLocationLongitudes[field_5C];
            float lon;
            if (lon0 < lon1) {
                lon = s * lon0 + u * lon1;
            } else {
                lon = s * lon0 + u * (360.0f + lon1);
            }
            field_10 = krB3GlobeSpherePosition;
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeLocation(lat, lon);
            field_20->SetGlobeAlpha(1.0f);
            field_20->SetGlobeReveal(1.0f);
            field_20->SetHighlight(-1, 0.0f);
            field_20->SetShape(1.0f, 0.0f);
            float a = 1.0f - GtMath::Min(GtMath::Max(field_60 / 0.25f, 0.0f), 1.0f);
            CGtV4d c(1.0f, 1.0f, 1.0f, a);
            CGtV4d c2;
            c2 = mgr->field_0;
            c2.SetA(a);
            field_34->field_10 = c;
            field_38->field_10 = c;
            field_3C->field_10 = c;
            field_40->field_10 = c2;
        } else {
            field_58 = field_5C;
            field_10 = krB3GlobeSpherePosition;
            float lat = karLocationLatitudes[field_58];
            float lon = karLocationLongitudes[field_58];
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeLocation(lat, lon);
            field_20->SetGlobeAlpha(1.0f);
            field_20->SetGlobeReveal(1.0f);
            field_20->SetHighlight(-1, 0.0f);
            field_20->SetShape(1.0f, 0.0f);
            field_60 = 0.0f;
            func_003B63F0_inl4(this);
            field_6C = 0.0f;
            field_54 = 2;
            D_01E7A800.FEGlobeHilight();
        }
        break;
    }
    case 4: {                               // pan to field_5C (westward)
        float t = field_60 + dt;
        field_60 = t;
        if (t <= 0.25f) {
            float s = (1.0f + cosf(kDegToRad * (180.0f * t / 0.25f))) / 2.0f;
            float u = 1.0f - s;
            float lat = s * karLocationLatitudes[field_58] + u * karLocationLatitudes[field_5C];
            float lon0 = karLocationLongitudes[field_58];
            float lon1 = karLocationLongitudes[field_5C];
            float lon;
            if (!(lon0 <= lon1)) {
                lon = s * lon0 + u * lon1;
            } else {
                lon = s * (360.0f + lon0) + u * lon1;
            }
            field_10 = krB3GlobeSpherePosition;
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeLocation(lat, lon);
            field_20->SetGlobeAlpha(1.0f);
            field_20->SetGlobeReveal(1.0f);
            field_20->SetHighlight(-1, 0.0f);
            field_20->SetShape(1.0f, 0.0f);
            float a = 1.0f - GtMath::Min(GtMath::Max(field_60 / 0.25f, 0.0f), 1.0f);
            CGtV4d c(1.0f, 1.0f, 1.0f, a);
            CGtV4d c2;
            c2 = mgr->field_0;
            c2.SetA(a);
            field_34->field_10 = c;
            field_38->field_10 = c;
            field_3C->field_10 = c;
            field_40->field_10 = c2;
        } else {
            field_58 = field_5C;
            field_10 = krB3GlobeSpherePosition;
            float lat = karLocationLatitudes[field_58];
            float lon = karLocationLongitudes[field_58];
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeLocation(lat, lon);
            field_20->SetGlobeAlpha(1.0f);
            field_20->SetGlobeReveal(1.0f);
            field_20->SetHighlight(-1, 0.0f);
            field_20->SetShape(1.0f, 0.0f);
            func_003B63F0_inl4(this);
            field_6C = 0.0f;
            field_60 = 0.0f;
            field_54 = 2;
            D_01E7A800.FEGlobeHilight();
        }
        break;
    }
    case 5:
    case 6: {                               // zoom out
        field_60 = field_60 + dt;
        field_20->SetGlobeLocation(karLocationLatitudes[field_58], karLocationLongitudes[field_58]);
        field_20->SetGlobeReveal(1.0f);
        field_20->SetHighlight(-1, 0.0f);
        if (!(field_60 <= 0.15f) && field_54 == 5) field_54 = 6;
        float t = field_60;
        if (t <= 0.25f) {
            float shape = func_003B63F0_inl1(t, 0.25f);
            float alpha = func_003B63F0_inl2(t, 0.15f, 0.25f);
            float zoom = func_003B63F0_inl3(t, 0.25f);
            float c0 = cosf(kDegToRad * (180.0f + 180.0f * shape));
            field_10 = Interpolate(krB3GlobeSpherePosition, krB3GlobeZoomEndPosition, zoom * zoom);
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeAlpha(alpha);
            field_20->SetShape((1.0f + c0) / 2.0f, 0.0f);
            float a = 1.0f - field_60 / 0.3f;
            CGtV4d c(1.0f, 1.0f, 1.0f, a);
            CGtV4d c2;
            c2 = mgr->field_0;
            c2.SetA(a);
            field_30->field_10 = c;
            field_34->field_10 = c;
            field_38->field_10 = c;
            field_3C->field_10 = c;
            field_40->field_10 = c2;
            field_44->field_10 = c;
            field_48->field_10 = c;
            field_4C->field_10 = c;
            field_50->field_10 = c2;
        } else {
            field_60 = 0.0f;
            field_54 = 7;
            field_10 = krB3GlobeZoomEndPosition;
            SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
            field_20->SetGlobeAlpha(0.0f);
            field_20->SetShape(0.0f, 1.0f);
        }
        break;
    }
    case 7: {                               // zoomed out, hidden
        field_10 = krB3GlobeZoomEndPosition;
        field_60 = 0.0f;
        float lat = karLocationLatitudes[field_58];
        float lon = karLocationLongitudes[field_58];
        SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d(field_20, &field_10);
        field_20->SetGlobeLocation(lat, lon);
        field_20->SetGlobeAlpha(0.0f);
        field_20->SetGlobeReveal(1.0f);
        field_20->SetHighlight(-1, 0.0f);
        field_20->SetShape(0.0f, 1.0f);
        break;
    }
    default:
        field_60 = 0.0f;
        break;
    }
}
