// Fixup__20CB3AILanesDataStructFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00271920;
struct UnkStruct_00271920_e0;

struct UnkStruct_00271920_e0 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_00271920 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0xC];
    UnkStruct_00271920_e0 * field_14;
    int field_18;
    int field_1C;
    int field_20;
};

// 0x00271920
extern "C" void Fixup__20CB3AILanesDataStructFv(UnkStruct_00271920 * self)
{
    self->field_14 = (UnkStruct_00271920_e0 *)((char *)self->field_14 + (int)self);
    self->field_18 = (int)(self->field_18 + (int)self);
    self->field_1C = (int)(self->field_1C + (int)self);
    self->field_20 = (int)(self->field_20 + (int)self);
    for (int i = 0; (i < self->field_4); i++) {
        UnkStruct_00271920_e0 * t0 = self->field_14;
        t0[i].field_0 = (int)(t0[i].field_0 + (int)&t0[i]);
        t0[i].field_4 = (int)(t0[i].field_4 + (int)&t0[i]);
        t0[i].field_8 = (int)(t0[i].field_8 + (int)&t0[i]);
    }
}
