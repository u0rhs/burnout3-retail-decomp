// NONMATCHING: func_004D6080 -- retail 41 / ours 77 instructions, 79 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D6080_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C1BD0[];
extern unsigned char D_004C1BE0[];
extern unsigned char D_004C1BF0[];
extern unsigned char D_004C1C00[];
extern unsigned char D_004C1C10[];
extern unsigned char D_004C1C20[];

// 0x004D6080
extern "C" void func_004D6080()
{
    UnkStruct_004D6080_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 0.0f;
    *(float *)&t1.w[1] = 0.0f;
    *(float *)&t1.w[2] = -1.0f;
    UnkStruct_004D6080_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 1.0f;
    *(float *)&t2.w[1] = 0.0f;
    *(float *)&t2.w[2] = 0.0f;
    UnkStruct_004D6080_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = -1.0f;
    *(float *)&t3.w[1] = 0.0f;
    *(float *)&t3.w[2] = 0.0f;
    UnkStruct_004D6080_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = 0.0f;
    *(float *)&t4.w[1] = 0.0f;
    *(float *)&t4.w[2] = 1.0f;
    UnkStruct_004D6080_q t5;   // lanes 3: never written, copied as retail does
    *(float *)&t5.w[0] = 0.0f;
    *(float *)&t5.w[1] = 1.0f;
    *(float *)&t5.w[2] = 0.0f;
    UnkStruct_004D6080_q t6;   // lanes 3: never written, copied as retail does
    *(float *)&t6.w[0] = 0.0f;
    *(float *)&t6.w[1] = -1.0f;
    *(float *)&t6.w[2] = 0.0f;
    *(UnkStruct_004D6080_q *)D_004C1BD0 = t1;
    *(UnkStruct_004D6080_q *)D_004C1BE0 = t2;
    *(UnkStruct_004D6080_q *)D_004C1BF0 = t3;
    *(UnkStruct_004D6080_q *)D_004C1C00 = t4;
    *(UnkStruct_004D6080_q *)D_004C1C10 = t5;
    *(UnkStruct_004D6080_q *)D_004C1C20 = t6;
}
