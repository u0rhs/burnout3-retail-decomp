// NONMATCHING: func_004D8D50 -- retail 30 / ours 31 instructions, 13 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C7170[];
extern unsigned char D_004C7174[];
extern unsigned char D_004C7178[];
extern unsigned char D_004C717C[];
extern unsigned char D_004C7180[];
extern unsigned char D_004C7184[];
extern unsigned char D_004C7188[];
extern unsigned char D_004C718C[];
extern unsigned char D_004C7190[];
extern unsigned char D_004C7194[];

// 0x004D8D50
extern "C" void func_004D8D50()
{
    *(float *)D_004C7170 = 320.0f;
    *(float *)D_004C7174 = 328.0f;
    *(float *)D_004C7178 = 0.5f;
    *(float *)D_004C717C = 0.5f;
    *(float *)D_004C7180 = 64.0f;
    *(float *)D_004C7188 = 0.0f;
    *(float *)D_004C7184 = 304.0f;
    *(float *)D_004C718C = 0.0f;
    *(float *)D_004C7194 = 49.0f;
    *(float *)D_004C7190 = (float)513;
}
