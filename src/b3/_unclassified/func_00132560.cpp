// func_00132560 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3Burn;
struct UnkStruct_00132560;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E75640;
struct UnkStruct_theMemMgr;

class CB3Burn {
public:
    static void UnregisterStaticVariables();
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E75640 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00132560 {
    unsigned char pad_0[0x2DA74];
    int field_2DA74;
    int field_2DA78;
    unsigned char pad_2DA7C[0x10];
    int field_2DA8C;
    int field_2DA90;
};

extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E75640 D_01E75640;
extern UnkStruct_theMemMgr theMemMgr;

extern "C" void UnregisterStaticVariables__8CB3ScoreFv(void *);  // CB3Score::UnregisterStaticVariables()
extern "C" void func_00344000();
extern "C" void func_00270D00(void *);
extern "C" void func_0028AF10(void *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void func_003752F0();

// 0x00132560
extern "C" void func_00132560(UnkStruct_00132560 * self)
{
    UnregisterStaticVariables__8CB3ScoreFv(self);
    CB3Burn::UnregisterStaticVariables();
    func_00344000();
    func_00270D00(&D_01E32AE0);
    func_0028AF10(&D_01E75640);
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 10, 0);
    self->field_2DA74 = 0;
    self->field_2DA78 = 0;
    func_003752F0();
    self->field_2DA90 = 2;
    self->field_2DA8C = 2;
}
