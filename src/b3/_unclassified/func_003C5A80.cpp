// Hand-written; the lifter refused it (flags unsigned long; hu>1 gives slti at; != 0 arm first).

struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8954E { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_003C5A80 {
    unsigned char pad_0[6];
    unsigned short field_6;
    unsigned char pad_8[0x28];
    unsigned long field_30;
    unsigned char pad_38[0x11];
    unsigned char field_49;
    unsigned char pad_4A[2];
    unsigned char field_4C;
};
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
// 0x003C5A80
extern "C" void func_003C5A80(UnkStruct_003C5A80 *self)
{
    unsigned long flags = 0;
    if (D_01E65499.field_0 != 0) {
        if (D_01E8954E.field_0 == 0) {
            flags |= self->field_30;
        } else {
            flags |= 4;
            if (self->field_6 > 1) flags |= 0x100;
        }
    } else {
        if (self->field_49 != 0) {
            if (self->field_4C != 0) {
                flags |= 0x40000;
            } else {
                flags |= 1;
            }
        }
        if (D_01E8954E.field_0 == 0) {
            flags |= 0x10;
        } else {
            flags |= 4;
            if (self->field_6 > 1) flags |= 0x100;
        }
    }
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, flags, 3);
}
