// HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two early returns instead of empty-then if/else).

// HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00157000;
struct UnkStruct_00157000_1;
struct UnkStruct_00157000_a1;

struct UnkStruct_00157000_1 {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
};

struct UnkStruct_00157000_a1 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_00157000 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    UnkStruct_00157000_1 * field_C8;
    unsigned char pad_CC[0x1B0];
    int field_27C;
    unsigned char pad_280[0x290];
    float field_510[1];  // [G] element count unknown
    unsigned char pad_514[0x4A];
    unsigned char field_55E[1];  // [G] element count unknown
};

extern "C" void HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar(UnkStruct_00157000 * self, UnkStruct_00157000_a1 * p0)
{
    if (self->field_27C == 3) return;
    if (self->field_C8->field_18EA != 0) return;
    self->field_55E[p0->field_19AC] = 1;
    self->field_510[p0->field_19AC] = self->field_C;
}
