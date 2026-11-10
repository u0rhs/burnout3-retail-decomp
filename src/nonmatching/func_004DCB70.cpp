// NONMATCHING: func_004DCB70 -- retail 29 / ours 29 instructions, 0 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D1C08[];
extern unsigned char D_004D1C0C[];
extern unsigned char D_004D1C10[];
extern unsigned char D_004D1C14[];
extern unsigned char D_004D1C18[];
extern unsigned char D_004D1C1C[];
extern unsigned char D_004D1C20[];
extern unsigned char D_004D1C24[];
extern unsigned char D_004D1C28[];
extern unsigned char D_004D1C2C[];

// 0x004DCB70
extern "C" void func_004DCB70()
{
    *(float *)D_004D1C08 = 496.0f;
    *(float *)D_004D1C0C = 224.0f;
    *(float *)D_004D1C14 = 0.5f;
    *(float *)D_004D1C10 = 0.5f;
    *(float *)D_004D1C18 = 496.0f;
    *(float *)D_004D1C1C = 224.0f;
    *(float *)D_004D1C20 = 0.5f;
    *(float *)D_004D1C24 = 0.5f;
    *(float *)D_004D1C28 = 225.0f;
    *(float *)D_004D1C2C = (float)257;
}
