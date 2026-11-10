// NONMATCHING: CollideWheelWithWorld__18CB3BodyPartPhysicsFv -- retail 377 / ours 379 instructions, 180 in changed runs
// draftAF C-first: logic complete (sphere-vs-cached-triangles loop, averaged contact point/normal, CollideWithWorld's impulse + friction + damping). 379/377, calls identical, VU op counts equal; left: 2 vmove.xyzw (sphere copies), lq/lqc2 class choices, frame 0x430 vs 0x7C0 (dead slots). Header gaps: CGtSphere::SetRadius(WAxisType), -WAxisType->X, WAxisType-XAxisType, XAxisType+float, CGtV4d xyz/w split scale
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block, call, store and VU op mapped one-to-one (draftA/m.sh op counts equal except 2 copies; calls.sh identical); constants 0.1/0.95/0.99/2^-32/-0.5 read from the ELF

// CB3BodyPartPhysics::CollideWheelWithWorld() [C name: config/symbol_addrs_b3names.txt]; Revenge's
// CB4BodyPartPhysics::CollideWheelWithWorld (B4BodyPartPhysics.cpp) names the locals [C tools/stabs_lookup.py].
// Sphere (the body's position, field_1C0's radius) against the cached world triangles (field_200); the contacts' normals
// and points are averaged, then CB3CollidingBody::CollideWithWorld's impulse/friction response (same fields).
// Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

