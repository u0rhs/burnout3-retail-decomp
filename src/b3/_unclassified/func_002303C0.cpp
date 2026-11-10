// Hand-written; the lifter refused it (a73: single record base (byte-offset rec, stride 24) so both arrays share one s-register).

// [L] DNAT: no row for 0x2303C0 (neighbour func_00230480 is CGtNetworkPlayer::UnRegisterMessageType, low): likely a CGtNetworkPlayer reset, [G].
struct UnkStruct_D_004BA000 { char field_0[0x10]; };
struct UnkStruct_002303C0_el {
    int field_0;
    int field_4;
    void * field_8;
    unsigned char pad_C[0xC];
};
struct UnkStruct_002303C0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x8];
    char field_14[0x10];
    int field_24;
    int field_28;
    UnkStruct_002303C0_el field_2C[24];
    UnkStruct_002303C0_el field_26C[24];
    int field_4AC;
};
struct UnkStruct_002303C0_rec {
    unsigned char pad_0[0x2C];
    int field_2C;
    int field_30;
    int field_34;
    unsigned char pad_38[0x234];
    int field_26C;
    int field_270;
    void * field_274;
};
extern UnkStruct_D_004BA000 D_004BA000;
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void func_0022DA20(void *);

// 0x002303C0
extern "C" void func_002303C0(UnkStruct_002303C0 * self)
{
    self->field_4 = 0;
    self->field_8 = -1;
    strncpy(self->field_14, D_004BA000.field_0, 16);
    self->field_24 = -1;
    self->field_28 = -1;
    for (int i = 0; i < self->field_4AC; i++) {
        UnkStruct_002303C0_rec * r = (UnkStruct_002303C0_rec *)((char *)self + i * 24);
        if (r->field_274 != 0) {
            func_0022DA20(r->field_274);
        }
        r->field_2C = -1;
        r->field_30 = -1;
        r->field_34 = 0;
        r->field_26C = -1;
        r->field_270 = -1;
        r->field_274 = 0;
    }
    self->field_4AC = 0;
}
