// NONMATCHING: func_004DB400 -- retail 34 / ours 25 instructions, 30 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4DB400..0x4DB484). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). HUD image UV constants: two float pairs and one CB3HUDImageUVs built by
// Construct(const CGtV2d &, const CGtV2d &, const CGtV2d &) from three stack CGtV2d temporaries.
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for

struct UnkStruct_004DB400_v2 { float x, y; };
extern float D_004CA818;
extern float D_004CA81C;
extern float D_004CA840;
extern float D_004CA844;
extern unsigned char D_004CA820[];   // [C] the CB3HUDImageUVs (Construct's a0)
extern "C" void Construct__14CB3HUDImageUVsFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    void *, const UnkStruct_004DB400_v2 *, const UnkStruct_004DB400_v2 *, const UnkStruct_004DB400_v2 *);

// 0x004DB400
extern "C" void func_004DB400()
{
    D_004CA818 = 54.0f;
    D_004CA81C = 36.0f;
    UnkStruct_004DB400_v2 c = { 64.0f, 32.0f };    // sp+0x18
    UnkStruct_004DB400_v2 b = { 63.0f, 31.0f };    // sp+0x20
    UnkStruct_004DB400_v2 a = { 1.0f, 1.0f };      // sp+0x28
    Construct__14CB3HUDImageUVsFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(D_004CA820, &a, &b, &c);
    D_004CA840 = 44.0f;
    D_004CA844 = 24.0f;
}
