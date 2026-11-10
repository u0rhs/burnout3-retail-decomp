// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_00435CC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (three buffer+pointer locals (ctor buf[0]=0 then ptr, as func_004387C0), const ptr params, sprintf+ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi in a static inline helper so its char buf is allocated below the third local).

struct UnkStruct_00435CC0_a2 { int field_0; };
struct UnkStruct_00435CC0_a3 { int field_0; };
struct UnkStruct_00435CC0_t0 { int field_0; };
struct UnkStruct_00435CC0_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_00435CC0_1(int p) { field_0[0] = 0; field_3C = p; }
    UnkStruct_00435CC0_1() { field_3C = 0; }
};
struct UnkStruct_D_004B77F0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004B77F0 D_004B77F0;
extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, UnkStruct_00435CC0_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, void *, void *, void *, int);

static inline void func_00435CC0_inl1(UnkStruct_00435CC0_1 * b, int v)
{
    char buf[0x20];
    sprintf(buf, &D_004B77F0, v);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, b, 30);
}

// 0x00435CC0
extern "C" void func_00435CC0(void *n0_, void *p0_, const UnkStruct_00435CC0_a2 * p1, const UnkStruct_00435CC0_a3 * p2, const UnkStruct_00435CC0_t0 * p3)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    UnkStruct_00435CC0_1 a(p1->field_0);
    UnkStruct_00435CC0_1 b;
    func_00435CC0_inl1(&b, p2->field_0);
    UnkStruct_00435CC0_1 c(p3->field_0);
    void * x = a.field_3C != 0 ? (void *)a.field_3C : (void *)&a;
    void * y = b.field_3C != 0 ? (void *)b.field_3C : (void *)&b;
    void * z = c.field_3C != 0 ? (void *)c.field_3C : (void *)&c;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x, y, z, 0);
}
