// CB3TrailRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailRenderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3TrailRenderer;
struct UnkStruct_002F3870_1;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_002F3870_1 * field_0;
};

struct UnkStruct_002F3870_1 {
    u_long128 field_0;
};

class CB3TrailRenderer {
public:
    void EndRender();
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x002F3870
void CB3TrailRenderer::EndRender()
{
    _rwDMAOpenVIFPkt(0, 1);
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000), "r"(0x10000000));
    farFogPlane.field_0->field_0 = q0;
    farFogPlane.field_0++;
}
