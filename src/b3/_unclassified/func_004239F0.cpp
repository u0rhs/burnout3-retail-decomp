// Hand-written; the lifter refused it (a156: queue builder; static inline push(op) (field_4/78/EC [lbu n]++), int cnt masked &0xFF + (unsigned char) test, bool found/flagged with bool callee params, __moddi3+0x4C = 0x12C6FC byte-offset casts (lui 0x13/lo bytes verified: 0x12C6FC, 0x12ACD2, 0x12C4A4)).

// Hand-written (a156): builds the online-menu step queue (op / arg / arg triples), sibling of func_00423F30 / func_004231B0.

struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_4239F0_obj {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual int vfunc_A8();
    unsigned char pad_4[0xC];
};
struct UnkStruct_4239F0_ctx {
    unsigned char pad_0[0x1B4];
    UnkStruct_4239F0_obj * field_1B4;
    const void * field_1B8;
};
struct UnkStruct_D_0051BA88 { UnkStruct_4239F0_ctx * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00423F30 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    int field_4[29];
    int field_78[29];
    int field_EC[29];
    int field_160;
    int field_164;
    unsigned char pad_168[0xC];
    unsigned char field_174;
    unsigned char field_175;
    unsigned char field_176;
    unsigned char field_177;
    unsigned char field_178;
};
extern UnkStruct_Pad16 D_00522660;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_Pad16 D_0051B928;
extern "C" void func_00423720(UnkStruct_00423F30 *);
extern "C" void func_004231B0(UnkStruct_00423F30 *, bool);
extern "C" void func_004230D0(UnkStruct_00423F30 *);
extern "C" void func_00422F40(UnkStruct_00423F30 *, bool);

static inline void func_004239F0_push(UnkStruct_00423F30 * q, int op)
{
    q->field_4[q->field_174] = op;
    q->field_78[q->field_174] = 0;
    q->field_EC[q->field_174] = 0;
    q->field_174 = q->field_174 + 1;
}

// 0x004239F0
extern "C" void func_004239F0(UnkStruct_00423F30 * self)
{
    int i;
    int n;
    bool found;
    bool flagged;
    int cnt;
    self->field_174 = 0;
    self->field_175 = 0;
    cnt = 0;
    n = self->field_178 ? 2 : 1;
    for (i = 0; i < n; i++) {
        cnt = (cnt + *((unsigned char *)&D_00522660 + *((signed char *)&D_00522660 + i * 0x27D0 + 0x12C6FC) + 0x12ACD2)) & 0xFF;
    }
    if ((unsigned char)cnt > 0) {
        func_004239F0_push(self, 0);
        func_00423720(self);
        func_004239F0_push(self, 1);
        func_004239F0_push(self, 6);
    }
    found = false;
    flagged = false;
    for (i = 0; i < n; i++) {
        unsigned char b = *((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12C4A4);
        int c = 0;
        if (b & 1) c++;
        if (b & 4) c++;
        if (b & 2) c++;
        if (c > 0) found = true;
        if (b & 8) flagged = true;
    }
    if (found) {
        func_004239F0_push(self, 7);
        func_004231B0(self, flagged);
        func_004239F0_push(self, 2);
    }
    UnkStruct_4239F0_ctx * g = D_0051BA88.field_0;
    if (self->field_178 == 0) {
        func_004239F0_push(self, 0x13);
        if (g->field_1B8 == &D_0051B928) {
            func_004230D0(self);
        }
    } else {
        if (g->field_1B4->vfunc_A8() == 0) {
            func_004239F0_push(self, 0x14);
        } else {
            func_00422F40(self, flagged);
        }
    }
    func_004239F0_push(self, 2);
}
