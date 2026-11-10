// NONMATCHING: func_004DD410 -- retail 91 / ours 72 instructions, 99 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DD410_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004D3650[];
extern unsigned char D_004D3654[];
extern unsigned char D_004D3658[];
extern unsigned char D_004D365C[];
extern unsigned char D_004D3660[];
extern unsigned char D_004D3664[];
extern unsigned char D_004D3668[];
extern unsigned char D_004D366C[];
extern unsigned char D_004D3670[];
extern unsigned char D_004D3674[];
extern unsigned char D_004D3678[];
extern unsigned char D_004D367C[];
extern unsigned char D_004D3680[];
extern unsigned char D_004D3684[];
extern unsigned char D_004D3688[];
extern unsigned char D_004D368C[];
extern unsigned char D_004D3690[];
extern unsigned char D_004D3694[];
extern unsigned char D_004D3698[];
extern unsigned char D_004D369C[];
extern unsigned char D_004D36A0[];
extern unsigned char D_004D36A4[];
extern unsigned char D_004D36A8[];
extern unsigned char D_004D36AC[];
extern unsigned char D_004D36B0[];
extern unsigned char D_004D36B4[];
extern unsigned char D_004D36B8[];
extern unsigned char D_004D36BC[];
extern unsigned char D_004D36C0[];
extern unsigned char D_004D36C4[];

// 0x004DD410
extern "C" void func_004DD410()
{
    *(float *)D_004D3660 = 0.0f;
    *(float *)D_004D3650 = 0.0f;
    *(float *)D_004D3654 = 0.0f;
    float t1 = 38.0f / 64.0f;
    *(float *)D_004D3658 = 64.0f;
    *(float *)D_004D3684 = 0.0f;
    *(float *)D_004D365C = 32.0f;
    *(float *)D_004D3664 = 0.0f;
    *(float *)D_004D3688 = 1.0f;
    *(float *)D_004D366C = 1.0f;
    *(float *)D_004D368C = 1.0f;
    *(float *)D_004D3674 = 0.0f;
    *(float *)D_004D367C = 1.0f;
    *(float *)D_004D3690 = 128.0f;
    *(float *)D_004D3694 = 64.0f;
    *(float *)D_004D369C = 0.0f;
    *(float *)D_004D3698 = 0.171875f;
    *(float *)D_004D36A4 = 1.0f;
    *(float *)D_004D36AC = 0.0f;
    *(float *)D_004D36B4 = 1.0f;
    *(float *)D_004D36BC = 0.0f;
    *(float *)D_004D36C0 = 0.828125f;
    *(float *)D_004D36C4 = 1.0f;
    *(float *)D_004D3668 = t1;
    *(float *)D_004D3670 = t1;
    float t2 = 46.0f / 64.0f;
    float t3 = 47.0f / 64.0f;
    *(float *)D_004D3678 = t2;
    *(float *)D_004D3680 = t3;
    float t4 = 71.0f / 128.0f;
    float t5 = 84.0f / 128.0f;
    *(float *)D_004D36A0 = t4;
    *(float *)D_004D36A8 = t4;
    *(float *)D_004D36B0 = t5;
    *(float *)D_004D36B8 = t5;
    UnkStruct_004DD410_q t6;   // lanes 0, 1, 2, 3: never written, copied as retail does
}
