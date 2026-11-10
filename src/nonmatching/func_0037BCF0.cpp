// NONMATCHING: func_0037BCF0 -- retail 285 / ours 288 instructions, 88 in changed runs
// a230: p8 low byte as 'unsigned char lo = (unsigned char)p8; (signed char)lo != limit' reproduces retail's andi 255 + dsll32/dsra32 pair (95->88). Left: sv in v1 vs retail v0 (decl order sel/sv swaps tried, worse), extra andi on sel
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



struct UnkStruct_0037BCF0_name { signed char b[0x20]; };
struct UnkStruct_0037BCF0_rec {
    UnkStruct_0037BCF0_name field_0;
    unsigned long field_20;
    unsigned long field_28;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    unsigned char pad_4C[0x4];
};
struct UnkStruct_0037BCF0_hdr { int field_0; short field_4; short field_6; };
struct UnkStruct_0037BCF0 {
    unsigned char pad_0[0x60];
    UnkStruct_0037BCF0_rec field_60[9];
    unsigned char pad_330[0x1920 - 0x330];
    int field_1920;
    UnkStruct_0037BCF0_hdr * field_1924;
    int field_1928;
    unsigned int field_192C;
    int field_1930;
};
struct UnkStruct_D_00665ECE { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00665ECE D_00665ECE;
extern UnkStruct_D_Pad16 D_005196A0;
extern "C" int GetTrackIndexFromID__12CB3TrackListFUl(void *, unsigned long);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int func_0037B6C0(const void *, const void *);
extern "C" int func_0037B400(UnkStruct_0037BCF0 *);

extern "C" int func_0037BCF0(char * name, int p1, int p2, unsigned int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, UnkStruct_0037BCF0 * self)
{
    int limit = D_00665ECE.field_0 ? 0x14 : 0x24;
    unsigned char lo = (unsigned char)p8;
    if ((signed char)lo != limit) return 1;
    unsigned char top = (unsigned char)(p8 >> 24);
    unsigned int sv = self->field_192C;
    unsigned char sel = p9;
    unsigned int d1 = p3 < sv ? sv - p3 : p3 - sv;
    int cur = self->field_60[self->field_1930].field_34;
    unsigned int d2 = cur < (int)sv ? sv - cur : cur - sv;
    if (d2 < d1) return 1;
    if (p13 & 1) return 1;
    if (p13 & 4) return 1;
    if (p5 == p6) return 1;
    if (p13 & 2) return 1;
    switch (sel) {
    case 0:
    default:
        break;
    case 1:
        if (!(d1 < 0x3E9)) return 1;
        if (sv == 0) return 1;
        break;
    case 2:
        if (!(d1 < 0x7D1)) return 1;
        if (sv == 0) return 1;
        break;
    case 3:
        if (!(d1 < 0x1389) || sv == 0) return 1;
        break;
    }
    if (self->field_1928 == 0) {
        UnkStruct_0037BCF0_hdr * h = self->field_1924;
        switch (h->field_4) {
        case 0:
        default:
            break;
        case 1:
            if (d1 >= 0x3E9) return 0;
            break;
        case 2:
            if (d1 >= 0x7D1) return 1;
            break;
        case 3:
            if (d1 >= 0x1389) return 1;
            break;
        }
        if (h->field_6 == 5 || h->field_6 == p4) {
            int t = h->field_0;
            if (!(t == 0 || t == top || (t == 1 && top == 0))) return 1;
        } else {
            return 1;
        }
    }
    union { unsigned long l; struct { int lo; int hi; } s; } id1;
    union { unsigned long l; struct { int lo; int hi; } s; } id2;
    id1.s.lo = p2;
    id1.s.hi = p10;
    id2.s.lo = p11;
    id2.s.hi = p12;
    if (GetTrackIndexFromID__12CB3TrackListFUl(&D_005196A0, id1.l) < 0) return 1;
    UnkStruct_0037BCF0_rec tmp;
    strncpy((char *)&tmp.field_0, name, 0x20);
    tmp.field_20 = id1.l;
    tmp.field_28 = id2.l;
    tmp.field_30 = p1;
    tmp.field_34 = d1;
    tmp.field_38 = p4;
    tmp.field_3C = p5;
    tmp.field_40 = p6;
    tmp.field_44 = p7;
    tmp.field_48 = (unsigned char)(p9 >> 8);
    if (self->field_1930 == 9) {
        if (func_0037B6C0(&tmp, &self->field_60[self->field_1930]) < 0) goto ins;
        return 1;
    }
ins:
    {
        UnkStruct_0037BCF0_rec * dst = &self->field_60[self->field_1930];
        int empty = dst->field_30 == -1;
        *dst = tmp;
        if (empty) {
            self->field_1920 = self->field_1920 + 1;
            self->field_1930 = self->field_1930 + 1;
        }
    }
    if (self->field_1928 == 1) {
        if (func_0037B400(self) == 0) return 1;
        return 0;
    }
    return 1;
}


