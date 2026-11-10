// NONMATCHING: func_004DA200 -- retail 30 / ours 33 instructions, 29 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9A20[];
extern unsigned char D_004C9A24[];
extern unsigned char D_004C9A28[];
extern unsigned char D_004C9A30[];
extern unsigned char D_004C9A40[];
extern unsigned char D_004E088C[];
extern unsigned char D_004E0984[];
extern unsigned char D_004E0A20[];

// 0x004DA200
extern "C" void func_004DA200()
{
    float t1 = *(float *)D_004E088C;
    float t2 = *(float *)D_004E0984;
    *(float *)D_004C9A20 = 4.0f;
    float t3 = *(float *)D_004E0A20;
    *(float *)D_004C9A24 = 4.0f;
    float t4 = t1 + 4.0f;
    *(float *)D_004C9A28 = t4;
    *(float *)D_004C9A30 = 1.0f;
    *(float *)(D_004C9A30 + 0x4) = 1.0f;
    *(float *)(D_004C9A30 + 0x8) = 1.0f;
    *(float *)(D_004C9A30 + 0xC) = t2;
    *(float *)D_004C9A40 = 1.0f;
    *(float *)(D_004C9A40 + 0x4) = 1.0f;
    *(float *)(D_004C9A40 + 0x8) = 1.0f;
    *(float *)(D_004C9A40 + 0xC) = t3;
}
