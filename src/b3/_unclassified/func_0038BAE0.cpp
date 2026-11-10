// Construct__25CB3OfflineBurningLapLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038BAE0;

struct UnkStruct_0038BAE0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3B];
    int field_40;
};

extern "C" void Construct__20CB3OfflineStageLogicFv(void *);  // CB3OfflineStageLogic::Construct()

// 0x0038BAE0
extern "C" void Construct__25CB3OfflineBurningLapLogicFv(UnkStruct_0038BAE0 * self)
{
    Construct__20CB3OfflineStageLogicFv(self);
    self->field_4 = 0;
    self->field_40 = 0;
}
