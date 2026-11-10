// CGtFilePS2DVD::Read(void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (n -= c * 0x800 (CSE'd with t = c << 11 gives retail's move v0,s5 copy and the s0/s5 order)).

// CGtFilePS2DVD::Read(void *, unsigned int) -- [C] mangled name from the retail tables; C-linkage definition of the
// mangled symbol (lifter form). near12: `n -= c * 0x800;` (not `n -= t`) -- MWCC CSEs it with t = c << 11 and keeps
// retail's `move v0,s5` copy, which also fixes the c/t s0/s5 assignment in the bulk-DMA block.

struct UnkStruct_001D3280 {
    virtual void vfunc_0();
    virtual void vfunc_4();
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_1C(int);
    unsigned char pad_4[4];
    long field_8;
    long field_10;
    int field_18;
    unsigned char pad_1C[4];
    int field_20;
    unsigned char pad_24[4];
    int field_28;
    unsigned char pad_2C[4];
    int field_30;
    unsigned int field_34;
};
extern "C" int mRPCArguments__13CGtFilePS2DVD[64];
extern "C" int mnRPCSemaphore__13CGtFilePS2DVD;
extern "C" char mRPCData__13CGtFilePS2DVD[0x40];
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
extern "C" int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);
extern "C" void SyncDCache(unsigned int, unsigned int);
extern "C" void *memcpy(unsigned int, unsigned int, unsigned int);

extern "C" int Read__13CGtFilePS2DVDFPvUi(UnkStruct_001D3280 * self, void *p, unsigned int n)
{
    p = (void *)((unsigned int)p & 0x0FFFFFFF);
    long size = self->field_8;
    long pos = self->field_10;
    int ret;
    unsigned int c, t;
    int bad = pos >= size;
    if (bad != 0) return 0;
    if (size < pos + (int)n) {
        long al = (size + 0x7FF) & 0xFFFFF800;
if (pos + n >= al) n = (int)(al - pos);
        else n = (int)(size - pos);
        ret = (int)(size - pos);
    } else {
        ret = n;
    }
    if (self->field_20 != 0) {
        unsigned int b2 = (unsigned int)p & 0x0FFFFFFF;
        SyncDCache(b2, b2 + n - 1);
        self->field_18 = 2;
        self->field_10 = self->field_10 + n;
        mRPCArguments__13CGtFilePS2DVD[0] = self->field_28;
        mRPCArguments__13CGtFilePS2DVD[1] = n / 0x800;
        mRPCArguments__13CGtFilePS2DVD[2] = b2;
        WaitSema(mnRPCSemaphore__13CGtFilePS2DVD);
        sceSifCallRpc(mRPCData__13CGtFilePS2DVD, 5, 0, mRPCArguments__13CGtFilePS2DVD, 0x10, 0, 0, 0, 0);
        SignalSema(mnRPCSemaphore__13CGtFilePS2DVD);
        return ret;
    }
    goto test;
top:
    if (self->field_30 < 0x800) {
        t = self->field_34 | 0x30000000;
        if (self->field_30 == 0) {
            self->field_30 = self->field_30 + (int)(self->field_10 % 0x800);
        }
        {
            int off = self->field_30;
            c = 0x800 - off;
            if (n < c) c = n;
            memcpy((unsigned int)p, t + off, c);
            n -= c;
            if (self->field_8 < self->field_10 + (int)c) c = (int)(self->field_8 - self->field_10);
            self->field_30 = self->field_30 + c;
            p = (void *)((unsigned int)p + c);
            self->field_10 = self->field_10 + (int)c;
        }
    }
    if (n >= 0x800 && ((unsigned int)p & 0xF) == 0 && (self->field_10 % 0x800) == 0) {
        c = n >> 11;
        t = c << 11;
        SyncDCache((unsigned int)p, (unsigned int)p + t - 1);
        self->field_18 = 2;
        self->field_10 = self->field_10 + t;
        mRPCArguments__13CGtFilePS2DVD[0] = self->field_28;
        mRPCArguments__13CGtFilePS2DVD[1] = c;
        mRPCArguments__13CGtFilePS2DVD[2] = (unsigned int)p;
        WaitSema(mnRPCSemaphore__13CGtFilePS2DVD);
        sceSifCallRpc(mRPCData__13CGtFilePS2DVD, 5, 0, mRPCArguments__13CGtFilePS2DVD, 0x10, 0, 0, 0, 0);
        SignalSema(mnRPCSemaphore__13CGtFilePS2DVD);
        self->vfunc_1C(1);
        p = (void *)((unsigned int)p + (int)t);
        n -= c * 0x800;
    }
    if (n != 0) {
        self->field_18 = 2;
        mRPCArguments__13CGtFilePS2DVD[0] = self->field_28;
        mRPCArguments__13CGtFilePS2DVD[1] = 1;
        mRPCArguments__13CGtFilePS2DVD[2] = self->field_34;
        WaitSema(mnRPCSemaphore__13CGtFilePS2DVD);
        sceSifCallRpc(mRPCData__13CGtFilePS2DVD, 5, 0, mRPCArguments__13CGtFilePS2DVD, 0x10, 0, 0, 0, 0);
        SignalSema(mnRPCSemaphore__13CGtFilePS2DVD);
        self->vfunc_1C(1);
        self->field_30 = (int)(self->field_10 % 0x800);
    }
test:
    if (n != 0) goto top;
    return ret;
}
