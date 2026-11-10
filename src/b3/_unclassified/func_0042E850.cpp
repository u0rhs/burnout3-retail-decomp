// func_0042E850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (branches swapped (p2!=0 first); merged || returns; int* element pointer; call result in temp).

// lifter variant 0
// func_0042E850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042E850;

struct UnkStruct_0042E850 {
    unsigned char pad_0[0x1F8];
    int field_1F8[1];  // [G] element count unknown
    unsigned char pad_1FC[0x167];
    signed char field_363;
};

extern "C" int func_003EAFC0(int);

// 0x0042E850
extern "C" int func_0042E850(UnkStruct_0042E850 * self, int p0, int p1, int p2)
{
    if (p2 != 0) {
        for (int i1 = (p1 + 1); (i1 < 67); i1++) {
            int r = func_003EAFC0(i1);
            if (r == p0 || p0 == 15 || p0 == 0) {
                return i1;
            }
        }
    } else {
        for (int i = 0; (i < self->field_363); i++) {
            int * pp = &self->field_1F8[i];
            int t0 = *pp;
            if (t0 != -1 && p1 < t0) {
                int r = func_003EAFC0(t0);
                if (r == p0 || p0 == 15 || p0 == 0) {
                    return *pp;
                }
            }
        }
    }
    return -1;
}
