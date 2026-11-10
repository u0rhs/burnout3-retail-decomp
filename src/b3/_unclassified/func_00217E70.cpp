// Hand-written; the lifter refused it (SetBlendMode: signed long GS register (sibling SetTextureFilterMode), double element read via const __int128* (sibling SetTextureAddressMode), extern C label).

// Gt2dRenderer::SetBlendMode(Gt2dRenderer::EGt2dRendererBlend) -- retail label func_00217E70 [C] (archive a246).
// Hand-written from the archived draft + the proven sibling SetTextureFilterMode's signed `long` GS register.
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_skyFrame_1 {
    long field_0;
};
extern UnkStruct_skyFrame_1 skyFrame_1;

class Gt2dRenderer {
public:
    enum EGt2dRendererBlend { UnkEnum_Blend_0 };  // [G] enumerators unknown
    static void _Dispatch();

    static u_long128 * _gau128Buffer;
    static unsigned long * _gpu64Current;
    static unsigned int * _gpuNLoops;
    static int _guCurrentPrimType;
    static u_long128 _gu128ADDRDATAGIFTag;
    static u_long128 _gau128ALPHA_1Regs[];
    static u_long128 _gu128Alpha_1;
    static u_long128 _gu128Frame_1;
};

// 0x00217E70
// [C] Gt2dRenderer::SetBlendMode(EGt2dRendererBlend) (archive a246); retail's label is still func_00217E70, so C linkage here.
extern "C" void func_00217E70(Gt2dRenderer::EGt2dRendererBlend p0)
{
    if (511 - (int)(((unsigned int)(Gt2dRenderer::_gpu64Current + 1) - (unsigned int)Gt2dRenderer::_gau128Buffer) >> 4) < 3) {
        Gt2dRenderer::_Dispatch();
    }
    if (Gt2dRenderer::_guCurrentPrimType != 10) {
        if (((int)Gt2dRenderer::_gpu64Current & 0xF) != 0) {
            Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 1;
        }
        Gt2dRenderer::_guCurrentPrimType = 10;
        u_long128 * tag = (u_long128 *)Gt2dRenderer::_gpu64Current;
        *tag = Gt2dRenderer::_gu128ADDRDATAGIFTag;
        Gt2dRenderer::_gpuNLoops = (unsigned int *)tag;
        Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 2;
    }
    Gt2dRenderer::_gu128Alpha_1 = Gt2dRenderer::_gau128ALPHA_1Regs[p0];
    u_long128 * dst = (u_long128 *)Gt2dRenderer::_gpu64Current;
    const __int128 * t1 = &Gt2dRenderer::_gau128ALPHA_1Regs[p0];
    *dst = (*t1);
    long f;
    if ((int)p0 == 7) {
        f = skyFrame_1.field_0 & 0x00FFFFFFFFFFFFFFL;
    } else {
        f = skyFrame_1.field_0 | (long)0xFF00000000000000UL;
    }
    u_long128 q;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(76), "r"(f));
    Gt2dRenderer::_gu128Frame_1 = q;
    dst[1] = q;
    Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 4;
    *Gt2dRenderer::_gpuNLoops += 2;
}
