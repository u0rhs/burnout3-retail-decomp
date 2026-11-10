// CGtFilePS2DVD::Close() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: static members as extern C mangled data; arg store before WaitSema).

struct UnkStruct_001D3670 {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0xC];
    int field_28;
};
struct UnkStruct_001D3670_rpc { unsigned char pad_0[0x40]; };
extern "C" int mRPCArguments__13CGtFilePS2DVD[64];
extern "C" UnkStruct_001D3670_rpc mRPCData__13CGtFilePS2DVD;
extern "C" int mnRPCSemaphore__13CGtFilePS2DVD;
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
extern "C" int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);

// 0x001D3670
extern "C" void Close__13CGtFilePS2DVDFv(UnkStruct_001D3670 *self)
{
    self->field_18 = 0;
    mRPCArguments__13CGtFilePS2DVD[0] = self->field_28;
    WaitSema(mnRPCSemaphore__13CGtFilePS2DVD);
    sceSifCallRpc(&mRPCData__13CGtFilePS2DVD, 4, 0, mRPCArguments__13CGtFilePS2DVD, 0x10, 0, 0, 0, 0);
    SignalSema(mnRPCSemaphore__13CGtFilePS2DVD);
}
