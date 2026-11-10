// NONMATCHING: func_004DC130 -- retail 93 / ours 93 instructions, 139 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004A5424[];
extern unsigned char D_004A542C[];
extern unsigned char D_004A5434[];
extern unsigned char D_004A543C[];
extern unsigned char D_004A5444[];
extern unsigned char D_004A544C[];
extern unsigned char D_004A5454[];
extern unsigned char D_004A545C[];
extern unsigned char D_004A5464[];
extern unsigned char D_004A546C[];
extern unsigned char D_004A5474[];
extern unsigned char D_004A547C[];
extern unsigned char D_004A5484[];
extern unsigned char D_004A548C[];
extern unsigned char D_004A5494[];
extern unsigned char D_004A549C[];
extern unsigned char D_004A54A4[];
extern unsigned char D_004A54AC[];
extern unsigned char D_004A54B4[];
extern unsigned char D_004A54BC[];
extern unsigned char D_004A54C4[];
extern unsigned char D_004A54CC[];
extern unsigned char D_004A54D4[];
extern unsigned char D_004A54DC[];
extern unsigned char D_004A54E4[];
extern unsigned char D_004A54EC[];
extern unsigned char D_004A54F4[];
extern unsigned char D_004A54FC[];
extern unsigned char D_004D17E0[];
extern unsigned char D_004D17E8[];
extern unsigned char D_004D17F0[];
extern unsigned char D_004D17F8[];
extern unsigned char D_004D1800[];
extern unsigned char D_004D1808[];
extern unsigned char D_004D1810[];
extern unsigned char D_004D1818[];
extern unsigned char D_004D1820[];
extern unsigned char D_004D1828[];
extern unsigned char D_004D1830[];
extern unsigned char D_004D1838[];
extern unsigned char D_004D1840[];
extern unsigned char D_004D1848[];
extern unsigned char D_004D1850[];
extern unsigned char D_004D1858[];
extern unsigned char D_004D1860[];
extern unsigned char D_004D1868[];

// 0x004DC130
extern "C" void func_004DC130()
{
    int t1 = *(int *)D_004D17E0;
    *(int *)D_004A5424 = t1;
    int t2 = *(int *)D_004D17F8;
    int t3 = *(int *)D_004D17E8;
    *(int *)D_004A542C = t2;
    int t4 = *(int *)D_004D17F0;
    *(int *)D_004A544C = t3;
    *(int *)D_004A5434 = t4;
    int t5 = *(int *)D_004D1808;
    *(int *)D_004A543C = t5;
    int t6 = *(int *)D_004D1800;
    *(int *)D_004A5464 = t3;
    int t7 = *(int *)D_004D1840;
    *(int *)D_004A5444 = t6;
    *(int *)D_004A5454 = t1;
    int t8 = *(int *)D_004D1838;
    *(int *)D_004A545C = t4;
    *(int *)D_004A548C = t7;
    int t9 = *(int *)D_004D1820;
    *(int *)D_004A5474 = t8;
    int t10 = *(int *)D_004D1810;
    *(int *)D_004A546C = t9;
    *(int *)D_004A547C = t10;
    int t11 = *(int *)D_004D1848;
    *(int *)D_004A5484 = t11;
    int t12 = *(int *)D_004D1828;
    int t13 = *(int *)D_004D1818;
    *(int *)D_004A5494 = t12;
    *(int *)D_004A54AC = t9;
    *(int *)D_004A54BC = t12;
    *(int *)D_004A54B4 = t10;
    int t14 = *(int *)D_004D1830;
    int t15 = *(int *)D_004D1860;
    *(int *)D_004A54A4 = t13;
    *(int *)D_004A549C = t14;
    *(int *)D_004A54C4 = t13;
    int t16 = *(int *)D_004D1868;
    int t17 = *(int *)D_004D1850;
    *(int *)D_004A54EC = t15;
    int t18 = *(int *)D_004D1858;
    *(int *)D_004A54CC = t15;
    *(int *)D_004A54D4 = t16;
    *(int *)D_004A54DC = t17;
    *(int *)D_004A54F4 = t17;
    *(int *)D_004A54E4 = t18;
    *(int *)D_004A54FC = t18;
}
