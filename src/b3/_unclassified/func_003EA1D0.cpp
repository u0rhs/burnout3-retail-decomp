// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_003EA1D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (pointer-to-element locals per loop level; call result in a temp (int r = f(); if (r == n0))).

// func_003EA1D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EA1D0_1;
struct UnkStruct_003EA1D0_5;
struct UnkStruct_003EA1D0_e0;
struct UnkStruct_003EA1D0_e1;
struct UnkStruct_003EA1D0_e2;
struct UnkStruct_D_00518690;

struct UnkStruct_D_00518690 {
    UnkStruct_003EA1D0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EA1D0_1 {
    unsigned char pad_0[0x4];
    UnkStruct_003EA1D0_e0 * field_4;
    int field_8;
};

struct UnkStruct_003EA1D0_e0 {
    UnkStruct_003EA1D0_e1 * field_0;
    int field_4;
};

struct UnkStruct_003EA1D0_e1 {
    unsigned char pad_0[0x10];
    UnkStruct_003EA1D0_e2 * field_10;
    int field_14;
};

struct UnkStruct_003EA1D0_e2 {
    unsigned char pad_0[0x34];
    UnkStruct_003EA1D0_5 * field_34;
    unsigned char pad_38[0x8];
};

struct UnkStruct_003EA1D0_5 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};

extern UnkStruct_D_00518690 D_00518690;

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);

// 0x003EA1D0
// [L] each level walks through a pointer-to-element local; the call result goes through a temp before ==.
extern "C" void * func_003EA1D0(int n0)
{
    for (int i = 0; i < D_00518690.field_0->field_8; i++) {
        UnkStruct_003EA1D0_e0 * e0 = &D_00518690.field_0->field_4[i];
        for (int i1 = 0; i1 < e0->field_4; i1++) {
            UnkStruct_003EA1D0_e1 * e1 = &e0->field_0[i1];
            for (int i2 = 0; i2 < e1->field_14; i2++) {
                UnkStruct_003EA1D0_e2 * e2 = &e1->field_10[i2];
                int r = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(e2->field_34->field_8);
                if (r == n0) {
                    return e2;
                }
            }
        }
    }
    return 0;
}
