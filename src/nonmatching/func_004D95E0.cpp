// NONMATCHING: func_004D95E0 -- retail 30 / ours 25 instructions, 20 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C90E0[];
extern unsigned char D_004C90E4[];
extern unsigned char D_004C90E8[];
extern unsigned char D_004C90EC[];
extern unsigned char D_004C90F0[];
extern unsigned char D_004C90F4[];
extern unsigned char D_004C90F8[];
extern unsigned char D_004C90FC[];
extern unsigned char D_004C9100[];

// 0x004D95E0
extern "C" void func_004D95E0()
{
    *(float *)D_004C90E0 = 48.0f;
    *(float *)D_004C90E4 = 96.0f;
    *(float *)D_004C90E8 = 544.0f;
    float t1 = 48.0f + 544.0f;
    *(float *)D_004C90EC = 224.0f;
    *(float *)D_004C90F4 = 96.0f;
    *(float *)D_004C90FC = 0.0f;
    float t2 = 8.0f + t1;
    *(float *)D_004C90F8 = 0.5f;
    *(float *)D_004C9100 = 224.0f;
    *(float *)D_004C90F0 = t2;
}
