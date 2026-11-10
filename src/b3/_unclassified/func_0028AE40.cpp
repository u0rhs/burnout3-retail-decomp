// Unpause__15CB3SoundManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundManager;

class CGtSoundManager {
public:
    void Unpause();
};

extern "C" void Pause__24CB3SoundCustomSoundtrackFv(void *, int);  // CB3SoundCustomSoundtrack::Pause(), passed 1 more argument(s) [G]

// 0x0028AE40
extern "C" void Unpause__15CB3SoundManagerFv(CGtSoundManager * self)
{
    Pause__24CB3SoundCustomSoundtrackFv((void *)(self + 21072), 0);
    self->Unpause();
}
