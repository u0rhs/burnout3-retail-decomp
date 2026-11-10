// Hand-written; the lifter refused it (FindTrack as static inline; const tables).

extern const unsigned long kaB3HardCodedTrackList[];
extern const unsigned char D_004CC730[];
extern const unsigned char D_004CC731[];
extern const unsigned char D_004CC732[];

static inline int func_003EA9D0_inl1(unsigned long p0)
{
    int i = 0;
    goto test;
body:
    if (p0 == kaB3HardCodedTrackList[i]) return i;
    i++;
test:
    if (i < 36) goto body;
    return -1;
}

// 0x003EA9D0
extern "C" void GetPayloadsForTrack__21CB3HardCodedTrackListFUlPUcPUcPUc(unsigned long n0, unsigned char *p1, unsigned char *p2, unsigned char *p3)
{
    int k = func_003EA9D0_inl1(n0) * 3;
    unsigned char a = D_004CC730[k];
    unsigned char b = D_004CC731[k];
    unsigned char c = D_004CC732[k];
    *p1 = a;
    *p2 = b;
    *p3 = c;
}
