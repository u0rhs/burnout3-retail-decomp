// CB3OfflineRoadRageLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OfflineRoadRageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (nested ifs; field_68[idx]=1; RaceCarKilled x2).

struct UnkStruct_0038C5D0_car {
    unsigned char pad_0[0x11E1];
    unsigned char field_11E1;
    unsigned char pad_11E2[0x16B4 - 0x11E2];
    float field_16B4;
    unsigned char pad_16B8[0x1914 - 0x16B8];
    int field_1914;
    unsigned char pad_1918[0x27C0 - 0x1918];
    int field_27C0;
};
struct UnkStruct_0038C5D0 {
    unsigned char pad_0[0x68];
    unsigned char field_68[0x100];
};
extern float D_004E0F5C;
extern "C" void OnTakedown__25CB3OfflineSingleRaceLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);
extern "C" void RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);
extern "C" void OnTakedown__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(UnkStruct_0038C5D0 *self, UnkStruct_0038C5D0_car *p1, UnkStruct_0038C5D0_car *p2)
{
    OnTakedown__25CB3OfflineSingleRaceLogicFP10CB3RaceCarP10CB3RaceCar(self, p1, p2);
    if (p2->field_11E1 != 0) {
        if (p2->field_1914 == 0) {
            self->field_68[p2->field_27C0] = 1;
        }
    }
    if (p1->field_1914 == 1) {
        if (p2->field_1914 == 0) {
            RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(self, p1, p2);
        }
    }
    if (p1->field_1914 == 0) {
        if (p1->field_16B4 < D_004E0F5C) {
            RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(self, p1, p2);
        }
    }
}
