// Hand-written; the lifter refused it (written by hand (lifter refused): two 30-wchar string locals filled by a sprintf+ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi static inline; Get() results taken into locals in order).

// func_0044A0F0 -- hand-written (lifter refused: sprintf argument counts). Shapes follow the matched sibling
// func_001A3AA0. Unnamed in every table, so a placeholder with C linkage; every type is [G] (instruction widths).

struct UnkStruct_0044A0F0_a2 {
    int field_0;
};

struct UnkStruct_0044A0F0_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_0044A0F0_1() { field_3C = 0; }
    UnkStruct_0044A0F0_1 *Get() { return field_3C != 0 ? (UnkStruct_0044A0F0_1 *)field_3C : this; }
};

struct UnkStruct_D_004CE0B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004CE0B0 D_004CE0B0;

extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, UnkStruct_0044A0F0_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_0044A0F0_1 *, UnkStruct_0044A0F0_1 *, int, int);

// [G] inlined helper (name unknown): sprintf the value, then UTF-8 to wide string
static inline void func_0044A0F0_inl1(UnkStruct_0044A0F0_1 *l, int v)
{
    char buf[0x20];
    sprintf(buf, &D_004CE0B0, v);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, l, 30);
}
// 0x0044A0F0
extern "C" void func_0044A0F0(void *n0_, void *p0_, const UnkStruct_0044A0F0_a2 * p1, const UnkStruct_0044A0F0_a2 * p2)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    UnkStruct_0044A0F0_1 l1;
    func_0044A0F0_inl1(&l1, p1->field_0);
    UnkStruct_0044A0F0_1 l2;
    func_0044A0F0_inl1(&l2, p2->field_0);
    UnkStruct_0044A0F0_1 *x1 = l1.Get();
    UnkStruct_0044A0F0_1 *x2 = l2.Get();
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x1, x2, 0, 0);
}
