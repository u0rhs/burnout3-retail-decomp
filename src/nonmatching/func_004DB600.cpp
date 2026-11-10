// NONMATCHING: func_004DB600 -- retail 7 / ours 9 instructions, 6 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004CA920[];
extern unsigned char D_004CA924[];
extern unsigned char D_004E06E0[];
extern unsigned char D_004E09DC[];

// 0x004DB600
extern "C" void func_004DB600()
{
    float t1 = *(float *)D_004E09DC;
    float t2 = *(float *)D_004E06E0;
    *(float *)D_004CA920 = t1;
    *(float *)D_004CA924 = t2;
}
