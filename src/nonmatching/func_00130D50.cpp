// NONMATCHING: func_00130D50 -- retail 98 / ours 96 instructions, 16 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x130D50..0x130ED4). Unnamed (no retail_names.csv row; between
// B3FrontEnd.cpp functions). [L] the front end's video Prepare by its calls: on first entry (+0x2F8 = 0x18) clears the
// 0x11 memory block (+0x310) and builds a linear allocator over it (+0x318), then prepares the video decoder at +0x1C8
// with track +0x2FC's file name (sprintf of D_004B5300[i] into D_004EDFF0), size (640 x D_004B5960[i]; 192 x 144 from
// index 0x52 on) and flags D_004B5750[i]; +0x20C gets the playback rate. Returns 0 when the decoder fails, else 1.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_00130D50 {
    unsigned char pad_0[0x1C8];
    unsigned char field_1C8[0x44];            // [C] the CGtVideoDecoder (Prepare__15CGtVideoDecoder... a0)
    float field_20C;
    unsigned char pad_210[0x2F8 - 0x210];
    int field_2F8;                            // [C] the video state (0x18 none, 2 allocator ready, 0x17 prepared)
    int field_2FC;                            // [C] the track index
    unsigned char pad_300[0x10];
    void * field_310;                         // [C] the 0x11 memory block (func_00131480 state 2)
    unsigned char pad_314[0x4];
    unsigned char field_318[0x10];            // [C] a CGtLinearMalloc
};

extern signed char D_004E2910;                // [C] gp-relative (lb)
extern float D_004E06E0;
extern float D_004E06E4;
extern char * D_004B5300[];                   // [C] per-track file-name formats
extern int D_004B5960[];                      // [C] per-track heights [G]
extern unsigned int D_004B5750[];             // [C] per-track flags
extern char D_004EDFF0[];                     // [C] gGame + 0xFB0 [G]: the file-name buffer
extern unsigned char theMemMgr[];

extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" void Create__15CGtLinearMallocFPvUi(void *, void *, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" int Prepare__15CGtVideoDecoderFP15CGtLinearMallociiPCcfUi(void *, void *, int, int, const char *, float, unsigned int);

// 0x00130D50
extern "C" int func_00130D50(UnkStruct_00130D50 * self)
{
    if (self->field_2F8 != 2) {
        if (self->field_2F8 != 0x18) {
            return 1;
        }
        memset(self->field_310, 0, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0x11));
        Create__15CGtLinearMallocFPvUi(self->field_318, self->field_310, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0x11));
        self->field_2F8 = 2;
    }
    float rate, rate2;
    if (D_004E2910 != 0) {
        rate = D_004E06E4;
        rate2 = D_004E06E0;
    } else {
        rate = D_004E06E4;
        rate2 = rate;
    }
    int i = self->field_2FC;
    int w, h;
    if (i < 0x52) {
        w = 0x280;
        h = D_004B5960[i];
    } else {
        w = 0xC0;
        h = 0x90;
    }
    sprintf(D_004EDFF0, D_004B5300[i], 30);   // [C] retail sets a2 = 30 (0x130DF0 / 0x130DF8): the format takes a number [G] the frame rate
    if (Prepare__15CGtVideoDecoderFP15CGtLinearMallociiPCcfUi(self->field_1C8, self->field_318, w, h, D_004EDFF0, rate,
                                                              D_004B5750[self->field_2FC]) == 0) {
        return 0;
    }
    self->field_20C = rate2;
    self->field_2F8 = 0x17;
    return 1;
}
