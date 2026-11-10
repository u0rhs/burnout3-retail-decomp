// Hand-written; the lifter refused it (a118: *a0=0 before null test (store in beqz delay slot); switch cases 0..3 then default; E0 case breaks to shared return, EC case returns).

struct UnkStruct_00466DA0_g {
    unsigned char pad_0[0xD4];
    int field_D4;
    unsigned char pad_D8[0x4];
    int field_DC;
    int (*field_E0)();
    unsigned char pad_E4[0x8];
    int (*field_EC)(int *, int *);
};
struct UnkStruct_D_004E2FC4_a { UnkStruct_00466DA0_g * field_0; };
extern UnkStruct_D_004E2FC4_a D_004E2FC4;

// 0x00466DA0
extern "C" int func_00466DA0(int * a0)
{
    int r = 0;
    *a0 = 0;
    if (a0 == 0) {
        r = 7;
    }
    UnkStruct_00466DA0_g * g = D_004E2FC4.field_0;
    int s = g->field_D4;
    switch (s) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    default:
        r = 0xF;
        break;
    }
    if (r == 0) {
        switch (g->field_DC) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            r = g->field_E0();
            break;
        case 9:
        case 10:
        default:
            g->field_EC(a0, &r);
            return r;
        }
    }
    return r;
}
