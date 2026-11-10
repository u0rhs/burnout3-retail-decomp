// func_002870D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bank fields CGtSoundBank* (not int) fixes then-block layout; p0!=0 arm first; phantom args dropped).

// lifter variant 0
// func_002870D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundBank;

class CGtSoundBankManager;
struct UnkStruct_002870D0;
struct UnkStruct_D_004E1AF8;
struct UnkStruct_D_01E77540;

class CGtSoundBankManager {
public:
    CGtSoundBank * LoadBank(const char*, bool, bool, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E1AF8 {
    int field_0;
};

struct UnkStruct_D_01E77540 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002870D0 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[0x2];
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    unsigned char pad_20[0x30];
    int field_50;
    int field_54;
    unsigned char pad_58[0x8];
    int field_60;
    int field_64;
    unsigned char pad_68[0x1];
    unsigned char field_69;
    unsigned char field_6A;
    unsigned char field_6B;
    unsigned char field_6C;
    unsigned char pad_6D[0x3];
    int field_70;
    int field_74;
    CGtSoundBank * field_78;
    CGtSoundBank * field_7C;
};

extern UnkStruct_D_004E1AF8 D_004E1AF8;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_01E77540 D_01E77540;

extern "C" void UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(void *, CGtSoundBank *);  // CGtSoundBankManager::UnloadBank(CGtSoundBank*), passed 1 more argument(s) [G]
extern "C" int GetModeBankPath__23CB3SoundGameModeManagerCFv(void *);  // CB3SoundGameModeManager::GetModeBankPath() const, passed 2 more argument(s) [G]

// 0x002870D0
extern "C" int func_002870D0(UnkStruct_002870D0 * self, int p0)
{
    self->field_0 = p0;
    self->field_69 = 0;
    self->field_6A = 0;
    self->field_6C = 0;
    self->field_6B = 0;
    self->field_60 = 999;
    self->field_64 = 0;
    self->field_14 = 0;
    self->field_74 = 2;
    self->field_1 = 0;
    self->field_1C = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_C = 0;
    self->field_13 = 1;
    if (p0 != 0) {
        if (self->field_7C != 0) {
            UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(&D_01E75648, self->field_7C);
            self->field_7C = 0;
            return 0;
        }
        if (self->field_78 == 0) {
            self->field_78 = D_01E75648.LoadBank((const char*)GetModeBankPath__23CB3SoundGameModeManagerCFv(&D_01E77540), 1, 1, 4096);
        }
        if (self->field_78 == 0) {
            return 0;
        }
    } else {
        if (self->field_78 != 0) {
            UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(&D_01E75648, self->field_78);
            self->field_78 = 0;
            return 0;
        }
        if (self->field_7C == 0) {
            self->field_7C = D_01E75648.LoadBank((const char*)D_004E1AF8.field_0, 1, 0, 8192);
        }
        if (self->field_7C == 0) {
            return 0;
        }
    }
    self->field_70 = -1;
    self->field_50 = 0;
    self->field_54 = 0;
    self->field_10 = 0;
    self->field_11 = 0;
    self->field_12 = 0;
    return 1;
}
