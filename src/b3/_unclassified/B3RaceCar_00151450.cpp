// CB3RaceCar::FindResetPointInSlice(bool,CB3AILane*,int,CB3AILane**,unsigned short*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near34: direct seg expressions (no seg pointer locals), e/s0 declared first, idx declared before id, i before free, found after the id/idx loads, hi = fl >> 6 local).

enum UnkEnum_00151450 { UnkEnum_00151450_0, UnkEnum_00151450_1 };
struct UnkStruct_1450_seg {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_1450_ls {
    unsigned char pad_0[0x8];
    UnkStruct_1450_seg * field_8;
};
class CB3AILane {
public:
    int field_0;
    UnkStruct_1450_ls * field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane lanes[1];
};
struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];
};
class CB3RaceCar;
struct UnkStruct_1450_car {
    unsigned char pad_0[0x18B4];
    CB3AILane * field_18B4;
    unsigned short field_18B8;
};
class CB3RaceCar {
public:
    bool FindResetPointInSlice(bool p0, CB3AILane * p1, int p2, CB3AILane ** p3, unsigned short * p4);
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_1450_car * D_0064D388[];

// 0x00151450
bool CB3RaceCar::FindResetPointInSlice(bool p0, CB3AILane * p1, int p2, CB3AILane ** p3, unsigned short * p4)
{
    CB3AILane * e;
    unsigned short s0;
    UnkEnum_00151450 d;
    if (p0) {
        d = UnkEnum_00151450_0;
    } else {
        d = UnkEnum_00151450_1;
    }
    unsigned short idx;
    unsigned char id = p1->field_4->field_8[p2].field_4[d];
    idx = p1->field_4->field_8[p2].field_6[d];
    bool found = false;
    goto test;
body:
    e = &D_00522660.lanes[id];
    s0 = idx;
    {
        int fl = e->field_4->field_8[s0].field_3;
        int ty = fl & 7;
        int hi = fl >> 6;
        if (ty == 7) goto next;
        if (ty == 5) goto next;
        if (hi == 0) goto next;
        int i;
        bool free = true;
        for (i = 0; i < D_0064D37C.field_0; i++) {
            if (i == field_19AC) continue;
            UnkStruct_1450_car * c = D_0064D388[i];
            if (c->field_18B4 == e && c->field_18B8 == s0) {
                free = false;
                break;
            }
        }
        if (!free) goto next;
        found = true;
        goto after;
    }
test:
    if (id != 255) goto body;
after:
    if (found) goto store;
done:
    return found;
next:
    {
        id = e->field_4->field_8[s0].field_4[d];
        idx = e->field_4->field_8[s0].field_6[d];
    }
    goto test;
store:
    *p3 = e;
    *p4 = s0;
    goto done;
}
