// CB3TrafficParam::FindLaneChange(CB3TrafficLane**,float*,float*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (L262: top-tested loop with spilled start copy, goto next, (c)^1 flag, element ptr first).

// CB3TrafficParam::FindLaneChange(CB3TrafficLane**,float*,float*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished (L262): top-tested for(;;) with a separate `start` copy (retail spills it), `goto next` [G] to the
// shared decrement, `(c) ^ 1` for the last-segment flag, element pointer declared before the flag.

enum ESegmentNeighbourTypes {};

struct UnkStruct_00160F10_e0 {
    unsigned short field_0[6];
    unsigned char field_C[4];
    unsigned char pad_10[0x2];
};

struct UnkStruct_00160F10_2 {
    unsigned char pad_0[0x8];
    UnkStruct_00160F10_e0 * field_8;
    unsigned char pad_C[0x4];
    int field_10;
};

class CB3TrafficLane {
public:
    UnkStruct_00160F10_2 * field_0;
    int DoesNeighbourExist(int, ESegmentNeighbourTypes);
};

struct UnkStruct_00160F10_e3 {
    unsigned char pad_0[0x4C];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00160F10_e3 field_0[1];  // [G] element count unknown
};

class CB3TrafficParam {
public:
    int FindLaneChange(CB3TrafficLane** p0, float* p1, float* p2, bool p3, bool p4);

    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0xD];
    unsigned char field_41;
    unsigned char pad_42[0x6];
    unsigned char field_48;
};

extern UnkStruct_D_00522660 D_00522660;

// 0x00160F10
int CB3TrafficParam::FindLaneChange(CB3TrafficLane** p0, float* p1, float* p2, bool p3, bool p4)
{
    CB3TrafficLane * lane;
    if (field_41 == 255) {
        lane = 0;
    } else {
        lane = (CB3TrafficLane *)((char *)&D_00522660.field_0[field_41] + 0x22C);
    }
    unsigned short seg = (unsigned short)field_30;
    unsigned short end;
    if (p4) {
        end = seg + 1;
    } else if (field_48 > 1) {
        end = seg + 1;
    } else {
        end = seg + 3;
    }
    if (end >= lane->field_0->field_10) {
        end = lane->field_0->field_10 - 1;
    }
    int dir;
    if (p3) {
        if (p4) dir = 0; else dir = 2;
    } else {
        if (p4) dir = 1; else dir = 3;
    }
    int start = seg;
    int i = end;
    for (;;) {
        if (i < start) break;
        UnkStruct_00160F10_e0 * e = &lane->field_0->field_8[i];
        int last = (i < lane->field_0->field_10 - 1) ^ 1;
        if (lane->DoesNeighbourExist((unsigned short)i, (ESegmentNeighbourTypes)dir)) {
            if (p4) {
                unsigned char nl = e->field_C[dir];
                if (nl == 255) goto next;
                unsigned int ns = e->field_0[dir];
                *p0 = (CB3TrafficLane *)((char *)&D_00522660.field_0[nl] + 0x22C);
                if (ns == 0) {
                    *p1 = (float)ns;
                    *p2 = 1.0f + (float)i;
                } else {
                    *p1 = (float)ns - 1.0f;
                    *p2 = (float)i;
                }
                return 1;
            } else {
                unsigned char nl = e->field_C[dir];
                if (nl == 255) goto next;
                unsigned int ns = e->field_0[dir];
                *p0 = (CB3TrafficLane *)((char *)&D_00522660.field_0[nl] + 0x22C);
                if (last) {
                    unsigned short d = i - (seg + 1);
                    if (d > 4) d = 4;
                    *p2 = (float)(i - d);
                    if (d < (unsigned short)ns) {
                        *p1 = (float)((unsigned short)ns - d);
                    } else {
                        *p1 = 0.0f;
                    }
                } else {
                    *p2 = (float)i;
                    *p1 = (float)ns;
                }
                return 1;
            }
        }
    next:
        i--;
    }
    return 0;
}
