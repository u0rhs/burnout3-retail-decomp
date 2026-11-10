// func_0013B010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013B010;

struct UnkStruct_0013B010 {
    unsigned char pad_0[0x29C];
    int field_29C;
};

extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);

// 0x0013B010
extern "C" unsigned long func_0013B010(UnkStruct_0013B010 * self)
{
    int t0 = self->field_29C;
    if (t0 == -1) {
        return 0;
    }
    unsigned long r0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(t0);
    return r0;
}
