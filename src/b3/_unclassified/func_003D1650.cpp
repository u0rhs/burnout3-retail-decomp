// Hand-written; the lifter refused it (flag-tested calls, inline row search).

struct UnkStruct_D_00522660_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660_x D_00522660;
extern "C" void func_003D23A0(void *, int, int, float);
extern "C" void func_003D2160(void *, int, int, int);
static inline bool func_003D1650_inl1(char *row, int p0)
{
    int k = 0;
    goto t;
b:
    if (p0 == row[k * 0x1C + 0x14]) return true;
    k++;
t:
    if (k < 5) goto b;
    return false;
}
// 0x003D1650
extern "C" int func_003D1650(char *self, int p0, unsigned long p1)
{
    char *base = (char *)&D_00522660 + p0 * 0x27D0 + 0x12AD50;
    if (p1 & 1) func_003D23A0(self, p0, 0, *(float *)(base + 0x16FC));
    if (p1 & 2) func_003D2160(self + 0x8C, *(int *)(base + 0x1728), p0, 3);
    if (p1 & 4) func_003D23A0(self + 0x118, p0, 3, *(float *)(base + 0x1724));
    if (p1 & 8) func_003D23A0(self + 0x1A4, p0, 3, *(float *)(base + 0x171C));
    int j = 0;
    goto t;
b:
    if (func_003D1650_inl1(self + j * 0x8C, p0)) return 1;
    j++;
t:
    if (j < 4) goto b;
    return 0;
}
