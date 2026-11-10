// NONMATCHING: func_004D5DC0 -- retail 33 / ours 25 instructions, 33 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4D5DC0..0x4D5E40). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). Vtable pointers of three network singletons, then the vptr of each 0x4F20-byte element of
// D_01E3D5A0..D_01E64EA0 (its embedded 0x3CE0..0x4EE0 vector members have empty constructors).
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for

extern unsigned char __vt__18CGtLogitechHeadset[];
extern unsigned char __vt__12CGtPS2LibNet[];
extern unsigned char __vt__20CGtLobbyPS2DirtySock[];
extern unsigned char D_004DE0A0[];          // [C] the array elements' vtable
extern void * D_01E3BCAC;
extern void * D_01E3C620;
extern void * D_01E3CD44;
extern unsigned char D_01E3D5A0[];
extern unsigned char D_01E64EA0[];

// 0x004D5DC0
extern "C" void func_004D5DC0()
{
    D_01E3BCAC = __vt__18CGtLogitechHeadset;
    D_01E3C620 = __vt__12CGtPS2LibNet;
    D_01E3CD44 = __vt__20CGtLobbyPS2DirtySock;
    for (unsigned char * p = D_01E3D5A0; p != D_01E64EA0; p += 0x4F20) {
        *(void **)p = D_004DE0A0;
        // [C] then an empty inner loop over p+0x3CE0..p+0x4EE0, step 0xC0 (empty member constructors)
    }
}
