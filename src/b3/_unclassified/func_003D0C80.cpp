// Hand-written; the lifter refused it (row pointer c + second array as (b*)(c+5)).

struct UnkStruct_003D0C80_a { unsigned char pad_0[0x14]; signed char field_14; unsigned char pad_15[0x7]; };
struct UnkStruct_003D0C80_b { unsigned char pad_0[0x14]; signed char field_14; unsigned char pad_15[0x1B]; };
struct UnkStruct_003D0C80_c { UnkStruct_003D0C80_a field_0[5]; UnkStruct_003D0C80_b field_8C[5]; };
struct UnkStruct_003D0C80 {
    UnkStruct_003D0C80_a field_0[36][4][5];
    UnkStruct_003D0C80_c field_4EC0[100];
};
// 0x003D0C80
extern "C" void func_003D0C80(UnkStruct_003D0C80 *self)
{
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                self->field_0[i][j][k].field_14 = -1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        UnkStruct_003D0C80_a *c = self->field_4EC0[i].field_0;
        UnkStruct_003D0C80_b *d = (UnkStruct_003D0C80_b *)(c + 5);
        for (int k = 0; k < 5; k++) {
            c[k].field_14 = -1;
            d[k].field_14 = -1;
        }
    }
}
