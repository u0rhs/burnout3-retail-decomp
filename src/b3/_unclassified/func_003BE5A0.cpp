// func_003BE5A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" int func_003BE2A0(void *, const void *, void *, float);

// 0x003BE5A0
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" int func_003BE5A0(void *self, const void *sel, void *entry)
{
    return func_003BE2A0(self, sel, entry, 2.4e+02f);
}
