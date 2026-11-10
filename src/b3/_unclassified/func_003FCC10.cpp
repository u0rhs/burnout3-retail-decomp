// func_003FCC10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_C0 void*; if (BC != 0) {...} else call; entry-jump goto loop (unsigned i declared before a const &D_004EE040 local, reused as the call's a1)).

// lifter variant 0
// func_003FCC10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FCC10;
struct UnkStruct_003FCC10_e1;
struct UnkStruct_D_004A5600;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_01E774E0;

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x7000];
    unsigned char field_7000[1];  // [G] element count unknown
};

struct UnkStruct_003FCC10_e1 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_004A5600 {
    UnkStruct_003FCC10_e1 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_01E774E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FCC10 {
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

extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_004A5600 D_004A5600;
extern UnkStruct_D_01E774E0 D_01E774E0;

extern "C" void func_0042B580(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_003FC700(UnkStruct_003FCC10 *);
extern "C" int func_0042B5D0(void *, void *);

// 0x003FCC10
extern "C" int func_003FCC10(UnkStruct_003FCC10 * self)
{
    if (self->field_C8 != 6) {
        self->field_E8 = (self->field_E8 & 254);
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
    unsigned int i = 0;
    UnkStruct_D_004EE040 * const src = &D_004EE040;
    goto loop0_test;
loop0_body:
    D_004A5600.field_0[i].field_14 = src->field_7000[i];
    i++;
loop0_test:
    if (i < 44) goto loop0_body;
    return func_0042B5D0(((char *)self + 0x8), src) & 255;
}
