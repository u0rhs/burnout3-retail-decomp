// func_004474F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BAC8.h"

struct UnkStruct_004474F0_2;
struct UnkStruct_004474F0_3;
struct UnkStruct_004474F0_4;
struct UnkStruct_004474F0_5;
struct UnkStruct_004474F0_6;
struct UnkStruct_004474F0_7;
struct UnkStruct_004474F0_a2;

struct UnkStruct_004474F0_a2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_004474F0_6 * field_10;
    float field_14;
};

struct UnkStruct_004474F0_2 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_004474F0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_004474F0_4 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004474F0_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_004474F0_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_004474F0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

extern UnkStruct_D_0051BAC8 D_0051BAC8;
extern "C" int func_004474A0(void *, void *);
extern "C" void func_004471A0(void *, float);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x004474F0
extern "C" void func_004474F0(int n0, int p0, void *p1_v, int p2, int p3)
{
    UnkStruct_004474F0_a2 * p1 = (UnkStruct_004474F0_a2 *)p1_v;  // N215 void* cast-copy (sreg)
    switch (p0) {
    default:
        return;
    case 3:
        func_004474A0(((char *)p1 + 0x50), (void *)(p3));
        return;
    case 4:
        func_004471A0(((char *)p1 + 0x50), D_0051BAC8.field_0);
    case 5:
        switch (p2) {
        case 14: {
            UnkStruct_004474F0_7 * r = (UnkStruct_004474F0_7 *)GetStateFromID__6CGtFSMFUl(p1, 0xBA38E6DC828A38A1UL);
            if (p1->field_4 == r) return;
            p1->vfunc_18(r, p3);
            void * t = p1->field_4;
            p1->field_4 = (void *)r;
            UnkStruct_004474F0_6 * t3 = p1->field_10;
            if (t3 != 0) {
                p1->field_14 = t3->field_20;
                if (r != 0) {
                    r->field_8 = p1->field_10->field_20;
                }
            }
            p1->vfunc_1C(t, p3);
        }
        }
    case 2:
        break;
    }
}
