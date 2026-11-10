// Hand-written; the lifter refused it (a140: sibling of func_0026C190 shape; case-1 via goto so return blocks precede body; hoisted file-name ptr).

struct UnkStruct_D_004F60C0_o {
    virtual void vfunc_8();
    virtual int vfunc_C();
};
struct UnkStruct_D_004F60C0 { UnkStruct_D_004F60C0_o *field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_26C480_file {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20();
    virtual int vfunc_24();
    int pad_4;
    int field_8;
};
struct UnkStruct_26C190_ent { unsigned long field_0; int field_8; int field_C; };
struct UnkStruct_26C190_hdr { int field_0; int field_4; UnkStruct_26C190_ent field_8[1]; };
struct UnkStruct_26C190 {
    unsigned char pad_0[0x329D0];
    UnkStruct_26C190_hdr *field_329D0;
    char *field_329D4;
    char *field_329D8;
    unsigned short *field_329DC;
    unsigned char field_329E0;
    unsigned char pad_329E1[2];
    unsigned char field_329E3;
    UnkStruct_26C480_file *field_329E4;
    unsigned char pad_329E8[4];
    int field_329EC;
    int field_329F0;
    int field_329F4;
};
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern char D_004BCA90[];
struct UnkStruct_D_004F6100 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004F6100 D_004F6100;
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
extern UnkStruct_theMemMgr theMemMgr;
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" int QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(void *, const char *, void *, void *, unsigned int);
extern "C" UnkStruct_26C480_file *Open__13CGTFileSystemFPCcUi(void *, const char *, unsigned int);
extern char D_004BCA50[];
extern char D_004BCA58[];
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" int strncmp(const char *, const char *, unsigned int);

// 0x0026C480
extern "C" int func_0026C480(UnkStruct_26C190 *self)
{
    switch (D_004F60C0.field_0->vfunc_C()) {
    case 0:
    case 1:
    case 5:
        break;
    case 2:
    case 3:
    case 4:
    default:
        self->field_329E3 = 1;
        break;
    }
    self->field_329EC = 10;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC, 0x544, func_00271A00(&D_0051BA44, 0xD50));
    int n = Length__10CGtUnicodeFPCUs(self->field_329DC);
    self->field_329DC[n] = 0xA;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD51));
    n = Length__10CGtUnicodeFPCUs(self->field_329DC);
    self->field_329DC[n] = 0xA;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD52));
    const char *nm = D_004BCA90;
    if (self->field_329E4 == 0) {
        self->field_329E4 = Open__13CGTFileSystemFPCcUi(D_004F60C0.field_0, nm, 0x11);
    }
    if (self->field_329E4 == 0) return 0;
    switch (self->field_329E4->vfunc_24()) {
    case 1:
        goto one;
    case 3:
        return 0;
    case 2:
    case 0:
    default:
        break;
    }
    return 0;
    one: {

        unsigned int sz = self->field_329E4->field_8;
        self->field_329E4->vfunc_C();
        self->field_329E4 = 0;
        if ((sz & 0x7FF) != 0) sz = ((sz >> 11) + 1) << 11;
        self->field_329D0 = (UnkStruct_26C190_hdr *)AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x18, 0);
        int m = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 0x18);
        memset(self->field_329D0, 0xCC, m);
        self->field_329E0 = 0;
        self->field_329F0 = QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(&D_004F6100, nm, &self->field_329E0, self->field_329D0, sz);
        return 1;
    }
}
