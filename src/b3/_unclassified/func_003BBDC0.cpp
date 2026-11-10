// Hand-written; the lifter refused it (a82: dlmalloc 2.7 sysmalloc: pool MORECORE inline (n>0 -> pool size), (old_size+4) fencepost parens, failure arm adds sbrked_mem, (unsigned)remainder|1).

// func_003BBDC0 -- [L] DNAT: sYSMALLOc(unsigned int,malloc_state*) (research/proto/new_names.csv, high); dlmalloc 2.7 sysmalloc [G]
#include "b3/classes/CGtMalloc.h"

struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
};
struct UnkStruct_003BBDC0_state {
    unsigned int max_fast;
    unsigned char pad_4[0x2C];
    malloc_chunk * top;
    unsigned char pad_34[0x314];
    unsigned int trim_threshold;
    unsigned int top_pad;
    unsigned char pad_350[0x10];
    unsigned int pagesize;
    unsigned int morecore_properties;
    unsigned int mmapped_mem;
    unsigned int sbrked_mem;
    unsigned int max_sbrked_mem;
    unsigned int max_mmapped_mem;
    unsigned int max_total_mem;
};

extern "C" void func_003BB460(UnkStruct_003BBDC0_state *);
extern "C" void * func_003BB7A0(unsigned int);
extern "C" void func_003BB610(void *);
extern "C" void func_003BC240(void);
extern "C" int printf(const char *, ...);
extern char D_004CA280[];

static inline char * func_003BBDC0_inl1(int n)
{
    if (n > 0) {
        n = CGtMalloc::mnPoolSize;
    }
    int off = CGtMalloc::mnPoolOffset;
    int newoff = off + n;
    if (CGtMalloc::mnPoolSize < newoff) {
        return (char *)-1;
    }
    CGtMalloc::mnPoolOffset = newoff;
    return (char *)CGtMalloc::mpBuffer + off;
}

static inline char * func_003BBDC0_inl0()
{
    if (CGtMalloc::mnPoolSize < CGtMalloc::mnPoolOffset) {
        return (char *)-1;
    }
    return (char *)CGtMalloc::mpBuffer + CGtMalloc::mnPoolOffset;
}

// 0x003BBDC0
extern "C" void * func_003BBDC0(unsigned int nb, UnkStruct_003BBDC0_state * av)
{
    malloc_chunk * old_top;
    unsigned int old_size;
    char * old_end;
    long size;
    char * brk;
    long correction;
    char * snd_brk;
    unsigned int front_misalign;
    unsigned int end_misalign;
    char * aligned_brk;
    malloc_chunk * p;
    malloc_chunk * remainder;
    unsigned long remainder_size;
    unsigned int sum;
    unsigned int pagemask = av->pagesize - 1;

    if ((av->max_fast & 2) != 0) {
        func_003BB460(av);
        return func_003BB7A0(nb - 15);
    }
    old_top = av->top;
    old_size = old_top->size & ~3;
    old_end = (char *)old_top + old_size;
    brk = snd_brk = (char *)-1;
    size = nb + av->top_pad + 16;
    if ((av->morecore_properties & 1) != 0) {
        size -= old_size;
    }
    size = (size + pagemask) & ~pagemask;
    if (size > 0) {
        brk = func_003BBDC0_inl1(size);
    }
    if (brk != (char *)-1) {
        av->sbrked_mem += size;
        if (brk == old_end) {
            old_top->size = (size + old_size) | 1;
        } else {
            front_misalign = 0;
            end_misalign = 0;
            correction = 0;
            aligned_brk = brk;
            if ((av->morecore_properties & 1) != 0 && old_size != 0 && brk < old_end) {
                av->morecore_properties &= ~1;
            }
            if ((av->morecore_properties & 1) != 0) {
                if (old_size != 0) {
                    av->sbrked_mem += brk - old_end;
                }
                front_misalign = (unsigned int)(brk + 8) & 15;
                if (front_misalign > 0) {
                    correction = 16 - front_misalign;
                    aligned_brk += correction;
                }
                correction += old_size;
                end_misalign = (unsigned int)(brk + size + correction);
                correction += ((end_misalign + pagemask) & ~pagemask) - end_misalign;
                snd_brk = func_003BBDC0_inl1(correction);
                if (snd_brk == (char *)-1) {
                    correction = 0;
                    snd_brk = func_003BBDC0_inl0();
                    if (snd_brk != (char *)-1) {
                        av->sbrked_mem += snd_brk - brk - size;
                    }
                } else if (snd_brk < brk) {
                    snd_brk = brk + size;
                    correction = 0;
                    av->morecore_properties &= ~1;
                }
            } else {
                snd_brk = func_003BBDC0_inl0();
                av->sbrked_mem += snd_brk - brk - size;
            }
            if (snd_brk != (char *)-1) {
                av->top = (malloc_chunk *)aligned_brk;
                av->top->size = (snd_brk - aligned_brk + correction) | 1;
                av->sbrked_mem += correction;
                if (old_size != 0) {
                    old_size = (old_size - 12) & ~15;
                    old_top->size = old_size | 1;
                    ((malloc_chunk *)((char *)old_top + old_size))->size = 5;
                    ((malloc_chunk *)((char *)old_top + (old_size + 4)))->size = 5;
                    if (old_size >= 16) {
                        unsigned int saved = av->trim_threshold;
                        av->trim_threshold = (unsigned int)-1;
                        func_003BB610((char *)old_top + 8);
                        av->trim_threshold = saved;
                    }
                }
            }
        }
        sum = av->sbrked_mem;
        if (sum > av->max_sbrked_mem) {
            av->max_sbrked_mem = sum;
        }
        sum += av->mmapped_mem;
        if (sum > av->max_total_mem) {
            av->max_total_mem = sum;
        }
        func_003BC240();
        p = av->top;
        size = p->size & ~3;
        if ((unsigned int)size >= nb + 16) {
            remainder_size = size - nb;
            remainder = (malloc_chunk *)((char *)p + nb);
            av->top = remainder;
            p->size = nb | 1;
            remainder->size = (unsigned int)remainder_size | 1;
            return (char *)p + 8;
        }
    }
    printf(D_004CA280);
    return 0;
}
