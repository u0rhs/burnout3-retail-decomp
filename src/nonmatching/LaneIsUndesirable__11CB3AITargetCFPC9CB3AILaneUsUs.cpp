// NONMATCHING: LaneIsUndesirable__11CB3AITargetCFPC9CB3AILaneUsUs -- retail 245 / ours 245 instructions, 17 in changed runs
// L262: logic+layout exact (245/245), 17 off: t3/t4/t5 rotation only (p2-promoted t5 vs t4, loop-1 lane->field_4 t3 vs t5, 1914 t4 vs t3, const 3 t4 vs t5). Keys: explicit loop guards, hoisted int k = field_4->field_1914, p2 -= n, (t!=1&&t!=3){}else form, &field_8[p1] element ptr.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// CB3AITarget::LaneIsUndesirable(const CB3AILane*,unsigned short,unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AITarget has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].

class CB3AILane;

class CB3AITarget;
struct CB3AILane;
struct UnkStruct_0014A560_1;
struct UnkStruct_0014A560_4;
struct UnkStruct_0014A560_e0;
struct UnkStruct_0014A560_e1;
struct UnkStruct_0014A560_e2;
struct UnkStruct_0014A560_e3;

struct CB3AILane {
    unsigned char pad_0[0x4];
    UnkStruct_0014A560_1 * field_4;
};

struct UnkStruct_0014A560_1 {
    unsigned char pad_0[0x8];
    UnkStruct_0014A560_e0 * field_8;
    unsigned short field_C;
    unsigned char field_E;
};

struct UnkStruct_0014A560_e0 {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_0014A560_4 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_0014A560_e1 {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_0014A560_e2 {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_0014A560_e3 {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

class CB3AITarget {
public:
    int LaneIsUndesirable(const CB3AILane* p0, unsigned short p1, unsigned short p2) const;

    unsigned char pad_0[0x4];
    UnkStruct_0014A560_4 * field_4;
    unsigned char pad_8[0x1E8];
    unsigned char field_1F0;
    unsigned char field_1F1;
    unsigned char pad_1F2[0xA];
    int field_1FC;
    unsigned char pad_200[0x91];
    unsigned char field_291;
    unsigned char field_292;
};

// 0x0014A560
int CB3AITarget::LaneIsUndesirable(const CB3AILane* p0, unsigned short p1, unsigned short p2) const
{
    int r = 0;
    UnkStruct_0014A560_e0 * e = &p0->field_4->field_8[p1];
    if ((e->field_3 & 7) == 5) {
        return 4;
    }
    unsigned short n = p0->field_4->field_C;
    if (p2 >= n) {
        if (p0->field_4->field_E != 0) {
            p2 -= n;
        } else {
            p2 = n - 1;
            r |= 2;
        }
    }
    if (p2 < p1) {
        if (p1 < n) {
        int k = field_4->field_1914;
        for (; p1 < p0->field_4->field_C; p1++) {
            if (k == 0) {
                if ((p0->field_4->field_8[p1].field_3 & 7) == 4) r |= 1;
            } else {
                if (field_1F1 == 0 && (p0->field_4->field_8[p1].field_3 & 7) == 4) {
                    if (field_291 != 0) r |= 1; else r |= 4;
                }
                if (field_1F0 == 0) {
                    unsigned int t = p0->field_4->field_8[p1].field_3 & 7;
                    if (t != 1 && t != 3) {} else
                        if (field_1FC != 0) { if (field_292 != 0) r |= 1; else r |= 4; }
                }
            }
        }
        }
        p1 = 0;
        if (p1 <= p2) {
        int k = field_4->field_1914;
        for (; p1 <= p2; p1++) {
            if (k == 0) {
                r |= 1;
            } else {
                if (field_1F1 == 0 && (p0->field_4->field_8[p1].field_3 & 7) == 4) {
                    if (field_291 != 0) r |= 1; else r |= 4;
                }
                if (field_1F0 == 0) {
                    unsigned int t = p0->field_4->field_8[p1].field_3 & 7;
                    if (t != 1 && t != 3) {} else
                        if (field_1FC != 0) { if (field_292 != 0) r |= 1; else r |= 4; }
                }
            }
        }
        }
    } else {
        if (p1 <= p2) {
        int k = field_4->field_1914;
        for (; p1 <= p2; p1++) {
            if (k == 0) {
                r |= 1;
            } else {
                if (field_1F1 == 0 && (p0->field_4->field_8[p1].field_3 & 7) == 4) {
                    if (field_291 != 0) r |= 1; else r |= 4;
                }
                if (field_1F0 == 0) {
                    unsigned int t = p0->field_4->field_8[p1].field_3 & 7;
                    if (t != 1 && t != 3) {} else
                        if (field_1FC != 0) { if (field_292 != 0) r |= 1; else r |= 4; }
                }
            }
        }
        }
    }
    return r;
}
