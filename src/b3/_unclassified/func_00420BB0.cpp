// OnFormatSuccess__24CB3MemCardControllerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two inlined FSM state-change blocks (if cur != r {...}, not early return); globals declared non-polymorphic and cast so the vfunc calls stay virtual; uint64 hash ?: default).

struct UnkStruct_00420BB0_1;
struct UnkStruct_00420BB0_4;

struct UnkStruct_00420BB0_1 {
    unsigned long field_0;
    float field_8;
};

struct UnkStruct_00420BB0_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00420BB0_1 *, int);
    virtual void vfunc_1C(UnkStruct_00420BB0_1 *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D04 {
    UnkStruct_00420BB0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D10 {
    UnkStruct_00420BB0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D14 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D00_g {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EB5D00_g D_01EB5D00;
extern UnkStruct_D_01EB5D04 D_01EB5D04;
extern UnkStruct_D_01EB5D10 D_01EB5D10;
extern UnkStruct_D_01EB5D14 D_01EB5D14;
extern UnkStruct_D_01EB5D00_g D_01ECD950;
extern UnkStruct_D_01EB5D04 D_01ECD954;
extern UnkStruct_D_01EB5D10 D_01ECD960;
extern UnkStruct_D_01EB5D14 D_01ECD964;

extern "C" UnkStruct_00420BB0_1 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00420BB0
extern "C" void OnFormatSuccess__24CB3MemCardControllerBaseFv(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_00420BB0_1 * t0 = D_01EB5D04.field_0;
    unsigned long v;
    if (t0 != 0) {
        v = t0->field_0;
    } else {
        v = 0x6D6123044330FCCF;
    }
    if (v == 0x93CB4D00E7330B63) {
        UnkStruct_00420BB0_1 * r = GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267C53B0B63);
        if (D_01ECD954.field_0 != r) {
            ((UnkStruct_D_01EB5D00 *)&D_01ECD950)->vfunc_18(r, 1);
            UnkStruct_00420BB0_1 * old = D_01ECD954.field_0;
            D_01ECD954.field_0 = r;
            UnkStruct_00420BB0_4 * t = D_01ECD960.field_0;
            if (t != 0) {
                D_01ECD964.field_0 = t->field_20;
                if (r != 0) {
                    r->field_8 = t->field_20;
                }
            }
            ((UnkStruct_D_01EB5D00 *)&D_01ECD950)->vfunc_1C(old, 1);
        }
    } else {
        UnkStruct_00420BB0_1 * r = GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00E7330B63);
        if (D_01EB5D04.field_0 != r) {
            ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_18(r, 1);
            UnkStruct_00420BB0_1 * old = D_01EB5D04.field_0;
            D_01EB5D04.field_0 = r;
            UnkStruct_00420BB0_4 * t = D_01EB5D10.field_0;
            if (t != 0) {
                D_01EB5D14.field_0 = t->field_20;
                if (r != 0) {
                    r->field_8 = t->field_20;
                }
            }
            ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_1C(old, 1);
        }
    }
}
