// NONMATCHING: Render__18CB3DirectionalBlurFv -- retail 277 / ours 278 instructions, 103 in changed runs
// fix3 (2026-11-01): the Downsample / BlurSetRenderstates / BlurIn / BlurOut / CopyToScreen / RestoreRenderstates helpers are static (retail passes their first argument in a0; the member form shifted every argument by one register) [C] retail 0x426F0C.. | Before: lit4fix: .lit4 externs rewritten as literals; was: a156: 284 vs 277 instrs, 199 changed (twin Render__13CB3RadialBlurFv is archived too). Adapted from the Radial shape; new facts: second D_00665F2A test kept (field_20 < D_004E1010 between), hw = (int)(0.0f + D_004E1014 + w*0.5*field_10) - 9999 (D_004E1014 gp float), packet size = 10 + (n1*2+1) + 5 +
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


typedef unsigned int u_long128 __attribute__((mode(TI)));
#include "b3/GtMathPs2.h"
class CGtTexture;
struct UnkStruct_00665F2A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_006662D8 { unsigned int field_0; unsigned char pad_4[0xC]; };
struct CB3CameraData {
    unsigned char pad_0[0x1C0];
    u_long128 field_1C0;
    unsigned char pad_1D0[0x20];
    u_long128 field_1F0;
    unsigned char pad_200[0x30];
};
struct UnkStruct_00665EC0 {
    unsigned char pad_0[0x470];
    CB3CameraData cams[4];
};
extern UnkStruct_00665F2A D_00665F2A;
extern UnkStruct_00667050 D_00667050;
extern UnkStruct_006662D8 D_006662D8;
extern UnkStruct_00665EC0 D_00665EC0;
extern float D_004E1010;
extern int D_004E25E0;
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);

class CB3DirectionalBlur {
public:
    // fix3: the helpers are static [C] retail Render 0x426F0C..: Downsample gets fbp in a0 .. h in t3, BlurSetRenderstates a0..a3,
    // BlurIn/BlurOut/CopyToScreen/RestoreRenderstates their first argument in a0 (no this); the mangled names cannot show it
    void Render();
    static void SetRenderstates();
    static void Downsample(unsigned long a, unsigned long b, unsigned long c, unsigned long d, int e, int f, int g, int h);
    static void BlurIn(int a, int b, int c, int d, const GtMathPs2::CGtV2d &e);
    static void BlurSetRenderstates(unsigned long p0, unsigned long p1, int p2, int p3);
    static void BlurOut(int a, int b, int c, int d, const GtMathPs2::CGtV2d &e);
    static void CopyToScreen(unsigned long a, unsigned long b, unsigned long c, unsigned long d, int e, int f, int g, int h, float i);
    static void RestoreRenderstates(const CB3CameraData *p0);
    unsigned char pad_0[0x10];
    float field_10;
    float field_14;
    GtMathPs2::CGtV2d field_18;
    float field_20;
};

static inline int func_Render_blk(int hw, int half, bool lt)
{
    int t0;
    int a3;
    if (lt) {
        int m = hw > 0 ? hw : 0;
        t0 = (half + 31) / 32 - m / 32;
    } else {
        t0 = 0;
    }
    if (hw > 0) {
        int mn = hw < half ? hw : half;
        a3 = (mn + 31) / 32;
    } else {
        a3 = 0;
    }
    return (a3 + t0) * 4 + 1;
}

void CB3DirectionalBlur::Render()
{
    if (D_00665F2A.field_0 == 0) return;
    if (field_20 < D_004E1010) return;
    if (D_00665F2A.field_0 == 0) return;
    CB3CameraData *camp;
    camp = &D_00665EC0.cams[D_00667050.field_0];
    unsigned long fbp, fbw;
    int y0, hv;
    unsigned long s6 = D_006662D8.field_0 >> 5;
    unsigned long fr = (unsigned long)camp->field_1C0;
    unsigned long sc = (unsigned long)camp->field_1F0;
    float f4 = 0.5f * field_10;
    fbp = fr & 0x1FF;
    float f1 = 0.5f * field_14;
    fbw = (fr >> 16) & 0x3F;
    int x0 = (int)(sc & 0x7FF);
    y0 = (int)((sc & 0x7FF00000000UL) >> 32);
    int x1 = (int)((sc & 0x7FF0000UL) >> 16);
    int y1 = (int)((sc & 0x7FF000000000000UL) >> 48);
    int w = (long)x1 + 1 - x0;
    int h = (long)y1 + 1 - y0;
    unsigned long s7 = (fbw + 1) >> 1;
    int hw = (int)(0.0f + 9999.5f + (float)w * f4) - 9999;
    hv = (int)(0.0f + 9999.5f + (float)h * f1) - 9999;
    int s2 = w / 2;
    int fp = h / 2;
    int n1 = (x0 + w + 31) / 32 - x0 / 32;
    int sz = 6;
    sz = sz + 4;
    sz = sz + (n1 * 2 + 1);
    sz += 5;
    bool lt = hw < s2;
    for (int i = 0; i < 3; i++) sz += func_Render_blk(hw, s2, lt);
    sz += 4;
    sz += ((w + 31) / 32) * 2 + 1;
    sz += 9;
    _rwDMAOpenVIFPkt(0x80000000, sz);
    SetRenderstates();
    Downsample(fbp, fbw, s6, s7, x0, y0, w, h);
    BlurSetRenderstates(s6, s7, s2, fp);
    GtMathPs2::CGtV2d v;
    v.Set(field_18.X(), field_18.Y());
    bool flip = true;
    for (int i = 0; i < 3; i++) {
        int g = D_004E25E0;
        if (g != -1) flip = (g != 0);
        if (flip) {
            BlurOut(hw, hv, s2, fp, v);
        } else {
            GtMathPs2::CGtV2d inv(1.0f / v.X(), 1.0f / v.Y());
            BlurIn(hw, hv, s2, fp, inv);
        }
        flip = !flip;
        v.Set(v.X() * v.X(), v.Y() * v.Y());
    }
    CopyToScreen(fbp, fbw, s6, s7, x0, y0, w, h, field_20);
    RestoreRenderstates(camp);
}
