// NONMATCHING: _DrawBezierSpline__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4dff -- retail 100 / ours 100 instructions, 36 in changed runs
// sm9: frame 0xF0 and every slot exact (named dir/a/b assigned after declaration keep the dead caller temps); left: retail loads all y lanes first (p0.y,p1.y,p3.y,p0.x..) and copies a before dir; ours interleaves dir.x first. Statement permutations, ctor-form subtract, 14 pragmas tried.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct CGtTexture;
struct CGtBezierSection {
    CGtV2d pt[4];
    float field_20;
    float field_24;
};

extern "C" void _SubdivideCurveSection__16CGt2dBezierCurveFP16CGtBezierSectionP16CGtBezierSectionP16CGtBezierSection(CGtBezierSection *, CGtBezierSection *, CGtBezierSection *);
extern "C" void _RenderCurveSection__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4df(
    const CGt2dObject::CGt2dObjectSpace &, const void *, CGtBezierSection *, CGtTexture *, CGtV4d, float);

// [L] N185: stands in for CGtV2d::Normalise() (B3O0PCH map, no header body yet)
static inline void func_0041DF90_inl1(CGtV2d &v)
{
    float *py = &v.marValues[1];
    float one = 1.0f;
    float inv;
    asm("rsqrt.s %0, %1, %2" : "=f"(inv) : "f"(one), "f"(*py * *py + v.marValues[0] * v.marValues[0]));
    v.marValues[0] *= inv;
    *py *= inv;
}
// [L] N185: stands in for GtMathPs2::DotProduct(const CGtV2d&, const CGtV2d&) (B3O0PCH map)
static inline float func_0041DF90_inl2(const CGtV2d &p, const CGtV2d &q)
{
    return p.marValues[0] * q.marValues[0] + p.marValues[1] * q.marValues[1];
}
static inline CGtV2d func_0041DF90_inl5(const CGtV2d &p, const CGtV2d &q)
{
    CGtV2d r(p.marValues[0] - q.marValues[0], p.marValues[1] - q.marValues[1]);
    return r;
}
extern "C" void _DrawBezierSpline__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4dff(
    const CGt2dObject::CGt2dObjectSpace & space, const void * data, CGtBezierSection * sec, CGtTexture * tex, CGtV4d colour, float tol, float width)
{
    CGtV2d dir;
    CGtV2d a;
    CGtV2d b;
    dir = sec->pt[3] - sec->pt[0];
    a = sec->pt[1] - sec->pt[0];
    b = sec->pt[2] - sec->pt[3];
    func_0041DF90_inl1(dir);
    float da = func_0041DF90_inl2(CGtV2d(-dir.Y(), dir.X()), a);
    float db = func_0041DF90_inl2(CGtV2d(-dir.Y(), dir.X()), b);
    if (GtMath::Max(GtMath::Abs(da), GtMath::Abs(db)) >= tol) {
        CGtBezierSection l;
        CGtBezierSection r;
        _SubdivideCurveSection__16CGt2dBezierCurveFP16CGtBezierSectionP16CGtBezierSectionP16CGtBezierSection(sec, &l, &r);
        _DrawBezierSpline__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4dff(space, data, &l, tex, space.mColour, tol, width);
        _DrawBezierSpline__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4dff(space, data, &r, tex, space.mColour, tol, width);
    } else {
        _RenderCurveSection__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4df(space, data, sec, tex, space.mColour, width);
    }
}

