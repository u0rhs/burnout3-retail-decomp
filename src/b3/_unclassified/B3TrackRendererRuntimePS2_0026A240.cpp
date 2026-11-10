// CB3TrackRenderer::FlushInstances() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near1: cmpdiff3 noreorder vcallms + last quad high half in its own local then z = 0 (zero in t2)).

// CB3TrackRenderer::FlushInstances() -- hand-matched (v295; cmpdiff3: `.set noreorder` region around the first vcallms, N223;
// near1: the last MSKPATH3 quad's high half in its own local, then `z = 0;`, gives retail's zero register t2 [G shape]); the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G] (instruction widths).
// Body: set the material and (if changed) the camera data, open a VIF packet sized for the mesh cache, copy the cached
// quads into it, then run the instance microprogram (vcallms 0x968, then 0x9D8 / 0x998 alternately, 5 quads out each)
// and close the packet; GIF/VIF quads as one pcpyld asm per quad into `*p++` (N218).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_0026A240_mc { int field_0; unsigned char pad_4[0xC]; u_long128 field_10[1]; };
struct UnkStruct_0026A240_fog { u_long128 * field_0; };
struct UnkStruct_0026A240_80 { unsigned int field_0; int field_4; };
union UnkStruct_0026A240_q { u_long128 q; int w[4]; };
class CB3TrackRenderer {
public:
    void FlushInstances();
    void ReallySetMaterial();
    void ReallySetupCameraData();
    unsigned char pad_0[0x80];
    UnkStruct_0026A240_80 * field_80;
    unsigned char pad_84;
    signed char field_85;
    signed char field_86;
    signed char field_87[0xD];
    int * field_94;
    unsigned char pad_98;
    signed char field_99;
    unsigned char pad_9A;
    unsigned char field_9B;
    unsigned char pad_9C[0x4];
    unsigned long field_A0;
    unsigned long field_A8;
    unsigned long field_B0;
    unsigned long field_B8;
};
extern UnkStruct_0026A240_mc * _gpMeshCache;
extern UnkStruct_0026A240_fog farFogPlane;
extern void * skyTextureRaster;
extern "C" void _rwDMAOpenVIFPkt(int, int);

static inline void func_0026A240_inl1(int v) { asm("ctc2.i %0, $vi3" : : "r"(v)); }

// 0x0026A240
void CB3TrackRenderer::FlushInstances()
{
    int t = field_86;
    if (t != 0) {
        int n = (signed char)t / 5;
        field_9B = 1;
        ReallySetMaterial();
        signed char c = field_87[field_85];
        if (c != field_99 || field_A0 != field_A8 || field_B0 != field_B8) {
            field_99 = c;
            field_A8 = field_A0;
            field_B8 = field_B0;
            if (field_99 > -1)
                ReallySetupCameraData();
        }
        UnkStruct_0026A240_q s;
        int * sw = s.w;
        sw[0] = n - 1;
        if (*field_94 == 5)
            sw[1] = 1;
        else
            sw[1] = 0;
        sw[2] = 0;
        sw[3] = 0;
        int k = field_86 + 3;
        _rwDMAOpenVIFPkt(0, k + 4 + _gpMeshCache->field_0);
        int i;
        u_long128 * p = farFogPlane.field_0;
        unsigned long z = 0;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)field_80->field_0 << 32) | 0x50000000), "r"(z));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000000UL), "r"(0x10000000UL));
        u_long128 * src = _gpMeshCache->field_10;
        i = 0;
        while (i < _gpMeshCache->field_0 - 7) {
            u_long128 a7, a6, a5, a4, a3, a2, a1, a0;
            a0 = src[i];
            a1 = src[i + 1];
            a2 = src[i + 2];
            a3 = src[i + 3];
            a4 = src[i + 4];
            a5 = src[i + 5];
            a6 = src[i + 6];
            a7 = src[i + 7];
            i += 8;
            *p++ = a0;
            *p++ = a1;
            *p++ = a2;
            *p++ = a3;
            *p++ = a4;
            *p++ = a5;
            *p++ = a6;
            *p++ = a7;
        }
        while (i < _gpMeshCache->field_0) {
            *p++ = src[i];
            i++;
        }
        _gpMeshCache->field_0 = 0;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(int)((k - 1) | 0x10000000)), "r"(((unsigned long)(unsigned int)(((k - 1) << 16) | 0x6C0003A4) << 32) | 0x01000404));
        *p++ = s.q;
        int j = 0;
        int tme;
        if (skyTextureRaster)
            tme = 1;
        else
            tme = 0;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(unsigned int)((int)(((long)tme << 4) | 0x4C) << 15) | 0x30004000) << 32), "r"(0x412));
        asm("ctc2.i %0, $vi3" : : "r"((long)field_85));
        asm(".set noreorder"); asm("vcallms 0x968"); asm(".set reorder");
        while (j < n) {
            u_long128 a, b, c2, d, e;
            asm("vcallms 0x9D8");
            asm(".set noreorder");
            asm("qmfc2 %0, $vf1" : "=r"(a));
            asm("qmfc2 %0, $vf2" : "=r"(b));
            asm("qmfc2 %0, $vf3" : "=r"(c2));
            asm("qmfc2 %0, $vf4" : "=r"(d));
            asm("qmfc2 %0, $vf5" : "=r"(e));
            asm(".set reorder");
            *p++ = a;
            *p++ = b;
            *p++ = c2;
            *p++ = d;
            *p++ = e;
            j++;
            if (!(j < n))
                break;
            asm("vcallms 0x998");
            asm(".set noreorder");
            asm("qmfc2 %0, $vf6" : "=r"(a));
            asm("qmfc2 %0, $vf7" : "=r"(b));
            asm("qmfc2 %0, $vf8" : "=r"(c2));
            asm("qmfc2 %0, $vf9" : "=r"(d));
            asm("qmfc2 %0, $vf10" : "=r"(e));
            asm(".set reorder");
            *p++ = a;
            *p++ = b;
            *p++ = c2;
            *p++ = d;
            *p++ = e;
            j++;
        }
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000000UL), "r"(0x17000000UL));
        if (field_80->field_4 != 0) {
            unsigned long hi = ((unsigned long)(unsigned int)field_80->field_4 << 32) | 0x50000000;
            z = 0;
            asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(hi), "r"(z));
        }
        farFogPlane.field_0 = p;
    }
    asm("vcallms 0xA18");
    asm("cfc2.i $0, $vi0");
    field_86 = 0;
}
