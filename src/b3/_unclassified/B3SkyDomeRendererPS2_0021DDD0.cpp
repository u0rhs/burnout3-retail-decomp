// CB3SkyDomeRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (farFogPlane.field_0 = t0+1; pcpyld asm operands in instruction order (%1=hi const, %2=loaded lo) fixes reg alloc).

// CB3SkyDomeRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3SkyDomeRenderer;
struct UnkStruct_0021DDD0_1;
struct UnkStruct_farFogPlane;
struct UnkStruct_skyAlpha_1;
struct UnkStruct_skyClamp_1;
struct UnkStruct_skyTest_1;

struct UnkStruct_farFogPlane {
    UnkStruct_0021DDD0_1 * field_0;
};

struct UnkStruct_0021DDD0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};

struct UnkStruct_skyClamp_1 {
    unsigned long field_0;
};

struct UnkStruct_skyTest_1 {
    unsigned long field_0;
};

struct UnkStruct_skyAlpha_1 {
    unsigned long field_0;
};

class CB3SkyDomeRenderer {
public:
    void EndRender();
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyClamp_1 skyClamp_1;
extern UnkStruct_skyTest_1 skyTest_1;
extern UnkStruct_skyAlpha_1 skyAlpha_1;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x0021DDD0
void CB3SkyDomeRenderer::EndRender()
{
    _rwDMAOpenVIFPkt(0x80000000, 4);
    UnkStruct_0021DDD0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008003), "r"(14));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %1, %2" : "=r"(q1) : "r"(8), "r"(skyClamp_1.field_0));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %1, %2" : "=r"(q2) : "r"(71), "r"(skyTest_1.field_0));
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %1, %2" : "=r"(q3) : "r"(66), "r"(skyAlpha_1.field_0));
    t0->field_30 = q3;
    farFogPlane.field_0 = t0 + 1;
}
