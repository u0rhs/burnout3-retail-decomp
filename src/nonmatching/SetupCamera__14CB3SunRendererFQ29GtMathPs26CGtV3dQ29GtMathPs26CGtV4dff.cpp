// NONMATCHING: SetupCamera__14CB3SunRendererFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV4dff -- retail 148 / ours 148 instructions, 134 in changed runs
// 148/148 instrs, 134 in changed runs: logic believed right (normalise dir -> D_01D9B940, pos = D_00666320 or cam+0xD0, TransformPoint(cam+0xE0, pos + dir*50), behind test z <= 0.01, XYOFFSET split, GS offsets, sun pos x/z y/z, screen size/aspect/FOV/blob, colour*128 and colour*W*128). Left: the static-member store/convert schedule (distinct gp globals reorder freely; retail converts field_218/21C early), pos slot (retail stores pos to the stack in both arms), lane-copy slots. Stand-ins: compiler-chosen vadd, compiler-chosen Normalise, CGtV4d*WAxisType
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SunRenderer::SetupCamera -- hand-matched (ghvu8). Static method (a0 = the direction, no this).
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CB3GraphicsManager;

// [G] one camera record (0x230 bytes) in the graphics manager's array at +0x470
struct UnkStruct_0024D110_cam {
    unsigned char pad_0[0xD0];
    CGtV3d field_D0;
    CGtMatrix3x4 field_E0;
    unsigned char pad_120[0xC0];
    u_long128 field_1E0;
    unsigned char pad_1F0[0x10];
    float field_200;
    unsigned char pad_204[0x4];
    float field_208;
    float field_20C;
    unsigned char pad_210[0x8];
    float field_218;
    float field_21C;
    float field_220;
    float field_224;
    unsigned char pad_228[0x8];
};
struct UnkStruct_0024D110_gm {
    unsigned char pad_0[0x470];
    UnkStruct_0024D110_cam field_470[1];  // [G] element count unknown
};
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };

class CB3SunRenderer {
public:
    static void SetupCamera(CGtV3d dir, CGtV4d colour, float blob, float corona);
    static CGtV2d mSunPos;
    static CGtV2d mScreenSize;
    static CGtV2d mScreenOffset;
    static int mnScreenSizeX;
    static int mnScreenSizeY;
    static int mnXYOffsetX;
    static int mnXYOffsetY;
    static int mnGSOffsetX;
    static int mnGSOffsetY;
    static float mrAspectRatio;
    static float mrFOVScale;
    static float mrBlobRadius;
    static float mrCoronaRadius;
    static bool mbBehind;
};

extern CB3GraphicsManager D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern CGtV3d D_00666320;
extern CGtV3d D_01D9B940;
extern CGtV4d D_01D9B960;
extern CGtV4d D_01D9B970;

// [L] N185: CGtV3d + CGtV3d on compiler-chosen registers (the header's goes through $vf1/$vf2 and GPRs)
static inline CGtV3d SetupCamera_inl1(const CGtV3d &a, CGtV3d b) {
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185: Normalise on the vector's own (compiler-chosen) register, result out through a GPR
static inline void SetupCamera_inl2(CGtV3d &v) {
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm("qmtc2.i %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(r) : "j"(v.mData));
    v.mData = r;
}

// [L] N185: CGtV4d * WAxisType (lane-broadcast multiply, missing from the header)
static inline CGtV4d SetupCamera_inl3(const CGtV4d &a, WAxisType w) {
    u_long128 r;
    asm("vmulw.xyzw %0, %1, %2w" : "=j"(r) : "j"(a.mData), "j"(w.lVector));
    return CGtV4d(r);
}

// 0x0024D110
void CB3SunRenderer::SetupCamera(CGtV3d dir, CGtV4d colour, float blob, float corona)
{
    CGtV4d col = colour;
    CGtV3d pos;
    const CGtV3d *pp = &pos;
    int idx = D_00667050.field_0;
    UnkStruct_0024D110_cam *cam = &((UnkStruct_0024D110_gm *)&D_00665EC0)->field_470[idx];
    CGtV3d d = dir;
    SetupCamera_inl2(d);
    D_01D9B940 = d;
    if (idx > 0) {
        pos = D_00666320;
    } else {
        pos = cam->field_D0;
    }
    CGtV3d r = TransformPoint(cam->field_E0, SetupCamera_inl1(*pp, D_01D9B940 * 50.0f));
    float z = r.Z();
    if (z <= 0.01f) {
        mbBehind = true;
        return;
    }
    mbBehind = false;
    unsigned long xy = (unsigned long)cam->field_1E0;
    mnXYOffsetX = (int)(xy & 0xFFFF);
    mnXYOffsetY = (int)((xy & 0xFFFF00000000UL) >> 32);
    mScreenOffset.marValues[0] = cam->field_220;
    mScreenOffset.marValues[1] = cam->field_224;
    mnScreenSizeX = (int)cam->field_218;
    mnScreenSizeY = (int)cam->field_21C;
    mnGSOffsetX = mnXYOffsetX + (int)(16.0f * mScreenOffset.marValues[0]);
    mnGSOffsetY = mnXYOffsetY + (int)(16.0f * mScreenOffset.marValues[1]);
    float iz = 1.0f / (float)r.Z();  // [C] retail FPU form, not a VU lane op: 0x24D2B4 / 0x24D300 div.s (the cast keeps the port's PS2 float model)
    float sx = r.X();
    float sy = r.Y();
    mSunPos.marValues[0] = sx * iz;
    mSunPos.marValues[1] = sy * iz;
    mScreenSize.marValues[0] = (float)mnScreenSizeX;
    mScreenSize.marValues[1] = (float)mnScreenSizeY;
    mrAspectRatio = cam->field_200 * (cam->field_20C * (mScreenSize.marValues[1] / mScreenSize.marValues[0]));
    mrFOVScale = cam->field_208;
    mrBlobRadius = blob * mrFOVScale;
    mrCoronaRadius = corona;
    D_01D9B960 = col * 128.0f;
    D_01D9B970 = SetupCamera_inl3(col, col.W()) * 128.0f;
}
