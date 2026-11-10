// NONMATCHING: Construct__13CB3CameraDataFP8RwCamera -- retail 358 / ours 356 instructions, 283 in changed runs
// v312 first draft (356/358, mnemonic diff 96): logic believed complete (RwMatrix rows widened by lwu/pcpyld, 4 projection rows on uninitialised CGtV4d locals via compiler-chosen lane setters [L] N185, z per projection type + skyUploadedCode bit 3, GS FRAME/ZBUF/XYOFFSET/SCISSOR quads, VU1 scale/shift lanes, frame + view rows via CGtV3d(x,y,z), Initialise, view window floats). Left: frame 0x200 vs 0x1C0, lane-setter VU numbering/scheduling, scissor bit-pack (ours re-extends with dsll32/dsra32 differently), the four m* copies.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3CameraData::Construct(RwCamera*) -- hand-written (v312; the lifter refused it).
// [C] name: retail symbol table. Field names are placeholders and every type is [G] (instruction widths).
// [L] RwCamera / RwRaster / RwFrame offsets from the RW 3.5 sky2 headers (viewMatrix 0x20, frameBuffer 0x60,
// viewWindow 0x68, nearPlane 0x80, farPlane 0x84; raster width 0xC, height 0x10, nOffsetX/Y 0x1C/0x1E).

#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_skyFrame_1.h"
using namespace GtMathPs2;

struct RwCamera;
struct UnkStruct_skyXyoffset_1 { unsigned long field_0; };
struct UnkStruct_skyZbuf_1 { unsigned long field_0; };
extern UnkStruct_skyFrame_1 skyFrame_1;
extern UnkStruct_skyZbuf_1 skyZbuf_1;
extern UnkStruct_skyXyoffset_1 skyXyoffset_1;
extern unsigned char skyUploadedCode;
extern CGtV4d xMaxYMax128;
extern CGtV4d vu1DataXYZScale;
extern CGtV4d vu1DataXYZShift;
extern CGtV4d vu1DataOffset3D;

struct UnkStruct_00225B30_v { unsigned int field_0, field_4, field_8, field_C; };   // [L] RwV3d + pad (RwMatrix row)
struct UnkStruct_00225B30_fv { float field_0, field_4, field_8, field_C; };
struct UnkStruct_00225B30_r {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[8];
    short field_1C;
    short field_1E;
};
struct UnkStruct_00225B30_fr {
    unsigned char pad_0[0x10];
    UnkStruct_00225B30_fv field_10[4];
};
struct UnkStruct_00225B30_c {
    unsigned char pad_0[4];
    UnkStruct_00225B30_fr *field_4;
    unsigned char pad_8[0xC];
    int field_14;
    unsigned char pad_18[8];
    union { UnkStruct_00225B30_v u[4]; UnkStruct_00225B30_fv f[4]; } field_20;
    UnkStruct_00225B30_r *field_60;
    unsigned char pad_64[4];
    float field_68[6];
    float field_80;
    float field_84;
};

class CB3CameraData {
public:
    void Construct(RwCamera *);
    unsigned char pad_0[0xA0];
    CGtV3d field_A0[4];
    CGtV3d field_E0[4];
    u_long128 field_120[4];
    CGtV4d field_160;
    CGtV4d field_170;
    CGtV4d field_180;
    CGtV4d field_190;
    CGtV4d field_1A0;
    CGtV4d field_1B0;
    u_long128 field_1C0;
    u_long128 field_1D0;
    u_long128 field_1E0;
    u_long128 field_1F0;
    float field_200[6];
    float field_218;
    float field_21C;
    float field_220;
    float field_224;
};
extern "C" void Initialise__16CGtCameraFrustumFP8RwCamera(void *, RwCamera *);

// [L] N185: compiler-chosen lane setters (retail: the scalar qmtc2'd into a compiler-chosen VF, then one lane op)
static inline void func_00225B30_inl1(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00225B30_inl2(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00225B30_inl3(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00225B30_inl4(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// [G] an RwV3d row widened to a quad: (x | y << 32) low, (z | z << 32) high
static inline u_long128 func_00225B30_inl5(const UnkStruct_00225B30_v &r)
{
    unsigned long lo = (unsigned long)r.field_0 | ((unsigned long)r.field_4 << 32);
    unsigned long hi = (unsigned long)r.field_8 | ((unsigned long)r.field_8 << 32);
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi));
    return q;
}
static inline u_long128 func_00225B30_inl6(unsigned long lo, unsigned long hi)
{
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi));
    return q;
}

