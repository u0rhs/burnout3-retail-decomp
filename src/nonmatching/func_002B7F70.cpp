// NONMATCHING: func_002B7F70 -- retail 539 / ours 542 instructions, 312 in changed runs
// fix2 (2026-11-01): decomp1 2026-11-06: the four Zero() accumulators zero w too (retail's w is a stale VU lane, 0x2B7F7C; host determinism) | Before: fix3 (2026-11-01): whole function drafted from retail (fallback-direction path, push bend > 60 deg, outputs +0xB0..+0xE0/+0x120/+0x130; clipped[32], local-normal push, unsigned count) | Before: fix2: gp globals renamed; skeleton (second half sketched)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm, every branch, store and call accounted for (behaviour_audit quiet; the Zero() accumulators' w, a stale VU lane in retail, is 0 here: func_002B7F70_inl2)


// func_002B7F70 -- [G] candidate name CB3ConvexHullCollide::DoCollideHullTriangles(CB3HullWorldTriCollideParams*,
// CB3ConvexHullCollideInfo*) (research/retail_names.csv 0x2B7F70, "low, direct:order+sim"; E maps 0x5D4..0x940 vs retail 0x86C;
// no Revenge counterpart), so the asm label stays. Caller: CB3ConvexHullCollide::CollideBodyHullWithWorld 0x2B9470
// (a0 = the params object it fills, a1 = &D_01E83670; its a2 is not read here) [C retail 0x2B7F8C overwrites a2 first].
// What it does [L, from the asm]: every triangle of the params' face table (field_F0) is transformed by the 3x4 matrix at
// +0x70 and clipped against the hull's planes (func_002BEDB0 -> func_00272EA0, a VU0 microprogram; returns the clipped
// vertex count, 0 below 3). For each surviving face: the clipped points' box (lo, hi), its centre, the face normal rotated by
// +0x70 (summed), the centre (summed), the hull penetration from the centre along -normal (func_002B7DB0 =
// GetHullPenetration(int*,CB3ConvexHull*,CGtV3d,CGtV3d) [L E map]) times the face's local normal (summed), the face's
// halfword tag (kept from the last hit) and the overall box. Afterwards: average normal; if it is too short
// (|n|^2 < 0.0225) the params' own direction (+0x100) is used and the penetration re-measured from the average centre
// (flag +0x111 = 1), else the normalised average rotated by the +0x30 matrix is the result normal (+0x111 = 0). If the
// summed push (B) is longer than 0.2 and turns more than 60 degrees from the result normal, it is bent halfway towards
// that normal (sum of the unit vectors, rescaled to half its length). Outputs: +0xB0 centre (through the +0x30 matrix),
// +0xC0 normal, +0xD0 average push, +0xE0 tag, +0x120/+0x130 box; returns 1, or 0 (+0x111 = 0) when no face survived.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [G] CB3ConvexHull-like: the object func_002B7DB0 reads (planes at +4, plane count at +0x19)
struct UnkStruct_002B7F70_hd {
    unsigned char pad_0[4];
    CGtPlane * field_4;             // [L] plane table (func_002B7DB0 / func_00272EA0 read it as {count, planes})
    unsigned char pad_8[0x11];
    unsigned char field_19;         // [L] plane count
};
// [G] one face entry, 0x40 bytes: three vertices then the face normal [C stride `sll s5, s2, 6`, normal at +0x30]
struct UnkStruct_002B7F70_face {
    CGtV3d field_0[3];
    CGtV3d field_30;
};
struct UnkStruct_002B7F70_faces {
    int field_0;                         // face count [C reloaded every pass, 0x2B823C]
    UnkStruct_002B7F70_face * field_4;
    unsigned short * field_8;            // per-face halfword tag [C lhu 0x2B8210]
};
// a0: the params object CollideBodyHullWithWorld fills (its include/b3/classes/CB3ConvexHullCollide.h layout: field_0,
// field_30..A0, field_F0, field_F4, field_100, field_111); the outputs B0..E0 and 120/130 are added here [C offsets below].
struct UnkStruct_002B7F70_hull {
    UnkStruct_002B7F70_hd * field_0;
    unsigned char pad_4[0x2C];
    CGtMatrix3x4 field_30;          // result frame [C rows +0x30..+0x60 read at 0x2B8340, 0x2B8680]
    CGtMatrix3x4 field_70;          // face-vertex frame [C rows +0x70..+0xA0, 0x2B8028..0x2B8040]
    CGtV3d field_B0;                // out: centre [C sq 0xB0(a1) 0x2B86B0]
    CGtV3d field_C0;                // out: normal [C 0x2B8364 / 0x2B8738]
    CGtV3d field_D0;                // out: average push [C 0x2B801C (zero), 0x2B86E0]
    unsigned short field_E0;        // out: tag [C sh 0x2B86CC]
    unsigned char pad_E2[0xE];
    UnkStruct_002B7F70_faces * field_F0;
    void * field_F4;
    unsigned char pad_F8[8];
    CGtV3d field_100;               // fallback direction [C lq 0x100(s4) 0x2B86F0]
    unsigned char pad_110[1];
    unsigned char field_111;        // out: 1 = fallback direction used [C sb 0x2B82FC / 0x2B8730 / 0x2B87A0]
    unsigned char pad_112[0xE];
    CGtV3d field_120;               // out: box min [C sq 0x120(s4) 0x2B86E4]
    CGtV3d field_130;               // out: box max [C sq 0x130(s4) 0x2B86EC]
};
// a1 = &D_01E83670 [C caller 0x2B9470]
struct UnkStruct_002B7F70_ctx {
    unsigned char pad_0[0x1360];
    int field_1360;
    int field_1364;
    UnkStruct_002B7F70_hull * field_1368;
    unsigned char pad_136C[4];
    UnkStruct_002B7F70_hull * field_1370;
    unsigned char pad_1374[4];
    UnkStruct_002B7F70_hd * field_1378;
    unsigned char pad_137C[4];
    int field_1380;
    int field_1384;
};
// the plane set func_00272EA0 clips against: {count, planes} [C 0x2B8090/0x2B8098; func_00272EA0 lw 0/4(a2)]
struct UnkStruct_002B7F70_clip {
    unsigned int field_0;
    CGtPlane * field_4;
};

