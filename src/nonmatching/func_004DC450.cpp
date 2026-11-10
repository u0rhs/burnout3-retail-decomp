// NONMATCHING: func_004DC450 -- retail 30 / ours 31 instructions, 13 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D10D8[];
extern unsigned char D_004D10DC[];
extern unsigned char D_004D10E0[];
extern unsigned char D_004D10E4[];
extern unsigned char D_004D10E8[];
extern unsigned char D_004D10EC[];
extern unsigned char D_004D10F0[];
extern unsigned char D_004D10F4[];
extern unsigned char D_004D10F8[];
extern unsigned char D_004D10FC[];

// 0x004DC450
extern "C" void func_004DC450()
{
    *(float *)D_004D10D8 = 320.0f;
    *(float *)D_004D10DC = 168.0f;
    *(float *)D_004D10E0 = 0.5f;
    *(float *)D_004D10E4 = 0.5f;
    *(float *)D_004D10E8 = 64.0f;
    *(float *)D_004D10F0 = 0.0f;
    *(float *)D_004D10EC = 112.0f;
    *(float *)D_004D10F4 = 0.0f;
    *(float *)D_004D10FC = 113.0f;
    *(float *)D_004D10F8 = (float)513;
}
