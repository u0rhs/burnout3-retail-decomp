// GtMathPs2 reconstruction (Criterion engine vector math, PS2/VU0 macro mode).
// Status per item: [M] = matches build E byte-for-byte, [D] = draft (API from link maps, body not yet verified).
// API source: docs/gtmathps2_api.md (355 functions from the -O0/Debug/Internal maps).
// Two builds: mwccps2 (__MWERKS__, the matching build: everything below as matched) and a host compiler (resource D
// port layer, x64): same layouts, the VU0 asm bodies left out (declared only).
#ifndef GTMATHPS2_H
#define GTMATHPS2_H
#if defined(__MWERKS__)
typedef unsigned int u_long128 __attribute__((mode(TI)));
#else
struct alignas(16) u_long128 { unsigned int w[4]; };   // host: 16 bytes, 16-aligned, like the EE's 128-bit registers
#endif

extern "C" float sinf(float);   // libm; retail calls both by these names (CB3RotatingImage2dObject::_Render)
extern "C" float cosf(float);

namespace GtMathPs2 {

struct CGtV2d {                                  // [D] 8 bytes: retail reads x,y with lwc1 0/4 (CGt2dObject::SetPos 0x1D5E00)
    float marValues[2];   // [L] name: Burnout Revenge prototype stabs (types.h)
    CGtV2d() {}
    CGtV2d(float x, float y) { marValues[0] = x; marValues[1] = y; }
    void Set(float x, float y) { marValues[0] = x; marValues[1] = y; }   // [D] API: B3O0PCH map (writes in place, no temporary)
    void SetX(float x) { marValues[0] = x; }   // [D] API: B3O0PCH map
    void SetY(float y) { marValues[1] = y; }   // [D] API: B3O0PCH map
    CGtV2d& operator*=(float s) { marValues[0] *= s; marValues[1] *= s; return *this; }   // [D] API: B3O0PCH map
    CGtV2d& operator+=(const CGtV2d& o) { marValues[0] += o.marValues[0]; marValues[1] += o.marValues[1]; return *this; }   // [D] API: B3O0PCH map
    // [D] API: B3O0PCH map (CGtV2d::operator-=(const CGtV2d&), 104 bytes, as +=). func_003D27F0 written `pos -= off;`
    // gets 146 -> 138 changed instrs (build/vt/gm/, 2026-10-25); a pointer or `*(marValues + 1)` body is identical.
    CGtV2d& operator-=(const CGtV2d& o) { marValues[0] -= o.marValues[0]; marValues[1] -= o.marValues[1]; return *this; }
    float X() const { return marValues[0]; }                    // [D] API: B3O0PCH map
    float Y() const { return marValues[1]; }                    // [D] API: B3O0PCH map
    // [D] small operators returning by value: retail copies their results through 8-byte stack temporaries
    // (swc1 x2, ld/sd), the shape of an inline returning CGtV2d (CGt2dObject::SetPos, CGt2dObjectBox::_Render)
    CGtV2d operator+(const CGtV2d& o) const { CGtV2d r(marValues[0] + o.marValues[0], marValues[1] + o.marValues[1]); return r; }
    CGtV2d operator-(const CGtV2d& o) const { CGtV2d r; r.marValues[0] = marValues[0] - o.marValues[0]; r.marValues[1] = marValues[1] - o.marValues[1]; return r; }
    CGtV2d operator*(const CGtV2d& o) const { CGtV2d r(marValues[0] * o.marValues[0], marValues[1] * o.marValues[1]); return r; }
    // [D] API: B3O0PCH map. Used for a reciprocal (CB3HeadingComponent::Prepare(EHeadingType), CHeadingBar2dObject)
    CGtV2d operator/(const CGtV2d& o) const { CGtV2d r; r.marValues[0] = marValues[0] / o.marValues[0]; r.marValues[1] = marValues[1] / o.marValues[1]; return r; }
    // [D] API: B3O0PCH map. One division, then a multiply per lane (func_0031A9C0: div.s 1/s, two mul.s)
    CGtV2d operator/(float s) const { float inv = 1.0f / s; CGtV2d r; r.marValues[0] = marValues[0] * inv; r.marValues[1] = marValues[1] * inv; return r; }
    // [D] scalar multiply. API: B3O0PCH map, a member (CGtV2d::operator *(float)). The free by-value form
    // this header had before (`operator*(const CGtV2d, float)`, "not in the E map") is retracted: the API
    // list has the member, and func_0031A9C0 only matches with the vector taken by reference (docs/known.md).
    CGtV2d operator*(float s) const { CGtV2d r; r.marValues[0] = marValues[0] * s; r.marValues[1] = marValues[1] * s; return r; }
    // [D] API: B3O0PCH map (CB3RotatingImage2dObject::_Render negates corners)
    CGtV2d operator-() const { CGtV2d r; r.marValues[0] = -marValues[0]; r.marValues[1] = -marValues[1]; return r; }
} __attribute__((aligned(8)));   // [L] N220: retail moves CGtV2d members/copies with ld/sd (whole-space copy in the Gt2d render tail,
                                 // CGt2dObjectTable::RenderBox 0x33DF50 `sd a2,0x60(sp)`); 4-byte alignment splits them into lwc1/swc1

// [D] API: B3O0PCH map has exactly three members (default ctor, copy ctor, operator=). Rows: mRight, mDown, mPos
// (TransformPoint: mPos + mRight * x + mDown * y). Retail calls the copy ctor and
// operator= out of line (0x31A590/0x31A570, emitted with B3HeadingComponent.cpp; DNAT has the same 56/32-byte
// copies): the copy ctor copies six floats, operator= three 8-byte CGtV2d moves.
struct CGtMatrix2x3 {
    CGtV2d mRight;   // names: [L] Burnout Revenge prototype stabs (types.h)
    CGtV2d mDown;
    CGtV2d mPos;
    CGtMatrix2x3() {}
    CGtMatrix2x3(const CGtMatrix2x3& o);             // out of line: B3HeadingComponent_0031A570.cpp
    CGtMatrix2x3& operator=(const CGtMatrix2x3& o);  // out of line: B3HeadingComponent_0031A570.cpp
};

// Axis types: a scalar carried in one lane of a 128-bit value. [C] layout and members: Burnout Revenge prototype
// stabs (types.h `GtXAxisTypePS2`: `u_long128 lVector`, copy ctor, (u_long128) ctor, operator float, unary -);
// Burnout 3's maps name them XAxisType etc. (B3O0PCH: default + copy ctor, operator=, operator float).
struct XAxisType {
    u_long128 lVector;
    XAxisType() {}
    XAxisType(const XAxisType& o) { lVector = o.lVector; }
    XAxisType(u_long128 v) { lVector = v; }      // __ct__Q29GtMathPs29XAxisTypeF1 (DNAT map)
    XAxisType& operator=(const XAxisType& o) { lVector = o.lVector; return *this; }
#if defined(__MWERKS__)
    // [L] the x lane to an FPR. The operand is read through the object's address: the temporary gets a stack slot
    // whose 128-bit store/reload MWCC forwards away -- retail's frame keeps that slot (CollideHulls 0x2B9400, N129)
    operator float() const { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(*(const u_long128*)&lVector)); return f; }
#else
    operator float() const;
#endif
    XAxisType operator-() const;                 // [C] API: B3O0PCH map (48); hdr17: defined in GtMathPs2Quat.h
};
// [L] YAxisType: members as ZAxisType's (B3O0PCH map: operator float 36 bytes, unary - 48 bytes; free operator -(YAxisType,
// YAxisType/float...) 80 bytes). Lane 1. [G] body shape (as ZAxisType's copy + lane read).
// [L] hdrrd (2026-10-27): copy ctor and lane read as ZAxisType's/WAxisType's -- the B3O0PCH map gives Y, Z and W the same
// operator float size (36 bytes; X's is 24), and retail's Y() reads go through the same 16-byte pointer copy
// (SetPos__16CB3Globe2dObject 0x3B5560: `addiu a1,sp,16; sq a2,0(a1); lwc1 f1,20(sp)`; func_0023F960).
struct YAxisType {
    u_long128 lVector;
    YAxisType() {}
#if defined(__MWERKS__)
    YAxisType(const YAxisType& o) { asm("sq %1, 0(%2)" : "=m"(lVector) : "r"(*(const u_long128*)&o.lVector), "r"(this)); }
#else
    YAxisType(const YAxisType& o) { lVector = o.lVector; }
#endif
    YAxisType(u_long128 v) { lVector = v; }
    YAxisType& operator=(const YAxisType& o) { lVector = o.lVector; return *this; }
    operator float() const { YAxisType t(*this); return ((const float*)&t.lVector)[1]; }
    YAxisType operator-() const;                 // defined at the end of this file
};
// [L] Z/W lane types: members as XAxisType's (the maps list operator float and unary - for both). [C] the copy and
// lane read below reproduce retail's `return GetWindscreenPos(..).Z();` (func_003E6F50/func_003E6F90, 16/16 each) and
// the speed test in CB3AIArbitrator::CalculateSpeedMatch (`2.2369363f * v.W()`, the 16-byte copy + lane read):
// - operator float copies the value into a local first and reads the lane from that copy (lwc1 8/12 off sp);
// - the copy reads its source through the object's address (the N129 mechanism: the source temporary keeps its
//   16-byte frame slot, retail's 0x40 frame) and stores through a pointer operand (`sq` with "=m" output and
//   "r"(this)): retail's `addiu v1,sp,32; addiu v0,sp,16; lq v1,0(v1); sq v1,0(v0)`. A C store folds the address into
//   `sq 16(sp)`; a memory-clobbering volatile asm matches too but blocks forwarding elsewhere (N149 probe).
// [G] body shape (no out-of-line copy to compare); build/vt/gm/ (GtMathPs2 header probe, 2026-10-25).
struct ZAxisType {
    u_long128 lVector;
    ZAxisType() {}
#if defined(__MWERKS__)
    ZAxisType(const ZAxisType& o) { asm("sq %1, 0(%2)" : "=m"(lVector) : "r"(*(const u_long128*)&o.lVector), "r"(this)); }
#else
    ZAxisType(const ZAxisType& o) { lVector = o.lVector; }
#endif
    ZAxisType(u_long128 v) { lVector = v; }
    ZAxisType& operator=(const ZAxisType& o) { lVector = o.lVector; return *this; }
    operator float() const { ZAxisType t(*this); return ((const float*)&t.lVector)[2]; }
    ZAxisType operator-() const;                 // defined at the end of this file
};
struct WAxisType {
    u_long128 lVector;
    WAxisType() {}
#if defined(__MWERKS__)
    WAxisType(const WAxisType& o) { asm("sq %1, 0(%2)" : "=m"(lVector) : "r"(*(const u_long128*)&o.lVector), "r"(this)); }
#else
    WAxisType(const WAxisType& o) { lVector = o.lVector; }
#endif
    WAxisType(u_long128 v) { lVector = v; }
    WAxisType& operator=(const WAxisType& o) { lVector = o.lVector; return *this; }
    operator float() const { WAxisType t(*this); return ((const float*)&t.lVector)[3]; }
    XAxisType operator-() const;                 // [C] API: B3O0PCH map (48); hdr17: defined in GtMathPs2Quat.h
};

