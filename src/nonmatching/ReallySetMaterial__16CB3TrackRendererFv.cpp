// NONMATCHING: ReallySetMaterial__16CB3TrackRendererFv -- retail 304 / ours 303 instructions, 25 in changed runs
// v304: 304/303 instrs, 25 changed. Jump table, sky VU-code quad, texture, GIF packet all in place; frame via two N140 pads. Left: case 2 (type 2) -- retail keeps addiu a0,sp,0x80 / addiu a2,sp,0xB0 as base registers for the field_60 copy and the b0 stores (ours folds them to sp offsets; pointer locals, inline helpers with pointer/reference/by-value params all fold; function-scope pointers go to s-regs); then a1/a0 + t0/a2/a3 rotation in the last 3 quads. field_94->field_10 re-read needs a const pun [G].
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrackRenderer::ReallySetMaterial() -- [C] name: the mangled symbol in retail's tables (config/symbol_addrs_b3names.txt).
// File: B3TrackRendererRuntimePS2.cpp (its neighbours EndMaterial / RestoreRenderStatesAfterRenderingTrack, retail_names.csv);
// Area not evidenced, so _unclassified/. Fields are placeholders; every type is [G] (instruction widths).
// Hand-written (no lifter draft): jump-table switch on the material type picks the VU1 microprogram and its size,
// the sky VU-code switch quad (B3SkyDomeRendererPS2_0021DE50 shape), texture upload, then an 11-quad GIF/VIF packet (N218).

typedef unsigned int u_long128 __attribute__((mode(TI)));
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV4d;

class CGtTexture;
enum EGtTextureCachePS2_FilterMode {};
class CGtTextureCache {
public:
    void AccessTexture(CGtTexture *, float, EGtTextureCachePS2_FilterMode, bool, bool);
    unsigned char pad_0[0x240];
};

struct UnkStruct_0026B2F0_m {
    int field_0;
    float field_4;
    float field_8;
    CGtTexture ** field_C;
    signed char field_10;
    unsigned char pad_11[0xB];
    float field_1C;
    unsigned int field_20;
    unsigned short field_24;
    unsigned char field_26;
    unsigned char field_27;
};

union UnkStruct_0026B2F0_q {
    u_long128 q;
    struct { int i0; float f4; int i8; int iC; } s;
    float f[4];
};

class CB3TrackRenderer {
public:
    void ReallySetMaterial();
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    CGtV4d field_40;
    CGtV4d field_50;
    CGtV4d field_60;
    unsigned char pad_70[0x24];
    UnkStruct_0026B2F0_m * field_94;
    unsigned char pad_98[4];
    unsigned char field_9C;
    unsigned char pad_9D[0x2B];
    float field_C8;
    float field_CC;
};

