// Hand-written; the lifter refused it (a115: split string at last space; p declared before mid fixes a1/a2).

struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_01E90438;
extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003D0960(unsigned short *, int, unsigned short *, int);

// 0x0039C1C0
extern "C" void func_0039C1C0(void * self, unsigned short * str, unsigned short ** out1, unsigned short ** out2)
{
    int n = Length__10CGtUnicodeFPCUs(str) * 2;
    unsigned short * buf = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, n);
    func_003D0960(buf, n, str, 0);
    unsigned short * p;
    unsigned short * mid = buf + n / 2;
    p = mid;
    while (*p != 0x20 && p != buf) {
        p--;
    }
    if (p == buf) {
        p = mid;
        while (*p != 0x20 && *p != 0) {
            p++;
        }
        if (*p != 0) {
            p = mid;
        }
    }
    *p = 0;
    *out1 = buf;
    *out2 = p + 1;
}
