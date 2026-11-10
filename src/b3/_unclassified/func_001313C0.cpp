// func_001313C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundStream;
class CGtVideoDecoder;
struct UnkStruct_001313C0;
struct UnkStruct_D_004EE040;

class CGtVideoDecoder {
public:
    void Update();
};

class CGtSoundStream {
public:
    void Play(bool);
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001313C0 {
    unsigned char pad_0[0x1C8];
    CGtVideoDecoder field_1C8;
    unsigned char pad_1C9[0x12F];
    int field_2F8;
    int field_2FC;
    unsigned char pad_300[0xC];
    CGtSoundStream * field_30C;
};

extern int D_004B5540[];  // [G] element count unknown
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131F60(void *);
extern "C" int func_00386010(CGtSoundStream *);
extern "C" void func_00134660(UnkStruct_001313C0 *);

// 0x001313C0
extern "C" void func_001313C0(UnkStruct_001313C0 * self)
{
    int r0 = func_00131F60(&D_004EE040);
    if (r0 == 0) {
        if (self->field_2F8 == 23) {
            self->field_1C8.Update();
            CGtSoundStream * t0 = self->field_30C;
            if (t0 != 0) {
                int r2 = func_00386010(t0);
                if (r2 == 0) {
                    if (D_004B5540[self->field_2FC] == 34) {
                        self->field_30C->Play(1);
                    } else {
                        self->field_30C->Play(0);
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        func_00134660(self);
        return;
    }
}
