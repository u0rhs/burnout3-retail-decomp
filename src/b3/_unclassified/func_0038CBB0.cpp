// func_0038CBB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Hand-structured: car element pointer into D_00522660+0x12FCF0 (0x2460 stride), respawn arm first (spawn arm in the else, retail places it last), forward/backward respawn as if/else-if with the D_0064D378 bounds checks inside, spawn gate ok = time > 5*i (or i/2) as a bool, info declared before car (s1/s0)).

// func_0038CBB0 -- hand-written from the retail structure (lifted draft compiled but tail-duplicated into
// 844 instructions: its region structuring copied the shared respawn blocks into every path).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038CBB0_8 {
    unsigned char pad_0[0x204];
    int field_204;
};

struct UnkStruct_0038CBB0_11 {
    unsigned char pad_0[0x1558];
    int field_1558;
};

// one 0x2460-byte element of the array at D_00522660 + 0x12FCF0 (a CB3RaceCar: SetActive is called on it [L])
struct UnkStruct_0038CBB0_e0 {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0x5F8];
    int field_16B8;
    unsigned char pad_16BC[0x1D8];
    float field_1894[11];  // [G] element count unknown
    unsigned char pad_18C0[0x2A];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xAD];
    unsigned char field_1998;
    unsigned char pad_1999[0x13];
    signed char field_19AC;
    unsigned char pad_19AD[0xA83];
    UnkStruct_0038CBB0_11 * field_2430;
    unsigned char pad_2434[0x2C];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12FCF0];
    UnkStruct_0038CBB0_e0 field_12FCF0[1];  // [G] element count unknown
};

struct UnkStruct_0038CBB0_7 {
    unsigned char pad_0[0x18C0];
    int field_18C0;
    unsigned char pad_18C4[0xE8];
    signed char field_19AC;
    unsigned char pad_19AD[0xA83];
    UnkStruct_0038CBB0_8 * field_2430;
};

struct UnkStruct_D_0064D378 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_int {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038CBB0 {
    unsigned char pad_0[0x4D];
    unsigned char field_4D;
    unsigned char pad_4E[0x2];
    float field_50[1];  // [G] element count unknown
};

extern UnkStruct_D_int D_0064D3A4;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D378 D_0064D378;
extern UnkStruct_D_int D_0064D3A0;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_int D_0064D368;

extern "C" void SetNumLives__8CB3ScoreFi(void *, int);  // CB3Score::SetNumLives(int)
extern "C" void SetActive__10CB3RaceCarFb(void *, bool);  // CB3RaceCar::SetActive(bool)
extern "C" void func_003959E0();
extern "C" UnkStruct_0038CBB0_7 * func_001D0CB0(UnkStruct_0038CBB0_11 *);
extern "C" void func_00141D60(void *, int, int);
extern "C" void ResetCarDamage__13CB3StageLogicFP10CB3RaceCar(UnkStruct_0038CBB0 *, void *);
extern "C" void func_001BED00(UnkStruct_0038CBB0_11 *, float);
extern "C" int func_001419B0(void *);

// 0x0038CBB0
extern "C" void func_0038CBB0(UnkStruct_0038CBB0 * self)
{
    if (self->field_4D != 0) {
        func_003959E0();
    }
    for (int i = 0; i < D_0064D3A4.field_0; i++) {
        UnkStruct_0038CBB0_7 * info;
        UnkStruct_0038CBB0_e0 * car = &D_00522660.field_12FCF0[i];
        if (car->field_18EA != 0) {
            continue;
        }
        info = func_001D0CB0(car->field_2430);
        if (D_0064D378.field_0 != 0 && !(info->field_18C0 < D_0064D368.field_0 - 30)) {
            continue;
        }
        if (car->field_1998 != 0) {
            if (self->field_50[car->field_19AC] < D_00522680.field_0) {
                float d = car->field_1894[info->field_19AC];
                if (func_001419B0(car) == 0 && car->field_2430->field_1558 == 3 && !(d <= 140.0f)) {
                    if (D_0064D378.field_0 == 0 || info->field_18C0 + 30 < D_0064D368.field_0 - 25) {
                        func_00141D60(car, info->field_18C0 + 30, info->field_2430->field_204);
                        ResetCarDamage__13CB3StageLogicFP10CB3RaceCar(self, car);
                        func_001BED00(car->field_2430, 13.4112f);
                        self->field_50[car->field_19AC] = 4.0f + D_00522680.field_0;
                    }
                } else if (func_001419B0(car) == 0 && car->field_2430->field_1558 == 2 && d < -160.0f) {
                    if (D_0064D378.field_0 == 0 || info->field_18C0 - 30 > 0) {
                        func_00141D60(car, info->field_18C0 - 30, info->field_2430->field_204);
                        ResetCarDamage__13CB3StageLogicFP10CB3RaceCar(self, car);
                        func_001BED00(car->field_2430, 44.704f);
                        self->field_50[car->field_19AC] = 4.0f + D_00522680.field_0;
                    }
                }
            }
        } else {
                bool ok;
                if (D_0064D3A0.field_0 == 1) {
                    ok = D_00522680.field_0 > 5.0f * (float)i;
                } else {
                    ok = D_00522680.field_0 > 5.0f * (float)(i / 2);
                }
                if (car->field_16B8 == 0 && ok) {
                    func_00141D60(car, info->field_18C0 + 30, info->field_2430->field_204);
                    SetNumLives__8CB3ScoreFi(car->field_10C0, 1);
                    ResetCarDamage__13CB3StageLogicFP10CB3RaceCar(self, car);
                    SetActive__10CB3RaceCarFb(car, true);
                    func_001BED00(car->field_2430, 13.4112f);
                    self->field_50[car->field_19AC] = 4.0f + D_00522680.field_0;
                }
        }
    }
}
