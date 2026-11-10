// func_003FE1F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two swap-block static inline helpers, all exits break, GetFreeSpace test as (unsigned)x > 61772 (slt at form)).

// lifter variant 0
// func_003FE1F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CMemoryDevicePS2;
struct UnkStruct_003FE1F0;
struct UnkStruct_003FE1F0_12;
struct UnkStruct_003FE1F0_14;
struct UnkStruct_003FE1F0_15;
struct UnkStruct_003FE1F0_16;
struct UnkStruct_003FE1F0_17;
struct UnkStruct_003FE1F0_18;
struct UnkStruct_003FE1F0_19;
struct UnkStruct_003FE1F0_20;
struct UnkStruct_003FE1F0_21;
struct UnkStruct_003FE1F0_3;
struct UnkStruct_003FE1F0_5;
struct UnkStruct_003FE1F0_6;
struct UnkStruct_003FE1F0_8;
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
    int GetFreeSpace();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_003FE1F0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FE1F0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01ECD964 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FE1F0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_6 {
    unsigned char pad_0[0x10];
    int field_10;
    unsigned char pad_14[0x4];
    int field_18;
    int field_1C;
};

struct UnkStruct_003FE1F0_8 {
    unsigned char pad_0[0x8];
    float field_8;
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
    UnkStruct_003FE1F0_12 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FE1F0_12 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EB5D14 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FE1F0_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_15 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003FE1F0_16 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_17 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_18 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_19 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_20 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0_21 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FE1F0 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
};

extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;
extern UnkStruct_D_01EB5D04 D_01EB5D04;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01EB5D10 D_01EB5D10;
extern UnkStruct_D_01EB5D14 D_01EB5D14;
extern CMemoryDevicePS2 D_005185A0;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(int, void *);

// inlined swap helpers (placeholder names) [G]
static inline void func_003FE1F0_inl1(UnkStruct_003FE1F0_5 * r, int flag)
{
    if (D_01ECD954.field_0 != r) {
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r, flag);
        void * t0 = D_01ECD954.field_0;
        D_01ECD954.field_0 = (void *)r;
        UnkStruct_003FE1F0_3 * t1 = D_01ECD960.field_0;
        if (t1 != 0) {
            D_01ECD964.field_0 = t1->field_20;
            if (r != 0) {
                r->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t0, flag);
    }
}

static inline void func_003FE1F0_inl2(UnkStruct_003FE1F0_5 * r, int flag)
{
    if (D_01EB5D04.field_0 != r) {
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_18(r, flag);
        void * t0 = D_01EB5D04.field_0;
        D_01EB5D04.field_0 = (void *)r;
        UnkStruct_003FE1F0_12 * t1 = D_01EB5D10.field_0;
        if (t1 != 0) {
            D_01EB5D14.field_0 = t1->field_20;
            if (r != 0) {
                r->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_1C(t0, flag);
    }
}

// 0x003FE1F0
extern "C" void func_003FE1F0(UnkStruct_003FE1F0 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_003FE1F0_inl1((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267661960F7), 0);
        self->field_10 = 1;
        self->field_14 = 0;
        break;
    case 4:
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_10();
        break;
    case 5:
        switch (p2) {
        case 0:
            if ((unsigned int)D_005185A0.GetFreeSpace() > 61772) {
                func_003FE1F0_inl1((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267889D607F), 0);
                func_003FE1F0_inl2((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00AA95607F), 0);
                ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(46, (void *)(0));
            } else {
                func_003FE1F0_inl1((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267889D607F), 0);
                func_003FE1F0_inl2((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00AA95607F), 0);
                ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(47, (void *)(0));
            }
            break;
        case 4:
            func_003FE1F0_inl1((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267889D607F), 0);
            func_003FE1F0_inl2((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00AA95607F), 0);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(46, (void *)(0));
            break;
        case 1:
            func_003FE1F0_inl1((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267889D607F), 0);
            func_003FE1F0_inl2((UnkStruct_003FE1F0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00AA95607F), 0);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(49, (void *)(0));
            self->field_14 = 0;
            break;
        }
        break;
    case 2:
        break;
    }
}
