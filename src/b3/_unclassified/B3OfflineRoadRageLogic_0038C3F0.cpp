// CB3OfflineRoadRageLogic::OnWorldPrepared() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineRoadRageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a130: RELOC note: retail %hi/%lo(D_0012AD28) is the constant 0x12AD28 (bytes equal, a107 exception); (unsigned)i index stops i*4 CSE; j declared before ptr; 0x10 wrappers for D_004A4FA8..).

struct UnkStruct_0038C3F0_car {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0x20];
    unsigned char pad_10E0[0x60];
    void * field_1140;
    unsigned char pad_1144[0xA0];
    unsigned char field_11E4[0x10];
    unsigned char pad_11F4[0x19C];
    float field_1390;
    unsigned char pad_1394[0x320];
    float field_16B4;
    unsigned char pad_16B8[0x25C];
    int field_1914;
};
struct UnkStruct_0038C3F0_car;
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD28]; UnkStruct_0038C3F0_car * field_12AD28[1]; };
struct UnkStruct_0038C3F0 {
    unsigned char pad_0[0x50];
    int field_50[6];
    unsigned char field_68[4];
    int field_6C[8];
};
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_int D_0064D37C;
extern UnkStruct_D_int D_0064D3A0;
extern UnkStruct_D_int D_01E900E8;
extern UnkStruct_D_int D_004A4FA8;
extern UnkStruct_D_int D_004A4FAC;
extern UnkStruct_D_int D_004A4FB0;
extern UnkStruct_D_int D_004EE040;
extern UnkStruct_D_int D_006481A0;
extern "C" void OnWorldPrepared__13CB3StageLogicFv(void *);
extern "C" void SetNumLives__8CB3ScoreFi(void *, int);
extern "C" void SetActive__10CB3RaceCarFb(void *, bool);
extern "C" void SetGamebreakerEvent__13CB3ScoreBonusF16EScoreBonusEvent(void *, int);
extern "C" int func_00131CE0(void *);
extern "C" void func_0014E7E0(void *, void *, void *, void *);
// 0x0038C3F0
extern "C" void OnWorldPrepared__23CB3OfflineRoadRageLogicFv(UnkStruct_0038C3F0 *self)
{
    OnWorldPrepared__13CB3StageLogicFv(self);
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_0038C3F0_car *car = D_00522660.field_12AD28[(unsigned)i];
        SetNumLives__8CB3ScoreFi(car->field_10C0, 1);
        if (car->field_1914 == 0) {
            car->field_16B4 = 1.0f - (float)D_01E900E8.field_0 / 100.0f;
        } else {
            car->field_16B4 = 1.0f;
        }
        if (car->field_1914 == 1) {
            SetActive__10CB3RaceCarFb(car, false);
            SetNumLives__8CB3ScoreFi(car->field_10C0, 0);
        }
        self->field_50[i] = 0;
    }
    int j;
    UnkStruct_D_int *ptr = 0;
    if (D_0064D3A0.field_0 == 1) {
        func_0014E7E0(&D_006481A0, &D_004A4FA8, &D_004A4FAC, &D_004A4FB0);
        ptr = &D_004A4FA8;
    }
    for (j = 0; j < D_0064D3A0.field_0; j++) {
        UnkStruct_0038C3F0_car *c = (UnkStruct_0038C3F0_car *)((char *)&D_00522660 + j * 0x27D0 + 0x12AD50);
        SetGamebreakerEvent__13CB3ScoreBonusF16EScoreBonusEvent(c->field_11E4, 0x87);
        self->field_68[j] = 0;
        if (func_00131CE0(&D_004EE040) != 0) {
            c->field_1140 = ptr;
            c->field_1390 = 180.0f;
        }
        self->field_6C[j] = 4;
    }
}
