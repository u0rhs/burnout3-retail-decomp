// func_0043E120 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_0043E1F0.

struct UnkStruct_0043E1F0;
extern "C" void func_0043E1F0(UnkStruct_0043E1F0 *);

// 0x0043E120
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_0043E120(UnkStruct_0043E1F0 *self)
{
    func_0043E1F0(self);
}