// [C] layout: Revenge stabs (types.h): `CGtV3d` is only `u_long128 mData`, with a user copy ctor and a
// CGtV3d(u_long128) ctor (`__Q29GtMathPs26CGtV3dUx`). Operations hard-code their VU0 registers and pass values
// through GPR operands with qmtc2/qmfc2 in the asm text; MWCC treats those moves as copies, folding same-register
// round trips and memory operands (lqc2) -- the shape of retail's inlined code (N128).
struct CGtV3d {
    u_long128 mData;
    CGtV3d() {}                                  // [M] empty (out-of-line copy in E is 8 bytes: jr ra/nop)
    CGtV3d(const CGtV3d& o) { mData = o.mData; }
    CGtV3d(u_long128 v) { mData = v; }           // __ct__Q29GtMathPs26CGtV3dF1 (DNAT map)
    // [C] API: CGtV3d::GetRawData() (B3O0PCH map, 28 bytes); [L] body: this by-value form is -O0 28 = map (a const& return gives 24).
    // CGtMatrix3x4::operator* reads its 8 operands through it (hdr21: that is what makes its -O0 340 = map).
    u_long128 GetRawData() const { return mData; }
    // [C] hdr16: no user operator= (implicit, bitwise). The B3O0PCH map's CGtMatrix3x4::operator= (116) and CGtMatrix3x3::operator=
    // (92) are the implicit ones only with this one implicit (a user CGtV3d op= gives 124/100); and an implicit matrix operator=
    // from a returned temporary is what compiles to retail's row-0 sq + three 16-byte lb/sb loops (69 functions, 185 loops;
    // e.g. func_002F5860, GetMatrix__17CB3CameraKeyFrameFv). The user copy ctor stays (map: CGtMatrix3x4 copy ctor 124 needs it).
    // [C] API: B3O0PCH map (CGtV3d::CGtV3d(float,float,float), 72 bytes). [L] body (hdr7): the three floats stored into a stack
    // temporary, then one 128-bit load (retail TriggerRealVoice__20CGtSoundVoiceManager 0x388BD0: swc1 x3 to 0x40(sp); lq; sq).
    CGtV3d(float x, float y, float z) { union { float f[4]; u_long128 q; } t; t.f[0] = x; t.f[1] = y; t.f[2] = z; mData = t.q; }
#if defined(__MWERKS__)
    // [C] API: CGtV3d::Zero() (B3O0PCH map). A hard-coded $vf1, out through a GPR (folds into sqc2): SetAIOutOfRange__8CB3AICarFv and
    // CB3AICar::StopCrashing (0x1423E0) match as lifted, two calls reusing $vf1 (a "=j" operand: $vf2 then $vf1) (N137)
    // gapE [L]: compiler-chosen register (CreateRotationMatrix3x4 `vadd.xyz $vf4,$vf0,$vf0`; retail census 240 of 455 not $vf1);
    // -O0 20 either way; headsafe 0 DIFF (N137's hard $vf1 sites unchanged).
    void Zero() { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); mData = r; }
    // [L] API: B3O0PCH map. Retail's inlined copies (CollideHulls 0x2B9400): the other vector in $vf1, this in
    // $vf2 (N128); the result on a compiler-chosen register (vuhdr: IntersectSphere(CGtSphere,CGtSphere) 0x2BF530
    // `vsub.xyz $vf3, $vf2, $vf1` -- the hard-coded inputs are what number the two operand loads above
    // GetSquaredLength's values; UpdateNearMissArray 0x1B3EA0 unchanged). Was: result over $vf1, qmfc2 to "=r".
    CGtV3d operator-(const CGtV3d& o) const {
        u_long128 t;
        asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vsub.xyz %0, $vf2, $vf1"
            : "=j"(t) : "r"(o.mData), "r"(mData));
        return CGtV3d(t);
    }
#else
    void Zero();
    CGtV3d operator-(const CGtV3d& o) const;
#endif
    XAxisType GetSquaredLength() const;          // defined below
    XAxisType GetSquaredLength(u_long128 one) const;   // FAKEMATCH [G]: explicit 1.0 hoist, defined at the end
    void SetX(float x);                          // defined at the end of this file (as CGtV4d::SetA)
    void SetY(float y);
    void SetZ(float z);
    void Set(float x, float y, float z);   // [C] API: B3O0PCH map (128 bytes); defined after SetZ(float)
    void Set(XAxisType x, YAxisType y, ZAxisType z);   // [C] API: B3O0PCH map (136 bytes); defined after SetZ(ZAxisType)
    void Normalise();
    XAxisType NormaliseGetLength();              // defined at the end of this file
    XAxisType GetLength() const;                 // [L] B3O0PCH map; defined at the end of this file
    bool IsZero() const;                         // defined at the end of this file
    bool IsEffectivelyZero() const;              // gapK: [C] API B3O0PCH map (104 bytes); defined after IsZero
    XAxisType NormaliseFast();                   // gapJ: [C] API B3O0PCH map (188 bytes); defined in GtMathPs2Quat.h
    CGtV3d operator-() const;                    // defined at the end of this file
    CGtV3d operator+(const CGtV3d& o) const;
    CGtV3d& operator+=(CGtV3d o);                // [C] API: B3O0PCH map (76 bytes); defined after operator+
    CGtV3d& operator-=(CGtV3d o);                // [C] API: B3O0PCH map (76 bytes); defined after operator+
    CGtV3d operator*(float s) const;
    XAxisType X() const;
    YAxisType Y() const;
    ZAxisType Z() const;
    void SetX(XAxisType a);
    void SetY(YAxisType a);
    void SetZ(ZAxisType a);
    // [C] API: B3O0PCH map (CreateRotationMatrix3x4's helpers, gapE): cross-lane setters (56), vector products (68), lane
    // in-place ops (76); defined in GtMathPs2Trig.h
    void SetX(YAxisType a);
    void SetX(ZAxisType a);
    void SetY(XAxisType a);
    void SetY(ZAxisType a);
    void SetZ(XAxisType a);
    void SetZ(YAxisType a);
    CGtV3d operator*(CGtV3d o) const;
    CGtV3d operator*(XAxisType a) const;
    CGtV3d operator*(YAxisType a) const;   // [C] API: B3O0PCH map (68); defined at the end of this file
    CGtV3d operator*(ZAxisType a) const;   // [C] API: B3O0PCH map (68); defined at the end of this file
    CGtV3d& operator*=(ZAxisType a);
    CGtV3d& operator+=(XAxisType a);
    // gapN: [C] API B3O0PCH map; defined at the end of this file
    CGtV3d operator*(WAxisType a) const;
    CGtV3d operator-(WAxisType a) const;
    CGtV3d& operator+=(WAxisType a);
    void SetX(WAxisType a);
    void SetY(WAxisType a);
    void SetZ(WAxisType a);
};


struct CGtV4d {
    union { float f[4]; u_long128 mData; };   // mData: [L] Revenge stabs (types.h); f[]: our float view
    CGtV4d() {}
    CGtV4d(u_long128 d) { mData = d; }   // [L] Revenge stabs declare it (__Q29GtMathPs26CGtV4dUx); body [G]
    // [C] API: B3O0PCH map (CGtV4d::CGtV4d(float,float,float,float), 0x54 out of line). [G] body: retail's static
    // initializers build the four floats in a stack temporary and store it with one lq/sq pair (func_004D7EC0).
    CGtV4d(float x, float y, float z, float w) { CGtV4d t; t.f[0] = x; t.f[1] = y; t.f[2] = z; t.f[3] = w; mData = t.mData; }
    CGtV4d& operator=(const CGtV4d& o) { mData = o.mData; return *this; }   // [D] one 128-bit move (CGt2dObject::Prepare)
#if defined(__MWERKS__)
    // [C] out-of-line copy byte-identical to retail 0x2EC8D0 / DNAT 0x29E850 (6/6, build/vt/gm2/ool.cpp). The result is
    // returned through CGtV4d(u_long128): a named `CGtV4d r` result is copied out through the float view (17 instrs).
    // A user copy ctor (retail has one, 0x2EC8C0) also gives 6/6 but changes 30 proven units (frames grow).
    CGtV4d operator*(float s) const {
        u_long128 t;
        asm("qmtc2 %1, $vf2\n\tvmulx.xyzw %0, %2, $vf2x" : "=j"(t) : "r"(s), "j"(mData));
        return CGtV4d(t);
    }
    // [C] lane-wise product. API: B3O0PCH map (operator *(CGtV4d)). Out-of-line copy byte-identical to DNAT 0x1987D0
    // (5/5: lqc2 $vf1 from the argument first, so the argument is the first "j" input; build/vt/gm2/ool.cpp).
    CGtV4d operator*(const CGtV4d o) const {
        u_long128 t;
        asm("vmul.xyzw %0, %2, %1" : "=j"(t) : "j"(o.mData), "j"(mData));
        return CGtV4d(t);
    }
    // [C] API: B3O0PCH map (CGtV4d::operator -(CGtV4d), 68 bytes, as operator +). [L] body: retail's
    // `lqc2 $vf1, o; lqc2 $vf2, this; vsub.xyzw $vf1, $vf2, $vf1` (Construct__17CB3ScrapeRenderer, a186: 37/37 exact).
    CGtV4d operator-(const CGtV4d o) const {
        u_long128 t;
        asm("vsub.xyzw %0, %2, %1" : "=j"(t) : "j"(o.mData), "j"(mData));
        return CGtV4d(t);
    }
    // gapO: [C] API: B3O0PCH map (CGtV4d::operator +(CGtV4d), 0x164790, 68 bytes). [L] body as operator -: one vadd.xyzw on
    // compiler-chosen registers (retail _Render__16CB3Panel2dObject 0x380318 `vadd.xyzw $vf1,$vf3,$vf1`).
    CGtV4d operator+(const CGtV4d o) const {
        u_long128 t;
        asm("vadd.xyzw %0, %2, %1" : "=j"(t) : "j"(o.mData), "j"(mData));
        return CGtV4d(t);
    }
    // [L] full 4-lane zero (CB3CollidingBody::StopImmediately); on $vf1 as CGtV3d::Zero (N137)
    // [C] API: B3O0PCH map (CGtV4d::GetRawData(), 28); [L] body as CGtV3d's (gapE)
    u_long128 GetRawData() const { return mData; }
    void Zero() { u_long128 r; asm("vsub.xyzw $vf1, $vf0, $vf0" "\n\t" "qmfc2 %0, $vf1" : "=r"(r)); mData = r; }
    void SetA(float a);                          // [D] defined out of class at the end of this file
    void SetW(float w);                          // [L] API: B3O0PCH map; defined at the very end
    void SetX(float x);                          // defined at the end of this file (as CGtV3d's)
    void SetY(float y);
    void SetZ(float z);
    XAxisType X() const;
    YAxisType Y() const;
    ZAxisType Z() const;
    WAxisType W() const;                         // [C] API: B3O0PCH map (CGtV4d::W(), 52 bytes); defined below
    void SetX(XAxisType a);
    void SetY(YAxisType a);
    void SetZ(ZAxisType a);
    void SetW(XAxisType a);                      // [C] API: B3O0PCH map (56); hdr17: defined in GtMathPs2Quat.h
    void SetW(YAxisType a);                      // [C] API: B3O0PCH map (56); hdr17b: the rest defined in GtMathPs2Quat.h
    void SetW(ZAxisType a);
    void SetW(WAxisType a);                      // [C] API: B3O0PCH map (56); hdr19: defined in GtMathPs2Quat.h
    void SetX(ZAxisType a);
    void SetY(XAxisType a);
    void SetZ(YAxisType a);
    CGtV4d& operator*=(float s);                 // [C] API: B3O0PCH map (76)
    void SetX(YAxisType a);                      // gapN: [C] API B3O0PCH map (56 each); defined at the end of this file
    void SetX(WAxisType a);
    void SetY(ZAxisType a);
    void SetY(WAxisType a);
    void SetZ(XAxisType a);
    void SetZ(WAxisType a);
#else
    CGtV4d operator*(float s) const;
    CGtV4d operator*(const CGtV4d o) const;
    CGtV4d operator-(const CGtV4d o) const;
    CGtV4d operator+(const CGtV4d o) const;
    void Zero();
    void SetA(float a);
#endif
};

