// func_0028B380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten from asm: lazy AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki, early returns, (unsigned char)(255*v), pointer to the 0x5248 member declared after the if/else (tail-duplicated), counted loop).

// lifter variant 0
// func_0028B380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3SpeakerConfig {};

class CGtSoundBankManager;
struct UnkStruct_0028B380;
struct UnkStruct_0028B380_6;
struct UnkStruct_D_004E1B88;
struct UnkStruct_D_004E1B9C;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_004F5073;
struct UnkStruct_D_004F5074;
struct UnkStruct_D_004F5075;
struct UnkStruct_D_004F5079;
struct UnkStruct_theMemMgr;

class CGtSoundBankManager {
public:
    int LoadBank(const char*, bool, bool, int);
};

struct UnkStruct_D_004F5074 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E1B9C {
    float field_0;
};

struct UnkStruct_D_004F5075 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F5073 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F5079 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028B380_6 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x58];
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x7000];
    unsigned char field_7000[0x10];  // [G] element count unknown
};

struct UnkStruct_D_004E1B88 {
    const char * field_0;
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028B380 {
    unsigned char pad_0[0x8];
    CGtSoundBankManager field_8;
    unsigned char pad_9[0x1ED3];
    int field_1EDC;
    unsigned char pad_1EE0[0xFF0];
    unsigned char field_2ED0[0x2378];
    unsigned char field_5248[0x1FB8];
    int field_7200;
    int field_7204;
    int field_7208;
    unsigned char pad_720C[0x8];
    unsigned char field_7214;
    unsigned char field_7215;
};

extern UnkStruct_D_004F5074 D_004F5074;
extern UnkStruct_D_004E1B9C D_004E1B9C;
extern UnkStruct_D_004F5075 D_004F5075;
extern UnkStruct_D_004F5073 D_004F5073;
extern UnkStruct_D_004F5079 D_004F5079;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_004E1B88 D_004E1B88;
extern UnkStruct_theMemMgr theMemMgr;

extern "C" void StopAll__15CGtSoundManagerFv(void *);  // CGtSoundManager::StopAll()
extern "C" void SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(void *, EB3SpeakerConfig);  // CB3SoundManager::SetSpeakerConfig(EB3SpeakerConfig)
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int Prepare__15CGtSoundManagerFPvPvii(UnkStruct_0028B380 *, void *, void *, int, int);
extern "C" void func_0027A900(void *, float);
extern "C" float func_003F8890(void *, float);
extern "C" void func_003F8870(void *, int);
extern "C" void func_003FBB50(void *, int, UnkStruct_0028B380_6 *);
extern "C" void func_003FBAA0(void *, int, UnkStruct_0028B380_6 *, unsigned char);

// 0x0028B380
extern "C" int func_0028B380(UnkStruct_0028B380 * self)
{
    UnkStruct_0028B380_6 local;
    if (self->field_7204 == 0) {
        self->field_7204 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 15, 0);
    }
    if (Prepare__15CGtSoundManagerFPvPvii(self, (void *)(self->field_7204), (void *)(self->field_7208), 0x40000, 0x20000) == 0) return 0;
    if (self->field_7200 == 0) {
        self->field_7200 = self->field_8.LoadBank(D_004E1B88.field_0, 1, 1, 0x1800);
        if (self->field_7200 == 0) return 0;
    }
    StopAll__15CGtSoundManagerFv(self);
    self->field_1EDC = 23;
    self->field_7215 = 0;
    float v = (float)D_004F5074.field_0 * D_004E1B9C.field_0;
    func_0027A900(self->field_2ED0, v);
    self->field_7214 = (unsigned char)(255.0f * v);
    func_003F8890(self->field_5248, (float)D_004F5075.field_0 * D_004E1B9C.field_0);
    SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(self, (EB3SpeakerConfig)D_004F5073.field_0);
    if (D_004F5079.field_0 != 0) {
        func_003F8870(self->field_5248, 1);
    } else {
        func_003F8870(self->field_5248, 0);
    }
    void *m = self->field_5248;
    func_003FBB50(m, 0, &local);
    for (int i = 0; i < local.field_4; i++) {
        func_003FBAA0(m, i, &local, D_004EE040.field_7000[i]);
    }
    return 1;
}
