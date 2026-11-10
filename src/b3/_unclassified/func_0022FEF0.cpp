// func_0022FEF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022FEF0;
struct UnkStruct_0022FEF0_a1;
struct UnkStruct_0022FEF0_e0;
struct UnkStruct_0022FEF0_e1;
struct UnkStruct_0022FEF0_e2;

struct UnkStruct_0022FEF0_a1 {
    unsigned char pad_0[0x2];
    unsigned char field_2;
    signed char field_3;
};

struct UnkStruct_0022FEF0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0022FEF0_e1 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[0x4];
};

struct UnkStruct_0022FEF0_e2 {
    unsigned char pad_0[0x18];
};

struct UnkStruct_0022FEF0 {
    UnkStruct_0022FEF0_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_18[0x240];
    UnkStruct_0022FEF0_e0 field_258[1];  // [G] element count unknown
    UnkStruct_0022FEF0_e1 field_270[1];  // [G] element count unknown
    unsigned char pad_288[0x224];
    int field_4AC;
};

// 0x0022FEF0
extern "C" void func_0022FEF0(UnkStruct_0022FEF0 * self, UnkStruct_0022FEF0_a1 * p0)
{
    int t0 = self->field_4AC;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (self->field_258[i].field_14 != p0->field_3) {
            goto loop0_next;
        }
        int t1 = self->field_270[i].field_C;
        if (t1 != 0) {
            if (((p0->field_2 & 2) != 0) != false) {
                ((void (*)(int, UnkStruct_0022FEF0_a1 *, int, void *, int, int))t1)(1, p0, self->field_270[i].field_10, &self->field_0[i], t0, i);
            } else {
                ((void (*)(int, UnkStruct_0022FEF0_a1 *, int, void *, int, int))t1)(0, p0, self->field_270[i].field_10, &self->field_0[i], t0, i);
            }
            goto loop0_end;
        }
        return;
    }
loop0_next:
    i++;
loop0_test:
    if ((i < t0) != false) goto loop0_body;
loop0_end:;
}
