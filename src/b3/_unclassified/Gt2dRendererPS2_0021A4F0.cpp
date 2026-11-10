// Gt2dRenderer::_Dispatch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (8x-unrolled quadword copy (same recipe as Flush): temps declared reversed up front then assigned, int n from an unsigned shift, i/src/dst declaration order).

// Gt2dRenderer::_Dispatch() -- hand-written (a69). Closes the open VIF packet: sets the EOP bit in the DMA tag's nloops word,
// opens a VIF packet for the quadwords accumulated in _gau128Buffer, copies them into the DMA buffer and resets the buffer.
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 *field_0;
};
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(unsigned int, unsigned int);

class Gt2dRenderer {
public:
    static void _Dispatch();
    static unsigned int *_gpuNLoops;
    static unsigned char *_gpu64Current;
    static u_long128 *_gau128Buffer;
    static int _guCurrentPrimType;
};

// 0x0021A4F0
void Gt2dRenderer::_Dispatch()
{
    *_gpuNLoops |= 0x8000;
    int n = (int)((unsigned int)(((unsigned char *)_gpu64Current - (unsigned char *)_gau128Buffer) + 8) >> 4);
    _rwDMAOpenVIFPkt(0x80000000, n);
    u_long128 *src = _gau128Buffer;
    int i = 0;
    u_long128 *dst = farFogPlane.field_0;
    while (i < n - 8) {
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
    _gpu64Current = (unsigned char *)_gau128Buffer;
    _guCurrentPrimType = 11;
    _gpuNLoops = 0;
}
