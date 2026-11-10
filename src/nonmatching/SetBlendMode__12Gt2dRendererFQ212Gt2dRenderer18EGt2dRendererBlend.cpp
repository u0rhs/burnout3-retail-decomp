// NONMATCHING: SetBlendMode__12Gt2dRendererFQ212Gt2dRenderer18EGt2dRendererBlend -- diff unavailable
// 82/82 instrs, 6 off: (1) retail loads _gau128ALPHA_1Regs[mode] twice before either store (same as SetTextureAddressMode: ours CSEs to one lq; tried locals/order); (2) 64-bit const 0xFF00000000000000 gives 'lui;dsll32;pcpyld v1,zero,v1' in ours, retail has no pcpyld (ul/ull/long/shift forms tried). Also func_00217E70 symbol name; use diff label func_00217E70=<mangled>
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00217E70 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: Gt2dRenderer::SetBlendMode(Gt2dRenderer::EGt2dRendererBlend) (research/proto/new_names.csv, high)
// Sibling shape: SetTextureAddressMode (src/nonmatching), Resume (Gt2dRendererPS2_00219CA0.cpp).
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_skyFrame_1 {
    unsigned long field_0;
};
extern UnkStruct_skyFrame_1 skyFrame_1;

class Gt2dRenderer {
public:
    enum EGt2dRendererBlend { UnkEnum_Blend_0 };  // [G] enumerators unknown
    static void SetBlendMode(EGt2dRendererBlend p0);
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
void Gt2dRenderer::SetBlendMode(EGt2dRendererBlend p0)
{
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < 3) {
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
    u_long128 qa = _gau128ALPHA_1Regs[p0];
    u_long128 qb = _gau128ALPHA_1Regs[p0];
    _gu128Alpha_1 = qa;
    u_long128 * dst = (u_long128 *)_gpu64Current;
    *dst = qb;
    unsigned long f;
    if ((int)p0 == 7) {
        f = skyFrame_1.field_0 & 0x00FFFFFFFFFFFFFFUL;
    } else {
        f = skyFrame_1.field_0 | (0xFF000000UL << 32);
    }
    u_long128 q;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(76), "r"(f));
    _gu128Frame_1 = q;
    dst[1] = q;
    _gpu64Current = _gpu64Current + 4;
    *_gpuNLoops += 2;
}