// 0x00225B30
void CB3CameraData::Construct(RwCamera *rc)
{
    UnkStruct_00225B30_c *c = (UnkStruct_00225B30_c *)rc;
    CGtV4d v0, v1, v2, v3;
    CGtV4d m0, m1, m2, m3;
    field_120[0] = func_00225B30_inl5(c->field_20.u[0]);
    field_120[1] = func_00225B30_inl5(c->field_20.u[1]);
    field_120[2] = func_00225B30_inl5(c->field_20.u[2]);
    field_120[3] = func_00225B30_inl5(c->field_20.u[3]);
    float n = c->field_80;
    float f = c->field_84;
    float rd = 1.0f / (f - n);
    int hw = c->field_60->field_C >> 1;
    int hh = c->field_60->field_10 >> 1;
    float a = 2047.9374f - (float)hw;
    float b = 2047.9374f - (float)hh;
    float cw = (float)(hw + 5);
    float ch = (float)(hh + 5);
    func_00225B30_inl1(v0, a);
    func_00225B30_inl2(v0, 1.0f / a);
    func_00225B30_inl4(v0, c->field_84);
    func_00225B30_inl1(v1, b);
    func_00225B30_inl2(v1, 1.0f / b);
    func_00225B30_inl4(v1, c->field_80);
    func_00225B30_inl1(v2, cw);
    func_00225B30_inl2(v2, 1.0f / cw);
    func_00225B30_inl4(v2, c->field_84);
    func_00225B30_inl1(v3, ch);
    func_00225B30_inl2(v3, 1.0f / ch);
    func_00225B30_inl4(v3, c->field_80);
    if (c->field_14 == 1) {
        skyUploadedCode &= ~8;
        float z0 = rd * (-2.0f * f * n);
        float z1 = rd * (f + n);
        m0 = v0; func_00225B30_inl3(m0, z0);
        m2 = v2; func_00225B30_inl3(m2, z0);
        m1 = v1; func_00225B30_inl3(m1, z1);
        m3 = v3; func_00225B30_inl3(m3, z1);
    } else {
        float z0 = -rd * (f + n);
        float z1 = 2.0f * rd;
        skyUploadedCode |= 8;
        m0 = v0; func_00225B30_inl3(m0, z0);
        m2 = v2; func_00225B30_inl3(m2, z0);
        m1 = v1; func_00225B30_inl3(m1, z1);
        m3 = v3; func_00225B30_inl3(m3, z1);
    }
    field_1A0 = m0;
    field_1B0 = m1;
    field_180 = m2;
    field_190 = m3;
    field_1C0 = func_00225B30_inl6(skyFrame_1.field_0, 0x4C);
    field_1D0 = func_00225B30_inl6(skyZbuf_1.field_0, 0x4E);
    field_1E0 = func_00225B30_inl6(skyXyoffset_1.field_0, 0x18);
    UnkStruct_00225B30_r *r = c->field_60;
    int x0 = r->field_1C;
    int y0 = r->field_1E;
    unsigned long sc = ((unsigned long)(y0 & 0x7FF) << 32) | ((unsigned long)(x0 & 0x7FF) | ((long)(r->field_C + x0 - 1) << 16));
    sc |= (long)(r->field_10 + y0 - 1) << 48;
    field_1F0 = func_00225B30_inl6(sc, 0x40);
    field_218 = (float)c->field_60->field_C;
    field_21C = (float)c->field_60->field_10;
    field_220 = (float)c->field_60->field_1C;
    field_224 = (float)c->field_60->field_1E;
    {
        CGtV4d t = vu1DataXYZScale;
        asm("vmulz.w %0, $vf0, %1z" : "+j"(t.mData) : "j"(xMaxYMax128.mData));
        field_160 = t;
    }
    {
        CGtV4d s = vu1DataXYZShift;
        CGtV4d o = vu1DataOffset3D;
        CGtV4d t = vu1DataXYZShift;
        asm("vaddx.x %0, %0, %1x" : "+j"(s.mData) : "j"(o.mData));
        asm("vaddx.x %0, $vf0, %1x" : "+j"(t.mData) : "j"(s.mData));
        asm("vaddy.y %0, %1, %0y" : "+j"(o.mData) : "j"(t.mData));
        asm("vaddy.y %0, $vf0, %1y" : "+j"(t.mData) : "j"(o.mData));
        asm("vmulw.w %0, $vf0, %1w" : "+j"(t.mData) : "j"(xMaxYMax128.mData));
        field_170 = t;
    }
    UnkStruct_00225B30_fr *fr = c->field_4;
    field_A0[0] = CGtV3d(fr->field_10[0].field_0, fr->field_10[0].field_4, fr->field_10[0].field_8);
    field_A0[1] = CGtV3d(fr->field_10[1].field_0, fr->field_10[1].field_4, fr->field_10[1].field_8);
    field_A0[2] = CGtV3d(fr->field_10[2].field_0, fr->field_10[2].field_4, fr->field_10[2].field_8);
    field_A0[3] = CGtV3d(fr->field_10[3].field_0, fr->field_10[3].field_4, fr->field_10[3].field_8);
    field_E0[0] = CGtV3d(c->field_20.f[0].field_0, c->field_20.f[0].field_4, c->field_20.f[0].field_8);
    field_E0[1] = CGtV3d(c->field_20.f[1].field_0, c->field_20.f[1].field_4, c->field_20.f[1].field_8);
    field_E0[2] = CGtV3d(c->field_20.f[2].field_0, c->field_20.f[2].field_4, c->field_20.f[2].field_8);
    field_E0[3] = CGtV3d(c->field_20.f[3].field_0, c->field_20.f[3].field_4, c->field_20.f[3].field_8);
    Initialise__16CGtCameraFrustumFP8RwCamera(this, rc);
    field_200[0] = c->field_68[0];
    field_200[1] = c->field_68[1];
    field_200[2] = c->field_68[2];
    field_200[3] = c->field_68[3];
    field_200[4] = c->field_68[4];
    field_200[5] = c->field_68[5];
}
