// Hand-written; the lifter refused it (dlmalloc mALLINFo (struct mallinfo via hidden ptr); bin addr via (char*)av + i*8 + 0x30, unsigned i, store order = retail's).

// func_003BB2F0 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: ~malloc_consolidate / "mALLINFo()" (research/proto/new_names.csv, high; GtMalloc.cpp); dlmalloc 2.7 mALLINFo [G]
// Returns struct mallinfo (10 ints) through a hidden pointer in a0.

struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
    struct malloc_chunk * fd;
    struct malloc_chunk * bk;
};

struct UnkStruct_003BB2F0_state {
    unsigned int max_fast;
    malloc_chunk * fastbins[11];
    malloc_chunk * top;
    malloc_chunk * last_remainder;
    malloc_chunk * bins[96 * 2];
    unsigned char pad_338[0x354 - 0x338];
    int field_354;
    unsigned char pad_358[0x368 - 0x358];
    int field_368;
    int field_36C;
    unsigned char pad_370[0x378 - 0x370];
    int field_378;
};

struct UnkStruct_003BB2F0_mallinfo {
    int arena;
    int ordblks;
    int smblks;
    int hblks;
    int hblkhd;
    int usmblks;
    int fsmblks;
    int uordblks;
    int fordblks;
    int keepcost;
};

extern UnkStruct_003BB2F0_state D_01EA50F0;
extern "C" void func_003BB460(UnkStruct_003BB2F0_state *);
extern "C" void func_003BC240(void);

// 0x003BB2F0
extern "C" UnkStruct_003BB2F0_mallinfo func_003BB2F0(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_003BB2F0_state * av = &D_01EA50F0;
    UnkStruct_003BB2F0_mallinfo mi;
    unsigned int fastavail, avail;
    int nblocks, nfastblocks;
    unsigned int i;
    malloc_chunk * p;
    malloc_chunk * b;

    if (av->top == 0)
        func_003BB460(av);
    func_003BC240();

    nblocks = 1;
    nfastblocks = 0;
    fastavail = 0;
    unsigned int top_size = av->top->size & ~3;
    avail = top_size;
    for (i = 0; i < 11; ++i) {
        for (p = av->fastbins[i]; p != 0; p = p->fd) {
            ++nfastblocks;
            fastavail += p->size & ~3;
        }
    }
    avail += fastavail;
    for (i = 1; i < 96; ++i) {
        b = (malloc_chunk *)((char *)av + i * 8 + 0x30);
        for (p = b->bk; p != b; p = p->bk) {
            ++nblocks;
            avail += p->size & ~3;
        }
    }
    mi.keepcost = top_size;
    mi.smblks = nfastblocks;
    mi.ordblks = nblocks;
    mi.fsmblks = fastavail;
    mi.fordblks = avail;
    mi.arena = av->field_36C;
    mi.uordblks = av->field_36C - avail;
    mi.hblks = av->field_354;
    mi.hblkhd = av->field_368;
    mi.usmblks = av->field_378;
    return mi;
}
