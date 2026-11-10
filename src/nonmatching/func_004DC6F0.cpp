// NONMATCHING: func_004DC6F0 -- retail 62 / ours 86 instructions, 101 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DC6F0_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004D1560[];
extern unsigned char D_004D1564[];
extern unsigned char D_004D1568[];
extern unsigned char D_004D156C[];
extern unsigned char D_004D1570[];
extern unsigned char D_004D1574[];
extern unsigned char D_004D1580[];
extern unsigned char D_004D1590[];
extern unsigned char D_004D15A0[];
extern unsigned char D_004D15A4[];
extern unsigned char D_004D15A8[];
extern unsigned char D_004D15AC[];
extern unsigned char D_004D15B0[];
extern unsigned char D_004D15B4[];
extern unsigned char D_004D15B8[];
extern unsigned char D_004D15BC[];
extern unsigned char D_004D15C0[];
extern unsigned char D_004D15D0[];

// 0x004DC6F0
extern "C" void func_004DC6F0()
{
    *(float *)D_004D1560 = 0.0f;
    *(float *)D_004D1564 = 0.0f;
    *(float *)D_004D1568 = 0.0f;
    *(float *)D_004D156C = 64.0f;
    *(float *)D_004D1570 = 640.0f;
    *(float *)D_004D1574 = 352.0f;
    *(float *)D_004D15A0 = 0.0f;
    UnkStruct_004DC6F0_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 1.0f;
    *(float *)&t1.w[1] = 0.0f;
    *(float *)&t1.w[2] = 0.0f;
    *(float *)D_004D15A4 = 0.0f;
    *(float *)D_004D15A8 = 1.0f;
    *(float *)D_004D15AC = 0.0f;
    *(float *)D_004D15B0 = 0.0f;
    UnkStruct_004DC6F0_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 0.0f;
    *(float *)&t2.w[1] = 1.0f;
    *(float *)&t2.w[2] = 0.0f;
    *(float *)D_004D15B4 = 1.0f;
    *(float *)D_004D15B8 = 1.0f;
    *(float *)D_004D15BC = 1.0f;
    UnkStruct_004DC6F0_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = 12.0f;
    *(float *)&t3.w[1] = 1.0f;
    *(float *)&t3.w[2] = 6.0f;
    UnkStruct_004DC6F0_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = 8.0f;
    *(float *)&t4.w[1] = 1.0f;
    *(float *)&t4.w[2] = 6.0f;
    *(UnkStruct_004DC6F0_q *)D_004D1580 = t1;
    *(UnkStruct_004DC6F0_q *)D_004D1590 = t2;
    *(UnkStruct_004DC6F0_q *)D_004D15C0 = t3;
    *(UnkStruct_004DC6F0_q *)D_004D15D0 = t4;
}
