// func_0038B530 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if-chain rewritten as a switch with default first, case 2 breaking to the shared final return 8 (the null path's)).

// func_0038B530 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038B530_1;
struct UnkStruct_0038B530_2;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    UnkStruct_0038B530_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038B530_1 {
    unsigned char pad_0[0x1B8];
    UnkStruct_0038B530_2 * field_1B8;
};

struct UnkStruct_0038B530_2 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x0038B530
extern "C" int func_0038B530()
{
    if (D_0051BA88.field_0->field_1B8 != 0) {
        switch (D_0051BA88.field_0->field_1B8->field_4) {
        default:
            return 8;
        case 0:
            return 8;
        case 1:
            return 1;
        case 2:
            break;
        }
    }
    return 8;
}
