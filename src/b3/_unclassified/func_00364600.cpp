// func_00364600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two func_003192A0-style buffer locals built by a ctor(ptr); Get() results into temps x,y before the call; p2 a const reference).

struct UnkStruct_00364600_a3 {
    int field_0;
};

// [G] a 30-wchar fallback buffer plus the caller's string pointer (as func_003192A0's local);
// Get() returns the pointer, or the empty buffer when it is null.
struct UnkStruct_00364600_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_00364600_1(int s) { field_3C = s; field_0[0] = 0; }
    UnkStruct_00364600_1 *Get() { return field_3C != 0 ? (UnkStruct_00364600_1 *)field_3C : this; }
};

extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_00364600_1 *, UnkStruct_00364600_1 *, int, int);

// 0x00364600
extern "C" void func_00364600(void *n0_, int p0, void *p1_, const UnkStruct_00364600_a3 & p2)
{
    int n0 = (int)n0_;
    int p1 = (int)p1_;
    UnkStruct_00364600_1 a(p1);
    UnkStruct_00364600_1 b(p2.field_0);
    UnkStruct_00364600_1 *x = a.Get();
    UnkStruct_00364600_1 *y = b.Get();
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, y, 0, 0);
}
