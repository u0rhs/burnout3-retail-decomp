// Hand-written; the lifter refused it (near8: nested field_3 ifs with the float compare's returns in place + second v test).

// func_003BA300 -- comparator (near8: field_3 test written as nested ifs with the float compare's returns in place,
// then a second 'if (v != 0) return -1;' -- retail tests v1 twice; an inline cmpf helper moved the block to the end).

struct UnkStruct_003BA300_e {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char pad_4[0x4];
    float field_8;
    unsigned char pad_C[0x4];
    int field_10;
    int field_14;
    unsigned char pad_18[0x14];
    int field_2C;
};

// 0x003BA300
extern "C" int func_003BA300(const UnkStruct_003BA300_e * a, const UnkStruct_003BA300_e * b)
{
    if (b->field_0 == 0) return -1;
    if (a->field_0 == 0) return 1;
    unsigned char v = a->field_1;
    if (v != 0 && b->field_1 == 0) return 1;
    if (b->field_1 != 0 && v == 0) return -1;
    if (v != 0) {
        if (a->field_10 < b->field_10) return 1;
        if (a->field_10 > b->field_10) return -1;
        if (a->field_2C < b->field_2C) return 1;
        if (a->field_2C > b->field_2C) return -1;
        if (a->field_14 < b->field_14) return -1;
        if (a->field_14 > b->field_14) return 1;
        goto ret0;
    }
    v = a->field_3;
    if (v != 0) {
        if (b->field_3 != 0) {
            if (a->field_8 < b->field_8) return -1;
            return 1;
        }
    }
    if (v != 0) return -1;
    if (b->field_3 != 0) return 1;
    v = a->field_2;
    if (v == 0) {
        if (b->field_2 != 0) return -1;
    }
    if (v != 0 && b->field_2 == 0) return 1;
    if (a->field_2C < b->field_2C) return 1;
    if (a->field_2C > b->field_2C) return -1;
ret0:
    return 0;
}
