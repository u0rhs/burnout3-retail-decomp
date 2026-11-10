// NONMATCHING: DrawIntervals__22CB3PhysicsManagerDebugFv -- retail 161 / ours 160 instructions, 72 in changed runs
// v285: logic complete (160/161). Y lane copy = c[i].SetY(CGtV3d(D_0064D3E0).Y()) (explicit copy temp, hoisted sq+lqc2 as retail); col SetY(float) on compiler-chosen regs via [L] N185 stand-in (CGtV4d::SetY(float) hard form can't hoist the 1.0 qmtc2). Left: frame 0x110 vs 0x220 -- retail has 8 dead caller-temp slots under the Y copy (0x120-0x190) and 9 dead inline slots under the CGtV4d ctor temp (0x80-0x100), probably the 8 X()/Z() lane temps + 9 SetX/SetZ/SetY by-value params (header lane-type shape); s-register order (retail pm=s0, i=s1, &line.f10=s3; ours pm=s1, i=s4, s0); retail rematerialises 1.0f (lui) in the loop guard, ours CSEs it with the ctor's 0x3F800000.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// DrawIntervals: draws each physics body's x/z interval box at the reference height; magenta, Y lifted to 1 when
// some overlap pair references the body. [G] meanings.
struct CGtLine { CGtV3d field_0; CGtV3d field_10; CGtLine() {} CGtLine(CGtV3d a, CGtV3d b) { field_0 = a; field_10 = b; } };
struct UnkStruct_002BE770_body { unsigned char pad_0[0x10]; CGtV3d field_10; CGtV3d field_20; };
struct UnkStruct_002BE770_pair { UnkStruct_002BE770_body *field_0; UnkStruct_002BE770_body *field_4; unsigned char pad_8[0x28]; };
class CB3PhysicsManager {
public:
    unsigned char pad_0[0x70];
    UnkStruct_002BE770_body field_70[0x990];
    int field_1CB70;
    unsigned char pad_1CB74[0xE6234 - 0x1CB74];
    UnkStruct_002BE770_pair field_E6234[255];
    unsigned char pad_E9204[0xC];
    int field_E9210;
};
extern CB3PhysicsManager D_0055EF70;
extern CGtV3d D_0064D3E0;
struct UnkStruct_D_004EB1E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern "C" void DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(void *, const CGtLine &, CGtV4d);
// [L] N185: stands in for a missing GtMathPs2 inline (CGtV4d::SetY(float) on compiler-chosen registers, as CGtV3d's)
static inline void v285_sety(CGtV4d &v, float y)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(y));
    asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s));
}
class CB3PhysicsManagerDebug {
public:
    void DrawIntervals();
};
// 0x002BE770
void CB3PhysicsManagerDebug::DrawIntervals()
{
    CGtV4d col(1.0f, 0.0f, 1.0f, 1.0f);
    CGtV3d c[4];
    CGtLine line;
    for (int i = 0; i < 4; i++) c[i].SetY(CGtV3d(D_0064D3E0).Y());
    CB3PhysicsManager * const pm = &D_0055EF70;
    for (int i = 0; i < pm->field_1CB70; i++) {
        UnkStruct_002BE770_body *b = &pm->field_70[i];
        v285_sety(col, 0.0f);
        for (int j = 0; j < pm->field_E9210; j++) {
            if (pm->field_E6234[j].field_0 == b || pm->field_E6234[j].field_4 == b) v285_sety(col, 1.0f);
        }
        c[0].SetX(b->field_10.X()); c[0].SetZ(b->field_10.Z());
        c[1].SetX(b->field_20.X()); c[1].SetZ(b->field_10.Z());
        c[2].SetX(b->field_20.X()); c[2].SetZ(b->field_20.Z());
        c[3].SetX(b->field_10.X()); c[3].SetZ(b->field_20.Z());
        line.field_0 = c[0]; line.field_10 = c[1];
        DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, line, col);
        line.field_0 = c[1]; line.field_10 = c[2];
        DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, line, col);
        line.field_0 = c[2]; line.field_10 = c[3];
        DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, line, col);
        line.field_0 = c[3]; line.field_10 = c[0];
        DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, line, col);
    }
}
