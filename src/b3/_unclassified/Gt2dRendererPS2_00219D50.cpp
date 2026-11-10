// Gt2dRenderer::Suspend() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gif4: *p++ GIF quads; first quad of each block in a local built before the packet pointer load).

// Gt2dRenderer::Suspend() -- hand-matched (gif4).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G] (instruction widths). End and Suspend have identical bodies.
// GIF quads (N218): asm straight into *p++, except the first quad of each block, which retail builds before it
// loads the packet pointer: that one goes into a u_long128 local declared before `p = _gpu64Current`.
// e g

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00219F20_rast {
    unsigned char pad_0[0x3C];
    unsigned int field_3C;
    unsigned int field_40;
};
struct UnkStruct_00219F20_rect {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[8];
    short field_1C;
    short field_1E;
};
struct UnkStruct_00219F20_p {
    unsigned char pad_0[0x60];
    UnkStruct_00219F20_rect *field_60;
};
struct UnkStruct_00219F20_g {
    UnkStruct_00219F20_p *field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_skyAlpha_1 { unsigned long field_0; };
struct UnkStruct_skyTex1_1 { unsigned long field_0; };
struct UnkStruct_skyClamp_1 { unsigned long field_0; };
struct UnkStruct_skyFrame_1 { unsigned long field_0; };
extern UnkStruct_00219F20_g ourGlobals;
extern UnkStruct_skyAlpha_1 skyAlpha_1;
extern UnkStruct_skyTex1_1 skyTex1_1;
extern UnkStruct_skyClamp_1 skyClamp_1;
extern UnkStruct_skyFrame_1 skyFrame_1;
extern UnkStruct_00219F20_rast *skyTextureRaster;

class Gt2dRenderer {
public:
    static void Suspend();
    static void _Dispatch();
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static UnkStruct_00219F20_rast *_gpCurrentTexture;
    static u_long128 _gu128ADDRDATAGIFTag;
};

// 0x00219D50
void Gt2dRenderer::Suspend()
{
    if (511 - (int)((unsigned int)(((unsigned char *)(Gt2dRenderer::_gpu64Current + 1)) - (unsigned char *)Gt2dRenderer::_gau128Buffer) / 16) < 7) {
        Gt2dRenderer::_Dispatch();
    }
    if (Gt2dRenderer::_guCurrentPrimType != 10) {
        if (((int)Gt2dRenderer::_gpu64Current & 0xF) != 0) {
            Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 1;
        }
        Gt2dRenderer::_guCurrentPrimType = 10;
        u_long128 *tag = (u_long128 *)Gt2dRenderer::_gpu64Current;
        *tag = Gt2dRenderer::_gu128ADDRDATAGIFTag;
        Gt2dRenderer::_gpuNLoops = (unsigned int *)tag;
        Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 2;
    }
    if (skyTextureRaster != 0 && skyTextureRaster != Gt2dRenderer::_gpCurrentTexture) {
        unsigned long v = (unsigned long)skyTextureRaster->field_3C | ((unsigned long)skyTextureRaster->field_40 << 32);
        u_long128 q;
        asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(6), "r"(v));
        *(u_long128 *)Gt2dRenderer::_gpu64Current = q;
        Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 2;
        *Gt2dRenderer::_gpuNLoops += 1;
    }
    u_long128 q0;
    asm("pcpyld %0, %1, %2" : "=r"(q0) : "r"(0x42), "r"(skyAlpha_1.field_0));
    u_long128 *p = (u_long128 *)Gt2dRenderer::_gpu64Current;
    *p++ = q0;
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(0x14), "r"(skyTex1_1.field_0));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(8), "r"(skyClamp_1.field_0));
    Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 6;
    UnkStruct_00219F20_rect *r = ourGlobals.field_0->field_60;
    unsigned long sc = ((unsigned long)(long)r->field_1E << 32 | ((unsigned long)(long)r->field_1C
        | (unsigned long)(long)(r->field_1C + r->field_C - 1) << 16))
        | (unsigned long)(long)(r->field_1E + r->field_10 - 1) << 48;
    u_long128 q3;
    asm("pcpyld %0, %1, %2" : "=r"(q3) : "r"(0x40), "r"(sc));
    u_long128 *p2 = (u_long128 *)Gt2dRenderer::_gpu64Current;
    *p2++ = q3;
    asm("pcpyld %0, %1, %2" : "=r"(*p2++) : "r"(0x4C), "r"(skyFrame_1.field_0));
    Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 4;
    *Gt2dRenderer::_gpuNLoops += 5;
    Gt2dRenderer::_Dispatch();
    Gt2dRenderer::_gpu64Current = 0;
}
