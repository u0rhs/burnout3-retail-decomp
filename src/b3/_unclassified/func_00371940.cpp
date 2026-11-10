// Hand-written; the lifter refused it (loader FSM; switch early test; src advanced in place; sibling of func_00371420).

struct UnkStruct_71940_file { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(void *, int); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual int vfunc_24(); };
struct UnkStruct_71940_row { unsigned long field_0; int field_8; int field_C; };
struct UnkStruct_71940 {
    UnkStruct_71940_row field_0[1];
    unsigned char pad_10[0x6B0];
    int field_6C0;
    unsigned char pad_6C4[0x4];
    void *field_6C8[8];
    unsigned char pad_6E8[0x20];
    void *field_708;
    unsigned char pad_70C[0x4];
    UnkStruct_71940_file *field_710;
    signed char field_714;
};
struct UnkStruct_D_004F60C0 { void *field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0x10 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_0x10 theMemMgr;
extern char D_004C8200[];
extern "C" UnkStruct_71940_file *Open__13CGTFileSystemFPCcUi(void *, const char *, unsigned int);
extern "C" void *AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
// 0x00371940
extern "C" int func_00371940(UnkStruct_71940 * self)
{
    if (self->field_710 != 0) {
        int s = self->field_710->vfunc_24();
        switch (s) {
        case 2:
        case 0:
            return 0;
        default:
            break;
        }
    }
    if (self->field_708 == 0) {
        self->field_708 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x16, 0);
        if (self->field_708 == 0) return 0;
    }
    switch (self->field_6C0) {
    case 1:
    case 2:
        self->field_710 = Open__13CGTFileSystemFPCcUi(D_004F60C0.field_0, D_004C8200, 0x11);
        if (self->field_710 != 0) self->field_6C0 = 3;
        break;
    case 3:
        self->field_710->vfunc_10(self->field_708, 0x800);
        self->field_6C0 = 4;
        break;
    case 4: {
        UnkStruct_71940_row *src = (UnkStruct_71940_row *)self->field_708;
        self->field_714 = *(int *)src;
        src = (UnkStruct_71940_row *)((char *)src + 8);
        int i;
        for (i = 0; i < self->field_714; i++) {
            self->field_0[i] = src[i];
        }
        self->field_710->vfunc_C();
        self->field_710 = 0;
        ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x16, 0);
        self->field_6C0 = 5;
    }
    case 5: {
        int i = 0;
        for (; i < 8; i++) {
            if (self->field_6C8[i] == 0) {
                self->field_6C8[i] = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x15, i);
                if (self->field_6C8[i] == 0) break;
            }
        }
        self->field_6C0 = 0x17;
    }
    case 0x17:
        return 1;
    }
    return 0;
}
