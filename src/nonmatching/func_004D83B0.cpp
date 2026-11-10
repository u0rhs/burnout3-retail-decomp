// NONMATCHING: func_004D83B0 -- retail 39 / ours 39 instructions, 22 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5568[];
extern unsigned char D_004C556C[];
extern unsigned char D_004C5570[];
extern unsigned char D_004C5574[];
extern unsigned char krTextBackgroundHandle[];
extern unsigned char krTextBackgroundPosition[];
extern unsigned char krTextBackgroundSize[];
extern unsigned char krTextHandle[];
extern unsigned char krTextPosition[];

// 0x004D83B0
extern "C" void func_004D83B0()
{
    *(float *)krTextPosition = 320.0f;
    *(float *)(krTextPosition + 0x4) = 168.0f;
    *(float *)krTextHandle = 0.5f;
    *(float *)(krTextHandle + 0x4) = 0.5f;
    *(float *)krTextBackgroundPosition = 64.0f;
    *(float *)krTextBackgroundHandle = 0.0f;
    *(float *)(krTextBackgroundPosition + 0x4) = 112.0f;
    *(float *)(krTextBackgroundHandle + 0x4) = 0.0f;
    *(float *)(krTextBackgroundSize + 0x4) = 113.0f;
    *(float *)D_004C5568 = 600.0f;
    *(float *)D_004C556C = 112.0f;
    *(float *)D_004C5570 = 0.5f;
    *(float *)krTextBackgroundSize = (float)513;
    *(float *)D_004C5574 = 0.0f;
}
