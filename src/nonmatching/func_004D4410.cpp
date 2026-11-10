// NONMATCHING: func_004D4410 -- retail 43 / ours 47 instructions, 58 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004E0F84[];
extern unsigned char kColourPosMarkerBlue[];
extern unsigned char kColourPosMarkerOrange[];
extern unsigned char kColourPosMarkerRed[];
extern unsigned char kColourPosMarkerWhite[];
extern unsigned char kHDRColourScale[];

// 0x004D4410
extern "C" void func_004D4410()
{
    float t1 = *(float *)D_004E0F84;
    *(float *)kColourPosMarkerOrange = t1;
    *(float *)(kColourPosMarkerOrange + 0x4) = 0.25f;
    *(float *)(kColourPosMarkerOrange + 0x8) = 0.0f;
    *(float *)(kColourPosMarkerOrange + 0xC) = 1.0f;
    *(float *)kColourPosMarkerRed = 0.5f;
    *(float *)(kColourPosMarkerRed + 0x4) = 0.0f;
    *(float *)(kColourPosMarkerRed + 0x8) = 0.0f;
    *(float *)(kColourPosMarkerRed + 0xC) = 1.0f;
    *(float *)kColourPosMarkerWhite = 0.5f;
    *(float *)(kColourPosMarkerWhite + 0x4) = 0.5f;
    *(float *)(kColourPosMarkerWhite + 0x8) = 0.5f;
    *(float *)(kColourPosMarkerWhite + 0xC) = 1.0f;
    *(float *)kColourPosMarkerBlue = 0.125f;
    *(float *)(kColourPosMarkerBlue + 0x4) = 0.25f;
    *(float *)(kColourPosMarkerBlue + 0x8) = 0.5f;
    *(float *)(kColourPosMarkerBlue + 0xC) = 1.0f;
    *(float *)kHDRColourScale = 0.5f;
    *(float *)(kHDRColourScale + 0x4) = 0.5f;
    *(float *)(kHDRColourScale + 0x8) = 0.5f;
    *(float *)(kHDRColourScale + 0xC) = 1.0f;
}
