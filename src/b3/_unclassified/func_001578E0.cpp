// Hand-written; the lifter refused it (a85: CalculateScoreForTakedowns; byte-offset car lookup with (unsigned)i*4 stops CSE of the index shift).

// [L] DNAT: CB3Score::CalculateScoreForTakedowns() (research/proto/new_names.csv, high)
class CB3RaceCar;
struct UnkStruct_Car {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};
struct UnkStruct_Player {
    unsigned char pad_0[0x4EFD];
    unsigned char field_4EFD[6];
    unsigned char field_4F03[1];
};
class CB3Score {
public:
    bool OnTakeDown(CB3RaceCar *);
    static float gmrTakedownWaitTime;
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    UnkStruct_Car * field_C8;
    unsigned char pad_CC[0x408];
    UnkStruct_Car * field_4D4;
    float field_4D8[1];
    unsigned char pad_4DC[0x14];
    unsigned char field_4F0[6];
    unsigned char field_4F6[1];
};
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" UnkStruct_Player * func_002366D0(void *, int);

// 0x001578E0
extern "C" void CalculateScoreForTakedowns__8CB3ScoreFv(CB3Score * self)
{
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        float * p = &self->field_4D8[i];
        float t = *p;
        if (t < 0.0f) continue;
        if (self->field_C < t + CB3Score::gmrTakedownWaitTime && self->field_4F0[i] == 0) continue;
        if (self->field_C8->field_18EA == 0 || self->field_4F0[i] != 0) {
            UnkStruct_Car * car = *(UnkStruct_Car **)((char *)&D_00522660 + (unsigned int)i * 4 + 0x12AD28);
            if (self->OnTakeDown((CB3RaceCar *)car)) {
                int a2 = car->field_1914;
                if (a2 == 0 && self->field_C8->field_1914 == 2) {
                    signed char idx = self->field_C8->field_19AC;
                    for (int j = 0; j < D_01E32B08.field_0; j++) {
                        UnkStruct_Player * pl = func_002366D0(&D_01E32AE0, j);
                        if (pl != 0) {
                            pl->field_4EFD[idx] |= 1;
                        }
                    }
                } else if (a2 == 2 && self->field_C8->field_1914 == 0) {
                    signed char idx = car->field_19AC;
                    for (int j = 0; j < D_01E32B08.field_0; j++) {
                        UnkStruct_Player * pl = func_002366D0(&D_01E32AE0, j);
                        if (pl != 0) {
                            pl->field_4F03[idx] |= 1;
                        }
                    }
                }
            }
        }
        *p = -1.0f;
        self->field_4F0[i] = 0;
        self->field_4F6[i] = 0;
    }
    if (self->field_4D4 != 0 && self->field_4D4->field_18EA == 0) {
        self->field_4D4 = 0;
    }
}
