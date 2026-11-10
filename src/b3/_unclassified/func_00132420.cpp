// func_00132420 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CAsyncLoadManager;
class CB3DebugManager;
class CB3GraphicsManagerBase;
class CB3SoundManager;
class CB3World;
struct UnkStruct_00132420;
struct UnkStruct_00132420_2;
struct UnkStruct_00132420_3;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_theMemMgr;

class CAsyncLoadManager {
public:
    void Shutdown();
};

class CB3GraphicsManagerBase {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundManager {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3DebugManager {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3World {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00132420_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
};

struct UnkStruct_00132420_3 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00132420 {
    unsigned char pad_0[0x80C0];
    CAsyncLoadManager field_80C0;
    unsigned char pad_80C1[0x25987];
    int field_2DA48;
    int field_2DA4C;
    unsigned char field_2DA50;
    unsigned char pad_2DA51[0x3B];
    int field_2DA8C;
    int field_2DA90;
};

extern UnkStruct_D_01EA2970 D_01EA2970;
extern CB3GraphicsManagerBase D_00665EC0;
extern CB3SoundManager D_01E75640;
extern CB3DebugManager D_004EB1E0;
extern CB3World D_00522660;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_theMemMgr theMemMgr;

extern "C" void func_0013C870(void *);
extern "C" void func_00270C90(void *);
extern "C" void func_00271A10(void *);
extern "C" void func_0021B760(void *);
extern "C" void Destruct__19CB3MemoryManagerPS2Fv(void *);
extern "C" void func_003752E0();

// 0x00132420
extern "C" void func_00132420(UnkStruct_00132420 * self)
{
    self->field_80C0.Shutdown();
    D_00665EC0.Destruct();
    D_01E75640.Destruct();
    D_004EB1E0.Destruct();
    D_00522660.Destruct();
    func_0013C870(((char *)self + 0x8854));
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_C();
    func_00270C90(&D_01E32AE0);
    self->field_2DA50 = 0;
    self->field_2DA48 = 0;
    self->field_2DA4C = 0;
    ((UnkStruct_00132420_2 *)((char *)self + 0x28E00))->vfunc_C();
    ((UnkStruct_00132420_3 *)((char *)self + 0x299B0))->vfunc_C();
    func_00271A10(((char *)self + 0x2DA04));
    func_00271A10(((char *)self + 0x2DA08));
    func_0021B760(((char *)self + 0x7000));
    Destruct__19CB3MemoryManagerPS2Fv(&theMemMgr);
    func_003752E0();
    self->field_2DA90 = 3;
    self->field_2DA8C = 3;
}
