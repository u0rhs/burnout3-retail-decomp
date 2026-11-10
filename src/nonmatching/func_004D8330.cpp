// NONMATCHING: func_004D8330 -- retail 30 / ours 31 instructions, 13 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5508[];
extern unsigned char D_004C550C[];
extern unsigned char D_004C5510[];
extern unsigned char D_004C5514[];
extern unsigned char D_004C5518[];
extern unsigned char D_004C551C[];
extern unsigned char D_004C5520[];
extern unsigned char D_004C5524[];
extern unsigned char D_004C5528[];
extern unsigned char D_004C552C[];

// 0x004D8330
extern "C" void func_004D8330()
{
    *(float *)D_004C5508 = 72.0f;
    *(float *)D_004C550C = 168.0f;
    *(float *)D_004C5510 = 0.0f;
    *(float *)D_004C5514 = 0.5f;
    *(float *)D_004C5518 = 64.0f;
    *(float *)D_004C5520 = 0.0f;
    *(float *)D_004C551C = 112.0f;
    *(float *)D_004C5524 = 0.0f;
    *(float *)D_004C552C = 113.0f;
    *(float *)D_004C5528 = (float)513;
}
