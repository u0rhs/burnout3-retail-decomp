// Hand-written; the lifter refused it (near21: cloned sibling func_00143860 shape + top-declared locals + lane before seg in the walk).

// near21: cloned from sibling func_00143860 (simfind 0.61): same lane-walk / FindResetPointInSlice retry shape, the
// retry stepping forward (+1, wrap by field_C or back to start); locals declared at the top (archive a92 order).
struct UnkStruct_00150460_seg {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_00150460_road {
    unsigned char pad_0[8];
    UnkStruct_00150460_seg *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
struct CB3AILane {
    unsigned char pad_0[4];
    UnkStruct_00150460_road *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct CB3RaceCar {
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
};
extern "C" bool FindResetPointInSlice__10CB3RaceCarFbP9CB3AILaneiPP9CB3AILanePUs(void *, int, CB3AILane *, int, CB3AILane **, unsigned short *);
extern "C" void RepositionCarInLane__10CB3RaceCarFv(void *);
// 0x00150460
enum UnkEnum_00150460 { UnkEnum_00150460_0, UnkEnum_00150460_1 };
extern "C" void func_00150460(CB3RaceCar *self, int b, int a2 /* passed by every caller, not read here */)
{
    CB3AILane *lane;
    int seg;
    bool found;
    int start;
    bool notfound;
    lane = self->field_18B4;
    if (lane == 0) {
        return;
    }
    UnkEnum_00150460 k;
    found = false;
    if (b != 0) {
        k = UnkEnum_00150460_1;
    } else {
        k = UnkEnum_00150460_0;
    }
    seg = self->field_18B8;
    unsigned char link = lane->field_4->field_8[seg].field_4[k];
    unsigned short ns = lane->field_4->field_8[seg].field_6[k];
    while (link != 0xFF) {
        lane = &D_00522660.field_2C[link];
        seg = ns;
        link = lane->field_4->field_8[seg].field_4[k];
        ns = lane->field_4->field_8[seg].field_6[k];
    }
    if (FindResetPointInSlice__10CB3RaceCarFbP9CB3AILaneiPP9CB3AILanePUs(self, b, lane, seg, &self->field_18B4, &self->field_18B8)) {
        found = true;
    }
    start = seg;
    notfound = !found;
    while (notfound) {
        seg += 1;
        UnkStruct_00150460_road *r2 = lane->field_4;
        if (seg >= r2->field_C) {
            if (r2->field_E != 0) {
                seg -= r2->field_C;
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
    switch ((((UnkStruct_00150460_seg *)((char *)self->field_18B4->field_4->field_8 + self->field_18B8 * 10))->field_3 >> 6)) {
    default:
        RepositionCarInLane__10CB3RaceCarFv(self);
        break;
    case 0:
        RepositionCarInLane__10CB3RaceCarFv(self);
    }
}
