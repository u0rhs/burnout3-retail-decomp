// CB3PopcornArray::Construct(EPopcornArrayID) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near21: last/rem after header stores; hi local for the DMA quad; integer-sum field_1C).

// near21: GIF/DMA header block: the quad high word in its own local (`hi | lo`) gives retail or-operand order;
// field_1C as an integer sum (hdr*16 + field_20) gives its addu order; last/rem computed after the two header stores.

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_00366160_par {
    unsigned char pad_0[4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x3C];
    float field_48;
    float field_4C;
};
extern UnkStruct_00366160_par maStandardParams__19CB3PopcornArrayBase[];
extern unsigned long _gu64PopcornBlendModes[];
enum EPopcornArrayID {};
extern "C" {
void *Alloc__17CB3EffectsManagerFUiUi(unsigned int, unsigned int);
void *memset(void *, int, unsigned int);
void SyncDCache(void *, void *);
}
class CB3PopcornArray {
public:
    void Construct(EPopcornArrayID);
    u_long128 field_0;
    float field_10;
    float field_14;
    float field_18;
    char *field_1C;
    char *field_20;
    int field_24;
    int field_28;
    int field_2C;
    UnkStruct_00366160_par *field_30;
};
// 0x00366160
void CB3PopcornArray::Construct(EPopcornArrayID id)
{
    unsigned long *q;
    field_30 = &maStandardParams__19CB3PopcornArrayBase[id];
    field_10 = field_30->field_48;
    field_14 = -1.0f / field_30->field_48;
    field_18 = -field_30->field_4C;
    field_24 = field_30->field_4;
    int n4 = field_24 / 4;
    int nb = (n4 + 19) / 20;
    int hdr = 1;
    hdr += nb * 2;
    int bytes = (hdr + n4 * 9) * 16;
    field_20 = (char *)Alloc__17CB3EffectsManagerFUiUi(bytes, 0x80);
    memset(field_20, 0, bytes);
    field_1C = (char *)(hdr * 16 + (int)field_20);
    q = (unsigned long *)field_20;
    q[0] = 0x10000000;
    q[1] = (unsigned long)0x05000000 << 32;
    q += 2;
    int last = nb - 1;
    int rem = n4 - last * 20;
    for (int i = 0; i < nb; i++) {
        int cnt = (i < last) ? 20 : rem;
        unsigned int c9 = cnt * 9;
        unsigned long hi = (unsigned long)(unsigned int)(field_1C + i * 2880) << 32;
        q[0] = hi | (unsigned long)(int)(c9 | 0x30000000);
        q[1] = ((unsigned long)(unsigned int)((c9 << 16) | 0x6C008000) << 32) | 0x01000101;
        if (i < last) { q[2] = 0x10000000; q += 3; }
        else { q[2] = 0x60000000; q += 3; }
        if (i == 0) { q[0] = (unsigned long)(unsigned int)(cnt | 0x04000000) | ((unsigned long)0x15000000 << 32); q += 1; }
        else { q[0] = (unsigned long)(unsigned int)(cnt | 0x04000000) | ((unsigned long)0x17000000 << 32); q += 1; }
    }
    SyncDCache(field_20, field_20 + bytes - 1);
    field_2C = 0;
    unsigned long hi = 0x42;
    unsigned long blend = _gu64PopcornBlendModes[field_30->field_8];
    u_long128 pk;
    asm("pcpyld %0,%2,%1" : "=r"(pk) : "r"(blend), "r"(hi));
    field_0 = pk;
}
