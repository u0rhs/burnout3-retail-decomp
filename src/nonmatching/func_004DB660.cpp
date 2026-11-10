// NONMATCHING: func_004DB660 -- retail 140 / ours 228 instructions, 328 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DB660_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004CACF0[];
extern unsigned char D_004CAD00[];
extern unsigned char D_004CAD10[];
extern unsigned char D_004CAD20[];
extern unsigned char D_004CAD30[];
extern unsigned char D_004CAD40[];
extern unsigned char D_004CAD50[];
extern unsigned char D_004CAD60[];
extern unsigned char D_004CAD70[];
extern unsigned char D_004CAD80[];
extern unsigned char D_004CAD90[];
extern unsigned char D_004CADA0[];
extern unsigned char D_004CADB0[];
extern unsigned char D_004CADC0[];
extern unsigned char D_004CADD0[];
extern unsigned char D_004CADE0[];
extern unsigned char D_004E0698[];
extern unsigned char D_004E06A8[];
extern unsigned char D_004E06AC[];
extern unsigned char D_004E06B4[];
extern unsigned char D_01EB5B40[];
extern "C" void __ct__Q29GtMathPs26CGtV3dFv();   // its address is stored
extern "C" void func_00100270(void *, void *, int, int, int);

// 0x004DB660
extern "C" void func_004DB660()
{
    float t1 = *(float *)D_004E06AC;
    float t2 = *(float *)D_004E0698;
    float t3 = *(float *)D_004E06A8;
    UnkStruct_004DB660_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = t2;
    *(float *)&t4.w[1] = 2.0f;
    *(float *)&t4.w[2] = 0.5f;
    float t5 = *(float *)D_004E06B4;
    UnkStruct_004DB660_q t6;   // lanes 3: never written, copied as retail does
    *(float *)&t6.w[0] = 0.0f;
    *(float *)&t6.w[1] = 0.5f;
    *(float *)&t6.w[2] = 0.0f;
    UnkStruct_004DB660_q t7;   // lanes 3: never written, copied as retail does
    *(float *)&t7.w[0] = 0.75f;
    *(float *)&t7.w[1] = 2.0f;
    *(float *)&t7.w[2] = t3;
    *(UnkStruct_004DB660_q *)D_004CAD00 = t6;
    UnkStruct_004DB660_q t8;   // lanes 3: never written, copied as retail does
    *(float *)&t8.w[0] = 0.75f;
    *(float *)&t8.w[1] = 1.0f;
    *(float *)&t8.w[2] = 1.0f;
    *(UnkStruct_004DB660_q *)D_004CAD20 = t8;
    UnkStruct_004DB660_q t9;   // lanes 3: never written, copied as retail does
    *(float *)&t9.w[0] = t1;
    *(float *)&t9.w[1] = t1;
    *(float *)&t9.w[2] = t1;
    UnkStruct_004DB660_q t10;   // lanes 3: never written, copied as retail does
    *(float *)&t10.w[0] = 0.0f;
    *(float *)&t10.w[1] = t5;
    *(float *)&t10.w[2] = 0.0f;
    *(UnkStruct_004DB660_q *)D_004CAD10 = t7;
    UnkStruct_004DB660_q t11;   // lanes 3: never written, copied as retail does
    *(float *)&t11.w[0] = 1.0f;
    *(float *)&t11.w[1] = 4.0f;
    *(float *)&t11.w[2] = 1.0f;
    UnkStruct_004DB660_q t12;   // lanes 3: never written, copied as retail does
    *(float *)&t12.w[0] = 1.0f;
    *(float *)&t12.w[1] = 0.0f;
    *(float *)&t12.w[2] = 1.0f;
    *(UnkStruct_004DB660_q *)D_004CAD30 = t9;
    UnkStruct_004DB660_q t13;   // lanes 3: never written, copied as retail does
    *(float *)&t13.w[0] = 1.0f;
    *(float *)&t13.w[1] = 0.0f;
    *(float *)&t13.w[2] = 0.0f;
    *(UnkStruct_004DB660_q *)D_004CAD40 = t10;
    UnkStruct_004DB660_q t14;   // lanes 3: never written, copied as retail does
    *(float *)&t14.w[0] = 0.0f;
    *(float *)&t14.w[1] = 1.0f;
    *(float *)&t14.w[2] = 0.0f;
    *(UnkStruct_004DB660_q *)D_004CACF0 = t4;
    UnkStruct_004DB660_q t15;   // lanes 3: never written, copied as retail does
    *(float *)&t15.w[0] = 0.0f;
    *(float *)&t15.w[1] = 0.0f;
    *(float *)&t15.w[2] = 1.0f;
    UnkStruct_004DB660_q t16;   // lanes 3: never written, copied as retail does
    *(float *)&t16.w[0] = 1.0f;
    *(float *)&t16.w[1] = 1.0f;
    *(float *)&t16.w[2] = 1.0f;
    *(UnkStruct_004DB660_q *)D_004CAD70 = t13;
    UnkStruct_004DB660_q t17;   // lanes 3: never written, copied as retail does
    *(float *)&t17.w[0] = 1.0f;
    *(float *)&t17.w[1] = 0.0f;
    *(float *)&t17.w[2] = 0.5f;
    *(UnkStruct_004DB660_q *)D_004CAD80 = t14;
    UnkStruct_004DB660_q t18;   // lanes 3: never written, copied as retail does
    *(float *)&t18.w[0] = 1.0f;
    *(float *)&t18.w[1] = 1.0f;
    *(float *)&t18.w[2] = 0.5f;
    *(UnkStruct_004DB660_q *)D_004CAD90 = t15;
    UnkStruct_004DB660_q t19;   // lanes 3: never written, copied as retail does
    *(float *)&t19.w[0] = 0.0f;
    *(float *)&t19.w[1] = 0.0f;
    *(float *)&t19.w[2] = 0.5f;
    *(UnkStruct_004DB660_q *)D_004CADA0 = t16;
    UnkStruct_004DB660_q t20;   // lanes 3: never written, copied as retail does
    *(float *)&t20.w[0] = 0.0f;
    *(float *)&t20.w[1] = 1.0f;
    *(float *)&t20.w[2] = 0.5f;
    *(UnkStruct_004DB660_q *)D_004CAD50 = t11;
    *(UnkStruct_004DB660_q *)D_004CAD60 = t12;
    *(UnkStruct_004DB660_q *)D_004CADB0 = t17;
    *(UnkStruct_004DB660_q *)D_004CADC0 = t18;
    *(UnkStruct_004DB660_q *)D_004CADD0 = t19;
    *(UnkStruct_004DB660_q *)D_004CADE0 = t20;
    func_00100270(D_01EB5B40, (unsigned char *)__ct__Q29GtMathPs26CGtV3dFv, 0x0, 0x10, 0x16);
    UnkStruct_004DB660_q t21;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t22;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t23;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t24;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t25;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t26;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t27;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t28;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004DB660_q t29;   // lanes 0, 1, 2, 3: never written, copied as retail does
}
