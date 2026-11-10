// NONMATCHING: ConstructDMAData__21CB3CoronaDynamicArrayFiii -- retail 136 / ours 136 instructions, 55 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 56 -> 55
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: ConstructDMAData__21CB3CoronaDynamicArrayFiii -- retail 136 / ours 135 instructions, 74 in changed runs
// a124: 135/136 instrs, 74 changed; logic believed exact (2 Allocs+memsets, 0x48-entry chunk loop building DMA tag/VIF unpack dwords as 64-bit ors, SyncDCache, store dma ptr at this+i1*8+i2*4 and uncached buf|0x30000000 at field_10[i1].field_0[i2]). Left: retail hoists ~14 loop constants into specific regs (i=t1, p=t0, cnt=a3, constant order), keeps 'li v1,1; addu' for the 1+2*chunks (ours folds addiu), ours missing 1 instr. Decl-order sweeps (24+48) did not move it. Header: include/b3/classes/CB3CoronaDynamicArray.h has pad_0[0x10] where an int[2] row array (dma ptrs, stride 8 like field_10) lives at +0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/classes/CB3CoronaDynamicArray.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off

class CB3EffectsManager {
public:
    static void * Alloc(unsigned int, unsigned int);
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" void SyncDCache(void *, void *);

void CB3CoronaDynamicArray::ConstructDMAData(int p0, int p1, int n)
{
    int chunks = (n + 0x47) / 0x48;
    int size1 = n << 5;
    unsigned long * dma;
    char * buf = (char *)CB3EffectsManager::Alloc(size1, 0x10);
    memset(buf, 0, size1);
    int size2 = 1;
    size2 += chunks * 2;
    size2 <<= 4;
    dma = (unsigned long *)CB3EffectsManager::Alloc(size2, 0x80);
    memset(dma, 0, size2);
    dma[0] = 0x10000000;
    dma[1] = 0x0500000000000000UL;
    unsigned long * p = dma + 2;
    for (int i = 0; i < chunks; i++) {
        int cnt;
        if (n < 0x48) {
            cnt = n;
        } else {
            cnt = 0x48;
        }
        n -= cnt;
        unsigned long addr = (unsigned int)(buf + i * 0x900);
        p[1] = ((unsigned long)(unsigned int)((cnt << 17) | 0x6C008000) << 32) | 0x1000101;
        p[0] = (addr << 32) | (unsigned long)(long)(int)((cnt << 1) | 0x30000000);
        if (i == chunks - 1) {
            p[2] = 0x60000000;
            p += 3;
        } else {
            p[2] = 0x10000000;
            p += 3;
        }
        if (i == 0) {
            p[0] = ((unsigned long)0x15000000 << 32) | (unsigned long)(unsigned int)(cnt | 0x04000000);
            p += 1;
        } else {
            p[0] = ((unsigned long)0x17000000 << 32) | (unsigned long)(unsigned int)(cnt | 0x04000000);
            p += 1;
        }
    }
    SyncDCache(dma, (char *)dma + size2 - 1);
    *(void **)((char *)this + p0 * 8 + p1 * 4) = dma;
    field_10[p0].field_0[p1] = (unsigned int)buf | 0x30000000;
}

#pragma pop
