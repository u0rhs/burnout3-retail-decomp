// func_0022FF90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (byte-offset element pointer (i*0x18 + (char*)field_270) keeps i*0x18 in s0; flag ?true:false; ok flag; empty-then 'if (!ok && !two) {} else {memcpy; break;} return;').

struct UnkStruct_0022FF90_4;

struct UnkStruct_0022FF90_a1 {
    unsigned char pad_0[0x2];
    unsigned char field_2;
    signed char field_3;
};

struct UnkStruct_0022FF90_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0022FF90_e1 {
    unsigned char pad_0[0x4];
    UnkStruct_0022FF90_4 * field_4;
    void (*field_8)(UnkStruct_0022FF90_a1 *, int, int);
    unsigned char pad_C[0x4];
    int field_10;
    unsigned char pad_14[0x4];
};

struct UnkStruct_0022FF90_4 {
    unsigned char pad_0[0xC];
    unsigned short field_C;
};

struct UnkStruct_0022FF90 {
    unsigned char pad_0[0x258];
    UnkStruct_0022FF90_e0 field_258[1];  // [G] element count unknown
    UnkStruct_0022FF90_e1 field_270[1];  // [G] element count unknown
    unsigned char pad_288[0x224];
    int field_4AC;
};

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_0022D7E0(UnkStruct_0022FF90_a1 *, int);
extern "C" int func_0022D760(UnkStruct_0022FF90_a1 *, unsigned short);

// 0x0022FF90
extern "C" void func_0022FF90(UnkStruct_0022FF90 * self, UnkStruct_0022FF90_a1 * p0, int p1)
{
    int n = self->field_4AC;
    // [G] the element is reached as a byte offset off field_270 (i*0x18 first) so i*0x18 stays in s0 and
    // the self+offset sum is not CSE'd with the loop's field_258 access.
    for (int i = 0; i < n; i++) {
        if (self->field_258[i].field_14 == p0->field_3) {
            func_0022D7E0(p0, p1);
            if ((p0->field_2 & 1) ? true : false) {
                ((UnkStruct_0022FF90_e1 *)(i * 0x18 + (char *)self->field_270))->field_8(p0, p1, ((UnkStruct_0022FF90_e1 *)(i * 0x18 + (char *)self->field_270))->field_10);
                break;
            }
            bool two = p0->field_3 == 2;
            UnkStruct_0022FF90_4 ** pp = &((UnkStruct_0022FF90_e1 *)(i * 0x18 + (char *)self->field_270))->field_4;
            bool ok = true;
            if ((*pp)->field_C != 0xFFFF) {
                if (func_0022D760(p0, (*pp)->field_C) == 0) ok = false;
            }
            if (!ok && !two) {} else { memcpy(*pp, p0, p1); break; }
            return;
        }
    }
}
