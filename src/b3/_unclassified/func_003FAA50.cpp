// func_003FAA50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (shared func_003FA600 tail; static inline bool helpers (IsPlaying guard, unload); !helper() then-arm; void*/CGtSoundBank* fields; variadic sprintf).

// lifter variant 0
// func_003FAA50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundBank;

class CGtSoundBankManager;
class CGtSoundRealVoice;
struct UnkStruct_003FAA50;
struct UnkStruct_D_004CE9C8;
struct UnkStruct_D_004CE9D0;
struct UnkStruct_D_004E1EC0;
struct UnkStruct_D_004E1EC4;
struct UnkStruct_D_01E774E0;

class CGtSoundRealVoice {
public:
    bool IsPlaying() const;
    void Stop();
};

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);
    CGtSoundBank * LoadBank(const char*, bool, bool, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E1EC0 {
    int field_0;
};

struct UnkStruct_D_004E1EC4 {
    int field_0;
};

struct UnkStruct_D_01E774E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CE9D0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CE9C8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FAA50 {
    unsigned char pad_0[0xF0];
    unsigned char field_F0;
    unsigned char pad_F1[0x6F];
    void * field_160;
    CGtSoundBank * field_164;
    int field_168;
    CGtSoundRealVoice * field_16C;
    int field_170;
    unsigned char pad_174[0x20];
    signed char field_194;
    unsigned char pad_195[0x3];
    int field_198;
    unsigned char pad_19C[0x12];
    unsigned char field_1AE;
};

extern UnkStruct_D_004E1EC0 D_004E1EC0;
extern UnkStruct_D_004E1EC4 D_004E1EC4;
extern UnkStruct_D_01E774E0 D_01E774E0;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_004CE9D0 D_004CE9D0;
extern UnkStruct_D_004CE9C8 D_004CE9C8;

extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_003FC650(UnkStruct_003FAA50 *);
extern "C" void func_003FA600(UnkStruct_003FAA50 *, int);
extern "C" int sprintf(char *, const void *, ...);

static inline bool a51_playing(UnkStruct_003FAA50 * self)
{
    if (self->field_16C != 0) {
        return self->field_16C->IsPlaying();
    }
    return false;
}

static inline bool a51_unload(UnkStruct_003FAA50 * self)
{
    if (self->field_198 & 16) {
        self->field_198 |= 32;
        return false;
    }
    if (self->field_164 != 0) {
        D_01E75648.UnloadBank(self->field_164);
        self->field_164 = 0;
        self->field_168 = 0;
        self->field_198 &= ~32;
    }
    return true;
}

// 0x003FAA50
extern "C" int func_003FAA50(UnkStruct_003FAA50 * self)
{
    switch (self->field_170) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 23:
        if (self->field_160 != 0) {
            Stop__14CGtSoundStreamFv(self->field_160);
            Release__14CGtSoundStreamFv(self->field_160);
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
            self->field_160 = 0;
        }
        self->field_F0 = 0;
        if (a51_playing(self)) {
            self->field_16C->Stop();
        }
        self->field_16C = 0;
        self->field_198 &= ~4;
        if (!a51_unload(self)) {
            if ((self->field_198 & 16) == 0) {
                sprintf(((char *)self + 0x110), &D_004CE9D0, D_004E1EC0.field_0, D_004E1EC4.field_0, self->field_194);
                self->field_198 |= 16;
            }
            self->field_164 = D_01E75648.LoadBank((const char*)((char *)self + 0x110), 1, 0, 2048);
            if (self->field_164 != 0) {
                self->field_168 = FindWave__12CGtSoundBankCFRCUlb(self->field_164, &D_004CE9C8, 0);
                self->field_198 &= ~16;
                self->field_194++;
                if (self->field_194 == 10) {
                    self->field_194 = 0;
                }
            }
            return 0;
        }
        func_003FC650(self);
        self->field_1AE = 1;
        self->field_170 = 24;
        break;
    case 24:
    case 25:
    case 1:
        break;
    }
    func_003FA600(self, 0);
    return 1;
}
