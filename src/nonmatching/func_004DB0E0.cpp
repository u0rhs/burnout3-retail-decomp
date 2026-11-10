// NONMATCHING: func_004DB0E0 -- retail 135 / ours 149 instructions, 258 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DB0E0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004CA4E0[];
extern unsigned char D_004CA4F0[];
extern unsigned char D_004CA500[];
extern unsigned char D_004CA510[];
extern unsigned char D_004CA520[];
extern unsigned char D_004CA530[];
extern unsigned char D_004CA540[];
extern unsigned char D_004CA550[];
extern unsigned char D_004CA560[];
extern unsigned char D_004CA570[];
extern unsigned char D_004CA580[];
extern unsigned char D_004CA590[];
extern unsigned char D_004CA5A0[];
extern unsigned char D_004CA5B0[];
extern unsigned char D_004CA5C0[];
extern unsigned char D_004E06A4[];
extern unsigned char D_004E06AC[];
extern unsigned char D_004E06B4[];
extern unsigned char D_004E06B8[];
extern unsigned char D_004E06C0[];
extern unsigned char D_004E06DC[];
extern unsigned char D_004E0760[];
extern unsigned char D_004E07C8[];
extern unsigned char D_004E0890[];
extern unsigned char D_004E0894[];
extern unsigned char D_004E0898[];
extern unsigned char D_004E089C[];
extern unsigned char D_004E08A0[];

// 0x004DB0E0
extern "C" void func_004DB0E0()
{
    float t1 = *(float *)D_004E0894;
    float t2 = *(float *)D_004E06AC;
    float t3 = *(float *)D_004E0760;
    float t4 = *(float *)D_004E06DC;
    float t5 = *(float *)D_004E0898;
    float t6 = *(float *)D_004E089C;
    float t7 = *(float *)D_004E08A0;
    float t8 = *(float *)D_004E07C8;
    float t9 = *(float *)D_004E06A4;
    float t10 = *(float *)D_004E06B4;
    float t11 = *(float *)D_004E0890;
    float t12 = *(float *)D_004E06C0;
    float t13 = *(float *)D_004E06B8;
    *(float *)D_004CA4E0 = 0.5f;
    *(float *)(D_004CA4E0 + 0x4) = t2;
    *(float *)(D_004CA4E0 + 0x8) = t2;
    *(float *)(D_004CA4E0 + 0xC) = 1.0f;
    *(float *)D_004CA4F0 = 0.0f;
    *(float *)(D_004CA4F0 + 0x4) = t1;
    *(float *)(D_004CA4F0 + 0x8) = t2;
    *(float *)(D_004CA4F0 + 0xC) = 1.0f;
    *(float *)D_004CA500 = t2;
    *(float *)(D_004CA500 + 0x4) = t3;
    *(float *)(D_004CA500 + 0x8) = 0.0f;
    *(float *)(D_004CA500 + 0xC) = 1.0f;
    *(float *)D_004CA510 = t2;
    *(float *)(D_004CA510 + 0x4) = t3;
    *(float *)(D_004CA510 + 0x8) = t4;
    *(float *)(D_004CA510 + 0xC) = 1.0f;
    *(float *)D_004CA520 = t6;
    *(float *)(D_004CA520 + 0x4) = t5;
    *(float *)(D_004CA520 + 0x8) = t7;
    *(float *)(D_004CA520 + 0xC) = 1.0f;
    *(float *)D_004CA530 = t2;
    *(float *)(D_004CA530 + 0x4) = t3;
    *(float *)(D_004CA530 + 0x8) = t8;
    *(float *)(D_004CA530 + 0xC) = 1.0f;
    *(float *)D_004CA570 = t2;
    *(float *)(D_004CA570 + 0x4) = t2;
    *(float *)(D_004CA570 + 0x8) = t2;
    *(float *)(D_004CA570 + 0xC) = 1.0f;
    *(float *)D_004CA580 = t2;
    *(float *)(D_004CA580 + 0x4) = t11;
    *(float *)(D_004CA580 + 0x8) = t12;
    *(float *)(D_004CA580 + 0xC) = 1.0f;
    *(float *)D_004CA590 = 1.0f;
    *(float *)(D_004CA590 + 0x4) = t2;
    *(float *)(D_004CA590 + 0x8) = t4;
    *(float *)(D_004CA590 + 0xC) = 1.0f;
    *(float *)D_004CA540 = t10;
    *(float *)(D_004CA540 + 0x4) = t10;
    *(float *)(D_004CA540 + 0x8) = t10;
    *(float *)(D_004CA540 + 0xC) = 1.0f;
    *(float *)D_004CA550 = t9;
    *(float *)(D_004CA550 + 0x4) = t9;
    *(float *)(D_004CA550 + 0x8) = t9;
    *(float *)(D_004CA550 + 0xC) = 1.0f;
    *(float *)D_004CA560 = 0.5f;
    *(float *)(D_004CA560 + 0x4) = 0.5f;
    *(float *)(D_004CA560 + 0x8) = 0.5f;
    *(float *)(D_004CA560 + 0xC) = 1.0f;
    *(float *)D_004CA5A0 = 0.5f;
    *(float *)(D_004CA5A0 + 0x4) = t13;
    *(float *)(D_004CA5A0 + 0x8) = 0.0f;
    *(float *)(D_004CA5A0 + 0xC) = 1.0f;
    *(float *)D_004CA5B0 = 1.0f;
    *(float *)(D_004CA5B0 + 0x4) = t2;
    *(float *)(D_004CA5B0 + 0x8) = t4;
    *(float *)(D_004CA5B0 + 0xC) = 1.0f;
    *(float *)D_004CA5C0 = 1.0f;
    *(float *)(D_004CA5C0 + 0x4) = 1.0f;
    *(float *)(D_004CA5C0 + 0x8) = 1.0f;
    *(float *)(D_004CA5C0 + 0xC) = 1.0f;
    UnkStruct_004DB0E0_q t14;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB0E0_q t15;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB0E0_q t16;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB0E0_q t17;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB0E0_q t18;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB0E0_q t19;   // lanes 0, 1, 2, 3: never written, copied as retail does
}
