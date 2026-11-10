// NONMATCHING: func_004DD070 -- retail 52 / ours 54 instructions, 48 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D30A0[];
extern unsigned char D_004D30A4[];
extern unsigned char D_004D30A8[];
extern unsigned char D_004D30AC[];
extern unsigned char D_004D30B0[];
extern unsigned char D_004D30B4[];
extern unsigned char D_004D30B8[];
extern unsigned char D_004D30BC[];
extern unsigned char D_004D30C0[];
extern unsigned char D_004D30C8[];
extern unsigned char D_004D30CC[];
extern unsigned char D_004D30D0[];
extern unsigned char D_004D30D4[];
extern unsigned char D_004D30D8[];
extern unsigned char D_004E2F98[];
extern unsigned char D_004E2F9C[];
extern unsigned char D_004E2FA0[];
extern unsigned char D_004E2FA4[];

// 0x004DD070
extern "C" void func_004DD070()
{
    *(float *)D_004D30A0 = 64.0f;
    *(float *)D_004D30A4 = 112.0f;
    *(float *)D_004D30AC = 241.0f;
    *(float *)D_004D30B0 = 320.0f;
    *(float *)D_004E2F98 = 0.0f;
    *(float *)D_004D30B4 = 240.0f;
    *(float *)D_004D30B8 = 320.0f;
    *(float *)D_004D30A8 = (float)513;
    float t1 = (float)513 - 32.0f;
    *(float *)D_004D30BC = 240.0f;
    *(float *)D_004D30C8 = 4.0f;
    *(float *)D_004D30C0 = t1;
    *(float *)D_004D30CC = 4.0f;
    *(float *)D_004D30D0 = 42.0f;
    float t2 = 24.0f + 4.0f;
    *(float *)D_004D30D4 = 32.0f;
    *(float *)D_004E2F9C = 0.5f;
    *(float *)D_004E2FA0 = 1.0f;
    *(float *)D_004E2FA4 = 0.5f;
    *(float *)D_004D30D8 = t2;
}
