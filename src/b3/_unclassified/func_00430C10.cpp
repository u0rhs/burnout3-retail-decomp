// Hand-written; the lifter refused it (a135: ori in found arm, if/else with fall-off end, s3 declared before s2).

struct UnkStruct_00430C10 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0xAE];
    unsigned char field_D2;
    unsigned char pad_D3;
    unsigned char field_D4;
    unsigned char pad_D5;
    unsigned char field_D6;
    unsigned char pad_D7[2];
    unsigned char field_D9;
    unsigned char pad_DA[5];
    unsigned char field_DF;
    unsigned char pad_E0;
    unsigned char field_E1;
    unsigned char field_E2;
};
struct UnkStruct_D_0064EA70_x { unsigned char pad_0[0x98]; int field_98; };
struct UnkStruct_D_00651240_x { unsigned char pad_0[0x98]; int field_98; };
struct UnkStruct_D_01E32B08_x { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064EA70_x D_0064EA70;
extern UnkStruct_D_00651240_x D_00651240;
extern UnkStruct_D_01E32B08_x D_01E32B08;
extern UnkStruct_D_Pad16 D_01E32AE0;
extern UnkStruct_D_Pad16 D_0051AEC0;
extern "C" void *func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" void *GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);
extern "C" void func_0013C910(void *, int, int);
extern "C" void func_0042F650(UnkStruct_00430C10 *);

// 0x00430C10
extern "C" void func_00430C10(UnkStruct_00430C10 * self)
{
    UnkStruct_D_0064EA70_x * s3;
    UnkStruct_D_00651240_x * s2 = 0;
    self->field_20 = 0x70;
    if (self->field_D6 != 0) {
        int id = -1;
        s3 = &D_0064EA70;
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            void *r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                id = func_0022FBB0(r);
            }
        }
        GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
        if (self->field_D9 != 0) {
            self->field_20 = self->field_20 | 0x100;
        }
    } else {
        s3 = &D_0064EA70;
        s2 = &D_00651240;
        if (self->field_D9 == 0) {
            if (s3->field_98 > s2->field_98) {
                self->field_E1 = 1;
                self->field_E2 = 0;
            } else if (s2->field_98 > s3->field_98) {
                self->field_E1 = 0;
                self->field_E2 = 1;
            } else {
                self->field_E1 = 1;
                self->field_E2 = 1;
            }
            func_0013C910(&D_0051AEC0, 0, self->field_E1);
            func_0013C910(&D_0051AEC0, 1, self->field_E2);
        }
        if (self->field_D9 != 0) {
            self->field_1C = 0x20;
        }
    }
    self->field_D4 = 1;
    if (self->field_D9 != 0) {
        self->field_14 = 0x9CC;
    } else {
        self->field_14 = 0x9CB;
        if (self->field_D6 != 0) {
            if (self->field_D2 == 0) {
                self->field_DF = 0xD;
                func_0042F650(self);
            }
        } else {
            if (s3->field_98 > s2->field_98) {
                self->field_DF = 0xB;
            } else if (s2->field_98 > s3->field_98) {
                self->field_DF = 0xC;
            } else {
                self->field_DF = 0xA;
            }
        }
        self->field_20 = self->field_20 | 0x80;
    }
}
