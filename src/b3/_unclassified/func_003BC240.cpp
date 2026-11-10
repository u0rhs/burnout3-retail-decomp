// Hand-written; the lifter refused it (a88: do_check_malloc_state, fastbin p tested before the loop).

// Hand-written (a88: dlmalloc 2.7.0 do_check_malloc_state; check_* macros are empty, `total` is kept by b119).
// [L] DNAT: do_check_malloc_state() (research/proto/new_names.csv, high; GtMalloc.cpp)

struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
    struct malloc_chunk * fd;
    struct malloc_chunk * bk;
};

struct UnkStruct_003BC240_state {
    unsigned int max_fast;
    malloc_chunk * fastbins[11];
    malloc_chunk * top;
    malloc_chunk * last_remainder;
    malloc_chunk * bins[96 * 2];
};

extern UnkStruct_003BC240_state D_01EA50F0;

// 0x003BC240
extern "C" void func_003BC240(void)
{
    UnkStruct_003BC240_state * av = &D_01EA50F0;
    unsigned int i;
    malloc_chunk * p;
    malloc_chunk * q;
    malloc_chunk * b;
    unsigned int total = 0;

    if (av->top == 0) return;
    if (av->top == (malloc_chunk *)((char *)av + 0x38)) return;

    for (i = 0; i < 11; ++i) {
        p = av->fastbins[i];
        if (p != 0) {
            for (; p != 0; p = p->fd) {
                total += p->size & ~3;
            }
        }
    }
    for (i = 1; i < 96; ++i) {
        b = (malloc_chunk *)((char *)av + i * 8 + 0x30);
        for (p = b->bk; p != b; p = p->bk) {
            total += p->size & ~3;
            for (q = (malloc_chunk *)((char *)p + (p->size & ~1));
                 q != av->top
                 && (((malloc_chunk *)((char *)q + (q->size & ~1)))->size & 1)
                 && (q->size & ~3) >= 16;
                 q = (malloc_chunk *)((char *)q + (q->size & ~1)))
                ;
        }
    }
}
