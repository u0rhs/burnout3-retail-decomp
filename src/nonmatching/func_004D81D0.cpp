// NONMATCHING: func_004D81D0 -- retail 86 / ours 97 instructions, 151 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5400[];
extern unsigned char D_004C5404[];
extern unsigned char D_004C5408[];
extern unsigned char D_004C540C[];
extern unsigned char D_004C5410[];
extern unsigned char D_004C5414[];
extern unsigned char D_004C5418[];
extern unsigned char D_004C541C[];
extern unsigned char D_004C5420[];
extern unsigned char D_004C5424[];
extern unsigned char D_004C5428[];
extern unsigned char D_004C542C[];
extern unsigned char D_004C5430[];
extern unsigned char D_004C5434[];
extern unsigned char D_004C5440[];
extern unsigned char D_004C5444[];
extern unsigned char D_004C5448[];
extern unsigned char D_004C544C[];
extern unsigned char D_004C5450[];
extern unsigned char D_004C5454[];
extern unsigned char D_004C5458[];
extern unsigned char D_004C545C[];
extern unsigned char D_004C5460[];
extern unsigned char D_004C5464[];
extern unsigned char D_004E0B44[];
extern unsigned char D_004E2D68[];
extern unsigned char D_004E2D6C[];
extern unsigned char D_004E2D70[];
extern unsigned char D_004E2D74[];
extern unsigned char D_004E2D78[];
extern unsigned char D_004E2D7C[];
extern unsigned char D_004E2D80[];
extern unsigned char D_004E2D84[];
extern unsigned char D_004E2D88[];
extern unsigned char D_004E2D8C[];
extern unsigned char D_01EA31C0[];
extern unsigned char D_01EA31D0[];

// 0x004D81D0
extern "C" void func_004D81D0()
{
    *(float *)D_004C5400 = 336.0f;
    *(float *)D_004C5404 = 272.0f;
    *(float *)D_004E2D7C = 272.0f;
    *(float *)D_004C5408 = 48.0f;
    *(float *)D_004E2D68 = 450.0f;
    *(float *)D_004C5410 = 0.0f;
    *(float *)D_004E2D6C = 215.0f;
    *(float *)D_004C5414 = 0.0f;
    *(float *)D_004C5418 = 0.25f;
    float t1 = *(float *)D_004E0B44;
    *(float *)D_004E2D78 = 240.0f;
    *(float *)D_004C541C = 0.5f;
    *(float *)D_004C5420 = 0.25f;
    *(float *)D_004C5424 = 0.0f;
    *(float *)D_004C5428 = 0.0f;
    *(float *)D_004C540C = t1;
    *(float *)D_004C542C = 0.5f;
    *(float *)D_004E2D88 = 1.0f;
    *(float *)D_004C5430 = 0.5f;
    *(float *)D_004E2D8C = 1.0f;
    *(float *)D_004C5434 = 0.0f;
    *(float *)D_004E2D70 = 0.5f;
    *(float *)D_004C5440 = 0.25f;
    *(float *)D_004E2D74 = 0.5f;
    *(float *)D_004C5444 = 0.5f;
    *(float *)D_004C5448 = 0.5f;
    *(float *)D_004C544C = 1.0f;
    *(float *)D_004C5450 = 0.5f;
    *(float *)D_004C5454 = 0.5f;
    *(float *)D_004E2D80 = 0.0f;
    *(float *)D_004C5458 = 0.25f;
    *(float *)D_004E2D84 = 0.0f;
    *(float *)D_004C545C = 1.0f;
    *(float *)D_004C5460 = 0.75f;
    *(float *)D_004C5464 = 0.5f;
    *(float *)D_01EA31C0 = 1.0f;
    *(float *)(D_01EA31C0 + 0x4) = 1.0f;
    *(float *)(D_01EA31C0 + 0x8) = 1.0f;
    *(float *)(D_01EA31C0 + 0xC) = 1.0f;
    *(float *)D_01EA31D0 = 0.0f;
    *(float *)(D_01EA31D0 + 0x4) = 0.0f;
    *(float *)(D_01EA31D0 + 0x8) = 0.0f;
    *(float *)(D_01EA31D0 + 0xC) = 0.0f;
}
