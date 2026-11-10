// Hand-written; the lifter refused it (p0==0 ? 12 : 0 -> movn).

// 0x00462130
extern "C" int func_00462130(int p0)
{
    return p0 == 0 ? 12 : 0;
}
