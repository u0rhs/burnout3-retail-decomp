// Hand-written; the lifter refused it (a157: [L] DNAT SetFinishedOnlineRoadRage; uchar s1/a2, goto fin/blk tail, tmp1/tmp2 slot order, field_C store after s3).

// [L] DNAT: CB3MenuFinishedEvent::SetFinishedOnlineRoadRage() (research/proto/new_names.csv)
struct UnkStruct_D_0064EA70 { short field_0; unsigned char pad_2[6]; int field_8; unsigned char pad_C[0x94]; unsigned char field_A0; unsigned char pad_A1[0xF]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064ED24 { unsigned char pad_0[0x10]; };
struct UnkStruct_00430210_car {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x567];
    int field_16C8;
    float field_16CC;
    unsigned char pad_16D0[0x92];
    unsigned char field_1762;
    unsigned char pad_1763[0x211];
    unsigned short field_1974[1];
};
struct UnkStruct_00430210_w {
    unsigned char pad_0[0x12AD28];
    UnkStruct_00430210_car * field_12AD28[1];
};
struct UnkStruct_00430210 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[4];
    int field_14;
    unsigned char pad_18[4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0x60];
    unsigned short field_84[1];
    unsigned char pad_86[0x3E];
    int field_C4;
};
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064ED24 D_0064ED24;
extern float D_004E0C14;
extern UnkStruct_00430210_w D_00522660;
extern UnkStruct_00430210_car * D_0064D388[];
extern "C" int func_00271A00(void *, int);
extern "C" void func_003180A0(unsigned short *dst, const unsigned short *fmt, unsigned short *const &arg);

// 0x00430210
extern "C" void func_00430210(UnkStruct_00430210 * self)
{
    UnkStruct_D_0064EA70 * const g = &D_0064EA70;
    unsigned short * tmp1;
    unsigned short * tmp2;
    unsigned char a2 = 0;
    int a1;
    int s3;
    int s2;
    int v1;
    unsigned char s1 = 0;
    self->field_1C = 14;
    self->field_20 = 9;
    v1 = g->field_8;
    if (v1 == 2) {
        s3 = 0x26C;
        self->field_C4 = 3;
        s2 = 0xFA5;
        self->field_C = 4;
        a1 = s3;
    } else if (v1 == 3) {
        s3 = 0x35A;
        self->field_C4 = 3;
        self->field_C = 4;
        s2 = 0x32D;
        a1 = s3;
    } else {
        int i;
        bool t2 = true;
        for (i = 0; i < D_0064D37C.field_0; i++) {
            UnkStruct_00430210_car * c = D_00522660.field_12AD28[i];
            if (c->field_1160 == 0) {
                if (c->field_16C8 == 0) t2 = 0;
            }
        }
        if (v1 == 1 && g->field_A0 != 0) {
            s1 = 1;
            a1 = 0x384;
            s3 = 0x36E;
            self->field_C = 4;
            s2 = 0xFA5;
        } else if (v1 == 4 && g->field_A0 == 0 && !t2) {
            self->field_C = 4;
            a1 = 0x384;
            s3 = 0x278;
            s2 = 0xFA5;
            s1 = 1;
        } else {
            switch (v1) {
            case 4:
                a2 = (g->field_A0 != 0) ^ 1;
                break;
            case 5:
                a2 = g->field_A0;
                break;
            case 1:
                a2 = 0;
                break;
            case 2:
            case 3:
                break;
            default:
                break;
            }
            if (g->field_A0 != a2) {
                self->field_C = 4;
                a1 = 0x36D;
            } else {
                self->field_C = 1;
                a1 = 0x36C;
            }
            if (a2) {
                s3 = 0x36F;
                s2 = 0x371;
            } else {
                s3 = 0x36E;
                s2 = 0x370;
            }
        }
    }
    if (a1 >= 4005) {} else self->field_0 = func_00271A00(&D_0051BA44, a1);
    if (s3 < 4005) {
        self->field_4 = func_00271A00(&D_0051BA44, s3);
    }
    if (s2 < 4005) {
        self->field_8 = func_00271A00(&D_0051BA44, s2);
    }
    if (s3 == 0x36E) {
        if (s1) goto blk;
        {
            int j;
            UnkStruct_00430210_car * best = D_0064D388[0];
            float m = D_004E0C14;
            for (j = 0; j < D_0064D37C.field_0; j++) {
                UnkStruct_00430210_car * c = D_00522660.field_12AD28[j];
                if (c->field_16C8 != 0 && c->field_1762 != 0 && c->field_16CC < m) {
                    m = c->field_16CC;
                    best = c;
                }
            }
            tmp2 = best->field_1974;
            func_003180A0(self->field_84, (const unsigned short *)self->field_4, tmp2);
        }
    fin:
        self->field_4 = (int)self->field_84;
        goto done;
    blk:
        {
            tmp1 = (unsigned short *)&D_0064ED24;
            func_003180A0(self->field_84, (const unsigned short *)self->field_4, tmp1);
        }
        goto fin;
    }
done:
    return;
}
