// NONMATCHING: func_004DD140 -- retail 74 / ours 82 instructions, 87 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D3130[];
extern unsigned char D_004D3134[];
extern unsigned char D_004D3138[];
extern unsigned char D_004D3140[];
extern unsigned char D_004D3150[];
extern unsigned char D_004D3160[];
extern unsigned char D_004D3170[];
extern unsigned char D_004D3180[];
extern unsigned char D_004D3190[];
extern unsigned char D_004E08B0[];
extern unsigned char D_004E0A38[];
extern unsigned char D_004E0A40[];
extern unsigned char D_004E0AAC[];
extern "C" void _CalculateUV__15CB3MenuImageUVsFffffffUi(void *, int, float, float, float, float, float, float);

// 0x004DD140
extern "C" void func_004DD140()
{
    float t1 = *(float *)D_004E0A38;
    *(float *)D_004D3138 = 40.0f;
    float t2 = *(float *)D_004E0A40;
    float t3 = *(float *)D_004E08B0;
    *(float *)D_004D3130 = t1;
    *(float *)D_004D3134 = t1;
    float t4 = *(float *)D_004E0AAC;
    *(float *)(D_004D3138 + 0x4) = 0.0f;
    *(float *)D_004D3140 = 0.0f;
    *(float *)(D_004D3140 + 0x4) = 0.0f;
    *(float *)(D_004D3140 + 0x8) = 0.0f;
    *(float *)(D_004D3140 + 0xC) = 0.0f;
    *(float *)D_004D3150 = t2;
    *(float *)(D_004D3150 + 0x4) = t2;
    *(float *)(D_004D3150 + 0x8) = t2;
    *(float *)(D_004D3150 + 0xC) = 1.0f;
    *(float *)D_004D3160 = 0.0f;
    *(float *)(D_004D3160 + 0x4) = 0.0f;
    *(float *)(D_004D3160 + 0x8) = 0.0f;
    *(float *)(D_004D3160 + 0xC) = t3;
    *(float *)D_004D3170 = 1.0f;
    *(float *)(D_004D3170 + 0x4) = 1.0f;
    *(float *)(D_004D3170 + 0x8) = t4;
    *(float *)(D_004D3170 + 0xC) = 1.0f;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004D3180, 0x0, 128.0f, 0.0f, 64.0f, 64.0f, 256.0f, 128.0f);
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004D3190, 0x0, 64.0f, 0.0f, 64.0f, 64.0f, 256.0f, 128.0f);
}
