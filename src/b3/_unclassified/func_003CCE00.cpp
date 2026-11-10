// Hand-written; the lifter refused it (unsigned char r |= bit flags).

struct UnkStruct_003CCE00_e { unsigned char field_0; unsigned char field_1; unsigned char field_2; };
struct UnkStruct_003CCE00 {
    unsigned char pad_0[0x4A9];
    UnkStruct_003CCE00_e field_4A9[1];
    unsigned char pad_4AC[0x4FB - 0x4AC];
    unsigned char field_4FB;
};
// 0x003CCE00
extern "C" unsigned char func_003CCE00(UnkStruct_003CCE00 *self, int p0)
{
    unsigned char r = 0;
    if (self->field_4A9[p0].field_0) r |= 1;
    if (self->field_4A9[p0].field_1) r |= 2;
    if (self->field_4A9[p0].field_2) r |= 4;
    if (self->field_4FB) r |= 8;
    return r;
}
