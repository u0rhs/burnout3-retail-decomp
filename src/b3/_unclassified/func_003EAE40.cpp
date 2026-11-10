// Hand-written; the lifter refused it (int p1; p0>-1 chain).

extern int D_004CD2B0[];
extern int D_004CD3C0[];
// 0x003EAE40
extern "C" int func_003EAE40(int p0, int p1)
{
    if (p0 > -1) {
        if (p1 != 0) return D_004CD2B0[p0];
        return D_004CD3C0[p0];
    }
    return p1 != 0 ? 0x4FF : 0x4FE;
}
