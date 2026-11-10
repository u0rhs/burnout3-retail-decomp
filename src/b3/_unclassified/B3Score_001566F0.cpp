// CB3Score::ConfirmGrinding(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a219: callee result as unsigned char* (null-tested ptr fixes block layout), q=(uchar*)(s0+(int)r) inside if, merged || early returns).



#include "b3/GtMathPs2.h"

class CB3RaceCar;
struct UnkStruct_6320_phys {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
};
struct UnkStruct_D_0055EFEC {
    UnkStruct_6320_phys * field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];
};
class CB3Score {
public:
    static bool ConfirmGrinding(CB3RaceCar * p0, CB3RaceCar * p1);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x26C];
    int field_27C;
    unsigned char pad_280[0x360];
    CB3RaceCar * field_5E0;
    unsigned char field_5E4;
    unsigned char pad_5E5[0x7];
    CB3RaceCar * field_5EC;
    float field_5F0;
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_16B4[0x260];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};
extern UnkStruct_D_0055EFEC D_0055EFEC[];
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern "C" unsigned char * func_002366D0(void *, int);

// 0x001566F0
bool CB3Score::ConfirmGrinding(CB3RaceCar * p0, CB3RaceCar * p1)
{
    CB3Score * sa = &p0->field_10C0;
    CB3Score * sb = &p1->field_10C0;
    if (*(int *)((char *)p0 + 0x133C) == 3 || sb->field_27C == 3) {
        return false;
    }
    float w0 = D_0055EFEC[p0->field_19AC].field_0->field_B0.W();
    float w1;
    if (2.236936331f * w0 < 40.0f || (w1 = D_0055EFEC[p1->field_19AC].field_0->field_B0.W(), 2.236936331f * w1 < 40.0f)) {
        return false;
    }
    sa->field_5E4 = 1;
    sa->field_5E0 = p1;
    sb->field_5EC = p0;
    sb->field_5F0 = sb->field_C;
    int t = p0->field_1914;
    if (t == 2 && p1->field_1914 == 0) {
        int s0 = p0->field_19AC;
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            unsigned char * r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                unsigned char * q = (unsigned char *)(s0 + (int)r);
                q[0x4EFD] |= 0x10;
            }
        }
    } else if (t == 0 && p1->field_1914 == 2) {
        int s0 = p1->field_19AC;
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            unsigned char * r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                unsigned char * q = (unsigned char *)(s0 + (int)r);
                q[0x4F03] |= 0x10;
            }
        }
    }
    return true;
}
