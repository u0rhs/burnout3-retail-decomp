// CB3ShadowRenderer::EndShadowPlaneRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element sub-struct pointer taken before _rwDMAOpenVIFPkt(0,4) (phantom 3rd arg dropped); interleaved pcpyld/store; farFogPlane = t1 + 1).

// lifter variant 0
// CB3ShadowRenderer::EndShadowPlaneRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3ShadowRenderer;
struct UnkStruct_003039A0_2;
struct UnkStruct_003039A0_e0;
struct UnkStruct_D_00665EC0;
struct UnkStruct_D_00667050;
struct UnkStruct_farFogPlane;

struct UnkStruct_D_00667050 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_farFogPlane {
    UnkStruct_003039A0_2 * field_0;
};

struct UnkStruct_003039A0_2 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};

struct UnkStruct_003039A0_s {
    u_long128 field_0;
    u_long128 field_10;
};

struct UnkStruct_003039A0_e0 {
    unsigned char pad_0[0x1D0];
    UnkStruct_003039A0_s field_1D0;
    unsigned char pad_1F0[0x40];
};

struct UnkStruct_D_00665EC0 {
    unsigned char pad_0[0x460];
    UnkStruct_003039A0_e0 field_460[1];  // [G] element count unknown
};

class CB3ShadowRenderer {
public:
    void EndShadowPlaneRendering();
};

extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_00665EC0 D_00665EC0;

extern "C" void EndRendering__6B3Im3dFv(void *);  // B3Im3d::EndRendering()
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x003039A0
void CB3ShadowRenderer::EndShadowPlaneRendering()
{
    int t0 = D_00667050.field_0;
    EndRendering__6B3Im3dFv(this);
    UnkStruct_003039A0_s * e = &D_00665EC0.field_460[t0].field_1D0;
    _rwDMAOpenVIFPkt(0, 4);
    UnkStruct_003039A0_2 * t1 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000003), "r"(0));
    t1->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x1000000000008002), "r"(14));
    t1->field_10 = q1;
    t1->field_20 = e->field_0;
    t1->field_30 = e->field_10;
    farFogPlane.field_0 = t1 + 1;
}
