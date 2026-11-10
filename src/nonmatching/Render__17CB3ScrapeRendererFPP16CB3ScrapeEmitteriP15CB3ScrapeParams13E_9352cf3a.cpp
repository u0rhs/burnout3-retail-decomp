// NONMATCHING: Render__17CB3ScrapeRendererFPP16CB3ScrapeEmitteriP15CB3ScrapeParams13EB3ScrapeType -- retail 161 / ours 160 instructions, 114 in changed runs
// v285 first draft (lifter refused): logic complete (160/161). Static (a0 = emitter array); CB3Im3dVertex[32] ctor loop (SetPlus(0) w=0, N216 bne) exact; GetFrameCount result unused; per segment: colour = lerp(params.field_0, field_10, fade=0) on compiler-chosen stand-in (t hoisted, b into a's reg, .i GPR round trip), width (f34 + z*(f38-f34))*0.5 adda/madd, two SetColour (v242 body), off = dir*w*karScrapeUVs[idx] then y += D_004E0FA0, SetGtV3d(pos -/+ off). Left: frame 0x4B0 vs 0x4F0 (4 dead 16-byte slots below the vertex array: probably SetColour/lerp by-value params), VU register numbering (retail uv vf9, fade vf10, k vf8, 128 in vf4/vf2; ours vf7/vf8/vf9/vf5/vf4) and the inner-loop schedule; D_004E0FA0 (0.0254) is gp-relative -- extern vs literal undecided.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// CB3ScrapeRenderer::Render: one tristrip per scrape emitter (2 vertices per trail segment, +-offset along the
// segment direction, colour lerped between the params' two colours). [G] meanings.
// [L] N185: stand-ins for GtMathPs2 inlines on compiler-chosen registers (retail hoists the scalars out of the loop).
static inline void func_00375F90_inl1(CGtV3dPlus &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline CGtV4d func_00375F90_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
static inline CGtV4d func_00375F90_lerp(const CGtV4d &a, CGtV4d b, float t)
{
    u_long128 tv, bv, r, rr;
    asm("qmtc2.ni %1, %0" : "=j"(tv) : "r"(t));
    asm("vaddax.xyzw $ACC, %0, $vf0x" "\n\t" "vmsubax.xyzw $ACC, %0, %1x" : : "j"(a.mData), "j"(tv));
    asm("qmtc2.i %1, %0" : "=j"(bv) : "r"(b.mData));
    asm("vmaddx.xyzw %0, %1, %2x" : "=j"(r) : "j"(bv), "j"(tv));
    asm("qmfc2.i %0, %1" : "=r"(rr) : "j"(r));
    return CGtV4d(rr);
}
class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    float field_10;
    float field_14;
    unsigned int field_18;
    unsigned char pad_1C[4];
    CB3Im3dVertex() { func_00375F90_inl1(field_0, 0.0f); }
    void SetColour(CGtV4d c) {
        CGtV4d s = func_00375F90_mul(c, 128.0f);
        u_long128 i, lim, m, h;
        unsigned int b;
        asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(s.mData));
        unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
        asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
        asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
        asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
        asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
        field_18 = b;
    }
};
struct UnkStruct_00375F90_seg { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_00375F90_trail { int field_0; unsigned char pad_4[0xC]; UnkStruct_00375F90_seg field_10[64]; };
class CB3ScrapeEmitter { public: int field_0; unsigned char pad_4[0x43C]; UnkStruct_00375F90_trail *field_440; };
class CB3ScrapeParams { public: CGtV4d field_0; CGtV4d field_10; unsigned char pad_20[0xC]; CGtTexture *field_2C; unsigned char pad_30[4]; float field_34; float field_38; };
enum EB3ScrapeType {};
extern float karScrapeUVs[5];
extern float D_004E0FA0;
extern "C" {
int GetFrameCount__8CGtTimerFv();
void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
void RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
}
class CB3ScrapeRenderer {
public:
    static void Render(CB3ScrapeEmitter **em, int n, CB3ScrapeParams *p, EB3ScrapeType type);
};
// 0x00375F90
void CB3ScrapeRenderer::Render(CB3ScrapeEmitter **em, int n, CB3ScrapeParams *p, EB3ScrapeType type)
{
    CB3Im3dVertex v[32];
    GetFrameCount__8CGtTimerFv();
    SetTexture__6B3Im3dFP10CGtTexture(p->field_2C);
    float fade = 0.0f;
    for (int i = 0; i < n; i++, em++) {
        CB3ScrapeEmitter *e = *em;
        float uv = karScrapeUVs[e->field_0];
        int k = e->field_440->field_0;
        if (k < 2) continue;
        for (int j = 0; j < k; j++) {
            UnkStruct_00375F90_seg *s = &e->field_440->field_10[j];
            CGtV4d col = func_00375F90_lerp(p->field_0, p->field_10, fade);
            float z = 0.0f;
            float w = (p->field_34 + z * (p->field_38 - p->field_34)) * 0.5f;
            float u = (float)(j & 1);
            CB3Im3dVertex *a = &v[j * 2];
            CB3Im3dVertex *b = &v[j * 2 + 1];
            a->SetColour(col);
            a->field_10 = u;
            a->field_14 = 0.0f;
            b->SetColour(col);
            CGtV3d off = s->field_10 * w * uv;
            u_long128 ty, kv;
            asm("qmtc2.ni %1, %0" : "=j"(kv) : "r"(D_004E0FA0));
            asm("vaddx.y %0, %1, %2x" : "=j"(ty) : "j"(off.mData), "j"(kv));
            off.SetY(YAxisType(ty));
            a->field_0.SetGtV3d(s->field_0 - off);
            b->field_0.SetGtV3d(s->field_0 + off);
            b->field_10 = u;
            b->field_14 = karScrapeUVs[e->field_0];
        }
        RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(v, k * 2);
    }
}
