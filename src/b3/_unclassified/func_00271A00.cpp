// func_00271A00 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00271A60.

struct UnkStruct_00271A00 {
    void * field_0;
};

extern "C" int func_00271A60(void *, int);

// 0x00271A00
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" int func_00271A00(UnkStruct_00271A00 *self, int p0)
{
    return func_00271A60(self->field_0, p0);
}
