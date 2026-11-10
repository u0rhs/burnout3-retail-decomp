// NONMATCHING: func_00131990 -- retail 65 / ours 64 instructions, 4 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x131990..0x131A90). Unnamed; file B3FrontEnd.cpp per
// research/retail_names.csv (high). [L] the front end's Construct by its stores: the video decoder at +0x1C8 is
// constructed, the tuning float D_004E1408 registered once (AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi, name D_004B5B28), then the start-up
// state: +0x2F4 = 1 (func_00131480's first state), +0x2F8 = 0x18 (no video), the menu-flow FSM id +0x300 =
// 0x60D6B06C7D38759E, track 0, flags; finally func_0042FCB0 and func_00134910.
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call in retail's order

struct UnkStruct_00131990_vdb { unsigned char pad_0[0x10]; unsigned char field_10[0x10]; };
struct UnkStruct_00131990 {
    unsigned char pad_0[0x1C4];
    int field_1C4;
    unsigned char field_1C8[0x120];           // [C] the CGtVideoDecoder (Construct__15CGtVideoDecoderFv a0)
    void * field_2E8;
    unsigned char pad_2EC[0x4];
    unsigned char field_2F0;
    unsigned char pad_2F1[0x3];
    int field_2F4;
    int field_2F8;
    int field_2FC;
    unsigned long field_300;                  // [C] sd: a 64-bit FSM state id (func_00131480 ld 0x300)
    int field_308;
    int field_30C;
    unsigned char pad_310[0x5];
    unsigned char field_315;
    unsigned char field_316;
    unsigned char field_317;
};

extern unsigned char D_004E26A0;              // [C] gp-relative: registered once
extern UnkStruct_00131990_vdb * mpToolBase__Q27GtComms16CGtCommsToolBase; // [C] gp-relative
extern float D_004E1408;
extern char * D_004E140C;
extern char * D_004E1410;
extern char D_004B5B28[];
extern unsigned char * D_006662DC;
extern unsigned char D_01E900B0[];            // [C] the CB3MenuChoices
extern unsigned char D_01EA2970[];            // [C] the menu-flow FSM
extern unsigned char D_01ECD9F0[];

extern "C" void Construct__15CGtVideoDecoderFv(void *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(void *, float *, const char *, const char *, const char *, int, int, float, float);
extern "C" void Prepare__14CB3MenuChoicesFv(void *);
extern "C" void func_0030ED40(void *, int);
extern "C" void func_0042FCB0(void *);
extern "C" void func_00134910(void *);

// 0x00131990
extern "C" void func_00131990(UnkStruct_00131990 * self)
{
    Construct__15CGtVideoDecoderFv(self->field_1C8);
    if (D_004E26A0 == 0) {
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase->field_10, &D_004E1408, D_004B5B28, D_004E1410, D_004E140C, 0, 0, 0.0f, 0.0f);
        D_004E26A0 = 1;
    }
    self->field_2E8 = D_006662DC + 0x300;
    Prepare__14CB3MenuChoicesFv(D_01E900B0);
    self->field_315 = 0;
    self->field_2F4 = 1;
    self->field_2F8 = 0x18;
    func_0030ED40(D_01EA2970, 0);
    self->field_300 = 0x60D6B06C7D38759EUL;
    self->field_2FC = 0;
    self->field_308 = 1;
    self->field_30C = 0;
    self->field_1C4 = 0;
    self->field_316 = 0;
    self->field_317 = 0;
    self->field_2F0 = 1;
    func_0042FCB0(D_01ECD9F0);
    func_00134910(self);
}
