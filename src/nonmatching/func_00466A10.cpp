// NONMATCHING: func_00466A10 -- retail 226 / ours 221 instructions, 113 in changed runs
// logic complete, 221/226 instrs; open: lwc1 trio load order (ours F8,FC,F4 vs retail F4,F8,FC; decl-order perms don't move it), entry-jump clear loop gets bottom-test, top-of-function d/r store order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00466A10 -- placeholder (a184, hand-matched).
struct UnkStruct_00466A10;
struct UnkStruct_00466A10_1;
struct UnkStruct_D_004E2FC4;


struct UnkStruct_00466A10_blk {
    int field_0;
    float field_4;
    float field_8;
    float field_C;
    int field_10;
    int field_14;
};

struct UnkStruct_00466A10_1 {
    unsigned char pad_0[0xDC];
    int field_DC;
    void (*field_E0)(int *);
    int (*field_E4)(UnkStruct_00466A10 *, int *);
    int (*field_E8)(UnkStruct_00466A10 *, int *);
    unsigned char pad_EC[0x4];
    UnkStruct_00466A10_blk cur;
    unsigned char pad_108[0x1C];
    UnkStruct_00466A10_blk saved;
};

struct UnkStruct_00466A10 {
    int field_0;
};

struct UnkStruct_D_004E2FC4 {
    UnkStruct_00466A10_1 * field_0;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;

static inline void func_00466A10_inl0()
{
    UnkStruct_00466A10_1 * d = D_004E2FC4.field_0;
    d->saved.field_0 = d->cur.field_0;
    float t0 = d->cur.field_4;
    float t1 = d->cur.field_8;
    float t2 = d->cur.field_C;
    d->saved.field_4 = t0;
    d->saved.field_8 = t1;
    d->saved.field_C = t2;
    d->saved.field_10 = d->cur.field_10;
    d->saved.field_14 = d->cur.field_14;
}

static inline void func_00466A10_inl1()
{
    int i;
    D_004E2FC4.field_0->cur.field_0 = 5;
    i = 0;
    goto t;
b:
    ((int *)&D_004E2FC4.field_0->cur.field_4)[i] = 0;
    i++;
t:
    if (i <= 2) goto b;
    D_004E2FC4.field_0->cur.field_10 = 0;
    D_004E2FC4.field_0->cur.field_14 = 0;
}

// 0x00466A10
extern "C" int func_00466A10(UnkStruct_00466A10 * self)
{
    int r = 0;
    int x20;
    int x24;
    int x28;
    UnkStruct_00466A10_1 * d = D_004E2FC4.field_0;
    if (self == 0) {
        r = 7;
    } else {
        self->field_0 = 0;
    }
    switch (d->field_DC) {
    case 10:
        r = 0xC;
        break;
    case 9:
    default:
        r = 0xD;
        break;
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        break;
    }
    if (r == 0) {
        UnkStruct_00466A10_blk * c = &d->cur;
        switch (d->cur.field_0) {
        case 4:
            d->saved.field_0 = c->field_0;
            {
            float t0 = c->field_4;
            float t1 = c->field_8;
            float t2 = c->field_C;
            d->saved.field_4 = t0;
            d->saved.field_8 = t1;
            d->saved.field_C = t2;
            }
            d->saved.field_10 = c->field_10;
            d->saved.field_14 = c->field_14;
            D_004E2FC4.field_0->cur.field_0 = 0;
            self->field_0 = 1;
            break;
        case 0:
            r = (*(int (**)())&d->cur.field_4)();
            if (r == 0) {
                func_00466A10_inl0();
                D_004E2FC4.field_0->cur.field_0 = 1;
                self->field_0 = 1;
            } else {
                func_00466A10_inl0();
                D_004E2FC4.field_0->cur.field_0 = 2;
                D_004E2FC4.field_0->field_E0(&x28);
                func_00466A10_inl1();
            }
            break;
        case 1:
            r = (*(int (**)(int *))&D_004E2FC4.field_0->cur.field_8)(&x24);
            if (r == 0) {
                self->field_0 = 1;
                if (x24 == 2) {
                    self->field_0 = 2;
                    func_00466A10_inl1();
                }
            } else {
                func_00466A10_inl0();
                D_004E2FC4.field_0->cur.field_0 = 2;
                D_004E2FC4.field_0->field_E0(&x20);
                func_00466A10_inl1();
            }
            break;
        case 2:
            r = (*(int (**)())&d->cur.field_C)();
            break;
        case 5:
            r = 0x10;
            break;
        default:
            r = 0x11;
            break;
        }
    }
    if (r == 0) {
        if (self->field_0 == 2) {
            D_004E2FC4.field_0->field_E4(self, &r);
        }
    } else {
        D_004E2FC4.field_0->field_E8(self, &r);
    }
    return r;
}
