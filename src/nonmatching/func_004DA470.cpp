// NONMATCHING: func_004DA470 -- retail 35 / ours 65 instructions, 55 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DA470_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C9CD0[];
extern unsigned char D_004C9CE0[];
extern unsigned char D_004C9D00[];
extern unsigned char kGravity[];
extern unsigned char kYAxis[];

// 0x004DA470
extern "C" void func_004DA470()
{
    UnkStruct_004DA470_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 0.0f;
    *(float *)&t1.w[1] = -20.0f;
    *(float *)&t1.w[2] = 0.0f;
    UnkStruct_004DA470_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 0.0f;
    *(float *)&t2.w[1] = 0.0f;
    *(float *)&t2.w[2] = 0.0f;
    UnkStruct_004DA470_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = 1.0f;
    *(float *)&t3.w[1] = 0.0f;
    *(float *)&t3.w[2] = 0.0f;
    UnkStruct_004DA470_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = 0.0f;
    *(float *)&t4.w[1] = 1.0f;
    *(float *)&t4.w[2] = 0.0f;
    UnkStruct_004DA470_q t5;   // lanes 3: never written, copied as retail does
    *(float *)&t5.w[0] = 0.0f;
    *(float *)&t5.w[1] = 0.0f;
    *(float *)&t5.w[2] = 1.0f;
    *(UnkStruct_004DA470_q *)kGravity = t1;
    *(UnkStruct_004DA470_q *)D_004C9CD0 = t2;
    *(UnkStruct_004DA470_q *)D_004C9CE0 = t3;
    *(UnkStruct_004DA470_q *)kYAxis = t4;
    *(UnkStruct_004DA470_q *)D_004C9D00 = t5;
}
