// NONMATCHING: GetCrashZoneAndCorner__22CB3CrashActionDirectorFPQ29GtMathPs26CGtV3dP17CGtAxisAlignedBoxP10EB3CADZoneP12EB3CADCorner -- retail 139 / ours 142 instructions, 94 in changed runs
// fix2 (2026-11-01): the two outputs were swapped: retail writes the 0..3 result through a3 (EB3CADZone*, 3rd parameter by the mangled name) and the 0..4 result through t0 (EB3CADCorner*) [C] retail 0x1B1110..0x1B122C | Before: ghvu7 logic-complete draft (t = (p-b10)/(b0-b10) per lane; corner from x<z and 1-x<z; zone from x/z vs 0.3/0.7). 142/139, 102 changed, frame 0x220 vs 0x3C0: retail's 60-slot frame interleaves live lane copies (0x10..0x1A0, t at 0x3B0) with dead by-value lane temporaries -- needs the real lane APIs operator-(X/Y/ZAxisType,...), operator-(float,XAxisType), CGtV3d::SetX/Y/Z(float) compiler-chosen
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3CrashActionDirector::GetCrashZoneAndCorner(CGtV3d*, CGtAxisAlignedBox*, EB3CADZone*, EB3CADCorner*) --
// hand-written draft (ghvu7) from the Ghidra draft. [C] name: the mangled symbol in retail's tables. Field names are
// placeholders and every type is [G]. The position is normalised into the box (t = (p - b.field_10) / (b.field_0 -
// b.field_10) per lane); the corner comes from t.x vs t.z and 1 - t.x vs t.z, the zone from t.x / t.z against 0.3 / 0.7.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EB3CADZone {};
enum EB3CADCorner {};
struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };
class CB3CrashActionDirector {
public:
    void GetCrashZoneAndCorner(CGtV3d *, CGtAxisAlignedBox *, EB3CADZone *, EB3CADCorner *);
};

// [L] N185: lane subtracts on compiler-chosen registers (operator -(XAxisType/YAxisType/ZAxisType, ...), B3O0PCH map).
static inline XAxisType func_001B1010_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return XAxisType(r); }
static inline YAxisType func_001B1010_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return YAxisType(r); }
static inline ZAxisType func_001B1010_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return ZAxisType(r); }
// [L] N185: operator -(float, XAxisType).
static inline XAxisType func_001B1010_inl4(float f, XAxisType x) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %0, %1x" : "+j"(s) : "j"(x.lVector)); return XAxisType(s); }
// [L] N185: CGtV3d lane setters from a float on compiler-chosen registers.
static inline void func_001B1010_inl5(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_001B1010_inl6(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_001B1010_inl7(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }

// 0x001B1010
void CB3CrashActionDirector::GetCrashZoneAndCorner(CGtV3d *pos, CGtAxisAlignedBox *box, EB3CADZone *zone, EB3CADCorner *corner)
{
    CGtV3d t;
    func_001B1010_inl5(t, (float)func_001B1010_inl1(*pos, box->field_10) / (float)func_001B1010_inl1(box->field_0, box->field_10));
    func_001B1010_inl6(t, (float)func_001B1010_inl2(*pos, box->field_10) / (float)func_001B1010_inl2(box->field_0, box->field_10));
    func_001B1010_inl7(t, (float)func_001B1010_inl3(*pos, box->field_10) / (float)func_001B1010_inl3(box->field_0, box->field_10));
    // fix2: [C] retail 0x1B1110..0x1B1164 writes 0..3 through a3 (the EB3CADZone* by the mangled order) and
    // 0x1B1170..0x1B122C writes 0..4 through t0 (the EB3CADCorner*): the draft had the two outputs swapped
    if (t.X() < t.Z()) {
        if (func_001B1010_inl4(1.0f, t.X()) < t.Z()) *zone = (EB3CADZone)0;
        else *zone = (EB3CADZone)2;
    } else {
        if (func_001B1010_inl4(1.0f, t.X()) < t.Z()) *zone = (EB3CADZone)3;
        else *zone = (EB3CADZone)1;
    }
    *corner = (EB3CADCorner)0;
    if (t.X() < 0.3f) {
        if (t.Z() < 0.3f) *corner = (EB3CADCorner)2;
        else if (!(t.Z() <= 0.7f)) *corner = (EB3CADCorner)1;
    } else if (!(t.X() <= 0.7f)) {
        if (t.Z() < 0.3f) *corner = (EB3CADCorner)4;
        else if (!(t.Z() <= 0.7f)) *corner = (EB3CADCorner)3;
    }
}
