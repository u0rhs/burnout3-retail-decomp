// Gt2dRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fresh: pcpyld asm per quad, literal halves; CLAMP zero half as unsigned long z declared first, z=0 after CLAMP[0]).

// Gt2dRenderer::Construct() -- hand-written (fresh2); the lifter gave no draft.
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// [C] static member names: config/symbol_addrs_b3names.txt. Quads via the one-line pcpyld asm (BRIEF gifq).
// GS register numbers in the tables (0x42 ALPHA_1, 0x08 CLAMP_1) per the GS manual [L].

typedef unsigned int u_long128 __attribute__((mode(TI)));

class Gt2dRenderer {
public:
    static void Construct();

    static u_long128 _gu128SetPrimGIFTag;
    static u_long128 _gu128SetPrimRGBAQGIFTag;
    static unsigned long _gau64PrimRegs[10];
    static u_long128 _gau128RegListGIFTags[10];
    static u_long128 _gu128ADDRDATAGIFTag;
    static u_long128 _gau128ALPHA_1Regs[8];
    static u_long128 _gau128CLAMP_1Regs[4];
};

#define Q(d, lo, hi) asm("pcpyld %0, %2, %1" : "=r"(d) : "r"(lo), "r"(hi))

// 0x0021A290
void Gt2dRenderer::Construct()
{
    unsigned long z;
    Q(_gu128SetPrimGIFTag, 0x1400000000000001UL, 0UL);
    Q(_gu128SetPrimRGBAQGIFTag, 0x2400000000000001UL, 0x10UL);
    _gau64PrimRegs[0] = 0x56;
    Q(_gau128RegListGIFTags[0], 0x4400000000000000UL, 0x5252UL);
    _gau64PrimRegs[1] = 0x46;
    Q(_gau128RegListGIFTags[1], 0x2400000000000000UL, 0x55UL);
    _gau64PrimRegs[2] = 0x53;
    Q(_gau128RegListGIFTags[2], 0x6400000000000000UL, 0x525252UL);
    _gau64PrimRegs[3] = 0x5B;
    Q(_gau128RegListGIFTags[3], 0x9400000000000000UL, 0x512512512UL);
    _gau64PrimRegs[4] = 0x43;
    Q(_gau128RegListGIFTags[4], 0x3400000000000000UL, 0x555UL);
    _gau64PrimRegs[5] = 0x4B;
    Q(_gau128RegListGIFTags[5], 0x6400000000000000UL, 0x515151UL);
    _gau64PrimRegs[6] = 0x54;
    Q(_gau128RegListGIFTags[6], 0x2400000000000000UL, 0x52UL);
    _gau64PrimRegs[7] = 0x5C;
    Q(_gau128RegListGIFTags[7], 0x3400000000000000UL, 0x512UL);
    _gau64PrimRegs[8] = 0x44;
    Q(_gau128RegListGIFTags[8], 0x1400000000000000UL, 0x5UL);
    _gau64PrimRegs[9] = 0x4C;
    Q(_gau128RegListGIFTags[9], 0x2400000000000000UL, 0x51UL);
    Q(_gu128ADDRDATAGIFTag, 0x1000000000000000UL, 0xEUL);
    Q(_gau128ALPHA_1Regs[0], 0x44UL, 0x42UL);
    Q(_gau128ALPHA_1Regs[1], 0x48UL, 0x42UL);
    Q(_gau128ALPHA_1Regs[2], 0x42UL, 0x42UL);
    Q(_gau128ALPHA_1Regs[3], 0x2AUL, 0x42UL);
    Q(_gau128ALPHA_1Regs[4], 0x54UL, 0x42UL);
    Q(_gau128ALPHA_1Regs[5], 0x58UL, 0x42UL);
    Q(_gau128ALPHA_1Regs[6], 0x52UL, 0x42UL);
    Q(_gau128ALPHA_1Regs[7], 0x6AUL, 0x42UL);
    Q(_gau128CLAMP_1Regs[0], 0x5UL, 0x8UL);
    z = 0;
    Q(_gau128CLAMP_1Regs[1], z, 0x8UL);
    Q(_gau128CLAMP_1Regs[2], 0x1UL, 0x8UL);
    Q(_gau128CLAMP_1Regs[3], 0x4UL, 0x8UL);
}
