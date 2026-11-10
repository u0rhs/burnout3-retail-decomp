// func_0038C070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element-pointer local into array at +0x12AD50 (null-tested); if(flag){loop; return 1;} return 1; merged && / || tests).

struct UnkStruct_0038C070;
struct UnkStruct_0038C070_4;
struct UnkStruct_0038C070_e3;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A0;

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038C070_e3 {
    unsigned char pad_0[0x16B4];
    float field_16B4;
    int field_16B8;
    unsigned char pad_16BC[0xD74];
    UnkStruct_0038C070_4 * field_2430;
    unsigned char pad_2434[0x39C];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD50];
    UnkStruct_0038C070_e3 field_12AD50[1];  // [G] element count unknown
};

struct UnkStruct_0038C070_4 {
    unsigned char pad_0[0x218];
    signed char field_218;
};

struct UnkStruct_0038C070 {
    unsigned char pad_0[0x4C];
    unsigned char field_4C;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;

// 0x0038C070
extern "C" int func_0038C070(UnkStruct_0038C070 * self, int p0)
{
    if (self->field_4C != 0) {
        int t0 = D_0064D3A0.field_0;
        for (int i = 0; i < t0; i++) {
            UnkStruct_0038C070_e3 * e = &D_00522660.field_12AD50[i];
            if (e != 0 && p0 == e->field_2430->field_218) {
                if (0.0f == e->field_16B4 || e->field_16B8 == 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 1;
}
