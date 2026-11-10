// NONMATCHING: func_004DAFA0 -- retail 9 / ours 15 instructions, 9 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DAFA0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004CA310[];

// 0x004DAFA0
extern "C" void func_004DAFA0()
{
    UnkStruct_004DAFA0_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 0.0f;
    *(float *)&t1.w[1] = 0.0f;
    *(float *)&t1.w[2] = 0.0f;
    *(UnkStruct_004DAFA0_q *)D_004CA310 = t1;
}
