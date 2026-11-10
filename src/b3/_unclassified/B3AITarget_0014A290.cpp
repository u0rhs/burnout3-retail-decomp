// CB3AITarget::LanesAreSideBySide(const CB3AILane*,const CB3AILane*,unsigned short,unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AITarget has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (near26: the ushort parameters p2/p3 advanced in place (no copies: retail keeps them raw in s4/s3 and masks per use), bool found, declarations found/id/off/sg for the s-register order, id read before sg in the second arm).

struct UnkStruct_14A290_seg {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char field_5;
    unsigned short field_6;
    unsigned short field_8;
};
struct UnkStruct_14A290_lane {
    unsigned char pad_0[0x8];
    UnkStruct_14A290_seg * field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    int field_0;
    UnkStruct_14A290_lane * field_4;
    static bool LaneIsDriveable(unsigned char p0, unsigned short p1, unsigned short p2);
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane lanes[1];
};
extern UnkStruct_D_00522660 D_00522660;

class CB3AITarget {
public:
    bool LanesAreSideBySide(const CB3AILane * p0, const CB3AILane * p1, unsigned short p2, unsigned short p3) const;
};

// 0x0014A290
bool CB3AITarget::LanesAreSideBySide(const CB3AILane * p0, const CB3AILane * p1, unsigned short p2, unsigned short p3) const
{
    bool found;
    unsigned char id;
    int off;
    unsigned short sg;
    goto test;
body:
    off = p2 * 10;
    id = ((UnkStruct_14A290_seg *)((char *)p0->field_4->field_8 + off))->field_4;
    sg = ((UnkStruct_14A290_seg *)((char *)p0->field_4->field_8 + off))->field_6;
    found = false;
    goto t1;
b1:
    {
        const CB3AILane * e = &D_00522660.lanes[id];
        if (e == p1) {
            found = true;
            goto after1;
        }
        id = e->field_4->field_8[sg].field_4;
        sg = e->field_4->field_8[sg].field_6;
    }
t1:
    if (CB3AILane::LaneIsDriveable(id, sg, 1)) goto b1;
after1:
    if (!found) {
        id = ((UnkStruct_14A290_seg *)((char *)p0->field_4->field_8 + off))->field_5;
        sg = ((UnkStruct_14A290_seg *)((char *)p0->field_4->field_8 + off))->field_8;
        goto t2;
b2:
        {
            const CB3AILane * e = &D_00522660.lanes[id];
            if (e == p1) {
                found = true;
                goto after2;
            }
            id = e->field_4->field_8[sg].field_5;
            sg = e->field_4->field_8[sg].field_8;
        }
t2:
        if (CB3AILane::LaneIsDriveable(id, sg, 1)) goto b2;
    }
after2:
    if (!found) {
        return false;
    }
    p2++;
    if (p2 >= p0->field_4->field_C) {
        if (p0->field_4->field_E == 0) {
            return false;
        }
        p2 = p2 - p0->field_4->field_C;
    }
    p3--;
test:
    if (p3 > 0) goto body;
    return true;
}
