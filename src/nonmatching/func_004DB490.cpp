// NONMATCHING: func_004DB490 -- retail 90 / ours 97 instructions, 126 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004CA858[];
extern unsigned char D_004CA85C[];
extern unsigned char D_004CA860[];
extern unsigned char D_004CA864[];
extern unsigned char D_004CA868[];
extern unsigned char D_004CA86C[];
extern unsigned char D_004CA870[];
extern unsigned char D_004CA874[];
extern unsigned char D_004CA878[];
extern unsigned char D_004CA87C[];
extern unsigned char D_004CA880[];
extern unsigned char D_004CA884[];
extern unsigned char D_004CA888[];
extern unsigned char D_004CA88C[];
extern unsigned char D_004CA890[];
extern unsigned char D_004CA894[];
extern unsigned char D_004CA8A0[];
extern unsigned char D_004CA8A4[];
extern unsigned char D_004CA8A8[];
extern unsigned char D_004CA8AC[];
extern unsigned char D_004CA8B0[];
extern unsigned char D_004CA8B4[];
extern unsigned char D_004CA8B8[];
extern unsigned char D_004CA8BC[];
extern unsigned char D_004CA8C0[];
extern unsigned char D_004CA8C4[];
extern unsigned char D_004CA8C8[];
extern unsigned char D_004CA8CC[];
extern unsigned char D_004CA8D0[];
extern unsigned char D_004CA8D4[];
extern unsigned char D_004CA900[];
extern unsigned char D_004CA910[];
extern unsigned char D_004E06A8[];
extern unsigned char D_004E06B4[];
extern unsigned char D_004E06DC[];
extern unsigned char D_004E09E8[];
extern unsigned char D_004E09EC[];
extern unsigned char D_004E09F0[];
extern unsigned char D_004E09F4[];

// 0x004DB490
extern "C" void func_004DB490()
{
    *(float *)D_004CA85C = 64.0f;
    *(float *)D_004CA858 = 64.0f;
    *(float *)D_004CA860 = 0.9921875f;
    *(float *)D_004CA864 = 0.0078125f;
    float t1 = *(float *)D_004E09E8;
    *(float *)D_004CA868 = 0.5078125f;
    float t2 = *(float *)D_004E09EC;
    *(float *)D_004CA86C = 0.0078125f;
    float t3 = *(float *)D_004E06DC;
    *(float *)D_004CA870 = 0.9921875f;
    float t4 = *(float *)D_004E06B4;
    *(float *)D_004CA874 = 0.0078125f;
    float t5 = *(float *)D_004E09F0;
    *(float *)D_004CA878 = 0.5078125f;
    *(float *)D_004CA880 = 0.9921875f;
    *(float *)D_004CA884 = 0.9921875f;
    *(float *)D_004CA87C = t5;
    *(float *)D_004CA888 = 0.5078125f;
    float t6 = *(float *)D_004E09F4;
    *(float *)D_004CA88C = 0.9921875f;
    *(float *)D_004CA8A0 = 0.0f;
    *(float *)D_004CA890 = 0.9921875f;
    *(float *)D_004CA894 = 0.9921875f;
    *(float *)D_004CA8BC = t6;
    *(float *)D_004CA8A4 = 0.0f;
    float t7 = *(float *)D_004E06A8;
    *(float *)D_004CA8A8 = 0.5f;
    *(float *)D_004CA8D0 = 1.0f;
    *(float *)D_004CA8AC = 0.0f;
    *(float *)D_004CA8B0 = 1.0f;
    *(float *)D_004CA8B4 = 0.0f;
    *(float *)D_004CA8B8 = 0.5f;
    *(float *)D_004CA8C0 = 0.0f;
    *(float *)D_004CA8C4 = 1.0f;
    *(float *)D_004CA8C8 = 0.5f;
    *(float *)D_004CA8CC = 1.0f;
    *(float *)D_004CA8D4 = 1.0f;
    *(float *)D_004CA900 = t1;
    *(float *)(D_004CA900 + 0x4) = t2;
    *(float *)(D_004CA900 + 0x8) = 0.5f;
    *(float *)(D_004CA900 + 0xC) = 1.0f;
    *(float *)D_004CA910 = t3;
    *(float *)(D_004CA910 + 0x4) = t4;
    *(float *)(D_004CA910 + 0x8) = t7;
    *(float *)(D_004CA910 + 0xC) = 1.0f;
}
