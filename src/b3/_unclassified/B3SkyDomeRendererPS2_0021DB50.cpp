// CB3SkyDomeRenderer::SetGradientTextureAsSource() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: pcpyld operand order %2,%1 with (97),(20)).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_0021D8E0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};
struct UnkStruct_farFogPlane {
    UnkStruct_0021D8E0_1 * field_0;
};
class CB3SkyDomeRenderer {
public:
    static u_long128 mu128SourceGradientTex0_1;
    void SetGradientTextureAsSource();
};
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);
// 0x0021DB50
void CB3SkyDomeRenderer::SetGradientTextureAsSource()
{
    _rwDMAOpenVIFPkt(0x80000000, 3);
    UnkStruct_0021D8E0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008002), "r"(14));
    t0->field_0 = q0;
    t0->field_10 = CB3SkyDomeRenderer::mu128SourceGradientTex0_1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(97), "r"(20));
    t0->field_20 = q2;
    farFogPlane.field_0 = t0 + 1;
}
