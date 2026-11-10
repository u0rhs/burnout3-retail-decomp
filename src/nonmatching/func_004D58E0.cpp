// NONMATCHING: func_004D58E0 -- retail 18 / ours 2 instructions, 16 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4D58E0..0x4D5924). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). Two nested loops over D_0066C590..D_0066DD90 (0x40 x 0x60 elements of 0x10) that only
// advance pointers: inlined empty constructors (e.g. CGtV3d) of an array of 0x60 objects with 3 vector members.
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for; the loops have no memory effect [C]

// 0x004D58E0
extern "C" void func_004D58E0()
{
    // [C] retail: for (p = D_0066C590; p != D_0066DD90; p += 0x40) for (q = p; q != p + 0x30; q += 0x10) {}
}
