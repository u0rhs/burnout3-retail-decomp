// NONMATCHING: func_004DA280 -- retail 6 / ours 7 instructions, 2 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9A58[];
extern unsigned char D_004C9A5C[];
extern unsigned char D_004E0A38[];

// 0x004DA280
extern "C" void func_004DA280()
{
    float t1 = *(float *)D_004E0A38;
    *(float *)D_004C9A58 = t1;
    *(float *)D_004C9A5C = t1;
}
