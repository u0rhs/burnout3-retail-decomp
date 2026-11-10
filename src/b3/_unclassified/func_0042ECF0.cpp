// func_0042ECF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if(p2)/else with one trailing return -1; call results in int temps (beq v0,s3 order); merged || returns; pointer-to-element).

// func_0042ECF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042ECF0;

struct UnkStruct_0042ECF0 {
    unsigned char pad_0[0xE4];
    int field_E4[1];  // [G] element count unknown
    unsigned char pad_E8[0x274];
    signed char field_35C;
};

extern "C" int func_003F5FF0(int);

// 0x0042ECF0
extern "C" int func_0042ECF0(UnkStruct_0042ECF0 * self, int p0, int p1, int p2)
{
    if (p2 != 0) {
        for (int i1 = (p1 + 1); (i1 < 20); i1++) {
            int r = func_003F5FF0(i1); if (r == p0 || p0 == 4) return i1;
        }
    } else {
    for (int i = 0; (i < self->field_35C); i++) {
        int * pp = &self->field_E4[i];
        if (*pp != -1 && p1 < *pp) {
            int r2 = func_003F5FF0(*pp);
            if (r2 == p0 || p0 == 4) return *pp;
        }
    }
    }
    return -1;
}
