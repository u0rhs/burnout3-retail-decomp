// NONMATCHING: func_002F2E70 -- retail 404 / ours 411 instructions, 335 in changed runs
// draftAO (2026-11-01): reviewed complete against retail 0x2F2E70..0x2F34BC (10 params: a, b, c, mesh, outAvg, outNormal, outId, outMin, stack outMax / outT); scoped inline_depth(3) dropped (it left XAxisType's copy ctor out of line: a call retail lacks); axis tests unrolled per lane as retail with 0 - n; dead TransformVector of the face normal kept | Before: psweep: scoped #pragma inline_depth(3) [G] improves 539 -> 537 | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: call identical, every store, compare and branch sense checked; the box rows a->mRight/mUp are min/max



#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

extern CGtV3d D_004C4020;
extern CGtV3d D_004C4030;
extern float D_004E068C;
extern "C" int func_002BEDC0(CGtV3d *, int, const void *, CGtV3d *);

struct UnkStruct_002F2E70_tri { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_002F2E70_mesh {
    int field_0;
    UnkStruct_002F2E70_tri *field_4;
    unsigned short *field_8;
};

// 0x002F2E70
extern "C" bool func_002F2E70(const CGtMatrix3x4 *a, const CGtMatrix3x4 *b, const CGtMatrix3x4 *c, UnkStruct_002F2E70_mesh *mesh,
                               CGtV3d *outAvg, CGtV3d *outNormal, unsigned short *outId, CGtV3d *outMin, CGtV3d *outMax, CGtV3d *outT)
{
    CGtV3d sumPos;
    CGtV3d sumNormal;
    CGtV3d mn = D_004C4020;
    CGtV3d mx = D_004C4030;
    sumPos.Zero();
    sumNormal.Zero();
    outT->Zero();
    bool found = false;
    int count = 0;
    for (int j = 0; j < mesh->field_0; j++) {
        UnkStruct_002F2E70_tri *tri = &mesh->field_4[j];
        CGtV3d in[3];
        for (int k = 0; k < 3; k++) {
            in[k] = TransformPoint(*c, (&tri->field_0)[k]);
        }
        CGtV3d poly[32];
        int n = func_002BEDC0(poly, 0x20, a, in);
        if (n < 3) continue;
        found = true;
        CGtV3d sum = poly[0];
        sumNormal += tri->field_30;
        for (int k = 1; k < n; k++) {
            mn = Min(mn, poly[k]);
            mx = Max(mx, poly[k]);
            sum += poly[k];
        }
        sum = sum * (1.0f / (float)n);
        TransformVector(*c, tri->field_30);   // retail computes this and drops it (vf1 overwritten) [C] 0x2F3030..0x2F3040
        sumPos += TransformPoint(*b, sum);
        count++;
        *outId = mesh->field_8[j];
    }
    if (!found) return false;
    if (outMin) *outMin = mn;
    if (outMax) *outMax = mx;
    if (sumNormal.IsEffectivelyZero()) return false;     // squared length < 2^-32 [C] 0x2F310C
    sumNormal.Normalise();
    *outNormal = sumNormal;
    CGtV3d nrm = sumNormal;
    CGtV3d avg = sumPos * (1.0f / (float)count);
    *outAvg = avg;
    CGtV3d n2 = TransformVector(*c, sumNormal);
    CGtV3d p = TransformPoint(*c, avg);
    // per axis (retail 0x2F31E8..0x2F3330): the distance from p to the face of box a (min row mRight, max row mUp)
    // the normal points away from, and |n| on that axis; l and h are stack vectors with only x/y/z set
    float l[3], h[3];
    if (n2.X() < 0.0f) {
        h[0] = 0.0f - (float)n2.X();     // vsub.x d, vf0, n
        l[0] = a->mRight.X() - p.X();
    } else {
        l[0] = p.X() - a->mUp.X();
        h[0] = n2.X();
    }
    if (n2.Y() < 0.0f) {
        h[1] = 0.0f - (float)n2.Y();     // vsub.y d, vf0, n
        l[1] = a->mRight.Y() - p.Y();
    } else {
        l[1] = p.Y() - a->mUp.Y();
        h[1] = n2.Y();
    }
    if (n2.Z() < 0.0f) {
        h[2] = 0.0f - (float)n2.Z();     // vsub.z d, vf0, n
        l[2] = a->mRight.Z() - p.Z();
    } else {
        l[2] = p.Z() - a->mUp.Z();
        h[2] = n2.Z();
    }
    float t;
    if (l[0] * h[1] < l[1] * h[0]) {
        if (l[0] * h[2] < l[2] * h[0]) t = l[0] / h[0];
        else t = l[2] / h[2];
    } else {
        if (l[1] * h[2] < l[2] * h[1]) t = l[1] / h[1];
        else t = l[2] / h[2];
    }
    if (t < D_004E068C) t = D_004E068C;
    *outT = nrm * t;
    return true;
}

