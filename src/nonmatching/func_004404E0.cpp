// NONMATCHING: func_004404E0 -- retail 57 / ours 56 instructions, 13 in changed runs
// draftAO (2026-11-01): reviewed complete (stub + the 0x4404F0 time formatter, FLT_MAX 0x7F7FFFFF sentinel [C] D_004E0AE4); the header scored 4 because the unit holds two entries -- nonmatch.py now scores the whole unit; duplicate header lines removed; behaviour_audit sees only the stub (its call-missing rows are the listed FP) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 265 -> 17
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: calls identical (snprintf 7 args, ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi), every float operation checked



// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)


// Hand-written (a108). func_004404E0 is a tail-call stub; the code after it (0x004404F0) is a second function,
// placeholder func_004404F0 [G]: formats a time as text via snprintf + ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi.
struct UnkStruct_004404E0 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
    int field_C;
};
struct UnkStruct_004404E0_fn {
    unsigned char pad_0[0x8];
    void (*field_8)(int);
    int field_C;
};
extern char D_004D2210[];
extern "C" int snprintf(char *, int, char *, int, int, int, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);

// 0x004404E0
extern "C" void func_004404E0(UnkStruct_004404E0_fn * self)
{
    self->field_8(self->field_C);
}

// 0x004404F0
extern "C" void func_004404F0(UnkStruct_004404E0 * self, unsigned short * out)
{
    char buf[0x20];
    int mm, ss, cs;
    if (3.4028235e+38f == self->field_8) {
        mm = 0;
        ss = 0;
        cs = 0;
    } else {
        float t = self->field_8;
        mm = (int)(t / 60.0f);
        float r = t - 60.0f * (float)(int)(t / 60.0f);
        ss = (int)r;
        cs = (int)(100.0f * (r - (float)ss)) % 100;
    }
    snprintf(buf, 0x20, D_004D2210, self->field_4, mm, ss, cs);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, out, 0x20);
}

#pragma pop
