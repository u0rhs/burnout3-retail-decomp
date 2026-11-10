// B3AILane.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3AILane.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4AILane.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3AILane.h"
#include "b3/classes/CB3AILaneStruct.h"
#include "b3/classes/UnkStruct_D_00522690.h"

struct UnkStruct_00146180_e1;

struct UnkStruct_00146180_e1 {
    float field_0;
    unsigned char pad_4[0x4];
};

extern UnkStruct_D_00522690 D_00522690[];

// CB3AILane::GetSegmentLengthFast(unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// 0x00146180
float CB3AILane::GetSegmentLengthFast(unsigned short p0) const
{
    if (p0 != 0) {
        return (field_4->field_4[p0].field_0 - field_4->field_4[(p0 + -1)].field_0);
    }
    return ((UnkStruct_00146180_e1 *)field_4->field_4)[p0].field_0;
}

// CB3AILane::SegmentAIsInfrontOfSegmentB(unsigned short,unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// 0x001478C0
int CB3AILane::SegmentAIsInfrontOfSegmentB(unsigned short p0, unsigned short p1) const
{
    UnkStruct_00146180_1 * t0 = field_4;
    int half = (unsigned int)t0->field_C >> 1;
    int d = p0 - p1;
    if (t0->field_E != 0) {
        if (d >= 0 && half > d) {
            return 1;
        }
        if (d >= 0 && !(d < half)) {
            return 0;
        }
        if (d >= 0 || d < -half) {
            return 1;
        }
        return 0;
    }
    return d >= 0;
}

// CB3AILane::LaneIsDriveable(const CB3AILaneStruct*,unsigned short,unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// 0x00148C20
bool CB3AILane::LaneIsDriveable(const CB3AILaneStruct *r, unsigned short seg, unsigned short n)
{
    while (n--) {
        if ((r->field_8[seg].field_3 & 7) == 5) {
            return false;
        }
        seg++;
        if (seg >= r->field_C) {
            if (r->field_E == 0) {
                break;
            }
            seg = 0;
        }
    }
    return true;
}

// CB3AILane::LaneIsDriveable(unsigned char,unsigned short,unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// 0x00148CA0
// N182: `#pragma opt_repositioncode off` [G] scoped to this function, as the proven sibling
// CB3AILane::LaneIsDriveable(unsigned short, unsigned short) (0x148D60): relay return blocks in source order.
#pragma push
#pragma opt_repositioncode off
bool CB3AILane::LaneIsDriveable(unsigned char p0, unsigned short p1, unsigned short p2)
{
    if (p0 == 255) {
        goto bad;
    }
    UnkStruct_00148CA0_lane *r = D_00522690[p0].field_0;
    int seg;
    int n;
    n = p2;
    seg = p1;
    bool res;
    int old;
    while ((old = n, n = (unsigned short)(n - 1), old != 0)) {
        if ((r->field_8[(unsigned short)seg].field_3 & 7) == 5) {
            goto ret0;
        }
        seg = (unsigned short)(seg + 1);
        if (seg >= r->field_C) {
            if (r->field_E == 0) {
                break;
            }
            seg = 0;
        }
    }
    res = true;
join:
    return res;
bad:
    return false;
ret0:
    res = false;
    goto join;
}
#pragma pop

// CB3AILane::LaneIsDriveable(unsigned short,unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// 0x00148D60
// N182: `#pragma opt_repositioncode off` [G] scoped to this function (relay return blocks in source order).
#pragma push
#pragma opt_repositioncode off
bool CB3AILane::LaneIsDriveable(unsigned short a, unsigned short b)
{
    UnkStruct_00146180_1 *r = field_4;
    int seg;
    int n;
    n = b;
    seg = a;
    bool res;
    int old;
    while ((old = n, n = (unsigned short)(n - 1), old != 0)) {
        if ((r->field_8[(unsigned short)seg].field_3 & 7) == 5) {
            goto ret0;
        }
        seg = (unsigned short)(seg + 1);
        if (seg >= r->field_C) {
            if (r->field_E == 0) {
                break;
            }
            seg = 0;
        }
    }
    res = true;
join:
    return res;
ret0:
    res = false;
    goto join;
}
#pragma pop
