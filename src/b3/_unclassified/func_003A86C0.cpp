// func_003A86C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_8E6 test wraps body, then-arm order swapped (field_250==0 first), 1 < field_9B8 compares, stack-temp structs).

// func_003A86C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_003A86C0;
struct UnkStruct_003A86C0_3;
struct UnkStruct_003A86C0_4;
struct UnkStruct_003A86C0_5;
struct UnkStruct_D_004CA060;
struct UnkStruct_D_004CA070;

struct UnkStruct_D_004CA070 {
    u_long128 field_0;
};

struct UnkStruct_D_004CA060 {
    u_long128 field_0;
};

struct UnkStruct_003A86C0_3 {
    u_long128 field_0;
    unsigned char pad_10[0x20];
    u_long128 field_30;
};

struct UnkStruct_003A86C0_4 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003A86C0_5 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003A86C0 {
    unsigned char pad_0[0x220];
    UnkStruct_003A86C0_4 * field_220;
    UnkStruct_003A86C0_5 * field_224;
    unsigned char pad_228[0x28];
    unsigned short field_250;
    unsigned char pad_252[0x694];
    unsigned char field_8E6;
    unsigned char pad_8E7[0xCD];
    int field_9B4;
    int field_9B8;
    unsigned char pad_9BC[0x4];
    int field_9C0[1];  // [G] element count unknown
};

extern UnkStruct_D_004CA070 D_004CA070;
extern UnkStruct_D_004CA060 D_004CA060;

extern "C" int func_00319360(void *);
extern "C" void func_003AB640(UnkStruct_003A86C0 *);

struct UnkStruct_003A86C0_L { u_long128 field_0; };
// [G] 0x30 bytes: the frame keeps 0x20 bytes past this temp (retail sp+0x10, the other at sp+0x40)
struct UnkStruct_003A86C0_M { u_long128 field_0; unsigned char pad_10[0x20]; };
// 0x003A86C0
extern "C" int func_003A86C0(UnkStruct_003A86C0 * self)
{
    if (self->field_8E6 != 0) {
        if (self->field_250 == 0) {
            u_long128 v3;
            if (1 < self->field_9B8) {
                v3 = D_004CA060.field_0;
            } else {
                v3 = D_004CA070.field_0;
            }
            UnkStruct_003A86C0_4 * t2 = self->field_220;
            UnkStruct_003A86C0_L l1;
            l1.field_0 = D_004CA060.field_0;
            if (t2 != 0) {
                t2->field_10 = v3;
            }
            UnkStruct_003A86C0_5 * t3 = self->field_224;
            if (t3 != 0) {
                t3->field_10 = l1.field_0;
            }
            int t4 = self->field_9B8;
            if (t4 > 0) {
                self->field_9B8 = (t4 + -1);
                self->field_9B4 = self->field_9C0[self->field_9B8];
                func_003AB640(self);
                return 1;
            }
            return 0;
        } else {
            u_long128 v0;
            if (1 < self->field_9B8) {
                v0 = D_004CA060.field_0;
            } else {
                v0 = D_004CA070.field_0;
            }
            UnkStruct_003A86C0_4 * t0 = self->field_220;
            UnkStruct_003A86C0_M l0;
            l0.field_0 = D_004CA060.field_0;
            if (t0 != 0) {
                t0->field_10 = v0;
            }
            UnkStruct_003A86C0_5 * t1 = self->field_224;
            if (t1 != 0) {
                t1->field_10 = l0.field_0;
            }
            self->field_9B8 = (self->field_9B8 + -1);
            return func_00319360(((char *)self + 0x250));
        }
    }
    return func_00319360(((char *)self + 0x250));
}
