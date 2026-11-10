// NONMATCHING: func_004DA310 -- retail 35 / ours 44 instructions, 64 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DA310_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C9BF0[];
extern unsigned char D_004E0E94[];
extern unsigned char D_004E0EE0[];
extern unsigned char kBottomUV[];
extern unsigned char kLeftUV[];
extern unsigned char kPickupUp[];
extern unsigned char kRightUV[];
extern unsigned char kTopUV[];

// 0x004DA310
extern "C" void func_004DA310()
{
    float t1 = *(float *)D_004E0EE0;
    *(float *)kRightUV = 0.0f;
    *(float *)kTopUV = 0.0f;
    *(float *)kLeftUV = 1.0f;
    *(float *)(kTopUV + 0x4) = 0.0f;
    float t2 = *(float *)D_004E0E94;
    UnkStruct_004DA310_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = 0.0f;
    *(float *)&t3.w[1] = t1;
    *(float *)&t3.w[2] = 0.0f;
    *(float *)kBottomUV = 1.0f;
    *(float *)(kBottomUV + 0x4) = 1.0f;
    *(UnkStruct_004DA310_q *)kPickupUp = t3;
    *(float *)(kRightUV + 0x4) = 1.0f;
    *(float *)(kLeftUV + 0x4) = 0.0f;
    *(float *)D_004C9BF0 = t2;
    *(float *)(D_004C9BF0 + 0x4) = t2;
    *(float *)(D_004C9BF0 + 0x8) = t2;
    *(float *)(D_004C9BF0 + 0xC) = 1.0f;
}
