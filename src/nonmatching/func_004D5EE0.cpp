// NONMATCHING: func_004D5EE0 -- retail 58 / ours 56 instructions, 34 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4D5EE0..0x4D5FC4). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). The sound singletons: CB3SoundManager D_01E75640, its player-car / AI-car / ESM arrays
// (vptr per element), then func_00100270 ([L] __construct_array) of 2 CUnk0028B700 of 0x1C at D_01E7C880.
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for

extern unsigned char __vt__15CB3SoundManager[];
extern unsigned char __vt__17CB3SoundPlayerCar[];
extern unsigned char __vt__13CB3SoundAICar[];
extern unsigned char __vt__15CB3SoundESMHigh[];
extern unsigned char __vt__14CB3SoundESMLow[];
extern int D_01E7751C;
extern unsigned char D_01E77520;
extern void * D_01E75640;
extern void * D_01E78178;
extern unsigned char D_01E77760[];
extern unsigned char D_01E77A90[];
extern unsigned char D_01E78170[];
extern unsigned char D_01E78238[];
extern unsigned char D_01E78508[];
extern unsigned char D_01E7C880[];
extern "C" void __ct__12CUnk0028B700Fv();   // its address is passed
extern "C" void func_00100270(void *, void *, int, int, int);

// 0x004D5EE0
extern "C" void func_004D5EE0()
{
    D_01E7751C = 0;
    D_01E77520 = 0;
    D_01E75640 = __vt__15CB3SoundManager;
    unsigned char * p;
    for (p = D_01E77760; p != D_01E77A90; p += 0x198) {
        *(void **)p = __vt__17CB3SoundPlayerCar;
    }
    for (; p != D_01E78170; p += 0x160) {        // [C] continues from D_01E77A90 (a0 carried over)
        *(void **)p = __vt__13CB3SoundAICar;
    }
    D_01E78178 = __vt__15CB3SoundESMHigh;
    for (p = D_01E78238; p != D_01E78508; p += 0x90) {
        *(void **)p = __vt__14CB3SoundESMLow;
    }
    func_00100270(D_01E7C880, (void *)__ct__12CUnk0028B700Fv, 0, 0x1C, 2);   // tail call in retail
}
