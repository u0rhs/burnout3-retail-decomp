// CB3SkyDomeRenderer::BeginRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pcpyld GIF quads via asm (EndRender style), operand order (unsigned)vu != switch).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3SkyDomeRenderer;

struct UnkStruct_farFogPlane {
    u_long128 *field_0;
};
struct UnkStruct_skyUserSwitch1 {
    unsigned int field_0;
};
struct UnkStruct_mCameraParams {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    u_long128 field_60;
    u_long128 field_70;
    u_long128 field_80;
};

class CB3SkyDomeRenderer {
public:
    void BeginRender();
    static UnkStruct_mCameraParams mCameraParams;
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern char vu_game_0046A590[];
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x0021DE50
void CB3SkyDomeRenderer::BeginRender()
{
    _rwDMAOpenVIFPkt(0, 0xB);
    u_long128 *t0 = farFogPlane.field_0;
    u_long128 *v1;
    u_long128 q0;
    if ((unsigned int)vu_game_0046A590 != skyUserSwitch1.field_0) {
        unsigned long lo = ((unsigned long)(unsigned int)vu_game_0046A590 << 32) | 0x50000000UL;
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(lo), "r"(0x1100000011000000UL));
        t0[0] = q0;
        v1 = t0 + 1;
        skyUserSwitch1.field_0 = (unsigned int)vu_game_0046A590;
    } else {
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000UL), "r"(0x1100000011000000UL));
        t0[0] = q0;
        v1 = t0 + 1;
    }
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x10000009UL), "r"(0x6C0903F701000101UL));
    v1[0] = q1;
    v1[1] = CB3SkyDomeRenderer::mCameraParams.field_0;
    v1[2] = CB3SkyDomeRenderer::mCameraParams.field_10;
    v1[3] = CB3SkyDomeRenderer::mCameraParams.field_20;
    v1[4] = CB3SkyDomeRenderer::mCameraParams.field_30;
    v1[5] = CB3SkyDomeRenderer::mCameraParams.field_40;
    v1[6] = CB3SkyDomeRenderer::mCameraParams.field_50;
    v1[7] = CB3SkyDomeRenderer::mCameraParams.field_60;
    v1[8] = CB3SkyDomeRenderer::mCameraParams.field_70;
    v1[9] = CB3SkyDomeRenderer::mCameraParams.field_80;
    farFogPlane.field_0 = v1 + 10;
}
