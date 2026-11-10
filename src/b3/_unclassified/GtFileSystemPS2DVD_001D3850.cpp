// CGtFileSystemPS2DVD::Init(unsigned int,CGtFilePS2DVD*,CGtFileBufferPS2DVD*,const char*,int,int,int,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a95: hand-written extern C; goto entry-jump loops, sema reference local, const args pointer for stores only).

struct UnkStruct_001D3850_buf { unsigned char pad_0[0x800]; };
struct UnkStruct_001D3850_file {
    unsigned char pad_0[0x2C];
    int field_2C;
    unsigned char pad_30[4];
    UnkStruct_001D3850_buf * field_34;
};
struct UnkStruct_001D3850 {
    unsigned char pad_0[0x10];
    UnkStruct_001D3850_file * field_10;
    UnkStruct_001D3850_buf * field_14;
};
struct UnkStruct_001D3850_sema { int field_0; int field_4; int field_8; int field_C; int field_10; int field_14; };
struct UnkStruct_001D3850_rpc { unsigned char pad_0[0x24]; int field_24; unsigned char pad_28[0x18]; };
struct UnkStruct_001D3850_args { int field_0; int field_4; int field_8; int field_C; char field_10[0x100]; };
extern "C" UnkStruct_001D3850_args mRPCArguments__13CGtFilePS2DVD;
extern "C" UnkStruct_001D3850_rpc mRPCData__13CGtFilePS2DVD;
extern "C" int mnRPCSemaphore__13CGtFilePS2DVD;
extern "C" int mCmdHandle__13CGtFilePS2DVD;
extern "C" int mpIOPFileFuncs__19CGtFileSystemPS2DVD;
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int CreateSema(void *);
extern "C" void func_00114E60(void);
extern "C" void EIntr(void);
extern "C" void FlushCache(int);
extern "C" int sceSifAddCmdHandler(unsigned int, void *, void *);
extern "C" int sceSifBindRpc(void *, unsigned int, unsigned int);
extern "C" int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);
extern "C" int CmdReadCompleteHandler__19CGtFileSystemPS2DVDFPvPv(void *, void *);
extern "C" void CmdErrorHandler__19CGtFileSystemPS2DVDFPvPv(void *, void *);
extern "C" int Init__13CGTFileSystemFUiPCc(void *, unsigned int, const char *);

extern "C" bool Init__19CGtFileSystemPS2DVDFUiP13CGtFilePS2DVDP19CGtFileBufferPS2DVDPCciiiPc(UnkStruct_001D3850 * self, unsigned int n, UnkStruct_001D3850_file * files, UnkStruct_001D3850_buf * bufs, const char * name, int a, int b, int c, char * path)
{
    self->field_10 = files;
    self->field_14 = bufs;
    unsigned int i = 0;
    goto test;
body:
    self->field_10[i].field_34 = self->field_14 + i;
    i++;
test:
    if (i < n) goto body;
    if (Init__13CGTFileSystemFUiPCc(self, n, name) == 0) return false;
    UnkStruct_001D3850_sema sema;
    int & w = sema.field_8;
    sema.field_4 = 1;
    unsigned int j = 0;
    w = 0;
    goto test2;
body2:
    self->field_10[j].field_2C = CreateSema(&sema);
    j++;
test2:
    if (j < n) goto body2;
    w = 1;
    mnRPCSemaphore__13CGtFilePS2DVD = CreateSema(&sema);
    mCmdHandle__13CGtFilePS2DVD = 0;
    func_00114E60();
    sceSifAddCmdHandler(4, (void *)CmdReadCompleteHandler__19CGtFileSystemPS2DVDFPvPv, self);
    sceSifAddCmdHandler(5, (void *)CmdErrorHandler__19CGtFileSystemPS2DVDFPvPv, self);
    EIntr();
    do {
        sceSifBindRpc(&mRPCData__13CGtFilePS2DVD, 0x475453, 0);
    } while (mRPCData__13CGtFilePS2DVD.field_24 == 0);
    UnkStruct_001D3850_args * const args = &mRPCArguments__13CGtFilePS2DVD;
    args->field_0 = n;
    args->field_4 = a;
    args->field_8 = b;
    args->field_C = c;
    if (path != 0) strncpy(args->field_10, path, 0x20);
    else args->field_10[0] = 0;
    FlushCache(0);
    sceSifCallRpc(&mRPCData__13CGtFilePS2DVD, 1, 0, &mRPCArguments__13CGtFilePS2DVD, 0x30, &mpIOPFileFuncs__19CGtFileSystemPS2DVD, 4, 0, 0);
    return mpIOPFileFuncs__19CGtFileSystemPS2DVD != 0;
}
