// Hand-written; the lifter refused it (a74: a71 clamp-asm helpers, unsigned char* buffer, three base-255 digit loops).

// [L] DNAT: no row in new_names.csv for 002350D0 (clamp via pminw/pmaxw/pextlw helpers, a71 pattern; base-255 digits written to p0)
static inline int func_002350D0_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}

static inline int func_002350D0_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}

static inline int func_002350D0_zx(int a)
{
    int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x002350D0
extern "C" void func_002350D0(unsigned char * p0, int p1, int p2, int p3)
{
    int lo = func_002350D0_zx(func_002350D0_min(p1, p2));
    int hi = func_002350D0_zx(func_002350D0_max(p1, p2));
    int n = 0;
    while (p3 > 0) {
        p0[n++] = p3 % 255;
        p3 = p3 / 255;
    }
    while (lo > 0) {
        p0[n++] = lo % 255;
        lo = lo / 255;
    }
    while (hi > 0) {
        p0[n++] = hi % 255;
        hi = hi / 255;
    }
    p0[n] = 0;
}
