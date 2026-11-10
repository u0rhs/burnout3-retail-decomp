// NONMATCHING: Construct__19CB3MemoryManagerPS2Fv -- retail 399 / ours 389 instructions, 56 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x222650). The PS2 memory map [C every constant]: fixed blocks
// (layout -1) from the arena D_0067D880, then three overlapping layouts 0 / 1 / 2 from arena + 0x3E3800 (the active one
// is +0x984, set later). Block objects 16 bytes apart; arguments (block, base, layout, size).
// Name: the asm symbol, which came from a config/symbol_addrs.txt row marked "names are ours" (the earlier research repo, upstream)
// -- not evidence. [L] research/retail_names.csv (high): CB3MemoryManagerPS2::Construct().
// TRACK: clean
// EQUIV: [L] written from the retail asm: every branch, store and call accounted for

// [C] the PS2 memory manager (theMemMgr, a0 of Update__19CB3MemoryManagerPS2Fv in func_00132600): 16-byte CB3ManagedMemoryBlock objects
// at +0x4 .. +0x9BC (a0 of their Construct / GetMemoryBlock / ReleaseMemoryBlock / Update), the active layout at
// +0x984 (-1 none, 0 / 1 / 2), +0x988 cleared by Construct__19CB3MemoryManagerPS2Fv. Blocks 0x17..0x1A map to the four fixed blocks below,
// block 4 to the layout's large block; every other id goes to the CB3MemoryManager base.
struct UnkStruct_mm {
    unsigned char pad_0[0x984];
    int field_984;
    int field_988;
};
static inline void * func_00222300_inl1(UnkStruct_mm * m, int off) { return (unsigned char *)m + off; }
extern unsigned char D_0067D880[];        // [C] the arena (bss): the fixed blocks from +0, the layouts from +0x3E3800
extern unsigned char * _gpWholeMemoryBlock;       // [C] gp-relative
extern void * _gpWholeMemoryBlockUnaligned;
extern "C" void Construct__21CB3ManagedMemoryBlockFPvii(void *, void *, int, int);
extern "C" void * GetMemoryBlock__21CB3ManagedMemoryBlockFi(void *, int);
extern "C" int ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(void *, int);
extern "C" void Update__21CB3ManagedMemoryBlockFi(void *, int);
extern "C" int func_003E8B70(void *);
extern "C" void func_003E87A0(void *);
extern "C" int GetBlockSize__16CB3MemoryManagerCF14EB3MemoryBlock(void *, int);
extern "C" int QueryBlock__16CB3MemoryManagerCF14EB3MemoryBlocki(void *, int, int);
extern "C" int ReleaseBlock__16CB3MemoryManagerF14EB3MemoryBlocki(void *, int, int);
extern "C" void * AcquireBlock__16CB3MemoryManagerF14EB3MemoryBlocki(void *, int, int);
extern "C" void free(void *);

// 0x00222650
extern "C" void Construct__19CB3MemoryManagerPS2Fv(UnkStruct_mm * m)
{
    unsigned char * a = D_0067D880;
    unsigned char * b = a + 0x3E3800;
    int i;
    m->field_984 = -1;
    m->field_988 = 0;
    _gpWholeMemoryBlock = a;
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x4), a, -1, 0x127000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x14), a + 0x127000, -1, 0x41800);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x24), a + 0x168800, -1, 0x800);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x34), a + 0x169000, -1, 0x5000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x44), a + 0x16E000, -1, 0x9000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x54), a + 0x177000, -1, 0x8000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x98C), a + 0x17F000, -1, 0x200000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x9BC), a + 0x37F000, -1, 0x5800);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x64), a + 0x39D800, -1, 0x4000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0xF4), a + 0x3C3000, -1, 0x20800);
    for (i = 0; i < 8; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x74 + i * 16), a + i * 0x4300 + 0x3A1800, -1, 0x4300);
    // layout 0
    for (i = 0; i < 2; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x8E4 + i * 16), b + i * 0x72000, 0, 0x72000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x904), b + 0xE4000, 0, 0x20000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x914), b + 0x104000, 0, 0x8800);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x934), b + 0x10C800, 0, 0xE0000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x944), b + 0x1EC800, 0, 0x900000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x964), b + 0xAECC00, 0, 0x4EB000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x954), b + 0xAEC800, 0, 0x400);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x974), b + 0xFD7C00, 0, 0x64000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x99C), b + 0x103BC00, 0, 0x1);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x9AC), b + 0x103BC80, 0, 0x221000);
    // layout 1
    for (i = 0; i < 6; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x104 + i * 16), b + i * 0x72000, 1, 0x72000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x164), b + 0x5AC000, 1, 0x8800);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x174), b + 0x5B4800, 1, 0x780000);
    for (i = 0; i < 10; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x184 + i * 16), b + i * 0x28000 + 0xD34800, 1, 0x28000);
    for (i = 0; i < 18; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x224 + i * 16), b + i * 0x18000 + 0xEC4800, 1, 0x18000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x344), b + 0x1074800, 1, 0x180000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x354), b + 0x11F4800, 1, 0x18000);
    for (i = 0; i < 12; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x364 + i * 16), b + (i << 18) + 0x2AC000, 1, 0x40000);
    // layout 2
    for (i = 0; i < 6; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x424 + i * 16), b + i * 0x72000, 2, 0x72000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x484), b + 0x5AC000, 2, 0x8800);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x494), b + 0x5B4800, 2, 0x580000);
    for (i = 0; i < 19; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x4A4 + i * 16), b + i * 0x28000 + 0xB34800, 2, 0x28000);
    for (i = 0; i < 35; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x5D4 + i * 16), b + i * 0x18000 + 0xE2C800, 2, 0x18000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x804), b + 0x1174800, 2, 0x180000);
    Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x814), b + 0x12F4800, 2, 0x18000);
    for (i = 0; i < 12; i++)
        Construct__21CB3ManagedMemoryBlockFPvii(func_00222300_inl1(m, 0x824 + i * 16), b + (i << 18) + 0x2AC000, 2, 0x40000);
}
