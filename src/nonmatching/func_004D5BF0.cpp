// NONMATCHING: func_004D5BF0 -- retail 20 / ours 21 instructions, 20 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004BBF70[];
extern unsigned char D_004BBF80[];
extern unsigned char D_004E0FF0[];

// 0x004D5BF0
extern "C" void func_004D5BF0()
{
    float t1 = *(float *)D_004E0FF0;
    *(float *)D_004BBF70 = 0.0f;
    *(float *)(D_004BBF70 + 0x4) = 0.0f;
    *(float *)(D_004BBF70 + 0x8) = t1;
    *(float *)(D_004BBF70 + 0xC) = t1;
    *(float *)D_004BBF80 = 128.0f;
    *(float *)(D_004BBF80 + 0x4) = 128.0f;
    *(float *)(D_004BBF80 + 0x8) = 256.0f;
    *(float *)(D_004BBF80 + 0xC) = 256.0f;
}
