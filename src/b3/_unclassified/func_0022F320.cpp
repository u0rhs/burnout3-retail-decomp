// Hand-written; the lifter refused it (a85: CGtPS2LibNet state step; default return reloads field_14 via const-int pun (FAKEMATCH-ish [G])).

// [L] DNAT: CGtPS2LibNet::Prepare() (research/proto/new_names.csv, high; the body is a connection state machine, name may be Update-like)
struct UnkStruct_0022F320_e {
    int field_0;
    unsigned char pad_4[0x14];
};
struct UnkStruct_0022F320 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x8];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x2C];
    int field_48;
    unsigned char field_4C;
    unsigned char pad_4D[0x1];
    unsigned char field_4E;
    unsigned char field_4F;
    unsigned char pad_50[0x54];
    int field_A4;
    unsigned char pad_A8[0x4];
    int field_AC;
    int field_B0;
    UnkStruct_0022F320_e field_B4[32];
    int field_3B4;
    int field_3B8;
    UnkStruct_0022F320_e field_3BC[32];
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    int field_6D0;
    unsigned char field_6D4;
    unsigned char field_6D5;
    unsigned char pad_6D6[0x36];
    int field_70C;
};
extern "C" void * memset(void *, int, unsigned int);

// 0x0022F320
extern "C" int func_0022F320(UnkStruct_0022F320 * self)
{
    if (self->field_14 == 3) {
        if (self->field_4E != 0) {
            switch (self->field_48) {
            case 2:
                self->field_14 = 1;
                self->field_48 = 2;
                self->field_4C = 0;
                self->field_18 = 0;
                self->field_4F = 0;
                break;
            case 3:
                self->field_A4 = -1;
                self->field_14 = 1;
                self->field_48 = 3;
                self->field_4C = 0;
                self->field_18 = 0;
                self->field_4F = 0;
                break;
            case 5:
                self->field_A4 = -1;
                self->field_14 = 1;
                self->field_48 = 3;
                self->field_4C = 0;
                self->field_18 = 0;
                self->field_4F = 0;
                break;
            default:
                break;
            }
        }
        self->field_4E = 1;
    } else if (self->field_4C != 0) {
        switch (self->field_48) {
        case 1:
            self->field_A4 = -1;
            self->field_AC = -1;
            self->field_B0 = -1;
            for (int i = 0; i < 32; i++) {
                self->field_B4[i].field_0 = 0;
            }
            self->field_3B4 = 0;
            self->field_3B8 = 0;
            for (int j = 0; j < 32; j++) {
                self->field_3BC[j].field_0 = 0;
            }
            self->field_6C8 = 0;
            self->field_6CC = 0;
            memset(&self->field_6D4, 0, 16);
            self->field_6D5 = 2;
            self->field_6BC = self->field_4;
            self->field_6D0 = self->field_8;
            self->field_6C4 = self->field_6BC;
            self->field_6C0 = self->field_6BC;
            self->field_70C = 0;
            self->field_14 = 1;
            self->field_48 = 2;
            self->field_4C = 0;
            break;
        case 2:
            self->field_48 = 3;
            self->field_4C = 0;
            break;
        case 3:
            self->field_48 = 4;
            self->field_14 = 2;
            self->field_4C = 0;
            break;
        default:
            return *(const int *)&self->field_14;
        }
    }
    return self->field_14;
}
