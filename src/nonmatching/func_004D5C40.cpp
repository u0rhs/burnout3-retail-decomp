// NONMATCHING: func_004D5C40 -- retail 78 / ours 133 instructions, 144 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D5C40_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004BBFB0[];
extern unsigned char D_004BBFC0[];
extern unsigned char D_004BBFD0[];
extern unsigned char D_004BBFE0[];
extern unsigned char D_004BBFF0[];
extern unsigned char D_004BC000[];
extern unsigned char D_004BC010[];
extern unsigned char D_004BC020[];
extern unsigned char D_004BC030[];
extern unsigned char D_004E0A9C[];
extern unsigned char D_004E0B74[];
extern unsigned char D_004E0C00[];
extern unsigned char D_004E0C2C[];
extern unsigned char D_004E0C30[];
extern unsigned char D_004E0C34[];
extern unsigned char D_004E0C38[];
extern unsigned char D_01D9D190[];

// 0x004D5C40
extern "C" void func_004D5C40()
{
    float t1 = *(float *)D_004E0C2C;
    float t2 = *(float *)D_004E0C30;
    float t3 = *(float *)D_004E0C34;
    float t4 = *(float *)D_004E0C38;
    float t5 = *(float *)D_004E0B74;
    float t6 = *(float *)D_004E0C00;
    float t7 = *(float *)D_004E0A9C;
    UnkStruct_004D5C40_q t8;   // lanes 3: never written, copied as retail does
    *(float *)&t8.w[0] = 0.0f;
    *(float *)&t8.w[1] = 1.0f;
    *(float *)&t8.w[2] = 0.0f;
    UnkStruct_004D5C40_q t9;   // lanes 3: never written, copied as retail does
    *(float *)&t9.w[0] = 0.0f;
    *(float *)&t9.w[1] = 0.5f;
    *(float *)&t9.w[2] = 0.0f;
    UnkStruct_004D5C40_q t10;   // lanes 3: never written, copied as retail does
    *(float *)&t10.w[0] = 1.5f;
    *(float *)&t10.w[1] = 1.5f;
    *(float *)&t10.w[2] = 1.5f;
    UnkStruct_004D5C40_q t11;   // lanes 3: never written, copied as retail does
    *(float *)&t11.w[0] = 1.0f;
    *(float *)&t11.w[1] = 1.0f;
    *(float *)&t11.w[2] = 1.0f;
    *(UnkStruct_004D5C40_q *)D_004BBFC0 = t8;
    UnkStruct_004D5C40_q t12;   // lanes 3: never written, copied as retail does
    *(float *)&t12.w[0] = t6;
    *(float *)&t12.w[1] = 0.0f;
    *(float *)&t12.w[2] = 0.0f;
    *(UnkStruct_004D5C40_q *)D_004BBFD0 = t9;
    UnkStruct_004D5C40_q t13;   // lanes 3: never written, copied as retail does
    *(float *)&t13.w[0] = t7;
    *(float *)&t13.w[1] = 0.0f;
    *(float *)&t13.w[2] = 0.0f;
    *(UnkStruct_004D5C40_q *)D_004BBFE0 = t10;
    UnkStruct_004D5C40_q t14;   // lanes 3: never written, copied as retail does
    *(float *)&t14.w[0] = 1.0f;
    *(float *)&t14.w[1] = t5;
    *(float *)&t14.w[2] = 0.0f;
    *(UnkStruct_004D5C40_q *)D_004BBFF0 = t11;
    UnkStruct_004D5C40_q t15;   // lanes 3: never written, copied as retail does
    *(float *)&t15.w[0] = t5;
    *(float *)&t15.w[1] = t5;
    *(float *)&t15.w[2] = t5;
    *(float *)D_01D9D190 = t1;
    *(float *)(D_01D9D190 + 0x4) = t2;
    *(float *)(D_01D9D190 + 0x8) = t3;
    *(float *)(D_01D9D190 + 0xC) = t4;
    *(float *)D_004BBFB0 = 8388608.0f;
    *(float *)(D_004BBFB0 + 0x4) = 8388608.0f;
    *(float *)(D_004BBFB0 + 0x8) = 8388608.0f;
    *(float *)(D_004BBFB0 + 0xC) = 8388608.0f;
    *(UnkStruct_004D5C40_q *)D_004BC000 = t12;
    *(UnkStruct_004D5C40_q *)D_004BC010 = t13;
    *(UnkStruct_004D5C40_q *)D_004BC020 = t14;
    *(UnkStruct_004D5C40_q *)D_004BC030 = t15;
    UnkStruct_004D5C40_q t16;   // lanes 0, 1, 2, 3: never written, copied as retail does
}
