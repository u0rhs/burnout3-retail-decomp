// Hand-written; the lifter refused it (!= || nested no-else, shared exit).

// Hand-written (a108).
struct UnkStruct_00442900 {
    unsigned char pad_0[0xE4];
    void *field_E4;
    unsigned char pad_E8[0xC];
    int field_F4_[1];
    unsigned char pad_F8[0x8];
    int field_100;
    int field_104;
    int field_108;
    unsigned char pad_10C[0xF8];
    unsigned char field_204;
};
extern "C" void func_00444AD0(int, int);
extern "C" void lgDevUpdateForceEffect(void *, void *);
// 0x00442900
extern "C" void func_00442900(UnkStruct_00442900 * self, float f12, float f13)
{
    if (self->field_204 == 0 && f12 != 0.0f) {
        int a = (int)(255.0f * f12);
        int b = (int)(1000.0f / f13);
        if (self->field_100 != a || self->field_108 != b) {
            self->field_100 = a;
            self->field_104 = 90;
            self->field_108 = b;
            func_00444AD0(0, 0);
            lgDevUpdateForceEffect(self->field_E4, &self->field_F4_);
        }
    } else {
        self->field_100 = 0;
        self->field_104 = 90;
        self->field_108 = 1000;
        func_00444AD0(0, 0);
        lgDevUpdateForceEffect(self->field_E4, &self->field_F4_);
    }
}
