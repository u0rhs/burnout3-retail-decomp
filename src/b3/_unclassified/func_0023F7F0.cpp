// func_0023F7F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0023F7F0;

struct UnkStruct_0023F7F0 {
    unsigned char pad_0[0x4F8];
    unsigned char field_4F8;
    unsigned char pad_4F9[0x3];
    int field_4FC;
    unsigned char pad_500[0x13D0];
    int field_18D0;
};

extern "C" void func_0022D9F0(void *);
extern "C" void func_001AA1A0(void *);
extern "C" void func_003755D0(void *);
extern "C" void func_003754B0(void *);

// 0x0023F7F0
extern "C" void func_0023F7F0(UnkStruct_0023F7F0 * self)
{
    func_0022D9F0(((char *)self + 0x6E4));
    func_001AA1A0(((char *)self + 0x924));
    func_0022D9F0(((char *)self + 0xD50));
    func_003755D0(((char *)self + 0xDC0));
    func_0022D9F0(((char *)self + 0xE30));
    func_003754B0(((char *)self + 0x1230));
    func_0022D9F0(((char *)self + 0x1630));
    self->field_4F8 = 0;
    self->field_4FC = -1;
    self->field_18D0 = 0;
}
