// NONMATCHING: func_001346C0 -- retail 148 / ours 135 instructions, 51 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1346C0..0x13490C). Unnamed; file B3GameMode.cpp per
// research/retail_names.csv (high). Called by both stage Prepares (func_00135280, func_00135740) and func_00131480 with
// a0 = the stage: when its +0x1BC "setup pending" flag is set it pushes the stage's race setup into the world (car
// counts; per car its 64-bit id and a byte at car+0x59 for the three car arrays of D_00522660: 0x12AD50 stride 0x27D0,
// 0x12FCF0 stride 0x2460, 0x13B2D0 stride 0x1AA0; the game-data file name, stage and track ids; LOD distances), then
// always calls slot 0xC of the objects at +0x1B4 and +0x1B8; returns 1.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_001346C0_obj { virtual void vfunc_8(); virtual void vfunc_C(); };
struct UnkStruct_001346C0 {
    unsigned long field_0;                    // [C] ld: the track id (SetTrackID__8CB3WorldFUl)
    unsigned long field_8[2];                 // [C] the first car array's ids (SetCarID__10CB3RaceCarFUl)
    unsigned long field_18[5];                // [C] the second array's ids
    unsigned long field_40[5];                // [C] the third array's ids
    unsigned long field_68;                   // [C] the stage id (SetStageID__11CB3GameDataFUl), 0 = keep
    int field_70[2];                          // [C] per car, stored as a byte at car+0x59
    int field_78[5];
    int field_8C[5];
    int field_A0;                             // [C] the three car counts (SetCarNumbers__8CB3WorldFiii)
    int field_A4;
    int field_A8;
    char field_AC[0x104];                     // [C] the game-data file name (a1 of SetGameDataFileName) [G] length
    unsigned char pad_1B0[0x4];               // [C] the stage's vtable pointer (func_00132600)
    UnkStruct_001346C0_obj * field_1B4;
    UnkStruct_001346C0_obj * field_1B8;
    unsigned char field_1BC;
};

extern unsigned char D_00522660[];            // [C] the CB3World
extern unsigned char D_006481A0[];            // [C] the CB3GameData
extern unsigned char D_00665EC0[];            // [C] the CB3GraphicsManager

extern "C" void SetCarNumbers__8CB3WorldFiii(void *, int, int, int);
extern "C" void SetCarID__10CB3RaceCarFUl(void *, unsigned long);
extern "C" void SetGameDataFileName__11CB3GameDataFPc(void *, char *);
extern "C" void SetStageID__11CB3GameDataFUl(void *, unsigned long);
extern "C" void SetTrackID__8CB3WorldFUl(void *, unsigned long);
extern "C" void SetDefaultLODSwitchDistances__22CB3GraphicsManagerBaseFv(void *);

// 0x001346C0
extern "C" int func_001346C0(UnkStruct_001346C0 * self)
{
    if (self->field_1BC != 0) {
        SetCarNumbers__8CB3WorldFiii(D_00522660, self->field_A0, self->field_A4, self->field_A8);
        for (int i = 0; i < self->field_A0; i++) {
            SetCarID__10CB3RaceCarFUl(D_00522660 + 0x12AD50 + i * 0x27D0, self->field_8[i]);
            D_00522660[0x12ADA9 + i * 0x27D0] = (unsigned char)self->field_70[i];
        }
        for (int i = 0; i < self->field_A4; i++) {
            SetCarID__10CB3RaceCarFUl(D_00522660 + 0x12FCF0 + i * 0x2460, self->field_18[i]);
            D_00522660[0x12FD49 + i * 0x2460] = (unsigned char)self->field_78[i];
        }
        for (int i = 0; i < self->field_A8; i++) {
            SetCarID__10CB3RaceCarFUl(D_00522660 + 0x13B2D0 + i * 0x1AA0, self->field_40[i]);
            D_00522660[0x13B329 + i * 0x1AA0] = (unsigned char)self->field_8C[i];
        }
        if (self->field_0 != 0) {
            SetGameDataFileName__11CB3GameDataFPc(D_006481A0, self->field_AC);
        }
        if (self->field_68 != 0) {
            SetStageID__11CB3GameDataFUl(D_006481A0, self->field_68);
        }
        SetTrackID__8CB3WorldFUl(D_00522660, self->field_0);
        SetDefaultLODSwitchDistances__22CB3GraphicsManagerBaseFv(D_00665EC0);
        self->field_1BC = 0;
    }
    if (self->field_1B4 != 0) {
        self->field_1B4->vfunc_C();
    }
    if (self->field_1B8 != 0) {
        self->field_1B8->vfunc_C();
    }
    return 1;
}
