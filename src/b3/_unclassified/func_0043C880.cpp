// Hand-written; the lifter refused it (switch, 1-indexed jtbl).

// Hand-written (a108).
struct UnkStruct_0043C880 { unsigned char pad_0[0x10]; };
// 0x0043C880
extern "C" int func_0043C880(UnkStruct_0043C880 * self, unsigned int n)
{
    switch (n) {
    case 1: return 5000;
    case 2: return 10000;
    case 3: return 20000;
    case 4: return 5000;
    case 5: return 2;
    case 6: return 4;
    case 7: return -1;
    case 0:
    default: return 0;
    }
}
