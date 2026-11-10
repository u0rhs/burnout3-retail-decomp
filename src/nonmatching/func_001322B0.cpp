// NONMATCHING: func_001322B0 -- retail 91 / ours 90 instructions, 8 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1322B0..0x132418). Unnamed (no retail_names.csv row; in
// B3Game.cpp's range). func_00132600's "wait for the next stage" step (states 7, 9, 11): the stage's slot 0xC must
// report ready, then the frame-rate manager (gGame + 0x2DA10 = D_0051BA50) is rebuilt with 20 / 40 (or D_004E11D8 /
// D_004E11DC when D_004E2910 is clear) for in-game / front-end stages (the front-end stage embedded at gGame+0x2C668, or
// a game mode embedded at +0x2D6D4 / +0x2D748), and the stage's +0x1AC byte goes to D_0055D7FB. Returns 1 when done.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_001322B0_st {
    unsigned char pad_0[0x1AC];
    unsigned char field_1AC;
    unsigned char pad_1AD[0x3];
    // [C] the stage's vtable pointer sits at +0x1B0; slot 0xC called with a0 = the stage
    virtual void vfunc_8(); virtual int vfunc_C();
    void * field_1B4;                         // [C] the game mode, compared with two embedded ones
};
struct UnkStruct_001322B0 {
    unsigned char pad_0[0x2C668];
    unsigned char field_2C668[0x106C];        // [C] compared with field_2DA48: an embedded stage [G] size
    unsigned char field_2D6D4[0x74];          // [C] compared with stage+0x1B4: embedded game modes [G] sizes
    unsigned char field_2D748[0x300];
    UnkStruct_001322B0_st * field_2DA48;      // [C] the current stage
};

extern signed char D_004E2910;               // [C] gp-relative (lb)
extern float D_004E11D8;
extern float D_004E11DC;
extern unsigned char D_0055D7FB;
extern unsigned char D_01E75640[];
extern unsigned char D_0051BA50[];           // [C] gGame + 0x2DA10: the CGtFramerateManager

extern "C" void func_0028B160(void *);
extern "C" void Construct__19CGtFramerateManagerFff(void *, float, float);

// 0x001322B0
extern "C" int func_001322B0(UnkStruct_001322B0 * self)
{
    func_0028B160(D_01E75640);
    if (self->field_2DA48->vfunc_C() == 0) {
        return 0;
    }
    bool game = true;
    UnkStruct_001322B0_st * st = self->field_2DA48;
    if ((void *)st == self->field_2C668) {
        game = false;
    } else if (st->field_1B4 != 0 && (st->field_1B4 == self->field_2D6D4 || st->field_1B4 == self->field_2D748)) {
        game = false;
    }
    if (game) {
        if (D_004E2910 != 0) {
            Construct__19CGtFramerateManagerFff(D_0051BA50, 20.0f, 0.0f);
        } else {
            Construct__19CGtFramerateManagerFff(D_0051BA50, D_004E11D8, 0.0f);
        }
    } else {
        if (D_004E2910 != 0) {
            Construct__19CGtFramerateManagerFff(D_0051BA50, 40.0f, 0.0f);
        } else {
            Construct__19CGtFramerateManagerFff(D_0051BA50, D_004E11DC, 0.0f);
        }
    }
    D_0055D7FB = self->field_2DA48->field_1AC;
    return 1;
}
