// NONMATCHING: func_004D97E0 -- retail 43 / ours 50 instructions, 67 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9360[];
extern unsigned char D_004C9370[];
extern unsigned char D_004C9380[];
extern unsigned char D_004C9390[];
extern unsigned char D_004C93A0[];
extern unsigned char D_004E07A8[];
extern unsigned char D_004E0808[];
extern unsigned char D_004E080C[];
extern unsigned char D_004E0810[];

// 0x004D97E0
extern "C" void func_004D97E0()
{
    float t1 = *(float *)D_004E0808;
    float t2 = *(float *)D_004E080C;
    float t3 = *(float *)D_004E0810;
    float t4 = *(float *)D_004E07A8;
    *(float *)D_004C9360 = 1.0f;
    *(float *)(D_004C9360 + 0x4) = 1.0f;
    *(float *)(D_004C9360 + 0x8) = 1.0f;
    *(float *)(D_004C9360 + 0xC) = t1;
    *(float *)D_004C9370 = 1.0f;
    *(float *)(D_004C9370 + 0x4) = 1.0f;
    *(float *)(D_004C9370 + 0x8) = 1.0f;
    *(float *)(D_004C9370 + 0xC) = t2;
    *(float *)D_004C9380 = 1.0f;
    *(float *)(D_004C9380 + 0x4) = 1.0f;
    *(float *)(D_004C9380 + 0x8) = 1.0f;
    *(float *)(D_004C9380 + 0xC) = t3;
    *(float *)D_004C9390 = 1.0f;
    *(float *)(D_004C9390 + 0x4) = 1.0f;
    *(float *)(D_004C9390 + 0x8) = 1.0f;
    *(float *)(D_004C9390 + 0xC) = 1.0f;
    *(float *)D_004C93A0 = 0.0f;
    *(float *)(D_004C93A0 + 0x4) = 0.0f;
    *(float *)(D_004C93A0 + 0x8) = 0.0f;
    *(float *)(D_004C93A0 + 0xC) = t4;
}
