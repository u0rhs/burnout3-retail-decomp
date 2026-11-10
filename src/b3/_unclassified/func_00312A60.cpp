// Hand-written; the lifter refused it (L276: lobby prompt-flag update; [G] find inline; (st==0&&row==0)||st!=0 for the redundant re-test; else-if order puts the |=1 stub last; block-form final test).

// [G] layout: the lobby page fields this function touches (offsets from the retail code).
struct UnkStruct_00312A60_row {
    unsigned char field_0;
    unsigned char pad_1[7];
};
struct UnkStruct_00312A60 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x1284 - 0x10];
    unsigned short field_1284;
    unsigned char pad_1286[6];
    UnkStruct_00312A60_row field_128C[6];
    unsigned char pad_12BC[4];
    int field_12C0[7];
    unsigned char field_12DC;
    unsigned char pad_12DD[0x13A4 - 0x12DD];
    unsigned char field_13A4;
    unsigned char field_13A5;
    unsigned char field_13A6;
    unsigned char pad_13A7[3];
    unsigned char field_13AA;
    unsigned char field_13AB;
    signed char field_13AC;
};
struct UnkStruct_00312A60_info {
    unsigned char pad_0[0x3C];
};
struct UnkStruct_00312A60_vt {
    // vptr at +0x0: placeholder virtuals by slot offset [G]
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
    virtual int vfunc_70();
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
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC(UnkStruct_00312A60_info *info);
    unsigned char pad_4[0xC];
};
struct UnkStruct_00312A60_mgr {
    unsigned char pad_0[0x8];
    void *field_8[8];
};
struct UnkStruct_00312A60_int { int value; unsigned char pad_4[0xC]; };
struct UnkStruct_00312A60_byte { unsigned char value; unsigned char pad_1[0xF]; };
struct UnkStruct_00312A60_ul { unsigned long value; unsigned char pad_8[0x8]; };
struct UnkStruct_00312A60_gen { unsigned char pad_0[0x10]; };

extern UnkStruct_00312A60_vt D_01E3CD44;
extern UnkStruct_00312A60_mgr D_01E32AE0;
extern UnkStruct_00312A60_int D_01E32B08;
extern UnkStruct_00312A60_gen D_01E33A8C;
extern UnkStruct_00312A60_byte D_01E898F2;
extern UnkStruct_00312A60_gen D_01E89544;
extern UnkStruct_00312A60_gen D_01E89800;
extern UnkStruct_00312A60_byte D_01E8980A;
extern UnkStruct_00312A60_ul D_01E89810;
extern UnkStruct_00312A60_int D_01E89818;
extern UnkStruct_00312A60_gen D_01E8D4B0;
extern char maOffsetTable__14CB3MenuFlowFSM[];

extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" bool AmIHost__17CB3NetworkManagerFv(void *);
extern "C" void SetItemEnabled__19CB3VSelectComponentFib(void *, int, int);
extern "C" int func_0041E8F0(void *, int *);
extern "C" float func_0041E8C0(void *);
extern "C" int func_0041E900(void *);
extern "C" int func_0041E8B0(void *);
extern "C" int func_0041E8A0(void *);
extern "C" int func_00351B20(void *, void *, void *, int, float);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, int);

// [G] placeholder inline: index of the first entry of field_12C0 equal to k, or -1.
static inline int func_00312A60_inl1(UnkStruct_00312A60 *self, int k)
{
    int n = self->field_12DC;
    for (int i = 0; i < n; i++) {
        if (self->field_12C0[i] == k)
            return i;
    }
    return -1;
}