// [D] API: B3O0PCH map (GtMathPs2::CreateRotationMatrix2x3(float), TransformPoint/TransformPoints for 2x3).
// Bodies from CB3RotatingImage2dObject::_Render (0x31A300), where all three are inlined.
inline CGtMatrix2x3 CreateRotationMatrix2x3(float angle) {
    float s = sinf(angle);
    float c = cosf(angle);
    CGtMatrix2x3 r;
    r.mDown.Set(s, c);   // this row first: retail's store order (single-change variants)
    r.mRight.Set(c, -s);
    r.mPos.Set(0.0f, 0.0f);
    return r;
}
inline CGtV2d TransformPoint(const CGtMatrix2x3& m, const CGtV2d& v) {
    CGtV2d r = m.mPos;
    r += m.mRight * v.marValues[0];
    r += m.mDown * v.marValues[1];
    return r;
}
inline void TransformPoints(const CGtMatrix2x3& m, CGtV2d* dst, const CGtV2d* src, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = TransformPoint(m, src[i]);
}

// [C] layout: Revenge stabs (types.h): three CGtV3d rows. [C] -O0 (hdr16): the implicit copy ctor 100 / operator= 92 = the
// B3O0PCH map (with CGtV3d's operator= implicit).
struct CGtMatrix3x3 {
    CGtV3d mRight, mUp, mAt;
};

struct CGtMatrix3x4 {
    CGtV3d mRight, mUp, mAt, mPos;
    CGtMatrix3x4() {}                            // [C] -O0 92 = B3O0PCH map (needed once a copy ctor is declared)
    // [L] gapG: the copy constructor assigns (implicit operator=, N239): an inline's `return r;` then copies r into the result
    // temporary the way retail does (row 0 from its register, rows 1-3 by 16-byte lb/sb loops: Globe2d _Render 15 loops,
    // BuildCustomCameraData 3 result levels per face, func_002F0440's natural `u = a * b` = its stand-in). [C] -O0 124 = map;
    // [G] body text: `{ *this = m; }` is 112 at -O0; this form is 124 and compiles like it at -O4 (spill slots only).
    CGtMatrix3x4(const CGtMatrix3x4& m) { CGtMatrix3x4& r = (*this = m); }
    void SetIdentity();                          // [C] API: B3O0PCH map (144 bytes); defined after TransformPoint
    CGtMatrix3x4 operator*(const CGtMatrix3x4& m) const;   // [C] API: B3O0PCH map (340 bytes)
    void OrthoNormalise();                       // [C] API: B3O0PCH map (1552 bytes); defined at the end of this file
    void Invert();                               // [C] API: B3O0PCH map (524 bytes); defined at the end of this file
    CGtMatrix3x4& operator*=(const CGtMatrix3x4& m);   // gapN: [C] API B3O0PCH map (176 bytes); defined at the end of this file
};   // [D] rows at +0x00/+0x10/+0x20/+0x30 (FireAirRam, StartCrashing)
#if defined(__MWERKS__)
// [L] hdr21 body (hdr16 / func_002F0440's v256_mul stand-in, N185, as a member): m's R/U/A rows in $vf4/$vf3/$vf2, each row of this
// through them (ACC chain; retail's interleave: basis R, row 0, vmulax, basis U, vmadday, basis A), the position row adding m.mPos;
// rows out through GPRs into r. Operands through GetRawData(): -O0 -inline off 340 = the B3O0PCH map [C] when measured without the
// named-return elision (with it 328; CGtQuatPos::ConvertToMatrix shows the same: 112 = map without, 104 with -> the map's -O0 build
// did not elide) [L]. gapG: no opt_classresults scope here any more -- with the assigning copy constructor above, the
// unelided return copy is retail's extra op= level (N246's "single staging area" reading retracted) [L].
inline CGtMatrix3x4 CGtMatrix3x4::operator*(const CGtMatrix3x4& m) const
{
    CGtMatrix3x4 r;
    asm("qmtc2.i %0, $vf4" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.i %1, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2.i %2, $vf2" : : "r"(m.mRight.GetRawData()), "r"(m.mUp.GetRawData()), "r"(m.mAt.GetRawData()), "r"(mRight.GetRawData()));
    asm("vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mRight.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mUp.mData) : "r"(mUp.GetRawData()));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mAt.mData) : "r"(mAt.GetRawData()));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mPos.mData) : "r"(mPos.GetRawData()), "r"(m.mPos.GetRawData()));
    return r;
}
// [C] API: B3O0PCH map (GtMathPs2::Multiply(const CGtMatrix3x4&, const CGtMatrix3x4&), 60 bytes). [L] body: -O0 60 = map (hdr21)
inline CGtMatrix3x4 Multiply(const CGtMatrix3x4& a, const CGtMatrix3x4& b) { return a * b; }
#endif

// [C] the square, then the 1.0 constant as its own partial-lane statement on a compiler-chosen register, defined late
// (just before the ACC tail that uses it), then the tail; all VU registers compiler-chosen ("j"). With the build
// compiler b119p (N184) the 1.0 is hoisted out of call-free loops as retail's compiler did:
// CB3PhysicsManager::UpdateNearMissArray (0x1B3EA0) byte-identical from plain `.GetSquaredLength()` (wine host; wibo
// is the N165 GPR tie-break), and the head of CB3RaceCar::UpdateLastPositions (0x150D50, probe build/vt/p_ulp.cpp) is
// unchanged (2 off as before). [L] Retail's out-of-line copy (0x2ED2C0, B3BehaviourFlyAround_002ED2C0.cpp) keeps the
// earlier hard-coded body under `peephole off` (its own definition, not this header); this body gives 7 instrs out of
// line instead of retail's 12 (open; build/vt/cpatch/hdr/). Was: hard-coded $vf1/$vf2 under a scoped `peephole off`
// (N130), which no compiler build can hoist.
// Defined after the other inline asm definitions (an inline asm function defined after it changed its register
// allocation, matching/vu0/v13.cpp).
// [L] hdr6 (2026-10-27): the ACC tail inside a `.set noreorder` region (N188), the square and the 1.0 before it. A 1.0 still in
// the block when the region starts is parked in a GPR (`vaddw.x $vf1; qmfc2 r; ... qmtc2 r,$vf1; vmaddz.x $vf1,$vf1,..z` --
// retail's 866 straight-line sites, N191's round trip without explicit .i moves); a 1.0 that b119p hoists out of a loop stays
// in its VU register (retail's 57 hoisted sites; census build/vt/hdr6/census_loop.py: parked = straight, held = hoisted, no
// exceptions). headsafe 0 DIFF; archives: CollideHulls__20CB3ConvexHullCollide and Draw__10CB3RaceCar exact. Was: no region.
#if defined(__MWERKS__)
inline XAxisType CGtV3d::GetSquaredLength() const {
    u_long128 sq, one, t;
    asm("vmul.xyz %0, %1, %1" : "=j"(sq) : "j"(mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(sq), "j"(one));
    asm(".set reorder");
    return XAxisType(t);
}

// [C] API: B3O0PCH map (GtMathPs2::DotProduct(CGtV3d, CGtV3d), 116 bytes, free). [L] body (hdr6, 2026-10-27): the product and
// the ACC sum, then the 1.0 as its own statement, then the tail inside a `.set noreorder` region (N188), the result moved out
// after it. The region makes MWCC park a 1.0 that is still in the block in a GPR (`vaddw.x $vf1; qmfc2 r; ... qmtc2 r,$vf1;
// vmaddz.x $vf1,$vf1,$vfMz` -- retail's 473 straight-line sites) and leaves a 1.0 that b119p hoists out of a loop in its VU
// register (`vmul.xyz $vf1,a,b; ...; vmaddz.x $vf1,$vfC,$vf1z` -- retail's 51 hoisted sites; census: every parked site is
// straight-line, every held one hoisted; build/vt/hdr6/census_loop.py). [C] reproduces IntersectSphere 0x2BF2E0 42/42,
// BuildClippedEdgeList 0x2B87E0 77/77 and UpdateNearMissArray 0x1B3EA0 60/60 (wine, as DotProduct(d, d)) with their local copies removed.
inline XAxisType DotProduct(CGtV3d a, CGtV3d b)
{
    u_long128 d, m, one, t;
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(m), "j"(one));
    asm(".set reorder");
    asm("qmfc2 %0, %1" : "=r"(d) : "j"(t));
    return XAxisType(d);
}

#if defined(__MWERKS__)
// [C] API: B3O0PCH map (Interpolate(CGtV4d, CGtV4d, float), 116 bytes out of line). a + (b - a) * t through ACC.
// [L] body (hdr12, build/vt/hdr12/notes.txt): a and t compiler-chosen in the first statement (t moved .ni inside it),
// then a noreorder region {b moved into $vf1 with .i, vmaddx, result out .i} (vu0_ni_fixup clears the .i bits). The region
// wraps real asm: it keeps b's lq + qmtc2 and the result's qmfc2 + sq unfolded (N94/N188), as at every retail HUD site.
// [C] -O0 -inline off size 116 = the map (build/vt/hdr12/o0all.sh; the previous body 132, hard-coded t 104).
// By value [C map]: each call keeps one dead 16-byte slot, which retail's frames show (former N140 pads, e.g.
// func_00394870). Retail's early-numbered t GPR is call-site shape: t passed as a float local (N183 kept local);
// with that, the HelpBar drafts func_0031BD60 / func_0031BF40 are exact.
inline CGtV4d Interpolate(CGtV4d a, CGtV4d b, float t)
{
    u_long128 tv, r;
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyzw $ACC, %1, %0x" : "=&j"(tv) : "j"(a.mData), "r"(t));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddx.xyzw $vf1, $vf1, %2x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(b.mData), "j"(tv));
    asm(".set reorder");
    return CGtV4d(r);
}

// [L] API: B3O0PCH map (GtMathPs2::Interpolate(CGtV3d, CGtV3d, float), 116 bytes, free). hdrrd (2026-10-27); was the lifter's
// file-local LERP3_HELPER (tools/tiny_lift.py). Defined here, next to the CGtV4d one: the same asm volatile body appended at the
// end of this file changed 34 proven units (definition order, cf. N187). [L] body: the CGtV4d Interpolate on the
// xyz lanes, as retail's RepositionCarInLane__10CB3RaceCar (`vaddax.xyz ACC,a,vf0x; qmtc2.ni t; vmsubax.xyz ACC,a,tx;
// qmtc2.ni b; vmaddx.xyz r,b,tx; qmfc2.ni`). [G] that this is the map's Interpolate rather than a written-out a + (b - a) * t:
// GetPositionAtParam__14CB3CameraUtils 0x2F5D40 has the other shape (vsub / vmulx / vadd, compiler-chosen registers).
inline CGtV3d Interpolate(CGtV3d a, CGtV3d b, float t)
{
    u_long128 r;
    asm volatile("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %3, $vf2" "\n\t" "vmsubax.xyz $ACC, %1, $vf2x" "\n\t"
        "qmtc2.ni %2, %1" "\n\t" "vmaddx.xyz %1, %1, $vf2x" "\n\t" "qmfc2.ni %0, %1"
        : "=r"(r), "+j"(a.mData) : "r"(b.mData), "r"(t));
    return CGtV3d(r);
}
#endif

// [D] API: B3O0PCH map (CGtV4d::SetA(float); SetW(float) too). w = 1.0 (vf0.w) * a, other lanes kept
// (CB3HeadingComponent::Update, 0x319490: lqc2 / qmtc2.ni / vmulx.w / sqc2 on an object's colour).
// Defined here, out of class: the same body defined inside the class schedules Update's two uses differently (tested;
// cf. the definition-order note above GetSquaredLength).
// [L] hdr15 (2026-10-27): the scalar moved by its own "=j" statement, then `vmulx.w` in place (as SetW / CGtSphere::SetRadius;
// ghvu2's stand-in). func_0042B030 4 -> 0 changed, func_003AEC70 96 -> 94; headsafe 0 DIFF (Update 0x319490 unchanged under
// b119p); -O0 48 = the map [C] (was 40). Was: one statement `qmtc2.ni %1,$vf2; vmulx.w %0,$vf0,$vf2x` ("+j" mData, "r" a).
inline void CGtV4d::SetA(float a) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(mData) : "j"(s));
}

