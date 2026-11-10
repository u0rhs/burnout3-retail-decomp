// NONMATCHING: func_0024FC20 -- retail 93 / ours 82 instructions, 24 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x24FC20..0x24FD90). Unnamed; file B3CarViewerGameMode.cpp per
// research/retail_names.csv (high). [L] the car viewer's Prepare: on first entry (+0x224 = 1 / 0x18) takes memory layout 1
// and resets the viewer (orbit 20 / -135 unless D_004E29C8, zoom 5.0, an identity basis at +0x240..+0x260 with their w
// lanes kept, counters cleared); then func_001346C0 (the race setup), five flag bytes and six words cleared, and
// D_004E197C = 1. Returns 0 only when the memory layout is refused.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_0024FC20_q { float x, y, z, w; };
struct UnkStruct_0024FC20 {
    unsigned char pad_0[0x200];
    float field_200;
    float field_204;
    int field_208;
    float field_20C;
    unsigned char field_210;
    unsigned char field_211;
    unsigned char field_212;
    unsigned char field_213;
    unsigned char field_214;
    unsigned char pad_215[0x3];
    int field_218;
    int field_21C;
    float field_220;
    int field_224;                            // [C] the prepare state
    int field_228;
    unsigned char field_22C;
    unsigned char field_22D;
    unsigned char pad_22E[0x2];
    int field_230;
    int field_234;
    unsigned char pad_238[0x8];
    UnkStruct_0024FC20_q field_240;
    UnkStruct_0024FC20_q field_250;
    UnkStruct_0024FC20_q field_260;
    int field_270;
    int field_274;
    unsigned char pad_278[0x88];
    int field_300[6];
};

extern unsigned char D_00516E10;
extern unsigned char D_00516E34;
extern int D_004E29C8;                        // [C] gp-relative
extern int D_004E197C;                        // [C] gp-relative
extern unsigned char theMemMgr[];

extern "C" int AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(void *, int);
extern "C" int func_001346C0(void *);

// 0x0024FC20
extern "C" int func_0024FC20(UnkStruct_0024FC20 * self)
{
    if (self->field_224 != 2) {
        if (self->field_224 != 0x18 && self->field_224 != 1) {
            D_004E197C = 1;
            return 1;
        }
        if (AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(theMemMgr, 1) == 0) {
            return 0;
        }
        self->field_224 = 2;
        D_00516E34 = 0;
        D_00516E10 = 0;
        if (D_004E29C8 == 0) {
            self->field_200 = 20.0f;
            self->field_204 = -135.0f;
        }
        self->field_208 = 0;
        self->field_20C = 5.0f;
        self->field_218 = 0;
        self->field_21C = 1;
        self->field_220 = 1.0f;
        self->field_228 = 2;
        self->field_240.x = 1.0f;
        self->field_240.y = 0.0f;
        self->field_240.z = 0.0f;
        self->field_250.x = 0.0f;
        self->field_250.y = 1.0f;
        self->field_250.z = 0.0f;
        self->field_260.x = 0.0f;
        self->field_260.y = 0.0f;
        self->field_260.z = 1.0f;
        self->field_234 = 0;
        self->field_230 = 0;
        self->field_274 = 0;
        self->field_270 = 0;
        self->field_22D = 0;
        self->field_22C = 0;
        self->field_214 = 0;
    }
    func_001346C0(self);
    self->field_210 = 0;
    self->field_211 = 0;
    self->field_212 = 0;
    self->field_213 = 0;
    self->field_214 = 0;
    for (int i = 0; i < 6; i++) {
        self->field_300[i] = 0;
    }
    D_004E197C = 1;
    return 1;
}
