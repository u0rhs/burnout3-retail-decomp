// CB3VehicleRenderer::EndVehicleRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3VehicleRenderer;
struct UnkStruct_002204C0_2;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_002204C0_2 * field_0;
};

struct UnkStruct_002204C0_2 {
    u_long128 field_0;
};

class CB3VehicleRenderer {
public:
    void EndVehicleRendering();

    unsigned char pad_0[0xF0];
    int field_F0;
    int field_F4;
    unsigned char pad_F8[0x8];
    int field_100;
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void RpSkyRenderStateSet(int, int);
extern "C" void RpSkyTexCacheFlush();

// 0x002204C0
void CB3VehicleRenderer::EndVehicleRendering()
{
    field_100 = 0;
    _rwDMAOpenVIFPkt(0, 1);
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000), "r"(0x1100000011000000));
    farFogPlane.field_0->field_0 = q0;
    farFogPlane.field_0++;
    RpSkyRenderStateSet(2, field_F0);
    RpSkyRenderStateSet(3, field_F4);
    RpSkyTexCacheFlush();
}
