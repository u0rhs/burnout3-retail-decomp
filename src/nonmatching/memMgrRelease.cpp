// NONMATCHING: ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki -- retail 63 / ours 62 instructions, 51 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2223C0). Block 4: the large block of layout 0 (+0x934), 2 (+0x494)
// or any other (+0x174).
// Name: the asm symbol, which came from a config/symbol_addrs.txt row marked "names are ours" (the earlier research repo, upstream)
// -- not evidence. [L] research/retail_names.csv (high): CB3MemoryManagerPS2::ReleaseBlock(EB3MemoryBlock,int).
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

// 0x002223C0
extern "C" int ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(UnkStruct_mm * m, int block, int i)
{
    switch (block) {
    case 4:
    {
        int k = m->field_984;               // [C] retail passes the loaded value on every path
        if (k == 0) return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x934), k);
        if (k == 2) return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x494), k);
        return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x174), k);
    }
    case 0x1A: return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x9BC), m->field_984);
    case 0x19: return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x98C), m->field_984);
    case 0x18: return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x9AC), m->field_984);
    case 0x17: return ReleaseMemoryBlock__21CB3ManagedMemoryBlockFi(func_00222300_inl1(m, 0x99C), m->field_984);
    }
    return ReleaseBlock__16CB3MemoryManagerF14EB3MemoryBlocki(m, block, i);
}
