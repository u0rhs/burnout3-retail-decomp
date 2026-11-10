// NONMATCHING: func_004D6C10 -- retail 55 / ours 77 instructions, 98 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D6C10_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C4280[];
extern unsigned char D_004C4290[];
extern unsigned char D_004C42A0[];
extern unsigned char D_004C42B0[];
extern unsigned char D_004C42C0[];
extern unsigned char kAxisX[];
extern unsigned char kAxisY[];

// 0x004D6C10
extern "C" void func_004D6C10()
{
    UnkStruct_004D6C10_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 1.0f;
    *(float *)&t1.w[1] = 0.0f;
    *(float *)&t1.w[2] = 0.0f;
    UnkStruct_004D6C10_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 0.0f;
    *(float *)&t2.w[1] = 1.0f;
    *(float *)&t2.w[2] = 0.0f;
    UnkStruct_004D6C10_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = 0.0f;
    *(float *)&t3.w[1] = 0.0f;
    *(float *)&t3.w[2] = 1.0f;
    *(UnkStruct_004D6C10_q *)kAxisX = t1;
    *(UnkStruct_004D6C10_q *)kAxisY = t2;
    *(float *)D_004C42B0 = 0.0f;
    *(float *)(D_004C42B0 + 0x4) = 0.0f;
    *(float *)(D_004C42B0 + 0x8) = 1.0f;
    *(float *)(D_004C42B0 + 0xC) = 0.0f;
    *(UnkStruct_004D6C10_q *)D_004C4280 = t3;
    *(float *)D_004C4290 = 2.0f;
    *(float *)(D_004C4290 + 0x4) = -2.0f;
    *(float *)(D_004C4290 + 0x8) = 1.0f;
    *(float *)(D_004C4290 + 0xC) = 1.0f;
    *(float *)D_004C42A0 = -3.0f;
    *(float *)(D_004C42A0 + 0x4) = 3.0f;
    *(float *)(D_004C42A0 + 0x8) = -2.0f;
    *(float *)(D_004C42A0 + 0xC) = -1.0f;
    *(float *)D_004C42C0 = 1.0f;
    *(float *)(D_004C42C0 + 0x4) = 0.0f;
    *(float *)(D_004C42C0 + 0x8) = 0.0f;
    *(float *)(D_004C42C0 + 0xC) = 0.0f;
}
