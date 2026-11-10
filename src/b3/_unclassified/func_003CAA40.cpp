// Hand-written; the lifter refused it (do-while signed char i; [L] DNAT CB3ControllerRemovedComponent::Construct()).

struct UnkStruct_003CAA40_row { short field_0; unsigned char pad_2[0xFE]; };
struct UnkStruct_003CAA40 {
    unsigned char pad_0[0xC];
    void *field_C;
    void *field_10[2];
    void *field_18[2];
    unsigned char pad_20[0x30];
    UnkStruct_003CAA40_row field_50[2];
    unsigned char field_250;
};
extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);
// 0x003CAA40
extern "C" void Construct__29CB3ControllerRemovedComponentFv(UnkStruct_003CAA40 *self)
{
    signed char i;
    Construct__20CB3MenuComponentBaseFi(self, 2);
    self->field_C = 0;
    self->field_250 = 0;
    i = 0;
    do {
        self->field_18[i] = 0;
        self->field_10[i] = 0;
        self->field_50[i].field_0 = 0;
        i++;
    } while (i < 2);
}
