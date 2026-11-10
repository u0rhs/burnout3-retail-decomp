// NONMATCHING: ClampToWithinDesiredLanes__17CB3AITargetSplineCFQ29GtMathPs26CGtV3dPC9CB3AILaneUsPQ29GtMathPs26CGtV3d -- retail 124 / ours 123 instructions, 9 in changed runs
// near25: probe loads seg2 before link (fixes the s4/s5 swap), 'while ((u != 0) ^ 1)' gives retail's sltu/xori/bnez shared test. Left (123 vs 124): retail computes &p into v1 right after sd ra and passes it with move a1,v1 (ours addiu a1,sp,0x90 in the delay slot; pp locals, assignment copy, member-call forms don't move it), and the first probe's lw field_154 scheduled before the seg*10 addu
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a91: peeled first iteration + shared tail reproduced with a PROBE macro; remaining: s4/s5 (link/seg2) swapped, u&4 test shared via sltu/xori+bnez in retail (ours beqz), early &pos copy in v1, load order of tg. 3 instrs short.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3AITargetSpline::ClampToWithinDesiredLanes(GtMathPs2::CGtV3d, const CB3AILane*, unsigned short, GtMathPs2::CGtV3d*) const -- hand-written (lifter refused).
#include "b3/GtMathPs2.h"
class CB3AILane;
class CB3AITarget {
public:
    unsigned int LaneIsUndesirable(const CB3AILane *, unsigned short) const;
};
struct UnkStruct_00149C90_e {
    unsigned char pad_0[4];
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_00149C90_road {
    unsigned char pad_0[8];
    UnkStruct_00149C90_e *field_8;
};
class CB3AILane {
public:
    unsigned char pad_0[4];
    UnkStruct_00149C90_road *field_4;
};
struct UnkStruct_00149C90_car {
    unsigned char pad_0[0x19F0];
    CB3AITarget field_19F0;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
extern "C" int IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(const CB3AILane *, const void *, unsigned short);
extern "C" int LaneIsDriveable__9CB3AILaneFUcUsUs(unsigned char, unsigned short, unsigned short);
class CB3AITargetSpline {
public:
    void ClampToWithinDesiredLanes(GtMathPs2::CGtV3d, const CB3AILane *, unsigned short, GtMathPs2::CGtV3d *) const;
    unsigned char pad_0[0x154];
    UnkStruct_00149C90_car *field_154;
};
// 0x00149C90
void CB3AITargetSpline::ClampToWithinDesiredLanes(GtMathPs2::CGtV3d pos, const CB3AILane *lane, unsigned short seg, GtMathPs2::CGtV3d *out) const
{
    GtMathPs2::CGtV3d p = pos;
    int flags = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &p, seg);
    int dir;
    if ((flags & 1) != 0) {
        dir = 0;
    } else if ((flags & 2) != 0) {
        dir = 1;
    } else {
        *out = p;
        return;
    }
#define A91_PROBE(L, S) \
    { \
        e = &(L)->field_4->field_8[(S)]; \
        tg = &field_154->field_19F0; \
        seg2 = e->field_6[dir]; \
        link = e->field_4[dir]; \
        u = (LaneIsDriveable__9CB3AILaneFUcUsUs(link, seg2, 1) != 0 ? tg->LaneIsUndesirable(&D_00522660.field_2C[link], seg2) : 4) & 4; \
    }
    UnkStruct_00149C90_e *e;
    CB3AITarget *tg;
    unsigned char link;
    unsigned short seg2;
    unsigned int u;
    A91_PROBE(lane, seg);
    while ((u != 0) ^ 1) {
        const CB3AILane *l2 = &D_00522660.field_2C[e->field_4[dir]];
        unsigned short s2 = e->field_6[dir];
        A91_PROBE(l2, s2);
    }
}
