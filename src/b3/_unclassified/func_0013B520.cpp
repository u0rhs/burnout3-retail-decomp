// IncrementVehicleUsage__10CB3ProfileFUl -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013B520;

struct UnkStruct_0013B520 {
    unsigned char pad_0[0x48];
    int field_48[1];  // [G] element count unknown
};

extern "C" int func_003EB060(unsigned long);

// 0x0013B520
extern "C" void IncrementVehicleUsage__10CB3ProfileFUl(UnkStruct_0013B520 * self, unsigned long p0)
{
    int r0 = func_003EB060(p0);
    if (r0 != -1) {
        self->field_48[r0] = (self->field_48[r0] + 1);
    }
}
