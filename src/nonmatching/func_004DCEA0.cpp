// NONMATCHING: func_004DCEA0 -- retail 26 / ours 35 instructions, 53 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004E2F60[];
extern unsigned char D_004E2F64[];
extern unsigned char D_004E2F68[];
extern unsigned char D_004E2F6C[];
extern unsigned char D_004E2F70[];
extern unsigned char D_004E2F74[];
extern unsigned char D_004E2F78[];
extern unsigned char D_004E2F7C[];
extern unsigned char D_004E2F80[];
extern unsigned char D_004E2F84[];
extern unsigned char D_01ECDEE0[];

// 0x004DCEA0
extern "C" void func_004DCEA0()
{
    *(float *)D_004E2F70 = 240.0f;
    *(float *)D_004E2F60 = 450.0f;
    *(float *)D_004E2F64 = 215.0f;
    *(float *)D_004E2F80 = 1.0f;
    *(float *)D_004E2F84 = 1.0f;
    *(float *)D_004E2F68 = 0.5f;
    *(float *)D_004E2F6C = 0.5f;
    *(float *)D_004E2F78 = 0.0f;
    *(float *)D_004E2F74 = 272.0f;
    *(float *)D_004E2F7C = 0.0f;
    *(float *)D_01ECDEE0 = 1.0f;
    *(float *)(D_01ECDEE0 + 0x4) = 1.0f;
    *(float *)(D_01ECDEE0 + 0x8) = 1.0f;
    *(float *)(D_01ECDEE0 + 0xC) = 1.0f;
}
