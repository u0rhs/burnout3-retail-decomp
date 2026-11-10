// NONMATCHING: func_004DC330 -- retail 26 / ours 35 instructions, 53 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004E2F10[];
extern unsigned char D_004E2F14[];
extern unsigned char D_004E2F18[];
extern unsigned char D_004E2F1C[];
extern unsigned char D_004E2F20[];
extern unsigned char D_004E2F24[];
extern unsigned char D_004E2F28[];
extern unsigned char D_004E2F2C[];
extern unsigned char D_004E2F30[];
extern unsigned char D_004E2F34[];
extern unsigned char D_01EB5CF0[];

// 0x004DC330
extern "C" void func_004DC330()
{
    *(float *)D_004E2F20 = 240.0f;
    *(float *)D_004E2F10 = 450.0f;
    *(float *)D_004E2F14 = 215.0f;
    *(float *)D_004E2F30 = 1.0f;
    *(float *)D_004E2F34 = 1.0f;
    *(float *)D_004E2F18 = 0.5f;
    *(float *)D_004E2F1C = 0.5f;
    *(float *)D_004E2F28 = 0.0f;
    *(float *)D_004E2F24 = 272.0f;
    *(float *)D_004E2F2C = 0.0f;
    *(float *)D_01EB5CF0 = 1.0f;
    *(float *)(D_01EB5CF0 + 0x4) = 1.0f;
    *(float *)(D_01EB5CF0 + 0x8) = 1.0f;
    *(float *)(D_01EB5CF0 + 0xC) = 1.0f;
}
