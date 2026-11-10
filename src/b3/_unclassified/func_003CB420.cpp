// Hand-written; the lifter refused it (a132: switch 0..4 with uninit default; vcall via pun cast).

struct UnkStruct_B420 {
    unsigned char pad_0[0x10];
    unsigned short field_10;
    unsigned char pad_12[0x66];
    unsigned short field_78;
    unsigned short field_7A;
    unsigned short field_7C;
    unsigned short field_7E;
    unsigned char pad_80[0x20];
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    unsigned char pad_B4[4];
    unsigned char field_B8;
};
class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E8961C {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E89626 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E89626 D_01E89626;
extern int D_004CA470[];
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_003CB900(void *, int);

// 0x003CB420
extern "C" void func_003CB420(UnkStruct_B420 *self)
{
    int *p;
    int lo, hi;
    int s0 = self->field_10;
    switch (s0) {
    case 0:
        if (self->field_B8 == 0) return;
        hi = 2;
        p = &self->field_A0;
        lo = 0;
        break;
    case 1:
        p = &self->field_A8;
        if (D_004CA470[self->field_A0] == 1) {
            hi = 3;
            lo = 0;
        } else {
            lo = self->field_78;
            hi = self->field_7A + 1;
        }
        break;
    case 2:
        p = &self->field_AC;
        lo = self->field_7C;
        hi = self->field_7E + 1;
        break;
    case 3:
        p = &self->field_A4;
        lo = 0;
        hi = 2;
        break;
    case 4:
        p = &self->field_B0;
        lo = 0;
        hi = 2;
        break;
    }
    if (D_004F50C0.GetMenuLeft(0) != 0) {
        *p = *p - 1;
        if (*p < lo) *p = hi - 1;
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        *p = *p + 1;
        if (*p >= hi) *p = lo;
    }
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_10, *p);
    if (s0 != 0) return;
    if (D_004CA470[self->field_A0] == 1) {
        self->field_A8 = 0;
    } else {
        self->field_A8 = self->field_78;
    }
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    func_003CB900(self, self->field_10);
}