// [C] API: B3O0PCH map (CGtV3d::SetX/SetY/SetZ(float), 48 bytes out of line). One lane from the float through $vf2
// into this vector on a hard-coded $vf1, mData in and out through GPR operands (MWCC folds the moves into lqc2/sqc2):
// probes build/vt/mx/sety.cpp (CB3NetworkCarPhysics::HideUnderRoad 0x268620, 23/23) and setxyz.cpp
// (CB3BehaviourInterpolate::Construct 0x3739C0, 20/20: consecutive calls on one vector merge into one lqc2/sqc2, one
// value into one qmtc2.ni). A "+j" in/out operand matches those two as well, but puts the vector in $vf3 where
// CB3EnvironmentManager::Construct (0x2BCEC0) has $vf1 (N135).
inline void CGtV3d::SetX(float x) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(x));
    asm("vaddx.x %0, $vf0, %1x" : "+j"(mData) : "j"(s));
}
inline void CGtV3d::SetY(float y) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(y));
    asm("vaddx.y %0, $vf0, %1x" : "+j"(mData) : "j"(s));
}
inline void CGtV3d::SetZ(float z) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(z));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(mData) : "j"(s));
}

// [C] API: B3O0PCH map (CGtV3d::Set(float,float,float), 128 bytes). [L] body (hdr8): see build/vt/hdr8/notes.txt item 4.
inline void CGtV3d::Set(float x, float y, float z) {
    u_long128 sx, sy, sz;
    asm("qmtc2.ni %1, %0" : "=j"(sx) : "r"(x));
    asm("qmtc2.ni %1, %0" : "=j"(sy) : "r"(y));
    asm("qmtc2.ni %1, %0" : "=j"(sz) : "r"(z));
    asm("vaddx.x %0, $vf0, %1x" "\n\t" "vaddx.y %0, $vf0, %2x" "\n\t" "vaddx.z %0, $vf0, %3x" : "+j"(mData) : "j"(sx), "j"(sy), "j"(sz));
}

// [L] API: B3O0PCH map (CGtV3d::operator-(), 48 bytes out of line). 0 - v on $vf1, mData through GPRs (as the binary
// operator-); retail's census: `vsub.xyz $vf1, $vf0, $vf1` 75 times.
// gapE [L]: compiler-chosen registers: retail census 128 of 204 `vsub.xyz D,$vf0,S` are not $vf1->$vf1 (CreateRotationMatrix3x4
// `vsub.xyz $vf8,$vf0,$vf1`); -O0 48 either way. Was hard $vf1 through GPRs. headsafe 0 DIFF.
inline CGtV3d CGtV3d::operator-() const {
    u_long128 t;
    asm("vsub.xyz %0, $vf0, %1" : "=j"(t) : "j"(mData));
    return CGtV3d(t);
}

// [L] API: B3O0PCH map (CGtV3d::operator+(CGtV3d), 68 bytes out of line). operator-'s layout: this in $vf2, the
// other in $vf1 (retail's census: `vadd.xyz $vf1, $vf2, $vf1` 103 times).
inline CGtV3d CGtV3d::operator+(const CGtV3d& o) const {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vadd.xyz $vf1, $vf2, $vf1" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(t) : "r"(o.mData), "r"(mData));
    return CGtV3d(t);
}
// [C] API: B3O0PCH map (CGtV3d::operator+=(CGtV3d), 76 bytes). [L] body (hdr8): operator-='s in-place shape, `vadd.xyz this, this, o`
// on compiler-chosen registers (retail census: 400+ in-place vadd.xyz sites, build/vt/hdr8/census_add.py).
inline CGtV3d& CGtV3d::operator+=(CGtV3d o) {
    asm("vadd.xyz %0, %0, %1" : "+j"(mData) : "j"(o.mData));
    return *this;
}

// [L] API: B3O0PCH map (CGtV3d::operator-=(CGtV3d), 76 bytes). hdr7: `vsub.xyz this, this, o` in place, compiler-chosen registers
// (retail census: 291 in-place vsub.xyz sites, build/vt/hdrrd/census2.py; TriggerRealVoice 0x388BD0 `vsub.xyz $vf3,$vf3,$vf2; sqc2`).
inline CGtV3d& CGtV3d::operator-=(CGtV3d o) {
    asm("vsub.xyz %0, %0, %1" : "+j"(mData) : "j"(o.mData));
    return *this;
}

