// func_003FC470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_C0 is a pointer (null-tested, passed on); &= ~1; plain if/else).

// func_003FC470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FC470;
struct UnkStruct_D_01E774E0;

struct UnkStruct_D_01E774E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FC470 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0x3];
    void * field_C0;
    unsigned char pad_C4[0x4];
    int field_C8;
    unsigned char pad_CC[0x4];
    int field_D0;
    unsigned char pad_D4[0x14];
    unsigned char field_E8;
};

extern UnkStruct_D_01E774E0 D_01E774E0;

extern "C" void func_0042B580(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_003FC700(UnkStruct_003FC470 *);

extern "C" void func_003FC470(UnkStruct_003FC470 * self)
{
    self->field_E8 &= ~1;
    if (self->field_BC != 0) {
        if (self->field_C0 != 0) {
            Stop__14CGtSoundStreamFv(self->field_C0);
            Release__14CGtSoundStreamFv(self->field_C0);
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_C0);
            self->field_C0 = 0;
        }
        if (self->field_D0 == 4) {
            self->field_D0 = 5;
            func_003FC700(self);
        }
        self->field_C8 = 6;
    } else {
        func_0042B580(((char *)self + 0x8));
    }
}
