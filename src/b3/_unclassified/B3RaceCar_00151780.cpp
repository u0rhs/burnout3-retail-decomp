// CB3RaceCar::SetFinished(EB3ScoreFinishState) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a92: 200-byte snapshot struct copy (int[8] pair loop, v4/v3 members) in CB3RaceCar 10C0->16C0).

#include "b3/classes/EB3ScoreFinishState.h"

struct UnkStruct_1780_v3 { float field_0; float field_4; float field_8; };
struct UnkStruct_1780_v4 { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_1780_snap {
    short field_0;
    short field_2;
    int field_4;
    int field_8;
    float field_C;
    float field_10;
    int field_14;
    int field_18;
    int field_1C[8];
    float field_3C;
    int field_40;
    int field_44;
    float field_48;
    int field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    int field_98;
    int field_9C;
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
    int field_A4;
    int field_A8;
    UnkStruct_1780_v4 field_AC;
    UnkStruct_1780_v3 field_BC;
};
struct UnkStruct_1780_ls {
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
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84(void *, int);
};
struct UnkStruct_1780_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_1780_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_1780_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_1780_car {
    unsigned char pad_0[0x216];
    signed char field_216;
};
struct UnkStruct_D_0055EFEC {
    UnkStruct_1780_car * field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_D_0055EF6C {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_0064D36C {
    int field_0;
    unsigned char pad_4[0xC];
};
class CB3RaceCar {
public:
    void SetFinished(EB3ScoreFinishState p0);
    unsigned char pad_0[0x10C0];
    UnkStruct_1780_snap field_10C0;
    unsigned char pad_1188[0x538];
    UnkStruct_1780_snap field_16C0;
    unsigned char pad_1788[0x138];
    int field_18C0;
    unsigned char pad_18C4[0x1C];
    int field_18E0;
    int field_18E4;
    unsigned char pad_18E8[0xC4];
    signed char field_19AC;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0055EFEC D_0055EFEC[];
extern UnkStruct_D_0055EF6C D_0055EF6C;
extern UnkStruct_D_0064D36C D_0064D36C;
extern "C" void func_00155A40(void *, int);

// 0x00151780
void CB3RaceCar::SetFinished(EB3ScoreFinishState p0)
{
    D_0051BA88.field_0->field_1B4->vfunc_84(this, (int)p0);
    field_18E0 = field_18C0;
    field_18E4 = D_0055EFEC[field_19AC].field_0->field_216;
    func_00155A40(&field_10C0, (int)p0);
    if (D_0055EF6C.field_0 == 0) {
        field_16C0 = field_10C0;
        if (p0 == 1) {
            D_0064D36C.field_0 = D_0064D36C.field_0 + 1;
            field_16C0.field_0 = D_0064D36C.field_0;
        }
    }
}