struct UnkStruct_farFogPlane { u_long128 * field_0; };
struct UnkStruct_skyUserSwitch1 { unsigned int field_0; };
struct UnkStruct_skyTextureRaster { CGtTexture * field_0; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern UnkStruct_skyTextureRaster skyTextureRaster;
extern CGtTextureCache gTextureCache;
extern char vu_game_00471FA0[];
extern char vu_game_00476130[];
extern char vu_game_00472EB0[];
extern char vu_game_00470650[];
extern char vu_game_004803F0[];
extern char vu_game_00481DD0[];
extern char vu_game_0047E300[];
extern char vu_game_004745C0[];
extern char vu_game_0046F0D0[];
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" float floorf(float);

// N140 pads: two unused 16-byte frame slots retail keeps between b0 and the field_60 copy [G].
struct UnkStruct_0026B2F0_pad { int x[4]; UnkStruct_0026B2F0_pad() {} ~UnkStruct_0026B2F0_pad() {} };
// [G] placeholder inline: case 2's parameter block, written through pointers (retail's a0/a2 bases).
static inline void func_0026B2F0_inl1(UnkStruct_0026B2F0_q * o, const CGtV4d v, bool on)
{
    UnkStruct_0026B2F0_q t;
    t.q = v.mData;
    o->f[0] = t.f[0];
    o->f[1] = t.f[2];
    o->s.i8 = on;
}
static inline void func_0026B2F0_inl2(UnkStruct_0026B2F0_q * o, CGtV4d v, bool on)
{
    o->f[0] = v.f[0];
    o->f[1] = v.f[2];
    o->s.i8 = on;
}
static inline void func_0026B2F0_inl3(UnkStruct_0026B2F0_q & o, CGtV4d v, bool on)
{
    o.f[0] = v.f[0];
    o.f[1] = v.f[2];
    o.s.i8 = on;
}
// 0x0026B2F0
void CB3TrackRenderer::ReallySetMaterial()
{
    CGtTexture * tex = 0;
    if (field_9C == 1) return;
    UnkStruct_0026B2F0_m * m = field_94;
    int type = m->field_0;
    unsigned int code;
    int size;
    switch (type) {
    case 4:
    case 5:
        code = (unsigned int)vu_game_00471FA0;
        size = 0x1D2;
        break;
    case 3:
        code = (unsigned int)vu_game_00476130;
        size = 0xF0;
        break;
    case 1:
        size = 0x110;
        if (m->field_24 & 0x20) code = (unsigned int)vu_game_00472EB0;
        else code = (unsigned int)vu_game_00470650;
        break;
    case 2:
        size = 0xF0;
        if (m->field_24 & 0x20) code = (unsigned int)vu_game_004803F0;
        else code = (unsigned int)vu_game_00481DD0;
        break;
    case 7:
        code = (unsigned int)vu_game_0047E300;
        size = 0xF0;
        break;
    default:
    case 0:
    case 6:
        size = 0xF0;
        if (m->field_24 & 0x20) code = (unsigned int)vu_game_004745C0;
        else code = (unsigned int)vu_game_0046F0D0;
        break;
    }
    if (m->field_C) tex = m->field_C[(*(UnkStruct_0026B2F0_m * const *)&field_94)->field_10];
    _rwDMAOpenVIFPkt(0, 2);
    u_long128 * t0 = farFogPlane.field_0;
    u_long128 * v1;
    u_long128 q0;
    if (skyUserSwitch1.field_0 != code) {
        skyUserSwitch1.field_0 = code;
        unsigned long lo = ((unsigned long)code << 32) | 0x50000000UL;
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(lo), "r"(0x0300000011000000UL));
        t0[0] = q0;
        v1 = t0 + 1;
    } else {
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000UL), "r"(0x0300000011000000UL));
        t0[0] = q0;
        v1 = t0 + 1;
    }
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x10000000UL), "r"((unsigned long)(unsigned int)(size | 0x02000000) | 0x1400000000000000UL));
    v1[0] = q1;
    farFogPlane.field_0 = v1 + 1;
    long fl;
    if (type == 3) fl = 0xE9;
    else fl = 0x4C;
    if (tex == 0) {
        skyTextureRaster.field_0 = 0;
    } else {
        if (tex != skyTextureRaster.field_0) {
            int mode;
            if (type == 6) mode = 2;
            else mode = 1;
            gTextureCache.AccessTexture(tex, field_C8, (EGtTextureCachePS2_FilterMode)mode, false, false);
        }
        skyTextureRaster.field_0 = tex;
        fl |= 0x10;
    }
    UnkStruct_0026B2F0_q c0;
    UnkStruct_0026B2F0_q b0;
    UnkStruct_0026B2F0_pad pad1;
    UnkStruct_0026B2F0_pad pad2;
    u_long128 a;
    u_long128 b;
    UnkStruct_0026B2F0_q * pc = &c0;
    if (field_94->field_24 & 0x200) {
        float f = floorf(field_94->field_1C);
        pc->s.i0 = 1;
        pc->s.f4 = 1.0f - (field_94->field_1C - f);
    } else {
        pc->s.i0 = 0;
        pc->s.f4 = 0.0f;
    }
    switch (type) {
    case 1:
        field_30.SetW(field_94->field_8);
        field_40.SetW(field_94->field_4);
        a = field_30.mData;
        b = field_40.mData;
        b0.f[0] = 4.0f;
        break;
    case 2: {
        field_30.SetW(field_94->field_8);
        field_50.SetW(field_94->field_4);
        a = field_30.mData;
        b = field_50.mData;
        func_0026B2F0_inl3(b0, field_60, field_94->field_4 > 0.0f);
        break;
    }
    case 7:
        b0.f[1] = field_CC;
        break;
    case 0:
        break;
    }
    _rwDMAOpenVIFPkt(0, 0xB);
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"((fl << 15 | 0x30004000UL) << 32), "r"(0x412UL));
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000005UL), "r"(0x6C0503ED01000404UL));
    *p++ = c0.q;
    *p++ = q2;
    *p++ = a;
    *p++ = b;
    *p++ = b0.q;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000004UL), "r"(0x5000000400000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008003UL), "r"(0xEUL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0UL), "r"(8UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)field_94->field_20), "r"(0x47UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)field_94->field_26 | ((unsigned long)field_94->field_27 << 32)), "r"(0x42UL));
    farFogPlane.field_0 = p;
    field_9C = 1;

}
