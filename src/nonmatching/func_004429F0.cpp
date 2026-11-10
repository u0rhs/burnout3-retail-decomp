// NONMATCHING: func_004429F0 -- retail 58 / ours 58 instructions, 3 in changed runs
// 3 instrs off: retail loads D_004E2630 before the first store in the changed arm (lw v0,gp; move a1,0; sw a0,0x178); ours stores first. Declaring d earlier fixes the load but moves a (a0->a3).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a108); twin of func_00442900.
struct UnkStruct_004429F0 {
    unsigned char pad_0[0xEC];
    void *field_EC;
    unsigned char pad_F0[0x7C];
    int field_16C_[1];
    unsigned char pad_170[0x8];
    int field_178;
    unsigned char pad_17C[0x4];
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    unsigned char pad_190[0x74];
    unsigned char field_204;
};
struct UnkStruct_D_004E2630 { int field_0; };
extern int D_004E2630;
extern "C" void func_00444AD0(int, int);
extern "C" void lgDevAUpdateForceEffect(void *, void *);
// 0x004429F0
extern "C" void func_004429F0(UnkStruct_004429F0 * self, float f12, float f13)
{
    if (self->field_204 == 0) {
        int a = (int)(32767 * f13);
        int b = (int)(255.0f * f12);
        if (a != self->field_178 || b != self->field_180) {
            self->field_178 = a;
            self->field_180 = b;
            self->field_184 = b;
            int d = D_004E2630;
            self->field_188 = d;
            self->field_18C = d;
            func_00444AD0(0, 0);
            lgDevAUpdateForceEffect(self->field_EC, &self->field_16C_);
        }
    } else {
        self->field_178 = 0;
        self->field_180 = 102;
        self->field_184 = 102;
        int d = D_004E2630;
        self->field_188 = d;
        self->field_18C = d;
        func_00444AD0(0, 0);
        lgDevAUpdateForceEffect(self->field_EC, &self->field_16C_);
    }
}
