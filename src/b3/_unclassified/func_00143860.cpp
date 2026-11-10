// Hand-written; the lifter refused it (UnkEnum_ k diamond + found=false after it; struct-indexed segment reads; byte-offset tail index).

// near13: k as an UnkEnum_ if/else diamond with `bool found = false;` right after it (fills the beqz delay slot);
// struct-indexed segment reads (field_8[seg].field_4/6[k]); the tail's byte-offset index form.

// func_00143860 -- hand-written (lifter refused).
struct UnkStruct_00143860_seg {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_00143860_road {
    unsigned char pad_0[8];
    UnkStruct_00143860_seg *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
struct CB3AILane {
    unsigned char pad_0[4];
    UnkStruct_00143860_road *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct CB3AICar {
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
};
extern "C" bool FindResetPointInSlice__10CB3RaceCarFbP9CB3AILaneiPP9CB3AILanePUs(void *, int, CB3AILane *, int, CB3AILane **, unsigned short *);
extern "C" void RepositionCarInLane__10CB3RaceCarFv(void *);
// 0x00143860
enum UnkEnum_00143860 { UnkEnum_00143860_0, UnkEnum_00143860_1 };
extern "C" void func_00143860(CB3AICar *self, int b)
{
    CB3AILane *lane = self->field_18B4;
    if (lane == 0) {
        return;
    }
    UnkEnum_00143860 k;
    bool found = false;
    if (b != 0) {
        k = UnkEnum_00143860_1;
    } else {
        k = UnkEnum_00143860_0;
    }
    int seg = self->field_18B8;
    UnkStruct_00143860_road *road = lane->field_4;
    unsigned char link = road->field_8[seg].field_4[k];
    unsigned short ns = road->field_8[seg].field_6[k];
    while (link != 0xFF) {
        seg = ns;
        lane = &D_00522660.field_2C[link];
        road = lane->field_4;
        link = road->field_8[seg].field_4[k];
        ns = road->field_8[seg].field_6[k];
    }
    seg -= 3;
    if (seg < 0) {
        if (road->field_E != 0) {
            seg += road->field_C;
        } else {
            seg = 0;
        }
    }
    if (FindResetPointInSlice__10CB3RaceCarFbP9CB3AILaneiPP9CB3AILanePUs(self, b, lane, seg, &self->field_18B4, &self->field_18B8)) {
        found = true;
    }
    int start = seg;
    bool notfound = !found;
    while (notfound) {
        seg -= 1;
        if (seg < 0) {
            UnkStruct_00143860_road *r2 = lane->field_4;
            if (r2->field_E != 0) {
                seg += r2->field_C;
            } else {
                seg = start;
            }
        }
        if (FindResetPointInSlice__10CB3RaceCarFbP9CB3AILaneiPP9CB3AILanePUs(self, b, lane, seg, &self->field_18B4, &self->field_18B8)) {
            break;
        }
        if (seg == start) {
            break;
        }
    }
    switch ((((UnkStruct_00143860_seg *)((char *)self->field_18B4->field_4->field_8 + self->field_18B8 * 10))->field_3 >> 6)) {
    default:
        RepositionCarInLane__10CB3RaceCarFv(self);
        break;
    case 0:
        RepositionCarInLane__10CB3RaceCarFv(self);
    }
}
