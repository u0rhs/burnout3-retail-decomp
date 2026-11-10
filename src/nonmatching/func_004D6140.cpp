// NONMATCHING: func_004D6140 -- retail 10 / ours 17 instructions, 11 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D6140_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C1CD0[];
extern unsigned char D_004E0FE0[];

// 0x004D6140
extern "C" void func_004D6140()
{
    float t1 = *(float *)D_004E0FE0;
    UnkStruct_004D6140_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 0.0f;
    *(float *)&t2.w[1] = t1;
    *(float *)&t2.w[2] = 0.0f;
    *(UnkStruct_004D6140_q *)D_004C1CD0 = t2;
}
