// NONMATCHING: func_00131F90 -- retail 63 / ours 59 instructions, 15 in changed runs
// gaps1: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x131F90..0x132088). [L] CB3Game::UpdatePostSimulation (port
// docs/frame-rate.md section 1; retail_names.csv: B3Game.cpp, high, unnamed) -- kept as its asm label. Called once per
// frame after func_00132600's tick loop: sound, then the two cameras with dt = N ticks * the world timer's dt.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_00131F90_fsm { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); };
struct UnkStruct_00131F90_game {
    unsigned char pad_0[0x8854];
    unsigned char field_8854[0xC];    // [C] a0 of func_0013C880
    unsigned char field_8860[0x10];   // [C] a0 of func_0021B820
    unsigned char pad_8870[0x28E00 - 0x8870];
    unsigned char field_28E00[0x10];  // [C] a0 of func_002E7610 ([G] a camera)
    unsigned char pad_28E10[0x299B0 - 0x28E10];
    unsigned char field_299B0[0x10];  // [C] a0 of func_002E7610 ([G] a camera)
    unsigned char pad_299C0[0x2DA54 - 0x299C0];
    int field_2DA54;                  // [C] the active pause, -1 none (UpdatePreSimulation__7CB3GameFv)
    unsigned char pad_2DA58[0x2C];
    int field_2DA84;                  // [C] N, this frame's tick count (func_00132600)
    float field_2DA88;                // [C] N * the world timer's dt (cvt.s.w + mul.s)
};

extern unsigned char D_004EB1E0;      // [C] the CB3DebugManager object's first byte, read as a flag
extern unsigned char D_004EB1E1;
extern unsigned char D_00522660[];    // [C] the CB3World (UpdateSound__8CB3WorldFv a0)
extern float D_0052267C;              // [C] D_00522660 + 0x1C: the world timer's dt [L]
extern unsigned char D_01E75640[];
extern UnkStruct_00131F90_fsm D_01EA2970;

extern "C" void func_0013C880(void *);
extern "C" void func_0021B820(void *);
extern "C" void UpdateSound__8CB3WorldFv(void *);
extern "C" void func_0028B160(void *);
extern "C" void func_002E7610(void *, float);

// 0x00131F90
extern "C" void func_00131F90(UnkStruct_00131F90_game * self)
{
    if (D_004EB1E0 != 0) {
        func_0013C880(self->field_8854);
        func_0021B820(self->field_8860);
        ((UnkStruct_00131F90_fsm *)&D_01EA2970)->vfunc_10();   // through the pointer: a virtual call, as retail
    }
    UpdateSound__8CB3WorldFv(D_00522660);
    func_0028B160(D_01E75640);
    self->field_2DA88 = (float)self->field_2DA84 * D_0052267C;
    if (self->field_2DA54 == -1 && D_004EB1E1 != 0) {
        func_002E7610(self->field_28E00, self->field_2DA88);
        func_002E7610(self->field_299B0, self->field_2DA88);
    }
}
