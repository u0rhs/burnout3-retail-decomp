// HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3CrashStartInfo;

class CB3Burn;
class CB3CrashCombo;
class CB3ScoreBonus;
struct UnkStruct_00157260;
struct UnkStruct_00157260_a1;

class CB3Burn {
public:
    void StopBurn();
};

class CB3CrashCombo {
public:
    void OnCrashStart(const CB3CrashStartInfo*);
};

class CB3ScoreBonus {
public:
    void OnCrashStart();
};

struct UnkStruct_00157260_a1 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[0x2];
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_00157260 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x8C];
    int field_9C;
    unsigned char pad_A0[0x2C];
    CB3Burn field_CC;
    unsigned char pad_CD[0x51];
    unsigned char field_11E;
    unsigned char pad_11F[0x5];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x153];
    CB3CrashCombo * field_278;
    int field_27C;
    unsigned char pad_280[0x54];
    unsigned char field_2D4;
    unsigned char pad_2D5[0x1];
    unsigned char field_2D6;
    unsigned char pad_2D7[0x31];
    unsigned char field_308;
    unsigned char field_309;
    unsigned char pad_30A[0x2];
    int field_30C;
    int field_310;
    int field_314;
    unsigned char pad_318[0x20];
    int field_338;
    float field_33C;
};

extern "C" void UpdateTakeDownStats__8CB3ScoreFP17CB3CrashStartInfo(UnkStruct_00157260 *, void *);

// 0x00157260
extern "C" void HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(UnkStruct_00157260 * self, UnkStruct_00157260_a1 * p0)
{
    int v0;
    if (self->field_11E != 0) {
        self->field_CC.StopBurn();
        v0 = self->field_27C;
    } else {
        v0 = self->field_27C;
    }
    if (v0 == 3) {
        return;
    }
    if (p0 == 0) {
        self->field_308 = 0;
        self->field_309 = 0;
        self->field_30C = 0;
        self->field_310 = 0;
        self->field_314 = 0;
    } else {
        self->field_308 = p0->field_0;
        self->field_309 = p0->field_1;
        self->field_30C = p0->field_4;
        self->field_310 = p0->field_8;
        self->field_314 = p0->field_C;
    }
    UpdateTakeDownStats__8CB3ScoreFP17CB3CrashStartInfo(self, ((char *)self + 0x308));
    self->field_338 = (self->field_338 + 1);
    self->field_9C = (self->field_9C + 1);
    self->field_33C = self->field_C;
    self->field_2D6 = 0;
    self->field_2D4 = 0;
    CB3CrashCombo * t0 = self->field_278;
    if (t0 != 0) {
        t0->OnCrashStart((const CB3CrashStartInfo*)p0);
    }
    self->field_124.OnCrashStart();
}
