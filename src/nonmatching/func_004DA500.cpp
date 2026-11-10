// NONMATCHING: func_004DA500 -- retail 82 / ours 89 instructions, 78 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9D30[];
extern unsigned char D_004C9D40[];
extern unsigned char D_004C9D50[];
extern unsigned char D_004C9D60[];
extern unsigned char D_004C9D70[];
extern unsigned char D_004C9D74[];
extern unsigned char D_004C9D78[];
extern unsigned char D_004C9D7C[];
extern unsigned char D_004C9D80[];
extern unsigned char D_004C9D90[];
extern unsigned char D_004C9DA0[];
extern unsigned char D_004E0808[];
extern unsigned char D_004E0B34[];
extern unsigned char D_004E0B38[];
extern "C" void _CalculateUV__15CB3MenuImageUVsFffffffUi(void *, int, float, float, float, float, float, float);

// 0x004DA500
extern "C" void func_004DA500()
{
    *(float *)D_004C9D70 = 32.0f;
    float t1 = *(float *)D_004E0808;
    *(float *)D_004C9D74 = 32.0f;
    float t2 = *(float *)D_004E0B34;
    float t3 = *(float *)D_004E0B38;
    *(float *)D_004C9D78 = 16.0f;
    *(float *)D_004C9D7C = 16.0f;
    *(float *)D_004C9D30 = 1.0f;
    *(float *)(D_004C9D30 + 0x4) = 1.0f;
    *(float *)(D_004C9D30 + 0x8) = 1.0f;
    *(float *)(D_004C9D30 + 0xC) = t1;
    *(float *)D_004C9D40 = 1.0f;
    *(float *)(D_004C9D40 + 0x4) = 1.0f;
    *(float *)(D_004C9D40 + 0x8) = 1.0f;
    *(float *)(D_004C9D40 + 0xC) = t2;
    *(float *)D_004C9D50 = 1.0f;
    *(float *)(D_004C9D50 + 0x4) = 1.0f;
    *(float *)(D_004C9D50 + 0x8) = 1.0f;
    *(float *)(D_004C9D50 + 0xC) = t3;
    *(float *)D_004C9D60 = 1.0f;
    *(float *)(D_004C9D60 + 0x4) = 1.0f;
    *(float *)(D_004C9D60 + 0x8) = 1.0f;
    *(float *)(D_004C9D60 + 0xC) = 1.0f;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C9D80, 0x0, 31.0f, 31.0f, 1.0f, 1.0f, 32.0f, 32.0f);
    float t4 = *(float *)D_004C9D74;
    float t5 = *(float *)D_004C9D70;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C9D90, 0x0, 0.0f, 0.0f, t5, t4, t5, t4);
    float t6 = *(float *)D_004C9D74;
    float t7 = *(float *)D_004C9D70;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C9DA0, 0x3, 0.0f, 0.0f, t7, t6, t7, t6);
}
