// UseTakedownCamera__21CB3Offline2PRaceLogicFP10CB3RaceCarP10CB3RaceCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BE640_a1;
struct UnkStruct_003BE640_a2;

struct UnkStruct_003BE640_a1 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_003BE640_a2 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

// 0x003BE640
extern "C" bool UseTakedownCamera__21CB3Offline2PRaceLogicFP10CB3RaceCarP10CB3RaceCar(int n0, UnkStruct_003BE640_a1 * p0, UnkStruct_003BE640_a2 * p1)
{
    bool v0 = ((p0->field_1914 == 0) && (p1->field_1914 == 0));
    return v0;
}
