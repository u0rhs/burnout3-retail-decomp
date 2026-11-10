// NONMATCHING: UpdateCustomLeadIn__18CB3SatNavComponentFf -- retail 1199 / ours 1188 instructions, 573 in changed runs
// draftT: 1188/1199, 573 changed; frame 0x5D0 vs retail 0x7E0. Decoded all 13 states (jtbl_004CA090; case 12 shares default). Found: zoom block uv0 = c - c*s; uv1 = c + c*s into function-level uv0/uv1 (retail 0x7D0/0x7C8), centre c = D_01EA4798 * 0.5f at 0x7D8; marker offset v must stay in memory (retail keeps &v.y in s0: '*py +=' or 'CGtV2d &rv = v; rv +=' gives +24 instrs); scoped '#pragma opt_loop_invariants off' [G] keeps the colour temporaries inside the 4 loops like retail (-20 changed). Left: 11 instrs short, frame size (retail allocates far more CGtV2d temps: per-case Prepare arg temps + operator copies), case 4/7 division/clamp schedule, madd operand order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from retail asm + Ghidra draft, every state, call, store and constant accounted for; same call sequence
// w64 (2026-11-02): callee prototypes set to the callees' own scalar widths (docs/known.md N293); behaviour_audit unchanged.

// CB3SatNavComponent::UpdateCustomLeadIn(float) -- hand-written from retail (draftT). [C] name: mangled symbol.
// The track-select "custom lead-in": a timed state machine (field_21C, 13 states, jtbl_004CA090) on the clock
// field_704: zoom the two track images (field_204/field_208, texture D_01EA4070.field_400[GetZoomImage(region, i)])
// out of the centre with uv = c -/+ c * scale, fade the extra objects in, then slide the two markers (field_30[0])
// to the region's lead-in point and release (ReleaseExtraLeadIn). Meanings [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EB3TrackRegion {};

class CB3HardCodedTrackRegionList {
public:
    static int GetZoomImage(EB3TrackRegion, int);
};

struct UnkStruct_003A9B70_obj {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
};

class CB3SatNavComponent {
public:
    void UpdateCustomLeadIn(float);
    void ReleaseExtraLeadIn();

    unsigned char pad_0[0x28];
    CGtV2d field_28;
    struct { UnkStruct_003A9B70_obj * field_0; UnkStruct_003A9B70_obj * field_4; } field_30[2];
    unsigned char pad_40[0x124];
    UnkStruct_003A9B70_obj * field_164[6];
    unsigned char pad_17C[0x88];
    UnkStruct_003A9B70_obj * field_204[2];
    UnkStruct_003A9B70_obj * field_20C[2];
    UnkStruct_003A9B70_obj * field_214;
    void * field_218;
    int field_21C;
    unsigned char pad_220[0x34];
    EB3TrackRegion field_254;
    unsigned char pad_258[0x24];
    int field_27C;
    unsigned char pad_280[0x484];
    float field_704;
    unsigned char pad_708[0x1DE];
    unsigned char field_8E6;
    unsigned char pad_8E7;
    unsigned char field_8E8;
    unsigned char pad_8E9[0xC7];
    float field_9B0;
};

