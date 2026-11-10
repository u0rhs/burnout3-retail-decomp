// func_00309690 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (.lit4 externs -> float literals (0.225f,0.925f,0.1f,0.35f,0.7f); void return; arrays [8]).

struct UnkStruct_00309690 {
    unsigned long field_0;
    float field_8[8];
    float field_28[8];
    float field_48[8];
    float field_68;
    float field_6C;
};

// 0x00309690
extern "C" void func_00309690(UnkStruct_00309690 * self, int a1 /* passed by every caller, not read here */)
{
    self->field_0 = 0;
    self->field_68 = 0.225f;
    self->field_6C = 0.925f;
    for (int i = 0; i < 8; i++) {
        self->field_8[i] = 0.1f;
        self->field_28[i] = 0.35f;
        self->field_48[i] = 0.7f;
    }
}
