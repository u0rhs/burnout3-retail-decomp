// NONMATCHING: ClipEdgesByHull__20CB3ConvexHullCollideFPQ29GtMathPs26CGtV3diPQ29GtMathPs26CGtV3dUiPQ29GtMathPs28CGtPlaneUi -- retail 121 / ours 119 instructions, 83 in changed runs
// ghvu5: logic complete (ping-pong ClipEdgesByPlane over D_01E84A00[2][120], epsilon dedupe; VU ops/registers match). Left (83, mostly renumbering): retail keeps cur and nxt in separate saved registers (6 s-regs: s4=out, s5=nPlanes, s3=planes, s1=cur, s0=nxt), ours 5; retail lays the Y/Z lane tests inline with X failing to k++ (ours out of line; nested/continue/goto forms and scoped repositioncode off do not move it); retail re-enters d via qmtc2 a1,vf1 and sqc2 for the Y copy (ours sq a1); frame 0xC0 vs 0xB0.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3ConvexHullCollide::ClipEdgesByHull(GtMathPs2::CGtV3d*, int, GtMathPs2::CGtV3d*, unsigned int, GtMathPs2::CGtPlane*,
// unsigned int) -- hand-written (ghvu5). [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv
// -> B3ConvexHullCollide.cpp. Area not evidenced, so _unclassified/ (docs/conventions.md). Types [G].
// [G] clips the edge list by every plane, ping-ponging between two static buffers, then copies out the points that are
// not within 1e-7 (per lane) of one already copied. The int second parameter is not read.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern CGtV3d D_01E84A00[2][120];   // [G] two 0x780-byte point buffers
// By-value CGtPlane parameter: retail passes the element's address with no copy (a66 link-name form).
extern "C" unsigned int ClipEdgesByPlane__20CB3ConvexHullCollideFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dUiQ29GtMathPs28CGtPlane(
    CGtV3d *dst, CGtV3d *src, unsigned int n, const void *pl);
class CB3ConvexHullCollide {
public:
    static unsigned int ClipEdgesByHull(CGtV3d *out, int n, CGtV3d *in, unsigned int nIn, CGtPlane *planes, unsigned int nPlanes);
};
// [L] N185: GtMathPs2::Abs(CGtV3d) (B3O0PCH map, 60 bytes) and CGtV3d::operator-=(float) (76 bytes), compiler-chosen
static inline CGtV3d func_002B7A00_inl1(CGtV3d v) { u_long128 r; asm("vabs.xyz %0, %1" : "=j"(r) : "j"(v.mData)); return CGtV3d(r); }
static inline void func_002B7A00_inl2(CGtV3d &v, float f)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.xyz %0, %0, %1x" : "+j"(v.mData) : "j"(s));
}
// 0x002B7A00
unsigned int CB3ConvexHullCollide::ClipEdgesByHull(CGtV3d *out, int n, CGtV3d *in, unsigned int nIn, CGtPlane *planes, unsigned int nPlanes)
{
    unsigned int cnt = ClipEdgesByPlane__20CB3ConvexHullCollideFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dUiQ29GtMathPs28CGtPlane(D_01E84A00[0], in, nIn, &planes[0]);
    int cur = 0;
    for (unsigned char i = 1; i < nPlanes && cnt >= 2; i++) {
        int nxt = 1 - cur;
        cnt = ClipEdgesByPlane__20CB3ConvexHullCollideFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dUiQ29GtMathPs28CGtPlane(D_01E84A00[nxt], D_01E84A00[cur], cnt, &planes[i]);
        cur = nxt;
    }
    CGtV3d *src = D_01E84A00[cur];
    unsigned int outN = 0;
    for (unsigned int j = 0; j < cnt; j++) {
        bool dup = false;
        for (unsigned int k = 0; k < outN; k++) {
            CGtV3d d = func_002B7A00_inl1(src[j] - out[k]);
            func_002B7A00_inl2(d, 1e-07f);
            if (d.X() < 0.0f && d.Y() < 0.0f && d.Z() < 0.0f) {
                dup = true;
                break;
            }
        }
        if (!dup) out[outN++] = src[j];
    }
    return outN;
}

