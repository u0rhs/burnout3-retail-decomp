// NONMATCHING: func_004D9A70 -- retail 37 / ours 39 instructions, 28 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9460[];
extern unsigned char D_004C9464[];
extern unsigned char D_004C9468[];
extern unsigned char D_004C946C[];
extern unsigned char D_004C9470[];
extern unsigned char D_004C9474[];
extern unsigned char D_004C9478[];
extern unsigned char D_004C947C[];
extern unsigned char D_004C9480[];
extern unsigned char D_004C9484[];
extern unsigned char D_004C9488[];
extern unsigned char D_004C948C[];
extern unsigned char D_004C9490[];
extern unsigned char D_004C9494[];
extern unsigned char D_004C9498[];
extern unsigned char D_004C949C[];
extern unsigned char D_004E06DC[];
extern unsigned char D_004E0860[];

// 0x004D9A70
extern "C" void func_004D9A70()
{
    *(float *)D_004C9460 = 0.0f;
    *(float *)D_004C9464 = -1.0f;
    float t1 = *(float *)D_004E06DC;
    *(float *)D_004C9470 = 1.0f;
    float t2 = *(float *)D_004E0860;
    *(float *)D_004C9474 = 0.0f;
    *(float *)D_004C9480 = 0.0f;
    *(float *)D_004C9468 = t1;
    *(float *)D_004C9484 = 1.0f;
    *(float *)D_004C9478 = t1;
    *(float *)D_004C9488 = t2;
    *(float *)D_004C948C = t1;
    *(float *)D_004C9490 = -1.0f;
    *(float *)D_004C946C = t2;
    *(float *)D_004C9494 = 0.0f;
    *(float *)D_004C947C = t1;
    *(float *)D_004C9498 = t2;
    *(float *)D_004C949C = t1;
}
