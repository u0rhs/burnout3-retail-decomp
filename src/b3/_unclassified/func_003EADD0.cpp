// Hand-written; the lifter refused it (twin of func_003EAD60 (D_004CD910)).

extern const unsigned long D_004CCF80[];
extern const float D_004CD910[];

static inline int func_003EADD0_inl1(unsigned long p0)
{
    int i = 0;
    goto test;
body:
    if (p0 == D_004CCF80[i]) return i;
    i++;
test:
    if (i < 67) goto body;
    return -1;
}

// 0x003EADD0
extern "C" float func_003EADD0(unsigned long n0)
{
    int i = func_003EADD0_inl1(n0);
    if (i != -1) {
        return D_004CD910[i * 2];
    }
    return 0.0f;
}
