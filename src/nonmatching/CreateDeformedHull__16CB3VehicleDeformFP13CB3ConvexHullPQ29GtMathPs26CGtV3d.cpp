// NONMATCHING: CreateDeformedHull__16CB3VehicleDeformFP13CB3ConvexHullPQ29GtMathPs26CGtV3d -- retail 143 / ours 142 instructions, 56 in changed runs
// logic/loop/frame right (top-tested goto loop, n Set(0,0,1) or Normalise in place, 0x90 N140 pad); left: VU numbering (retail a/n vf3, e1 vf4, consts vf8/vf7/vf6/vf2/vf5) and the cross->n GPR round trip -- the .i move-out form gives retail's trip but b119 then parks the square (qmfc2/qmtc2) before vadday. Header gaps: XAxisType unary minus, compiler-chosen Normalise, cross with result on first operand
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehicleDeform::CreateDeformedHull -- hand-matched (ghvu8).
#include "b3/GtMathPs2.h"
#include "b3/classes/CB3ConvexHull.h"

using namespace GtMathPs2;

// [G] the hull's arrays as this function reads them
struct UnkStruct_003D9C50_h {
    unsigned char *field_0;     // 3 vertex indices per face
    CGtPlane *field_4;          // one plane per face
    CGtV3d *field_8;            // vertices
    unsigned char pad_C[0xC];
    unsigned char field_18;     // vertex count
    unsigned char field_19;     // face count
};

// [G] 0x20-byte vertex records handed to the hull maker (CB3ConvexHullVertex)
struct UnkStruct_003D9C50_v {
    CGtV3d field_0;
    unsigned char pad_10[0x10];
};

// [G] N140: dead 16-byte frame slots between the vertex records and the normal
struct UnkStruct_003D9C50_pad { int x[36]; UnkStruct_003D9C50_pad() {} ~UnkStruct_003D9C50_pad() {} };

class CB3VehicleDeform {
public:
    void CreateDeformedHull(CB3ConvexHull *hull, CGtV3d *pts);
    unsigned char pad_0[0x28];
    float field_28[1];
};

extern "C" void GetHullPoints__16CB3VehicleDeformFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dP13CB3ConvexHullPQ29GtMathPs26CGtV3d(
    CB3VehicleDeform *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *,
    CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CB3ConvexHull *, CGtV3d *);
extern "C" void MakeConvexHull__18CB3ConvexHullMakerFP13CB3ConvexHullPfP19CB3ConvexHullVertex(void *, CB3ConvexHull *, float *, void *);
extern __declspec(sdata) unsigned char mHullMaker__16CB3VehicleDeform[];

// [L] N185: a x b with the result on a's register (retail's vopmula/vopmsub operand order), out through a GPR
static inline CGtV3d CreateDeformedHull_inl1(CGtV3d a, CGtV3d b) {
    u_long128 t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.ni %0, %1" : "=r"(t), "+j"(a.mData) : "j"(b.mData));
    return CGtV3d(t);
}
// [L] N185: XAxisType unary minus (missing from the header), compiler-chosen
static inline XAxisType CreateDeformedHull_inl2(XAxisType x) {
    u_long128 r;
    asm("vsub.x %0, $vf0, %1" : "=j"(r) : "j"(x.lVector));
    return XAxisType(r);
}
// [L] N185: Normalise on a compiler-chosen register (the header's hard-codes $vf1), result out through a GPR
static inline void CreateDeformedHull_inl3(CGtV3d &v) {
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm("qmtc2.i %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(r) : "j"(v.mData));
    v.mData = r;
}

// 0x003D9C50
void CB3VehicleDeform::CreateDeformedHull(CB3ConvexHull *hull, CGtV3d *pts)
{
    UnkStruct_003D9C50_h *h = (UnkStruct_003D9C50_h *)hull;
    UnkStruct_003D9C50_v v[16];
    UnkStruct_003D9C50_pad pad;
    int i;
    for (i = 0; i < h->field_18; i++) {
        h->field_8[i] = pts[i];
    }
    i = 0;
top:
    if (!(i < h->field_19)) goto out;
    {
        unsigned char *f = &h->field_0[i * 3];
        int i0 = f[0];
        CGtV3d &a = h->field_8[i0];
        CGtV3d e1 = h->field_8[f[1]];
        e1 -= a;
        CGtV3d e2 = h->field_8[f[2]];
        e2 -= a;
        CGtV3d n = CreateDeformedHull_inl1(e2, e1);
        if (n.GetSquaredLength() < 2.3283064e-10f) {
            n.Set(0.0f, 0.0f, 1.0f);
        } else {
            CreateDeformedHull_inl3(n);
        }
        h->field_4[i].SetNormal(n);
        h->field_4[i].SetDistance(CreateDeformedHull_inl2(DotProduct(n, h->field_8[i0])));
        i++;
    }
    goto top;
out:
    GetHullPoints__16CB3VehicleDeformFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dP13CB3ConvexHullPQ29GtMathPs26CGtV3d(
        this, &v[0].field_0, &v[1].field_0, &v[2].field_0, &v[3].field_0, &v[4].field_0, &v[5].field_0, &v[6].field_0,
        &v[7].field_0, &v[8].field_0, &v[9].field_0, &v[10].field_0, &v[11].field_0, &v[12].field_0, &v[13].field_0,
        &v[14].field_0, &v[15].field_0, hull, pts);
    MakeConvexHull__18CB3ConvexHullMakerFP13CB3ConvexHullPfP19CB3ConvexHullVertex(mHullMaker__16CB3VehicleDeform, hull, field_28, v);
}
