// NONMATCHING: func_004DA0B0 -- retail 30 / ours 27 instructions, 34 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9948[];
extern unsigned char D_004C994C[];
extern unsigned char D_004C9950[];
extern unsigned char D_004C9954[];
extern unsigned char D_004C9958[];
extern unsigned char D_004C995C[];
extern unsigned char D_004C9960[];
extern unsigned char D_004C9964[];
extern unsigned char D_004C9968[];

// 0x004DA0B0
extern "C" void func_004DA0B0()
{
    *(float *)D_004C9948 = 32.0f;
    *(float *)D_004C994C = 128.0f;
    *(float *)D_004C9950 = 241.0f;
    float t1 = 32.0f + 241.0f;
    *(float *)D_004C9954 = 240.0f;
    *(float *)D_004C995C = 128.0f;
    *(float *)D_004C9964 = 0.0f;
    float t2 = 8.0f + t1;
    *(float *)D_004C9960 = 0.5f;
    *(float *)D_004C9968 = 240.0f;
    *(float *)D_004C9958 = t2;
}
