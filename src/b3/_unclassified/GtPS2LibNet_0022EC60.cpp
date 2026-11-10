// CGtPS2LibNet::ReceiveFrom(void**,int*,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near15: ring read index field_6C8 volatile (retail reloads it at every use)).

// CGtPS2LibNet::ReceiveFrom(void**, int*, int*) -- hand-written (near15): pops one packet from the ring of 24-byte
// entries at 0x3BC (data, length rounded up to 4, address, port), advancing the read index field_6C8 (wraps at 31).
// The read index is volatile (shared with the receive side). Types and fields are placeholders [G].

struct UnkStruct_ReceiveFrom_pkt {
    void *field_0;
    int field_4;
    unsigned char pad_8[2];
    unsigned short field_A;
    int field_C;
    unsigned char pad_10[8];
};

class CGtPS2LibNet {
public:
    int ReceiveFrom(void **p0, int *p1, int *p2);

    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x3BC - 0x10];
    UnkStruct_ReceiveFrom_pkt field_3BC[32];
    int field_6BC;
    int field_6C0;
    unsigned char pad_6C4[4];
    volatile int field_6C8;   // [L] read index of the receive ring: retail reloads it at every use, even back to back
    int field_6CC;
    int field_6D0;
};

extern "C" int func_002372F8(int);
extern "C" int func_00237320(int);

// 0x0022EC60
int CGtPS2LibNet::ReceiveFrom(void **p0, int *p1, int *p2)
{
    if (field_6C8 == field_6CC) {
        return 0;
    }
    *p0 = field_3BC[field_6C8].field_0;
    int len = field_3BC[field_6C8].field_4;
    *p1 = func_002372F8(field_3BC[field_6C8].field_C);
    *p2 = func_00237320(field_3BC[field_6C8].field_A) & 0xFFFF;
    int n = len;
    int rem = len % 4;
    if (rem != 0) {
        n += 4 - rem;
    }
    field_3BC[field_6C8].field_0 = 0;
    field_6C0 += n;
    if (field_6BC + field_6D0 - field_6C0 < field_C) {
        field_6C0 = field_6BC;
    }
    if (field_6C8 >= 31) {
        field_6C8 = 0;
    } else {
        field_6C8 = field_6C8 + 1;
    }
    return len;
}
