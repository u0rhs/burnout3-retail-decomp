// NONMATCHING: func_004DA680 -- retail 142 / ours 117 instructions, 192 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DA680_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C9DE8[];
extern unsigned char D_004C9DEC[];
extern unsigned char D_004C9DF0[];
extern unsigned char D_004C9DF4[];
extern unsigned char D_004C9DF8[];
extern unsigned char D_004C9E00[];
extern unsigned char D_004C9E08[];
extern unsigned char D_004C9E10[];
extern unsigned char D_004C9E18[];
extern unsigned char D_004C9E1C[];
extern unsigned char D_004C9E20[];
extern unsigned char D_004C9E28[];
extern unsigned char D_004C9E30[];
extern unsigned char D_004C9E38[];
extern unsigned char D_004C9E40[];
extern unsigned char D_004C9E48[];
extern unsigned char D_004C9E50[];
extern unsigned char D_004C9E58[];
extern unsigned char D_004C9E60[];
extern unsigned char D_004C9E68[];
extern unsigned char D_004C9E70[];
extern unsigned char D_004C9E78[];
extern unsigned char D_004C9E80[];
extern unsigned char D_004C9E88[];
extern unsigned char D_004C9E8C[];
extern unsigned char D_004C9E90[];
extern unsigned char D_004C9E94[];
extern unsigned char D_004C9E98[];
extern unsigned char D_004C9EA0[];
extern unsigned char D_004C9EB0[];
extern unsigned char D_004C9EF0[];
extern unsigned char D_004E08B0[];
extern unsigned char D_004E0924[];
extern unsigned char D_004E0A3C[];
extern unsigned char D_004E0A40[];
extern unsigned char D_004E0A44[];

// 0x004DA680
extern "C" void func_004DA680()
{
    *(float *)D_004C9DEC = 40.0f;
    *(float *)D_004C9DE8 = 256.0f;
    *(float *)D_004C9DF0 = 256.0f;
    float t1 = 30.0f + 256.0f;
    *(float *)D_004C9DF4 = 40.0f;
    *(float *)D_004C9E1C = 232.0f;
    *(float *)D_004C9DF8 = t1;
    float t2 = 30.0f + t1;
    *(float *)D_004C9E88 = 64.0f;
    float t3 = *(float *)D_004E08B0;
    float t4 = 0.5f * t2;
    *(float *)D_004C9E00 = t4;
    float t5 = 16.0f + 256.0f;
    *(float *)D_004C9E8C = 32.0f;
    *(float *)D_004C9E90 = 18.0f;
    float t6 = 30.0f + t5;
    *(float *)D_004C9E94 = 18.0f;
    *(float *)D_004C9EA0 = 1.0f;
    *(float *)(D_004C9EA0 + 0x4) = 1.0f;
    *(float *)(D_004C9EA0 + 0x8) = 1.0f;
    *(float *)(D_004C9EA0 + 0xC) = 1.0f;
    float t7 = (float)610 - t6;
    *(float *)D_004C9EB0 = 0.0f;
    *(float *)(D_004C9EB0 + 0x4) = 0.0f;
    *(float *)(D_004C9EB0 + 0x8) = 0.0f;
    *(float *)(D_004C9EB0 + 0xC) = 1.0f;
    float t8 = t7 - 30.0f;
    float t9 = t3 * t8;
    *(float *)D_004C9E08 = t6;
    float t10 = 15.0f + t6;
    float t11 = *(float *)D_004E0A3C;
    float t12 = *(float *)D_004E0924;
    float t13 = *(float *)D_004E0A40;
    *(float *)D_004C9EF0 = 1.0f;
    *(float *)(D_004C9EF0 + 0x4) = 1.0f;
    *(float *)(D_004C9EF0 + 0x8) = 1.0f;
    *(float *)(D_004C9EF0 + 0xC) = 0.0f;
    *(float *)D_004C9E18 = t7;
    *(float *)D_004C9E10 = t7;
    UnkStruct_004DA680_q t14;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DA680_q t15;   // lanes 0, 1, 2, 3: never written, copied as retail does
    float t16 = t11 * t8;
    UnkStruct_004DA680_q t17;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DA680_q t18;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DA680_q t19;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DA680_q t20;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DA680_q t21;   // lanes 0, 1, 2, 3: never written, copied as retail does
    float t22 = 10.0f + t8;
    *(float *)D_004C9E98 = t22;
    float t23 = *(float *)D_004E0A44;
    float t24 = t12 * t8;
    *(float *)D_004C9E50 = t16;
    float t25 = t23 * t8;
    *(float *)D_004C9E60 = t24;
    float t26 = t10 + t9;
    float t27 = t13 * t8;
    float t28 = t10 + t24;
    *(float *)D_004C9E20 = t8;
    *(float *)D_004C9E28 = t10;
    UnkStruct_004DA680_q t29;   // lanes 0, 1, 2, 3: never written, copied as retail does
    *(float *)D_004C9E38 = t26;
    UnkStruct_004DA680_q t30;   // lanes 0, 1, 2, 3: never written, copied as retail does
    *(float *)D_004C9E80 = t25;
    float t31 = t26 + t9;
    float t32 = t28 + t27;
    *(float *)D_004C9E58 = t10;
    *(float *)D_004C9E30 = t9;
    *(float *)D_004C9E40 = t9;
    *(float *)D_004C9E68 = t28;
    *(float *)D_004C9E48 = t31;
    *(float *)D_004C9E70 = t27;
    *(float *)D_004C9E78 = t32;
}
