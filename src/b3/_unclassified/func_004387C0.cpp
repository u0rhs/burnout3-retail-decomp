// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_004387C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two buffer+pointer locals with ctor (buf[0]=0 then ptr), const pointer params, as func_003B8930).

struct UnkStruct_004387C0_a3 {
    int field_0;
};

struct UnkStruct_004387C0_a2 {
    int field_0;
};

// [G] same shape as func_003B8930's local: a 30-wchar fallback buffer plus the caller's string pointer.
struct UnkStruct_004387C0_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_004387C0_1(int p) { field_0[0] = 0; field_3C = p; }
};

extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, void *, void *, int, int);

// 0x004387C0
extern "C" void func_004387C0(int n0, void *p0_, const UnkStruct_004387C0_a2 * p1, const UnkStruct_004387C0_a3 * p2)
{
    int p0 = (int)p0_;
    UnkStruct_004387C0_1 a(p1->field_0);
    UnkStruct_004387C0_1 b(p2->field_0);
    void * x = a.field_3C != 0 ? (void *)a.field_3C : (void *)&a;
    void * y = b.field_3C != 0 ? (void *)b.field_3C : (void *)&b;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, y, 0, 0);
}
