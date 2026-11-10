// NONMATCHING: func_004DCD10 -- retail 97 / ours 106 instructions, 152 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D2050[];
extern unsigned char D_004D2060[];
extern unsigned char D_004D2070[];
extern unsigned char D_004D2080[];
extern unsigned char D_004D2090[];
extern unsigned char D_004D2094[];
extern unsigned char D_004D2098[];
extern unsigned char D_004D20A0[];
extern unsigned char D_004D20A4[];
extern unsigned char D_004D20A8[];
extern unsigned char D_004D20B0[];
extern unsigned char D_004D20B4[];
extern unsigned char D_004D20B8[];
extern unsigned char D_004D20C0[];
extern unsigned char D_004D20C4[];
extern unsigned char D_004D20C8[];
extern unsigned char D_004D20D0[];
extern unsigned char D_004D20D4[];
extern unsigned char D_004D20D8[];
extern unsigned char D_004D20E0[];
extern unsigned char D_004D20E4[];
extern unsigned char D_004E06A8[];
extern unsigned char D_004E0AF8[];
extern unsigned char D_004E0AFC[];
extern unsigned char D_004E0B00[];
extern unsigned char D_004E0B04[];
extern unsigned char D_004E0B08[];
extern unsigned char D_004E0B0C[];

// 0x004DCD10
extern "C" void func_004DCD10()
{
    float t1 = *(float *)D_004E0AF8;
    float t2 = *(float *)D_004E0AFC;
    float t3 = *(float *)D_004D20A0;
    float t4 = *(float *)D_004E0B00;
    float t5 = *(float *)D_004E0B04;
    float t6 = *(float *)D_004E0B08;
    float t7 = *(float *)D_004E0B0C;
    float t8 = *(float *)D_004D20A4;
    float t9 = *(float *)D_004E06A8;
    *(float *)D_004D2050 = t2;
    *(float *)(D_004D2050 + 0x4) = t4;
    *(float *)(D_004D2050 + 0x8) = t5;
    *(float *)(D_004D2050 + 0xC) = 1.0f;
    float t10 = *(float *)D_004D2090;
    float t11 = *(float *)D_004D20A8;
    float t12 = 80.0f + t8;
    *(float *)D_004D2060 = t1;
    *(float *)(D_004D2060 + 0x4) = t6;
    *(float *)(D_004D2060 + 0x8) = t7;
    *(float *)(D_004D2060 + 0xC) = 1.0f;
    *(float *)D_004D20B4 = t12;
    *(float *)D_004D2070 = 0.0f;
    *(float *)(D_004D2070 + 0x4) = 0.0f;
    *(float *)(D_004D2070 + 0x8) = 0.0f;
    *(float *)(D_004D2070 + 0xC) = t9;
    float t13 = 47.5f + t10;
    *(float *)D_004D2080 = 0.0f;
    *(float *)(D_004D2080 + 0x4) = 0.0f;
    *(float *)(D_004D2080 + 0x8) = 0.0f;
    *(float *)(D_004D2080 + 0xC) = 0.0f;
    float t14 = 80.0f + t11;
    float t15 = 80.0f + t3;
    *(float *)D_004D20B0 = t15;
    float t16 = *(float *)D_004D2094;
    float t17 = t13 - 33.0f;
    *(float *)D_004D20B8 = t14;
    float t18 = 47.5f + t16;
    *(float *)D_004D20E4 = 76.0f;
    float t19 = t18 - 33.0f;
    *(float *)D_004D20C4 = t19;
    *(float *)D_004D20C0 = t17;
    float t20 = 8.0f + t3;
    float t21 = *(float *)D_004D2098;
    *(float *)D_004D20D0 = t20;
    *(float *)D_004D20E0 = (float)610;
    float t22 = 47.5f + t21;
    float t23 = t22 - 33.0f;
    *(float *)D_004D20C8 = t23;
    float t24 = 8.0f + t8;
    *(float *)D_004D20D4 = t24;
    float t25 = 8.0f + t11;
    *(float *)D_004D20D8 = t25;
}
