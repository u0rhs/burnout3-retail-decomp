// NONMATCHING: func_003BB7A0 -- retail 392 / ours 398 instructions, 293 in changed runs
// fix3 (2026-11-01): best-fit exhaust test back to remainder_size < 16 (the mwperm '<= 16' rewrite changed behaviour; retail 0x3BBCAC sltiu 0x10) | Before: a81 (rev 2): dlmalloc 2.7.0 mALLOc reconstructed; 398 vs 392 instrs, 293 changed with '#pragma opt_loop_invariants off' (401/341 without). Remaining: block layout (retail places the large-bin path inline before the unsorted-loop body, constants rematerialised per use) and scan-loop register choices. Tried macro vs inline largebin_index, if/else inversion, no outer for(;;), for(;;)+break, goto use_top placement, opt_loop_invariants off | classic-op fallback | guard: n/a (classic ops) | mwperm: 315 -> 277 ('if (remainder_size < 16) {' -> 'if (remainder_size <= 16) {')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_003BB7A0 -- mALLOc(unsigned int): the dlmalloc 2.7.0 allocator (public domain), as retail's GtMalloc.cpp links it
// [L] DNAT: mALLOc(unsigned int) (research/proto/new_names.csv, high); [C] name: research/E_B3DEBUG_symbols.csv 003dc1a0 mALLOc(unsigned int)

struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
    struct malloc_chunk * fd;
    struct malloc_chunk * bk;
};
typedef struct malloc_chunk * mchunkptr;
typedef struct malloc_chunk * mbinptr;
typedef struct malloc_chunk * mfastbinptr;

struct malloc_state {
    unsigned int max_fast;
    mfastbinptr fastbins[11];
    mchunkptr top;
    mchunkptr last_remainder;
    mchunkptr bins[96 * 2];
    unsigned int binmap[3];
};
typedef struct malloc_state * mstate;

struct UnkStruct_P { unsigned char pad_0[0x10]; };
extern struct malloc_state D_01EA50F0;
extern UnkStruct_P D_004CA280;
extern int dbg_bCheckMalloc;

extern "C" int printf(const char *, ...);
extern "C" void func_003BC240();
extern "C" void func_003BB460(mstate);
extern "C" void * func_003BBDC0(unsigned int, mstate);

#define bin_at(m, i) ((mbinptr)((char *)&((m)->bins[(i) << 1]) - 8))
#define next_bin(b) ((mbinptr)((char *)(b) + 8))
#define last(b) ((b)->bk)
#define first(b) ((b)->fd)
#define unsorted_chunks(M) (bin_at(M, 1))
#define chunksize(p) ((p)->size & ~(unsigned int)3)
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define chunk2mem(p) ((void *)((char *)(p) + 8))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= 1)
#define in_smallbin_range(sz) ((unsigned int)(sz) < 256)
#define smallbin_index(sz) ((unsigned)(sz) >> 3)
#define fastbin_index(sz) ((((unsigned int)(sz)) >> 3) - 2)
#define idx2block(i) ((i) >> 5)
#define idx2bit(i) ((1U << ((i) & 31)))
#define mark_bin(m, i) ((m)->binmap[idx2block(i)] |= idx2bit(i))

static inline int largebin_index(unsigned int sz)
{
    unsigned int x = sz >> 8;
    if (x >= 0x10000) {
        return 95;
    }
    unsigned int n = ((x - 0x100) >> 16) & 8;
    unsigned int m = n;
    x <<= n;
    n = ((x - 0x1000) >> 16) & 4;
    m += n;
    x <<= n;
    n = ((x - 0x4000) >> 16) & 2;
    m += n;
    x <<= n;
    m = 13 - m + ((x >> 14) & ~(x >> 15));
    return (m << 2) + 32 + ((sz >> (m + 6)) & 3);
}

