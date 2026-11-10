// NONMATCHING: func_004D5E50 -- retail 36 / ours 41 instructions, 42 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_0049C24C[];
extern unsigned char D_0049C258[];
extern unsigned char D_0049C264[];
extern unsigned char D_0049C270[];
extern unsigned char D_0049C27C[];
extern unsigned char D_0049C288[];
extern unsigned char D_0049C294[];
extern unsigned char D_0049C2A0[];
extern unsigned char D_0049C2AC[];
extern unsigned char D_0049C2B8[];
extern unsigned char D_0049C2C4[];
extern unsigned char D_0049C2D0[];
extern unsigned char D_0049C2DC[];
extern unsigned char D_0049C2E8[];
extern unsigned char D_004E1B6C[];
extern unsigned char D_004E1B70[];
extern unsigned char _grPitcherAttackTime[];
extern unsigned char _grPitcherDecayTime[];

// 0x004D5E50
extern "C" void func_004D5E50()
{
    float t1 = *(float *)D_004E1B6C;
    float t2 = *(float *)_grPitcherAttackTime;
    *(float *)D_0049C24C = t1;
    float t3 = 3.0f - t2;
    *(float *)D_0049C258 = t1;
    *(float *)D_0049C264 = t1;
    *(float *)D_0049C270 = t1;
    *(float *)D_0049C27C = t1;
    *(float *)D_0049C288 = t1;
    *(float *)D_0049C294 = t1;
    *(float *)D_0049C2A0 = t1;
    *(float *)D_0049C2AC = t1;
    *(float *)D_0049C2B8 = t1;
    *(float *)D_0049C2C4 = t1;
    *(float *)D_0049C2D0 = t1;
    *(float *)D_0049C2DC = t1;
    float t4 = *(float *)D_004E1B70;
    *(float *)_grPitcherDecayTime = t3;
    *(float *)D_0049C2E8 = t4;
}
