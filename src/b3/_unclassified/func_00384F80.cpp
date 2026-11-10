// func_00384F80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundListenerManager;
class CGtSoundVoiceManager;
struct UnkStruct_00384F80;

class CGtSoundVoiceManager {
public:
    void Release();
};

class CGtSoundListenerManager {
public:
    void Release();
};

struct UnkStruct_00384F80 {
    unsigned char pad_0[0x48];
    CGtSoundListenerManager field_48;
    unsigned char pad_49[0x13];
    CGtSoundVoiceManager field_5C;
    unsigned char pad_5D[0x1E7F];
    int field_1EDC;
};

extern "C" void func_00384330(void *);
extern "C" void func_00386C90(void *);

// 0x00384F80
extern "C" int func_00384F80(UnkStruct_00384F80 * self)
{
    self->field_5C.Release();
    func_00384330(((char *)self + 0x8));
    func_00386C90(((char *)self + 0x1EA0));
    self->field_48.Release();
    self->field_1EDC = 24;
    return 1;
}
