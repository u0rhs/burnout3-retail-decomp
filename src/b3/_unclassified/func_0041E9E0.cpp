// func_0041E9E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_002C1C10.

struct UnkStruct_002C1C10;
extern "C" void func_002C1C10(UnkStruct_002C1C10 *);

// 0x0041E9E0
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_0041E9E0(UnkStruct_002C1C10 *self)
{
    func_002C1C10(self);
}
