// FindUTFChar__15CGtUnicodeUtilsFPUsUs -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0035F020_0;

struct UnkStruct_0035F020_0 {
    unsigned short field_0;
};

// 0x0035F020
extern "C" UnkStruct_0035F020_0 * FindUTFChar__15CGtUnicodeUtilsFPUsUs(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (UnkStruct_0035F020_0 * q = (UnkStruct_0035F020_0 *)n0; (q->field_0 != 0); q++) {
        if (q->field_0 == (p0 & 65535)) {
            return q;
        }
    }
    return 0;
}
