// Release__12CB3PlayerCarFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00150890;

class CB3CrashCombo {
public:
    void Release();
};

struct UnkStruct_00150890 {
    unsigned char pad_0[0x2470];
    CB3CrashCombo field_2470;
    unsigned char pad_2471[0x358];
    unsigned char field_27C9;
};

extern "C" void Release__8CB3AICarFv(void *);  // CB3AICar::Release()

// 0x00150890
extern "C" void Release__12CB3PlayerCarFv(UnkStruct_00150890 * self)
{
    Release__8CB3AICarFv(self);
    self->field_27C9 = 0;
    self->field_2470.Release();
}
