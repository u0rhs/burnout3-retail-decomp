// Gt2dRenderer::ResetClipRegion() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (scissor quad via pcpyld asm, assoc ((Y|(X|XW))|YH)).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_rect {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[8];
    short field_1C;
    short field_1E;
};
struct UnkStruct_p {
    unsigned char pad_0[0x60];
    UnkStruct_rect *field_60;
};
struct UnkStruct_g {
    UnkStruct_p *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_g ourGlobals;

class Gt2dRenderer {
public:
    static void ResetClipRegion();
    static void _Dispatch();
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static u_long128 _gu128ADDRDATAGIFTag;
    static u_long128 _gu128Scissor_1;
};

// 0x002178E0
void Gt2dRenderer::ResetClipRegion()
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
    UnkStruct_rect *r = ourGlobals.field_0->field_60;
    u_long128 *p2 = (u_long128 *)_gpu64Current;
    unsigned long sc = ((unsigned long)(long)r->field_1E << 32 | ((unsigned long)(long)r->field_1C
        | (unsigned long)(long)(r->field_1C + r->field_C - 1) << 16))
        | (unsigned long)(long)(r->field_1E + r->field_10 - 1) << 48;
    u_long128 q3;
    asm("pcpyld %0, %1, %2" : "=r"(q3) : "r"(0x40), "r"(sc));
    _gu128Scissor_1 = q3;
    p2[0] = q3;
    _gpu64Current = _gpu64Current + 2;
    *_gpuNLoops += 1;
}
