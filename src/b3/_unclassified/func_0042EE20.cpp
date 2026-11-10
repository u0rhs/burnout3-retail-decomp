// Hand-written; the lifter refused it (N182 pragma match (lead): archive source + scoped optimiser pragma).

// N182: retail compiled this function with `#pragma opt_optimizecontrolflow off` ([G] scoped to this function).
#pragma push
#pragma opt_optimizecontrolflow off

struct UnkStruct_Prof { unsigned char pad_0[0x49A]; unsigned char field_49A; };
struct UnkStruct_D_0051BF9C { UnkStruct_Prof * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
struct UnkStruct_D_01E90190 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90190 D_01E90190;
extern "C" int func_0013A3E0(void *, int);
extern "C" int func_0013A2E0(void *, int);
extern "C" int func_0013A1C0(void *, int);
extern "C" int func_0013A280(void *, int);
extern "C" int func_0013A220(void *, int);
extern "C" int func_0013A500(void *, int);
extern "C" int func_0013A4A0(void *, int);
extern "C" int func_0013A440(void *, int);
extern "C" int func_0013A160(void *, int);
extern "C" int func_00135B50(void *, int);
extern "C" int func_00135BE0(void *, int, int);
struct UnkStruct_0042EE20 {
    unsigned char pad_0[0xE4];
    int field_E4[1];
    unsigned char pad_E8[0x50];
    int field_138[1];
    unsigned char pad_13C[0x10];
    int field_14C[1];
    unsigned char pad_150[0x50];
    int field_1A0[1];
    unsigned char pad_1A4[0x28];
    int field_1CC[1];
    unsigned char pad_1D0[0x28];
    int field_1F8[1];
    unsigned char pad_1FC[0x10C];
    int field_308[1];
    unsigned char pad_30C[0x28];
    int field_334[1];
    unsigned char pad_338[0x14];
    int field_34C[1];
    unsigned char pad_350[0xC];
    signed char field_35C[12];
    unsigned char pad_368[0x30];
    int field_398;
};
// 0x0042EE20
extern "C" void func_0042EE20(UnkStruct_0042EE20 * self)
{
    int i;
    UnkStruct_Prof * p = D_0051BF9C.field_0;
    for (i = 0; i < 12; i++) {
        int v = -1;
        self->field_35C[i] = 0;
        do {
            switch (i) {
        case 0:
            v = func_0013A3E0(p, v);
            self->field_E4[self->field_35C[i]++] = v;
            break;
        case 1:
            v = func_0013A2E0(p, v);
            self->field_138[self->field_35C[i]++] = v;
            break;
        case 2:
            v = func_0013A1C0(p, v);
            self->field_14C[self->field_35C[i]++] = v;
            break;
        case 3:
            v = func_0013A280(p, v);
            self->field_1A0[self->field_35C[i]++] = v;
            break;
        case 4:
            v = func_0013A220(p, v);
            self->field_1CC[self->field_35C[i]++] = v;
            break;
        case 7:
            v = func_0013A500(p, v);
            self->field_1F8[self->field_35C[i]++] = v;
            break;
        case 6:
            v = func_0013A4A0(p, v);
            self->field_334[self->field_35C[i]++] = v;
            break;
        case 5:
            v = func_0013A440(p, v);
            self->field_308[self->field_35C[i]++] = v;
            break;
        case 8:
            v = func_0013A160(p, v);
            self->field_34C[self->field_35C[i]++] = v;
            break;
            case 9:
            case 10:
            case 11:
                v = -1;
                break;
            }
        } while (v != -1);
    }
    self->field_398 = -1;
    if (func_00135B50(p, D_01E90190.field_0) == 0) {
        return;
    }
    if (D_01E90190.field_0 != 0) {
        goto try0;
    }
try1:
    if (D_01E90190.field_0 != 1) {
        goto body1;
    }
try2:
    if (D_01E90190.field_0 == 2) {
        goto out;
    }
    if (func_00135BE0(p, 2, ((p->field_49A != 0) ^ 1))) {
        self->field_398 = 2;
    }
    goto out;
try0:
    if (func_00135BE0(p, 0, ((p->field_49A != 0) ^ 1))) {
        self->field_398 = 0;
        goto out;
    }
    goto try1;
body1:
    if (func_00135BE0(p, 1, ((p->field_49A != 0) ^ 1)) == 0) {
        goto try2;
    }
    self->field_398 = 1;
out:
    return;
}

#pragma pop
