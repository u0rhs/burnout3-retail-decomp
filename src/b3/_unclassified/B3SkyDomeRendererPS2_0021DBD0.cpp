// CB3SkyDomeRenderer::SetBackdropAsRenderTarget() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a77: EndRender-style pcpyld packet + 3 lq copies, skyFrame_1 low-half ld via pointer pun).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3SkyDomeRenderer;
struct UnkStruct_0021DBD0_1;
struct UnkStruct_farFogPlane;
struct UnkStruct_skyFrame_1;

struct UnkStruct_0021DBD0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};
struct UnkStruct_farFogPlane {
    UnkStruct_0021DBD0_1 * field_0;
};
struct UnkStruct_skyFrame_1 {
    unsigned long field_0;
};

class CB3SkyDomeRenderer {
public:
    static unsigned long mu64OldFrame_1;
    static u_long128 mu128BackdropFrame_1;
    static u_long128 mu128BackdropScissor_1;
    static u_long128 mu128BackdropTest_1;
    void SetBackdropAsRenderTarget();
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyFrame_1 skyFrame_1;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x0021DBD0
void CB3SkyDomeRenderer::SetBackdropAsRenderTarget()
{
    _rwDMAOpenVIFPkt(0x80000000, 4);
    UnkStruct_0021DBD0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008003), "r"(14));
    t0->field_0 = q0;
    t0->field_10 = CB3SkyDomeRenderer::mu128BackdropFrame_1;
    t0->field_20 = CB3SkyDomeRenderer::mu128BackdropScissor_1;
    t0->field_30 = CB3SkyDomeRenderer::mu128BackdropTest_1;
    unsigned long old = skyFrame_1.field_0;
    farFogPlane.field_0 = t0 + 1;
    CB3SkyDomeRenderer::mu64OldFrame_1 = old;
    skyFrame_1.field_0 = *(unsigned long *)&CB3SkyDomeRenderer::mu128BackdropFrame_1;
}
