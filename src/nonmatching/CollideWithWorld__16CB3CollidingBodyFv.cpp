// NONMATCHING: CollideWithWorld__16CB3CollidingBodyFv -- retail 456 / ours 469 instructions, 481 in changed runs
// fix2 (2026-11-01): hull path: the stack object is a CB3ConvexHullCollide called with the body itself as its params (the draft passed the stack object twice), and the contact position/normal/flags/+0x1A0/+0x1B0 and the 10th output are copied out of it as retail 0x1AB764..0x1AB7A8 (the draft copied 2 of 8, from wrong offsets); the end adds that 10th output (sp+0xA20), not field_1B0 [C] 0x1ABBDC | Before: psweep: scoped #pragma inline_depth(3) [G] improves 618 -> 485
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



// CB3CollidingBody::CollideWithWorld -- hand-written (son7) first archive. Collides the body against the world (either via
// func_002F2E70 for kind 1 bodies when D_004EB902 is set, or the convex hull test), then turns the contact into an impulse
// (restitution at +0x1F8, inverse mass at +0x1F0), friction / damping depending on the body kind (+0x215), accumulates into
// +0x110/+0x120 or +0xF0/+0x100 and finally damps +0xE0, flags +0x20E and adds the contact offset into +0x130. Written with
// GtMathPs2's CGtV3d operators [G]; the exact VU0 instruction sequence is not reproduced. Field names are placeholders and every
// type is [G].
#include "b3/GtMathPs2.h"
#include "b3/classes/CB3ConvexHullCollide.h"
#include "b3/classes/CB3HullWorldTriCollideParams.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;

struct UnkStruct_Cww_mat { unsigned char pad_0[0x10]; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_Cww_cache { int field_0; };
struct UnkStruct_Cww_hit { unsigned char pad_0[0x70]; };

class CB3CollidingBody {
public:
    void CollideWithWorld();
    unsigned char pad_0[0x40];
    CGtV3d field_40, field_50, field_60;
    CGtV3d field_70, field_80, field_90, field_A0;
    CGtV3d field_B0;      // linear velocity [G]; its w lane (+0xBC) is a speed-like scalar
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;      // angular velocity [G]
    CGtV3d field_E0;
    CGtV3d field_F0, field_100, field_110, field_120, field_130;
    u_long128 field_140;
    unsigned char pad_150[0x10];
    CGtV3d field_160;     // contact position [G]
    CGtV3d field_170;     // contact normal [G]
    u_long128 field_180;
    unsigned short field_190;
    unsigned char pad_192[2];
    float field_194;
    int field_198;
    unsigned char pad_19C[4];
    u_long128 field_1A0;
    u_long128 field_1B0;
    unsigned char pad_1C0[0x10];
    u_long128 field_1D0;
    unsigned char pad_1E0[0x10];
    float field_1F0;
    unsigned char pad_1F4[4];
    float field_1F8;
    unsigned char pad_1FC[4];
    UnkStruct_Cww_cache *field_200;
    UnkStruct_Cww_mat *field_204;
    unsigned char pad_208[4];
    unsigned char field_20C;
    unsigned char pad_20D;
    unsigned char field_20E;
    unsigned char pad_20F[3];
    unsigned char field_212;
    unsigned char field_213;
    unsigned char field_214;
    signed char field_215;
    unsigned char pad_216[0xA4];
    signed char field_2BA;
};
extern unsigned char D_004EB902;
extern const CGtV3d kGravity;
extern float D_004E06A0, D_004E06A4, D_004E06A8, D_004E06AC, D_004E06B0, D_004E06B4, D_004E06B8, D_004E06BC;
extern "C" float fabsf(float);
// the hull test's object on the stack (named, so a tool that moves escaping locals can see its type)
// [C] retail 0x1AB8BC / 0x1AB8C0 (qmtc2.ni, vaddx.x): a scalar added to an XAxisType on VU0 (no GtMathPs2 operator has it)
static inline XAxisType func_001AB6B0_addx(XAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return XAxisType(r);
}

// [C] retail 0x1ABA74..0x1ABAA0 / 0x1ABB30..0x1ABB54: the linear velocity and speed (+0xB0: xyz velocity, w speed) scaled
// by k -- xyz by vmulx.xyz then vadd.xyz $vf0 (a -0 becomes +0), w by vmulx.w (vmove.w into the stored register)
static inline void func_001AB6B0_scale_speed(CGtV3d &v, float k)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(k));
    asm("vmulx.xyz %0, %0, %1x" : "+j"(v.mData) : "j"(s));
    asm("vadd.xyz %0, $vf0, %0" : "+j"(v.mData));
    asm("vmulx.w %0, %0, %1x" : "+j"(v.mData) : "j"(s));
}

