// Hand-written; the lifter refused it (stride loops, b declared before a).

struct UnkStruct_003D0B70 { unsigned char pad_0[0x4EC0 + 100 * 0x17C]; };
extern "C" void func_003D1CA0(void *a, void *b, int c);
extern "C" void func_003D1F00(void *a, void *b, int c);
extern "C" void func_003D17D0(void *a, void *b, int c);
// 0x003D0B70
extern "C" void func_003D0B70(UnkStruct_003D0B70 *self, UnkStruct_003D0B70 *p0)
{
    int i;
    for (i = 0; i < 36; i++) {
        char *b = (char *)p0 + i * 0x230;
        char *a = (char *)self + i * 0x230;
        func_003D1CA0(a, b, 0);
        func_003D1F00(a + 0x8C, b + 0x8C, 3);
        func_003D1CA0(a + 0x118, b + 0x118, 3);
        func_003D1CA0(a + 0x1A4, b + 0x1A4, 3);
    }
    for (i = 0; i < 100; i++) {
        char *b = (char *)p0 + i * 0x17C;
        char *a = (char *)self + i * 0x17C;
        func_003D1F00(a + 0x4EC0, b + 0x4EC0, 3);
        func_003D17D0(a + 0x4F4C, b + 0x4F4C, 3);
    }
}
