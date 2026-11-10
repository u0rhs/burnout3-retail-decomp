// Hand-written; the lifter refused it (a153: jtbl state machine, fallthrough cases with goto out-of-line blocks that return; unsigned char callee param).

// func_003C7B60 -- hand-matched (a153). State machine over field_1C (jump table jtbl_004CA3B0).
struct UnkStruct_D_01ECD9F0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98404 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98414 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98418 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01ECDAD0 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01ECDD88 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90190 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BF9C { void * field_0; unsigned char pad_4[0xC]; };

struct UnkStruct_003C7B60 {
    unsigned char pad_0[0x1C];
    int field_1C;
    int field_20;
    unsigned char pad_24[0x2];
    unsigned char field_26;
};

extern unsigned char D_004E2EDC;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern UnkStruct_D_01E98404 D_01E98404;
extern UnkStruct_D_01E98414 D_01E98414;
extern UnkStruct_D_01E98418 D_01E98418;
extern UnkStruct_D_01ECDAD0 D_01ECDAD0;
extern UnkStruct_D_01ECDD88 D_01ECDD88;
extern UnkStruct_D_01E90190 D_01E90190;
extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" int func_0042EA70(void *, int, unsigned char);
extern "C" int func_0042E850(void *, int, int, unsigned char);
extern "C" int func_0042E9F0(void *, int, unsigned char);
extern "C" int func_00453DC0(void *, int);
extern "C" int func_00454120(void *, int, int, int);
extern "C" int func_004547C0(void *, unsigned long, int, int);
extern "C" int func_00135B50(void *, int);
extern "C" int func_001362F0(void *);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);

// 0x003C7B60
extern "C" void func_003C7B60(UnkStruct_003C7B60 * self)
{
    void * s0;
    switch (self->field_1C) {
    case 0:
        self->field_20 = func_0042EA70(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b0;
        self->field_1C = 1;
    case 1:
        self->field_20 = func_0042E850(&D_01ECD9F0, 9, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b1;
        self->field_1C = 2;
    case 2:
        self->field_20 = func_0042E850(&D_01ECD9F0, 8, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b2;
        self->field_1C = 3;
    case 3:
        self->field_1C = 4;
        func_00453DC0(&D_01E98414, 2);
        return;
    case 4:
        self->field_20 = func_0042E850(&D_01ECD9F0, 10, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b4;
        self->field_1C = 5;
    case 5:
        self->field_20 = func_0042E9F0(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b5;
        self->field_1C = 6;
    case 6:
        self->field_20 = func_0042E850(&D_01ECD9F0, 14, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b6;
        self->field_1C = 8;
    case 8:
        s0 = D_0051BF9C.field_0;
        if (self->field_20 == -1) goto b8;
    fail:
        self->field_26 = 1;
    case 7:
        break;
    b0:
        func_00454120(&D_01E98418, 8, self->field_20, 0);
        return;
    b1:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b2:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b4:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 7);
        return;
    b5:
        func_00454120(&D_01E98418, 5, self->field_20, 0);
        return;
    b6:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 7);
        return;
    b8:
        if (func_00135B50(s0, D_01E90190.field_0) == 0) goto fail;
        {
            int v = D_01ECDD88.field_0;
            if (v == -1) goto fail;
            self->field_20 = v;
        }
        if (self->field_20 != 0) {
            func_00454120(&D_01E98418, 9, self->field_20, 0);
        } else {
            self->field_20 = func_001362F0(s0) - 1;
            func_00454120(&D_01E98418, 11, self->field_20, 0);
        }
        return;
    }
}
