// Hand-written; the lifter refused it (memcard FSM Action cloned from func_003FE1F0: swap inline, jump-table cases in block order (0,1,2,4,5,6,7,8,9/18,16,17,15), no default).

// func_003FF540 -- hand-written (L254) from the asm after the proven sibling func_003FE1F0 (same file).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction widths).
// [L] DNAT: CB3MCMasterPreSaveCheckState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

struct UnkStruct_003FF540;
struct UnkStruct_003FF540_3;
struct UnkStruct_003FF540_5;

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
    UnkStruct_003FF540_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FF540_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01ECD964 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FF540_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FF540 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
};

extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(int, void *);

// inlined swap helper (placeholder name), as func_003FE1F0 [G]
static inline void func_003FF540_inl1(UnkStruct_003FF540_5 * r, int flag)
{
    if (D_01ECD954.field_0 != r) {
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r, flag);
        void * t0 = D_01ECD954.field_0;
        D_01ECD954.field_0 = (void *)r;
        UnkStruct_003FF540_3 * t1 = D_01ECD960.field_0;
        if (t1 != 0) {
            D_01ECD964.field_0 = t1->field_20;
            if (r != 0) {
                r->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t0, flag);
    }
}

#define SWAP(id) func_003FF540_inl1((UnkStruct_003FF540_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, id), 0)

// 0x003FF540
extern "C" void func_003FF540(UnkStruct_003FF540 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        SWAP(0x93D12267661960F7);
        self->field_10 = 1;
        self->field_14 = 0;
        break;
    case 4:
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_10();
        break;
    case 5:
        switch (p2) {
        case 0:
            if (self->field_14 == 0) {
                SWAP(0x93D1226773392A6F);
            }
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x30, (void *)(0));
            break;
        case 1:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x31, (void *)(0));
            self->field_14 = 0;
            break;
        case 2:
            self->field_14 = 1;
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x32, (void *)(0));
            break;
        case 4:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x33, (void *)(0));
            break;
        case 5:
            SWAP(0x93D122679C8FCA23);
            self->field_10 = 0;
            break;
        case 6:
            SWAP(0x93D12267661960F7);
            break;
        case 7:
            self->field_14 = 1;
            SWAP(0x93D12267661960F7);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x2F, (void *)(0));
            break;
        case 8:
            self->field_14 = 1;
            SWAP(0x93D12267661960F7);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x2E, (void *)(0));
            break;
        case 9:
        case 18:
            self->field_14 = 1;
            self->field_10 = 0;
            SWAP(0x93D12267661960F7);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x3A, (void *)(0));
            break;
        case 16:
            self->field_14 = 1;
            self->field_10 = 0;
            SWAP(0x93D12267661960F7);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x38, (void *)(0));
            break;
        case 17:
            self->field_14 = 1;
            self->field_10 = 0;
            SWAP(0x93D12267661960F7);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x39, (void *)(0));
            break;
        case 15:
            SWAP(0x93D12267661960F7);
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(0x36, (void *)(0));
            break;
        }
        break;
    case 2:
        break;
    }
}
