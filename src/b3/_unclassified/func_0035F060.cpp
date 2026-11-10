// PrintUTFChar__15CGtUnicodeUtilsFPUsUs -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (unsigned short pointer walk: while (*s != 0) s++; s[0] = c; s[1] = 0; return s + 1 (lifted pointer/m1 temp pair removed)).

// PrintUTFChar__15CGtUnicodeUtilsFPUsUs -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0035F060;
struct UnkStruct_0035F060_1;

struct UnkStruct_0035F060_1 {
    short field_0;
    unsigned short field_2;
};

struct UnkStruct_0035F060 {
    unsigned short field_0;
};

extern "C" unsigned short * PrintUTFChar__15CGtUnicodeUtilsFPUsUs(unsigned short * s, int p0)
{
    while (*s != 0) {
        s++;
    }
    s[0] = p0;
    s[1] = 0;
    return s + 1;
}
