// Hand-written; the lifter refused it (if(D==5) return idiom (N53), extern C).

struct UnkStruct_a167_g { int value; unsigned char pad[0x100]; };
extern UnkStruct_a167_g D_01E90424;
// 0x003D27D0
extern "C" void func_003D27D0()
{
    if (D_01E90424.value == 5)
        return;
}
