// GtMathPs2Quat.h -- hdr17 (2026-10-27) PROPOSAL: CGtQuat / CGtQuatPos and the lane helpers they inline.
// [G] file split (as GtMathPs2Trig.h, N232): included only by users, so the definitions cannot perturb other units (N225/N231).
// Names: the B3O0PCH map (docs/gtmathps2_api.md) [C]; layout CGtQuat { CGtV4d mRot; } [C] Revenge stabs (types.h 34640).
#ifndef GTMATHPS2QUAT_H
#define GTMATHPS2QUAT_H
#include "b3/GtMathPs2.h"

extern "C" float sinf(float);
extern "C" float cosf(float);
extern "C" float sqrtf(float);
namespace GtMath {
// [C] name: GtMath::Sqrt(float) (B3O0PCH map, 56 bytes). [L] body: retail's inlined copies are one sqrt.s.
inline float Sqrt(float x) { return sqrtf(x); }
// gapN (2026-11-01): GtMath::Clamp(float,float,float). [C] API: B3O0PCH map (0x14ABA0, 32 bytes). [L] body: max.s then min.s (retail
// GetCrashingDrivingControls 0x1BCD58 x3, 0x1BC2FC; Revenge STABS local lrClamped). [G] file: here rather than GtMath.h -- defined in
// GtMath.h it perturbs the register allocation of units that never call it (OnTakedown__13CB3ScoreBonus archive +7; N231 effect).
inline float Clamp(float lrValue, float lrMin, float lrMax) {
    float lrClamped;   // the Max then Min bodies of GtMath.h written out (this header does not include GtMath.h)
    asm("max.s %0, %1, %2" : "=f"(lrClamped) : "f"(lrValue), "f"(lrMin));
    asm("min.s %0, %1, %2" : "=f"(lrClamped) : "f"(lrClamped), "f"(lrMax));
    return lrClamped;
}
}

