// func_0026CA00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0026CA00;
struct UnkStruct_0026CA00_1;

struct UnkStruct_0026CA00_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
};

extern "C" int func_003607C0(void *);

// 0x0026CA00
extern "C" void func_0026CA00(UnkStruct_0026CA00 * self)
{
    ((UnkStruct_0026CA00_1 *)((char *)self + 0xA264))->vfunc_2C();
    func_003607C0(((char *)self + 0xA8B0));
}
