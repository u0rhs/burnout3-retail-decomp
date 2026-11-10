// NONMATCHING: func_004D6DF0 -- retail 19 / ours 34 instructions, 29 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D6DF0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C4A10[];
extern unsigned char D_004C4A20[];
extern unsigned char D_004E09E4[];
extern unsigned char D_004E0A40[];
extern unsigned char D_004E0D68[];

// 0x004D6DF0
extern "C" void func_004D6DF0()
{
    float t1 = *(float *)D_004E0A40;
    float t2 = *(float *)D_004E0D68;
    float t3 = *(float *)D_004E09E4;
    UnkStruct_004D6DF0_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = t2;
    *(float *)&t4.w[1] = t3;
    *(float *)&t4.w[2] = 0.75f;
    UnkStruct_004D6DF0_q t5;   // lanes 3: never written, copied as retail does
    *(float *)&t5.w[0] = t1;
    *(float *)&t5.w[1] = t1;
    *(float *)&t5.w[2] = t1;
    *(UnkStruct_004D6DF0_q *)D_004C4A10 = t4;
    *(UnkStruct_004D6DF0_q *)D_004C4A20 = t5;
}
