// NONMATCHING: func_004DAE70 -- retail 10 / ours 9 instructions, 8 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004CA250[];

// 0x004DAE70
extern "C" void func_004DAE70()
{
    *(float *)D_004CA250 = 0.0f;
    *(float *)(D_004CA250 + 0x4) = 0.0f;
    *(float *)(D_004CA250 + 0x8) = 0.0f;
    *(float *)(D_004CA250 + 0xC) = 0.0f;
}