// [C] retail 0x1ABC70..0x1ABC88: the velocity's xyz scaled by k (vmulx.xyz, then vadd.xyz $vf0), its w (speed) kept
static inline void func_001AB6B0_scale_xyz(CGtV3d &v, float k)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(k));
    asm("vmulx.xyz %0, %0, %1x" : "+j"(v.mData) : "j"(s));
    asm("vadd.xyz %0, $vf0, %0" : "+j"(v.mData));
}

union UnkUnion_Cww_hull {
    CB3ConvexHullCollide hc;
    unsigned char raw[0x170];
};
extern "C" int CollideBodyHullWithWorld__20CB3ConvexHullCollideFP28CB3HullWorldTriCollideParamsP16CB3CollidingBody(void *self, void *params, void *body);
extern "C" signed char func_002F2E70(void *, UnkStruct_Cww_mat *, void *, UnkStruct_Cww_cache *, void *, void *, void *, void *, void *, void *);

// 0x001AB6B0
void CB3CollidingBody::CollideWithWorld()
{
    // fix2: [C] retail 0x1AB758..0x1AB7A8: a CB3ConvexHullCollide on the stack (sp+0x8D0, 0x150 bytes), called with the body
    // itself as the params (CB3CollidingBody starts with the CB3HullWorldTriCollideParams layout: +0x70.., +0x140, +0x200..+0x214);
    // the contact results are then copied out of it
    // 0x170: the room retail has from sp+0x8D0 to the frame end 0xA40 (the hull test writes past the 0x150 the reads
    // below use: the native port caught a write at +0x160)
    // fix5 (2026-11-09): the slot's previous contents. Without a contact the hull test leaves +0xB0..+0xE0 unwritten and
    // the copies below take what the stack slot sp+0x8D0 held -- on the PS2 normally the previous call's results (this
    // function is called again and again from the same depth); a fresh native local held only fill bytes, and the
    // native port's poison test showed crash rendering reads those copies. [L] closest to retail.
    static UnkUnion_Cww_hull prev;
    UnkUnion_Cww_hull h;
    u_long128 keep;
    field_213 = 0;
    if (field_200->field_0 == 0) {
        field_212 = 0;
        field_198 = 0;
        field_194 = 0.0f;
        return;
    }
    if (field_20C == 1 && D_004EB902 != 0) {
        field_212 = func_002F2E70(&field_1D0, field_204, &field_70, field_200, &field_160, &field_170, &field_190, &field_1A0, &field_1B0, &keep);
    } else {
        // by its C-linkage name with &h: the whole 0x170-byte object is the callee's (a member call through the header's
        // smaller CB3ConvexHullCollide view would hand over only that much)
        h = prev;
        field_212 = (signed char)CollideBodyHullWithWorld__20CB3ConvexHullCollideFP28CB3HullWorldTriCollideParamsP16CB3CollidingBody(&h, this, this);
        prev = h;
        field_140 = *(u_long128 *)(h.raw + 0x100);
        field_214 = h.raw[0x111];
        field_160 = *(CGtV3d *)(h.raw + 0xB0);         // contact position
        field_170 = *(CGtV3d *)(h.raw + 0xC0);         // contact normal
        field_190 = *(unsigned short *)(h.raw + 0xE0);
        field_1A0 = *(u_long128 *)(h.raw + 0x120);
        field_1B0 = *(u_long128 *)(h.raw + 0x130);
        keep = *(u_long128 *)(h.raw + 0xD0);
    }
    if (field_212 == 0) {
        field_198 = 0;
        field_194 = 0.0f;
        return;
    }
    CGtV3d r = field_160 - field_204->field_30;
    CGtV3d vel = CrossProduct(field_D0, r) + field_B0;
    // fix3 (2026-11-09) [C] retail 0x1AB7F4..0x1AB8D0: the impulse's arithmetic on VU0 as retail does it (the native
    // port's per-call check against retail found the accumulators +0x110 / +0x120 1 ulp off with the FPU / row-dot form):
    // num = (n . v) vmulx.x -(1 + e); the inverse inertia through the rows +0x40 / +0x50 / +0x60 as vmulax / vmadday /
    // vmaddz (row0 * x + row1 * y + row2 * z, TransformVector), not three row dot products; 1 / m added by vaddx.x
    float num = DotProduct(field_170, vel) * -(field_1F8 + 1.0f);
    CGtV3d rxn = CrossProduct(r, field_170);
    CGtV3d it = TransformVector(*(const CGtMatrix3x3 *)&field_40, rxn);
    float den = func_001AB6B0_addx(DotProduct(CrossProduct(it, r), field_170), 1.0f / field_1F0);
    float j = num / den;
    CGtV3d imp = field_170 * fabsf(j);
    if (j > 0.0f) {
        field_110 += imp;                           // fix4: in place (vadd.xyz: the w lane kept) [C] 0x1AB910
        field_120 += CrossProduct(r, imp);          // [C] 0x1AB938
        field_194 = j;
        field_213 = 1;
    } else {
        field_194 = 0.0f;
    }
    signed char kind = field_215;
    bool grounded = kind == 1 || kind == 2 || kind == 3;
    if (!grounded) vel = vel + kGravity;
    CGtV3d tang = (vel - field_170 * (float)DotProduct(vel, field_170)) * field_1F0 * D_004E06A0;
    if (grounded) {
        if ((float)DotProduct(tang, tang) > 1.0f) {
            field_F0 += tang;                       // fix4: in place [C] 0x1ABA34..0x1ABA6C
            field_100 += CrossProduct(r, tang);
        } else {
            func_001AB6B0_scale_speed(field_B0, D_004E06A4);   // fix4: the speed (w) too [C] 0x1ABA70..0x1ABAA0
        }
    } else {
        if ((float)DotProduct(tang, tang) <= 1.44e+06f) {
            float k = D_004E06B4;
            if (kind != 6) {
                if (kind == 7) k = field_2BA == 2 ? D_004E06A8 : D_004E06AC;
                else k = 0.875f;
            }
            func_001AB6B0_scale_speed(field_B0, k);   // fix4: the speed (w) too [C] 0x1ABB2C..0x1ABB54
        } else {
            field_F0 += tang;                       // fix4: in place [C] 0x1ABC10..0x1ABC48
            field_100 += CrossProduct(r, tang);
        }
    }
    field_E0 = field_E0 * D_004E06B0;
    if (kind == 6 || kind == 7) {
        field_E0 = field_E0 * D_004E06A4;
        func_001AB6B0_scale_xyz(field_B0, D_004E06A4);   // fix4: [C] 0x1ABC70..0x1ABC88 (xyz; w kept)
    }
    float speed = *((float *)&field_B0 + 3);
    if (speed < 1.0f) {
        UnkStruct_Cww_mat *m = field_204;
        const CGtV3d &n = field_170;
        if (fabsf((float)DotProduct(n, m->field_10)) > D_004E06B0 || fabsf((float)DotProduct(n, m->field_20)) > D_004E06B0 ||
            fabsf((float)DotProduct(n, *(const CGtV3d *)m)) > D_004E06B0) {
            field_E0 = field_E0 * 0.5f;
            if (*((float *)&field_B0 + 3) < D_004E06B8) {
                if ((float)DotProduct(field_D0, field_D0) < D_004E06BC) field_20E = 1;
            }
        }
    }
    if (*((float *)&field_B0 + 3) < 1.0f) field_E0 = field_E0 * D_004E06AC;
    field_180 = keep;                                  // fix2: [C] retail 0x1ABBDC: the 10th output (sp+0xA20), not field_1B0
    field_130 = field_130 + *(CGtV3d *)&field_180;
    field_198 = 1;
}

#pragma pop
