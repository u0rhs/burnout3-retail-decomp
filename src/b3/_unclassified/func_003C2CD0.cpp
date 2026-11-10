// Hand-written; the lifter refused it (hand-written CB3TurnBasedCrashChallenge::OnChallengeFinishDriving [L]; bubble sort over byte-pun element pointer, (unsigned char) cast on += global).

// func_003C2CD0 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: CB3TurnBasedCrashChallenge::OnChallengeFinishDriving() (research/proto/new_names.csv, medium)

struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_uchar { unsigned char field_0; unsigned char pad_1[0xF]; };

struct UnkStruct_003C2CD0 {
    unsigned char pad_0[0x58];
    int field_58[8];
    int field_78[8];
    unsigned char field_98[7];
    signed char field_9F[9];
    unsigned char pad_A8[0x9];
    unsigned char field_B1;
    unsigned char pad_B2[0x1];
    unsigned char field_B3;
};

extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_int D_0064EB08;
extern UnkStruct_D_uchar D_0064EAF8;
extern UnkStruct_D_int D_006512D8;
extern UnkStruct_D_uchar D_006512C8;

extern "C" bool func_00131CA0(void *);

// 0x003C2CD0
extern "C" void func_003C2CD0(UnkStruct_003C2CD0 * self)
{
    bool t = func_00131CA0(&D_004EE040);
    self->field_58[self->field_B1] = D_0064EB08.field_0;
    self->field_98[self->field_B1] += (unsigned char)D_0064EAF8.field_0;
    if (t) {
        self->field_58[self->field_B1] += D_006512D8.field_0;
        self->field_98[self->field_B1] += (unsigned char)D_006512C8.field_0;
    }
    self->field_78[self->field_B1] += self->field_58[self->field_B1];
    int n = t ? (unsigned char)((unsigned)self->field_B3 >> 1) : self->field_B3;
    if (self->field_B1 + 1 < n) {
        return;
    }
    int j;
    bool sorted;
    do {
        sorted = true;
        for (j = 1; j < n; j++) {
            signed char *p = (signed char *)self + j;
            signed char b = p[0xA0];
            signed char a = p[0x9F];
            if (self->field_78[a] < self->field_78[b]) {
                p[0xA0] = a;
                p[0x9F] = b;
                sorted = false;
            }
        }
    } while (!sorted);
}