namespace GtMathPs2 {
#if defined(__MWERKS__)
// [C] API: B3O0PCH map (operator *(lane, lane), 80 bytes each, free). [L] body: one partial-lane vmul, result in a's lane,
// compiler-chosen (retail GetMatrix__17CB3CameraKeyFrameFv 0x446CF0..: vmulx.x / vmuly.x / vmulz.x / vmuly.y / vmulz.y /
// vmulz.z / vmulx.w / vmuly.w / vmulz.w; the N185 stand-ins of func_002622A0).
inline XAxisType operator*(XAxisType x, XAxisType y) { u_long128 r; asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline XAxisType operator*(XAxisType x, YAxisType y) { u_long128 r; asm("vmuly.x %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline XAxisType operator*(XAxisType x, ZAxisType y) { u_long128 r; asm("vmulz.x %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline XAxisType operator*(XAxisType x, WAxisType y) { u_long128 r; asm("vmulw.x %0, %1, %2w" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline YAxisType operator*(YAxisType x, XAxisType y) { u_long128 r; asm("vmulx.y %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline YAxisType operator*(YAxisType x, YAxisType y) { u_long128 r; asm("vmuly.y %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline YAxisType operator*(YAxisType x, ZAxisType y) { u_long128 r; asm("vmulz.y %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline YAxisType operator*(YAxisType x, WAxisType y) { u_long128 r; asm("vmulw.y %0, %1, %2w" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline ZAxisType operator*(ZAxisType x, XAxisType y) { u_long128 r; asm("vmulx.z %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline ZAxisType operator*(ZAxisType x, YAxisType y) { u_long128 r; asm("vmuly.z %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline ZAxisType operator*(ZAxisType x, ZAxisType y) { u_long128 r; asm("vmulz.z %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline WAxisType operator*(WAxisType x, XAxisType y) { u_long128 r; asm("vmulx.w %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return WAxisType(r); }
inline WAxisType operator*(WAxisType x, YAxisType y) { u_long128 r; asm("vmuly.w %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return WAxisType(r); }
inline WAxisType operator*(WAxisType x, ZAxisType y) { u_long128 r; asm("vmulz.w %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return WAxisType(r); }
inline WAxisType operator*(WAxisType x, WAxisType y) { u_long128 r; asm("vmulw.w %0, %1, %2w" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return WAxisType(r); }
// [C] API: B3O0PCH map (operator -(XAxisType, Y/W), 80 bytes). [L] body as the products (UncompressRotation: vsuby.x / vsubw.x).
inline XAxisType operator-(XAxisType x, YAxisType y) { u_long128 r; asm("vsuby.x %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline XAxisType operator-(XAxisType x, WAxisType y) { u_long128 r; asm("vsubw.x %0, %1, %2w" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
// [C] API: B3O0PCH map (operator -(float, XAxisType / WAxisType), 80 bytes). [L] body: the scalar by its own qmtc2.ni statement, then
// `vsub<b>.x r, s, b<b>` -- result in lane x (UncompressRotation 0x446BA0: `qmtc2.ni 1.0,$vf1; vsubw.x $vf1,$vf1,$vf2w`; 0x446BF4 vsubx.x).
inline XAxisType operator-(float f, XAxisType b) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(s), "j"(b.lVector)); return XAxisType(r); }
inline XAxisType operator-(float f, WAxisType b) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.x %0, %1, %2w" : "=j"(r) : "j"(s), "j"(b.lVector)); return XAxisType(r); }
// gapK (2026-10-31): operator -(float, YAxisType) -> XAxisType. [C] API: B3O0PCH map (0x1ADB70, 80 bytes). [L] body as the X/W forms:
// CB3BehaviourRaceCarFollow::Update 0x2E3580 `vsuby.x $vf1,$vf4,$vf3y` with 1.0 in $vf4 (qmtc2.ni) shared with the X form.
inline XAxisType operator-(float f, YAxisType b) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsuby.x %0, %1, %2y" : "=j"(r) : "j"(s), "j"(b.lVector)); return XAxisType(r); }
#endif

// [C] layout: Revenge stabs. [C] API members: B3O0PCH map. Retail's out-of-line copy ctor / CGtQuat(CGtV4d) (0x2ED2F0 / 0x2ED300):
// one lq/sq (B3BehaviourFlyAround_002ED2F0/_002ED300.cpp, proven).
struct CGtQuat {
    CGtV4d mRot;
    CGtQuat() {}
    CGtQuat(const CGtQuat& o) : mRot(o.mRot.mData) {}   // hdr19 [L]: through CGtV4d(u_long128) -- our CGtV4d union has no user copy ctor (retail does, map 44), whose implicit copy goes float by float; -O0 56 (map 52 with retail CGtV4d)
    CGtQuat(CGtV4d v) : mRot(v) {}                // [C] -O0 68 = map
    CGtQuat& operator=(const CGtQuat& o) { mRot.mData = o.mRot.mData; return *this; }
    CGtQuat operator*(float s) { CGtQuat r(mRot * s); return r; }   // [C] -O0 88 = map
    CGtMatrix3x4 ConvertToMatrix();
    void SetFromMatrix(const CGtMatrix3x4& m);
};
struct CGtQuatPos {
    CGtQuat mQuat;
    CGtV3d mPos;
    CGtQuatPos() {}
    CGtMatrix3x4 ConvertToMatrix();
    void SetFromMatrix(const CGtMatrix3x4& m);
};

#if defined(__MWERKS__)
// [C] API: B3O0PCH map (CGtQuat::ConvertToMatrix(), 996 bytes). [C] decode: retail GetMatrix__17CB3CameraKeyFrameFv 0x446C9C-0x446E04:
// q scaled by sqrt(2) (D_004E0ED4 = 0x3FB504F3), the nine lane products in the order below (X lane via qmfc2, Y/Z/W via the
// 16-byte copy + lwc1), rows R = (1-yy-zz, xy+wz, xz-wy), U = (xy-wz, 1-xx-zz, yz+wx), A = (xz+wy, yz-wx, 1-xx-yy) by
// CGtV3d::SetX/Y/Z(float), mPos never written. [C] the map emits its new helpers after it in reverse first-use order:
// ..., X(), X*X, Y(), Z(), X*Z, Y*Y, Y float, Z*Z, Z float, W(), W*X, W float, W*Y, W*Z, CGtV3d::SetY(float), SetZ(float).
// gapG: N250's opt_classresults scope removed here and on CGtQuatPos::ConvertToMatrix (the assigning CGtMatrix3x4 copy ctor
// gives retail's return copy; CGtQuatPos -O0 112 = map only without the scope; GetMatrix's natural `m = q.ConvertToMatrix()`) [L].
inline CGtMatrix3x4 CGtQuat::ConvertToMatrix()
{
    CGtQuat q;
    q = *this * 1.4142135f;
    float xx = q.mRot.X() * q.mRot.X();
    float xy = q.mRot.X() * q.mRot.Y();
    float xz = q.mRot.X() * q.mRot.Z();
    float yy = q.mRot.Y() * q.mRot.Y();
    float yz = q.mRot.Y() * q.mRot.Z();
    float zz = q.mRot.Z() * q.mRot.Z();
    float wx = q.mRot.W() * q.mRot.X();
    float wy = q.mRot.W() * q.mRot.Y();
    float wz = q.mRot.W() * q.mRot.Z();
    CGtMatrix3x4 m;
    m.mRight.SetX(1.0f - yy - zz);
    m.mRight.SetY(xy + wz);
    m.mRight.SetZ(xz - wy);
    m.mUp.SetX(xy - wz);
    m.mUp.SetY(1.0f - xx - zz);
    m.mUp.SetZ(yz + wx);
    m.mAt.SetX(xz + wy);
    m.mAt.SetY(yz - wx);
    m.mAt.SetZ(1.0f - xx - yy);
    return m;
}
// [C] API: B3O0PCH map (CGtQuatPos::ConvertToMatrix(), 112 bytes). [L] body.
inline CGtMatrix3x4 CGtQuatPos::ConvertToMatrix()
{
    CGtMatrix3x4 m;
    m = mQuat.ConvertToMatrix();
    m.mPos = mPos;
    return m;
}
#endif


#if defined(__MWERKS__)
// [C] API: B3O0PCH map (XAxisType::operator -(), WAxisType::operator -(), 48 bytes; CGtV4d::SetW(XAxisType), 56 bytes). [L] bodies
// (UncompressRotation's sign flips, 0x446F28 / 0x446C80): `vsub.x $vf1,$vf0,$vf1`; W: `vsubw.x $vf1,$vf0,$vf1w` (result in lane x)
// then `vmulx.w D,$vf0,$vf1x`.
inline XAxisType XAxisType::operator-() const { u_long128 r; asm("vsub.x %0, $vf0, %1" : "=j"(r) : "j"(lVector)); return XAxisType(r); }
inline XAxisType WAxisType::operator-() const { u_long128 r; asm("vsubw.x %0, $vf0, %1w" : "=j"(r) : "j"(lVector)); return XAxisType(r); }
inline void CGtV4d::SetW(XAxisType a) { asm("vmulx.w %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }

// [C] API: B3O0PCH map (GtMathPs2::UncompressRotation(unsigned int), 1256 bytes). [L] body decoded from retail
// GetMatrix__17CB3CameraKeyFrameFv 0x446AC0-0x446C94; helper order [C] map (after it, reverse first use): SetY(float), -(float,W),
// SetX(X), SetY(Y), -(X,W), SetZ(Z), W::operator-, SetW(X). Bits 31..14: index n = a*a + b (a = (int)sqrt n), angles
// pi/2 * a/511 and pi/2 * b/(2a); bits 9..0: w * 1023; bits 10..13: signs of x, y, z, w.
inline CGtQuat UncompressRotation(unsigned int c)
{
    CGtQuat q;
    int n = c >> 14;
    int a = (int)GtMath::Sqrt((float)n);
    int b = n - a * a;
    int d = a * 2;
    float t = 1.5707964f * ((float)a / 511.0f);
    float p;
    if (d > 0) p = 1.5707964f * ((float)b / (float)d); else p = 0.0f;
    q.mRot.SetY(cosf(t));
    q.mRot.SetX(sinf(p));
    // gapN [L]: w by SetA(float) (`vmulx.w D,$vf0,Sx`): both retail copies (GetMatrix__17CB3CameraKeyFrame 0x446BA4, GetCrashingDrivingControls
    // 0x1BBBC4; build/vt/gapN/censusU.py). Was SetW(float) unless QX_SETA was defined (QX_SETA is now a no-op).
    q.mRot.SetA((float)(int)(c & 0x3FF) / 1023.0f);
    float r = GtMath::Sqrt(1.0f - q.mRot.W() * q.mRot.W());   // [C] sqrt.s before the eps test (0x446BBC)
    // gapN [L]: the zero case first, `r <= eps` (both retail copies: c.le.s r, eps; GetMatrix 0x446BC8 bc1t to the zero lanes out of line;
    // GetMatrix archive 214 -> 207, GetCrashingDrivingControls equal). Was `if (r > 0.001f) {main} else {zero}`.
    if (r <= 0.001f) {
        q.mRot.SetX(0.0f);
        q.mRot.SetY(0.0f);
        q.mRot.SetZ(0.0f);
    } else {
        q.mRot.SetX(q.mRot.X() * r);
        q.mRot.SetY(q.mRot.Y() * r);
        float z = 1.0f - q.mRot.X() * q.mRot.X() - q.mRot.Y() * q.mRot.Y() - q.mRot.W() * q.mRot.W();
#ifdef QX_ZB
        if (z <= 0.0f) q.mRot.SetZ(0.0f); else q.mRot.SetZ(GtMath::Sqrt(z));
#else
        if (z > 0.0f) q.mRot.SetZ(GtMath::Sqrt(z)); else q.mRot.SetZ(0.0f);
#endif
        if (c & 0x400) q.mRot.SetX(-q.mRot.X());
        if (c & 0x800) q.mRot.SetY(-q.mRot.Y());
        if (c & 0x1000) q.mRot.SetZ(-q.mRot.Z());
        if (c & 0x2000) q.mRot.SetW(-q.mRot.W());
    }
    return q;
}
#endif


// ---- hdr17b: CGtQuat::SetFromMatrix (N225 decode) and the lane helpers it inlines ----
#if defined(__MWERKS__)
// [C] API: B3O0PCH map (operator +/-(lane, lane), operator +(lane, float), 80 bytes; CGtV4d::Set<l>(<m>AxisType) 56). [L] bodies: one
// partial-lane op, result in the left operand's lane, compiler-chosen (N225: retail Prepare__20CB3BehaviourKeyFrameFPv 0x374F3C).
inline XAxisType operator+(XAxisType x, YAxisType y) { u_long128 r; asm("vaddy.x %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline XAxisType operator+(XAxisType x, ZAxisType y) { u_long128 r; asm("vaddz.x %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline YAxisType operator+(YAxisType x, XAxisType y) { u_long128 r; asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline YAxisType operator+(YAxisType x, ZAxisType y) { u_long128 r; asm("vaddz.y %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline ZAxisType operator+(ZAxisType x, XAxisType y) { u_long128 r; asm("vaddx.z %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline ZAxisType operator+(ZAxisType x, YAxisType y) { u_long128 r; asm("vaddy.z %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline XAxisType operator-(XAxisType x, ZAxisType y) { u_long128 r; asm("vsubz.x %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return XAxisType(r); }
inline YAxisType operator-(YAxisType x, XAxisType y) { u_long128 r; asm("vsubx.y %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline YAxisType operator-(YAxisType x, ZAxisType y) { u_long128 r; asm("vsubz.y %0, %1, %2z" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return YAxisType(r); }
inline ZAxisType operator-(ZAxisType x, XAxisType y) { u_long128 r; asm("vsubx.z %0, %1, %2x" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline ZAxisType operator-(ZAxisType x, YAxisType y) { u_long128 r; asm("vsuby.z %0, %1, %2y" : "=j"(r) : "j"(x.lVector), "j"(y.lVector)); return ZAxisType(r); }
inline XAxisType operator+(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
inline YAxisType operator+(YAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
inline ZAxisType operator+(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return ZAxisType(r); }
inline void CGtV4d::SetW(YAxisType a) { asm("vmuly.w %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetW(ZAxisType a) { asm("vmulz.w %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetX(ZAxisType a) { asm("vaddz.x %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetY(XAxisType a) { asm("vaddx.y %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetZ(YAxisType a) { asm("vaddy.z %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
// [C] API: B3O0PCH map (CGtV4d::operator *=(float), 76). [L] body: the scalar by its own qmtc2.ni statement, `vmulx.xyzw` in place.
inline CGtV4d& CGtV4d::operator*=(float s)
{
    u_long128 sv;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyzw %0, %0, %1x" : "+j"(mData) : "j"(sv));
    return *this;
}
// [C] API: B3O0PCH map (CGtQuat::SetFromMatrix(const CGtMatrix3x4&), 2432). [C order / L body] N225 (build/vt/quat/notes.txt):
// Shoemake's conversion; the map's helper order after it = positive branch, then switch cases 0, 1, 2.
inline void CGtQuat::SetFromMatrix(const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        mRot.SetX(m.mUp.Z() - m.mAt.Y());
        mRot.SetY(m.mAt.X() - m.mRight.Z());
        mRot.SetZ(m.mRight.Y() - m.mUp.X());
        mRot *= 0.5f / s;
        // gapN [L]: w by SetA(float) (`vmulx.w D,$vf0,Sx`): retail census (build/vt/gapN/censusQ.py) 24 of 24 positive-branch sites (e.g.
        // func_00446300 0x446944, CollisionResolveCameraWorld 0x2F6F04, Update__20CB3CarViewerGameMode 0x24F974), none SetW(float)'s
        // vsubw.w + vaddx.w. [L] the API may be SetW(XAxisType) on a float moved by qmtc2 (same code). Was SetW(0.5f * s).
        mRot.SetA(0.5f * s);
    } else {
        int i;
        if (m.mUp.Y() > m.mRight.X()) {
            if (m.mAt.Z() > m.mUp.Y()) i = 2; else i = 1;
        } else {
            if (m.mAt.Z() > m.mRight.X()) i = 2; else i = 0;
        }
        switch (i) {
        case 0: {
            float s = GtMath::Sqrt(m.mRight.X() - (m.mUp.Y() + m.mAt.Z()) + 1.0f);
            mRot.SetX(0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            mRot.SetY(0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            mRot.SetZ(0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
// [C] API: B3O0PCH map (CGtQuatPos::SetFromMatrix, 72). [C] -O0 72 = map (N225).
inline void CGtQuatPos::SetFromMatrix(const CGtMatrix3x4& m)
{
    mQuat.SetFromMatrix(m);
    mPos = m.mPos;
}
#endif


// ---- hdr19: Slerp(CGtQuat, CGtQuat, float) and the helpers it inlines (retail Update__23CB3BehaviourInterpolateFP9CGtCameraf) ----
#if defined(__MWERKS__)
// [C] API: B3O0PCH map (operator +(X,X) / (Z,Z) / (W,W), 80 bytes; CGtV4d::SetW(WAxisType), 56). [L] bodies: one partial-lane add
// accumulated over the FIRST operand (GtMathPs2.h's operator+(Y,Y) the same, hdr19), and `vmulw.w D,$vf0,Sw` (retail 0x373DAC..0x373DF8:
// `vaddx.x $vf1,$vf2,$vf1x`, $vf2 = a*s0 computed first; MWCC evaluates operator arguments right to left, so Slerp writes b*t + a*s0).
// gapE [L]: three-operand forms, compiler-chosen result (retail CreateRotationMatrix3x4 0x429EC4 `vaddx.x $vf2,$vf7,$vf4x`,
// 0x429E90 `vaddz.z $vf1,$vf7,$vf4z`: the result is on neither operand). Were "+j"(a) (hdr19).
inline XAxisType operator+(XAxisType a, XAxisType b) { u_long128 r; asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
inline ZAxisType operator+(ZAxisType a, ZAxisType b) { u_long128 r; asm("vaddz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return ZAxisType(r); }
inline WAxisType operator+(WAxisType a, WAxisType b) { u_long128 r; asm("vaddw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
inline void CGtV4d::SetW(WAxisType a) { asm("vmulw.w %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
// [C] API: B3O0PCH map (DotProduct(CGtV4d, CGtV4d) 128, DotProduct(CGtQuat, CGtQuat) 96; both emitted right after Slerp). [L] body: retail
// 0x373D1C `vmul.xyzw $vf2,$vf2,$vf1; vaddy.x $vf1,$vf2,$vf2y; vaddz.x $vf1,$vf1,$vf2z; vaddw.x $vf1,$vf1,$vf2w`. -O0 128 = map [C];
// the CGtQuat one 60 (map 96, open).
inline XAxisType DotProduct(CGtV4d a, CGtV4d b)
{
    u_long128 m, t;
    asm("vmul.xyzw %0, %1, %2" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddy.x %0, %1, %1y" "\n\t" "vaddz.x %0, %0, %1z" "\n\t" "vaddw.x %0, %0, %1w" : "=&j"(t) : "j"(m));
    return XAxisType(t);
}
inline XAxisType DotProduct(CGtQuat a, CGtQuat b) { return DotProduct(a.mRot, b.mRot); }
#endif
extern "C" float acosf(float);   // [L] retail func_0011E328 (E_B3DEBUG map: LIBM.A wf_acos.o at that address)
#if defined(__MWERKS__)
// [C] API: B3O0PCH map (GtMathPs2::Slerp(CGtQuat, CGtQuat, float), 1360). [C decode] retail Update__23CB3BehaviourInterpolateFP9CGtCameraf
// 0x373CF8-0x373DFC + 0x373E54-0x373F3C: c = DotProduct(a, b); c < 0 -> c = -c and flip; c < 0.999 (D_004E0F00) -> om = acosf(c),
// k = 1/sin(om), s0 = sin((1-t)*om)*k, t = sin(t*om)*k; flip -> t = -t; r = b*t + a*s0 lane by lane. [L] t (the by-value parameter) is
// the second weight: retail copies the caller's t into its own callee-saved FPR (f21) before the dot. sin = an odd Taylor polynomial to
// x^13, written out three times (D_004E0E80 -1/3!, D_004E0D04 1/5!, D_004E0D00 -1/7!, D_004E0CFC 1/9!, D_004E0CF4 -1/11!, D_004E0F04
// ~1/13!): the map has no helper for it after Slerp [C], so [L] it is in the body. -O0 1312 (map 1360, open).
inline CGtQuat Slerp(CGtQuat a, CGtQuat b, float t)
{
    float s0 = 1.0f - t;
    float c = DotProduct(a, b);
    bool flip;
    if (c < 0.0f) { c = -c; flip = true; } else flip = false;
    if (c < 0.999f) {
        float om = acosf(c);
        float o2 = om * om;
        float k = 1.0f / (om + o2 * om * (-0.1666666716f + o2 * (0.008333333768f + o2 * (-0.0001984127011f + o2 * (2.75573143e-06f + o2 * (-2.505075969e-08f + 1.589691018e-10f * o2))))));
        float x0 = s0 * om;
        float x1 = t * om;
        float x02 = x0 * x0;
        s0 = (x0 + x02 * x0 * (-0.1666666716f + x02 * (0.008333333768f + x02 * (-0.0001984127011f + x02 * (2.75573143e-06f + x02 * (-2.505075969e-08f + 1.589691018e-10f * x02)))))) * k;
        float x12 = x1 * x1;
        t = (x1 + x12 * x1 * (-0.1666666716f + x12 * (0.008333333768f + x12 * (-0.0001984127011f + x12 * (2.75573143e-06f + x12 * (-2.505075969e-08f + 1.589691018e-10f * x12)))))) * k;
    }
    if (flip) t = -t;
    CGtQuat r;
    r.mRot.SetX(b.mRot.X() * t + a.mRot.X() * s0);
    r.mRot.SetY(b.mRot.Y() * t + a.mRot.Y() * s0);
    r.mRot.SetZ(b.mRot.Z() * t + a.mRot.Z() * s0);
    r.mRot.SetW(b.mRot.W() * t + a.mRot.W() * s0);
    return r;
}
#endif

// ---- gapE: the free lane operators CreateRotationMatrix3x4 adds (GtMathPs2Trig.h) ----
// [C] API: B3O0PCH map (operator -(XAxisType,XAxisType) / (ZAxisType,ZAxisType), 80 bytes). [L] bodies: one partial-lane op, result
// in a's lane, compiler-chosen (retail func_00429BE0 0x429E88 `vsubx.x $vf1,$vf5,$vf8x`, 0x429EB0 `vsubz.z $vf3,$vf7,$vf4z`). Kept
// out of GtMathPs2.h: there `XAxisType - XAxisType` would stop meaning a float subtraction (proven B3SoundTrafficVehicle_00278830).
#if defined(__MWERKS__)
inline XAxisType operator-(XAxisType a, XAxisType b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
inline ZAxisType operator-(ZAxisType a, ZAxisType b) { u_long128 r; asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return ZAxisType(r); }
#endif

// ---- gapJ (2026-10-31): operator -(ZAxisType, float) ----
// [C] API: B3O0PCH map (GtMathPs2::operator -(ZAxisType, float) 0x1319F0, 80 bytes, next to operator +(ZAxisType, float)). [L] body as
// operator -(YAxisType, float) on lane z: retail func_00427D00 0x4288FC `qmtc2.ni f,$vf1; vsubx.z $vf1,$vf3,$vf1x` (box.Z() - h).
// -O0 68 (as its Y twin; the map's 80 is open for the whole lane-operator family).
#if defined(__MWERKS__)
inline ZAxisType operator-(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return ZAxisType(r); }
#endif

// ---- gapJ (2026-10-31): CGtV3d::NormaliseFast() ----
// [C] API: B3O0PCH map (CGtV3d::NormaliseFast() 0x153190, 188 bytes); [L] Revenge STABS `GtXAxisTypePS2 NormaliseFast()` (types.h):
// returns a lane value. [C] decode (CB3AICar::UpdateOutOfRange 0x142E18..0x142EA8, twice): GetSquaredLength, vrsqrt, the 1.0 formed in
// the rsqrt latency, vmulq.xyz in place on a compiler-chosen register, then vmulq.x of the 1.0 = 1/length in $vf1 (returned [L]).
// [L] body = proven B3VehiclePhysics_001CB780's func_001CB780_inl1 (N185) as the member; 1/length written back into the squared-length
// local and returned: -O0 188 = map [C] (`return XAxisType(one)` 192, a fresh local 208, void-style `mData = r.mData` 172).
#if defined(__MWERKS__)
inline XAxisType CGtV3d::NormaliseFast()
{
    XAxisType l = GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(mData), "=&r"(one) : "r"(l.lVector));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r.mData), "=r"(l.lVector) : "j"(mData), "1"(one));
    asm(".set reorder");
    *this = r;
    return l;
}
#endif

} // namespace GtMathPs2
// ---- gapJ (2026-10-31): GtMath::ACosRad / ACosDeg, GtMathPs2::AngleBetweenVectors(CGtV3d, CGtV3d) ----
// [C] API: B3O0PCH map: AngleBetweenVectors(CGtV3d,CGtV3d) 0x152F30 (208 bytes), then ACosDeg(float) 0x153000 (56), ACosRad(float)
// 0x153040 (112), CosAngleBetweenNormalisedVectors, XAxisType(const XAxisType&), NormaliseFast (its helpers, reverse first use).
// [C] decode (CB3AICar::UpdateOutOfRange 0x142E18..0x142EFC): NormaliseFast(a), NormaliseFast(b), the clamped cosine, mtc1, acosf
// (func_0011E328), then `mul.s f0, D_004E069C (57.29578), f0`. [L] bodies; AngleBetweenVectors with both arguments
// assigned to locals: -O0 208 = map [C] (normalising the parameters 152, copy-constructed locals 184).
extern "C" float acosf(float);   // [L] retail func_0011E328 (as above, at file scope for GtMath)
namespace GtMath {
inline float ACosRad(float x) { return acosf(x); }   // -O0 40 vs map 112: open (retail's inlined copies: mtc1 + jal acosf only)
inline float ACosDeg(float x) { float r = 57.29578f * ACosRad(x); return r; }   // -O0 56 = map [C] (`return K * ACosRad(x)` 48)
}
// ---- gapK (2026-10-31): GtMath::ASinRad / ASinDeg ----
// [C] API: B3O0PCH map: ASinRad(float) 0x1A43C0 (112 bytes, as ACosRad), ASinDeg(float) 0x312210 (56, as ACosDeg; emitted after
// CB3BehaviourRaceCarFollow::Prepare). [C] retail census: 17 calls of func_0011E340 (the libm wrapper that tail-jumps to
// __ieee754_asinf [C asm]) in 10 functions, each a bare mtc1 + jal; RaceCarFollow Update 0x2E3670 then mul.s by D_004E069C (57.29578).
// [L] bodies as ACosRad/ACosDeg: ASinDeg -O0 56 = map [C]; ASinRad 40 vs 112 (open, as ACosRad).
extern "C" float asinf(float);   // [L] retail func_0011E340
namespace GtMath {
inline float ASinRad(float x) { return asinf(x); }
inline float ASinDeg(float x) { float r = 57.29578f * ASinRad(x); return r; }
}
namespace GtMathPs2 {
#if defined(__MWERKS__)
inline float AngleBetweenVectors(CGtV3d a, CGtV3d b)
{
    CGtV3d lA;
    CGtV3d lB;
    lA = a;
    lB = b;
    lA.NormaliseFast();
    lB.NormaliseFast();
    XAxisType lCos = CosAngleBetweenNormalisedVectors(lA, lB);
    return GtMath::ACosDeg(lCos);
}
#endif

// ---- gapJ (2026-10-31): GtMathPs2::GetRight(CGtQuat) / GetUp(CGtQuat) ----
// [C] API: B3O0PCH map (GetUp(CGtQuat) 0x25F430, GetRight(CGtQuat) 0x25F6E0, 616 bytes each, in CB3CarViewerGameMode's queue).
// [C] decode (CB3CarViewerGameMode::Update 0x24F59C.. / 0x24F750..): q * sqrt(2) (D_004E0ED4), then only that row's six lane products
// (right: xy, xz, yy, zz, wy, wz; up: xx, xy, yz, zz, wx, wz) and CGtV3d::SetX/Y/Z(float) -- ConvertToMatrix's mRight / mUp row
// alone. [L] bodies (draftE's local stand-ins func_0024DAB0_right/up).
#if defined(__MWERKS__)
inline CGtV3d GetRight(CGtQuat a)
{
    CGtQuat q;
    q = a * 1.4142135f;
    float xy = q.mRot.X() * q.mRot.Y();
    float xz = q.mRot.X() * q.mRot.Z();
    float yy = q.mRot.Y() * q.mRot.Y();
    float zz = q.mRot.Z() * q.mRot.Z();
    float wy = q.mRot.W() * q.mRot.Y();
    float wz = q.mRot.W() * q.mRot.Z();
    CGtV3d r;
    r.SetX(1.0f - yy - zz);
    r.SetY(xy + wz);
    r.SetZ(xz - wy);
    return r;
}
inline CGtV3d GetUp(CGtQuat a)
{
    CGtQuat q;
    q = a * 1.4142135f;
    float xx = q.mRot.X() * q.mRot.X();
    float xy = q.mRot.X() * q.mRot.Y();
    float yz = q.mRot.Y() * q.mRot.Z();
    float zz = q.mRot.Z() * q.mRot.Z();
    float wx = q.mRot.W() * q.mRot.X();
    float wz = q.mRot.W() * q.mRot.Z();
    CGtV3d r;
    r.SetX(xy - wz);
    r.SetY(1.0f - xx - zz);
    r.SetZ(yz + wx);
    return r;
}
#endif

// ---- gapN (2026-11-01): lane operators / setters missing from the header ----
// [C] API: B3O0PCH map names and sizes (research/E_B3O0PCH_symbols.csv): operator -(XAxisType,float) 0x131C90, operator +(WAxisType,float)
// 0x1BEC10, operator -(WAxisType,float) 0x2E2790 (80 bytes each, as the other lane/float operators); operator +(ZAxisType,WAxisType)
// 0x432040, operator -(WAxisType, X/Y/ZAxisType) 0x22B9E0/0x22B990/0x22B940, operator -(WAxisType,WAxisType) 0x2ED890 (80 bytes).
// [L] bodies: one partial-lane op, result in the left operand's lane, compiler-chosen, as the existing lane operators (retail
// ApplyDrivingForces 0x1C1E00 `vsubx.x $vf1,$vf2,$vf1x`, 0x1C1F30 `vaddx.w $vf2,$vf1,$vf2x`; _RenderDistort 0x3CF860 vaddw.z;
// DoCollideHullToHull 0x2B92E4 / CollideWheelWithWorld 0x3336BC vsubx.w).
#if defined(__MWERKS__)
inline XAxisType operator-(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
inline WAxisType operator+(WAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return WAxisType(r); }
inline WAxisType operator-(WAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return WAxisType(r); }
inline WAxisType operator-(WAxisType w, XAxisType x) { u_long128 r; asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(w.lVector), "j"(x.lVector)); return WAxisType(r); }
inline WAxisType operator-(WAxisType w, YAxisType y) { u_long128 r; asm("vsuby.w %0, %1, %2y" : "=j"(r) : "j"(w.lVector), "j"(y.lVector)); return WAxisType(r); }
inline WAxisType operator-(WAxisType w, ZAxisType z) { u_long128 r; asm("vsubz.w %0, %1, %2z" : "=j"(r) : "j"(w.lVector), "j"(z.lVector)); return WAxisType(r); }
inline WAxisType operator-(WAxisType a, WAxisType b) { u_long128 r; asm("vsubw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
#endif

// ---- gapN (2026-11-01): GtMathPs2::CompressRotation(CGtQuat) ----
// [C] API: B3O0PCH map (0x1BC1D0, 1092 bytes; Abs(CGtV4d) and CGtV3d::Set(X,Y,Z) emitted right after it = its new helpers). [L] body: the
// inverse of UncompressRotation, decoded by draftV from retail GetCrashingDrivingControls 0x1BCB34..0x1BCD38 (|q| by Abs, w * 1023
// capped at 0x3FF, sign bits 0x400..0x2000, the |xyz| axis normalised and clamped, row/col angles by acos(y) / asin(x)); locals:
// Revenge STABS (luResult, lnRow, lnCol, lrRowAngle, lrColAngle, lrLength, lAxis).
#if defined(__MWERKS__)
inline unsigned int CompressRotation(CGtQuat q)
{
    CGtV4d lAbs = Abs(q.mRot);
    unsigned int luResult = (int)(lAbs.W() * (float)1023);
    if (luResult >= 0x400) luResult = 0x3FF;
    if (q.mRot.X() < 0.0f) luResult |= 0x400;
    if (q.mRot.Y() < 0.0f) luResult |= 0x800;
    if (q.mRot.Z() < 0.0f) luResult |= 0x1000;
    if (q.mRot.W() < 0.0f) luResult |= 0x2000;
    CGtV3d lAxis;
    lAxis.Set(lAbs.X(), lAbs.Y(), lAbs.Z());
    float lrLength = lAxis.GetLength();
    float lrRowAngle;
    float lrColAngle;
    if (lrLength < 0.001f) {
        lrRowAngle = 1.5707964f;
        lrColAngle = 0.0f;
    } else {
        lAxis = lAxis * (1.0f / lrLength);
        lAxis.SetX(GtMath::Clamp((float)lAxis.X(), -1.0f, 1.0f));
        lAxis.SetY(GtMath::Clamp((float)lAxis.Y(), -1.0f, 1.0f));
        lAxis.SetZ(GtMath::Clamp((float)lAxis.Z(), -1.0f, 1.0f));
        lrRowAngle = GtMath::ACosRad(lAxis.Y());
        lrColAngle = GtMath::ASinRad(lAxis.X());
    }
    int lnRow = (int)((float)511 * (lrRowAngle / 1.5707964f));
    int lnCol = (int)((float)(lnRow * 2) * (lrColAngle / 1.5707964f));
    return luResult | ((lnRow * lnRow + lnCol) << 14);
}
#endif

// ---- gapN (2026-11-01): operator +(ZAxisType, WAxisType) ----
// [C] API: B3O0PCH map (0x432040, 80 bytes). [L] body: one vaddw.z, compiler-chosen (retail _RenderDistort__23CB3StylisedText2dObject 0x3CF860).
// Note: with it, `float + WAxisType` is ambiguous (float -> u_long128 -> ZAxisType) for the files that include this header.
#if defined(__MWERKS__)
inline ZAxisType operator+(ZAxisType z, WAxisType w) { u_long128 r; asm("vaddw.z %0, %1, %2w" : "=j"(r) : "j"(z.lVector), "j"(w.lVector)); return ZAxisType(r); }
#endif

// ---- gapO (2026-11-01): lane operators missing from the header ----
// [C] API: B3O0PCH map (research/E_B3O0PCH_symbols.csv), 80 bytes each as the other lane operators.
#if defined(__MWERKS__)
// operator +(YAxisType, WAxisType) 0x273420. [L] body: one vaddw.y, result in the left operand's lane, compiler-chosen (retail
// UpdateTrafficWorldCollisionEffects__17CB3EffectsManager `vaddw.y $vf2,$vf3,$vf2w`; as operator +(ZAxisType, WAxisType)).
inline YAxisType operator+(YAxisType y, WAxisType w) { u_long128 r; asm("vaddw.y %0, %1, %2w" : "=j"(r) : "j"(y.lVector), "j"(w.lVector)); return YAxisType(r); }
// operator -(float, ZAxisType) -> XAxisType 0x16EA60. [L] body as the X/Y/W forms: the scalar by its own qmtc2.ni statement, then
// `vsubz.x r, s, bz` (retail DrawPositionMarker__15CB3RacePosition 0x1538B8 `vsubz.x $vf1,$vf1,$vf2z`; GetHullPoints 0x3DA234).
inline XAxisType operator-(float f, ZAxisType b) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubz.x %0, %1, %2z" : "=j"(r) : "j"(s), "j"(b.lVector)); return XAxisType(r); }
#endif

} // namespace GtMathPs2
#endif
