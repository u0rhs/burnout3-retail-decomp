// NONMATCHING: func_004D55F0 -- retail 168 / ours 168 instructions, 314 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D55F0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004B77F8[];
extern unsigned char D_004B77FC[];
extern unsigned char D_004B7800[];
extern unsigned char D_004B7810[];
extern unsigned char D_004B7820[];
extern unsigned char D_004B7830[];
extern unsigned char D_004B7840[];
extern unsigned char D_004B7850[];
extern unsigned char D_004B7860[];
extern unsigned char D_004B7870[];
extern unsigned char D_004B7880[];
extern unsigned char D_004B78B0[];
extern unsigned char D_004B78C0[];
extern unsigned char D_004B78D0[];
extern unsigned char D_004B7900[];
extern unsigned char D_004B7904[];
extern unsigned char D_004B7908[];
extern unsigned char D_004B790C[];
extern unsigned char D_004B7910[];
extern unsigned char D_004B7914[];
extern unsigned char D_004B7918[];
extern unsigned char D_004B791C[];
extern unsigned char D_004B7920[];
extern unsigned char D_004B7924[];
extern unsigned char D_004B7928[];
extern unsigned char D_004B792C[];
extern unsigned char D_004B7930[];
extern unsigned char D_004B7940[];
extern unsigned char D_004B7944[];
extern unsigned char D_004B7948[];
extern unsigned char D_004E0688[];
extern unsigned char D_004E06AC[];
extern unsigned char D_004E06C0[];
extern unsigned char D_004E06DC[];
extern unsigned char D_004E0784[];
extern unsigned char D_004E08B0[];
extern unsigned char D_004E08D0[];
extern unsigned char D_004E08D4[];
extern unsigned char krHUDBoostBarMessageIndentX[];

// 0x004D55F0
extern "C" void func_004D55F0()
{
    float t1 = *(float *)D_004E06DC;
    float t2 = *(float *)D_004E06C0;
    float t3 = *(float *)D_004E08B0;
    float t4 = *(float *)D_004E06AC;
    float t5 = *(float *)D_004E08D0;
    *(float *)D_004B7900 = 64.0f;
    *(float *)D_004B7908 = 64.0f;
    *(float *)D_004B7904 = 32.0f;
    *(float *)D_004B790C = 32.0f;
    *(float *)D_004B7910 = 7.0f;
    float t6 = *(float *)D_004E0784;
    *(float *)D_004B7914 = 29.0f;
    *(float *)D_004B7918 = 4.0f;
    float t7 = *(float *)D_004E0688;
    *(float *)D_004B791C = 4.0f;
    *(float *)D_004B7920 = 1.0f;
    float t8 = *(float *)D_004E08D4;
    *(float *)D_004B7924 = 21.0f;
    *(float *)D_004B77F8 = 360.0f;
    *(float *)D_004B7928 = 6.0f;
    *(float *)D_004B792C = 21.0f;
    *(float *)D_004B77FC = 28.0f;
    float t9 = 3.0f + 29.0f;
    *(float *)krHUDBoostBarMessageIndentX = 4.0f;
    *(float *)D_004B7940 = 210.0f;
    *(float *)D_004B7930 = t9;
    float t10 = 1.0f / 210.0f;
    *(float *)D_004B7944 = 26.0f;
    *(float *)D_004B7800 = 1.0f;
    *(float *)(D_004B7800 + 0x4) = 1.0f;
    *(float *)(D_004B7800 + 0x8) = 1.0f;
    *(float *)(D_004B7800 + 0xC) = 1.0f;
    *(float *)D_004B7810 = 1.0f;
    *(float *)(D_004B7810 + 0x4) = t1;
    *(float *)(D_004B7810 + 0x8) = t2;
    *(float *)(D_004B7810 + 0xC) = t1;
    *(float *)D_004B7820 = 1.0f;
    *(float *)(D_004B7820 + 0x4) = t4;
    *(float *)(D_004B7820 + 0x8) = t1;
    *(float *)(D_004B7820 + 0xC) = 0.0f;
    *(float *)D_004B7830 = 1.0f;
    *(float *)(D_004B7830 + 0x4) = 1.0f;
    *(float *)(D_004B7830 + 0x8) = 1.0f;
    *(float *)(D_004B7830 + 0xC) = 0.5f;
    *(float *)D_004B7840 = 1.0f;
    *(float *)(D_004B7840 + 0x4) = 1.0f;
    *(float *)(D_004B7840 + 0x8) = 0.0f;
    *(float *)(D_004B7840 + 0xC) = t5;
    *(float *)D_004B7850 = 1.0f;
    *(float *)(D_004B7850 + 0x4) = 1.0f;
    *(float *)(D_004B7850 + 0x8) = 0.0f;
    *(float *)(D_004B7850 + 0xC) = t1;
    float t11 = 1.0f / 26.0f;
    *(float *)D_004B7860 = 1.0f;
    *(float *)(D_004B7860 + 0x4) = t1;
    *(float *)(D_004B7860 + 0x8) = t3;
    *(float *)(D_004B7860 + 0xC) = 0.0f;
    *(float *)D_004B7870 = 1.0f;
    *(float *)(D_004B7870 + 0x4) = t6;
    *(float *)(D_004B7870 + 0x8) = t7;
    *(float *)(D_004B7870 + 0xC) = t3;
    *(float *)D_004B7880 = 1.0f;
    *(float *)(D_004B7880 + 0x4) = t2;
    *(float *)(D_004B7880 + 0x8) = 0.0f;
    *(float *)(D_004B7880 + 0xC) = 0.0f;
    *(float *)D_004B78B0 = 0.0f;
    *(float *)(D_004B78B0 + 0x4) = 0.0f;
    *(float *)(D_004B78B0 + 0x8) = 0.0f;
    *(float *)(D_004B78B0 + 0xC) = 0.0f;
    *(float *)D_004B78C0 = 0.0f;
    *(float *)(D_004B78C0 + 0x4) = 0.0f;
    *(float *)(D_004B78C0 + 0x8) = 0.0f;
    *(float *)(D_004B78C0 + 0xC) = 0.5f;
    *(float *)D_004B78D0 = t8;
    *(float *)(D_004B78D0 + 0x4) = t8;
    *(float *)(D_004B78D0 + 0x8) = t8;
    *(float *)(D_004B78D0 + 0xC) = 0.0f;
    *(float *)D_004B7948 = t10;
    *(float *)(D_004B7948 + 0x4) = t11;
    UnkStruct_004D55F0_q t12;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D55F0_q t13;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D55F0_q t14;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D55F0_q t15;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D55F0_q t16;   // lanes 0, 1, 2, 3: never written, copied as retail does
}
