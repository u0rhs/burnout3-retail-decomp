// NONMATCHING: func_004DC7F0 -- retail 82 / ours 83 instructions, 106 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004D16D8[];
extern unsigned char D_004D16DC[];
extern unsigned char D_004D16E0[];
extern unsigned char D_004D16E4[];
extern unsigned char D_004D16E8[];
extern unsigned char D_004D16EC[];
extern unsigned char D_004D16F0[];
extern unsigned char D_004D16F4[];
extern unsigned char D_004D16F8[];
extern unsigned char D_004D16FC[];
extern unsigned char D_004D1700[];
extern unsigned char D_004D1704[];
extern unsigned char D_004D1708[];
extern unsigned char D_004D170C[];
extern unsigned char D_004D1710[];
extern unsigned char D_004D1714[];
extern unsigned char D_004D1718[];
extern unsigned char D_004D171C[];
extern unsigned char D_004D1720[];
extern unsigned char D_004D1724[];
extern unsigned char D_004D1728[];
extern unsigned char D_004D172C[];
extern unsigned char D_004D1730[];
extern unsigned char D_004D1734[];
extern unsigned char D_004D1738[];
extern unsigned char D_004D173C[];
extern unsigned char D_004D1740[];
extern unsigned char D_004D1750[];
extern unsigned char D_004E09BC[];

// 0x004DC7F0
extern "C" void func_004DC7F0()
{
    *(float *)D_004D16D8 = 0.5f;
    *(float *)D_004D16DC = 0.5f;
    *(float *)D_004D16E0 = 96.0f;
    *(float *)D_004D16E4 = 97.0f;
    *(float *)D_004D16E8 = 96.0f;
    *(float *)D_004D1700 = 0.3125f;
    *(float *)D_004D1710 = 0.3125f;
    *(float *)D_004D16F0 = 24.0f;
    *(float *)D_004D1724 = 0.0f;
    *(float *)D_004D16F4 = 12.0f;
    *(float *)D_004D16F8 = 0.0f;
    *(float *)D_004D16FC = 0.0f;
    *(float *)D_004D16EC = (float)367;
    *(float *)D_004D1704 = 0.0f;
    float t1 = *(float *)D_004E09BC;
    *(float *)D_004D172C = 0.0f;
    *(float *)D_004D1708 = 0.0f;
    *(float *)D_004D170C = 0.34375f;
    *(float *)D_004D1714 = 0.34375f;
    *(float *)D_004D1718 = 12.0f;
    *(float *)D_004D171C = 24.0f;
    *(float *)D_004D1720 = 0.3125f;
    *(float *)D_004D1728 = 0.5f;
    *(float *)D_004D1730 = 0.3125f;
    *(float *)D_004D1734 = 0.65625f;
    *(float *)D_004D1738 = 0.5f;
    *(float *)D_004D173C = 0.65625f;
    *(float *)D_004D1740 = 0.0f;
    *(float *)(D_004D1740 + 0x4) = 0.0f;
    *(float *)(D_004D1740 + 0x8) = 0.0f;
    *(float *)(D_004D1740 + 0xC) = t1;
    *(float *)D_004D1750 = t1;
    *(float *)(D_004D1750 + 0x4) = t1;
    *(float *)(D_004D1750 + 0x8) = t1;
    *(float *)(D_004D1750 + 0xC) = 1.0f;
}
