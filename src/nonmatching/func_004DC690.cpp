// NONMATCHING: func_004DC690 -- retail 22 / ours 26 instructions, 30 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D1540[];
extern unsigned char D_004D1550[];
extern unsigned char D_004E0FB0[];
extern unsigned char D_004E0FB4[];
extern unsigned char D_004E0FB8[];
extern unsigned char D_004E0FBC[];

// 0x004DC690
extern "C" void func_004DC690()
{
    float t1 = *(float *)D_004E0FB0;
    float t2 = *(float *)D_004E0FB4;
    float t3 = *(float *)D_004E0FB8;
    float t4 = *(float *)D_004E0FBC;
    *(float *)D_004D1540 = t1;
    *(float *)(D_004D1540 + 0x4) = t2;
    *(float *)(D_004D1540 + 0x8) = t3;
    *(float *)(D_004D1540 + 0xC) = t4;
    *(float *)D_004D1550 = 2.5f;
    *(float *)(D_004D1550 + 0x4) = 2.5f;
    *(float *)(D_004D1550 + 0x8) = 2.5f;
    *(float *)(D_004D1550 + 0xC) = 2.5f;
}
