// Hand-written; the lifter refused it (hand-written (lifter refused): neighbour func_0044A0F0's shape with three values (wide-string struct ctor + Get(), inline sprintf/ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi helper)).

// func_00449FC0 -- hand-written (the lifter refused: sprintf called with different argument counts).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Same shape as its matched neighbour func_0044A0F0 (two values), here with three.
// Every type is [G] (instruction widths).

struct UnkStruct_00449FC0_a2 {
    int field_0;
};

// [G] same shape as func_0044A0F0's local: a 30-wchar buffer plus a string pointer.
struct UnkStruct_00449FC0_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_00449FC0_1() { field_3C = 0; }
    UnkStruct_00449FC0_1 *Get() { return field_3C != 0 ? (UnkStruct_00449FC0_1 *)field_3C : this; }
};

struct UnkStruct_D_004CE0B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004CE0B0 D_004CE0B0;

extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, UnkStruct_00449FC0_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_00449FC0_1 *, UnkStruct_00449FC0_1 *, UnkStruct_00449FC0_1 *, int);

// [G] inlined helper (name unknown): sprintf the value, then UTF-8 to wide string
static inline void func_00449FC0_inl1(UnkStruct_00449FC0_1 *l, int v)
{
    char buf[0x20];
    sprintf(buf, &D_004CE0B0, v);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, l, 30);
}

// 0x00449FC0
extern "C" void func_00449FC0(int n0, int p0, const UnkStruct_00449FC0_a2 * p1, const UnkStruct_00449FC0_a2 * p2, const UnkStruct_00449FC0_a2 * p3)
{
    UnkStruct_00449FC0_1 l1;
    func_00449FC0_inl1(&l1, p1->field_0);
    UnkStruct_00449FC0_1 l2;
    func_00449FC0_inl1(&l2, p2->field_0);
    UnkStruct_00449FC0_1 l3;
    func_00449FC0_inl1(&l3, p3->field_0);
    UnkStruct_00449FC0_1 *x1 = l1.Get();
    UnkStruct_00449FC0_1 *x2 = l2.Get();
    UnkStruct_00449FC0_1 *x3 = l3.Get();
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x1, x2, x3, 0);
}
