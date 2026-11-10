// Hand-written; the lifter refused it (a153: sibling of func_003C7B60 (12-state jtbl); old value via const int pun for separate load).

// func_003C7E80 -- hand-matched (a153). State machine over field_1C (jump table jtbl_004CA3E0).
struct UnkStruct_D_01ECD9F0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98404 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98414 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98418 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01ECDAD0 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01ECDD88 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90190 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BF9C { void * field_0; unsigned char pad_4[0xC]; };

struct UnkStruct_003C7E80 {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x4];
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
extern "C" int func_0042EAF0(void *, int, unsigned char);
extern "C" int func_0042EB70(void *, int, unsigned char);
extern "C" int func_00453DC0(void *, int);
extern "C" int func_00454120(void *, int, int, int);
extern "C" int func_004547C0(void *, unsigned long, int, int);
extern "C" int func_00135B50(void *, int);
extern "C" int func_001362F0_unused(void *);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);

// 0x003C7E80
extern "C" void func_003C7E80(UnkStruct_003C7E80 * self)
{
    int old;
    void * pp;
    switch (self->field_18) {
    case 0:
        self->field_20 = func_0042EA70(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b0;
        self->field_18 = 1;
    case 1:
        self->field_20 = func_0042E850(&D_01ECD9F0, 9, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b1;
        self->field_18 = 2;
    case 2:
        self->field_20 = func_0042E850(&D_01ECD9F0, 7, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b2;
        self->field_18 = 3;
    case 3:
        self->field_20 = func_0042E850(&D_01ECD9F0, 3, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b3;
        self->field_18 = 4;
    case 4:
        self->field_20 = func_0042E850(&D_01ECD9F0, 2, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b4;
        self->field_18 = 5;
    case 5:
        self->field_20 = func_0042E850(&D_01ECD9F0, 6, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b5;
        self->field_18 = 6;
    case 6:
        self->field_20 = func_0042EAF0(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b6;
        self->field_18 = 7;
    case 7:
        self->field_20 = func_0042E850(&D_01ECD9F0, 13, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b7;
        self->field_18 = 8;
    case 8:
        self->field_18 = 9;
        func_00453DC0(&D_01E98414, 0);
        return;
    case 9:
        self->field_20 = func_0042E850(&D_01ECD9F0, 4, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b9;
        self->field_18 = 10;
    case 10:
        old = *(const int *)&self->field_20;
        self->field_20 = func_0042EB70(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b10;
        if (old != -1) goto stub;
        self->field_18 = 11;
    case 11:
        pp = D_0051BF9C.field_0;
        if (self->field_20 == -1) goto b11;
    fail:
        self->field_26 = 1;
    end:
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
    b3:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b4:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b5:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b6:
        func_00454120(&D_01E98418, 4, self->field_20, 0);
        return;
    b7:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b9:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 8);
        return;
    b10:
        func_00454120(&D_01E98418, 3, self->field_20, 0);
        return;
    stub:
        self->field_26 = 1;
        goto end;
    b11:
        if (func_00135B50(pp, D_01E90190.field_0) == 0) goto fail;
        {
            int v = D_01ECDD88.field_0;
            if (v == -1) goto fail;
            self->field_20 = v;
        }
        func_00454120(&D_01E98418, 9, self->field_20, 0);
        return;
    }
}
