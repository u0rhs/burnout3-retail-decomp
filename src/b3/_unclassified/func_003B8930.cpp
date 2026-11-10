// func_003B8930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (three buffer+pointer locals with a ctor (as func_003192A0); each pointer-or-buffer argument taken into a local first).

// func_003B8930 -- tiny-function batch (tools/tiny_batch.py, lifted; hand-matched).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths).

// [G] same shape as func_003192A0's local: a 30-wchar fallback buffer plus the caller's string
// pointer; the argument is the pointer, or the empty buffer when it is null.
struct UnkStruct_003B8930_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_003B8930_1(int p) { field_3C = p; field_0[0] = 0; }
};

extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, void *, void *, void *, int);

// 0x003B8930
// [C] each pointer is taken into its own local before the call (as arguments, MWCC evaluates the
// last one first); the three objects are declared in argument order.
extern "C" void func_003B8930(void *n0_, int p0, void *p1_, void *p2_, void *p3_)
{
    int n0 = (int)n0_;
    int p1 = (int)p1_;
    int p2 = (int)p2_;
    int p3 = (int)p3_;
    UnkStruct_003B8930_1 a(p1);
    UnkStruct_003B8930_1 b(p2);
    UnkStruct_003B8930_1 c(p3);
    void * x = a.field_3C != 0 ? (void *)a.field_3C : (void *)&a;
    void * y = b.field_3C != 0 ? (void *)b.field_3C : (void *)&b;
    void * z = c.field_3C != 0 ? (void *)c.field_3C : (void *)&c;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, y, z, 0);
}
