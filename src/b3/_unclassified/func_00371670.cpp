// func_00371670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (4 params (lifter's 8 were phantoms); name buf via func_0021AB40; blk char-array strcmp/strcasecmp; null-tested slot as char*; slot=(p0<<2)+(int)self+0x6C8).

struct UnkStruct_00371670 {
    unsigned char pad_0[0x6C8];
    int field_6C8[1];
    unsigned char pad_6CC[0x1C];
    int field_6E8[1];
};
struct UnkStruct_00371670_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_00371670_rec { unsigned char pad_0[8]; int field_8; unsigned char pad_C[4]; };
struct UnkStruct_00371670_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00371670_rec * field_C;
};
struct UnkStruct_00371670_tex { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_D_0051A868 {
    UnkStruct_00371670_4 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" char *CreateCopy__10CGtTextureFUi(void *, void *, int);
extern "C" int strcmp(const char *, const char *);
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int strcasecmp(const char *, char *);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
// 0x00371670
extern "C" int func_00371670(UnkStruct_00371670 * self, int p0, unsigned long p1, int p2)
{
    char name[0x10];
    func_0021AB40(p1, name);
    int *slot = (int *)((p0 << 2) + (int)self + 0x6C8);
    char *t0 = (char *)*slot;
    if (t0 == 0 || strcmp(((UnkStruct_00371670_blk *)((int)t0 + 0x90))->field_18, name) != 0) {
        int tex;
        UnkStruct_00371670_4 * t1 = D_0051A868.field_0;
        for (int i = 0; i < t1->field_8; i++) {
            tex = t1->field_C[i].field_8;
            if (strcasecmp(((UnkStruct_00371670_blk *)(tex + 0x90))->field_18, name) == 0) goto found;
        }
        tex = 0;
found:
        CreateCopy__10CGtTextureFUi((void *)tex, (void *)*slot, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 21));
        self->field_6E8[p0] = p2 % ((UnkStruct_00371670_tex *)tex)->field_A0;
    }
    return 1;
}
