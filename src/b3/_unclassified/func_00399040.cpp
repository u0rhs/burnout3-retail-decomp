// Hand-written; the lifter refused it (a89: callees take self (a0 passes through); early 'value != 5 return'; vfunc_C slot after vfunc_8).

// func_00399040 -- [L] DNAT: CB3OnlineGameCreateOptionsPage::Update() (research/proto/new_names.csv, vtable slot 2)
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
struct UnkStruct_00399040 {
    unsigned char pad_0[0xE0];
    int field_E0;
};
struct UnkStruct_00399040_o {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_00399040_o D_01E898E8;

extern "C" void func_00398DE0(void *);
extern "C" void UpdateKeyboard__30CB3OnlineGameCreateOptionsPageFv(void *);
extern "C" void func_00398850(void *);
extern "C" int func_0032B2C0(void *, int, int);

// 0x00399040
extern "C" void func_00399040(UnkStruct_00399040 * self)
{
    if (D_01E90424.value != 5) return;
    {
        switch (self->field_E0) {
        case 0: func_00398DE0(self); break;
        case 1: UpdateKeyboard__30CB3OnlineGameCreateOptionsPageFv(self); break;
        case 2: UpdateKeyboard__30CB3OnlineGameCreateOptionsPageFv(self); break;
        case 3: func_00398850(self); break;
        case 4: func_00398850(self); break;
        case 5:
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
                ((UnkStruct_00399040_o *)&D_01E898E8)->vfunc_C();
                self->field_E0 = 0;
            }
            break;
        }
    }
}
