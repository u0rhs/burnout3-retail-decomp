// Hand-written; the lifter refused it (a118: nested switch(g->D4){case 0:case 1:..;case 2:..;default} puts bodies 2,4,err; case 0 returns).

struct UnkStruct_00466850_g {
    unsigned char pad_0[0xD4];
    int field_D4;
    unsigned char pad_D8[0x4];
    int field_DC;
};
struct UnkStruct_D_004E2FC4_a { UnkStruct_00466850_g * field_0; };
extern UnkStruct_D_004E2FC4_a D_004E2FC4;
extern "C" int func_00465D00(int, int);

// 0x00466850
extern "C" void func_00466850(int * a0, int * a1)
{
    int one = 1;
    *a0 = one;
    UnkStruct_00466850_g * g = D_004E2FC4.field_0;
    switch (g->field_DC) {
    case 0:
        func_00465D00(one, one);
        return;
    case 1: {
        switch (g->field_D4) {
        case 0:
        case 1:
            func_00465D00(2, 1);
            break;
        case 2:
            func_00465D00(4, one);
            break;
        default:
            *a1 = 0xC;
            *a0 = 0;
            break;
        }
        break;
    }
    case 2:
        func_00465D00(3, one);
        break;
    case 3:
        func_00465D00(6, one);
        break;
    case 4:
        func_00465D00(5, one);
        break;
    case 5:
        func_00465D00(6, one);
        break;
    default:
        *a1 = 0xC;
        *a0 = 0;
        break;
    }
}
