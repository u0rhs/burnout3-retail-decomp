// func_00284970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged duplicated tail: one && early return, then single PlayHudSound with the float param reassigned).

// func_00284970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundBank;

struct UnkStruct_00284970;
struct UnkStruct_00284970_e0;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D384;
struct UnkStruct_D_0064D3A0;

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00284970_e0 {
    unsigned char pad_0[0x1CBA];
    unsigned char field_1CBA;
    unsigned char pad_1CBB[0xB15];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_00284970_e0 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_D_0064D384 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00284970 {
    unsigned char pad_0[0x64];
    int field_64;
    unsigned char pad_68[0x1];
    unsigned char field_69;
    unsigned char pad_6A[0xE];
    int field_78;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D384 D_0064D384;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]
extern "C" int func_00131E40(void *);
extern "C" int func_00131E00(void *);

// 0x00284970
extern "C" void func_00284970(UnkStruct_00284970 * self, float f0)
{
    if (self->field_69 != 0) {
        return;
    }
    if (func_00131E40(&D_004EE040) == 0) {
        int t0 = D_0064D3A0.field_0;
        for (int i = 0; (i < t0); i++) {
            if (D_00522660.field_12A980[i].field_1CBA != 0) {
                return;
            }
        }
    }
    if (func_00131E00(&D_004EE040) != 0 && D_0064D384.field_0 == 1) {
        return;
    }
    self->field_69 = 5;
    self->field_64++;
    if ((self->field_64 % 10) != 0) {
        f0 = 0.5f;
    }
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBD69B91E81C00000, (const CGtSoundBank*)self->field_78, f0, 1.0f, 0, 0.0f);
}
