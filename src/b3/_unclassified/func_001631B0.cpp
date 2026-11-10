// Prepare__15CB3TrafficParamFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001631B0;

struct UnkStruct_001631B0 {
    unsigned char pad_0[0x49];
    unsigned char field_49;
};

extern "C" void ResetMemberVariables__15CB3TrafficParamFv(void *);  // CB3TrafficParam::ResetMemberVariables()

// 0x001631B0
extern "C" int Prepare__15CB3TrafficParamFv(UnkStruct_001631B0 * self)
{
    ResetMemberVariables__15CB3TrafficParamFv(self);
    self->field_49 = 255;
    return 1;
}
