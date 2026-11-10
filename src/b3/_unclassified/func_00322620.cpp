// Hand-written; the lifter refused it (hand-written (lifter refused): two-string version of func_001A3AA0; sprintf+ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi in a static inline (char buffers allocated below both string locals); x/y temps).

struct UnkStruct_00322620_a2 {
    int field_0;
};

// [G] same shape as func_001A3AA0's / func_00310180's local: a 30-wchar buffer plus a string pointer.
struct UnkStruct_00322620_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_00322620_1() { field_3C = 0; }
};

struct UnkStruct_D_004B77F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004B77F0 D_004B77F0;

extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, UnkStruct_00322620_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_00322620_1 *, UnkStruct_00322620_1 *, int, int);

static inline void func_00322620_inl1(UnkStruct_00322620_1 & s, const UnkStruct_00322620_a2 * p)
{
    char buf[0x20];
    sprintf(buf, &D_004B77F0, p->field_0);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, &s, 30);
}

// 0x00322620
extern "C" void func_00322620(void *n0_, void *p0_, const UnkStruct_00322620_a2 * p1, const UnkStruct_00322620_a2 * p2)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    UnkStruct_00322620_1 a;
    func_00322620_inl1(a, p1);
    UnkStruct_00322620_1 b;
    func_00322620_inl1(b, p2);
    UnkStruct_00322620_1 * x = a.field_3C != 0 ? (UnkStruct_00322620_1 *)a.field_3C : &a;
    UnkStruct_00322620_1 * y = b.field_3C != 0 ? (UnkStruct_00322620_1 *)b.field_3C : &b;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, y, 0, 0);
}
