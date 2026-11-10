// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// FindProgressionChallenge__25CB3HardCodedRaceStageListFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (key in one unsigned long local; loop counters declared first; compared value read into its own local (fixes beq operand order)).

// from build/vt\try_func_003E9B40_best.cpp
// FindProgressionChallenge__25CB3HardCodedRaceStageListFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003E9B40_10;
struct UnkStruct_003E9B40_4;
struct UnkStruct_003E9B40_6;
struct UnkStruct_003E9B40_7;
struct UnkStruct_003E9B40_e2;
struct UnkStruct_003E9B40_e3;
struct UnkStruct_D_00518690;

struct UnkStruct_003E9B40_4 {
    unsigned long field_0;
};

struct UnkStruct_D_00518690 {
    UnkStruct_003E9B40_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003E9B40_6 {
    unsigned char pad_0[0x4];
    UnkStruct_003E9B40_7 * field_4;
};

struct UnkStruct_003E9B40_7 {
    UnkStruct_003E9B40_e2 * field_0;
    int field_4;
};

struct UnkStruct_003E9B40_e2 {
    unsigned char pad_0[0x10];
    UnkStruct_003E9B40_e3 * field_10;
    int field_14;
};

struct UnkStruct_003E9B40_e3 {
    unsigned char pad_0[0x34];
    UnkStruct_003E9B40_10 * field_34;
    unsigned char pad_38[0x8];
};

struct UnkStruct_003E9B40_10 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};

extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern UnkStruct_003E9B40_4 * kapGPChallengeStageArrays[];  // [G] element count unknown
extern UnkStruct_D_00518690 D_00518690;

// 0x003E9B40
extern "C" void * FindProgressionChallenge__25CB3HardCodedRaceStageListFi(int n0)
{
    int i, i1;
    unsigned long v0 = kaB3HardCodedRaceChallengeList[n0];
    if (v0 < 7) {
        v0 = kapGPChallengeStageArrays[(int)v0]->field_0;
    }
    UnkStruct_003E9B40_6 * t1 = D_00518690.field_0;
    UnkStruct_003E9B40_7 * t2 = t1->field_4;
    int t3 = t2->field_4;
    for (i = 0; (i < t3); i++) {
        UnkStruct_003E9B40_e2 * t4 = t2->field_0;
        int t5 = t4[i].field_14;
        for (i1 = 0; (i1 < t5); i1++) {
            UnkStruct_003E9B40_e3 * t6 = t4[i].field_10;
            unsigned long k = t6[i1].field_34->field_8;
            if (k == v0) {
                return &t6[i1];
            }
        }
    }
    return 0;
}
