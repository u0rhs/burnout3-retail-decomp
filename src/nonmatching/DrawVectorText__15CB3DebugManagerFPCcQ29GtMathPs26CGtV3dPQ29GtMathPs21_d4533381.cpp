// NONMATCHING: DrawVectorText__15CB3DebugManagerFPCcQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4fQ29GtMathPs26CGtV4d -- retail 235 / ours 235 instructions, 54 in changed runs
// near35: up-terms passed as explicit CGtV3d(m->mUp * k) copy temporaries through a const-ref helper (67 -> 54). Left: retail gives every CGtV3d*float result a 16-byte slot (frame 0x1A0 vs 0x100) and spills the up-term across the unsigned-char->float branch with sqc2 0xF0/0xD0 (ours qmfc2/qmtc2 through a GPR); const-ref/by-value helper params and read-back-through-address stand-ins tried (latter much worse)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: DrawVectorText__15CB3DebugManagerFPCcQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4fQ29GtMathPs26CGtV4d -- retail 235 / ours 235 instructions, 67 in changed runs
// v293: logic and block layout complete (char classes digit/a-z/A-Z/':'..'@' with idx = c-0x21 into gaSymbolMaps2 as retail, 24-byte glyphs of 4-byte segments, start = cursor + right*(-s/128)*seg[0] + up*(s/128)*seg[1], advance right*-1.3*scale; extern C link name with pointer params [G]). 67 left: retail gives every CGtV3d::operator*(float) result a 16-byte frame slot (10 temps, frame 0x1A0 vs 0x100) so the up-term B crossing the conversion branch lives in memory (sqc2 0xF0/0xD0) where ours goes through a GPR; f21/f22 swap (nk vs the -1.3 literal); colour loaded before pos. Scalar-first product stand-in (vector*k evaluated before the (float)seg conversion) is needed for retail's order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3DebugManager::DrawVectorText(const char*, CGtV3d, CGtMatrix3x4*, float, CGtV4d). Field names placeholders [G].
#include "b3/GtMathPs2.h"
#include "b3/classes/CB3DebugManager.h"
using namespace GtMathPs2;

struct CGtLine { CGtV3d mStart; CGtV3d mEnd; };   // [G] layout: the two points DrawLine reads
extern unsigned char gaSymbolMaps2[7][24];
extern unsigned char gaDigitMaps[10][24];
extern unsigned char gaAlphaMaps[26][24];
extern "C" void DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(CB3DebugManager *, const CGtLine &, const void *);

// [L] N185: stands in for CGtV3d::operator+ on compiler-chosen VU registers (retail `vadd.xyz vf1,vf1,vf3`)
static inline CGtV3d func_00130390_inl1(const CGtV3d &a, CGtV3d b)
{
    u_long128 t;
    asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}

// [L] N185: scalar-first product (the vector operand is evaluated before the scalar, as retail)
static inline CGtV3d func_00130390_inl2(float f, const CGtV3d &v) { const CGtV3d &w = v; return w * f; }

// 0x00130390
extern "C" void DrawVectorText__15CB3DebugManagerFPCcQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4fQ29GtMathPs26CGtV4d(
    CB3DebugManager *self, const char *text, const CGtV3d *pos, CGtMatrix3x4 *m, float scale, const CGtV4d *colour)
{
    CGtV3d p = *pos;
    CGtV4d col(colour->mData);
    CGtMatrix3x4 ident;
    if (m == 0) {
        ident.SetIdentity();
        m = &ident;
    }
    CGtV3d cursor = p;
    while (*text != 0) {
        int c = *text;
        unsigned char (*map)[24];
        int idx;
        if (c >= '0' && c <= '9') { map = gaDigitMaps; idx = c - '0'; }
        else if (c >= 'a' && c <= 'z') { map = gaAlphaMaps; idx = c - 'a'; }
        else if (c >= 'A' && c <= 'Z') { map = gaAlphaMaps; idx = c - 'A'; }
        else if (c >= ':' && c <= '@') { map = gaSymbolMaps2; idx = c - '!'; }
        else map = 0;
        if (map != 0) {
            float k = scale / 128.0f;
            float nk = -k;
            unsigned char *s = map[idx];
            while (s[0] != 0 || s[2] != 0 || s[1] != 0 || s[3] != 0) {
                CGtLine line;
                line.mStart = func_00130390_inl1(func_00130390_inl1(cursor, func_00130390_inl2((float)s[0], m->mRight * nk)), func_00130390_inl2((float)s[1], CGtV3d(m->mUp * k)));
                line.mEnd = func_00130390_inl1(func_00130390_inl1(cursor, func_00130390_inl2((float)s[2], m->mRight * nk)), func_00130390_inl2((float)s[3], CGtV3d(m->mUp * k)));
                DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(self, line, &col);
                s += 4;
            }
        }
        cursor += m->mRight * -1.3f * scale;
        text++;
    }
}
