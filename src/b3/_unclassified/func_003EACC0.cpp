// Hand-written; the lifter refused it (int p1; p0>-1 chain).

extern int D_004CDD40[];
extern int D_004CDE80[];
// 0x003EACC0
extern "C" int func_003EACC0(int p0, int p1)
{
    if (p0 > -1) {
        if (p1 != 0) return D_004CDD40[p0];
        return D_004CDE80[p0];
    }
    return p1 != 0 ? 0x4FF : 0x4FE;
}
