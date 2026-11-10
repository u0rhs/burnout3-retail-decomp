// NONMATCHING: func_004D8DD0 -- retail 10 / ours 16 instructions, 8 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D8DD0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C71A0[];

// 0x004D8DD0
extern "C" void func_004D8DD0()
{
    UnkStruct_004D8DD0_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 1.0f;
    *(float *)&t1.w[1] = 1.0f;
    *(float *)&t1.w[2] = 1.0f;
    *(UnkStruct_004D8DD0_q *)D_004C71A0 = t1;
}
