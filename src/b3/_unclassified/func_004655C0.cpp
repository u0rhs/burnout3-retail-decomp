// Hand-written; the lifter refused it (near26: bounded-copy inline as do/while(--n) with (s, n, d) parameter order; void* parameter keeps the copy register; shared status via int r coalesced into st).

struct UnkStruct_004655C0_g {
    unsigned char pad_0[0xAC];
    char field_AC[0x11];
    char field_BD[0x17];
    int field_D4;
};
struct UnkStruct_D_004E2FC4_a { UnkStruct_004655C0_g * field_0; };
extern UnkStruct_D_004E2FC4_a D_004E2FC4;
extern "C" int func_00465EB0(int);
// [G] bounded copy: stop on terminator or after n-1 chars, then terminate
static inline void func_004655C0_inl1(const char * s, int n, char * d)
{
    if (s != 0 && d != 0 && s != d) {
        do {
            if (--n == 0) {
                *d = 0;
                break;
            }
        } while ((*d++ = *s++) != 0);
    }
}
// 0x004655C0
extern "C" int func_004655C0(const void * a0)
{
    int st = 0;
    if (a0 == 0) {
        st = 7;
    } else {
        func_004655C0_inl1((const char *)a0, 0x11, D_004E2FC4.field_0->field_AC);
        func_004655C0_inl1((const char *)a0 + 0x11, 0x11, D_004E2FC4.field_0->field_BD);
    }
    if (st == 0) {
        int r = 0;
        if (D_004E2FC4.field_0->field_D4 == 4) func_00465EB0(1); else r = 0x16;
        st = r;
    }
    return st;
}
