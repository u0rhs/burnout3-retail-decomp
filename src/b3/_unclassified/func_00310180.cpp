// func_00310180 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (buffer+pointer local with ctor (ptr = 0), const pointer param (lw before the store), as func_003192A0).

struct UnkStruct_00310180_a2 {
    int field_0;
};

// [G] same shape as func_003192A0's local: a 30-wchar buffer plus a string pointer.
struct UnkStruct_00310180_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_00310180_1() { field_3C = 0; }
};

extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, UnkStruct_00310180_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_00310180_1 *, int, int, int);

// 0x00310180
extern "C" void func_00310180(void *n0_, void *p0_, const UnkStruct_00310180_a2 * p1)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    UnkStruct_00310180_1 local;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p1->field_0, &local, 30);
    UnkStruct_00310180_1 * x = local.field_3C != 0 ? (UnkStruct_00310180_1 *)local.field_3C : &local;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, 0, 0, 0);
}
