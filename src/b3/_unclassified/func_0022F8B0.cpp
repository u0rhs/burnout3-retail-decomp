// func_0022F8B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022F8B0;

struct UnkStruct_0022F8B0 {
    int field_0;
};

extern "C" void func_0022E560(int, UnkStruct_0022F8B0 *);

// 0x0022F8B0
extern "C" void func_0022F8B0(UnkStruct_0022F8B0 * self)
{
    func_0022E560(self->field_0, self);
}
