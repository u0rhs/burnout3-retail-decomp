// NONMATCHING: func_004DD6E0 -- retail 52 / ours 100 instructions, 98 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DD6E0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004D39E0[];
extern unsigned char D_004D39F0[];
extern unsigned char D_004D3A00[];
extern unsigned char D_004D3A10[];
extern unsigned char D_004D3A20[];
extern unsigned char D_004D3A30[];
extern unsigned char D_004D3A40[];
extern unsigned char D_004D3A50[];

// 0x004DD6E0
extern "C" void func_004DD6E0()
{
    UnkStruct_004DD6E0_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 1.0f;
    *(float *)&t1.w[1] = 0.0f;
    *(float *)&t1.w[2] = 1.0f;
    UnkStruct_004DD6E0_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 1.0f;
    *(float *)&t2.w[1] = 1.0f;
    *(float *)&t2.w[2] = 1.0f;
    UnkStruct_004DD6E0_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = 0.0f;
    *(float *)&t3.w[1] = 0.0f;
    *(float *)&t3.w[2] = 1.0f;
    UnkStruct_004DD6E0_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = 0.0f;
    *(float *)&t4.w[1] = 1.0f;
    *(float *)&t4.w[2] = 1.0f;
    UnkStruct_004DD6E0_q t5;   // lanes 3: never written, copied as retail does
    *(float *)&t5.w[0] = 1.0f;
    *(float *)&t5.w[1] = 0.0f;
    *(float *)&t5.w[2] = 0.0f;
    UnkStruct_004DD6E0_q t6;   // lanes 3: never written, copied as retail does
    *(float *)&t6.w[0] = 1.0f;
    *(float *)&t6.w[1] = 1.0f;
    *(float *)&t6.w[2] = 0.0f;
    *(UnkStruct_004DD6E0_q *)D_004D3A20 = t5;
    UnkStruct_004DD6E0_q t7;   // lanes 3: never written, copied as retail does
    *(float *)&t7.w[0] = 0.0f;
    *(float *)&t7.w[1] = 0.0f;
    *(float *)&t7.w[2] = 0.0f;
    *(UnkStruct_004DD6E0_q *)D_004D3A30 = t6;
    UnkStruct_004DD6E0_q t8;   // lanes 3: never written, copied as retail does
    *(float *)&t8.w[0] = 0.0f;
    *(float *)&t8.w[1] = 1.0f;
    *(float *)&t8.w[2] = 0.0f;
    *(UnkStruct_004DD6E0_q *)D_004D39E0 = t1;
    *(UnkStruct_004DD6E0_q *)D_004D39F0 = t2;
    *(UnkStruct_004DD6E0_q *)D_004D3A00 = t3;
    *(UnkStruct_004DD6E0_q *)D_004D3A10 = t4;
    *(UnkStruct_004DD6E0_q *)D_004D3A40 = t7;
    *(UnkStruct_004DD6E0_q *)D_004D3A50 = t8;
}