// 0x00312A60
// Neighbour of func_00312420 ([L] DNAT: CB3OnlineLobbyPage::RebuildList) in B3OnlineLobbyPage.cpp: builds the lobby
// prompt flags and extra id, and hands them to the prompts component (D_01E89800) when they change.
extern "C" void func_00312A60(UnkStruct_00312A60 *self)
{
    UnkStruct_00312A60_info info;
    int st;
    unsigned long flags = 0;
    int extra;
    int i;

    ((UnkStruct_00312A60_vt *)&D_01E3CD44)->vfunc_BC(&info);
    if (D_01E898F2.value != 0)
        return;
    if (self->field_13AC == 11)
        return;
    if (self->field_13AC == 2) {
        extra = 0xF;
        flags |= 0x40000104;
    } else {
        flags |= 0x100;
        extra = 3;
        if ((self->field_13AC == 0 && self->field_128C[self->field_1284].field_0 == 0) || self->field_13AC != 0)
            flags |= 4;
        if (self->field_13AC == 1) {
            flags |= 0x3000000000UL;
            if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2)
                flags |= 1;
        } else if (self->field_13AC == 0) {
            i = func_00312A60_inl1(self, 6);
            if (i != -1) {
                if (self->field_128C[i].field_0 == (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2))
                    SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, i, GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2);
            }
            flags |= 1;
        } else {
            flags |= 1;
        }
    }
    if (func_0041E8F0(&D_01E33A8C, &st) == 0) {
        if (func_0041E8C0(&D_01E33A8C) == 0.0f && func_0041E900(&D_01E33A8C) != 0 && func_0041E8B0(&D_01E33A8C) == 0 &&
            func_0041E8A0(&D_01E33A8C) == 0) {
            int j;
            int c = 0;
            for (j = 0; j < D_01E32B08.value; j++) {
                if (D_01E32AE0.field_8[j] != 0)
                    c++;
            }
            if (c > 0 && ((UnkStruct_00312A60_vt *)&D_01E3CD44)->vfunc_70() == 0)
                flags |= 0x200;
        }
    }
    if (self->field_13A5 != 0 && self->field_13A4 != 0 && AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) &&
        D_01E32B08.value > 1 && ((UnkStruct_00312A60_vt *)&D_01E3CD44)->vfunc_70() == 0 && self->field_13A6 != 0 &&
        self->field_13AC != 12 && self->field_13AC != 14 && self->field_13AC != 13) {
        func_00351B20(&D_01E8D4B0, maOffsetTable__14CB3MenuFlowFSM + 0x448, maOffsetTable__14CB3MenuFlowFSM + 0x450, 0xC03, 28.0f);
        i = func_00312A60_inl1(self, 0);
        if (i != -1 && self->field_128C[i].field_0 != 0 && self->field_13AC == 0 && self->field_C > 2.0f)
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, i, 1);
        else if (i != -1 && self->field_C < 2.0f && self->field_13AC == 0 && self->field_128C[i].field_0 == 0)
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, i, 0);
    } else if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0)) {
        if (D_01E32B08.value < 2)
            func_00351B20(&D_01E8D4B0, maOffsetTable__14CB3MenuFlowFSM + 0x448, maOffsetTable__14CB3MenuFlowFSM + 0x450, 0xC14, 28.0f);
        else if (self->field_13AB == 0)
            func_00351B20(&D_01E8D4B0, maOffsetTable__14CB3MenuFlowFSM + 0x448, maOffsetTable__14CB3MenuFlowFSM + 0x450, 0xC2E, 28.0f);
        else if (self->field_13AA == 0)
            func_00351B20(&D_01E8D4B0, maOffsetTable__14CB3MenuFlowFSM + 0x448, maOffsetTable__14CB3MenuFlowFSM + 0x450, 0xC2F, 28.0f);
        else
            func_00351B20(&D_01E8D4B0, maOffsetTable__14CB3MenuFlowFSM + 0x448, maOffsetTable__14CB3MenuFlowFSM + 0x450, 0xC14, 28.0f);
        i = func_00312A60_inl1(self, 0);
        if (i != -1 && self->field_128C[i].field_0 == 0 && self->field_13AC == 0)
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, i, 0);
    }
    if (D_01E8980A.value == 0 || flags != D_01E89810.value || extra != D_01E89818.value) {
        if (D_01E8980A.value == 0)
            func_0031ECD0(&D_01E89800, 0, 3);
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, flags, extra);
    }
}
