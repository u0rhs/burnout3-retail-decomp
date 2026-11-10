// Hand-written; the lifter refused it (exact; switch jump table retargeted (N166 alias label)).

// a67: MATCHES (64/64, 0 changed) in try.py, but the 8-case fallthrough switch emits a jump table (.rodata), which the single-function pipeline rejects ('object has data sections'); needs the jtbl_retarget path (tools/jtbl_retarget.py) / merged TU. Source is exact.

// [L] DNAT: CGtPS2LibNet::Release() (research/proto/new_names.csv, high)
struct UnkStruct_0022F220_1 {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x24];
    unsigned char field_40;
    unsigned char pad_41[0x7];
    int field_48;
    unsigned char field_4C;
    unsigned char pad_4D[0x2];
    unsigned char field_4F;
    unsigned char pad_50[0x50];
    int field_A0;
    unsigned char pad_A4[0x8];
    int field_AC;
    unsigned char pad_B0[0x654];
    int field_704;
};
extern "C" void sceNetcnfifDeleteMc2Thread(int);
extern "C" void sceNetcnfifTerm();
extern "C" void sceInsockShutdown(int, int);
extern "C" void func_0022DA60(UnkStruct_0022F220_1 *);

// 0x0022F220
extern "C" void Release__12CGtPS2LibNetFv(UnkStruct_0022F220_1 *self)
{
    switch (self->field_48) {
    case 6:
    case 7:
        if (self->field_4C) {
            sceInsockShutdown(self->field_AC, 2);
            self->field_704 = -1;
            self->field_AC = -1;
        }
        self->field_4C = 1;
    case 5:
        if (self->field_4C) {
            func_0022DA60(self);
        }
        self->field_4C = 1;
    case 4:
        self->field_4C = 1;
    case 3:
        if (self->field_4C) {
            if (self->field_A0 >= 0) {
                sceNetcnfifDeleteMc2Thread(self->field_A0);
                self->field_A0 = -1;
                sceNetcnfifTerm();
            }
        }
        self->field_4C = 1;
    case 2:
        self->field_4C = 1;
    default:
        break;
    }
    self->field_14 = 0;
    self->field_48 = 1;
    self->field_4C = 1;
    self->field_40 = 0;
    self->field_18 = 0;
    self->field_4F = 0;
}
