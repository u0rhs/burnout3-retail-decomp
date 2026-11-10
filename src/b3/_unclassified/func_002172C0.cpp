// IsControlJustPressed__26CGtInputDevicePS2DualShockFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (materialized range test as int v = p >= 0; if (v) v = p < 28; if ((unsigned char)v == 0) return 0; then return the && value).

// IsControlJustPressed__26CGtInputDevicePS2DualShockFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002172C0;

struct UnkStruct_002172C0 {
    unsigned char pad_0[0xA];
    unsigned char field_A[1];  // [G] element count unknown
    unsigned char pad_B[0x1B];
    unsigned char field_26[1];  // [G] element count unknown
};

extern "C" bool IsControlJustPressed__26CGtInputDevicePS2DualShockFi(UnkStruct_002172C0 * self, int p0)
{
    int v0 = p0 >= 0;
    if (v0) {
        v0 = p0 < 28;
    }
    if ((unsigned char)v0 == 0) return 0;
    return self->field_26[p0] != 0 && self->field_A[p0] == 0;
}
