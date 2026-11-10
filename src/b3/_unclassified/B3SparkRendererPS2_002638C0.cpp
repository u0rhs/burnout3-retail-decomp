// CB3SparkRenderer::BeginRender(int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fresh4: from scratch; head statement order, if/else-if chain, k=j-1 copy loop, XAxisType-float vsubx stand-in, N140 pad for frame).

// CB3SparkRenderer::BeginRender(int,bool) -- hand-written from scratch (the lifter refused it).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G]
// (instruction widths). Static: a0 is the player index (no `this`). One N140 pad: retail's frame keeps a 16-byte
// slot our build drops (likely the XAxisType temporary of the f[1] time read).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CB3CameraData { public: unsigned char pad_0[0x230]; };

class CB3SparkRenderer {
public:
    static void BeginRender(int, bool);
    static unsigned char mbIsCrash;
    static int mnRenderPlayer;
    static int mnNumRenderableArrays;
    static float mrMaxMotionBlurTime;
    class CSparkFrameData {
    public:
        void Set(const CB3CameraData *, float);
        u_long128 field_0;
        u_long128 field_10;
        u_long128 field_20;
        u_long128 field_30;
        u_long128 field_40;
        CGtV3d field_50;
    };
};

struct UnkStruct_002638C0_sf { CB3SparkRenderer::CSparkFrameData field_0[18]; };
struct UnkStruct_002638C0_pl { unsigned char pad_0[0x29980]; unsigned long field_29980; unsigned char pad_29988[0x1E]; unsigned char field_299A6; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x470]; CB3CameraData field_470[1]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BAC8 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA94 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };

extern unsigned char D_004EE040[];
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_0051BAC8 D_0051BAC8;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_002638C0_sf D_01E31A30[];
extern "C" int func_00131F60(void *);

// [G] XAxisType minus a float (no header API yet): retail `qmtc2.ni f, $vf2` hoisted, `vsubx.x a, a, $vf2x`
// (YAxisType's operator-(YAxisType, float) body on lane x).
static inline XAxisType func_002638C0_inl1(XAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return XAxisType(r);
}

struct UnkStruct_002638C0_pad { UnkStruct_002638C0_pad() {} ~UnkStruct_002638C0_pad() {} unsigned char pad_0[0x10]; };
// 0x002638C0
void CB3SparkRenderer::BeginRender(int player, bool crash)
{
    UnkStruct_002638C0_pad g0;  // N140 [G]: retail's frame keeps one more 16-byte slot
    UnkStruct_002638C0_pl *pl = (UnkStruct_002638C0_pl *)(D_004EE040 + player * 0xBB0);
    int i;
    int st = pl->field_299A6;
    const CB3CameraData *cam = &D_00665EC0.field_470[D_00667050.field_0];
    mbIsCrash = crash;
    mnRenderPlayer = player;
    mnNumRenderableArrays = 0;
    mrMaxMotionBlurTime = 0.0f;
    float t = D_00522680.field_0;
    float dt = D_0051BAC8.field_0;
    if (D_0051BA94.field_0 != -1) {
        if ((pl->field_29980 & 1) != 0) {
            for (i = 0; i < 18; i++) {
                D_01E31A30[mnRenderPlayer].field_0[i].Set(cam, t);
                t -= dt;
            }
        }
    } else if (st != 0) {
        for (i = 0; i < 18; i++) {
            D_01E31A30[mnRenderPlayer].field_0[i].Set(cam, t);
        }
    } else {
        CSparkFrameData *f = D_01E31A30[player].field_0;
        if (!(t - (float)f[1].field_50.X() < 0.01041666698f)) {
            int j = 17;
            int k;
            do {
                k = j - 1;
                f[j] = f[k];
                j = k;
            } while (k > 0);
        }
        f[0].Set(cam, t);
        if (func_00131F60(D_004EE040)) {
            float k5 = 0.5f;
            float h = dt * k5;
            CSparkFrameData *g = D_01E31A30[mnRenderPlayer].field_0;
            for (i = 1; i < 18; i++) {
                g[i].field_50.SetX(func_002638C0_inl1(g[i].field_50.X(), h));
            }
        }
    }
}
