// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_00240A70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00240A70;
struct UnkStruct_00240A70_1;
struct UnkStruct_00240A70_3;
struct UnkStruct_00240A70_e1;

struct UnkStruct_00240A70_1 {
    unsigned char pad_0[0x8];
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
};

struct UnkStruct_00240A70_3 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    float field_10;
};

struct UnkStruct_00240A70_e1 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_00240A70 {
    UnkStruct_00240A70_e1 * field_0;
    UnkStruct_00240A70_1 * field_4;
};

extern "C" UnkStruct_00240A70_3 * func_00240D10(void *, UnkStruct_00240A70_1 *, int);
extern "C" void func_00240D40(void *, int, float, float);

// 0x00240A70
extern "C" void func_00240A70(UnkStruct_00240A70 * self, int p0, int p1, float f0)
{
    int m0 = 0;
    for (;;) {
        UnkStruct_00240A70_1 * t0 = self->field_4;
        int t1 = t0->field_28;
        int m1 = 0;
        for (int i = 0; (i < t1); i++) {
            if (t0->field_8[i] != 0) {
                m1 = (m1 + 1);
            }
        }
        if (m0 >= m1) {
            break;
        }
        UnkStruct_00240A70_3 * r0 = func_00240D10(&self->field_0[m0], t0, m1);
        if (p1 != 0) {
            if (r0 != 0) {
                func_00240D40(&self->field_0[m0], p0, r0->field_10, f0);
                r0->field_0 = (r0->field_0 & -2);
            }
        }
        m0 = (m0 + 1);
    }
}
