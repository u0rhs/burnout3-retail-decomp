// NONMATCHING: func_004DD670 -- retail 26 / ours 26 instructions, 8 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D39A0[];
extern unsigned char D_004D39A4[];
extern unsigned char D_004D39A8[];
extern unsigned char D_004D39AC[];
extern unsigned char D_004D39B0[];
extern unsigned char D_004D39B4[];
extern unsigned char D_004D39B8[];
extern unsigned char D_004D39BC[];
extern unsigned char D_004D39C0[];
extern unsigned char D_004D39C4[];

// 0x004DD670
extern "C" void func_004DD670()
{
    *(float *)D_004D39A0 = 12.0f;
    *(float *)D_004D39A4 = 24.0f;
    *(float *)D_004D39AC = 0.0f;
    *(float *)D_004D39A8 = 0.3125f;
    *(float *)D_004D39B0 = 0.5f;
    *(float *)D_004D39B4 = 0.0f;
    *(float *)D_004D39B8 = 0.3125f;
    *(float *)D_004D39C0 = 0.5f;
    *(float *)D_004D39BC = 0.65625f;
    *(float *)D_004D39C4 = 0.65625f;
}
