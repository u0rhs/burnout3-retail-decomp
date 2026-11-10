// NONMATCHING: func_004D8710 -- retail 53 / ours 53 instructions, 61 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5C30[];
extern unsigned char D_004C5C34[];
extern unsigned char D_004C5C38[];
extern unsigned char D_004C5C3C[];
extern unsigned char D_004C5C40[];
extern unsigned char D_004C5C44[];
extern unsigned char D_004C5C48[];
extern unsigned char D_004C5C4C[];
extern unsigned char D_004C5C50[];
extern unsigned char D_004C5C54[];
extern unsigned char D_004C5C58[];
extern unsigned char D_004C5C5C[];
extern unsigned char D_004C5C60[];
extern unsigned char D_004C5C64[];
extern unsigned char D_004C5C68[];
extern unsigned char D_004C5C6C[];
extern unsigned char D_004C5C70[];
extern unsigned char D_004C5C74[];
extern unsigned char D_004C5C78[];
extern unsigned char D_004C5C7C[];

// 0x004D8710
extern "C" void func_004D8710()
{
    *(float *)D_004C5C30 = 320.0f;
    *(float *)D_004C5C34 = 168.0f;
    *(float *)D_004C5C3C = 0.5f;
    *(float *)D_004C5C38 = 0.5f;
    *(float *)D_004C5C40 = 64.0f;
    *(float *)D_004C5C48 = 0.0f;
    *(float *)D_004C5C44 = 112.0f;
    *(float *)D_004C5C4C = 0.0f;
    *(float *)D_004C5C54 = 113.0f;
    *(float *)D_004C5C58 = 320.0f;
    *(float *)D_004C5C5C = 368.0f;
    *(float *)D_004C5C60 = 0.5f;
    *(float *)D_004C5C64 = 0.5f;
    *(float *)D_004C5C50 = (float)513;
    *(float *)D_004C5C68 = 64.0f;
    *(float *)D_004C5C70 = 0.0f;
    *(float *)D_004C5C6C = 336.0f;
    *(float *)D_004C5C78 = (float)513;
    *(float *)D_004C5C74 = 0.0f;
    *(float *)D_004C5C7C = 65.0f;
}
