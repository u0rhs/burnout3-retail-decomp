// NONMATCHING: func_004D8E00 -- retail 28 / ours 27 instructions, 27 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C7A50[];
extern unsigned char kB3BuddyDisplayPos[];
extern unsigned char krB3BuddyBackgroundSize[];
extern unsigned char krB3BuddyTableSize[];

// 0x004D8E00
extern "C" void func_004D8E00()
{
    *(float *)krB3BuddyBackgroundSize = 544.0f;
    *(float *)(krB3BuddyBackgroundSize + 0x4) = 272.0f;
    *(float *)krB3BuddyTableSize = 536.0f;
    *(float *)(krB3BuddyTableSize + 0x4) = 272.0f;
    *(float *)kB3BuddyDisplayPos = 48.0f;
    *(float *)(kB3BuddyDisplayPos + 0x4) = 112.0f;
    *(float *)D_004C7A50 = 0.0f;
    *(float *)(D_004C7A50 + 0x4) = 0.0f;
    *(float *)(D_004C7A50 + 0x8) = 0.0f;
    *(float *)(D_004C7A50 + 0xC) = 0.25f;
}
