// NONMATCHING: Render__13CB3RadialBlurFv -- retail 249 / ours 249 instructions, 97 in changed runs
// a146: same 249 instrs, control flow/calls/args/stack slots right (camp 0xC0,hv 0xD0,y0 0xE0,fbw 0xF0,fbp 0x100 via declaration order); remains: w/hw s3/s4 swapped, scheduling of the packet-size sum (retail accumulates 6,+4,+..; ours reorders), GS scissor decode (D_00665EC0+0x470 CB3CameraData[0x230] stride, SCISSOR at cam+0x1F0, FRAME at cam+0x1C0)
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
extern void *skyTextureRaster;
extern "C" void RpSkyTexCacheAccessSpeculate(void *);
extern "C" int RpSkyTexCacheAccessRaster(void *, int);
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);

class CB3RadialBlur {
public:
    void Render();
    void SetRenderstates();
    void Downsample(unsigned long a, unsigned long b, unsigned long c, unsigned long d, int e, int f, int g, int h);
    void SetAlpha(unsigned long a, unsigned long b, int c, int d, int e, int f, CGtTexture *g, bool h);
    void BlurSetRenderstates(unsigned long p0, unsigned long p1, int p2, int p3);
    void BlurOut(int a, int b, int c, int d, const GtMathPs2::CGtV2d &e);
    void CopyToScreen(unsigned long a, unsigned long b, unsigned long c, unsigned long d, int e, int f, int g, int h);
    void RestoreRenderstates(const CB3CameraData *p0);
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    int field_1C;
    GtMathPs2::CGtV3d field_20;
    unsigned char field_30;
    unsigned char pad_31[0xF];
    CGtTexture *field_40;
};

void CB3RadialBlur::Render()
{
    if (D_00665F2A.field_0 == 0) return;
    CGtTexture *tex = field_40;
    if (skyTextureRaster != (void *)tex) {
        RpSkyTexCacheAccessSpeculate(tex);
        if (RpSkyTexCacheAccessRaster(tex, 0) != 0) skyTextureRaster = tex;
    }
    unsigned long fbp, fbw;
    int y0, hv;
    CB3CameraData *camp;
    camp = &D_00665EC0.cams[D_00667050.field_0];
    unsigned long s6 = D_006662D8.field_0 >> 5;
    unsigned long fr = (unsigned long)camp->field_1C0;
    unsigned long sc = (unsigned long)camp->field_1F0;
    float f3 = 0.5f * field_0;
    fbp = fr & 0x1FF;
    float f1 = 0.5f * field_4;
    fbw = (fr >> 16) & 0x3F;
    int x0 = (int)(sc & 0x7FF);
    y0 = (int)((sc & 0x7FF00000000UL) >> 32);
    int x1 = (int)((sc & 0x7FF0000UL) >> 16);
    int y1 = (int)((sc & 0x7FF000000000000UL) >> 48);
    int w = (long)x1 + 1 - x0;
    int h = (long)y1 + 1 - y0;
    unsigned long s7 = (fbw + 1) >> 1;
    int hw = (int)(0.0f + 0.5f + (float)w * f3);
    hv = (int)(0.0f + 0.5f + (float)h * f1);
    int s2 = w / 2;
    int fp = h / 2;
    int n1 = (x0 + w + 31) / 32 - x0 / 32;
    int n2 = (s2 + 31) / 32 - hw / 32;
    int per = ((hw + 31) / 32 + n2) * 4 + 1;
    int sz = 6;
    sz = sz + 4;
    sz = sz + (n1 * 2 + 1);
    sz += 4;
    sz += per + 5;
    for (int i = 0; i < 3; i++) sz += per;
    sz += 5;
    sz += ((w + 31) / 32) * 2 + 1;
    sz += 9;
    _rwDMAOpenVIFPkt(0x80000000, sz);
    SetRenderstates();
    Downsample(fbp, fbw, s6, s7, x0, y0, w, h);
    SetAlpha(s6, s7, hw, hv, s2, fp, field_40, field_30);
    BlurSetRenderstates(s6, s7, s2, fp);
    GtMathPs2::CGtV2d v;
    v.Set(field_10, field_14);
    for (int i = 0; i < 3; i++) {
        BlurOut(hw, hv, s2, fp, v);
        v.Set(v.X() * v.X(), v.Y() * v.Y());
    }
    CopyToScreen(fbp, fbw, s6, s7, x0, y0, w, h);
    RestoreRenderstates(camp);
}


