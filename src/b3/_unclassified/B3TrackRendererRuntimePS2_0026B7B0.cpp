// CB3TrackRenderer::RestoreRenderStatesAfterRenderingTrack() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pcpyld GIF quads; loop dst via (u_long128*)(long)(int)farFogPlane.field_0 (dsll32/dsra32); sky regs: x,z,f declared in order f,z,x and stored x,z,f).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_skyXyoffset_1 { unsigned long field_0; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_006664F0 { u_long128 field_0[4]; };
class CB3TrackRenderer {
public:
    void RestoreRenderStatesAfterRenderingTrack();
    unsigned char pad_0[0x94];
    int field_94;
    unsigned char field_98;
    signed char field_99;
    unsigned char field_9A;
    unsigned char pad_9B[5];
    unsigned long field_A0;
    unsigned long field_A8;
    unsigned long field_B0;
    unsigned long field_B8;
    int field_C0;
    int field_C4;
};
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyXyoffset_1 skyFrame_1;
extern UnkStruct_skyXyoffset_1 skyZbuf_1;
extern UnkStruct_skyXyoffset_1 skyXyoffset_1;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_006664F0 D_006664F0;
extern int _gpMeshCache;
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void RpSkyRenderStateSet(int, int);
extern "C" void RpSkyTexCacheFlush();
// 0x0026B7B0
void CB3TrackRenderer::RestoreRenderStatesAfterRenderingTrack()
{
    field_99 = 0;
    D_00667050.field_0 = field_99;
    _rwDMAOpenVIFPkt(0, 7);
    u_long128 *t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000UL), "r"(0x1100000011000000UL));
    t0[0] = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x10000005UL), "r"(0x5000000500000000UL));
    t0[1] = q1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(0x1000000000008004UL), "r"(14));
    t0[2] = q2;
    farFogPlane.field_0 = farFogPlane.field_0 + 3;
    const UnkStruct_D_006664F0 *const d = &D_006664F0;
    for (int i = 0; i < 4; i++) {
        *(u_long128 *)(long)(int)farFogPlane.field_0 = d->field_0[i];
        farFogPlane.field_0 = farFogPlane.field_0 + 1;
    }
    u_long128 f = d->field_0[0];
    u_long128 z = d->field_0[1];
    u_long128 x = d->field_0[2];
    skyXyoffset_1.field_0 = (unsigned long)x;
    skyZbuf_1.field_0 = (unsigned long)z;
    skyFrame_1.field_0 = (unsigned long)f;
    RpSkyRenderStateSet(2, field_C0);
    RpSkyRenderStateSet(3, field_C4);
    field_94 = 0;
    field_9A = 0;
    _gpMeshCache = 0;
    field_98 = 0;
    field_A0 = 0;
    field_A8 = 0;
    field_B0 = 0;
    field_B8 = 0;
    field_99 = -1;
    RpSkyTexCacheFlush();
}
