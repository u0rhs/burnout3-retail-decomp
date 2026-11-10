// NONMATCHING: func_004DA3D0 -- retail 37 / ours 62 instructions, 73 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9C40[];
extern unsigned char D_004C9C50[];
extern unsigned char D_004C9C60[];
extern unsigned char D_004C9C70[];
extern unsigned char D_004C9C80[];
extern unsigned char D_004C9C90[];
extern unsigned char D_004E06A8[];
extern unsigned char D_004E06DC[];
extern unsigned char D_004E0760[];
extern unsigned char D_004E0954[];
extern unsigned char D_004E0958[];
extern unsigned char D_004E095C[];

// 0x004DA3D0
extern "C" void func_004DA3D0()
{
    float t1 = *(float *)D_004E0760;
    float t2 = *(float *)D_004E0954;
    float t3 = *(float *)D_004E0958;
    float t4 = *(float *)D_004E06A8;
    float t5 = *(float *)D_004E06DC;
    float t6 = *(float *)D_004E095C;
    *(float *)D_004C9C40 = t1;
    *(float *)(D_004C9C40 + 0x4) = t2;
    *(float *)(D_004C9C40 + 0x8) = t3;
    *(float *)(D_004C9C40 + 0xC) = 1.0f;
    *(float *)D_004C9C70 = t1;
    *(float *)(D_004C9C70 + 0x4) = t2;
    *(float *)(D_004C9C70 + 0x8) = t3;
    *(float *)(D_004C9C70 + 0xC) = 1.0f;
    *(float *)D_004C9C50 = t4;
    *(float *)(D_004C9C50 + 0x4) = t4;
    *(float *)(D_004C9C50 + 0x8) = t4;
    *(float *)(D_004C9C50 + 0xC) = 1.0f;
    *(float *)D_004C9C80 = t4;
    *(float *)(D_004C9C80 + 0x4) = t4;
    *(float *)(D_004C9C80 + 0x8) = t4;
    *(float *)(D_004C9C80 + 0xC) = 1.0f;
    *(float *)D_004C9C60 = 1.0f;
    *(float *)(D_004C9C60 + 0x4) = t5;
    *(float *)(D_004C9C60 + 0x8) = t6;
    *(float *)(D_004C9C60 + 0xC) = 1.0f;
    *(float *)D_004C9C90 = 1.0f;
    *(float *)(D_004C9C90 + 0x4) = t5;
    *(float *)(D_004C9C90 + 0x8) = t6;
    *(float *)(D_004C9C90 + 0xC) = 1.0f;
}