extern CGtV4d D_004C1BB0;        // [C sinit func_004D5FD0] (-1000, -1000, -1000): box max start
extern CGtV4d D_004C1BC0;        // [C sinit func_004D5FD0] (1000, 1000, 1000): box min start
extern float D_004E0694;         // [C ELF] 0.0225 (0x3CB851EC)
extern float D_004E0698;         // [C ELF] 0.2 (0x3E4CCCCD)
extern float D_004E069C;         // [C ELF] 57.29578 (rad -> deg)
// [C retail] returns func_00272EA0's vertex count (v0); the matched src/b3/_unclassified/func_002BEDB0.cpp declares it void
extern "C" int func_002BEDB0(const CGtV3d *, int, const UnkStruct_002B7F70_clip *, CGtV3d *);
extern "C" float func_002B7DB0(int *, const UnkStruct_002B7F70_hd *, CGtV3d, CGtV3d);
extern "C" float func_0011E328(float);  // [L] acosf (E_B3DEBUG map: LIBM.A wf_acos.o)

// [C 0x2B80D4] `vmaddw.xyz $vf2, $vf1, $vf0w` lands in the vertex's own register: the transformed point keeps the vertex's w
static inline CGtV3d func_002B7F70_inl1(const CGtMatrix3x4 & m, CGtV3d v)
{
    CGtV4d r(TransformPoint(m, v).mData);
    CGtV4d s(v.mData);
    r.f[3] = s.f[3];
    return CGtV3d(r.mData);
}

// [C 0x2B7F7C..0x2B7FD4] retail zeroes its four accumulators with `vadd.xyz $vfN, $vf0, $vf0` (CGtV3d::Zero): the w lane is
// whatever the register held at entry, a stale lane of the caller's VU state (vf1 / vf3 / vf2, then vf1 again), and it reaches
// game memory (+0xD0's w, 0x2B801C). Not reproducible in C; a host stack local in its place is undefined (native3: a VUBIND port
// build left navproof14's path here). The draft zeroes all four lanes instead (CGtV4d::Zero): equal to retail on x/y/z, w = 0
// deterministic [L: no reader of these w lanes found; retail's own w is not fixed either] (decomp1 2026-11-06).
static inline CGtV3d func_002B7F70_inl2()
{
    CGtV4d z;
    z.Zero();
    return CGtV3d(z.mData);
}

