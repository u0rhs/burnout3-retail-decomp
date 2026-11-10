// NONMATCHING: func_004D5890 -- retail 17 / ours 30 instructions, 22 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D5890_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004B7A60[];
extern unsigned char D_004B7A70[];
extern unsigned char D_004E0C6C[];

// 0x004D5890
extern "C" void func_004D5890()
{
    float t1 = *(float *)D_004E0C6C;
    UnkStruct_004D5890_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 50.0f;
    *(float *)&t2.w[1] = 50.0f;
    *(float *)&t2.w[2] = 50.0f;
    *(UnkStruct_004D5890_q *)D_004B7A60 = t2;
    UnkStruct_004D5890_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = t1;
    *(float *)&t3.w[1] = t1;
    *(float *)&t3.w[2] = t1;
    *(UnkStruct_004D5890_q *)D_004B7A70 = t3;
}
