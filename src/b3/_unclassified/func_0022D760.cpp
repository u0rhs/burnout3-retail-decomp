// func_0022D760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (comparator: bool result var set in an else-if chain (wrap-around unsigned short compare), p0 unsigned short).

// func_0022D760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D760;

struct UnkStruct_0022D760 {
    unsigned char pad_0[0xC];
    unsigned short field_C;
};

// 0x0022D760
extern "C" bool func_0022D760(UnkStruct_0022D760 * self, unsigned short p0)
{
    unsigned short a = self->field_C;
    bool r;
    if (a < 21845 && p0 > 43690) {
        r = true;
    } else if (p0 < 21845 && a > 43690) {
        r = false;
    } else if (p0 < a) {
        r = true;
    } else {
        r = false;
    }
    return r;
}
