// NONMATCHING: func_004DD270 -- retail 58 / ours 61 instructions, 55 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D15E0[];
extern unsigned char D_004D15E8[];
extern unsigned char D_004D15F0[];
extern unsigned char D_004D3418[];
extern unsigned char D_004D341C[];
extern unsigned char D_004D3420[];
extern unsigned char D_004D3424[];
extern unsigned char D_004D3428[];
extern unsigned char D_004D342C[];
extern unsigned char D_004D3430[];
extern unsigned char D_004D3438[];
extern unsigned char D_004D343C[];
extern unsigned char D_004D3440[];
extern unsigned char D_004D3448[];
extern unsigned char D_004D345C[];
extern unsigned char D_004D3460[];
extern unsigned char D_004D349C[];
extern unsigned char D_004D34A0[];
extern unsigned char D_004E0B20[];

// 0x004DD270
extern "C" void func_004DD270()
{
    *(float *)D_004D3418 = 320.0f;
    *(float *)D_004D341C = 180.0f;
    float t1 = *(float *)D_004E0B20;
    *(float *)D_004D3420 = 320.0f;
    *(float *)D_004D3424 = 220.0f;
    *(float *)D_004D3428 = 0.0f;
    *(float *)D_004D342C = 26.0f;
    float t2 = *(float *)D_004D15F0;
    *(float *)(D_004D3430 + 0x4) = 330.0f;
    *(float *)D_004D343C = 380.0f;
    float t3 = *(float *)D_004D15E0;
    float t4 = *(float *)D_004D15E8;
    *(float *)D_004D3438 = (float)594;
    *(float *)D_004D3430 = (float)594;
    float t5 = t3 + t4;
    float t6 = t2 + t5;
    float t7 = t1 + t6;
    float t8 = 1.0f + t6;
    float t9 = 2.0f + t6;
    *(float *)D_004D3440 = t6;
    *(float *)D_004D3448 = t9;
    *(float *)D_004D345C = t7;
    *(float *)D_004D349C = t7;
    *(float *)D_004D3460 = t8;
    *(float *)D_004D34A0 = t8;
}
