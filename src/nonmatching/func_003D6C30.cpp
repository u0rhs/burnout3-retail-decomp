// NONMATCHING: func_003D6C30 -- retail 233 / ours 234 instructions, 73 in changed runs
// ghvu13: [L] the D-pad 2d object's _Render callback (CB3HUDDPad2dObject::Prepare passes it). 233/234, 73 off: prologue, weights (Max lanes, 1-t*t without madd), colour products + out-of-line func_001D4E80 / CGtV2d __as__ calls, Interpolate and both loops' logic match; left: the first strip loop's saved-register assignment (retail holds e in fp and spills &e[j] to 0xB0 across the __as__ call; ours spills e and keeps i*32 in s8), frame +0x20 from that, and pts[i] temp order. Do-while inner loops and held v[i]/uv[i] pointers are right (retail passes s6/s7 to RenderTriStripFlatTex). Note: B3HUDDPad2dObject_003D6BA0.cpp declares func_003D6C30 as data (address-taken callback).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D6C30 -- hand-written by ghvu13 from the Ghidra draft. [L] the D-pad 2d object's render callback: the address
// CB3HUDDPad2dObject::Prepare (0x3D6BA0) passes to CGt2dObject::Prepare. Unnamed in every table: placeholder with C
// linkage; _unclassified/. Field names are placeholders and every type is [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003D6C30_space { CGtV2d mTopLeftPos; CGtV2d mSize; CGtV4d mColour; };   // [L] CGt2dObject::CGt2dObjectSpace
struct UnkStruct_D_00645170 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0057BAF0 { unsigned char pad_0[0x1408]; float field_1408; float field_140C; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0066A4C0 { unsigned char pad_0[0x60]; CGtV4d field_60; };
class CGtTexture;
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_0057BAF0 D_0057BAF0;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern CGtV4d D_004CA900;
extern CGtV4d D_004CA910;
extern CGtV2d D_004CA8A0[7];
extern CGtV2d D_004CA860[8];
extern unsigned char D_004CA8E0[4][5];
extern CGtTexture *mpHUDAftertouchTexture__15CB3HUDComponent;
extern "C" void func_001D4E80(CGtV4d *, const CGtV4d *);   // [L] DNAT: CGtV4d::operator=(const CGtV4d&) out of line (new_names.csv, medium)
extern "C" void __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d(CGtV2d *, const CGtV2d *);   // CGtV2d::operator=(const CGtV2d&)
extern "C" void SetTexture__12Gt2dRendererFP10CGtTexture(CGtTexture *);
extern "C" void RenderTriStripFlatTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(const CGtV4d *, const CGtV2d &, int, const CGtV2d *, const CGtV2d *);
extern "C" void func_00217E70(int);

static inline UnkStruct_D_0057BAF0 *func_003D6C30_inl1() { return 0 < D_00645170.field_0 ? &D_0057BAF0 : 0; }

// 0x003D6C30
extern "C" void func_003D6C30(const UnkStruct_003D6C30_space &space, const void *data)
{
    int i;
    UnkStruct_D_0066A4C0 * const g = &D_0066A4C0;
    float x = func_003D6C30_inl1()->field_1408;
    float y = -func_003D6C30_inl1()->field_140C;
    float t = 2.0f * D_004F50A0.field_0;
    t = t - (float)(int)t;
    t *= t;
    float s = 1.0f - t;
    CGtV4d c0;
    CGtV4d c1;
    CGtV4d c;
    CGtV2d p[7];
    CGtV2d v[4][4];
    CGtV2d uv[4][4];
    float w[4];
    w[0] = GtMath::Max(-y, 0.0f);
    w[1] = GtMath::Max(y, 0.0f);
    w[2] = GtMath::Max(-x, 0.0f);
    w[3] = GtMath::Max(x, 0.0f);
    func_001D4E80(&c0, &(D_004CA900 * space.mColour));
    func_001D4E80(&c1, &(g->field_60 * space.mColour));
    for (i = 0; i < 7; i++) {
        __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d(&p[i], &(space.mSize * D_004CA8A0[i]));
    }
    SetTexture__12Gt2dRendererFP10CGtTexture(mpHUDAftertouchTexture__15CB3HUDComponent);
    for (i = 0; i < 4; i++) {
        const unsigned char *e = D_004CA8E0[i];
        int n = e[0];
        CGtV2d *vi = v[i];
        CGtV2d *ui = uv[i];
        CGtV2d *pv = vi;
        CGtV2d *pu = ui;
        int j = n;
        do {
            __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d(pv++, &p[e[j]]);
            __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d(pu++, &D_004CA860[e[j]]);
            j--;
        } while (j != 0);
        float a = s * w[i];
        w[i] = 0.0f + (a + a) - a * a;
        func_001D4E80(&c, &Interpolate(c0, c1, w[i]));
        RenderTriStripFlatTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(&c, space.mTopLeftPos, n, vi, ui);
    }
    func_00217E70(1);
    func_001D4E80(&c, &(D_004CA910 * space.mColour));
    for (i = 0; i < 4; i++) {
        if (w[i] > 0.01f) {
            int n = D_004CA8E0[i][0];
            CGtV2d *ui = uv[i];
            CGtV2d *vi = v[i];
            CGtV2d *pu = ui;
            int k = n;
            do {
                pu->marValues[0] = 1.0f - pu->marValues[0];
                k--;
                pu++;
            } while (k != 0);
            c.SetA(w[i] * w[i]);
            RenderTriStripFlatTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(&c, space.mTopLeftPos, n, vi, ui);
        }
    }
    func_00217E70(0);
}
