// func_0041E910 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C02A0;
extern "C" int func_002C02A0(UnkStruct_002C02A0 *);

// 0x0041E910
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" bool func_0041E910(UnkStruct_002C02A0 *self)
{
    int r0 = func_002C02A0(self);
    return (r0 != 0);
}
