// NONMATCHING: func_004D94D0 -- retail 38 / ours 40 instructions, 52 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C8F70[];
extern unsigned char D_004C8F80[];
extern unsigned char D_004C8F90[];
extern unsigned char D_004C8FA0[];

// 0x004D94D0
extern "C" void func_004D94D0()
{
    *(float *)D_004C8F70 = -0.5f;
    *(float *)(D_004C8F70 + 0x4) = 1.5f;
    *(float *)(D_004C8F70 + 0x8) = -1.5f;
    *(float *)(D_004C8F70 + 0xC) = 0.5f;
    *(float *)D_004C8F80 = 1.0f;
    *(float *)(D_004C8F80 + 0x4) = -2.5f;
    *(float *)(D_004C8F80 + 0x8) = 2.0f;
    *(float *)(D_004C8F80 + 0xC) = -0.5f;
    *(float *)D_004C8F90 = -0.5f;
    *(float *)(D_004C8F90 + 0x4) = 0.0f;
    *(float *)(D_004C8F90 + 0x8) = 0.5f;
    *(float *)(D_004C8F90 + 0xC) = 0.0f;
    *(float *)D_004C8FA0 = 0.0f;
    *(float *)(D_004C8FA0 + 0x4) = 1.0f;
    *(float *)(D_004C8FA0 + 0x8) = 0.0f;
    *(float *)(D_004C8FA0 + 0xC) = 0.0f;
}
