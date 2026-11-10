// func_0039D530 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (phantom sprintf args dropped; char buf + 30-wchar string local as sibling func_00310180; p1 const).

struct UnkStruct_0039D530_a2 {
    unsigned char field_0;
};

// [G] same shape as func_00310180's local: a 30-wchar buffer plus a string pointer.
struct UnkStruct_0039D530_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_0039D530_1() { field_3C = 0; }
};

struct UnkStruct_D_004B77F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004B77F0 D_004B77F0;

extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, UnkStruct_0039D530_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_0039D530_1 *, int, int, int);

// 0x0039D530
extern "C" void func_0039D530(void *n0_, void *p0_, const UnkStruct_0039D530_a2 * p1)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    UnkStruct_0039D530_1 local;
    char buf[0x20];
    sprintf(buf, &D_004B77F0, p1->field_0);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, &local, 30);
    UnkStruct_0039D530_1 * x = local.field_3C != 0 ? (UnkStruct_0039D530_1 *)local.field_3C : &local;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, 0, 0, 0);
}
