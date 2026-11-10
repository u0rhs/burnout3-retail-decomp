// Hand-written; the lifter refused it (a76: plain init loop).

// [G] initializer: 2 x 24 slots of 24 bytes {-1,-1,0} at +0x2C and +0x26C, name buffer at +0x14 from D_004BA000 (cf. func_002303C0); no DNAT row, layout [G].
struct UnkStruct_00230570_e {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct UnkStruct_00230570 {
    unsigned char pad_0[4];
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[4];
    char field_14[16];
    int field_24;
    int field_28;
    UnkStruct_00230570_e field_2C[24];
    UnkStruct_00230570_e field_26C[24];
    int field_4AC;
};

extern char D_004BA000[];
extern "C" char * strncpy(char *, const char *, unsigned int);

// 0x00230570
extern "C" void func_00230570(UnkStruct_00230570 * self, void *a1)
{
    self->field_4 = 0;
    self->field_8 = -1;
    self->field_C = (int)a1;
    strncpy(self->field_14, D_004BA000, 16);
    self->field_24 = -1;
    self->field_28 = -1;
    for (int i = 0; i < 24; i++) {
        self->field_2C[i].field_0 = -1;
        self->field_2C[i].field_4 = -1;
        self->field_2C[i].field_8 = 0;
        self->field_26C[i].field_0 = -1;
        self->field_26C[i].field_4 = -1;
        self->field_26C[i].field_8 = 0;
    }
    self->field_4AC = 0;
}
