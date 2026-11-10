// NONMATCHING: func_004DB330 -- retail 43 / ours 45 instructions, 38 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004CA638[];
extern unsigned char D_004CA63C[];
extern unsigned char D_004CA640[];
extern unsigned char D_004CA644[];
extern unsigned char D_004CA648[];
extern unsigned char D_004CA64C[];
extern unsigned char D_004CA650[];
extern unsigned char D_004CA654[];
extern unsigned char D_004CA658[];
extern unsigned char D_004CA65C[];
extern unsigned char D_004CA660[];
extern unsigned char D_004CA664[];
extern unsigned char D_004CA668[];
extern unsigned char D_004CA66C[];
extern unsigned char D_004CA670[];
extern unsigned char D_004E0950[];
extern unsigned char D_004E09DC[];

// 0x004DB330
extern "C" void func_004DB330()
{
    *(float *)D_004CA638 = 0.0f;
    *(float *)D_004CA63C = 0.0f;
    *(float *)D_004CA654 = 2.0f;
    *(float *)D_004CA640 = 640.0f;
    *(float *)D_004CA644 = 60.0f;
    float t1 = *(float *)D_004E0950;
    *(float *)D_004CA648 = 0.0f;
    float t2 = *(float *)D_004E09DC;
    *(float *)D_004CA64C = 0.0f;
    *(float *)D_004CA650 = 640.0f;
    *(float *)D_004CA66C = t1;
    *(float *)D_004CA658 = 0.0f;
    *(float *)D_004CA65C = 420.0f;
    *(float *)D_004CA660 = 640.0f;
    *(float *)D_004CA664 = 60.0f;
    *(float *)D_004CA668 = t2;
    *(float *)(D_004CA670 + 0x4) = 404.0f;
    *(float *)D_004CA670 = (float)610;
}
