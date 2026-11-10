// NONMATCHING: func_004D6D00 -- retail 59 / ours 111 instructions, 119 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D6D00_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C4970[];
extern unsigned char D_004C4980[];
extern unsigned char D_004C4990[];
extern unsigned char D_004C49A0[];
extern unsigned char D_004C49B0[];
extern unsigned char D_004C49C0[];
extern unsigned char D_004E0A40[];
extern unsigned char D_004E0E00[];
extern unsigned char D_004E0EE0[];
extern unsigned char D_004E0F78[];
extern unsigned char kXAxisVector[];
extern unsigned char kYAxisVector[];

// 0x004D6D00
extern "C" void func_004D6D00()
{
    float t1 = *(float *)D_004E0F78;
    float t2 = *(float *)D_004E0EE0;
    float t3 = *(float *)D_004E0E00;
    float t4 = *(float *)D_004E0A40;
    UnkStruct_004D6D00_q t5;   // lanes 3: never written, copied as retail does
    *(float *)&t5.w[0] = 1.0f;
    *(float *)&t5.w[1] = 0.0f;
    *(float *)&t5.w[2] = 0.0f;
    UnkStruct_004D6D00_q t6;   // lanes 3: never written, copied as retail does
    *(float *)&t6.w[0] = 0.0f;
    *(float *)&t6.w[1] = 1.0f;
    *(float *)&t6.w[2] = 0.0f;
    UnkStruct_004D6D00_q t7;   // lanes 3: never written, copied as retail does
    *(float *)&t7.w[0] = 0.0f;
    *(float *)&t7.w[1] = 0.0f;
    *(float *)&t7.w[2] = 1.0f;
    UnkStruct_004D6D00_q t8;   // lanes 3: never written, copied as retail does
    *(float *)&t8.w[0] = t1;
    *(float *)&t8.w[1] = 0.0f;
    *(float *)&t8.w[2] = 0.0f;
    UnkStruct_004D6D00_q t9;   // lanes 3: never written, copied as retail does
    *(float *)&t9.w[0] = 2.0f;
    *(float *)&t9.w[1] = t2;
    *(float *)&t9.w[2] = t3;
    UnkStruct_004D6D00_q t10;   // lanes 3: never written, copied as retail does
    *(float *)&t10.w[0] = t4;
    *(float *)&t10.w[1] = 2.0f;
    *(float *)&t10.w[2] = t4;
    *(UnkStruct_004D6D00_q *)D_004C4990 = t9;
    UnkStruct_004D6D00_q t11;   // lanes 3: never written, copied as retail does
    *(float *)&t11.w[0] = 0.0f;
    *(float *)&t11.w[1] = 0.5f;
    *(float *)&t11.w[2] = 0.0f;
    *(UnkStruct_004D6D00_q *)D_004C49A0 = t10;
    UnkStruct_004D6D00_q t12;   // lanes 3: never written, copied as retail does
    *(float *)&t12.w[0] = 0.0f;
    *(float *)&t12.w[1] = -0.5f;
    *(float *)&t12.w[2] = 0.0f;
    *(UnkStruct_004D6D00_q *)kXAxisVector = t5;
    *(UnkStruct_004D6D00_q *)kYAxisVector = t6;
    *(UnkStruct_004D6D00_q *)D_004C4970 = t7;
    *(UnkStruct_004D6D00_q *)D_004C4980 = t8;
    *(UnkStruct_004D6D00_q *)D_004C49B0 = t11;
    *(UnkStruct_004D6D00_q *)D_004C49C0 = t12;
}
