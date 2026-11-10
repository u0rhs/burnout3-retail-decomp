// func_00240A60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00240E90.

struct UnkStruct_00240E90;
extern "C" void func_00240E90(UnkStruct_00240E90 *, int);

// 0x00240A60
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_00240A60(UnkStruct_00240E90 *self, void *p0_)
{
    int p0 = (int)p0_;
    func_00240E90(self, p0);
}
