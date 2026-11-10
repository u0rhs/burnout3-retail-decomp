// Gt2dRenderer::Resume() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: re-opens the sprite GIF packet (type 10 tag + 5 register quads), static members, nloops += 5).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct RwRaster;
extern RwRaster * skyTextureRaster;
class Gt2dRenderer {
public:
    static void Resume();
    static u_long128 * _gau128Buffer;
    static unsigned long * _gpu64Current;
    static unsigned int * _gpuNLoops;
    static int _guCurrentPrimType;
    static RwRaster * _gpCurrentTexture;
    static u_long128 _gu128ADDRDATAGIFTag;
    static u_long128 _gu128Alpha_1;
    static u_long128 _gu128Tex1_1;
    static u_long128 _gu128Clamp_1;
    static u_long128 _gu128Scissor_1;
    static u_long128 _gu128Frame_1;
};

// 0x00219CA0
void Gt2dRenderer::Resume()
{
    _gpu64Current = (unsigned long *)_gau128Buffer;
    _gpCurrentTexture = skyTextureRaster;
    if (((int)_gpu64Current & 0xF) != 0) {
        _gpu64Current = _gpu64Current + 1;
    }
    _guCurrentPrimType = 10;
    u_long128 * tag = (u_long128 *)_gpu64Current;
    tag[0] = _gu128ADDRDATAGIFTag;
    _gpuNLoops = (unsigned int *)tag;
    tag[1] = _gu128Alpha_1;
    tag[2] = _gu128Tex1_1;
    tag[3] = _gu128Clamp_1;
    tag[4] = _gu128Scissor_1;
    tag[5] = _gu128Frame_1;
    _gpu64Current = _gpu64Current + 12;
    *_gpuNLoops += 5;
}
