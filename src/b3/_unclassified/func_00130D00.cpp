// func_00130D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundStream;

class CGtSoundStream;
class CGtSoundStreamManager;
struct UnkStruct_00130D00;

class CGtSoundStream {
public:
    void Stop();
    void Release();
};

class CGtSoundStreamManager {
public:
    void FreeStream(CGtSoundStream*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00130D00 {
    unsigned char pad_0[0x30C];
    CGtSoundStream * field_30C;
};

extern CGtSoundStreamManager D_01E774E0;

// 0x00130D00
extern "C" void func_00130D00(UnkStruct_00130D00 * self)
{
    CGtSoundStream * t0 = self->field_30C;
    if (t0 == 0) return;
    t0->Stop();
    self->field_30C->Release();
    D_01E774E0.FreeStream((CGtSoundStream*)self->field_30C);
    self->field_30C = 0;
}
