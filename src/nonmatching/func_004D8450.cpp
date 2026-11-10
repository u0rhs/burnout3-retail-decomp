// NONMATCHING: func_004D8450 -- retail 58 / ours 57 instructions, 59 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5618[];
extern unsigned char D_004C561C[];
extern unsigned char D_004C5620[];
extern unsigned char D_004C5624[];
extern unsigned char D_004C5628[];
extern unsigned char D_004C562C[];
extern unsigned char D_004C5630[];
extern unsigned char D_004C5634[];
extern unsigned char D_004C5638[];
extern unsigned char D_004C563C[];
extern unsigned char D_004C5640[];
extern unsigned char D_004C5644[];
extern unsigned char D_004C5648[];
extern unsigned char D_004C5650[];
extern unsigned char D_004C5654[];
extern unsigned char D_004C5658[];
extern unsigned char D_004C565C[];
extern unsigned char D_004C5660[];

// 0x004D8450
extern "C" void func_004D8450()
{
    *(float *)D_004C5618 = 64.0f;
    *(float *)D_004C561C = 112.0f;
    *(float *)D_004C5624 = 241.0f;
    *(float *)D_004C562C = 240.0f;
    *(float *)D_004C5628 = 320.0f;
    *(float *)D_004C5630 = 64.0f;
    *(float *)D_004C5620 = (float)513;
    *(float *)D_004C5634 = 80.0f;
    *(float *)D_004C5638 = (float)513;
    *(float *)D_004C563C = (float)321;
    *(float *)D_004C5640 = 320.0f;
    *(float *)D_004C5644 = 240.0f;
    float t1 = (float)513 - 32.0f;
    *(float *)D_004C5658 = 42.0f;
    *(float *)D_004C5650 = 4.0f;
    *(float *)D_004C5648 = t1;
    *(float *)D_004C5654 = 4.0f;
    *(float *)D_004C565C = 32.0f;
    float t2 = 24.0f + 4.0f;
    *(float *)D_004C5660 = t2;
}
