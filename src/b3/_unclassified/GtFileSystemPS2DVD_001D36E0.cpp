// CGtFilePS2DVD::Open(CGTFileSystem*,const char*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a95: hand-written extern C; const result-pointer local gives lui/addiu a1 base).

struct UnkStruct_001D36E0 {
    unsigned char pad_0[4];
    void * field_4;
    long field_8;
    long field_10;
    int field_18;
    int field_1C;
    int field_20;
    unsigned char pad_24[4];
    int field_28;
    unsigned char pad_2C[4];
    int field_30;
};
extern "C" char mRPCArguments__13CGtFilePS2DVD[256];
extern "C" unsigned int mRPCResults__13CGtFilePS2DVD[4];
extern "C" int mnRPCSemaphore__13CGtFilePS2DVD;
extern "C" char mRPCData__13CGtFilePS2DVD[0x40];
extern char D_004B7DE8[];
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
extern "C" int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);
extern "C" const char * GetFileNameFromDeviceName__13CGTFileSystemFPCc(const char *);
extern "C" char * BuildFileName__13CGTFileSystemFPciPCcPCcc(char *, int, const char *, const char *, char);

extern "C" int Open__13CGtFilePS2DVDFP13CGTFileSystemPCcUi(UnkStruct_001D36E0 * self, void * fs, const char * name, unsigned int flags)
{
    char buf[0x40];
    if (!BuildFileName__13CGTFileSystemFPciPCcPCcc(buf, 0x40, D_004B7DE8, GetFileNameFromDeviceName__13CGTFileSystemFPCc(name), '\\')) return 5;
    if ((flags & 0xE) != 0) return 4;
    if ((flags & 0x10) != 0) self->field_20 = 1;
    else self->field_20 = 0;
    strncpy(mRPCArguments__13CGtFilePS2DVD, buf, 0x100);
    WaitSema(mnRPCSemaphore__13CGtFilePS2DVD);
    sceSifCallRpc(mRPCData__13CGtFilePS2DVD, 3, 0, mRPCArguments__13CGtFilePS2DVD, 0x40, mRPCResults__13CGtFilePS2DVD, 0x10, 0, 0);
    SignalSema(mnRPCSemaphore__13CGtFilePS2DVD);
    unsigned int * const res = mRPCResults__13CGtFilePS2DVD;
    int r = res[0];
    if (r < 0) return 2;
    self->field_28 = r;
    self->field_10 = 0;
    self->field_8 = res[1];
    self->field_30 = 0x800;
    self->field_4 = fs;
    self->field_18 = 1;
    self->field_1C = 0;
    return 0;
}