#pragma opt_loop_invariants off
// 0x003BB7A0
extern "C" void * func_003BB7A0(unsigned int bytes)
{
    mstate av = &D_01EA50F0;
    unsigned int nb;
    int idx;
    mchunkptr victim;
    mchunkptr bck;
    mchunkptr fwd;
    mchunkptr remainder;
    unsigned int remainder_size;
    unsigned int size;
    int victim_index;
    mbinptr bin;
    unsigned int block;
    unsigned int map;
    unsigned int bit;

    if (dbg_bCheckMalloc) {
        func_003BC240();
    }
    if ((unsigned int)bytes >= (unsigned int)(unsigned int)(-2 * 16)) {
        printf((const char *)&D_004CA280);
        return 0;
    }
    nb = (bytes + 4 + 15 < 16) ? 16 : (bytes + 4 + 15) & ~15;

    if (!(av->max_fast & 1)) {
        if (av->max_fast == 0) {
            func_003BB460(av);
        }
        goto use_top;
    }

    if ((unsigned int)nb <= (unsigned int)av->max_fast) {
        mfastbinptr * fb = &av->fastbins[fastbin_index(nb)];
        if ((victim = *fb) != 0) {
            *fb = victim->fd;
            return chunk2mem(victim);
        }
    }

    if (in_smallbin_range(nb)) {
        idx = smallbin_index(nb);
        bin = bin_at(av, idx);
        if ((victim = last(bin)) != bin) {
            bck = victim->bk;
            set_inuse_bit_at_offset(victim, nb);
            bin->bk = bck;
            bck->fd = bin;
            return chunk2mem(victim);
        }
    } else {
        idx = largebin_index(nb);
        if (av->max_fast & 2) {
            func_003BB460(av);
        }
    }

    for (;;) {
        while ((victim = unsorted_chunks(av)->bk) != unsorted_chunks(av)) {
            bck = victim->bk;
            size = chunksize(victim);

            if (in_smallbin_range(nb) && bck == unsorted_chunks(av) && victim == av->last_remainder && (unsigned int)size > (unsigned int)(nb + 16)) {
                remainder_size = size - nb;
                remainder = chunk_at_offset(victim, nb);
                unsorted_chunks(av)->bk = unsorted_chunks(av)->fd = remainder;
                av->last_remainder = remainder;
                remainder->bk = remainder->fd = unsorted_chunks(av);
                set_head(victim, nb | 1);
                set_head(remainder, remainder_size | 1);
                set_foot(remainder, remainder_size);
                return chunk2mem(victim);
            }

            unsorted_chunks(av)->bk = bck;
            bck->fd = unsorted_chunks(av);

            if (size == nb) {
                set_inuse_bit_at_offset(victim, size);
                return chunk2mem(victim);
            }

            if (in_smallbin_range(size)) {
                victim_index = smallbin_index(size);
                bck = bin_at(av, victim_index);
                fwd = bck->fd;
            } else {
                victim_index = largebin_index(size);
                bck = bin_at(av, victim_index);
                fwd = bck->fd;
                if (fwd != bck) {
                    if ((unsigned int)size < (unsigned int)bck->bk->size) {
                        fwd = bck;
                        bck = bck->bk;
                    } else if ((unsigned int)size >= (unsigned int)256) {
                        size |= 1;
                        while ((unsigned int)size < (unsigned int)fwd->size) {
                            fwd = fwd->fd;
                        }
                        bck = fwd->bk;
                    }
                }
            }
            mark_bin(av, victim_index);
            victim->bk = bck;
            victim->fd = fwd;
            fwd->bk = victim;
            bck->fd = victim;
        }

        if (!in_smallbin_range(nb)) {
            bin = bin_at(av, idx);
            if ((victim = last(bin)) != bin && (unsigned int)first(bin)->size >= (unsigned int)nb) {
                while (((unsigned int)(size = chunksize(victim)) < (unsigned int)nb)) {
                    victim = victim->bk;
                }
                remainder_size = size - nb;
                fwd = victim->fd;
                bck = victim->bk;
                bck->fd = fwd;
                fwd->bk = bck;
                if (remainder_size < 16) {   // fix3 [C] retail 0x3BBCAC sltiu 0x10 (the mwperm "<= 16" changed the exhaust bound)
                    set_inuse_bit_at_offset(victim, size);
                    return chunk2mem(victim);
                } else {
                    remainder = chunk_at_offset(victim, nb);
                    unsorted_chunks(av)->bk = unsorted_chunks(av)->fd = remainder;
                    remainder->bk = remainder->fd = unsorted_chunks(av);
                    set_head(victim, nb | 1);
                    set_head(remainder, remainder_size | 1);
                    set_foot(remainder, remainder_size);
                    return chunk2mem(victim);
                }
            }
        }

        ++idx;
        bin = bin_at(av, idx);
        block = idx2block(idx);
        map = av->binmap[block];
        bit = idx2bit(idx);

        for (;;) {
            if (bit > map || bit == 0) {
                do {
                    if (++block >= 3) {
                        goto use_top;
                    }
                } while ((map = av->binmap[block]) == 0);
                bin = bin_at(av, (block << 5));
                bit = 1;
            }
            while ((bit & map) == 0) {
                bin = next_bin(bin);
                bit <<= 1;
            }
            victim = last(bin);
            if (victim == bin) {
                av->binmap[block] = map &= ~bit;
                bin = next_bin(bin);
                bit <<= 1;
            } else {
                size = chunksize(victim);
                remainder_size = size - nb;
                bck = victim->bk;
                bin->bk = bck;
                bck->fd = bin;
                if (remainder_size < 16) {
                    set_inuse_bit_at_offset(victim, size);
                    return chunk2mem(victim);
                } else {
                    remainder = chunk_at_offset(victim, nb);
                    unsorted_chunks(av)->bk = unsorted_chunks(av)->fd = remainder;
                    remainder->bk = remainder->fd = unsorted_chunks(av);
                    if (in_smallbin_range(nb)) {
                        av->last_remainder = remainder;
                    }
                    set_head(victim, nb | 1);
                    set_head(remainder, remainder_size | 1);
                    set_foot(remainder, remainder_size);
                    return chunk2mem(victim);
                }
            }
        }

    use_top:
        victim = av->top;
        size = chunksize(victim);
        if ((unsigned int)size >= (unsigned int)(nb + 16)) {
            remainder_size = size - nb;
            remainder = chunk_at_offset(victim, nb);
            av->top = remainder;
            set_head(victim, nb | 1);
            set_head(remainder, remainder_size | 1);
            return chunk2mem(victim);
        }
        return func_003BBDC0(nb, av);
    }
}
