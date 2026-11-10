// CB3AILane::WalkLanesToFindPosition(unsigned short*,GtMathPs2::CGtV3d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pp=&p taken before the copy + scoped opt_propagation off [G]).

// a91: 1 instr short, 7 in changed runs: retail materialises addiu v1,sp,0x60 early (shared &copy in v1, move a1,v1 at first IsInSegment call); ours addiu a1 at the call. Everything else matches (regs, loops, link lookups).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3AILane::WalkLanesToFindPosition(unsigned short*, GtMathPs2::CGtV3d) -- hand-written (lifter refused).
#include "b3/GtMathPs2.h"
class CB3AILane;
struct UnkStruct_00146540_e {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char field_5;
    unsigned short field_6;
    unsigned short field_8;
};
struct UnkStruct_00146540_road {
    unsigned char pad_0[8];
    UnkStruct_00146540_e *field_8;
};
class CB3AILane {
public:
    CB3AILane *WalkLanesToFindPosition(unsigned short *, GtMathPs2::CGtV3d);
    CB3AILane *UpdateSegmentIndex(unsigned short *, signed char);
    unsigned char pad_0[4];
    UnkStruct_00146540_road *field_4;
};
extern "C" int IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(const CB3AILane *, const void *, unsigned short);
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
// N182: `#pragma opt_propagation off` ([G] scoped to this function): keeps `pp` (&p, taken before the
// copy) a real value, so retail's early addiu v1 + move a1 at the first IsInSegment call.
#pragma push
#pragma opt_propagation off
// 0x00146540
CB3AILane *CB3AILane::WalkLanesToFindPosition(unsigned short *seg, GtMathPs2::CGtV3d pos)
{
    GtMathPs2::CGtV3d p;
    const void *pp = &p;
    p = pos;
    CB3AILane *lane = this;
    unsigned short cur = *seg;
    int last = 16;
    int count = 0;
    unsigned short local = cur;
    int r = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, pp, cur);
    while (r != 0) {
        count++;
        if (count == 128) {
            break;
        }
        if ((r & 4) != 0) {
            if (last == 8) {
                break;
            }
            CB3AILane *n = lane->UpdateSegmentIndex(&local, 1);
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 4;
        } else if ((r & 8) != 0) {
            if (last == 4) {
                break;
            }
            CB3AILane *n = lane->UpdateSegmentIndex(&local, -1);
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 8;
        } else if ((r & 1) != 0) {
            if (last == 2) {
                break;
            }
            UnkStruct_00146540_e *e = &lane->field_4->field_8[local];
            unsigned char link = e->field_4;
            CB3AILane *n;
            if (link == 255) {
                n = 0;
            } else {
                local = e->field_6;
                n = &D_00522660.field_2C[link];
            }
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 1;
        } else if ((r & 2) != 0) {
            if (last == 1) {
                break;
            }
            UnkStruct_00146540_e *e = &lane->field_4->field_8[local];
            unsigned char link = e->field_5;
            CB3AILane *n;
            if (link == 255) {
                n = 0;
            } else {
                local = e->field_8;
                n = &D_00522660.field_2C[link];
            }
            if (n == 0) {
                break;
            }
            cur = local;
            lane = n;
            last = 2;
        }
        r = IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs(lane, &p, cur);
    }
    *seg = cur;
    return lane;
}
#pragma pop
