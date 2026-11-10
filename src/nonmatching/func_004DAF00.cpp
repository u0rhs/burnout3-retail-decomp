// NONMATCHING: func_004DAF00 -- retail 40 / ours 42 instructions, 33 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004CA290[];
extern unsigned char D_004CA294[];
extern unsigned char D_004CA298[];
extern unsigned char D_004CA2A0[];
extern unsigned char D_004CA2C8[];
extern unsigned char D_004CA2D0[];
extern unsigned char D_004CA2D4[];
extern unsigned char D_004CA2D8[];
extern unsigned char D_004CA2DC[];
extern unsigned char D_004CA2E0[];
extern unsigned char D_004CA2E4[];
extern unsigned char D_004CA2E8[];
extern unsigned char D_004CA2EC[];
extern unsigned char D_004E09FC[];
extern unsigned char D_004E0A00[];

// 0x004DAF00
extern "C" void func_004DAF00()
{
    *(float *)D_004CA290 = 2.0f;
    *(float *)D_004CA294 = 2.0f;
    float t1 = *(float *)D_004E09FC;
    float t2 = *(float *)D_004CA2A0;
    float t3 = t1 + 2.0f;
    *(float *)D_004CA2D0 = 256.0f;
    float t4 = 320.0f + t2;
    *(float *)D_004CA2D4 = 24.0f;
    *(float *)D_004CA2D8 = 248.0f;
    *(float *)D_004CA2C8 = t4;
    *(float *)D_004CA2DC = 16.0f;
    *(float *)D_004CA2E4 = 16.0f;
    float t5 = *(float *)D_004E0A00;
    *(float *)D_004CA298 = t3;
    *(float *)D_004CA2E8 = 48.0f;
    *(float *)D_004CA2EC = 24.0f;
    *(float *)D_004CA2E0 = t5;
}
