// NONMATCHING: func_004D5FD0 -- retail 43 / ours 27 instructions, 34 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4D5FD0..0x4D6078). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). Two CGtV3d constants (-1000 x3, 1000 x3; the w lane is an uninitialised stack word in
// retail, copied as is), an empty-constructor array loop over D_01E839D0..D_01E849D0, then func_00100270 ([L]
// __construct_array) of 0xF0 CGtV3d at D_01E84A00.
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for; the w lanes: retail copies uninitialised stack words, kept that way

struct UnkStruct_004D5FD0_q { unsigned int w[4]; };
extern UnkStruct_004D5FD0_q D_004C1BB0;
extern UnkStruct_004D5FD0_q D_004C1BC0;
extern unsigned char D_01E839D0[];
extern unsigned char D_01E849D0[];
extern unsigned char D_01E84A00[];
extern "C" void __ct__Q29GtMathPs26CGtV3dFv();   // its address is passed
extern "C" void func_00100270(void *, void *, int, int, int);

// 0x004D5FD0
extern "C" void func_004D5FD0()
{
    UnkStruct_004D5FD0_q lo;   // lane 3 never written
    UnkStruct_004D5FD0_q hi;   // lane 3 never written
    *(float *)&lo.w[0] = -1000.0f; *(float *)&lo.w[1] = -1000.0f; *(float *)&lo.w[2] = -1000.0f;
    *(float *)&hi.w[0] = 1000.0f;  *(float *)&hi.w[1] = 1000.0f;  *(float *)&hi.w[2] = 1000.0f;
    D_004C1BB0 = lo;
    D_004C1BC0 = hi;
    // [C] an empty loop: for (p = D_01E839D0; p != D_01E849D0; p += 0x40) for (q = p; q != p + 0x20; q += 0x10) {}
    func_00100270(D_01E84A00, (void *)__ct__Q29GtMathPs26CGtV3dFv, 0, 0x10, 0xF0);
}
