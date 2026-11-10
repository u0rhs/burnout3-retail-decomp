// CB3NetworkManager::Prepare(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch(state) cases 1,2,3,default with goto s2; ushort 0xFFFF; store order).

struct UnkStruct_2714C0_p { unsigned char pad_0[0x4F0]; int field_4F0; unsigned char pad_4F4[0xCC]; unsigned char field_5C0; };
struct UnkStruct_2714C0_e { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004E2A14 { unsigned short field_0; };
extern UnkStruct_D_004E2A14 D_004E2A14;
extern "C" UnkStruct_2714C0_p * func_002366D0(void *, int);
extern "C" int func_0026D2A0(void *);
extern "C" int func_0022F320(void *);
extern "C" void func_00235BA0(void *);
extern "C" int Update__12CGtPS2LibNetFi(void *, int);
extern "C" void UpInterface__12CGtPS2LibNetFi(void *, int);
class CB3NetworkManager {
public:
    int Prepare(bool p0);
    void PrepareForGameStart();
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x9B40 - 0x2C];
    unsigned char field_9B40[0x10];
    unsigned char pad_9B50[0xA9D4 - 0x9B50];
    UnkStruct_2714C0_e field_A9D4[10];
    unsigned char field_AA74;
    unsigned char pad_AA75[0xAAB0 - 0xAA75];
    int field_AAB0;
    unsigned char pad_AAB4[2];
    unsigned char field_AAB6;
    unsigned char pad_AAB7;
    unsigned short field_AAB8;
    unsigned char pad_AABA[0x32660 - 0xAABA];
    int field_32660;
    int field_32664;
    unsigned char pad_32668[0x32978 - 0x32668];
    int field_32978;
    unsigned char pad_3297C[0x329A0 - 0x3297C];
    int field_329A0;
    unsigned char pad_329A4[5];
    unsigned char field_329A9;
    unsigned char pad_329AA[0x329B8 - 0x329AA];
    unsigned char field_329B8;
};
// 0x002714C0
int CB3NetworkManager::Prepare(bool p0)
{
    int r;
    switch (field_32664) {
    case 1:
        if (p0) {
            field_329A9 = 1;
            r = func_0022F320(field_9B40);
            if (r == 1) return 0;
            if (r == 2) {
                UpInterface__12CGtPS2LibNetFi(field_9B40, 0);
                field_32664 = 2;
                goto s2;
            }
            field_32664 = 1;
            field_329A9 = 0;
            return 1;
        }
        field_32664 = 3;
        return 0;
    case 2:
    s2:
        {
            unsigned short v = D_004E2A14.field_0;
            if (v == 0xFFFF) v = 0;
            r = Update__12CGtPS2LibNetFi(field_9B40, v);
            if (r == 1) return 0;
            field_329A9 = 0;
            if (r == 3) {
                field_32664 = 3;
                return 1;
            }
        }
    case 3:
        if (func_0026D2A0(this) != 9) return 0;
        field_32664 = 4;
    default:
        field_32978 = 0;
        PrepareForGameStart();
        field_AAB6 = 0;
        field_AA74 = 0;
        for (int i = 0; i < 10; i++) field_A9D4[i].field_0 = 0;
        for (int j = 0; j < field_28; j++) {
            UnkStruct_2714C0_p *p = func_002366D0(this, j);
            if (p != 0) {
                p->field_5C0 = 0;
                p->field_4F0 = 0;
            }
        }
        func_00235BA0(this);
        field_AAB0 = 0;
        field_AAB8 = 0xFFFF;
        field_329B8 = 0;
        field_32660 = 0;
        field_329A0 = -1;
        field_32664 = 0x17;
        return 1;
    }
}
