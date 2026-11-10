// func_003A72E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (plain for loops with && conditions; the shared success block as a static inline (crash flag param); i and t2 declared before t0 (register order)).

// func_003A72E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3TrackRegion {};

class CB3HardCodedCrashStageList;
struct UnkStruct_003A72E0;
struct UnkStruct_003A72E0_e0;
struct UnkStruct_D_0051BF9C;

class CB3HardCodedCrashStageList {
public:
    static int IsChallengeOnThisCircuit(EB3TrackRegion, int, int);
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A72E0_e0 {
    unsigned char pad_0[0x3C];
    int field_3C[1];  // [G] element count unknown
    unsigned char pad_40[0x30];
};

struct UnkStruct_003A72E0 {
    unsigned char pad_0[0x254];
    int field_254;
    unsigned char pad_258[0x4];
    int field_25C;
    unsigned char pad_260[0x4];
    int field_264;
    int field_268[1];  // [G] element count unknown
    unsigned char pad_26C[0x8];
    unsigned char field_274[1];  // [G] element count unknown
    unsigned char pad_275[0x3];
    int field_278;
    int field_27C;
    unsigned char pad_280[0x2C0];
    UnkStruct_003A72E0_e0 field_540[1];  // [G] element count unknown
    unsigned char pad_5B0[0x160];
    int field_710;
    unsigned char pad_714[0x1D0];
    unsigned char field_8E4;
    unsigned char pad_8E5[0x1];
    unsigned char field_8E6;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);
extern "C" int IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(int, int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);

static inline void func_003A72E0_inl1(UnkStruct_003A72E0 * self, int i, int j, int t2, unsigned char crash)
{
    self->field_27C = i;
    self->field_25C = j;
    self->field_8E6 = crash;
    self->field_268[self->field_254] = t2;
    self->field_274[self->field_254] = self->field_8E6;
    if (self->field_27C != self->field_278) {
        self->field_710 = 0;
        self->field_8E4 = 1;
    }
    self->field_264 = t2;
}

// 0x003A72E0
extern "C" int func_003A72E0(UnkStruct_003A72E0 * self)
{
    int i;
    int t2;
    int t0 = D_0051BF9C.field_0;
    for (i = self->field_27C - 1; i >= 0; i--) {
        t2 = self->field_540[self->field_254].field_3C[i];
        for (int j = 0; j < 73; j++) {
            if (IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(self->field_254, j) != 0 && IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(self->field_254, j, t2) != 0 && func_0013AD70((void *)(t0), j, 1) == 0) {
                func_003A72E0_inl1(self, i, j, t2, 0);
                return 1;
            }
        }
        for (int j = 0; j < 100; j++) {
            if (IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(self->field_254, j) != 0 && CB3HardCodedCrashStageList::IsChallengeOnThisCircuit((EB3TrackRegion)self->field_254, j, t2) != 0 && func_0013AD70((void *)(t0), j, 0) == 0) {
                func_003A72E0_inl1(self, i, j, t2, 1);
                return 1;
            }
        }
    }
    return 0;
}
