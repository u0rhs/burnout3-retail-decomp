// NONMATCHING: func_003BB460 -- retail 108 / ours 108 instructions, 26 in changed runs
// near25: dlmalloc-faithful malloc_consolidate + malloc_init_state static inline, dlmalloc declaration order (29 same); sreg 2 rounds 26: still a 5-value temp rotation (retail raw-size/nextchunk a1, -2 a2, maxfb a3, unsorted t0, size t1; ours -2 takes a1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_003BB460 -- [L] DNAT: malloc_consolidate(malloc_state*) (research/proto/new_names.csv, high); dlmalloc 2.7 malloc_consolidate / malloc_init_state [G]

struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
    struct malloc_chunk * fd;
    struct malloc_chunk * bk;
};

struct UnkStruct_003BB460_state {
    unsigned int max_fast;
    malloc_chunk * fastbins[11];
    malloc_chunk * top;
    malloc_chunk * last_remainder;
    malloc_chunk * bins[96 * 2];
    unsigned int binmap[4];
    unsigned int trim_threshold;
    unsigned int top_pad;
    unsigned int mmap_threshold;
    unsigned int field_354;
    unsigned int n_mmaps_max;
    unsigned int field_35C;
    unsigned int pagesize;
    unsigned int morecore_properties;
};

extern "C" void func_003BC240(void);


static inline void func_003BB460_inl1(UnkStruct_003BB460_state * av)
{
    int i;
    malloc_chunk * bin;
    for (i = 1; i < 96; ++i) {
        bin = (malloc_chunk *)((char *)&av->bins[i << 1] - 8);
        bin->fd = bin->bk = bin;
    }
    av->top_pad = 0;
    av->n_mmaps_max = 0;
    av->mmap_threshold = 0x40000;
    av->trim_threshold = 0x40000;
    av->morecore_properties |= 1;
    av->max_fast = 0x50 | (av->max_fast & 3);
    av->top = (malloc_chunk *)((char *)&av->bins[2] - 8);
    av->pagesize = 0x1000;
}

// 0x003BB460
extern "C" void func_003BB460(UnkStruct_003BB460_state * av)
{
    malloc_chunk ** fb;
    malloc_chunk ** maxfb;
    malloc_chunk * p;
    malloc_chunk * nextp;
    malloc_chunk * unsorted_bin;
    malloc_chunk * first_unsorted;
    unsigned int size;
    unsigned int nextsize;
    unsigned int prevsize;
    int nextinuse;
    malloc_chunk * nextchunk;
    malloc_chunk * bck;
    malloc_chunk * fwd;
    if (av->max_fast != 0) {
        av->max_fast &= ~2;
        unsorted_bin = (malloc_chunk *)((char *)&av->bins[2] - 8);
        maxfb = &av->fastbins[((av->max_fast >> 3) - 2)];
        fb = &av->fastbins[0];
        do {
            if ((p = *fb) != 0) {
                *fb = 0;
                do {
                    nextp = p->fd;
                    size = p->size & ~1;
                    nextchunk = (malloc_chunk *)((char *)p + size);
                    nextsize = nextchunk->size & ~3;
                    if (!(p->size & 1)) {
                        prevsize = p->prev_size;
                        size += prevsize;
                        p = (malloc_chunk *)((char *)p + -((long)prevsize));
                        { fwd = p->fd; bck = p->bk; fwd->bk = bck; bck->fd = fwd; }
                    }
                    if (nextchunk != av->top) {
                        nextinuse = ((malloc_chunk *)((char *)nextchunk + nextsize))->size & 1;
                        nextchunk->size = nextsize;
                        if (!nextinuse) {
                            size += nextsize;
                            { fwd = nextchunk->fd; bck = nextchunk->bk; fwd->bk = bck; bck->fd = fwd; }
                        }
                        first_unsorted = unsorted_bin->fd;
                        unsorted_bin->fd = p;
                        first_unsorted->bk = p;
                        p->size = size | 1;
                        p->bk = unsorted_bin;
                        p->fd = first_unsorted;
                        ((malloc_chunk *)((char *)p + size))->prev_size = size;
                    } else {
                        size += nextsize;
                        p->size = size | 1;
                        av->top = p;
                    }
                } while ((p = nextp) != 0);
            }
        } while (fb++ != maxfb);
    } else {
        func_003BB460_inl1(av);
        func_003BC240();
    }
}

