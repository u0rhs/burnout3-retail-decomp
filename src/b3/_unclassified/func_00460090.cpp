// Hand-written; the lifter refused it (if(D==5) return idiom (N53)).

struct UnkStruct_a167_g { int value; unsigned char pad[0x100]; };
extern UnkStruct_a167_g D_01E90424;
// 0x00460090
extern "C" void func_00460090()
{
    if (D_01E90424.value == 5)
        return;
}
