// NONMATCHING: CalculateEdgePosition__11CB3AITargetFUsUsiPQ29GtMathPs26CGtV3dPUcPUs -- retail 420 / ours 414 instructions, 261 in changed runs
// son5: logic [L]: seek forward/back for a drivable, not-undesirable lane segment (two search loops), then a side-by-side walk bounded by min(IncrementSegmentIndexClamped,20); edge position = normalised segment direction * (lane offset + 2434/213 terms) + endpoint. remaining: frame 0x150 vs 0x110 (retail spills extra shorts/qwords), loop block layout (goto-shaped), the tail normalise block (retail compares ushorts via bne order, uses vf3/vf4 not vf1/vf2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): callee prototypes set to the callees' own scalar widths (docs/known.md N293); behaviour_audit unchanged.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0014A980_seg {   // [G] stride 10
    unsigned char pad_0[4];
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_0014A980_ld {   // [G] lane data
    unsigned short *field_0;
    unsigned char pad_4[4];
    UnkStruct_0014A980_seg *field_8;
    unsigned short field_C;
};

class CB3AILane {
public:
    unsigned short IncrementSegmentIndexClamped(unsigned short, short) const;
    static bool LaneIsDriveable(unsigned char, unsigned short, unsigned short);

    void *field_0;
    UnkStruct_0014A980_ld *field_4;
};

struct UnkStruct_00522690 { UnkStruct_0014A980_ld *field_0; unsigned char pad_4[4]; };
extern unsigned char D_00522660[];
extern UnkStruct_00522690 D_00522690[];
struct UnkStruct_D_0064D354 { CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_D_01E75594 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E75594 D_01E75594;

struct UnkStruct_0014A980_game { unsigned char pad_0[0x2434]; float field_2434; };

class CB3AITarget {
public:
    void CalculateEdgePosition(unsigned short seg, unsigned short n, int dir, CGtV3d *outPos, unsigned char *outLane, unsigned short *outSeg);
    unsigned int LaneIsUndesirable(const CB3AILane *, unsigned short, unsigned short) const;
    bool LanesAreSideBySide(const CB3AILane *, const CB3AILane *, unsigned short, unsigned short) const;

    unsigned char pad_0[4];
    UnkStruct_0014A980_game *field_4;
    unsigned char pad_8[0x1D4 - 8];
    CB3AILane *field_1D4;
    unsigned char pad_1D8[0x1F3 - 0x1D8];
    unsigned char field_1F3;
    unsigned char pad_1F4[0x213 - 0x1F4];
    unsigned char field_213;
};

#define LANE(i) ((CB3AILane *)(D_00522660 + (i) * 8 + 0x2C))

// 0x0014A980
void CB3AITarget::CalculateEdgePosition(unsigned short seg, unsigned short n, int dir, CGtV3d *outPos, unsigned char *outLane, unsigned short *outSeg)
{
    *outLane = 0xFF;
    *outSeg = 0xFFFF;
    CB3AILane *base = field_1D4;
    unsigned int b = 1;
    unsigned int f;
    if (dir == 1) {
        f = 0;
    } else {
        f = 1;
        b = 0;
    }
    unsigned short limit = (unsigned short)(field_1D4->IncrementSegmentIndexClamped(seg, (short)-(short)n) & 0xFFFF);
    if (limit > 20) limit = 20;
    unsigned int cs = seg;
    unsigned int r = LaneIsUndesirable(base, seg, (unsigned short)(seg + 8));
    if (r & 4) {
        CB3AILane *cur = base;
        while (LaneIsUndesirable(cur, (unsigned short)cs, (unsigned short)(cs + 8)) != 0) {
            UnkStruct_0014A980_seg *e = &cur->field_4->field_8[(unsigned short)cs];
            unsigned char nl = e->field_4[f];
            unsigned short ns = e->field_6[f];
            if (!CB3AILane::LaneIsDriveable(nl, ns, 1)) break;
            cs = ns;
            *outLane = nl;
            *outSeg = ns;
            cur = LANE(nl);
        }
        base = cur;
        if (LaneIsUndesirable(base, (unsigned short)cs, (unsigned short)(cs + 8)) != 0) {
            base = field_1D4;
            cs = seg;
            do {
                UnkStruct_0014A980_seg *e = &base->field_4->field_8[(unsigned short)cs];
                unsigned char nl = e->field_4[b];
                unsigned short ns = e->field_6[b];
                if (!CB3AILane::LaneIsDriveable(nl, ns, 1)) break;
                cs = ns;
                *outLane = nl;
                *outSeg = ns;
                base = LANE(nl);
            } while (LaneIsUndesirable(base, (unsigned short)cs, (unsigned short)(cs + 8)) != 0);
        }
    }
    unsigned int s0 = (unsigned short)cs;
    CB3AILane *cur = base;
    unsigned char nl;
    unsigned short ns;
    {
        UnkStruct_0014A980_seg *e = &cur->field_4->field_8[s0];
        nl = e->field_4[f];
        ns = e->field_6[f];
    }
    unsigned short t = ns + 8;
    int diff = t - ns;
    if (diff < 0) diff += D_00522690[nl].field_0->field_C;
    r = CB3AILane::LaneIsDriveable(nl, ns, (unsigned short)diff) ? LaneIsUndesirable(LANE(nl), ns, t) : 4;
    while ((r & 4) == 0) {
        UnkStruct_0014A980_seg *e = &cur->field_4->field_8[(unsigned short)s0];
        nl = e->field_4[f];
        if (r & 1) {
            s0 = e->field_6[f];
            cur = LANE(nl);
        } else {
            CB3AILane *nxt = LANE(nl);
            if (!LanesAreSideBySide(field_1D4, nxt, n, limit)) break;
            base = nxt;
            cs = e->field_6[f];
            *outLane = nl;
            *outSeg = cs;
            s0 = e->field_6[f];
            cur = nxt;
        }
        UnkStruct_0014A980_seg *e2 = &cur->field_4->field_8[(unsigned short)s0];
        ns = e2->field_6[f];
        nl = e2->field_4[f];
        unsigned short t2 = ns + 8;
        int d2 = t2 - ns;
        if (d2 < 0) d2 += D_00522690[nl].field_0->field_C;
        r = CB3AILane::LaneIsDriveable(nl, ns, (unsigned short)d2) ? LaneIsUndesirable(LANE(nl), ns, t2) : 4;
    }
    float len = (cur == base) ? field_4->field_2434 : 0.0f;
    if (field_1F3 != 0) len += field_4->field_2434;
    if (field_213 != 0) len += D_01E75594.field_0;
    unsigned short *pts = base->field_4->field_0;
    unsigned int k = (unsigned short)cs;
    if (pts[k * 2 + 1] == pts[k * 2]) {
        if (k > 0) k = (unsigned short)(k - 1); else k = (unsigned short)(k + 1);
    }
    if (dir == 1) {
        CGtV3d p0 = D_0064D354.field_0[pts[k * 2]];
        CGtV3d p1 = D_0064D354.field_0[pts[k * 2 + 1]];
        CGtV3d d = p1 - p0;
        d.Normalise();
        *outPos = d * len + p0;
    } else {
        CGtV3d p1 = D_0064D354.field_0[pts[k * 2 + 1]];
        CGtV3d p0 = D_0064D354.field_0[pts[k * 2]];
        CGtV3d d = p0 - p1;
        d.Normalise();
        *outPos = d * len + p1;
    }
}
