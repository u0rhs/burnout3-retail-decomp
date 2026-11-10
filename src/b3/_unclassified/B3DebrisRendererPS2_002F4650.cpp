// CB3DebrisArray::UploadStaticDataAndGeometry(bool) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: pcpyld halves via asm, local farFogPlane pointer, unsigned long n).

// [L] pcpyld-built VIF/DMA tag quads appended at farFogPlane (gp); types [G] (instruction widths), halves per a73 pcpyld idiom.
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_002F4650_1 {
    unsigned int field_0;
};

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class CB3DebrisArray {
public:
    unsigned char pad_0[0x10];
    UnkStruct_002F4650_1 * field_10;
    void UploadStaticDataAndGeometry(bool) const;
};

extern UnkStruct_farFogPlane farFogPlane;

// 0x002F4650
void CB3DebrisArray::UploadStaticDataAndGeometry(bool b) const
{
    u_long128 * p = farFogPlane.field_0;
    if (b) {
        u_long128 q0;
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000), "r"(0x10000000));
        *p = q0;
        p++;
    }
    unsigned long n = (unsigned int)((field_10->field_0 & 0x7FFF) + 1);
    unsigned long lo = ((unsigned long)(unsigned int)field_10 << 32) | (n | 0x30000000);
    unsigned long hi = ((unsigned long)(unsigned int)(((int)n << 16) | 0x6C0003B5) << 32) | 0x1000101;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(lo), "r"(hi));
    *p = q1;
    farFogPlane.field_0 = p + 1;
}
