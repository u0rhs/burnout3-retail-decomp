// Construct__28CB3OnlineTurnBasedCrashLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00393320;

struct UnkStruct_00393320 {
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
    int field_68;
};

extern "C" void func_00392330(UnkStruct_00393320 *);

// 0x00393320
extern "C" void Construct__28CB3OnlineTurnBasedCrashLogicFv(UnkStruct_00393320 * self)
{
    self->field_68 = 0;
    func_00392330(self);
    self->field_60 = 0;
    self->field_64 = 0;
}
