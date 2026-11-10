// CGtFilePS2DVD::SetPosition(long,EFileMoveMethod) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a95: hand-written extern C; seek add as q=pos; pos=p8; pos+=q to get retail's operand order; vptr slot 0x1C).

struct UnkStruct_001D30B0 {
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
};
extern "C" int mRPCArguments__13CGtFilePS2DVD[64];
extern "C" int mnRPCSemaphore__13CGtFilePS2DVD;
extern "C" char mRPCData__13CGtFilePS2DVD[0x40];
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
extern "C" int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);

extern "C" long SetPosition__13CGtFilePS2DVDFl15EFileMoveMethod(UnkStruct_001D30B0 * self, long pos, int method)
{
    switch (method) {
    default:
        break;
    case 0:
        break;
    case 1:
        {
            long p8 = self->field_8;
            long p10 = self->field_10;
            if (p8 < p10) { long q = pos; pos = p8; pos += q; }
            else { long q = pos; pos = p10; pos += q; }
        }
        break;
    case 2:
        pos = self->field_8 - pos;
        break;
    }
    if (self->field_8 < pos) pos = self->field_8;
    else if (pos < 0) pos = 0;
    int n = self->field_30;
    if (n < 0x800) {
        long a = self->field_10 - (long)n;
        long b = self->field_10 + (unsigned long)(unsigned int)(0x800 - n);
        if (!(pos < a) && !(pos > b)) {
            self->field_30 = (int)(pos - a);
            self->field_10 = pos;
            return self->field_10;
        }
    }
    self->field_30 = 0x800;
    self->field_10 = pos;
    self->field_18 = 2;
    mRPCArguments__13CGtFilePS2DVD[0] = self->field_28;
    mRPCArguments__13CGtFilePS2DVD[1] = (int)(pos / 0x800);
    mRPCArguments__13CGtFilePS2DVD[2] = 0;
    WaitSema(mnRPCSemaphore__13CGtFilePS2DVD);
    sceSifCallRpc(mRPCData__13CGtFilePS2DVD, 6, 0, mRPCArguments__13CGtFilePS2DVD, 0x10, 0, 0, 0, 0);
    SignalSema(mnRPCSemaphore__13CGtFilePS2DVD);
    if (self->field_20 == 0) self->vfunc_1C(1);
    return self->field_10;
}
