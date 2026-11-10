// Update__17CB3SoundPlayerCarFPC10CB3RaceCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (func_0028BF90 takes p0 as a second argument (its body reads a1)).

// Update__17CB3SoundPlayerCarFPC10CB3RaceCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3RaceCar;
class CB3SoundRaceCarAttribs;

class CB3SoundTurboModel;
struct UnkStruct_0028CB00;

class CB3SoundTurboModel {
public:
    void Update(const CB3RaceCar*, const CB3SoundRaceCarAttribs*);
};

struct UnkStruct_0028CB00 {
    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0xD8];
    CB3SoundTurboModel field_144;
};

extern "C" void UpdateRoadNoise__17CB3SoundPlayerCarFPC10CB3RaceCar(void *, const void *);  // CB3SoundPlayerCar::UpdateRoadNoise(const CB3RaceCar*)
extern "C" void func_0028D830(UnkStruct_0028CB00 *, void *);
extern "C" void func_0028BF90(UnkStruct_0028CB00 *, void *);

struct UnkStruct_0028CB00_pad {
    unsigned char field_0[0x4];
    UnkStruct_0028CB00_pad() {}
    ~UnkStruct_0028CB00_pad() {}
};

// 0x0028CB00
extern "C" void Update__17CB3SoundPlayerCarFPC10CB3RaceCar(UnkStruct_0028CB00 * self, int p0)
{
    UnkStruct_0028CB00_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    func_0028D830(self, (void *)(p0));
    UpdateRoadNoise__17CB3SoundPlayerCarFPC10CB3RaceCar(self, (const CB3RaceCar*)p0);
    func_0028BF90(self, (void *)(p0));
    self->field_144.Update((const CB3RaceCar*)p0, (const CB3SoundRaceCarAttribs*)self->field_68);
}
