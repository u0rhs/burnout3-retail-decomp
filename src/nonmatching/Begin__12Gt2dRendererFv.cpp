// NONMATCHING: Begin__12Gt2dRendererFv -- retail 102 / ours 106 instructions, 116 in changed runs
// a128: 102 vs 106 instrs; structure right (4 quads, scissor, GS offsets), retail keeps pcpyld quads in s0/t8/t9 (128-bit regs, s0 saved via sq) with lds interleaved; ours schedules loads up front
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Gt2dRenderer::Begin -- [L] DNAT: Gt2dRenderer::Begin() (research/proto/new_names.csv, high); sets the 2D renderer's GS register templates, scissor and offsets [G]

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct RwRaster;

struct UnkStruct_0021A0F0_vp {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[0x8];
    short field_1C;
    short field_1E;
};

struct UnkStruct_0021A0F0_g1 {
    unsigned char pad_0[0x60];
    UnkStruct_0021A0F0_vp * field_60;
};

struct UnkStruct_ourGlobals {
    UnkStruct_0021A0F0_g1 * field_0;
    unsigned char pad_4[0x14];
    float field_18;
};

struct UnkStruct_skyClamp_1 {
    unsigned long field_0;
};
struct UnkStruct_skyFrame_1 {
    unsigned long field_0;
};
struct UnkStruct_skyAlpha_1 {
    unsigned long field_0;
};
struct UnkStruct_skyTex1_1 {
    unsigned long field_0;
};
struct UnkStruct_skyXyoffset_1 {
    unsigned long field_0;
};

class Gt2dRenderer {
public:
    static void Begin();
    static u_long128 * _gau128Buffer;
    static unsigned long * _gpu64Current;
    static unsigned int * _gpuNLoops;
    static int _guCurrentPrimType;
    static RwRaster * _gpCurrentTexture;
    static int _gnCurrentTexturePalette;
    static bool _gbIsZTestEnabled;
    static int _gnNearZ;
    static int _gnUserDefinedZ;
    static int _gnZ;
    static int _gnGSOffX;
    static int _gnGSOffY;
    static u_long128 _gu128Alpha_1;
    static u_long128 _gu128Tex1_1;
    static u_long128 _gu128Clamp_1;
    static u_long128 _gu128Scissor_1;
    static u_long128 _gu128Frame_1;
    static u_long128 _gGsOffsetXYXY;
};

extern UnkStruct_ourGlobals ourGlobals;
extern RwRaster * skyTextureRaster;
extern UnkStruct_skyClamp_1 skyClamp_1;
extern UnkStruct_skyFrame_1 skyFrame_1;
extern UnkStruct_skyAlpha_1 skyAlpha_1;
extern UnkStruct_skyTex1_1 skyTex1_1;
extern UnkStruct_skyXyoffset_1 skyXyoffset_1;

// 0x0021A0F0
void Gt2dRenderer::Begin()
{
    u_long128 q0;
    asm("pcpyld %0, %1, %2" : "=r"(q0) : "r"(8), "r"(skyClamp_1.field_0));
    u_long128 q1;
    asm("pcpyld %0, %1, %2" : "=r"(q1) : "r"(76), "r"(skyFrame_1.field_0));
    u_long128 q2;
    asm("pcpyld %0, %1, %2" : "=r"(q2) : "r"(66), "r"(skyAlpha_1.field_0));
    u_long128 q3;
    asm("pcpyld %0, %1, %2" : "=r"(q3) : "r"(20), "r"(skyTex1_1.field_0));
    unsigned long xy = skyXyoffset_1.field_0;
    UnkStruct_0021A0F0_vp * vp = ourGlobals.field_0->field_60;
    Gt2dRenderer::_gu128Clamp_1 = q0;
    Gt2dRenderer::_gu128Frame_1 = q1;
    Gt2dRenderer::_gu128Tex1_1 = q3;
    Gt2dRenderer::_gu128Alpha_1 = q2;
    Gt2dRenderer::_gpu64Current = (unsigned long *)Gt2dRenderer::_gau128Buffer;
    Gt2dRenderer::_gpCurrentTexture = skyTextureRaster;
    Gt2dRenderer::_guCurrentPrimType = 11;
    Gt2dRenderer::_gnCurrentTexturePalette = -1;
    Gt2dRenderer::_gpuNLoops = 0;
    Gt2dRenderer::_gbIsZTestEnabled = 0;
    unsigned long sc = (((unsigned long)vp->field_1E << 32)
                     | ((unsigned long)vp->field_1C | ((unsigned long)(vp->field_1C + vp->field_C - 1) << 16)))
                     | ((unsigned long)(vp->field_1E + vp->field_10 - 1) << 48);
    u_long128 q4;
    asm("pcpyld %0, %1, %2" : "=r"(q4) : "r"(64), "r"(sc));
    Gt2dRenderer::_gu128Scissor_1 = q4;
    int z = (int)ourGlobals.field_18;
    Gt2dRenderer::_gnNearZ = z;
    Gt2dRenderer::_gnUserDefinedZ = z;
    Gt2dRenderer::_gnZ = z;
    Gt2dRenderer::_gnGSOffX = (int)((xy & 0xFFFF) + (vp->field_1C << 4));
    Gt2dRenderer::_gnGSOffY = (int)(((long)(xy & 0xFFFF00000000) >> 32) + (vp->field_1E << 4));
    float k = 0.0625f;
    union { u_long128 q; struct { float a, b, c, d; } f; } u;
    u.f.a = k * (float)Gt2dRenderer::_gnGSOffX;
    u.f.b = k * (float)Gt2dRenderer::_gnGSOffY;
    u.f.c = u.f.a;
    u.f.d = u.f.b;
    Gt2dRenderer::_gGsOffsetXYXY = u.q;
}
