// NONMATCHING: func_004D89C0 -- retail 30 / ours 31 instructions, 13 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C6E78[];
extern unsigned char D_004C6E7C[];
extern unsigned char D_004C6E80[];
extern unsigned char D_004C6E84[];
extern unsigned char D_004C6E88[];
extern unsigned char D_004C6E8C[];
extern unsigned char D_004C6E90[];
extern unsigned char D_004C6E94[];
extern unsigned char D_004C6E98[];
extern unsigned char D_004C6E9C[];

// 0x004D89C0
extern "C" void func_004D89C0()
{
    *(float *)D_004C6E78 = 320.0f;
    *(float *)D_004C6E7C = 168.0f;
    *(float *)D_004C6E80 = 0.5f;
    *(float *)D_004C6E84 = 0.5f;
    *(float *)D_004C6E88 = 64.0f;
    *(float *)D_004C6E90 = 0.0f;
    *(float *)D_004C6E8C = 112.0f;
    *(float *)D_004C6E94 = 0.0f;
    *(float *)D_004C6E9C = 113.0f;
    *(float *)D_004C6E98 = (float)513;
}
