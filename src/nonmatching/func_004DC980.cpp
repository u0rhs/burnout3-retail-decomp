// NONMATCHING: func_004DC980 -- retail 100 / ours 104 instructions, 122 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D1A40[];
extern unsigned char D_004D1A44[];
extern unsigned char D_004D1A48[];
extern unsigned char D_004D1A4C[];
extern unsigned char D_004D1A50[];
extern unsigned char D_004D1A54[];
extern unsigned char D_004D1A58[];
extern unsigned char D_004D1A5C[];
extern unsigned char D_004D1A60[];
extern unsigned char D_004D1A64[];
extern unsigned char D_004D1A68[];
extern unsigned char D_004D1A6C[];
extern unsigned char D_004D1A70[];
extern unsigned char D_004D1A74[];
extern unsigned char D_004D1A78[];
extern unsigned char D_004D1A7C[];
extern unsigned char D_004D1A80[];
extern unsigned char D_004D1A84[];
extern unsigned char D_004D1A88[];
extern unsigned char D_004D1A8C[];
extern unsigned char D_004D1A90[];
extern unsigned char D_004D1A94[];
extern unsigned char D_004D1A98[];
extern unsigned char D_004D1A9C[];
extern unsigned char D_004D1AA0[];
extern unsigned char D_004D1AA4[];
extern unsigned char D_004D1AA8[];
extern unsigned char D_004D1AAC[];
extern unsigned char D_004D1AB0[];
extern unsigned char D_004D1AB4[];
extern unsigned char D_004D1AC0[];
extern unsigned char D_004D1AD0[];
extern unsigned char D_004E08B0[];
extern unsigned char D_004E0AAC[];
extern unsigned char D_01ECDD90[];
extern "C" void func_00100270(void *, void *, int, int, int);
extern "C" void func_0024D4C0();   // its address is stored

// 0x004DC980
extern "C" void func_004DC980()
{
    *(float *)D_004D1A40 = 0.0f;
    *(float *)D_004D1A44 = 0.0f;
    float t1 = *(float *)D_004E08B0;
    *(float *)D_004D1A48 = 0.5f;
    *(float *)D_004D1A4C = 0.0f;
    *(float *)D_004D1A50 = 0.5f;
    *(float *)D_004D1A54 = 0.5f;
    *(float *)D_004D1A58 = 0.25f;
    *(float *)D_004D1A5C = t1;
    func_00100270(D_01ECDD90, (unsigned char *)func_0024D4C0, 0x0, 0x8, 0x2);
    *(float *)D_004D1A64 = 0.0f;
    float t2 = *(float *)D_004E0AAC;
    *(float *)D_004D1A68 = 1.0f;
    *(float *)D_004D1A60 = 0.0f;
    *(float *)D_004D1A6C = 0.0f;
    *(float *)D_004D1A70 = 0.0f;
    *(float *)D_004D1A74 = 1.0f;
    *(float *)D_004D1A78 = 1.0f;
    *(float *)D_004D1A7C = 1.0f;
    *(float *)D_004D1A80 = 0.015625f;
    *(float *)D_004D1A84 = 0.6875f;
    *(float *)D_004D1A88 = 0.953125f;
    *(float *)D_004D1A8C = 1.0f;
    *(float *)D_004D1A90 = 256.0f;
    *(float *)D_004D1A94 = 384.0f;
    *(float *)D_004D1A98 = 256.0f;
    *(float *)D_004D1A9C = 408.0f;
    *(float *)D_004D1AB0 = 640.0f;
    *(float *)D_004D1AA0 = 384.0f;
    *(float *)D_004D1AA4 = 32.0f;
    *(float *)D_004D1AA8 = 0.0f;
    *(float *)D_004D1AC0 = 1.0f;
    *(float *)(D_004D1AC0 + 0x4) = 1.0f;
    *(float *)(D_004D1AC0 + 0x8) = 1.0f;
    *(float *)(D_004D1AC0 + 0xC) = 1.0f;
    *(float *)D_004D1AAC = 384.0f;
    *(float *)D_004D1AB4 = 32.0f;
    *(float *)D_004D1AD0 = t2;
    *(float *)(D_004D1AD0 + 0x4) = t2;
    *(float *)(D_004D1AD0 + 0x8) = t2;
    *(float *)(D_004D1AD0 + 0xC) = 1.0f;
}
