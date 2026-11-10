// NONMATCHING: func_004DD580 -- retail 58 / ours 53 instructions, 44 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D3760[];
extern unsigned char D_004D3764[];
extern unsigned char D_004D3768[];
extern unsigned char D_004D376C[];
extern unsigned char D_004D3770[];
extern unsigned char D_004D3774[];
extern unsigned char D_004D3778[];
extern unsigned char D_004D377C[];
extern unsigned char D_004D3780[];
extern unsigned char D_004D3784[];
extern unsigned char D_004D38A8[];
extern unsigned char D_004D38AC[];
extern unsigned char D_004D38B0[];
extern unsigned char D_004D38B4[];
extern unsigned char D_004D38B8[];
extern unsigned char D_004D38BC[];
extern unsigned char D_004D38C0[];
extern unsigned char D_004D38C4[];
extern unsigned char D_004D38C8[];

// 0x004DD580
extern "C" void func_004DD580()
{
    *(float *)D_004D3760 = 320.0f;
    *(float *)D_004D3764 = 184.0f;
    *(float *)D_004D3768 = 0.5f;
    *(float *)D_004D376C = 0.5f;
    *(float *)D_004D3770 = 64.0f;
    *(float *)D_004D3778 = 0.0f;
    *(float *)D_004D3774 = 112.0f;
    *(float *)D_004D377C = 0.0f;
    *(float *)D_004D3784 = 145.0f;
    *(float *)D_004D38A8 = 48.0f;
    *(float *)D_004D38AC = 96.0f;
    *(float *)D_004D3780 = (float)513;
    *(float *)D_004D38B0 = 544.0f;
    float t1 = 48.0f + 544.0f;
    *(float *)D_004D38B4 = 304.0f;
    *(float *)D_004D38BC = 96.0f;
    *(float *)D_004D38C0 = 0.5f;
    float t2 = 8.0f + t1;
    *(float *)D_004D38C4 = 0.0f;
    *(float *)D_004D38C8 = 304.0f;
    *(float *)D_004D38B8 = t2;
}
