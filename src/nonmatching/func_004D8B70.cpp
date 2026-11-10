// NONMATCHING: func_004D8B70 -- retail 115 / ours 116 instructions, 176 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C6FE0[];
extern unsigned char D_004C6FE4[];
extern unsigned char D_004C7060[];
extern unsigned char D_004C7070[];
extern unsigned char D_004C7074[];
extern unsigned char D_004C7078[];
extern unsigned char D_004C707C[];
extern unsigned char D_004C7080[];
extern unsigned char D_004C7084[];
extern unsigned char D_004C7088[];
extern unsigned char D_004C708C[];
extern unsigned char D_004C7090[];
extern unsigned char D_004C7094[];
extern unsigned char D_004C7098[];
extern unsigned char D_004C709C[];
extern unsigned char D_004C70A0[];
extern unsigned char D_004C70A4[];
extern unsigned char D_004C70A8[];
extern unsigned char D_004C70AC[];
extern unsigned char D_004C70B0[];
extern unsigned char D_004C70B4[];
extern unsigned char D_004C70B8[];
extern unsigned char D_004C70BC[];
extern unsigned char D_004C70C0[];
extern unsigned char D_004C70C4[];
extern unsigned char D_004C70C8[];
extern unsigned char D_004C70CC[];
extern unsigned char D_004C70D0[];
extern unsigned char D_004E0A0C[];
extern unsigned char D_004E0A10[];
extern unsigned char D_004E0A14[];
extern unsigned char D_01EA3F40[];
extern unsigned char kB3KeyboardHelpButtonSize[];
extern unsigned char kB3OnScreenKeyboardSelectedBoxColour[];
extern unsigned char kB3OnScreenKeyboardUnSelectedBoxColour[];
extern "C" void func_00100270(void *, void *, int, int, int);
extern "C" void func_00351A80();   // its address is stored

// 0x004D8B70
extern "C" void func_004D8B70()
{
    *(float *)D_004C6FE0 = 29.0f;
    float t1 = *(float *)D_004E0A0C;
    *(float *)D_004C6FE4 = 29.0f;
    *(float *)D_004C7070 = 1.0f;
    *(float *)D_004C7074 = 4.0f;
    float t2 = *(float *)D_004E0A10;
    *(float *)D_004C7078 = 1.0f;
    float t3 = *(float *)D_004E0A14;
    *(float *)D_004C707C = 4.0f;
    *(float *)D_004C7080 = 33.0f;
    *(float *)D_004C7084 = 4.0f;
    *(float *)D_004C7088 = 33.0f;
    *(float *)D_004C708C = 4.0f;
    *(float *)D_004C7090 = 30.0f;
    *(float *)D_004C7094 = 24.0f;
    *(float *)D_004C7098 = 30.0f;
    *(float *)D_004C709C = 24.0f;
    *(float *)D_004C70A0 = 30.0f;
    *(float *)D_004C70A4 = 24.0f;
    *(float *)D_004C70A8 = 30.0f;
    *(float *)D_004C70AC = 24.0f;
    *(float *)D_004C70B0 = 64.0f;
    *(float *)D_004C70B4 = 32.0f;
    *(float *)D_004C70B8 = 64.0f;
    *(float *)kB3OnScreenKeyboardSelectedBoxColour = t1;
    *(float *)(kB3OnScreenKeyboardSelectedBoxColour + 0x4) = t2;
    *(float *)(kB3OnScreenKeyboardSelectedBoxColour + 0x8) = t3;
    *(float *)(kB3OnScreenKeyboardSelectedBoxColour + 0xC) = 1.0f;
    *(float *)D_004C70BC = 32.0f;
    *(float *)kB3OnScreenKeyboardUnSelectedBoxColour = 0.0f;
    *(float *)(kB3OnScreenKeyboardUnSelectedBoxColour + 0x4) = 0.0f;
    *(float *)(kB3OnScreenKeyboardUnSelectedBoxColour + 0x8) = 0.0f;
    *(float *)(kB3OnScreenKeyboardUnSelectedBoxColour + 0xC) = 0.0f;
    *(float *)D_004C70C0 = 64.0f;
    *(float *)D_004C70CC = 32.0f;
    *(float *)D_004C70C8 = 64.0f;
    *(float *)D_004C70C4 = 32.0f;
    *(float *)D_004C70D0 = 26.0f;
    *(float *)(D_004C70D0 + 0x4) = 20.0f;
    *(float *)kB3KeyboardHelpButtonSize = 26.0f;
    *(float *)(kB3KeyboardHelpButtonSize + 0x4) = 20.0f;
    *(float *)(kB3KeyboardHelpButtonSize + 0x8) = 26.0f;
    *(float *)(kB3KeyboardHelpButtonSize + 0xC) = 20.0f;
    *(float *)(kB3KeyboardHelpButtonSize + 0x10) = 26.0f;
    *(float *)(kB3KeyboardHelpButtonSize + 0x14) = 20.0f;
    *(float *)D_004C7060 = 1.0f;
    *(float *)(D_004C7060 + 0x4) = 1.0f;
    *(float *)(D_004C7060 + 0x8) = 1.0f;
    *(float *)(D_004C7060 + 0xC) = 1.0f;
    func_00100270(D_01EA3F40, (unsigned char *)func_00351A80, 0x0, 0x10, 0x4);
}
