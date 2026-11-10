// Hand-written; the lifter refused it (if/else on the id with != arm first; swap blocks store D_xx04 before loading D_xx10; GetStateFromID__6CGtFSMFUl takes 2 args).

// StartLoadProfileFlow__24CB3MemCardControllerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00421190_10;
struct UnkStruct_00421190_11;
struct UnkStruct_00421190_14;
struct UnkStruct_00421190_16;
struct UnkStruct_00421190_17;
struct UnkStruct_00421190_3;
struct UnkStruct_00421190_8;
struct UnkStruct_00421190_e0;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01EB5D04;
struct UnkStruct_D_01EB5D10;
struct UnkStruct_D_01EB5D14;
struct UnkStruct_D_01EB5D60;
struct UnkStruct_D_01EBE3B0;
struct UnkStruct_D_01ECD950;
struct UnkStruct_D_01ECD954;
struct UnkStruct_D_01ECD960;
struct UnkStruct_D_01ECD964;

struct UnkStruct_00421190_e0 {
    unsigned char pad_0[0x1B3];
    unsigned char field_1B3;
    unsigned char pad_1B4[0x2E8];
};

struct UnkStruct_D_01EBE3B0 {
    unsigned char pad_0[0xE678];
    UnkStruct_00421190_e0 field_E678[1];  // [G] element count unknown
};

struct UnkStruct_D_01EB5D04 {
    UnkStruct_00421190_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421190_3 {
    unsigned long field_0;
};

struct UnkStruct_D_01EB5D60 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD954 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD950 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00421190_10 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD960 {
    UnkStruct_00421190_8 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421190_8 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01ECD964 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421190_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00421190_11 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00421190_16 *, int);
    virtual void vfunc_1C(UnkStruct_00421190_3 *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D10 {
    UnkStruct_00421190_14 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421190_14 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EB5D14 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421190_16 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00421190_17 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

extern UnkStruct_D_01EBE3B0 D_01EBE3B0;
extern UnkStruct_D_01EB5D04 D_01EB5D04;
extern UnkStruct_D_01EB5D60 D_01EB5D60;
extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01EB5D10 D_01EB5D10;
extern UnkStruct_D_01EB5D14 D_01EB5D14;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00421190
extern "C" void StartLoadProfileFlow__24CB3MemCardControllerBaseFv(void *a0 /* passed by every caller, not read here */)
{
    for (int i = 0; i < 3; i++) {
        D_01EBE3B0.field_E678[i].field_1B3 = 1;
    }
    UnkStruct_00421190_3 * t0 = D_01EB5D04.field_0;
    unsigned long v0;
    if (t0 != 0) {
        v0 = t0->field_0;
    } else {
        v0 = 0x6D6123044330FCCF;
    }
    if (v0 != 0x93CB4D00BE87CA23) {
        UnkStruct_00421190_16 * r3 = (UnkStruct_00421190_16 *)GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00BE87CA23);
        if (D_01EB5D04.field_0 == (void *)r3) return;
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_18(r3, 0);
        UnkStruct_00421190_3 * t3 = D_01EB5D04.field_0;
        D_01EB5D04.field_0 = (UnkStruct_00421190_3 *)r3;
        UnkStruct_00421190_14 * t4 = D_01EB5D10.field_0;
        if (t4 != 0) {
            D_01EB5D14.field_0 = t4->field_20;
            if (r3 != 0) {
                r3->field_8 = t4->field_20;
            }
        }
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_1C(t3, 0);
    } else {
        D_01EB5D60.field_0 = 0;
        UnkStruct_00421190_10 * r0 = (UnkStruct_00421190_10 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267661960F7);
        if (D_01ECD954.field_0 == r0) return;
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r0, 0);
        void * t1 = D_01ECD954.field_0;
        D_01ECD954.field_0 = (void *)r0;
        UnkStruct_00421190_8 * t2 = D_01ECD960.field_0;
        if (t2 != 0) {
            D_01ECD964.field_0 = t2->field_20;
            if (r0 != 0) {
                r0->field_8 = t2->field_20;
            }
        }
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t1, 0);
    }
}
