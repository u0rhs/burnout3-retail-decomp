// NONMATCHING: func_0032A5C0 -- retail 217 / ours 216 instructions, 3 in changed runs
// 3 off (pass3a: 'case 0: default:' gives the default arm's fresh li a0,1 -- 5->3). Left: retail's dead 'lw zero,0xF8(sp)' entry load of p13 (N180 open) plus the li v0,4 it displaces. Tried 8-byte struct, union, unsigned, ctor'd struct, volatile struct/member/int p13 (volatile shrinks the frame), 15-pragma sweep: none give the dead load
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_Fl { int field_0; };
union UnkUnion_8 { unsigned long l; struct { int a; int b; } s; };
struct UnkStruct_Row {
    unsigned long field_0;
    unsigned long field_8;
    char field_10[0x20];
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    signed char field_44;
    unsigned char field_45;
    unsigned char pad_46[2];
};
struct UnkStruct_Page {
    unsigned char pad_0[0x15E8];
    UnkStruct_Row rows[18];
    unsigned char pad_1AF8[0x10];
    int field_1B08;
    unsigned char pad_1B0C[0x8];
    unsigned char field_1B14;
};
struct UnkStruct_RowPair {
    unsigned char pad_0[0x15E8];
    UnkStruct_Row a;
};
extern UnkStruct_P D_01E3CD44;
extern "C" void func_0021ADF0(unsigned long, void *);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int func_00339380(void *, int *);
extern "C" char * strncpy(char *, const char *, unsigned int);

static inline UnkStruct_RowPair * Rw2(UnkStruct_Page * self)
{
    return (UnkStruct_RowPair *)(self->field_1B08 * 72 + (int)self);
}

extern "C" int func_0032A5C0(char * p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, signed char p8, int p9, int p10, int p11, int p12, UnkStruct_Fl p13, UnkStruct_Page * self)
{
    int local;
    char buf[15];
    UnkUnion_8 id;
    UnkUnion_8 id2;
    if ((p8 & 7) != 4) {
        return 1;
    }
    if ((p8 & 0x10) != 0) {
        p13.field_0 = p13.field_0 | 0x10;
    } else {
        p13.field_0 = p13.field_0 | 0x20;
    }
    id.s.a = p2;
    id.s.b = p10;
    id2.s.a = p11;
    id2.s.b = p12;
    func_0021ADF0(id.l, buf);
    if (FindTrack__21CB3HardCodedTrackListFUl(id.l) == -1) {
        return 1;
    }
    unsigned int kind = (unsigned char)p9;
    func_00339380(&D_01E3CD44, &local);
    if (p3 < local) {
        p3 = local - p3;
    } else {
        p3 = p3 - local;
    }
    self->rows[self->field_1B08].field_45 = 1;
    switch (kind) {
    case 0:
    default:
        self->rows[self->field_1B08].field_45 = 1;
        break;
    case 1:
        if (!(p3 < 0x3E9) || local == 0) self->rows[self->field_1B08].field_45 = 0;
        break;
    case 2:
        if (!(p3 < 0x7D1) || local == 0) self->rows[self->field_1B08].field_45 = 0;
        break;
    case 3:
        if (!(p3 < 0x1389) || local == 0) self->rows[self->field_1B08].field_45 = 0;
        break;
    }
    self->rows[self->field_1B08].field_3C = p1;
    strncpy(self->rows[self->field_1B08].field_10, p0, 0x20);
    self->rows[self->field_1B08].field_0 = id.l;
    self->rows[self->field_1B08].field_8 = id2.l;
    if (!(p5 < self->rows[self->field_1B08].field_34)) {
        self->rows[self->field_1B08].field_34 = p5;
    }
    self->rows[self->field_1B08].field_44 = (signed char)p13.field_0;
    self->rows[self->field_1B08].field_38 = p6;
    self->rows[self->field_1B08].field_30 = p4;
    self->rows[self->field_1B08].field_40 = (p9 >> 8) & 0xFF;
    self->field_1B08 = self->field_1B08 + 1;
    self->field_1B14 = 1;
    return 1;
}





