// NONMATCHING: func_003BB610 -- retail 100 / ours 100 instructions, 41 in changed runs
// near32: 41 off, temp registers only (a 4-cycle a0/a3/t0/t1 permutation vs retail: -4 const t0, nextchunk t1, max_fast temp a0). Unsorted-bin link written as dlmalloc 2.7 (bck = unsorted_chunks(av); fwd = bck->fd; ...). sreg reached 36 only by reordering the backward unlink (semantically wrong, rejected)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a86: 100/100 instrs, 46 in changed runs; logic exact (dlmalloc 2.7 free; 'unsigned mm = p->size & 2' local hoists andi into the first delay slot like retail). Only register colouring differs: retail -4 const in t0 / nextchunk t1 / max_fast temp a0; ours -4 in t1 / nextchunk a0 / temp a3 (declaration order, local forms, const av tried)

// func_003BB610 -- [L] DNAT: fREe(void*) (research/proto/new_names.csv, high); dlmalloc 2.7 free [G]

struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
    struct malloc_chunk * fd;
    struct malloc_chunk * bk;
};

struct UnkStruct_003BB610_state {
    unsigned int max_fast;
    malloc_chunk * fastbins[11];
    malloc_chunk * top;
    malloc_chunk * last_remainder;
    malloc_chunk * bins[96 * 2];
};

extern UnkStruct_003BB610_state D_01EA50F0;
extern int dbg_bCheckMalloc;
extern "C" void func_003BB460(UnkStruct_003BB610_state *);
extern "C" void func_003BC240(void);

// 0x003BB610
extern "C" void func_003BB610(void * mem)
{
    UnkStruct_003BB610_state * av = &D_01EA50F0;
    malloc_chunk * p;
    malloc_chunk * nextchunk;
    malloc_chunk * bck;
    malloc_chunk * fwd;
    malloc_chunk * first_unsorted;
    malloc_chunk ** fb;
    unsigned int size;
    unsigned int nextsize;
    unsigned int prevsize;
    int nextinuse;

    if (mem != 0) {
        p = (malloc_chunk *)((char *)mem - 8);
        size = p->size & ~3;
        unsigned int mm = p->size & 2;
        if (size <= av->max_fast) {
            av->max_fast |= 3;
            fb = &av->fastbins[(size >> 3) - 2];
            p->fd = *fb;
            *fb = p;
        } else if (mm == 0) {
            av->max_fast |= 1;
            nextchunk = (malloc_chunk *)((char *)p + size);
            nextsize = nextchunk->size & ~3;
            if (!(p->size & 1)) {
                prevsize = p->prev_size;
                size += prevsize;
                p = (malloc_chunk *)((char *)p + -((long)prevsize));
                fwd = p->fd;
                bck = p->bk;
                fwd->bk = bck;
                bck->fd = fwd;
            }
            if (nextchunk != av->top) {
                nextinuse = ((malloc_chunk *)((char *)nextchunk + nextsize))->size & 1;
                nextchunk->size = nextsize;
                if (!nextinuse) {
                    size += nextsize;
                    fwd = nextchunk->fd;
                    bck = nextchunk->bk;
                    fwd->bk = bck;
                    bck->fd = fwd;
                }
                bck = (malloc_chunk *)((char *)&av->bins[2] - 8);
                fwd = bck->fd;
                p->bk = bck;
                p->fd = fwd;
                bck->fd = p;
                fwd->bk = p;
                p->size = size | 1;
                ((malloc_chunk *)((char *)p + size))->prev_size = size;
            } else {
                size += nextsize;
                p->size = size | 1;
                av->top = p;
            }
            if ((unsigned long)size >= 0x20000) {
                if (av->max_fast & 2) {
                    func_003BB460(av);
                }
            }
        }
    }
    if (dbg_bCheckMalloc) {
        func_003BC240();
    }
}
