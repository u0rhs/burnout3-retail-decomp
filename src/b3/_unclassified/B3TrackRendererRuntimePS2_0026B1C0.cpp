// CB3TrackRendererSPRCache::Flush() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (8x-unrolled quadword copy: temps declared reversed up front (u_long128 a7..a0) then assigned in order, src += 8 before the first store, locals declared i/src/dst then assigned dst,i,src).

// CB3TrackRendererSPRCache::Flush() -- hand-written (a69; the lifter refused the register t6 of the unrolled quadword copy).
// Copies the cache's pending quadwords (field_8 .. field_4) into the open VIF packet and rewinds the cache. Layout [G].
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 *field_0;
};
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);

class CB3TrackRendererSPRCache {
public:
    void Flush();

    unsigned char pad_0[4];
    unsigned char *field_4;
    u_long128 *field_8;
};

// 0x0026B1C0
void CB3TrackRendererSPRCache::Flush()
{
    int n = ((int)field_4 - (int)field_8) / 16;
    _rwDMAOpenVIFPkt(0, n);
    int i;
    u_long128 *src;
    u_long128 *dst;
    dst = farFogPlane.field_0;
    i = 0;
    src = field_8;
    while (i < n - 7) {
        u_long128 a7, a6, a5, a4, a3, a2, a1, a0;
        a0 = src[0];
        a1 = src[1];
        a2 = src[2];
        a3 = src[3];
        a4 = src[4];
        a5 = src[5];
        a6 = src[6];
        a7 = src[7];
        i += 8;
        src += 8;
        dst[0] = a0;
        dst[1] = a1;
        dst[2] = a2;
        dst[3] = a3;
        dst[4] = a4;
        dst[5] = a5;
        dst[6] = a6;
        dst[7] = a7;
        dst += 8;
    }
    while (i < n) {
        *dst = *src;
        i++;
        src++;
        dst++;
    }
    farFogPlane.field_0 = dst;
    field_4 = (unsigned char *)field_8;
}
