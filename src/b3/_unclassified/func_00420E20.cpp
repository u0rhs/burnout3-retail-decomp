// OnMemCardPageExit__24CB3MemCardControllerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_..04 store before the D_..10 load (as StartFormat__24CB3MemCardControllerBaseFv); GetError test merged: if (r != 0 && r != 13)).

// OnMemCardPageExit__24CB3MemCardControllerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EMemDevPollOrWait {};

class CMemoryDevicePS2;
struct UnkStruct_00420E20_11;
struct UnkStruct_00420E20_3;
struct UnkStruct_00420E20_5;
struct UnkStruct_00420E20_9;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01EB5D04;
struct UnkStruct_D_01EB5D10;
struct UnkStruct_D_01EB5D14;
struct UnkStruct_D_01ECD950;
struct UnkStruct_D_01ECD954;
struct UnkStruct_D_01ECD960;
struct UnkStruct_D_01ECD964;

class CMemoryDevicePS2 {
public:
    int GetError();
    void Sync(EMemDevPollOrWait, int*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D04 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D10 {
    UnkStruct_00420E20_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00420E20_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EB5D14 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00420E20_5 {
    unsigned char pad_0[0x8];
    float field_8;
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD960 {
    UnkStruct_00420E20_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00420E20_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01ECD964 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00420E20_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

extern UnkStruct_D_01EB5D04 D_01EB5D04;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01EB5D10 D_01EB5D10;
extern UnkStruct_D_01EB5D14 D_01EB5D14;
extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;
extern CMemoryDevicePS2 D_005185A0;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00420E20
extern "C" void OnMemCardPageExit__24CB3MemCardControllerBaseFv(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_00420E20_5 * r0 = (UnkStruct_00420E20_5 *)GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00AA95607F);
    if (D_01EB5D04.field_0 != r0) {
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_18(r0, 0);
        void * t0 = D_01EB5D04.field_0;
        D_01EB5D04.field_0 = (void *)r0;
        UnkStruct_00420E20_3 * t1 = D_01EB5D10.field_0;
        if (t1 != 0) {
            D_01EB5D14.field_0 = t1->field_20;
            if (r0 != 0) {
                r0->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_1C(t0, 0);
    }
    UnkStruct_00420E20_11 * r3 = (UnkStruct_00420E20_11 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267889D607F);
    if (D_01ECD954.field_0 != r3) {
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r3, 0);
        void * t2 = D_01ECD954.field_0;
        D_01ECD954.field_0 = (void *)r3;
        UnkStruct_00420E20_9 * t3 = D_01ECD960.field_0;
        if (t3 != 0) {
            D_01ECD964.field_0 = t3->field_20;
            if (r3 != 0) {
                r3->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t2, 0);
    }
    int r6 = D_005185A0.GetError();
    if (r6 != 0 && r6 != 13) {
        D_005185A0.Sync((EMemDevPollOrWait)1, 0);
    }
}
