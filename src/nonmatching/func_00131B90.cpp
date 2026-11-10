// NONMATCHING: func_00131B90 -- retail 67 / ours 64 instructions, 6 in changed runs
// gaps1: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x131B90..0x131C98). Unnamed (retail_names.csv has no row);
// called per tick from func_00132600 and in its loading state. Sleeps the thread for a time scaled by the current
// frame-rate constant D_004F509C and by one of three factors (D_01E6549A / D_01E65499 select) [C the calls; G meaning].
// TRACK: clean
// EQUIV: [L] written from the asm: the three exact-float tests in retail's order, cvt.w.s = truncation (EE FPU)

extern unsigned char D_01E6549A;
extern unsigned char D_01E65499;
extern float D_004F509C;
extern float D_004E0E00;              // [C] gp-relative constants (lwc1 %gp_rel)
extern float D_004E0F88;
extern float D_004E10D4;
extern float D_004E1328;
extern float D_004E138C;
extern float D_004E1414;
extern float D_004E1418;

extern "C" void SleepThread__12CGtThreadMgrFi(int);

// 0x00131B90
extern "C" void func_00131B90()
{
    float k;
    if (D_01E6549A != 0) {
        k = D_004E1418;
    } else if (D_01E65499 != 0) {
        k = D_004E1414;
    } else {
        k = D_004E0E00;
    }
    float r = D_004F509C;
    int t;
    if (D_004E0F88 == r) {
        t = (int)(15.625f * (2.0f * k));
    } else if (D_004E10D4 == r) {
        t = (int)(D_004E138C * (2.0f * k));
    } else if (D_004E1328 == r) {
        t = (int)(15.625f * k);
    } else {
        t = (int)(D_004E138C * k);
    }
    SleepThread__12CGtThreadMgrFi(t);
}
