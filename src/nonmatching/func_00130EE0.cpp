// NONMATCHING: func_00130EE0 -- retail 134 / ours 129 instructions, 25 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x130EE0..0x1310F4). Unnamed (no retail_names.csv row; between
// B3FrontEnd.cpp functions). The front end's music stream: waits while D_01E7A888 reports busy (func_003FA5F0 != 0 and
// != 3) or the stream at +0x30C still plays (func_00386010), then starts track +0x2FC from the tables D_004B5540
// (stream id; 0x24 = none, 0x22 = the D_004E1404 file) / D_004B5750 (bit 2: named by +0x1C8) at the louder of the two
// volume settings D_004F5074 / D_004F5075 (percent) x D_004E1408. Returns 0 when the stream could not start, else 1.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_00130EE0 {
    unsigned char pad_0[0x1C8];
    char field_1C8[0x10];                     // [C] a2 of func_003865A0 for flagged tracks ([G] a file name)
    unsigned char pad_1D8[0x2FC - 0x1D8];
    int field_2FC;                            // [C] the track index into D_004B5540 / D_004B5750
    unsigned char pad_300[0xC];
    void * field_30C;                         // [C] the CGtSoundStream (AllocStream__21CGtSoundStreamManagerFb)
};

extern int D_004B5540[];
extern int D_004B5750[];
extern char * D_004E1400;                     // [C] gp-relative words passed as a1 ([G] file names)
extern char * D_004E1404;
extern float D_004E1408;
extern signed char D_004F5074;                // [C] lb: gGame + 0x7034 / 0x7035 ([G] the two volume settings)
extern signed char D_004F5075;
extern unsigned char D_01E7A888[];
extern unsigned char D_01E774E0[];            // [C] the CGtSoundStreamManager

extern "C" int func_003FA5F0(void *);
extern "C" int func_00386010(void *);
extern "C" void * AllocStream__21CGtSoundStreamManagerFb(void *, bool);
extern "C" int func_003865A0(void *, char *, char *, int, int, int);
extern "C" void SetVolume__14CGtSoundStreamFfi(void *, float, int);

// 0x00130EE0
extern "C" int func_00130EE0(UnkStruct_00130EE0 * self)
{
    if (func_003FA5F0(D_01E7A888) != 0 && func_003FA5F0(D_01E7A888) != 3) {
        return 1;
    }
    if (self->field_30C != 0 && func_00386010(self->field_30C) != 0) {
        return 1;
    }
    if (D_004B5540[self->field_2FC] == 0x24) {
        self->field_30C = 0;
        return 1;
    }
    if (self->field_30C == 0) {
        self->field_30C = AllocStream__21CGtSoundStreamManagerFb(D_01E774E0, false);
    }
    int i = self->field_2FC;
    int ok;
    if (D_004B5750[i] & 2) {
        ok = func_003865A0(self->field_30C, D_004E1400, self->field_1C8, 0, D_004B5540[i], 4);
    } else if (D_004B5540[i] == 0x22) {
        ok = func_003865A0(self->field_30C, D_004E1404, 0, 0, 0, 4);
    } else {
        ok = func_003865A0(self->field_30C, D_004E1400, 0, 0, D_004B5540[i], 4);
    }
    if (ok == 0) {
        return 0;
    }
    float a = (float)D_004F5075 / 100.0f;
    float b = (float)D_004F5074 / 100.0f;
    if (a <= b) {
        SetVolume__14CGtSoundStreamFfi(self->field_30C, b * D_004E1408, 0);
    } else {
        SetVolume__14CGtSoundStreamFfi(self->field_30C, a * D_004E1408, 0);
    }
    return 1;
}