// [L] API: B3O0PCH map (CGtV3d::operator*(float), 68 bytes out of line). The scalar moved into a VU register by its own
// statement, then the lane-scaled product, all compiler-chosen (hdrj, 2026-10-26): retail hoists the scalar out of loops
// (GetClosestBitToPoint 0x3E18E0: `qmtc2.ni v1,$vf4` before the loop, `vmulx.xyz $vf2,$vf1,$vf4x` inside), which the
// hard-coded $vf1/$vf2 body can't do. No proven unit uses it. Was: `qmtc2 %1,$vf1; qmtc2.ni %2,$vf2; vmulx.xyz $vf1,$vf1,$vf2x`.
inline CGtV3d CGtV3d::operator*(float s) const {
    u_long128 t;
    u_long128 sv;
    asm("qmtc2 %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(mData), "j"(sv));
    return CGtV3d(t);
}

// [L] API: B3O0PCH map (CGtV3d::X()/Y()/Z(), 52 bytes; SetX/Y/Z(XAxisType/...), 56 bytes). A lane type carries the
// whole 128-bit vector (types.h); the setter copies that lane into this one: source $vf1, destination $vf2
// (CB3EnvironmentManager::SunOcclusionTest reloads both for each call).
inline XAxisType CGtV3d::X() const { return XAxisType(mData); }
inline YAxisType CGtV3d::Y() const { return YAxisType(mData); }   // [L] as X()/Z() (hdrrd); was `YAxisType r; r.lVector = mData; return r;`
inline ZAxisType CGtV3d::Z() const { return ZAxisType(mData); }   // [L] as X(); matches func_003E6F50/6F90
inline void CGtV3d::SetX(XAxisType a) { asm("vaddx.x %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetY(YAxisType a) { asm("vaddy.y %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetZ(ZAxisType a) { asm("vaddz.z %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }
// [C] API: B3O0PCH map (CGtV3d::Set(XAxisType,YAxisType,ZAxisType), 136 bytes). [L] body (hdr8): the three lane copies in one
// "+j" statement on compiler-chosen registers (SetX/SetY/SetZ(axis) above).
inline void CGtV3d::Set(XAxisType x, YAxisType y, ZAxisType z) {
    asm("vaddx.x %0, $vf0, %1x" "\n\t" "vaddy.y %0, $vf0, %2y" "\n\t" "vaddz.z %0, $vf0, %3z" : "+j"(mData) : "j"(x.lVector), "j"(y.lVector), "j"(z.lVector));
}

// [L] CGtV4d's lane setters/getters (B3O0PCH map): the CGtV3d bodies on the 128-bit value.
inline void CGtV4d::SetX(float v) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2.ni %2, $vf2" "\n\t" "vaddx.x $vf1, $vf0, $vf2x" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(t) : "r"(mData), "r"(v));
    mData = t;
}
inline XAxisType CGtV4d::X() const { return XAxisType(mData); }
// [L] hdr19: CGtV4d::SetX/SetY/SetZ(lane) in place on compiler-chosen registers (as CGtV3d::SetX/Y/Z(lane); retail Slerp builds its
// result in $vf5, 0x373DB0..0x373DF8); were hard-coded $vf1/$vf2 through GPRs. headsafe 0 DIFF.
inline void CGtV4d::SetX(XAxisType a) { asm("vaddx.x %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetY(float v) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2.ni %2, $vf2" "\n\t" "vaddx.y $vf1, $vf0, $vf2x" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(t) : "r"(mData), "r"(v));
    mData = t;
}
inline YAxisType CGtV4d::Y() const { return YAxisType(mData); }
inline void CGtV4d::SetY(YAxisType a) { asm("vaddy.y %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetZ(float v) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2.ni %2, $vf2" "\n\t" "vaddx.z $vf1, $vf0, $vf2x" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(t) : "r"(mData), "r"(v));
    mData = t;
}
inline ZAxisType CGtV4d::Z() const { return ZAxisType(mData); }   // [L] W()-style (N172); was `ZAxisType r; r.lVector = mData`
inline WAxisType CGtV4d::W() const { return WAxisType(mData); }   // [L] as CGtV3d::X()/Z() (CalculateSpeedMatch probe)
inline void CGtV4d::SetZ(ZAxisType a) { asm("vaddz.z %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }

// [L] API: B3O0PCH map (CGtV3d::Normalise(), 144 bytes out of line). The squared length (GetSquaredLength
// inlined), then 1/sqrt into Q and the scale, mData in and out through GPRs. NOT MATCHING YET (N136):
// CB3EnvironmentManager::Construct (0x2BCEC0) 11 instrs differ -- retail computes GetSquaredLength's 1.0 before the
// SetX/Y/Z chain and parks it in a GPR, and squares the stored vector straight from $vf1; our b119 computes it after
// (the scheduling family of N129). The .i moves keep the result's qmfc2 + sq (a .ni pair folds into sqc2).
// [L] hdr14 (N232): -O0 -inline off size 144 = the map [C] (was 88): `XAxisType l; l = GetSquaredLength();` (operator= call) and the
// result through a CGtV3d local assigned to *this. The map emits XAxisType::operator= and GetSquaredLength right after Normalise
// (0x132D80, reverse first-use order, N225's rule): its two new callees [L]. -O4 identical in every proven unit (headsafe).
inline void CGtV3d::Normalise() {
    XAxisType l;
    l = GetSquaredLength();
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "qmtc2 %1, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2 %0, $vf1" : "=r"(r.mData) : "r"(mData));
    asm(".set reorder");
    *this = r;
}

// FAKEMATCH [G]: retail's compiler (between b103 and b119, unavailable) hoisted GetSquaredLength's 1.0
// (`vaddw.x $vfC, $vf0, $vf0w`) out of call-free loops; b119 never hoists partial-lane VU writes (N157). The caller
// computes the 1.0 once, before the loop in the source:
//     u_long128 one;
//     asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));   // FAKEMATCH [G]: explicit 1.0 hoist (N157)
// and passes it in. The vector is squared in place on $vf1, the 1.0 is a "j" input (b119 keeps it in its VU register
// across the loop: $vf3 next to the operators' hard-coded $vf1/$vf2). [C] reproduces CB3PhysicsManager::
// UpdateNearMissArray (0x1B3EA0) 60/60 (build/vt/fh/nm4a.cpp). Defined last: no existing inline follows it.
inline XAxisType CGtV3d::GetSquaredLength(u_long128 one) const {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "vmul.xyz $vf1, $vf1, $vf1" "\n\t" "vadday.x $ACC, $vf1, $vf1y" "\n\t"
        "vmaddz.x $vf1, %2, $vf1z" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(mData), "j"(one));
    return XAxisType(t);
}

#endif

// ---- header-API proposal (build/vt/hdr, 2026-10-26): defined last, after every existing inline ----
#if defined(__MWERKS__)
// [L] API: B3O0PCH map (YAxisType::operator -(), 48 bytes). Retail: `vsub.y $vf1, $vf0, $vf1` (DetectAirAndGround archives).
inline YAxisType YAxisType::operator-() const {
    u_long128 t;
    asm("vsub.y %0, $vf0, %1" : "=j"(t) : "j"(lVector));   // gapJ [L]: compiler-chosen (retail ImpactBody 0x3DC84C `vsub.y $vf3,$vf0,$vf2`)
    return YAxisType(t);
}
// [L] API: B3O0PCH map (operator -(YAxisType, YAxisType), 80 bytes, free). Retail (CheckRaceCar 0x13EFA0):
// `lqc2 $vf1, b; lqc2 $vf2, a; vsuby.y $vf1, $vf2, $vf1y`.
// gapE [L]: three-operand form, compiler-chosen result (retail CreateRotationMatrix3x4 `vsuby.y $vf1,$vf7,$vf4y`, a still live;
// CheckRaceCar's `vsuby.y $vf1,$vf2,$vf1y` is the same text with b dead). Was "+j"(b). headsafe 0 DIFF.
inline YAxisType operator-(YAxisType a, YAxisType b) {
    u_long128 r;
    asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return YAxisType(r);
}
// [L] API: B3O0PCH map (operator -(YAxisType, float), 80 bytes, free). Retail (func_002F6140 0x2F6194):
// `lqc2 $vf1, a; qmtc2.ni f, $vf2; vsubx.y $vf1, $vf1, $vf2x`.
inline YAxisType operator-(YAxisType a, float f) {
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return YAxisType(r);
}
// [C] API: B3O0PCH map (operator +(YAxisType, YAxisType), 80 bytes, free). [L] body (hdr19): accumulated over the FIRST operand
// (`vaddy.y a, b, ay`: Slerp's y lane, Update__23CB3BehaviourInterpolateFP9CGtCameraf 0x373E04, like its x/z/w lanes); headsafe 0 DIFF.
// Was (hdr7): `vaddy.y b, a, by`, from ScaleAndFillInHullDetails__13CB3ConvexHull's local stand-in (an archive).
// gapE [L]: three-operand form as operator-(Y,Y) (retail CreateRotationMatrix3x4 `vaddy.y $vf3,$vf7,$vf4y`). Was "+j"(a).
inline YAxisType operator+(YAxisType a, YAxisType b) {
    u_long128 r;
    asm("vaddy.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return YAxisType(r);
}
// [C] API: B3O0PCH map (operator *(XAxisType/YAxisType/ZAxisType/WAxisType, float), 80 bytes each, free). [L] body (hdr7): the scalar
// moved by its own statement, then `vmulx.<lane> r, a, sx`, compiler-chosen (Prepare__19CB32dObjectGradient's v241 stand-ins).
inline XAxisType operator*(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
inline YAxisType operator*(YAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
inline ZAxisType operator*(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return ZAxisType(r); }
inline WAxisType operator*(WAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return WAxisType(r); }
// [C] API: B3O0PCH map (GtMathPs2::CrossProduct(CGtV3d, CGtV3d), 92 bytes, free). Retail (GetAvgRightwardsVector
// 0x147CB0, ConvertTo 0x...): `vopmula.xyz $ACC, a, b; vopmsub.xyz b, b, a` = a x b, result through qmfc2.ni.
// [L] body (gapC, build/vt/gapC/notes.txt): all 438 retail vopmsub.xyz are followed at once by an unfolded qmfc2.ni [C],
// which only a `.set noreorder` region keeps (N188; volatile does not); a and b both "+j": -O0 0x5C = map [C]; the
// header-shaped proven stand-ins (B3CameraUtils_002F6210, B3AILane_00147CB0/00147E90, B3AITarget_001495C0,
// B3VehiclePhysics_001CC580) compile identically when routed through this body [C].
inline CGtV3d CrossProduct(CGtV3d a, CGtV3d b) {
    u_long128 t;
    asm(".set noreorder");
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.ni %0, %1" : "=r"(t), "+j"(b.mData), "+j"(a.mData));
    asm(".set reorder");
    return CGtV3d(t);
}
// [C] API: B3O0PCH map (GtMathPs2::Min/Max(CGtV3d, CGtV3d), Min(CGtV4d, CGtV4d), 80 bytes each, free). [L] body (hdr7): one
// `vmini`/`vmax` on compiler-chosen registers (retail 52 vmini.xyz/vmax.xyz sites; RenderImage__16CGt2dObjectTable's v241 stand-in).
inline CGtV3d Min(CGtV3d a, CGtV3d b) { u_long128 r; asm("vmini.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
inline CGtV3d Max(CGtV3d a, CGtV3d b) { u_long128 r; asm("vmax.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
inline CGtV4d Min(CGtV4d a, CGtV4d b) { u_long128 r; asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV4d(r); }
// [L] API: B3O0PCH map: CGtV3dPlus::SetGtV3d(CGtV3d) 56 bytes, CGtPlane::SetNormal(CGtV3d) 56 bytes, CGtSphere::SetPosition
// (CGtV3d) 56 bytes (all one shape: xyz from the argument, the 4th lane of this kept). Retail: `vadd.xyz D, $vf0, S`
// with D loaded from the destination first (ExplodeVehicle, EndUpdate__16CB3ParticleArray, func_001AE360, the frustum
// tests, CGtSimpleOrientedBox::ConvertTo). Only the three types are given the xyz/w pair; a source's own CGtV4d field
// has no evidenced SetXYZ (no map name), so the destination types are these.
struct CGtV3dPlus {
    u_long128 mData;
    CGtV3dPlus() {}
    void SetGtV3d(CGtV3d v);
    // [L] API: B3O0PCH map (CGtV3dPlus::SetPlus(float), 72 bytes; WAxisType 56, Y/Z 80). Retail: `qmtc2.ni f, $vf1;
    // vsubw.w D, $vf0, $vf0w; vaddx.w D, D, $vf1x` (w = 0 + f, kept xyz).
    void SetPlus(float f);
    void SetPlus(YAxisType y);   // [C] API: B3O0PCH map (80 bytes); hdr7
    CGtV3d GtV3d() const { return CGtV3d(mData); }        // gapN: [C] API B3O0PCH map (52 bytes); [L] body as CGtPlane::Normal()
    WAxisType Plus() const { return WAxisType(mData); }   // gapN: [C] API B3O0PCH map (52 bytes); [L] body as CGtPlane::Distance()
    void SetPlus(WAxisType a);   // gapN: [C] API B3O0PCH map (56 bytes); defined at the end of this file
    // gapO: [C] API B3O0PCH map (CGtV3dPlus::Zero(), 0x17C480, 28 bytes = CGtV4d::Zero's size). [L] body as CGtV4d::Zero (retail
    // GetDrivingControls__17CB3RaceCarPhysics 0x1C19C4 `vsub.xyzw $vf1,$vf0,$vf0; sqc2` on field_B0, Revenge mLinearVelocityAndSpeed).
    void Zero() { u_long128 r; asm("vsub.xyzw $vf1, $vf0, $vf0" "\n\t" "qmfc2 %0, $vf1" : "=r"(r)); mData = r; }
};
struct CGtPlane {
    u_long128 mData;
    CGtPlane() {}
    CGtV3d Normal() const { return CGtV3d(mData); }          // [C] API: B3O0PCH map (52 bytes); layout Revenge stabs
    WAxisType Distance() const { return WAxisType(mData); }  // [C] API: B3O0PCH map (52 bytes)
    void SetNormal(CGtV3d v);
    // [L] API: B3O0PCH map (CGtPlane::SetDistance(float), 48 bytes): w = vf0.w * f, as CGtV4d::SetA
    void SetDistance(float f);
    void SetDistance(XAxisType d);   // [L] API: B3O0PCH map (56 bytes)
};
inline void CGtV3dPlus::SetGtV3d(CGtV3d v) { u_long128 m = mData; asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(v.mData)); mData = m; }
inline void CGtV3dPlus::SetPlus(float f) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(mData) : "j"(s));
}
// [L] hdr7: `vsubw.w D,$vf0,$vf0w; vaddy.w D,D,Sy` (w = 0 + y; SpawnBouncyPopcorn__15CB3PopcornArray, func_00263E80 stand-ins).
inline void CGtV3dPlus::SetPlus(YAxisType y) { asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddy.w %0, %0, %1y" : "+j"(mData) : "j"(y.lVector)); }
inline void CGtPlane::SetNormal(CGtV3d v) { asm("vadd.xyz %0, $vf0, %1" : "+j"(mData) : "j"(v.mData)); }
inline void CGtPlane::SetDistance(XAxisType d) {
    u_long128 t;
    asm("lqc2 %0, 0(%1)" : "=j"(t) : "r"(this));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(t) : "j"(d.lVector));
    asm("sqc2 %1, 0(%2)" : "=m"(mData) : "j"(t), "r"(this));
}
inline void CGtPlane::SetDistance(float f) { asm("qmtc2.ni %1, $vf2\n\tvmulx.w %0, $vf0, $vf2x" : "+j"(mData) : "r"(f)); }
// [L] API: B3O0PCH map: CGtSphere::SetPosition(CGtV3d) 56 bytes (as CGtPlane::SetNormal), SetRadius(float) 48 bytes (as
// SetDistance); Position()/Radius() 52 bytes. Layout [C] Revenge stabs (u_long128 mData). Retail: FrustumTest*Vehicle.
struct CGtSphere {
    u_long128 mData;
    CGtSphere() {}
    CGtV3d Position() const { return CGtV3d(mData); }
    WAxisType Radius() const { return WAxisType(mData); }
    void SetPosition(CGtV3d v);
    void SetRadius(float f);
    void SetRadius(WAxisType a);   // gapN: [C] API B3O0PCH map (56 bytes); defined at the end of this file
    void SetRadius(XAxisType a);   // gapN: [C] API B3O0PCH map (56 bytes)
};
// [L] hdrrd (2026-10-27): the argument read through its address (the N129 mechanism: its by-value slot stays in the frame).
// With SetRadius below: AddSphere__13CGtSphereTree and FrustumTestUndamagedVehicle__18CB3VehicleRenderer 0x220170 exact (lift3
// drafts), FrustumTestDamagedVehicle 0x220270 17 -> 9 changed. Was: "j"(v.mData).
inline void CGtSphere::SetPosition(CGtV3d v) { asm("vadd.xyz %0, $vf0, %1" : "+j"(mData) : "j"(*(const u_long128*)&v.mData)); }
// [L] hdrrd (2026-10-27): the scalar moved by its own statement onto a compiler-chosen register, as CGtV4d::SetW (retail
// AddSphere__13CGtSphereTree 0x35E750: `qmtc2 f,$vf1; vadd.xyz $vf3,$vf0,$vf2; vmulx.w $vf3,$vf0,$vf1x`; census of
// `vmulx.w D,$vf0,S`: S = $vf2 130, $vf1 122, $vf3 10). Was: `qmtc2.ni %1,$vf2; vmulx.w %0,$vf0,$vf2x` (no proven user).
inline void CGtSphere::SetRadius(float f) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(mData) : "j"(s));
}
// [L] API: B3O0PCH map (ZAxisType::operator -(), 48 bytes). gapN (2026-11-01) [L]: `vsub.z D,$vf0,S` (0 - z), as X/YAxisType::operator-:
// retail census (build/vt/gapN/censusZ.py) 28 vsub.z D,$vf0,S sites in 18 functions (GetMatrix__17CB3CameraKeyFrame 0x446F60, DrawGlobeHalo,
// FlyAround Prepare 0x2ECE0C, Prepare__17CB3VehiclePhysics 0x1CF800, ...) vs 1 site of `lui 0xBF80; qmtc2.ni; vmulx.z D,D,Sx`
// (Create__17CB3TrafficVehicle 0x1865D0) = operator *(ZAxisType, float) with -1.0f there [L] (the x lane: 48 vsub.x vs 3 -1.0 multiplies).
// Was (hdr): the -1.0 multiply through $vf2.x.
inline ZAxisType ZAxisType::operator-() const {
    u_long128 t;
    asm("vsub.z %0, $vf0, %1" : "=j"(t) : "j"(lVector));
    return ZAxisType(t);
}
// [L] API: B3O0PCH map (CGtV4d::SetW(float), 48 bytes). The CGtV3d::SetX/Y/Z recipe for lane w: vf0.w is 1, so w = 0
// (vsubw.w D,vf0,vf0w) then + the scalar (vaddx.w). Retail: CB3CoronaDynamicArray::EndUpdate (a CGtV4d's SetW(0.0f), the scalar
// qmtc2.ni'd into $vf2 ahead of a loop) and ExplodeVehicle (scalar in $vf1). NOT the SetA(float) body (vmulx.w, 1 op).
inline void CGtV4d::SetW(float w) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(w));
    asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(mData) : "j"(s));
}
#endif

// ---- header-API task 2 (build/vt/hdr, 2026-10-26) ----
#if defined(__MWERKS__)
// [L] API: B3O0PCH map (GtMathPs2::TransformPoint(const CGtMatrix3x4&, CGtV3d), 112 bytes). Retail (GetClosestBitToPoint 0x3E18E0):
// row 0 a VU operand (compiler-chosen), rows 1-3 each `qmtc2.ni row,$vf1` ahead of its ACC step, the point a VU operand,
// result `vmaddw.xyz $vf1,$vf1,$vf0w; qmfc2.ni`.
// [L] hdr15 (2026-10-27): `.set noreorder` / `.set reorder` inside the asm string (as NGL): keeps loads/stores out of the ACC chain
// (near14 backlog). GetNewBonnetLengths 95 -> 62, func_001C8120 51 -> 41, AddScrapeSegment 50 -> 48, DoVehicleSteam 25 -> 24 with its
// call-site noreorder statements dropped; headsafe 0 DIFF (no proven unit changes). -O0 100 (map 112, unchanged; open).
inline CGtV3d TransformPoint(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm(".set noreorder" "\n\t" "vmulax.xyz $ACC, %1, %2x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %2y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %2z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t" ".set reorder"
        : "=r"(t) : "j"(m.mRight.mData), "j"(v.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}

// [C] API: B3O0PCH map (GtMathPs2::TransformVector(const CGtMatrix3x4&, CGtV3d), 100 bytes). [L] body (hdr7): TransformPoint without
// the position row, `vmaddz.xyz $vf1,$vf1,vz` the last step (func_002F0440's v256 stand-in).
inline CGtV3d TransformVector(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddz.xyz $vf1, $vf1, %1z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    return CGtV3d(t);
}

// [L] API: B3O0PCH map (CGtMatrix3x4::SetIdentity(), 144 bytes). hdr7: four `vadd.xyz D,$vf0,$vf0` (xyz zeroed, w kept), then
// `vaddw.x/.y/.z` (1.0) on rows 0/1/2 (retail GetTrackMatrix__14CB3CameraUtils 0x2F6210, Construct__18CB3BodyPartPhysics 0x334680,
// Prepare__13CB3NetworkCar, 0x35BC10, 0x171E90: the proven sources' local V241_/A211_ macros, this exact sequence).
inline void CGtMatrix3x4::SetIdentity() {
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); mRight.mData = r; }
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); mUp.mData = r; }
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); mAt.mData = r; }
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); mPos.mData = r; }
    { u_long128 r = mRight.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); mRight.mData = r; }
    { u_long128 r = mUp.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); mUp.mData = r; }
    { u_long128 r = mAt.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); mAt.mData = r; }
}

