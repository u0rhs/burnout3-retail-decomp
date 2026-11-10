// Hand-written; the lifter refused it (a66: fn-pointer call passes out (a0 stays live -> temps in a1/a2), int r=0 / else r=7 shape, two reset copies with N24 goto label loops using i <= 2 (slti at)).

// func_00465430 -- hand-matched (a66).
struct UnkStruct_D_004E2FC4 {
    unsigned char pad_0[0xD4];
    int field_D4;
    int (*field_D8)(int *);
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4[3];
    int field_100;
    int field_104;
};

extern UnkStruct_D_004E2FC4 * D_004E2FC4;

// 0x00465430
extern "C" int func_00465430(int * out, void *a1 /* passed by every caller, not read here */)
{
    int r = 0;
    int i;
    if (out == 0) {
        r = 7;
    } else {
        *out = 0;
        if (D_004E2FC4->field_D4 != 4) {
            r = D_004E2FC4->field_D8(out);
            if (r != 0) {
        D_004E2FC4->field_D4 = 4;
        D_004E2FC4->field_D8 = 0;
        D_004E2FC4->field_EC = 0;
        D_004E2FC4->field_DC = 10;
        D_004E2FC4->field_E0 = 0;
        D_004E2FC4->field_E4 = 0;
        D_004E2FC4->field_E8 = 0;
        D_004E2FC4->field_F0 = 5;
        i = 0;
        goto test1;
    body1:
        D_004E2FC4->field_F4[i++] = 0;
    test1:
        if (i <= 2) goto body1;
        D_004E2FC4->field_100 = 0;
        D_004E2FC4->field_104 = 0;
            } else if (*out == 2) {
        D_004E2FC4->field_D4 = 4;
        D_004E2FC4->field_D8 = 0;
        D_004E2FC4->field_EC = 0;
        D_004E2FC4->field_DC = 10;
        D_004E2FC4->field_E0 = 0;
        D_004E2FC4->field_E4 = 0;
        D_004E2FC4->field_E8 = 0;
        D_004E2FC4->field_F0 = 5;
        i = 0;
        goto test2;
    body2:
        D_004E2FC4->field_F4[i++] = 0;
    test2:
        if (i <= 2) goto body2;
        D_004E2FC4->field_100 = 0;
        D_004E2FC4->field_104 = 0;
                *out = 2;
            }
        }
    }
    return r;
}
