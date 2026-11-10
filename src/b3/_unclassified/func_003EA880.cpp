// Hand-written; the lifter refused it (static inline find (goto loop) then table read).

extern const unsigned long kaB3HardCodedTrackList[];
extern float D_004CCDD0[];
static inline int func_003EA880_inl1(unsigned long p0)
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
// 0x003EA880
extern "C" float func_003EA880(unsigned long n0)
{
    int i = func_003EA880_inl1(n0);
    return D_004CCDD0[i];
}
