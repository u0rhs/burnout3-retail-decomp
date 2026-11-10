// NONMATCHING: func_004D9700 -- retail 27 / ours 27 instructions, 18 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9220[];
extern unsigned char D_004C9224[];
extern unsigned char D_004C9228[];
extern unsigned char D_004C922C[];
extern unsigned char D_004C9230[];
extern unsigned char D_004C9234[];
extern unsigned char D_004C9238[];
extern unsigned char D_004C923C[];
extern unsigned char D_004C9240[];
extern unsigned char D_004C9244[];

// 0x004D9700
extern "C" void func_004D9700()
{
    *(float *)D_004C9220 = 320.0f;
    *(float *)D_004C9224 = 120.0f;
    *(float *)D_004C922C = 0.0f;
    *(float *)D_004C9228 = 0.5f;
    *(float *)D_004C9230 = 64.0f;
    *(float *)D_004C9234 = 112.0f;
    *(float *)D_004C9238 = 0.0f;
    *(float *)D_004C923C = 0.0f;
    *(float *)D_004C9240 = 512.0f;
    *(float *)D_004C9244 = 64.0f;
}
