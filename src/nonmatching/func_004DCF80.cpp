// NONMATCHING: func_004DCF80 -- retail 60 / ours 76 instructions, 107 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D3040[];
extern unsigned char D_004D3050[];
extern unsigned char D_004D3060[];
extern unsigned char D_004D3070[];
extern unsigned char D_004D3080[];
extern unsigned char D_004D3090[];
extern unsigned char D_004E095C[];
extern unsigned char D_004E0A40[];
extern unsigned char D_004E0AAC[];
extern unsigned char D_004E0BA8[];
extern unsigned char D_004E0BAC[];
extern unsigned char D_004E0BB0[];
extern unsigned char D_004E0BB4[];
extern unsigned char D_004E0BB8[];
extern unsigned char D_004E0BBC[];
extern unsigned char D_004E0BC0[];
extern unsigned char D_004E0BC4[];
extern unsigned char D_004E0BC8[];

// 0x004DCF80
extern "C" void func_004DCF80()
{
    float t1 = *(float *)D_004E0BA8;
    float t2 = *(float *)D_004E095C;
    float t3 = *(float *)D_004E0BAC;
    float t4 = *(float *)D_004E0BB0;
    float t5 = *(float *)D_004E0BB4;
    float t6 = *(float *)D_004E0BB8;
    float t7 = *(float *)D_004E0A40;
    float t8 = *(float *)D_004E0BBC;
    float t9 = *(float *)D_004E0BC0;
    *(float *)D_004D3040 = t1;
    *(float *)(D_004D3040 + 0x4) = t2;
    *(float *)(D_004D3040 + 0x8) = t3;
    *(float *)(D_004D3040 + 0xC) = 1.0f;
    float t10 = *(float *)D_004E0BC4;
    float t11 = *(float *)D_004E0BC8;
    float t12 = *(float *)D_004E0AAC;
    *(float *)D_004D3050 = 0.5f;
    *(float *)(D_004D3050 + 0x4) = t4;
    *(float *)(D_004D3050 + 0x8) = t6;
    *(float *)(D_004D3050 + 0xC) = 1.0f;
    *(float *)D_004D3060 = 1.0f;
    *(float *)(D_004D3060 + 0x4) = 1.0f;
    *(float *)(D_004D3060 + 0x8) = 1.0f;
    *(float *)(D_004D3060 + 0xC) = 1.0f;
    *(float *)D_004D3070 = t7;
    *(float *)(D_004D3070 + 0x4) = t8;
    *(float *)(D_004D3070 + 0x8) = 0.25f;
    *(float *)(D_004D3070 + 0xC) = 1.0f;
    *(float *)D_004D3080 = t5;
    *(float *)(D_004D3080 + 0x4) = t9;
    *(float *)(D_004D3080 + 0x8) = t11;
    *(float *)(D_004D3080 + 0xC) = 1.0f;
    *(float *)D_004D3090 = t12;
    *(float *)(D_004D3090 + 0x4) = t10;
    *(float *)(D_004D3090 + 0x8) = t10;
    *(float *)(D_004D3090 + 0xC) = 1.0f;
}
