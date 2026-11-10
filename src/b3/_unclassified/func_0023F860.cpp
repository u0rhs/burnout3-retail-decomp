// func_0023F860 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0023F860;

struct UnkStruct_0023F860 {
    unsigned char pad_0[0x5C0];
    unsigned char field_5C0;
    unsigned char pad_5C1[0x1083];
    int field_1644;
    unsigned char pad_1648[0x38A4];
    int field_4EEC;
};

extern "C" void func_00230570(UnkStruct_0023F860 *, void *);
extern "C" void func_002C2070(void *);
extern "C" void func_002C2040(void *);
extern "C" void func_001AA1A0(void *);
extern "C" void func_00272D50(void *);
extern "C" void func_0026BD40(void *);
extern "C" void func_001A8610(void *);
extern "C" void func_002B7100(void *);
extern "C" void func_002B7070(void *);
extern "C" void func_00341CF0(void *);
extern "C" void func_003350E0(void *);
extern "C" void func_002F99D0(void *);
extern "C" void func_002F9920(void *);
extern "C" void func_003755D0(void *);
extern "C" void func_003754B0(void *);
extern "C" void func_003CC2C0(void *);

// 0x0023F860
extern "C" void func_0023F860(UnkStruct_0023F860 * self, void *p0_, void *p1_)
{
    int p0 = (int)p0_;
    int p1 = (int)p1_;
    self->field_5C0 = 0;
    func_00230570(self, p0_);
    self->field_1644 = p1;
    func_002C2070(((char *)self + 0x1650));
    func_002C2070(((char *)self + 0x1780));
    func_002C2040(((char *)self + 0x18B0));
    func_001AA1A0(((char *)self + 0x6E4));
    func_001AA1A0(((char *)self + 0x924));
    func_00272D50(((char *)self + 0xB64));
    func_0026BD40(((char *)self + 0xBAC));
    func_001A8610(((char *)self + 0xBBC));
    func_002B7100(((char *)self + 0xBF4));
    func_002B7100(((char *)self + 0xC08));
    func_002B7070(((char *)self + 0xC1C));
    func_002B7070(((char *)self + 0xC30));
    func_00341CF0(((char *)self + 0xC44));
    func_00341CF0(((char *)self + 0xC58));
    func_003350E0(((char *)self + 0xC6C));
    func_002F99D0(((char *)self + 0xCBC));
    func_002F99D0(((char *)self + 0xCD0));
    func_002F9920(((char *)self + 0xCE4));
    func_002F9920(((char *)self + 0xD18));
    func_003755D0(((char *)self + 0xD50));
    func_003755D0(((char *)self + 0xDC0));
    func_003754B0(((char *)self + 0xE30));
    func_003754B0(((char *)self + 0x1230));
    func_003CC2C0(((char *)self + 0x1630));
    self->field_4EEC = 0;
}