// [G] a cached world triangle: three corners and the face normal, 64 bytes (index << 6)
struct UnkStruct_00333150_tri { CGtV3d field_0, field_10, field_20, field_30; };
struct UnkStruct_00333150_cache { int field_0; UnkStruct_00333150_tri *field_4; unsigned short *field_8; };
struct UnkStruct_00333150_mat { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_00333150 {
    unsigned char pad_0[0x40];
    CGtV3d field_40, field_50, field_60;   // [G] inverse inertia rows (CollideWithWorld's it = rows . (r x n))
    unsigned char pad_70[0x40];
    CGtV4d field_B0;      // linear velocity [G]; w = a speed-like scalar
    CGtV3d field_C0;      // [G] the wheel's down/axis direction
    CGtV3d field_D0;      // angular velocity [G]
    CGtV3d field_E0;
    CGtV3d field_F0, field_100, field_110, field_120, field_130;
    unsigned char pad_140[0x20];
    CGtV3d field_160;     // contact position [G]
    CGtV3d field_170;     // contact normal [G]
    unsigned char pad_180[0x10];
    unsigned short field_190;
    unsigned char pad_192[2];
    float field_194;
    int field_198;
    unsigned char pad_19C[0x24];
    CGtSphere field_1C0;
    unsigned char pad_1D0[0x20];
    float field_1F0;      // [G] mass (CollideWithWorld: 1.0f / field_1F0 in the denominator)
    unsigned char pad_1F4[4];
    float field_1F8;      // [G] restitution
    unsigned char pad_1FC[4];
    UnkStruct_00333150_cache *field_200;
    UnkStruct_00333150_mat *field_204;
    unsigned char pad_208[6];
    unsigned char field_20E;
    unsigned char pad_20F[3];
    unsigned char field_212;
    unsigned char field_213;
};
// [C] GtIntersection::IntersectSphereTriangle(CGtSphere, CGtV3d, CGtV3d, CGtV3d, CGtV3d *) (mangled name); declared through its
// link name with the by-value classes as pointers to the caller's own objects, as retail passes them (B3CrashActionDirector's
// ApplyRamp form)
extern "C" bool IntersectSphereTriangle__14GtIntersectionFQ29GtMathPs29CGtSphereQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d(const CGtSphere *, const CGtV3d *, const CGtV3d *, const CGtV3d *, CGtV3d *);
extern "C" float fabsf(float);
extern float D_004E0E24;   // 0.1f
extern float D_004E0978;   // 0.95f
extern float D_004E06B0;   // 0.99f

// [L] N185 stand-in (header gap: no unary minus of WAxisType into an x lane): x = 0 - w, retail `vsubw.x D, $vf0, Sw`
static inline XAxisType func_00333150_inl2(WAxisType w) { u_long128 r; asm("vsubw.x %0, $vf0, %1w" : "=j"(r) : "j"(w.lVector)); return XAxisType(r); }
// [L] N185 stand-in (header gap: no WAxisType - XAxisType): w = w - x, retail `vsubx.w D, D, Sx`
static inline WAxisType func_00333150_inl3(WAxisType w, XAxisType x) { u_long128 r = w.lVector; asm("vsubx.w %0, %0, %1x" : "+j"(r) : "j"(x.lVector)); return WAxisType(r); }
// [L] N185 stand-in (header gap: CGtV3dPlus-style scale): xyz scaled as a CGtV3d and put back, then w scaled and moved in
// (retail 0x333588: vmulx.xyz / vadd.xyz D,$vf0 / vmulx.w / vmove.w) = field_B0 * s on all four lanes
static inline void func_00333150_inl4(CGtV4d &v, float s)
{
    CGtV3d xyz = CGtV3d(v.mData) * s;
    u_long128 t = v.mData, w;
    asm("vadd.xyz %0, $vf0, %1" : "+j"(t) : "j"(xyz.mData));
    u_long128 sv;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.w %0, %1, %2x" : "=j"(w) : "j"(t), "j"(sv));
    asm("vmove.w %0, %1" : "+j"(t) : "j"(w));
    v.mData = t;
}
// [L] N185 stand-in (header gap: no operator+(XAxisType, float)): the scalar by its own qmtc2.ni, retail `vaddx.x D, D, Sx`
static inline XAxisType func_00333150_inl5(XAxisType x, float f) { u_long128 s, r = x.lVector; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, %0, %1x" : "+j"(r) : "j"(s)); return XAxisType(r); }

// 0x00333150
extern "C" void CollideWheelWithWorld__18CB3BodyPartPhysicsFv(UnkStruct_00333150 *self)
{
    int lnNumContacts = 0;
    CGtV3d lAverageNormal(0.0f, 0.0f, 0.0f);
    CGtV3d lWorldPoint(0.0f, 0.0f, 0.0f);
    float lrMostPenetration = 0.0f;
    self->field_212 = 0;
    self->field_198 = 0;
    self->field_194 = 0.0f;
    self->field_213 = 0;
    if (self->field_200->field_0 == 0) return;
    CGtSphere lSphere;
    lSphere.SetPosition(self->field_204->field_30);
    lSphere.SetRadius(self->field_1C0.Radius());
    for (int lnTri = 0; lnTri < self->field_200->field_0; lnTri++) {
        UnkStruct_00333150_tri *tri = &self->field_200->field_4[lnTri];
        if ((float)DotProduct(self->field_C0, tri->field_30) < D_004E0E24) {
            CGtV3d lNormal;
            if (IntersectSphereTriangle__14GtIntersectionFQ29GtMathPs29CGtSphereQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d(&lSphere, &tri->field_0, &tri->field_10, &tri->field_20, &lNormal)) {
                self->field_212 = 1;
                lAverageNormal += lNormal;
                lWorldPoint += lNormal * func_00333150_inl2(lSphere.Radius()) + lSphere.Position();
                XAxisType d = DotProduct(lSphere.Position() - self->field_200->field_4[lnTri].field_0, lNormal);
                float lrValue = func_00333150_inl3(lSphere.Radius(), d);
                self->field_130 += lNormal * GtMath::Max(lrMostPenetration, lrValue);
                self->field_190 = self->field_200->field_8[lnTri];
                lnNumContacts++;
            }
        }
    }
    if (self->field_212 == 0) return;
    self->field_198 = 1;
    self->field_160 = lWorldPoint * (1.0f / (float)lnNumContacts);
    CGtV3d n;
    if ((float)lAverageNormal.GetSquaredLength() < 1.0f / 4294967296.0f) {
        n = -self->field_C0;
    } else {
        n = lAverageNormal;
        n.Normalise();
    }
    self->field_170 = n;
    CGtV3d lVel = CrossProduct(self->field_D0, self->field_160 - self->field_204->field_30) + CGtV3d(self->field_B0.mData);
    ((float *)&lVel)[3] = ((const float *)&self->field_D0)[3]; // [C] 0x333324 lqc2 vf1, 0xD0(s3); 0x333334 vopmsub.xyz vf1, vf2, vf1
    // writes field_D0's register (w kept); 0x333338/0x33333C qmfc2/qmtc2 into vf2; 0x333354 vadd.xyz vf2, vf2, vf1 keeps it;
    // 0x33335C sqc2 vf2, 0x770(sp) -- `a + b` took field_B0's w
    CGtV3d lN = self->field_170;
    float num = DotProduct(lN, lVel) * -(1.0f + self->field_1F8);
    CGtV3d r = self->field_160 - self->field_204->field_30;
    CGtV3d it = TransformVector(*(const CGtMatrix3x4 *)&self->field_40, CrossProduct(r, lN));
    float den = func_00333150_inl5(DotProduct(CrossProduct(it, r), lN), 1.0f / self->field_1F0);
    float lrImpulse = num / den;
    CGtV3d lImpulse = lN * fabsf(lrImpulse);
    if (lrImpulse > 0.0f) {
        self->field_110 += lImpulse;
        self->field_120 += CrossProduct(self->field_160 - self->field_204->field_30, lImpulse);
        self->field_194 = lrImpulse;
        self->field_213 = 1;
    } else {
        self->field_194 = 0.0f;
    }
    CGtV3d lFriction = (lVel - self->field_170 * DotProduct(lVel, self->field_170)) * self->field_1F0 * -0.5f;
    if ((float)lFriction.GetSquaredLength() > 1.0f) {
        self->field_F0 += lFriction;
        self->field_100 += CrossProduct(self->field_160 - self->field_204->field_30, lFriction);
    } else {
        func_00333150_inl4(self->field_B0, D_004E0978);
    }
    self->field_E0 = self->field_E0 * D_004E06B0;
    if ((float)self->field_D0.GetSquaredLength() < 1.0f) {
        if ((float)self->field_B0.W() < 1.0f) self->field_20E = 1;
    }
}
