// Hand-written; the lifter refused it (static inline find then table read).

extern const unsigned long kaB3HardCodedTrackList[];
extern float D_004CCD40[];
static inline int func_003EA8E0_inl1(unsigned long p0)
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
// 0x003EA8E0
extern "C" float func_003EA8E0(unsigned long n0)
{
    int i = func_003EA8E0_inl1(n0);
    return D_004CCD40[i];
}
