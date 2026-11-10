// Gt2dRenderer::SetTextureFilterMode(Gt2dRenderer::EGt2dRendererFilter) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (skyTex1_1 field is signed long (mask sign-extends, no pcpyld)).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_skyTex1_1 { long field_0; };
extern UnkStruct_skyTex1_1 skyTex1_1;

class Gt2dRenderer {
public:
    enum EGt2dRendererFilter { UnkEnum_Filter_0 };  // [G] enumerators unknown
    static void SetTextureFilterMode(EGt2dRendererFilter p0);
    static void _Dispatch();
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static u_long128 _gu128ADDRDATAGIFTag;
    static u_long128 _gu128Tex1_1;
};

// 0x00217D40
void Gt2dRenderer::SetTextureFilterMode(EGt2dRendererFilter p0)
{
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < 2) {
        _Dispatch();
    }
    if (_guCurrentPrimType != 10) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = 10;
        u_long128 *tag = (u_long128 *)_gpu64Current;
        *tag = _gu128ADDRDATAGIFTag;
        _gpuNLoops = (unsigned int *)tag;
        _gpu64Current = _gpu64Current + 2;
    }
    switch ((int)p0) {
    case 0:
        skyTex1_1.field_0 = (skyTex1_1.field_0 & ~0x1E0) | 0x120;
        break;
    case 1:
        skyTex1_1.field_0 = skyTex1_1.field_0 & ~0x1E0;
        break;
    }
    u_long128 q;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(0x14), "r"(skyTex1_1.field_0));
    _gu128Tex1_1 = q;
    *(u_long128 *)_gpu64Current = q;
    _gpu64Current = _gpu64Current + 2;
    *_gpuNLoops += 1;
}
