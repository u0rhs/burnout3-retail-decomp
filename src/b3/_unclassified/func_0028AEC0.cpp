// Destruct__15CB3SoundManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3SoundGameModeManager;
struct UnkStruct_0028AEC0;

class CB3SoundGameModeManager {
public:
    void Destruct();
};

struct UnkStruct_0028AEC0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    unsigned char pad_4[0x1EFC];
    CB3SoundGameModeManager field_1F00;
    unsigned char pad_1F01[0x5307];
    int field_7208;
};

extern "C" void Destruct__15CGtSoundManagerFv(void *);  // CGtSoundManager::Destruct()
extern "C" void sceSifFreeSysMemory(int);

// 0x0028AEC0
extern "C" void Destruct__15CB3SoundManagerFv(UnkStruct_0028AEC0 * self)
{
    self->field_1F00.Destruct();
    Destruct__15CGtSoundManagerFv(self);
    self->vfunc_18();
    sceSifFreeSysMemory(self->field_7208);
}