struct UnkStruct_D_01EA4070 {
    unsigned char pad_0[0x400];
    void * field_400[1];  // [G] element count unknown
};
struct UnkStruct_D_01EA4798 {
    CGtV2d field_0;
    unsigned char pad_8[8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01EA4070 D_01EA4070;
extern UnkStruct_D_01EA4798 D_01EA4798;
extern UnkStruct_Pad16 D_0051A870;
extern UnkStruct_Pad16 D_01E7A800;

extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void func_003D30C0(void *, float);
extern "C" void func_00324EC0(void *);
extern "C" void func_00284FF0(void *);
extern "C" void FERoadShow__18CB3HUDSoundManagerFv(void *);
extern "C" CGtV2d func_003F5C70(int, int, int);   // [L] third argument: retail passes a3 (0/1) explicitly
extern "C" void func_003ADD80(CB3SatNavComponent *, float);

#define ZOOM(OBJ, IMG, S, COL) \
    uv0 = c - c * (S); \
    uv1 = c + c * (S); \
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(OBJ, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 416.0f), COL, D_01EA4070.field_400[IMG], uv0, uv1, 0)

static inline float func_003A9B70_inl1(float x)
{
    if (x > 1.0f) {
        x = 1.0f;
    }
    return x;
}

static inline float func_003A9B70_inl2(float x)
{
    x = x * 2.0f - 1.0f;
    if (x < 0.0f) {
        x = 0.0f;
    }
    float s = x * x;
    return s * s;
}

// the two markers slide from field_28 towards the region's lead-in point
static inline void func_003A9B70_inl3(CB3SatNavComponent *self, float p)
{
    CGtV2d v(0.0f, 0.0f);
    float *py = &v.marValues[1];
    if (self->field_8E6 != 0) {
        CGtV2d r = func_003F5C70(self->field_254, self->field_27C, 0);
        v.marValues[0] += r.marValues[0];
        *py += r.marValues[1];
    } else {
        CGtV2d r = func_003F5C70(self->field_254, self->field_27C, 1);
        v.marValues[0] += r.marValues[0];
        *py += r.marValues[1];
    }
    CGtV2d pos = self->field_28 + (v - self->field_28) * p;
    self->field_30[0].field_0->field_0 = CGtV2d(pos.marValues[0] - 6.0f, 0.0f);
    self->field_30[0].field_4->field_0 = CGtV2d(0.0f, pos.marValues[1] - 3.0f);
    func_003ADD80(self, p);
}

#pragma push
#pragma opt_loop_invariants off  // [G] retail rebuilds each loop's colour temporary inside the loop
// 0x003A9B70
void CB3SatNavComponent::UpdateCustomLeadIn(float dt)
{
    field_704 += dt;
    field_9B0 += dt;
    CGtV2d c = D_01EA4798.field_0 * 0.5f;
    CGtV2d uv0;
    CGtV2d uv1;
    int img0 = CB3HardCodedTrackRegionList::GetZoomImage(field_254, 0);
    int img1 = CB3HardCodedTrackRegionList::GetZoomImage(field_254, 1);
    field_204[0]->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    field_204[1]->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    field_20C[0]->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    field_20C[1]->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    field_214->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    int i;
    for (i = 0; i < 6; i++) {
        field_164[i]->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    }
    func_003D30C0(field_218, 0.7f);
    switch (field_21C) {
    case 0: {
        float a = func_003A9B70_inl1(field_704 / 0.1f);
        float s = func_003A9B70_inl1(field_704 / 0.525f);
        ZOOM(field_204[0], img0, 1.0f + s * -0.975f, CGtV4d(a, a, a, a));
        if (field_704 >= 0.1f) {
            field_21C = 1;
        }
        break;
    }
    case 1: {
        float s = func_003A9B70_inl1(field_704 / 0.525f);
        ZOOM(field_204[0], img0, 1.0f + s * -0.975f, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        if (field_704 >= 0.2f) {
            field_21C = 3;
        }
        break;
    }
    case 2:
        field_204[0]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        func_003D30C0(field_218, 0.0f);
        if (field_704 >= 0.2f) {
            field_21C = 3;
        }
        break;
    case 3: {
        float s = func_003A9B70_inl1((field_704 - 0.2f + 0.1f + 0.1f) / 0.525f);
        ZOOM(field_204[0], img0, 1.0f + s * -0.975f, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        if (field_704 >= 0.5f) {
            field_21C = 4;
        }
        break;
    }
    case 4: {
        float a = func_003A9B70_inl1((field_704 - 0.5f) / 0.025f);
        float s0 = func_003A9B70_inl1((field_704 - 0.2f + 0.1f + 0.1f) / 0.525f);
        float s1 = func_003A9B70_inl1((field_704 - 0.5f) / 0.425f);
        float k0 = 1.0f + s0 * -0.975f;
        float k1 = 1.0f + s1 * -0.75f;
        ZOOM(field_204[0], img0, k0, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        ZOOM(field_204[1], img1, k1, CGtV4d(1.0f, 1.0f, 1.0f, a));
        if (field_704 >= 0.525f) {
            field_21C = 5;
        }
        break;
    }
    case 5: {
        func_00324EC0(&D_0051A870);
        float s = func_003A9B70_inl1((field_704 - 0.5f) / 0.425f);
        ZOOM(field_204[1], img1, 1.0f + s * -0.75f, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        if (field_704 >= 0.525f) {
            field_21C = 7;
        }
        break;
    }
    case 6:
        field_204[1]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        func_003D30C0(field_218, 0.0f);
        if (field_704 >= 0.525f) {
            field_21C = 7;
        }
        break;
    case 7: {
        float s = 1.0f - func_003A9B70_inl1((0.025f + (field_704 - 0.525f)) / 0.425f);
        func_003D30C0(field_218, 0.7f * s);
        ZOOM(field_204[1], img1, 1.0f + (1.0f - s * s) * -0.75f, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        if (field_704 >= 0.925f) {
            FERoadShow__18CB3HUDSoundManagerFv(&D_01E7A800);
            field_21C = 9;
        }
        break;
    }
    case 8: {
        float a = func_003A9B70_inl2(1.0f);
        ZOOM(field_204[1], img1, 0.25f, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        field_20C[0]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, a);
        func_003D30C0(field_218, 0.0f);
        if (field_704 >= 0.925f) {
            FERoadShow__18CB3HUDSoundManagerFv(&D_01E7A800);
            field_21C = 9;
        }
        break;
    }
    case 9: {
        float a = func_003A9B70_inl2(func_003A9B70_inl1((field_704 - 0.925f) / 0.5f));
        field_20C[0]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        field_20C[1]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, a);
        func_003D30C0(field_218, 0.0f);
        if (field_704 >= 1.425f) {
            FERoadShow__18CB3HUDSoundManagerFv(&D_01E7A800);
            field_21C = 10;
        }
        break;
    }
    case 10: {
        float a = func_003A9B70_inl2(func_003A9B70_inl1((field_704 - 1.425f) / 0.5f));
        field_20C[1]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        for (i = 0; i < 6; i++) {
            field_164[i]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, a);
        }
        func_003D30C0(field_218, 0.0f);
        if (field_704 >= 1.925f) {
            FERoadShow__18CB3HUDSoundManagerFv(&D_01E7A800);
            field_21C = 11;
        }
        break;
    }
    case 11: {
        float p = func_003A9B70_inl1((field_704 - 1.925f) / 0.3f);
        func_003A9B70_inl3(this, p);
        for (i = 0; i < 6; i++) {
            field_164[i]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        }
        func_003D30C0(field_218, 0.0f);
        if (field_704 >= 2.225f) {
            field_21C = 12;
        }
        break;
    }
    case 12:
    default:
        func_00284FF0(&D_01E7A800);
        for (i = 0; i < 6; i++) {
            field_164[i]->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        }
        func_003D30C0(field_218, 0.0f);
        func_003A9B70_inl3(this, 1.0f);
        field_8E8 = 0;
        ReleaseExtraLeadIn();
        break;
    }
}
#pragma pop


