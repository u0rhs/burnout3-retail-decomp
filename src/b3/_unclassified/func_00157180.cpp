// HandleCrashReset__8CB3ScoreFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3CrashCombo;
class CB3ScoreBonus;
struct UnkStruct_00157180;
struct UnkStruct_D_0064D37C;

class CB3CrashCombo {
public:
    void OnCrashStop();
};

class CB3ScoreBonus {
public:
    void OnCrashReset();
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00157180 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x114];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x153];
    CB3CrashCombo * field_278;
    int field_27C;
    unsigned char pad_280[0x54];
    unsigned char field_2D4;
    unsigned char pad_2D5[0x1];
    unsigned char field_2D6;
    unsigned char pad_2D7[0x69];
    float field_340;
    unsigned char pad_344[0x178];
    float field_4BC;
    unsigned char pad_4C0[0x8];
    float field_4C8;
    unsigned char pad_4CC[0xC];
    float field_4D8[1];  // [G] element count unknown
    unsigned char pad_4DC[0x14];
    unsigned char field_4F0[1];  // [G] element count unknown
    unsigned char pad_4F1[0x5];
    unsigned char field_4F6[1];  // [G] element count unknown
    unsigned char pad_4F7[0xD];
    unsigned char field_504;
    unsigned char field_505;
    unsigned char field_506;
    unsigned char pad_507[0x1];
    int field_508;
    unsigned char pad_50C[0xB3];
    unsigned char field_5BF;
    float field_5C0;
    unsigned char pad_5C4[0x20];
    unsigned char field_5E4;
    unsigned char field_5E5;
    unsigned char field_5E6;
    unsigned char pad_5E7[0x5];
    int field_5EC;
    float field_5F0;
};

extern UnkStruct_D_0064D37C D_0064D37C;

// 0x00157180
extern "C" void HandleCrashReset__8CB3ScoreFv(UnkStruct_00157180 * self)
{
    CB3CrashCombo * t0 = self->field_278;
    if (t0 != 0) {
        t0->OnCrashStop();
    }
    if (self->field_27C == 3) return;
    for (int i = 0; (i < D_0064D37C.field_0); i++) {
        self->field_4D8[i] = -1.0f;
        self->field_4F0[i] = 0;
        self->field_4F6[i] = 0;
    }
    self->field_506 = 0;
    self->field_2D6 = 0;
    self->field_2D4 = 0;
    self->field_5BF = 0;
    self->field_5C0 = -1.0f;
    self->field_4C8 = -1.0f;
    self->field_4BC = -1.0f;
    self->field_5E4 = 0;
    self->field_5E5 = 0;
    self->field_5E6 = 0;
    self->field_504 = 0;
    self->field_505 = 0;
    self->field_508 = 0;
    self->field_340 = self->field_C;
    self->field_124.OnCrashReset();
    self->field_5EC = 0;
    self->field_5F0 = -1.0f;
}
