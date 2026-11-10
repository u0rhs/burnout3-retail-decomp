// NONMATCHING: func_004D9660 -- retail 39 / ours 39 instructions, 22 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C9148[];
extern unsigned char D_004C914C[];
extern unsigned char D_004C9150[];
extern unsigned char D_004C9154[];
extern unsigned char D_004C9158[];
extern unsigned char D_004C915C[];
extern unsigned char D_004C9160[];
extern unsigned char D_004C9164[];
extern unsigned char D_004C9168[];
extern unsigned char D_004C916C[];
extern unsigned char D_004C9170[];
extern unsigned char D_004C9174[];
extern unsigned char D_004C9178[];
extern unsigned char D_004C917C[];

// 0x004D9660
extern "C" void func_004D9660()
{
    *(float *)D_004C9148 = 320.0f;
    *(float *)D_004C914C = 168.0f;
    *(float *)D_004C9150 = 0.5f;
    *(float *)D_004C9154 = 0.5f;
    *(float *)D_004C9158 = 64.0f;
    *(float *)D_004C9160 = 0.0f;
    *(float *)D_004C915C = 112.0f;
    *(float *)D_004C9164 = 0.0f;
    *(float *)D_004C916C = 113.0f;
    *(float *)D_004C9170 = 600.0f;
    *(float *)D_004C9174 = 112.0f;
    *(float *)D_004C9178 = 0.5f;
    *(float *)D_004C9168 = (float)513;
    *(float *)D_004C917C = 0.0f;
}
