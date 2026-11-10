// NONMATCHING: func_004DCF30 -- retail 18 / ours 20 instructions, 22 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D2F80[];
extern unsigned char D_004D2F84[];
extern unsigned char D_004D2F88[];
extern unsigned char D_004D2F8C[];
extern unsigned char D_004D2F90[];
extern unsigned char D_004D2F94[];
extern unsigned char D_004E0A38[];
extern unsigned char D_004E0B1C[];

// 0x004DCF30
extern "C" void func_004DCF30()
{
    float t1 = *(float *)D_004E0A38;
    float t2 = *(float *)D_004E0B1C;
    *(float *)D_004D2F88 = 80.0f;
    *(float *)D_004D2F90 = 480.0f;
    *(float *)D_004D2F94 = 32.0f;
    *(float *)D_004D2F80 = t1;
    *(float *)D_004D2F84 = t1;
    *(float *)D_004D2F8C = t2;
}
