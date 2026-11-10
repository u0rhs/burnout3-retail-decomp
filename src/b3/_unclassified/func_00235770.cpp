// func_00235770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a222: int i before idx at top; early 'if (on==0) return 0;'; update block as goto-upd after shared 'tail: return 0'; wrap ring index as if(<10){}else{=0}).

struct UnkStruct_00235770_msg {
    unsigned char pad_0[2];
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
};
struct UnkStruct_00235770_ent {
    int field_0;
    int field_4;
    int field_8;
};
struct UnkStruct_00235770_row {
    unsigned char pad_0[0x324];
    UnkStruct_00235770_ent field_324;
};
struct UnkStruct_00235770 {
    unsigned char pad_0[0x324];
    UnkStruct_00235770_ent field_324[10];
    int field_39C;
};

static inline bool func_00235770_inl1(unsigned short a, unsigned short b)
{
    if (a < 0x5555) {
        if (b > 0xAAAA) {
            return true;
        }
    }
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return false;
        }
    }
    if (b < a) {
        return true;
    }
    return false;
}

// 0x00235770
extern "C" int func_00235770(UnkStruct_00235770 *self, UnkStruct_00235770_msg *m)
{
    int on = (m->field_2 & 1) != 0;
    int i;
    int idx = -1;
    if (on == 0) return 0;
    {
        for (i = 0; i < 10; i++) {
            UnkStruct_00235770_row *e = (UnkStruct_00235770_row *)((char *)self + i * 12);
            if (e->field_324.field_0 == m->field_4 && e->field_324.field_4 == m->field_C && e->field_324.field_8 == m->field_3) {
                return 1;
            }
            if (e->field_324.field_0 == m->field_4 && e->field_324.field_8 == m->field_3 && func_00235770_inl1(e->field_324.field_4, m->field_C)) {
                return 1;
            }
            if (e->field_324.field_0 == m->field_4 && e->field_324.field_8 == m->field_3) {
                idx = i;
            }
        }
        if (idx != -1) goto upd;
        self->field_324[self->field_39C].field_0 = m->field_4;
        self->field_324[self->field_39C].field_4 = m->field_C;
        self->field_324[self->field_39C].field_8 = m->field_3;
        self->field_39C = self->field_39C + 1;
        if (self->field_39C < 10) {
        } else {
            self->field_39C = 0;
        }
      tail:
        return 0;
      upd:
        self->field_324[idx].field_0 = m->field_4;
        self->field_324[idx].field_4 = m->field_C;
        self->field_324[idx].field_8 = m->field_3;
        goto tail;
    }
    return 0;
}