// [L] API: B3O0PCH map (CGtV3d::IsZero(), 72 bytes). Retail (FindClosestDriveableAILaneSegment, unit_00147950 0x479A0,
// unit_001423E0 0x42430): the xyz lanes or-ed through two qfsrv rotations by 4 bytes, then the low word's sign bit
// dropped (dsll32/dsrl32 by 1); true when the result is 0. [G] the bool return.
// [L] hdr14 (N232): the bool through a ternary local gives -O0 size 72 = the map [C] (was 48); -O4 unchanged [G] form.
inline bool CGtV3d::IsZero() const {
    u_long128 r, t;
    asm("mtsab $0, 4" "\n\t" "qfsrv %1, %2, %2" "\n\t" "or %0, %2, %1" "\n\t" "qfsrv %1, %1, %1" "\n\t" "or %0, %0, %1" : "=r"(r), "=&r"(t) : "r"(mData));
    // gapJ [L]: the test returned directly. Retail's 6 inlined copies all branch on the masked value (dsll32/dsrl32 then bnez/beqz;
    // build/vt/gapJ notes); the hdr14 `bool b = ... ? true : false; return b;` (-O0 72 = map) materialises the bool with xor/sltiu
    // in CB3AICar::UpdateOutOfRange (0x142448). -O0 68 vs map 72 (the bool local's join andi).
    return (((unsigned long long)r & 0x7fffffffULL) == 0) ? true : false;
}

// ---- gapK (2026-10-31): CGtV3d::IsEffectivelyZero() ----
// [C] API: B3O0PCH map (CGtV3d::IsEffectivelyZero() 0x132EA0, 104 bytes, right after Normalise's helpers). [C] retail: the squared
// length (vmaddz.x) compared c.lt.s with 2^-32 (lui 0x2F80; 201 such constants in 112 functions, 48 straight after a squared length;
// func_00250350 0x2506A4 materialises the bool for a `== false` test, 0x25093C branches straight). [L] body: the float local and an
// if/else: -O0 104 = map [C] (direct `return GetSquaredLength() < K` 88; a float local + return 96; XAxisType local 116). Proven
// B3AICar_001419F0 `!fwd.IsEffectivelyZero()` compiles identically (gapK prov).
inline bool CGtV3d::IsEffectivelyZero() const
{
    float lrSquaredLength = GetSquaredLength();
    if (lrSquaredLength < 2.3283064e-10f)
        return true;
    else
        return false;
}

