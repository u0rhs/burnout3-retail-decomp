// Hand-written; the lifter refused it (date pack, stepwise t = t + term, unsigned %100).

// Hand-written (a108): packs a 6-field date into an int (year%100, month, day, h, m, s), stored as a float bit pattern.
struct UnkStruct_00436270_date {
    unsigned short field_0;
    unsigned short field_2;
    unsigned short field_4;
    unsigned short field_6;
    unsigned short field_8;
    unsigned short field_A;
};

// 0x00436270
extern "C" void func_00436270(float * out, UnkStruct_00436270_date * d)
{
    union { int i; float f; } u;
    int t = d->field_A + d->field_8 * 60;
    t = t + d->field_6 * 3600;
    t = t + (d->field_4 - 1) * 86400;
    t = t + (d->field_2 - 1) * 2678400;
    t = t + (unsigned)d->field_0 % 100 * 32140800;
    u.i = t;
    *out = u.f;
}
