// NONMATCHING: func_00131B30 -- retail 23 / ours 24 instructions, 16 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x131B30..0x131B88). Unnamed (no retail_names.csv row; in B3Game.cpp's range). Number
// separators by the language D_004E2918 [G]: 10, 6, 5 -> ('.', ','); 4 -> (' ', '.'); else (',', '.'); a tail call.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

extern int D_004E2918;                        // [C] gp-relative

extern "C" void ustrSetSeparators(int, int);

// 0x00131B30
extern "C" void func_00131B30()
{
    int a, b;
    switch (D_004E2918) {
    case 10:
    case 6:
    case 5:
        a = 0x2E;
        b = 0x2C;
        break;
    case 4:
        a = 0x20;
        b = 0x2E;
        break;
    default:
        a = 0x2C;
        b = 0x2E;
        break;
    }
    ustrSetSeparators(a, b);
}
