// NONMATCHING: func_004D87F0 -- retail 85 / ours 85 instructions, 20 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5CC8[];
extern unsigned char D_004C5CCC[];
extern unsigned char D_004C5CD0[];
extern unsigned char D_004C5CD4[];
extern unsigned char D_004C5CD8[];
extern unsigned char D_004C5CDC[];
extern unsigned char D_004C5CE0[];
extern unsigned char D_004C5CE4[];
extern unsigned char D_004C5CE8[];
extern unsigned char D_004C5CEC[];
extern unsigned char D_004C5CF0[];
extern unsigned char D_004C5CF4[];
extern unsigned char D_004C5CF8[];
extern unsigned char D_004C5CFC[];
extern unsigned char D_004C5D00[];
extern unsigned char D_004C5D04[];
extern unsigned char D_004C5D10[];
extern unsigned char D_004C5D14[];
extern unsigned char D_004C5D18[];
extern unsigned char D_004C5D1C[];
extern unsigned char D_004C5D20[];
extern unsigned char D_004C5D24[];
extern unsigned char D_004C5D28[];
extern unsigned char D_004C5D2C[];
extern unsigned char D_004C5D30[];
extern unsigned char D_004C5D34[];
extern unsigned char D_004C5D38[];
extern unsigned char D_004C5D3C[];
extern unsigned char D_004C5D40[];
extern unsigned char D_004C5D44[];
extern unsigned char D_004C5D48[];
extern unsigned char D_004C5D4C[];

// 0x004D87F0
extern "C" void func_004D87F0()
{
    *(float *)D_004C5CC8 = 556.0f;
    *(float *)D_004C5CCC = 107.0f;
    *(float *)D_004C5CD0 = 140.0f;
    *(float *)D_004C5CD4 = 107.0f;
    *(float *)D_004C5CD8 = 120.0f;
    *(float *)D_004C5CDC = 140.0f;
    *(float *)D_004C5CE0 = -30.0f;
    *(float *)D_004C5CE4 = 33.0f;
    *(float *)D_004C5CE8 = 140.0f;
    *(float *)D_004C5CEC = 140.0f;
    *(float *)D_004C5CF0 = 0.0f;
    *(float *)D_004C5CF4 = 33.0f;
    *(float *)D_004C5CFC = 360.0f;
    *(float *)D_004C5D00 = 640.0f;
    *(float *)D_004C5D04 = 360.0f;
    *(float *)D_004C5D10 = 0.0f;
    *(float *)D_004C5CF8 = (float)570;
    *(float *)D_004C5D14 = 0.1640625f;
    *(float *)D_004C5D24 = 0.4296875f;
    *(float *)D_004C5D18 = 0.6484375f;
    *(float *)D_004C5D1C = 0.3984375f;
    *(float *)D_004C5D20 = 0.0f;
    *(float *)D_004C5D28 = 0.6484375f;
    *(float *)D_004C5D2C = 0.65625f;
    *(float *)D_004C5D30 = 0.0f;
    *(float *)D_004C5D34 = 0.6875f;
    *(float *)D_004C5D38 = 0.6484375f;
    *(float *)D_004C5D3C = 0.9140625f;
    *(float *)D_004C5D40 = 0.6640625f;
    *(float *)D_004C5D44 = 0.1640625f;
    *(float *)D_004C5D48 = 1.0f;
    *(float *)D_004C5D4C = 0.3984375f;
}
