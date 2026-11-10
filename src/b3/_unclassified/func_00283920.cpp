// Update__14CB3SoundScrapeFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (void return (f0 leftover); void callees; += / -= 0.1f literals; !(x <= 0) guard; else-if decrement).

// lifter variant 0
// Update__14CB3SoundScrapeFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00283920;

struct UnkStruct_00283920 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    unsigned char pad_18[0x8];
    int field_20;
    int field_24;
    float field_28;
    unsigned char pad_2C[0xC];
    int field_38;
    unsigned char field_3C;
};

extern "C" void StartScrape__14CB3SoundScrapeFiPC12CGtSoundWave(UnkStruct_00283920 *, int, void *);
extern "C" void UpdateScrape__14CB3SoundScrapeFi(UnkStruct_00283920 *, int);

// 0x00283920
extern "C" void Update__14CB3SoundScrapeFb(UnkStruct_00283920 * self, int p0)
{
    if (p0 != 0) {
        if (self->field_28 < 1.0f) {
            self->field_28 += 0.1f;
        }
    } else {
        if (!(self->field_28 <= 0.0f)) {
            self->field_28 -= 0.1f;
        }
    }
    if (self->field_10 == 0) {
        StartScrape__14CB3SoundScrapeFiPC12CGtSoundWave(self, 0, (void *)(self->field_20));
    }
    if (self->field_14 == 0) {
        StartScrape__14CB3SoundScrapeFiPC12CGtSoundWave(self, 1, (void *)(self->field_24));
    }
    if (self->field_3C != 0) {
        self->field_3C = 0;
    } else if (self->field_38 != 0) {
        self->field_38--;
    }
    if (self->field_10 != 0) {
        UpdateScrape__14CB3SoundScrapeFi(self, 0);
    }
    if (self->field_14 != 0) {
        UpdateScrape__14CB3SoundScrapeFi(self, 1);
    }
}
