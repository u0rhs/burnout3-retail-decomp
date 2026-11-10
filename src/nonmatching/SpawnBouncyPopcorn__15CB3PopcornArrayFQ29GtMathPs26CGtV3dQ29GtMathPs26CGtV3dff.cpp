// NONMATCHING: SpawnBouncyPopcorn__15CB3PopcornArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dff -- retail 111 / ours 112 instructions, 60 in changed runs
// hdr7: stand-ins rerouted to the N212 header APIs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: SpawnBouncyPopcorn__15CB3PopcornArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dff -- retail 111 / ours 112 instructions, 60 in changed runs
// hdr7: local stand-ins rerouted to the hdr7 header APIs (build/vt/hdr/inc_hdr7)
// v242: logic complete, block layout and VU registers exact (112 vs 111, 61 changed, frame 0x40 vs 0xE0). Slot = field_1C[i/4] (0x90 blocks: float t[4] + 4 x {CGtV3dPlus pos, vel}), i&3 kept; wrap via goto (out-of-line b back; sw zero). Bounce: vy = vel.Y() (negated if vy<0 && h<=0), d = vy^2 - g*h; d<=0: pos/vel SetGtV3d + SetPlus(Y lane); else tt = field_14*(sqrt(d)+vy), nv = field_18*(vy+g*tt) - g*tt, w = pos.Y()-h-nv*tt-0.5*field_10*tt*tt. Stand-ins: SetPlus(YAxisType) (map 80 bytes), operator-(YAxisType,float) with the float on $vf1 (header has $vf2). Left: float scheduling in the bounce arm (retail moves h into VU right after SetGtV3d), a2/a3/t0 temp swap, frame (retail 0xE0: 6 slots above the vy lane copy, 5 below).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" float sqrtf(float);
namespace GtMathPs2 {
// [L] N185: stands in for a missing GtMathPs2 inline (CGtV3dPlus::SetPlus(YAxisType), B3O0PCH map 80 bytes): w = 0 + y


}
struct UnkStruct_00365E80_p { CGtV3dPlus field_0; CGtV3dPlus field_10; };
struct UnkStruct_00365E80_b { float field_0[4]; UnkStruct_00365E80_p field_10[4]; };

class CB3PopcornArray {
public:
    void SpawnBouncyPopcorn(CGtV3d pos, CGtV3d vel, float t, float h);
    u_long128 field_0;
    float field_10;
    float field_14;
    float field_18;
    UnkStruct_00365E80_b *field_1C;
    char *field_20;
    int field_24;
    int field_28;
};

// 0x00365E80
void CB3PopcornArray::SpawnBouncyPopcorn(CGtV3d pos, CGtV3d vel, float t, float h)
{
    CGtV3d pc = pos;
    CGtV3d vc = vel;
    int i = field_28;
    int q = i / 4;
    int r = i & 3;
    UnkStruct_00365E80_b *b = &field_1C[q];
    UnkStruct_00365E80_p *p = &b->field_10[r];
    field_28++;
    if (field_28 == field_24) goto wrap;
back:
    float vy = vc.Y();
    if (vy < 0.0f && h <= 0.0f) vy = -vy;
    float g = field_10;
    float d = vy * vy - g * h;
    if (d <= 0.0f) {
        p->field_0.SetGtV3d(pc);
        (p->field_0).SetPlus(pc.Y());
        p->field_10.SetGtV3d(vc);
        (p->field_10).SetPlus(vc.Y());
        b->field_0[r] = t;
        return;
    } else {
        float s = sqrtf(d);
        float tt = field_14 * (s + vy);
        float gt = g * tt;
        float nv = field_18 * (vy + gt) - gt;
        p->field_0.SetGtV3d(pc);
        (p->field_0).SetPlus(((((((pc.Y()) - (h))) - (nv * tt))) - (0.5f * field_10 * tt * tt)));
        p->field_10.SetGtV3d(vc);
        p->field_10.SetPlus(nv);
        b->field_0[r] = t;
    }
    return;
wrap:
    field_28 = 0;
    goto back;
}
