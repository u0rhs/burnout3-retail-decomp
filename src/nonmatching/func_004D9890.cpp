// NONMATCHING: func_004D9890 -- retail 118 / ours 130 instructions, 145 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C93B0[];
extern unsigned char D_004C93C0[];
extern unsigned char D_004C93D0[];
extern unsigned char D_004C93E0[];
extern unsigned char D_004C93F0[];
extern unsigned char D_004C93F8[];
extern unsigned char D_004C9400[];
extern unsigned char D_004C9404[];
extern unsigned char D_004C9408[];
extern unsigned char D_004C940C[];
extern unsigned char D_004C9410[];
extern unsigned char D_004C9418[];
extern unsigned char D_004C9420[];
extern unsigned char D_004C9428[];
extern unsigned char D_004E1E3C[];
extern unsigned char D_004E1E40[];
extern unsigned char D_004E1E44[];
extern unsigned char D_004E1E48[];
extern unsigned char D_004E1E4C[];
extern unsigned char D_004E2E58[];
extern unsigned char D_004E2E5C[];
extern unsigned char D_004E2E60[];
extern "C" void _CalculateUV__15CB3MenuImageUVsFffffffUi(void *, int, float, float, float, float, float, float);

// 0x004D9890
extern "C" void func_004D9890()
{
    float t1 = *(float *)D_004E1E40;
    float t2 = *(float *)D_004E1E3C;
    float t3 = *(float *)D_004E1E44;
    float t4 = *(float *)D_004E1E48;
    float t5 = *(float *)D_004E1E3C;
    float t6 = *(float *)D_004E1E40;
    *(float *)D_004E2E58 = t1;
    *(float *)D_004E2E5C = t2;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C93B0, 0x0, t3, t4, t5, t6, 32.0f, 16.0f);
    float t7 = *(float *)D_004E1E44;
    float t8 = *(float *)D_004E1E48;
    float t9 = *(float *)D_004E1E3C;
    float t10 = *(float *)D_004E1E40;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C93C0, 0x1, t7, t8, t9, t10, 32.0f, 16.0f);
    float t11 = *(float *)D_004E1E4C;
    float t12 = *(float *)D_004E2E60;
    float t13 = *(float *)D_004E2E58;
    float t14 = *(float *)D_004E2E5C;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C93D0, 0x2, t11, t12, t13, t14, 32.0f, 16.0f);
    float t15 = *(float *)D_004E1E4C;
    float t16 = *(float *)D_004E2E60;
    float t17 = *(float *)D_004E2E58;
    float t18 = *(float *)D_004E2E5C;
    _CalculateUV__15CB3MenuImageUVsFffffffUi(D_004C93E0, 0x0, t15, t16, t17, t18, 32.0f, 16.0f);
    float t19 = *(float *)D_004E1E3C;
    *(float *)D_004C9400 = 0.0f;
    float t20 = *(float *)D_004E1E3C;
    *(float *)D_004C940C = 0.0f;
    float t21 = *(float *)D_004E1E40;
    float t22 = 32.0f - t19;
    float t23 = t20 * 0.03125f;
    float t24 = t22 / 32.0f;
    float t25 = *(float *)D_004E1E40;
    float t26 = *(float *)D_004E2E58;
    float t27 = *(float *)D_004E2E5C;
    *(float *)D_004C93F8 = t24;
    *(float *)D_004C9404 = t24;
    *(float *)D_004C9408 = t24;
    float t28 = t25 * 0.03125f;
    float t29 = t22 * 0.03125f;
    *(float *)D_004C93F0 = t22;
    float t30 = *(float *)D_004E2E58;
    float t31 = t26 * 0.03125f;
    float t32 = t27 * 0.03125f;
    *(float *)D_004C9410 = t23;
    *(float *)(D_004C9410 + 0x4) = t28;
    float t33 = *(float *)D_004E2E5C;
    float t34 = 32.0f - t21;
    float t35 = 32.0f - t30;
    float t36 = 0.5f * t34;
    float t37 = t36 * 0.03125f;
    float t38 = 0.5f * t35;
    float t39 = 32.0f - t33;
    float t40 = t38 * 0.03125f;
    float t41 = t39 * 0.03125f;
    *(float *)D_004C9418 = t31;
    *(float *)(D_004C9418 + 0x4) = t32;
    *(float *)D_004C9420 = t29;
    *(float *)(D_004C9420 + 0x4) = t37;
    *(float *)D_004C9428 = t40;
    *(float *)(D_004C9428 + 0x4) = t41;
}
