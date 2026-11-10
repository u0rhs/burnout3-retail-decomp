// func_003AFCE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (one shared counter m declared before t0; call result in a local, if (r0 > t1) {73-loop} else {100-loop}; per-loop scoped int i; && chains).

enum EB3TrackRegion {};

class CB3HardCodedCrashStageList;
struct UnkStruct_003AFCE0;
struct UnkStruct_003AFCE0_10;
struct UnkStruct_003AFCE0_11;
struct UnkStruct_003AFCE0_e4;
struct UnkStruct_003AFCE0_e6;
struct UnkStruct_D_0051BF9C;

class CB3HardCodedCrashStageList {
public:
    static int IsChallengeOnThisCircuit(EB3TrackRegion, int, int);
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003AFCE0_e4 {
    unsigned char pad_0[0x3C];
    int field_3C[1];  // [G] element count unknown
    unsigned char pad_40[0x30];
};

struct UnkStruct_003AFCE0_e6 {
    unsigned char pad_0[0x4];
    int field_4[1];  // [G] element count unknown
    unsigned char pad_8[0x28];
};

struct UnkStruct_003AFCE0_10 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
};

struct UnkStruct_003AFCE0_11 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
    unsigned char pad_18[0x18];
    int field_30;
};

struct UnkStruct_003AFCE0 {
    unsigned char pad_0[0x300];
    UnkStruct_003AFCE0_e6 field_300[1];  // [G] element count unknown
    unsigned char pad_330[0x210];
    UnkStruct_003AFCE0_e4 field_540[1];  // [G] element count unknown
    unsigned char pad_5B0[0x16C];
    int field_71C[1];  // [G] element count unknown
    unsigned char pad_720[0x6C];
    int field_78C[1];  // [G] element count unknown
    unsigned char pad_790[0x6C];
    int field_7FC[1];  // [G] element count unknown
    unsigned char pad_800[0x6C];
    int field_86C[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" int func_003EA530(int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int func_0013AD30(void *, int, int);
extern "C" UnkStruct_003AFCE0_10 * func_003E93B0(int);
extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);
extern "C" int IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(int, int, int);
extern "C" UnkStruct_003AFCE0_11 * func_003EA1D0(int);

// 0x003AFCE0
extern "C" int func_003AFCE0(UnkStruct_003AFCE0 * self, int p0, int p1)
{
    int m = 0;
    int t0 = D_0051BF9C.field_0;
    self->field_7FC[p1] = 0;
    self->field_71C[p1] = 0;
    self->field_86C[p1] = 0;
    self->field_78C[p1] = 0;
    int t1 = self->field_540[p0].field_3C[p1];
    int r0 = func_003EA530(p0);
    if (r0 > t1) {
        for (int i = 0; i < 73; i++) {
            if (IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(p0, i) != 0 && IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(p0, i, t1) != 0) {
                self->field_300[p1].field_4[self->field_78C[p1]] = i;
                self->field_78C[p1]++;
                if (func_0013AD70((void *)(t0), i, 1) == 0) {
                    m++;
                    self->field_71C[p1] = m;
                    if (func_0013AD30((void *)(t0), i, 1) == 3) {
                        self->field_7FC[p1]++;
                    }
                    UnkStruct_003AFCE0_11 * r = func_003EA1D0(i);
                    if (r != 0) {
                        if (r->field_10 != 0 && func_0013AD30((void *)(t0), i, 1) != 3) {
                            self->field_86C[p1]++;
                        } else if (r->field_30 == 2 && func_0013AD30((void *)(t0), i, 1) <= 0) {
                            self->field_86C[p1]++;
                        }
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < 100; i++) {
            if (IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(p0, i) != 0 && CB3HardCodedCrashStageList::IsChallengeOnThisCircuit((EB3TrackRegion)p0, i, t1) != 0) {
                self->field_300[p1].field_4[self->field_78C[p1]] = i;
                self->field_78C[p1]++;
                if (func_0013AD70((void *)(t0), i, 0) == 0) {
                    m++;
                    self->field_71C[p1] = m;
                    if (func_0013AD30((void *)(t0), i, 0) == 3) {
                        self->field_7FC[p1]++;
                    }
                    UnkStruct_003AFCE0_10 * r = func_003E93B0(i);
                    if (r != 0 && r->field_10 != 0) {
                        self->field_86C[p1]++;
                    }
                }
            }
        }
    }
    return m;
}
