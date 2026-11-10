// NONMATCHING: func_004D8A80 -- retail 58 / ours 53 instructions, 44 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C6F50[];
extern unsigned char D_004C6F54[];
extern unsigned char D_004C6F58[];
extern unsigned char D_004C6F5C[];
extern unsigned char D_004C6F60[];
extern unsigned char D_004C6F64[];
extern unsigned char D_004C6F68[];
extern unsigned char D_004C6F6C[];
extern unsigned char D_004C6F70[];
extern unsigned char D_004C6F74[];
extern unsigned char D_004C6F78[];
extern unsigned char D_004C6F7C[];
extern unsigned char D_004C6F80[];
extern unsigned char D_004C6F84[];
extern unsigned char D_004C6F88[];
extern unsigned char D_004C6F8C[];
extern unsigned char D_004C6F90[];
extern unsigned char D_004C6F94[];
extern unsigned char D_004C6F98[];

// 0x004D8A80
extern "C" void func_004D8A80()
{
    *(float *)D_004C6F50 = 320.0f;
    *(float *)D_004C6F54 = 168.0f;
    *(float *)D_004C6F58 = 0.5f;
    *(float *)D_004C6F5C = 0.5f;
    *(float *)D_004C6F60 = 64.0f;
    *(float *)D_004C6F68 = 0.0f;
    *(float *)D_004C6F64 = 112.0f;
    *(float *)D_004C6F6C = 0.0f;
    *(float *)D_004C6F74 = 113.0f;
    *(float *)D_004C6F78 = 48.0f;
    *(float *)D_004C6F7C = 96.0f;
    *(float *)D_004C6F70 = (float)513;
    *(float *)D_004C6F80 = 544.0f;
    float t1 = 48.0f + 544.0f;
    *(float *)D_004C6F84 = 224.0f;
    *(float *)D_004C6F8C = 96.0f;
    *(float *)D_004C6F90 = 0.5f;
    float t2 = 8.0f + t1;
    *(float *)D_004C6F94 = 0.0f;
    *(float *)D_004C6F98 = 224.0f;
    *(float *)D_004C6F88 = t2;
}
