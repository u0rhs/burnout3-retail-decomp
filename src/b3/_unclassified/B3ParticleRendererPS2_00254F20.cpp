// CB3ParticleArray::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (Ghidra draft; strcasecmp find loop with the 0x90/0x18 char-array block; two inlined buffer resets (stride 0x2C), SetW(int v) param stops the (float)-9999 CSE; declaration order rec,name,i,t).

// CB3ParticleArray::Prepare() -- hand-written from the Ghidra draft (ghvu11).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00254F20_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_00254F20_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_00254F20_3 { unsigned char pad_0[0x8]; int field_8; UnkStruct_00254F20_e0 *field_C; };
struct UnkStruct_D_00518688 { UnkStruct_00254F20_3 *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00518688 D_00518688;
struct UnkStruct_00254F20_5 { unsigned char pad_0[0xC]; int field_C; unsigned char pad_10[0x3A]; unsigned char field_4A; };
struct UnkStruct_00254F20_2 { const char *field_0; };
// [G] the two particle buffers at +0xF0 / +0x11C (same layout, reset by the same inlined code)
struct UnkStruct_00254F20_buf {
    CGtV4d *field_0;
    unsigned char pad_4[8];
    unsigned int field_C;
    int field_10;
    float *field_14;
    float field_18;
    float field_1C;
    int field_20;
    unsigned char pad_24[4];
    float field_28;   // [G] read only through field_11C (this+0x144)
};
extern "C" int strcasecmp(const char *, const char *);
static inline void func_00254F20_inl2(UnkStruct_00254F20_buf *b)
{
    for (unsigned int i = 0; i < (b->field_C + 59) / 60; i++) b->field_14[i] = (float)-9999;
}
static inline void func_00254F20_inl3(UnkStruct_00254F20_buf *b, int v)
{
    for (unsigned int i = 0; i < b->field_C; i++) b->field_0[i].SetW(v);
}
static inline void func_00254F20_inl1(UnkStruct_00254F20_buf *b, const float *k)
{
    func_00254F20_inl2(b);
    b->field_20 = 0;
    func_00254F20_inl3(b, -9999);
    b->field_10 = b->field_C - 1;
    b->field_18 = 1.0f;
    b->field_1C = *k;
}

class CB3ParticleArray {
public:
    int Prepare();
    unsigned char pad_0[0x7C];
    int field_7C;
    unsigned char pad_80[0x50];
    u_long128 field_D0;
    UnkStruct_00254F20_5 *field_E0;
    UnkStruct_00254F20_2 *field_E4;
    unsigned char pad_E8[0x8];
    UnkStruct_00254F20_buf field_F0;
    UnkStruct_00254F20_buf field_11C;
};

// 0x00254F20
int CB3ParticleArray::Prepare()
{
    int rec;
    const char *name;
    int i;
    UnkStruct_00254F20_3 *t;
    t = D_00518688.field_0;
    name = field_E4->field_0;
    for (i = 0; i < t->field_8; i++) {
        rec = t->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00254F20_blk *)(rec + 0x90))->field_18, name) == 0) goto found;
    }
    rec = 0;
found:
    field_E0 = (UnkStruct_00254F20_5 *)rec;
    int sh = field_E0->field_4A >> 2;
    if (sh > 0) {
        int n = field_E0->field_C;
        float l = -2.5f;
        while (n > 1) {
            n /= 2;
            l += 1.0f;
        }
        int v = (int)(0.0f + 2048.5f + 16.0f * l) - 0x800;
        if (v < -0x800) v = -0x800;
        else if (v > 0x7FF) v = 0x7FF;
        u_long128 q;
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"((((unsigned long)sh << 2) | 0x120) | ((unsigned long)(v & 0xFFF) << 32)), "r"(20));
        field_D0 = q;
    } else {
        u_long128 q;
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(0x61), "r"(20));
        field_D0 = q;
    }
    func_00254F20_inl1(&field_F0, &field_11C.field_28);
    func_00254F20_inl1(&field_11C, &field_11C.field_28);
    field_7C = 0;
    return 1;
}
