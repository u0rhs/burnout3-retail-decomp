// func_003FAA40 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_003FC640.

extern "C" void func_003FC640(char *);

// 0x003FAA40
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_003FAA40(char *p0)
{
    func_003FC640(p0);
}
