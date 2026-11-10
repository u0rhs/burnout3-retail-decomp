// func_00466E70 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00462160.

struct UnkStruct_00462160;
extern "C" void func_00462160(UnkStruct_00462160 *);

// 0x00466E70
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_00466E70(UnkStruct_00462160 *self)
{
    func_00462160(self);
}