// [L] API: B3O0PCH map (CGtV3d::NormaliseGetLength(), 196 bytes). hdr9 (2026-10-27): Normalise's two-statement noreorder form with the
// length taken by the FPU in the rsqrt latency gap: `qmtc2 sq,$vf1; vrsqrt $Q,$vf0w,$vf1x; qmfc2 r,$vf1; mtc1 r,f; sqrt.s f,f; mfc1 r,f;
// qmtc2 r,$vf1; qmfc2 r,$vf1; vwaitq; qmtc2 v,$vf1; vmulq.xyz $vf1,$vf1,$Q; qmfc2 v,$vf1` (retail census build/vt/hdr9/census_ngl2.py:
// 100 sites, FPR compiler-chosen f0 89 / f1 10 / f4 1; GetDesiredDirection__11CB3AITarget 0x14A1C0). Returns the length.
// [L] hdr14 (N232): `XAxisType l; l = ...`, the length written back into l and returned, the vector via `*this = CGtV3d(t)`:
// -O0 size 204 = the map's 196 + the 2 hazard nops b119 puts after mtc1/mfc1 (retail's compiler emits none, N217) [L]. Its
// locals reserve retail's dead frame slots: GetDesiredDirection__11CB3AITarget needs no N140 pad with it (3 changed = the nops).
// [L] hdr15 (2026-10-27): `.set noreorder` / `.set reorder` also INSIDE the asm string (ghvu2, func_001BEEE0): b119 then emits no
// hazard nops after the mtc1/mfc1, as retail; -O0 196 = the map [C] (was 204). CalculateCarPositionInMap 27 -> 25, func_001BE3C0
// 81 -> 79; headsafe 0 DIFF. Closes N232's open nop item without a compiler patch.
inline XAxisType CGtV3d::NormaliseGetLength() {
    XAxisType l;
    l = GetSquaredLength();
    u_long128 t;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "qmtc2 %3, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t"
        "qmfc2 %0, $vf1" "\n\t" ".set reorder" : "=r"(t), "=&r"(l.lVector), "=&f"(f) : "r"(mData));
    asm(".set reorder");
    *this = CGtV3d(t);
    return l;
}
#endif

// ---- CGtV3d::GetLength (lift3, N195) ----
#if defined(__MWERKS__)
// [L] API: B3O0PCH map (CGtV3d::GetLength(), 140 bytes). Retail (GetWidth__9CB3AILaneCFUs 0x147C10, 26 unproven callers):
// the squared length through a GPR, `vsqrt $Q,$vf1x; vaddw.x $vf1,$vf0,$vf0w; qmfc2 t; vwaitq; qmtc2 t,$vf1;
// vmulq.x $vf1,$vf1,$Q; qmfc2 r` -- 1.0 * sqrt (.i moves). hdr9: the tail inside a `.set noreorder` region, as the proven local copies
// in func_00353FA0 / func_003E7390 (v257/v272: keeps stores and constants out of the vwaitq gap).
// [L] hdr14 (N232): the result through `XAxisType r; r = XAxisType(t); return r;` gives -O0 size 140 = the map [C] (was 96). The
// `XAxisType l; l = ...` head (as Normalise) also gives 140 but changes proven func_003E7390 (headsafe), so not that one.
inline XAxisType CGtV3d::GetLength() const {
    XAxisType l = GetSquaredLength();
    u_long128 one, t;
    XAxisType r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t), "=&r"(one) : "r"(l.lVector));
    asm(".set reorder");
    r = XAxisType(t);
    return r;
}
#endif


