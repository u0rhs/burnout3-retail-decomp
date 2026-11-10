// NONMATCHING: Draw__12CB3CrashRampFP10CGtTexture -- retail 316 / ours 315 instructions, 62 in changed runs
// 62 changed, 315/316, frame 0x300/0x2F0: dead CGtV4d col local (stores + lq a0) not reproduced, vertex-ctor prologue scheduling; body blocks match
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3CrashRamp::Draw(CGtTexture*) -- v306 hand draft (lifter refused: pextlh). Six CB3Im3dVertex built on the stack,
// coloured from D_004C9C30 (0.5,0.5,0.5,1.0, set by sinit func_004DA3A0 [C]), drawn as 3+3+6+6 triangles; the last
// six depend on field_60->field_40 == 2. Vertex layout [G] (pos CGtV3dPlus, u, v, packed colour); UV values [C] asm.
// [L] CB3Im3dVertex ctor/SetColour bodies as RenderSquare (0x460A50). SetColour takes a const& here [G]: by value
// our build copies D_004C9C30 through a stack slot, retail lqc2's it directly.
// [G] SetGtV3d stand-in reads back through the address of its result (as func_002510F0_inl5): gives retail's 24
// dead 16-byte slots (one per vertex position set). Open: retail keeps a dead `CGtV4d(0.15,0.02,0.06,1.0)` local
// (four stores to 0x220 + a dead `lq a0`); the asm "r" use below keeps the stores but not the lq, adds a slot.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    float field_10;
    float field_14;
    unsigned int field_18;
    unsigned char pad_1C[4];
    // [L] CB3Im3dVertex::CB3Im3dVertex() (B3O0PCH map); [G] body: w = 0 (as RenderSquare, 0x460A50)
    CB3Im3dVertex() { field_0.SetPlus(0.0f); }
    // [L] CB3Im3dVertex::SetColour(GtMathPs2::CGtV4d) (B3O0PCH map, 0x44); body as RenderSquare (0x460A50)
    void SetColour(const CGtV4d &c) {
        u_long128 s0; asm("qmtc2.ni %1, $vf2" "\n\t" "vmulx.xyzw %0, %2, $vf2x" : "=j"(s0) : "r"(128.0f), "j"(c.mData)); CGtV4d s(s0);
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
extern "C" {
void BeginRendering__6B3Im3dFv();
void SetAlphaTestThreshold__6B3Im3dFf(float);
void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
void RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
void EndRendering__6B3Im3dFv();
}
struct UnkStruct_D_00665EA1 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_00665EA1 D_00665EA1;
extern CGtV4d D_004C9C30;
struct UnkStruct_003A1800_60 {
    unsigned char pad_0[0x40];
    int field_40;
};
class CB3CrashRamp {
public:
    void Draw(CGtTexture *tex);
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    CGtV3d field_40;
    CGtV3d field_50;
    UnkStruct_003A1800_60 *field_60;
};
static inline void func_003A1800_inl6(CGtV3dPlus &p, const CGtV3d &v) { u_long128 a = v.mData; u_long128 m = p.mData; asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(a)); p.mData = *(const u_long128 *)&m; }
// 0x003A1800
void CB3CrashRamp::Draw(CGtTexture *tex)
{
    CGtV4d col(0.15f, 0.02f, 0.06f, 1.0f);
    CB3Im3dVertex v[6];
    if (D_00665EA1.field_0 != 0) return;
    asm("qmtc2 %0, $vf1" : : "r"(col.mData));
    for (int i = 0; i < 6; i++) v[i].SetColour(D_004C9C30);
    BeginRendering__6B3Im3dFv();
    SetAlphaTestThreshold__6B3Im3dFf(0.5f);
    SetTexture__6B3Im3dFP10CGtTexture(tex);
    func_003A1800_inl6(v[0].field_0, field_50); v[0].field_10 = 1.0f; v[0].field_14 = 0.5f;
    func_003A1800_inl6(v[1].field_0, field_30); v[1].field_10 = 0.0f; v[1].field_14 = 1.0f;
    func_003A1800_inl6(v[2].field_0, field_10); v[2].field_10 = 1.0f; v[2].field_14 = 1.0f;
    RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(v, 3);
    func_003A1800_inl6(v[0].field_0, field_40); v[0].field_10 = 0.0f; v[0].field_14 = 0.5f;
    func_003A1800_inl6(v[1].field_0, field_0); v[1].field_10 = 0.0f; v[1].field_14 = 1.0f;
    func_003A1800_inl6(v[2].field_0, field_20); v[2].field_10 = 1.0f; v[2].field_14 = 1.0f;
    RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(v, 3);
    func_003A1800_inl6(v[0].field_0, field_50); v[0].field_10 = 0.0f; v[0].field_14 = 0.5f;
    func_003A1800_inl6(v[1].field_0, field_0); v[1].field_10 = 1.0f; v[1].field_14 = 1.0f;
    func_003A1800_inl6(v[2].field_0, field_10); v[2].field_10 = 0.0f; v[2].field_14 = 1.0f;
    func_003A1800_inl6(v[3].field_0, field_0); v[3].field_10 = 1.0f; v[3].field_14 = 1.0f;
    func_003A1800_inl6(v[4].field_0, field_40); v[4].field_10 = 1.0f; v[4].field_14 = 0.5f;
    func_003A1800_inl6(v[5].field_0, field_50); v[5].field_10 = 0.0f; v[5].field_14 = 0.5f;
    RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(v, 6);
    if (field_60->field_40 == 2) {
    func_003A1800_inl6(v[0].field_0, field_50); v[0].field_10 = 1.0f; v[0].field_14 = 0.0f;
    func_003A1800_inl6(v[1].field_0, field_20); v[1].field_10 = 0.0f; v[1].field_14 = 0.5f;
    func_003A1800_inl6(v[2].field_0, field_30); v[2].field_10 = 0.0f; v[2].field_14 = 0.0f;
    func_003A1800_inl6(v[3].field_0, field_50); v[3].field_10 = 1.0f; v[3].field_14 = 0.0f;
    func_003A1800_inl6(v[4].field_0, field_40); v[4].field_10 = 1.0f; v[4].field_14 = 0.5f;
    func_003A1800_inl6(v[5].field_0, field_20); v[5].field_10 = 0.0f; v[5].field_14 = 0.5f;
    } else {
    func_003A1800_inl6(v[0].field_0, field_50); v[0].field_10 = 1.0f; v[0].field_14 = 0.0f;
    func_003A1800_inl6(v[1].field_0, field_40); v[1].field_10 = 1.0f; v[1].field_14 = 0.5f;
    func_003A1800_inl6(v[2].field_0, field_30); v[2].field_10 = 0.0f; v[2].field_14 = 0.0f;
    func_003A1800_inl6(v[3].field_0, field_40); v[3].field_10 = 1.0f; v[3].field_14 = 0.5f;
    func_003A1800_inl6(v[4].field_0, field_20); v[4].field_10 = 0.0f; v[4].field_14 = 0.5f;
    func_003A1800_inl6(v[5].field_0, field_30); v[5].field_10 = 0.0f; v[5].field_14 = 0.0f;
    }
    RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(v, 6);
    EndRendering__6B3Im3dFv();
}
