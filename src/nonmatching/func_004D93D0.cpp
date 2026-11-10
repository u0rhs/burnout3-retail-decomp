// NONMATCHING: func_004D93D0 -- retail 16 / ours 12 instructions, 14 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4D93D0..0x4D940C). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). kVFlashColourScale = (1, 1, 1, D_004E06DC) * s, s = the float in D_004E07C8 (VU0 vmulx.xyzw
// by its x lane; retail moves it with lw + qmtc2).
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for

extern float D_004E06DC;          // [C] gp-relative
extern float D_004E07C8;          // [C] gp-relative, read as a word and used as a float
extern float kVFlashColourScale[4];

// 0x004D93D0
extern "C" void func_004D93D0()
{
    float s = D_004E07C8;
    kVFlashColourScale[0] = 1.0f * s;
    kVFlashColourScale[1] = 1.0f * s;
    kVFlashColourScale[2] = 1.0f * s;
    kVFlashColourScale[3] = D_004E06DC * s;
}
