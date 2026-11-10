// AllocRealVoice__20CGtSoundVoiceManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (16 x 0x20 elements at +0x1A00 (voice at +4, flag byte at +0x1F); ok flag set inside two '(cond) ^ 1' tests; unsigned counter).

class CGtSoundRealVoice;
struct UnkStruct_00388FA0;
struct UnkStruct_00388FA0_e0;

class CGtSoundRealVoice {
public:
    int IsPlaying() const;

    unsigned char pad_0[0x1B];
};

struct UnkStruct_00388FA0_e0 {
    int field_0;
    CGtSoundRealVoice field_4;
    unsigned char field_1F;  // [G] bit 0: voice handed out
};

struct UnkStruct_00388FA0 {
    unsigned char pad_0[0x1A00];
    UnkStruct_00388FA0_e0 field_1A00[16];
};

// 0x00388FA0
extern "C" CGtSoundRealVoice * AllocRealVoice__20CGtSoundVoiceManagerFv(UnkStruct_00388FA0 * self)
{
    for (unsigned int i = 0; i < 16; i++) {
        bool ok = false;
        CGtSoundRealVoice * vc = &self->field_1A00[i].field_4;
        if (((vc->IsPlaying() != 0) ^ 1) != 0) {
            if ((((self->field_1A00[i].field_1F & 1) > 0) ^ 1) != 0) {
                ok = true;
            }
        }
        if (ok) {
            self->field_1A00[i].field_1F |= 1;
            return vc;
        }
    }
    return 0;
}
