// NONMATCHING: Render__20CB3CarViewerGameModeFv -- retail 279 / ours 264 instructions, 181 in changed runs
// N253: header CGtMatrix3x4::operator* (retune3); 198->181
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: Render__20CB3CarViewerGameModeFv -- retail 279 / ours 262 instructions, 198 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: v300 first draft, logic decoded: char z[4]={0} + func_001E1FF0, UpdateViewport, func_002768F0 x D_004E197C, early return on field_22D, field_228==2 -> CB3VehicleDeform::Render, else 120 CB3Im3dVertex (w=0 ctor loop), red/yellow CGtV4d, 8 arrows from bone matrices (+0x700) and 6x2 from matrix product
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3CarViewerGameMode::Render() -- hand-written (v300); the lifter refused it. [C] name: the mangled symbol in
// retail's tables; file: research/retail_names.csv -> B3CarViewerGameMode.cpp. Area not evidenced, so _unclassified/.
// Field names are placeholders; every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] N185: compiler-chosen stand-ins (retail: vadd/vsub/vmulx on compiler-chosen registers)
static inline CGtV3d func_0024D520_add(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_0024D520_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_0024D520_neg(const CGtV3d &a) { u_long128 t; asm("vsub.xyz %0, $vf0, %1" : "=j"(t) : "j"(a.mData)); return CGtV3d(t); }
static inline CGtV3d func_0024D520_mul(const CGtV3d &a, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s)); return CGtV3d(t); }
// [L] N185: CGtMatrix3x4 product (rows of a through b)
static inline CGtMatrix3x4 func_0024D520_mm(const CGtMatrix3x4 &a, const CGtMatrix3x4 &b)
{
    CGtMatrix3x4 r;
    u_long128 t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddz.xyz %0, %4, %2z" : "=j"(t) : "j"(b.mRight.mData), "j"(a.mRight.mData), "j"(b.mUp.mData), "j"(b.mAt.mData));
    r.mRight.mData = t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddz.xyz %0, %4, %2z" : "=j"(t) : "j"(b.mRight.mData), "j"(a.mUp.mData), "j"(b.mUp.mData), "j"(b.mAt.mData));
    r.mUp.mData = t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddz.xyz %0, %4, %2z" : "=j"(t) : "j"(b.mRight.mData), "j"(a.mAt.mData), "j"(b.mUp.mData), "j"(b.mAt.mData));
    r.mAt.mData = t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddaz.xyz $ACC, %4, %2z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(b.mRight.mData), "j"(a.mPos.mData), "j"(b.mUp.mData), "j"(b.mAt.mData), "r"(b.mPos.mData));
    r.mPos.mData = t;
    return r;
}

struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[0x10];
    // [L] CB3Im3dVertex::CB3Im3dVertex() (B3O0PCH map); [G] body: w = 0 (as B3VehicleDeform_00460A50.cpp)
    CB3Im3dVertex() { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(0.0f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(field_0.mData) : "j"(s)); }
};
class CGtTexture;
extern "C" void BeginRendering__6B3Im3dFv();
extern "C" void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
extern "C" void RenderLinelist__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
extern "C" void EndRendering__6B3Im3dFv();
extern "C" void func_001E1FF0(int, void *, int);
extern "C" void func_002768F0(void *);
extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *, int);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void Render__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, void *, void *);
struct UnkStruct_D_00666228 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00666228 D_00666228;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00522660 D_00522660;
extern int D_004E197C;
struct UnkStruct_0024D520_ep {
    unsigned char pad_0[0xA70];
    float field_A70[8];
    float field_A90[6][2];
};
struct UnkStruct_0024D520_vp {
    unsigned char pad_0[0x180 - 0x80];
    CGtMatrix3x4 field_180[6];
    unsigned char pad_300[0x700 - 0x300];
    CGtMatrix3x4 field_700[8];
    unsigned char pad_900[0xC00 - 0x900];
    CGtMatrix3x4 field_C00[6][2];
};
struct UnkStruct_0024D520_g {
    unsigned char pad_0[0x40];
    UnkStruct_0024D520_ep *field_40;
    unsigned char pad_44[0x3C];
    UnkStruct_0024D520_vp field_80;
};
extern UnkStruct_0024D520_g *D_0064D388;

class CB3CarViewerGameMode {
public:
    void Render();
    void SetArrowVertices(CB3Im3dVertex *v, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d d, CGtV4d col);
    unsigned char pad_0[0x228];
    int field_228;
    unsigned char pad_22C;
    unsigned char field_22D;
};

// 0x0024D520
void CB3CarViewerGameMode::Render()
{
    char z[4] = {0};
    func_001E1FF0(D_00666228.field_0, z, 3);
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(&D_00665EC0, 1);
    for (int i = 0; i < D_004E197C; i++) func_002768F0(&D_00522660);
    UnkStruct_0024D520_g *g = D_0064D388;
    UnkStruct_0024D520_ep *ep = g->field_40;
    UnkStruct_0024D520_vp *vp = &g->field_80;
    if (field_22D == 0) return;
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, 1);
    if (field_228 == 2) {
        Render__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams((char *)vp + 0x300, g, vp);
    } else {
        CB3Im3dVertex verts[120];
        CGtV4d red(255.0f, 0.0f, 0.0f, 255.0f);
        CGtV4d yellow(255.0f, 255.0f, 0.0f, 255.0f);
        float k1 = 0.2f;
        float k2 = 0.3f;
        int n = 0;
        for (int i = 0; i < 8; i++) {
            CGtMatrix3x4 &m = vp->field_700[i];
            CGtV3d tip = func_0024D520_add(m.mPos, func_0024D520_mul(m.mAt, ep->field_A70[i]));
            SetArrowVertices(&verts[n], m.mPos, tip,
                func_0024D520_add(tip, func_0024D520_mul(func_0024D520_mul(func_0024D520_sub(m.mRight, m.mAt), k1), k2)),
                func_0024D520_add(tip, func_0024D520_mul(func_0024D520_mul(func_0024D520_sub(func_0024D520_neg(m.mRight), m.mAt), k1), k2)),
                red);
            n += 6;
        }
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 2; k++) {
                CGtMatrix3x4 m = ((vp->field_C00[j][k]) * (vp->field_180[j]));
                CGtV3d tip = func_0024D520_add(m.mPos, func_0024D520_mul(m.mAt, ep->field_A90[j][k]));
                SetArrowVertices(&verts[n], m.mPos, tip,
                    func_0024D520_add(tip, func_0024D520_mul(func_0024D520_mul(func_0024D520_sub(m.mRight, m.mAt), k1), k2)),
                    func_0024D520_add(tip, func_0024D520_mul(func_0024D520_mul(func_0024D520_sub(func_0024D520_neg(m.mRight), m.mAt), k1), k2)),
                    yellow);
                n += 6;
            }
        }
        BeginRendering__6B3Im3dFv();
        SetTexture__6B3Im3dFP10CGtTexture(0);
        RenderLinelist__6B3Im3dFPC13CB3Im3dVertexi(verts, n);
        EndRendering__6B3Im3dFv();
    }
    CloseViewport__22CB3GraphicsManagerBaseFv(&D_00665EC0);
}
