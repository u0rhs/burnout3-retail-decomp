// Gt2dRenderer::SetTextureAddressMode(Gt2dRenderer::EGt2dRendererTexAddress) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: '*dst = _gau128CLAMP_1Regs[p0];' -> 'const __int128 * t1 = &_gau128CLAMP_1Regs[p0]; *dst = (*t1);').

typedef unsigned int u_long128 __attribute__((mode(TI)));

class Gt2dRenderer {
public:
    enum EGt2dRendererTexAddress { TexAddress_0, TexAddress_1, TexAddress_2, TexAddress_3 };  // [G] values unknown
    static void SetTextureAddressMode(EGt2dRendererTexAddress p0);
    static void _Dispatch();

    static u_long128 * _gau128Buffer;
    static unsigned long * _gpu64Current;
    static unsigned int * _gpuNLoops;
    static int _guCurrentPrimType;
    static u_long128 _gu128ADDRDATAGIFTag;
    static u_long128 _gau128CLAMP_1Regs[];
    static u_long128 _gu128Clamp_1;
};

// 0x00217C40
void Gt2dRenderer::SetTextureAddressMode(EGt2dRendererTexAddress p0)
{
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < 2) {
        _Dispatch();
    }
    if (_guCurrentPrimType != 10) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = 10;
        u_long128 * tag = (u_long128 *)_gpu64Current;
        *tag = _gu128ADDRDATAGIFTag;
        _gpuNLoops = (unsigned int *)tag;
        _gpu64Current = _gpu64Current + 2;
    }
    _gu128Clamp_1 = _gau128CLAMP_1Regs[p0];
    u_long128 * dst = (u_long128 *)_gpu64Current;
    const __int128 * t1 = &_gau128CLAMP_1Regs[p0];
    *dst = (*t1);
    _gpu64Current = _gpu64Current + 2;
    (*_gpuNLoops)++;
}
