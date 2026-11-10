// Hand-written; the lifter refused it (noreorder region [G] around pminw/pextlw helpers + first 3 SPR-DMA writes).

typedef volatile unsigned int vu32;
#define R32(a) (*(vu32 *)(a))
static inline int func_002F34C0_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_002F34C0_ext(int a) { int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
// 0x002F34C0
extern "C" void func_002F34C0(void *dst_, void *src_, int n)
{
    unsigned int dst = (unsigned int)dst_;
    unsigned int src = (unsigned int)src_;
    int done;
    for (done = 0; done < n; done += 0x2000) {
        int len;
        // [G] N188-style region around the real pminw/pextlw helper asm and the first three SPR-DMA
        // register writes: retail keeps pextlw right after pminw and the qwc shift after the writes.
        asm(".set noreorder");
        len = func_002F34C0_ext(func_002F34C0_min(n - done, 0x2000));
        R32(0x1000E010) = 0x200;
        R32(0x1000D480) = 0x70002000;
        R32(0x1000D410) = src;
        asm(".set reorder");
        unsigned int qwc = len >> 4;
        R32(0x1000D420) = qwc;
        R32(0x1000D400) = 0x100;
        asm("sync\nsync.p");
        if ((R32(0x1000D400) & 0x100) != 0) {
            R32(0x1000E020) = 0x200;
            asm("sync\nsync.p\nn32cw1:\nnop\nnop\nnop\nnop\nnop\nbc0f n32cw1");
            while ((R32(0x1000D400) & 0x100) != 0) { }
        }
        R32(0x1000E010) = 0x100;
        R32(0x1000D080) = 0x70002000;
        R32(0x1000D010) = dst;
        R32(0x1000D020) = qwc;
        R32(0x1000D000) = 0x100;
        asm("sync\nsync.p");
        if ((R32(0x1000D000) & 0x100) != 0) {
            R32(0x1000E020) = 0x100;
            asm("sync\nsync.p\nn32cw2:\nnop\nnop\nnop\nnop\nnop\nbc0f n32cw2");
        }
        src += 0x2000;
        dst += 0x2000;

    }
}