#if defined(__MWERKS__)
// [C] API: B3O0PCH map (GtMathPs2::CosAngleBetweenNormalisedVectors(CGtV3d, CGtV3d), 176 bytes). [L] body (hdr13): the dot product
// clamped to [-1, 1] in place on its compiler-chosen register (`vsubw.x m,$vf0,$vf0w; vmax.x d,d,m; vminiw.x d,d,$vf0w`);
// -O0 -inline off size 176 = the map [C] (hard-$vf1 GPR form 152, float return 160).
inline XAxisType CosAngleBetweenNormalisedVectors(CGtV3d a, CGtV3d b)
{
    XAxisType d = DotProduct(a, b);
    u_long128 m;
    asm("vsubw.x %0, $vf0, $vf0w" : "=j"(m));
    asm("vmax.x %0, %0, %1" "\n\t" "vminiw.x %0, %0, $vf0w" : "+j"(d.lVector) : "j"(m));
    return d;
}
// ---- gapE (2026-10-30): the CGtV3d members CreateRotationMatrix3x4 (GtMathPs2Trig.h) inlines ----
#if defined(__MWERKS__)
// [C] API: B3O0PCH map (names and sizes; their order after CreateRotationMatrix3x4 = reverse first use). [L] bodies: one VU op each,
// compiler-chosen registers (retail func_00429BE0 0x429E40..0x429EE8).
inline void CGtV3d::SetX(YAxisType a) { asm("vaddy.x %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetX(ZAxisType a) { asm("vaddz.x %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetY(XAxisType a) { asm("vaddx.y %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetY(ZAxisType a) { asm("vaddz.y %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetZ(XAxisType a) { asm("vaddx.z %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetZ(YAxisType a) { asm("vaddy.z %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
inline CGtV3d CGtV3d::operator*(CGtV3d o) const { u_long128 r; asm("vmul.xyz %0, %1, %2" : "=j"(r) : "j"(mData), "j"(o.mData)); return CGtV3d(r); }
inline CGtV3d CGtV3d::operator*(XAxisType a) const { u_long128 r; asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(mData), "j"(a.lVector)); return CGtV3d(r); }
inline CGtV3d& CGtV3d::operator*=(ZAxisType a) { asm("vmulz.xyz %0, %0, %1z" : "+j"(mData) : "j"(a.lVector)); return *this; }
inline CGtV3d& CGtV3d::operator+=(XAxisType a) { asm("vaddx.xyz %0, %0, %1x" : "+j"(mData) : "j"(a.lVector)); return *this; }
#endif

#endif

#if defined(__MWERKS__)
// ---- gapF (2026-10-30): GtMathPs2::Abs(CGtV3d), CGtMatrix3x4::OrthoNormalise() ----
// [C] API: B3O0PCH map (GtMathPs2::Abs(CGtV3d), 60 bytes, free; emitted right after OrthoNormalise = first used there).
// [L] body: one `vabs.xyz` on compiler-chosen registers (retail 44 vabs.xyz sites, e.g. the 11 inlined OrthoNormalise copies).
inline CGtV3d Abs(CGtV3d v) { u_long128 r; asm("vabs.xyz %0, %1" : "=j"(r) : "j"(v.mData)); return CGtV3d(r); }

// [G] gapF: CGtV3d::Normalise() in retail's in-place shape (N238's H1Q0N2V1R- body: vrsqrt; vwaitq; vmulq.xyz on the register
// that was squared), used for OrthoNormalise's rebuilt rows. Placeholder name (func_<first retail site>_inlN): retail inlines
// CGtV3d::Normalise there; FlyAround 0x2EC128.. (rows of a stack-local matrix) shows this shape, UpdateOutOfRange 0x1429E8..
// (rows behind a pointer) shows the header Normalise's -- and this body gives exactly that one there too [C, t4 probe].
inline void func_002EBED0_inl1(CGtV3d& v) {
    XAxisType l = v.GetSquaredLength();
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" "\n\t" ".set reorder" : "+j"(v.mData));
}
// [C] API: B3O0PCH map (CGtMatrix3x4::OrthoNormalise(), 1552 bytes; Abs(CGtV3d) its only new helper). [C] retail census: 11 inlined
// copies in 11 functions, no out-of-line copy (build/vt/gapF/census2.py). [L] body, decoded from FlyAround 0x2EBED0..0x2EC438 +
// 0x2EC6D0..0x2EC800: the three row lengths into one CGtV3d, a zero length rebuilds that row (and one more) from the other two;
// else the |dot products| into a CGtV3d choose the pair kept. Open: -O0 0x91C vs map 0x610 (a selector + switch shape gives 0x5F0
// but only 3 rebuild blocks at -O4, retail has 7) -- the E build's source may differ [G].
inline void CGtMatrix3x4::OrthoNormalise()
{
    CGtV3d lLengths;
    lLengths.SetX(mRight.NormaliseGetLength());
    lLengths.SetY(mUp.NormaliseGetLength());
    lLengths.SetZ(mAt.NormaliseGetLength());
    if (lLengths.X() > 0.0f) {
        if (lLengths.Y() > 0.0f) {
            if (lLengths.Z() > 0.0f) {
                CGtV3d lDots;
                lDots.SetX(DotProduct(mUp, mAt));
                lDots.SetY(DotProduct(mAt, mRight));
                lDots.SetZ(DotProduct(mRight, mUp));
                lDots = Abs(lDots);
                if (lDots.X() < lDots.Y()) {
                    if (lDots.X() < lDots.Z()) {
                        mRight = CrossProduct(mUp, mAt); func_002EBED0_inl1(mRight);
                        mAt = CrossProduct(mRight, mUp); func_002EBED0_inl1(mAt);
                    } else {
                        mAt = CrossProduct(mRight, mUp); func_002EBED0_inl1(mAt);
                        mUp = CrossProduct(mAt, mRight); func_002EBED0_inl1(mUp);
                    }
                } else if (lDots.Y() < lDots.Z()) {
                    mUp = CrossProduct(mAt, mRight); func_002EBED0_inl1(mUp);
                    mRight = CrossProduct(mUp, mAt); func_002EBED0_inl1(mRight);
                } else {
                    mAt = CrossProduct(mRight, mUp); func_002EBED0_inl1(mAt);
                    mUp = CrossProduct(mAt, mRight); func_002EBED0_inl1(mUp);
                }
            } else {
                mAt = CrossProduct(mRight, mUp); func_002EBED0_inl1(mAt);
                mUp = CrossProduct(mAt, mRight); func_002EBED0_inl1(mUp);
            }
        } else {
            mUp = CrossProduct(mAt, mRight); func_002EBED0_inl1(mUp);
            mRight = CrossProduct(mUp, mAt); func_002EBED0_inl1(mRight);
        }
    } else {
        mRight = CrossProduct(mUp, mAt); func_002EBED0_inl1(mRight);
        mAt = CrossProduct(mRight, mUp); func_002EBED0_inl1(mAt);
    }
}
// ---- gapH (2026-10-31): CGtMatrix3x4::Invert(), CGtV3d::operator*(YAxisType) / operator*(ZAxisType) ----
// [C] API: B3O0PCH map (CGtV3d::operator *(ZAxisType) 0x153BC0 and operator *(YAxisType) 0x153C10, 68 bytes each, emitted right
// after CGtMatrix3x4::Invert() = its new helpers, Y first used). [L] body: as operator*(XAxisType) (retail vmuly.xyz / vmulz.xyz with
// a lane operand: 77 / 283 sites).
inline CGtV3d CGtV3d::operator*(YAxisType a) const { u_long128 r; asm("vmuly.xyz %0, %1, %2y" : "=j"(r) : "j"(mData), "j"(a.lVector)); return CGtV3d(r); }
inline CGtV3d CGtV3d::operator*(ZAxisType a) const { u_long128 r; asm("vmulz.xyz %0, %1, %2z" : "=j"(r) : "j"(mData), "j"(a.lVector)); return CGtV3d(r); }
// [C] API: B3O0PCH map (CGtMatrix3x4::Invert(), 0x1539B0, 524 bytes). [C] retail census (build/vt/gapH/census_inv.py): 52 inlined
// copies in 33 functions, no out-of-line copy. [L] body (the orthonormal inverse in place, as the proven stand-ins of
// func_00333740 / func_00356FB0 / B3AICar_00141C10 / B3CrashCameraDirector_00356700): rows transposed by the cross-lane setters
// (from copies of the old rows), then mPos = -(R^T p) through the lane products, summed with +=.
inline void CGtMatrix3x4::Invert()
{
    CGtV3d lRight = mRight;
    CGtV3d lUp = mUp;
    CGtV3d lAt = mAt;
    mRight.SetY(lUp.X());
    mRight.SetZ(lAt.X());
    mUp.SetX(lRight.Y());
    mUp.SetZ(lAt.Y());
    mAt.SetX(lRight.Z());
    mAt.SetY(lUp.Z());
    CGtV3d lPos = mPos;
    CGtV3d lZ = mAt * lPos.Z();
    CGtV3d lX = mRight * lPos.X();
    CGtV3d lResult = lX + mUp * lPos.Y();
    lResult += lZ;
    mPos = -lResult;
}
// ---- gapH (2026-10-31): GtMathPs2::Matrix3x4SetLookAt ----
// [C] API: B3O0PCH map (Matrix3x4SetLookAt(CGtV3d) 0x16A700 100 bytes, Matrix3x4SetLookAt(CGtV3d, CGtV3d) 0x16A770 432 bytes,
// emitted in that order in CB3RaceCar::RepositionCarInLane's queue: the one-argument form calls the two-argument one).
// [L] body, decoded from the retail sites (RepositionCarInLane 0x1512E4, Update__18CB3BehaviourRotate 0x2E61B8, Update__18CB3BehaviourOffset
// 0x2E2934 x5, Prepare__21CB3BehaviourTrackSide 0x2FEF4C, ...): at kept as given (RepositionCarInLane normalises it in the caller
// and stores it before the up vector is built), right = up x at normalised in place, up = at x right, mPos left unwritten (the
// callers that store a position write it after). The one-argument form passes (0, 1, 0) built on the stack (RepositionCarInLane
// 0x1512C4: `sw 1.0, 4(sp)`). Open: -O0 0xF4 / 0x70 vs the map's 0x1B0 / 0x64.
inline CGtMatrix3x4 Matrix3x4SetLookAt(CGtV3d at, CGtV3d up)
{
    CGtMatrix3x4 lReturnMatrix;
    lReturnMatrix.mAt = at;
    lReturnMatrix.mRight = CrossProduct(up, lReturnMatrix.mAt);
    func_002EBED0_inl1(lReturnMatrix.mRight);
    lReturnMatrix.mUp = CrossProduct(lReturnMatrix.mAt, lReturnMatrix.mRight);
    return lReturnMatrix;
}
inline CGtMatrix3x4 Matrix3x4SetLookAt(CGtV3d at) { return Matrix3x4SetLookAt(at, CGtV3d(0.0f, 1.0f, 0.0f)); }
#endif

// ---- gapN (2026-11-01): CGtV3d WAxisType members ----
// [C] API: B3O0PCH map: CGtV3d::operator *(WAxisType) 0x1646A0 (68 bytes, as operator *(X/Y/ZAxisType)), operator -(WAxisType) 0x28DA20
// (68), operator +=(WAxisType) 0x22BA30 (76, as operator +=(XAxisType)), SetX/SetY/SetZ(WAxisType) 0x132F60/0x225670/0x22B900 (56, as the
// other cross-lane setters). [L] bodies as their X/Y/Z siblings (retail func_001B2BA0 0x1B3188 `vmulw.xyz $vf15,$vf15,$vf12w`,
// VehicleTrafficResponse 0x1B60C8, func_0035A270 0x35A4D8).
#if defined(__MWERKS__)
inline CGtV3d CGtV3d::operator*(WAxisType a) const { u_long128 r; asm("vmulw.xyz %0, %1, %2w" : "=j"(r) : "j"(mData), "j"(a.lVector)); return CGtV3d(r); }
inline CGtV3d CGtV3d::operator-(WAxisType a) const { u_long128 r; asm("vsubw.xyz %0, %1, %2w" : "=j"(r) : "j"(mData), "j"(a.lVector)); return CGtV3d(r); }
inline CGtV3d& CGtV3d::operator+=(WAxisType a) { asm("vaddw.xyz %0, %0, %1w" : "+j"(mData) : "j"(a.lVector)); return *this; }
inline void CGtV3d::SetX(WAxisType a) { asm("vaddw.x %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetY(WAxisType a) { asm("vaddw.y %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3d::SetZ(WAxisType a) { asm("vaddw.z %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
#endif

// ---- gapN (2026-11-01): the remaining CGtV4d cross-lane setters, Abs(CGtV4d) ----
// [C] API: B3O0PCH map (56 bytes each): CGtV4d::SetX(YAxisType) 0x164880, SetY(ZAxisType) 0x1648C0, SetX(WAxisType) 0x36B5C0, SetY(WAxisType)
// 0x36B580, SetZ(XAxisType) 0x36B540, SetZ(WAxisType) 0x36B500. [L] bodies as SetX(ZAxisType): `vadd<s>.<d> D,$vf0,S` (retail
// ConstructPerspective__17CGtFrustumBuilder 0x349BB8.., the frustum's SoA side planes).
// [C] API: B3O0PCH map (GtMathPs2::Abs(CGtV4d) 0x1BC6B0, 60 bytes, as Abs(CGtV3d)). [L] body: one vabs.xyzw (retail 0x1BCB40).
#if defined(__MWERKS__)
inline void CGtV4d::SetX(YAxisType a) { asm("vaddy.x %0, $vf0, %1y" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetX(WAxisType a) { asm("vaddw.x %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetY(ZAxisType a) { asm("vaddz.y %0, $vf0, %1z" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetY(WAxisType a) { asm("vaddw.y %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetZ(XAxisType a) { asm("vaddx.z %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV4d::SetZ(WAxisType a) { asm("vaddw.z %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
inline CGtV4d Abs(CGtV4d v) { u_long128 r; asm("vabs.xyzw %0, %1" : "=j"(r) : "j"(v.mData)); return CGtV4d(r); }
#endif

// ---- gapN (2026-11-01): CGtSphere::SetRadius(lane), CGtV3dPlus::GtV3d() / Plus() / SetPlus(WAxisType) ----
// [C] API: B3O0PCH map: CGtSphere::SetRadius(WAxisType) 0x1A6F60 and SetRadius(XAxisType) 0x1BE400 (56 bytes, as CGtV4d::SetW(lane));
// CGtV3dPlus::GtV3d() 0x14D670 and Plus() 0x14A870 (52 bytes, as CGtPlane::Normal()/Distance()), SetPlus(WAxisType) 0x1A77B0 (56).
// [L] bodies: SetRadius as CGtV4d::SetW(W/XAxisType), `vmul<l>.w D,$vf0,S` (retail CollideWheelWithWorld 0x3331E4 `vmulw.w`); GtV3d/Plus
// as CGtPlane's getters; SetPlus(WAxisType) one `vmove.w D,S` (retail Update__17CB3VehiclePhysics 0x1CEAC4..0x1CEAE4).
#if defined(__MWERKS__)
inline void CGtSphere::SetRadius(WAxisType a) { asm("vmulw.w %0, $vf0, %1w" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtSphere::SetRadius(XAxisType a) { asm("vmulx.w %0, $vf0, %1x" : "+j"(mData) : "j"(a.lVector)); }
inline void CGtV3dPlus::SetPlus(WAxisType a) { asm("vmove.w %0, %1" : "+j"(mData) : "j"(a.lVector)); }
#endif

// ---- gapN (2026-11-01): CGtMatrix3x4::operator*=, TransformPoints(3x4), TransformVector(3x3) ----
// [C] API: B3O0PCH map: CGtMatrix3x4::operator *=(const CGtMatrix3x4&) 0x1BB9C0 (176 bytes; first used by GetCrashingDrivingControls,
// TransformVector(3x4) emitted right after it); GtMathPs2::TransformPoints(const CGtMatrix3x4&, CGtV3d*, const CGtV3d*, int) 0x1BF720
// (148 bytes); TransformVector(const CGtMatrix3x3&, CGtV3d) 0x1A6130 (76 bytes).
// [L] bodies: operator*= = `*this = *this * m` (retail 0x1BC5F0..0x1BC6B4 keeps the product's extra 4-row copies on the stack, as the
// header operator*'s unelided return); TransformPoints as the CGtMatrix2x3 form (one TransformPoint per element; retail
// DoCollideHullToHull 0x2B8C40 keeps the rows in VU registers across the loop); TransformVector(3x3) as the 3x4 form with rows 1-2
// moved `qmtc2.ni` into $vf2 (retail RaceCarRaceCarResponse 0x1B6528, BodyBodyResponse: vmulax / vmadday / vmaddz).
#if defined(__MWERKS__)
inline CGtMatrix3x4& CGtMatrix3x4::operator*=(const CGtMatrix3x4& m) { *this = *this * m; return *this; }
inline void TransformPoints(const CGtMatrix3x4& m, CGtV3d* dst, const CGtV3d* src, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = TransformPoint(m, src[i]);
}
inline CGtV3d TransformVector(const CGtMatrix3x3& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.ni %3, $vf2" "\n\t" "vmadday.xyz $ACC, $vf2, %1y" "\n\t" "qmtc2.ni %4, $vf2" "\n\t"
        "vmaddz.xyz $vf2, $vf2, %1z" "\n\t" "qmfc2.ni %0, $vf2"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    return CGtV3d(t);
}
#endif

} // namespace GtMathPs2
#endif
