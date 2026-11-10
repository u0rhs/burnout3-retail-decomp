// CB3DebrisRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3DebrisRenderer;
struct UnkStruct_002F42C0_2;
struct UnkStruct_D_01E86D1C;
struct UnkStruct_farFogPlane;

struct UnkStruct_D_01E86D1C {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_farFogPlane {
    UnkStruct_002F42C0_2 * field_0;
};

struct UnkStruct_002F42C0_2 {
    u_long128 field_0;
};

class CB3DebrisRenderer {
public:
    void EndRender();
};

extern UnkStruct_D_01E86D1C D_01E86D1C;
extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x002F42C0
void CB3DebrisRenderer::EndRender()
{
    if (D_01E86D1C.field_0 != 0) {
        _rwDMAOpenVIFPkt(0, 1);
        u_long128 q0;
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000), "r"(0x1100000011000000));
        farFogPlane.field_0->field_0 = q0;
        farFogPlane.field_0++;
    }
}
