// CB3PlayerCar::StopCrashing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a92: unsigned char param stops lbu hoist; byte-offset row address gives mult by 0xBB0).

struct UnkStruct_0640_car {
    unsigned char pad_0[0x3524];
    int field_3524;
    unsigned char pad_3528[0x4590 - 0x3528];
};
struct UnkStruct_D_0055EF70 {
    unsigned char pad_0[0x1CB80];
    UnkStruct_0640_car field_1CB80[1];
};
struct UnkStruct_D_00645170 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064D37A {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_00665E53 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_0640_key {
    unsigned long field_0;
};
struct UnkStruct_0640_row {
    // vptr at +0x0
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    UnkStruct_0640_key * field_4;
};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x28E00];
    UnkStruct_0640_row field_28E00[1];
};
struct UnkStruct_001507D0_e0 {
    unsigned char pad_0[0x70];
};
struct UnkStruct_D_0066A3D0 {
    UnkStruct_001507D0_e0 field_0[1];
};
class CB3PlayerCar {
public:
    void StopCrashing();
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x16F4];
    int field_27C0;
    unsigned char pad_27C4[0x4];
    unsigned char field_27C8;
};
extern UnkStruct_D_0055EF70 D_0055EF70;
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_0064D37A D_0064D37A;
extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0066A3D0 D_0066A3D0;
extern "C" void func_00150460(void *, unsigned char, int);
extern "C" void StopCrashing__8CB3AICarFv(void *);
extern "C" void StopCrashing__10CB3RaceCarFv(void *);
extern "C" void SetHUDMode__6CB3HUDF8EHUDMode(void *, int);

// 0x00150640
void CB3PlayerCar::StopCrashing()
{
    UnkStruct_0640_car * c;
    if (field_27C0 < D_00645170.field_0) {
        c = &D_0055EF70.field_1CB80[field_27C0];
    } else {
        c = 0;
    }
    func_00150460(this, D_0064D37A.field_0, c->field_3524);
    if (field_27C8 != 0) {
        StopCrashing__8CB3AICarFv(this);
    } else {
        StopCrashing__10CB3RaceCarFv(this);
    }
    UnkStruct_0640_row * row = (UnkStruct_0640_row *)((char *)&D_004EE040 + field_27C0 * 0xBB0 + 0x28E00);
    unsigned long key;
    if (row->field_4 != 0) {
        key = row->field_4->field_0;
    } else {
        key = 0x6D6123044330FCCFUL;
    }
    if (key != 0xBA38E7C8878337FFUL) {
        if (D_00665E53.field_0 == 0 && field_10C8 != 1 && field_10C8 != 5) {
            row->vfunc_14(0x11, 0);
        } else {
            row->vfunc_14(0x14, 0);
        }
    }
    SetHUDMode__6CB3HUDF8EHUDMode(&D_0066A3D0.field_0[field_27C0], 1);
}
