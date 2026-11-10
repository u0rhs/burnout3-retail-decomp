// CB3NetworkManager::PrepareForGameStart() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (member layout from offsets (rows stride 0x50 @0x323E0, int[8] @0x323C0, obj @0x9B40 vfunc_3C)).

struct UnkStruct_26DF70_obj {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
};
struct UnkStruct_26DF70_p { unsigned char pad_0[0x4F4]; unsigned char field_4F4; };
struct UnkStruct_26DF70_row { int field_0; unsigned char field_4; unsigned char pad_5[0xF]; unsigned char field_14[0x38]; unsigned char field_4C; unsigned char field_4D; unsigned char pad_4E[2]; };
extern "C" UnkStruct_26DF70_p * func_002366D0(void *, int);
extern "C" void func_0023F5B0(void *);
extern "C" void func_00272E50(void *);
class CB3NetworkManager {
public:
    void PrepareForGameStart();
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x9B40 - 0x2C];
    unsigned char field_9B40[0x10];
    unsigned char pad_9B50[0xAAB4 - 0x9B50];
    unsigned char field_AAB4;
    unsigned char pad_AAB5[0x323C0 - 0xAAB5];
    int field_323C0[8];
    UnkStruct_26DF70_row field_323E0[8];
    int field_32660;
    unsigned char pad_32664[0x32978 - 0x32664];
    int field_32978;
    unsigned char pad_3297C[0x329A4 - 0x3297C];
    short field_329A4;
    short field_329A6;
    unsigned char field_329A8;
    unsigned char pad_329A9[0x329B4 - 0x329A9];
    int field_329B4;
    unsigned char field_329B8;
    unsigned char pad_329B9[3];
    int field_329BC;
    int field_329C0;
    float field_329C4;
    int field_329C8;
    unsigned char field_329CC;
};
// 0x0026DF70
void CB3NetworkManager::PrepareForGameStart()
{
    field_32978 = 0;
    field_329A4 = 0;
    field_329A6 = 0;
    field_329A8 = 1;
    field_329BC = 0;
    field_329C4 = -1.0f;
    field_329C8 = -1;
    field_329CC = 0;
    field_329C0 = -1;
    field_AAB4 = 0;
    for (int i = 0; i < field_28; i++) {
        UnkStruct_26DF70_p *p = func_002366D0(this, i);
        if (p != 0) p->field_4F4 = 0;
    }
    field_329B8 = 0;
    field_329B4 = 0;
    ((UnkStruct_26DF70_obj *)field_9B40)->vfunc_3C();
    for (int j = 0; j < 8; j++) {
        func_0023F5B0((void *)(field_323C0[j]));
    }
    for (int k = 0; k < 8; k++) {
        field_323E0[k].field_0 = -1;
        field_323E0[k].field_4 = 0;
        func_00272E50(field_323E0[k].field_14);
        field_323E0[k].field_4C = 0;
        field_323E0[k].field_4D = 0;
    }
    field_32660 = 0;
}