// 0x002B7F70
extern "C" int func_002B7F70(UnkStruct_002B7F70_hull * hull, UnkStruct_002B7F70_ctx * ctx)
{
    // the four zeros: retail `vadd.xyz $vfN, $vf0, $vf0` with a stale w [C 0x2B7F7C..0x2B7FD4]; w = 0 here (func_002B7F70_inl2)
    CGtV3d nsum = func_002B7F70_inl2();     // sp+0x260: sum of the rotated face normals
    CGtV3d push = func_002B7F70_inl2();     // sp+0x210: sum of penetration * local face normal
    CGtV3d csum = func_002B7F70_inl2();     // sp+0x270: sum of the face centres
    CGtV3d dzero = func_002B7F70_inl2();
    CGtV3d bmin = CGtV3d(D_004C1BC0.mData);
    CGtV3d bmax = CGtV3d(D_004C1BB0.mData);
    unsigned int count = 0;
    unsigned short tag;
    int idx;
    UnkStruct_002B7F70_clip planes;
    CGtPlane * planeTable = hull->field_0->field_4;     // [C read before the stores below, 0x2B7FE8]

    ctx->field_1360 = 0;
    ctx->field_1364 = 0;
    ctx->field_1380 = 0;
    ctx->field_1384 = -1;
    ctx->field_1370 = hull;
    ctx->field_1378 = hull->field_0;
    ctx->field_1368 = hull;
    ctx->field_1370->field_D0 = dzero;

    CGtMatrix3x4 m = ctx->field_1370->field_70;          // rows held in registers / stack across the loop [C 0x2B8028..]
    UnkStruct_002B7F70_faces * faces = ctx->field_1368->field_F0;

    for (int i = 0; i < faces->field_0; i++) {
        CGtV3d tri[3];
        CGtV3d clipped[32];                              // sp+0x280..0x480
        planes.field_0 = hull->field_0->field_19;        // [C reloaded each pass 0x2B807C]
        planes.field_4 = planeTable;
        UnkStruct_002B7F70_face * face = &faces->field_4[i];
        for (int k = 0; k < 3; k++)
            tri[k] = func_002B7F70_inl1(m, face->field_0[k]);
        int n = func_002BEDB0(tri, 3, &planes, clipped);
        if (n == 0)
            continue;
        CGtV3d wn = TransformVector(m, faces->field_4[i].field_30);
        CGtV3d lo = clipped[0];
        CGtV3d hi = clipped[0];
        for (int k = 1; k < n; k++) {
            lo = Min(lo, clipped[k]);
            hi = Max(hi, clipped[k]);
        }
        CGtV3d mid = (lo + hi) * 0.5f;
        csum += mid;
        nsum += wn;
        float pen = func_002B7DB0(&idx, ctx->field_1378, mid, -wn);
        count++;
        push += faces->field_4[i].field_30 * pen;        // the LOCAL normal [C lqc2 0x30(a0) 0x2B81FC]
        tag = faces->field_8[i];
        bmin = Min(lo, bmin);                            // [C 0x2B8218: w from lo's register]
        bmax = Max(hi, bmax);                            // [C 0x2B822C: w from hi's register]
    }

    if (count == 0) {
        hull->field_111 = 0;
        return 0;
    }

    float inv = 1.0f / (float)count;                     // unsigned conversion [C bltz/srl path 0x2B825C]
    csum = csum * inv;
    CGtV3d navg = nsum * inv;
    CGtV3d dir;                                          // sp+0x100
    if ((float)navg.GetSquaredLength() < D_004E0694) {   // [C c.lt.s; bc1t 0x2B82EC]
        dir = hull->field_100;
        CGtV3d v = TransformVector(m, dir);
        hull->field_111 = 1;
        ctx->field_1370->field_C0 = dir;
        float pen = func_002B7DB0(&idx, ctx->field_1378, csum, v);
        push = dir * pen * (float)count;
    } else {
        hull->field_111 = 0;
        dir = navg;
        dir.Normalise();
        UnkStruct_002B7F70_hull * h = ctx->field_1370;
        h->field_C0 = TransformVector(h->field_30, dir);
    }

    // [C 0x2B83B4] skip when |push| <= 0.2, or the direction is effectively zero (2^-32, 0x2B83F0)
    if (!((float)push.GetLength() <= D_004E0698) && !dir.IsEffectivelyZero()) {
        CGtV3d rn = TransformVector(ctx->field_1370->field_30, dir);     // sp+0x1A0
        CGtV3d pn = push; pn.Normalise();
        CGtV3d rnn = rn; rnn.Normalise();
        float angle = D_004E069C * func_0011E328((float)CosAngleBetweenNormalisedVectors(pn, rnn));
        if (!(angle <= 60.0f)) {                         // [C c.le.s; bc1t 0x2B8518]
            float len = (float)push.GetLength();
            CGtV3d a = rn; a.Normalise();
            CGtV3d b = push; b.Normalise();
            b += a;
            push = b;                                    // stored before the zero test [C sqc2 0x2B85E8]
            if (!push.IsEffectivelyZero()) {
                push.Normalise();
                push = push * (0.5f * len);
            }
        }
    }

    UnkStruct_002B7F70_hull * h = ctx->field_1370;
    h->field_B0 = TransformPoint(h->field_30, csum);
    ctx->field_1370->field_E0 = tag;
    ctx->field_1370->field_D0 = push * inv;
    hull->field_120 = bmin;
    hull->field_130 = bmax;
    return 1;
}
