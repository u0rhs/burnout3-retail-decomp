// Hand-written; the lifter refused it (near3: call result in a top-declared 'int r' (declared before s1) compared 'r == s1' gives beq v0,s1; the case-12/chk/found exits are 'return' (not goto end) so they thread to the epilogue).


// [G] state machine over field_14 (jtbl_004CA410, 20 states); sibling of func_003C7E80
struct UnkStruct_D_01ECD9F0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98404 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98414 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98418 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01ECDAD0 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01ECDD88 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90190 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BF9C { void * field_0; unsigned char pad_4[0xC]; };

struct UnkStruct_3C82E0 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x8];
    int field_20;
    unsigned char field_24;
    unsigned char pad_25;
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
extern "C" int func_0042E970(void *, int, unsigned char);
extern "C" int func_0042EBF0(void *, int, unsigned char);
extern "C" int func_0042EC70(void *, int, unsigned char);
extern "C" int func_0042ECF0(void *, int, int, unsigned char);
extern "C" int func_003C60B0(void *, int, int);
struct UnkStruct_D_01E959C8 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E959C8 D_01E959C8;
extern "C" int func_0042EAF0(void *, int, unsigned char);
extern "C" int func_0042EB70(void *, int, unsigned char);
extern "C" int func_00453DC0(void *, int);
extern "C" int func_00454120(void *, int, int, int);
extern "C" int func_004547C0(void *, unsigned long, int, int);
extern "C" int func_00135B50(void *, int);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);

// 0x003C82E0
extern "C" void func_003C82E0(UnkStruct_3C82E0 * self)
{
    int r;
    int old;
    int s1;
    void * pp;
    switch (self->field_14) {
    case 0:
        self->field_20 = func_0042EA70(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b0;
        self->field_14 = 1;
    case 1:
        self->field_20 = func_0042E970(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b1;
        self->field_14 = 2;
    case 2:
        self->field_20 = func_0042E850(&D_01ECD9F0, 1, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b2;
        self->field_14 = 3;
    case 3:
        self->field_20 = func_0042E850(&D_01ECD9F0, 9, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b3;
        self->field_14 = 4;
    case 4:
        self->field_20 = func_0042E850(&D_01ECD9F0, 7, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b4;
        self->field_14 = 5;
    case 5:
        self->field_20 = func_0042E850(&D_01ECD9F0, 3, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b5;
        self->field_14 = 6;
    case 6:
        self->field_20 = func_0042E850(&D_01ECD9F0, 2, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b6;
        self->field_14 = 7;
    case 7:
        self->field_20 = func_0042E850(&D_01ECD9F0, 6, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b7;
        self->field_14 = 8;
    case 8:
        self->field_20 = func_0042EAF0(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b8;
        self->field_14 = 9;
    case 9:
        self->field_20 = func_0042E850(&D_01ECD9F0, 13, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b9;
        self->field_14 = 10;
    case 10:
        self->field_14 = 11;
        func_00453DC0(&D_01E98414, 0);
        return;
    case 11:
        self->field_20 = func_0042E850(&D_01ECD9F0, 4, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b11;
        self->field_14 = 12;
    case 12:
        self->field_14 = 13;
        func_00453DC0(&D_01E98414, 1);
        return;
    case 13:
        self->field_20 = func_0042E850(&D_01ECD9F0, 5, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b13;
        self->field_14 = 14;
    case 14:
        self->field_20 = func_0042EBF0(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b14;
        self->field_14 = 15;
    case 15:
        self->field_20 = func_0042E850(&D_01ECD9F0, 11, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b15;
        self->field_14 = 16;
    case 16:
        s1 = self->field_20 + 1;
        goto ltest;
    lbody:
        if (self->field_24 == 0) goto chk;
    cont:
        r = func_0042EC70(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (r == s1) goto found;
        self->field_20 = self->field_20 + 1;
        self->field_24 = 0;
        s1 = self->field_20 + 1;
    ltest:
        if (s1 < 4) goto lbody;
        self->field_20 = -1;
        self->field_14 = 17;
    case 17:
        self->field_20 = func_0042E850(&D_01ECD9F0, 12, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b17;
        self->field_14 = 18;
    case 18:
        old = *(const int *)&self->field_20;
        self->field_20 = func_0042EB70(&D_01ECD9F0, self->field_20, D_004E2EDC);
        if (self->field_20 >= 0) goto b18;
        if (old != -1) goto stub;
        self->field_14 = 19;
    case 19:
        pp = D_0051BF9C.field_0;
        if (self->field_20 == -1) goto b19;
    fail:
        self->field_26 = 1;
    end:
        break;
    b0:
        func_00454120(&D_01E98418, 8, self->field_20, 0);
        return;
    b1:
        func_00454120(&D_01E98418, 6, self->field_20, 0);
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
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b7:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b8:
        func_00454120(&D_01E98418, 4, self->field_20, 0);
        return;
    b9:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 6);
        return;
    b11:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 8);
        return;
    b13:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 9);
        return;
    b14:
        func_00454120(&D_01E98418, 2, self->field_20, 0);
        return;
    b15:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 9);
        return;
    chk:
        if (func_0042ECF0(&D_01ECD9F0, s1, -1, D_004E2EDC) < 0) goto cont;
        func_003C60B0(&D_01E959C8, 0, self->field_20 + 1);
        self->field_24 = 1;
        return;
    found:
        func_00454120(&D_01E98418, 1, s1, 0);
        self->field_20 = self->field_20 + 1;
        self->field_24 = 0;
        return;
    b17:
        func_004547C0(&D_01E98404, GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_20), D_01ECDAD0.field_0, 9);
        return;
    b18:
        func_00454120(&D_01E98418, 3, self->field_20, 0);
        return;
    stub:
        self->field_26 = 1;
        goto end;
    b19:
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
