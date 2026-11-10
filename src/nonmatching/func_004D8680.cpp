// NONMATCHING: func_004D8680 -- retail 34 / ours 34 instructions, 3 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5BD8[];
extern unsigned char D_004C5BDC[];
extern unsigned char D_004C5BE0[];
extern unsigned char D_004C5BE4[];
extern unsigned char D_004C5BE8[];
extern unsigned char D_004C5BEC[];
extern unsigned char D_004C5BF0[];
extern unsigned char D_004C5BF4[];
extern unsigned char D_004C5BF8[];
extern unsigned char D_004C5BFC[];
extern unsigned char D_004C5C00[];
extern unsigned char D_004C5C04[];
extern unsigned char D_004C5C08[];
extern unsigned char D_004C5C0C[];

// 0x004D8680
extern "C" void func_004D8680()
{
    *(float *)D_004C5BD8 = 0.0f;
    *(float *)D_004C5BDC = 0.0f;
    *(float *)D_004C5BE0 = 0.0f;
    *(float *)D_004C5BE4 = 1.0f;
    *(float *)D_004C5BE8 = 24.0f;
    *(float *)D_004C5BEC = 12.0f;
    *(float *)D_004C5BF0 = 0.0f;
    *(float *)D_004C5BF4 = 0.0f;
    *(float *)D_004C5BF8 = 0.3125f;
    *(float *)D_004C5C04 = 0.34375f;
    *(float *)D_004C5BFC = 0.0f;
    *(float *)D_004C5C00 = 0.0f;
    *(float *)D_004C5C08 = 0.3125f;
    *(float *)D_004C5C0C = 0.34375f;
}
