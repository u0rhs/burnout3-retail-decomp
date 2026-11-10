// CGtFilePS2DVD::Abort() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: wait on sceSifDmaStat, send abort cmd until handle nonzero).

extern "C" int sceSifDmaStat(unsigned int);
extern "C" unsigned int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);
struct UnkStruct_001D2FA0_hdr {
    int field_0;
    int field_4;
    int field_8;
    unsigned int field_C;
};
class CGtFilePS2DVD {
public:
    int Abort();
    static unsigned int mCmdHandle;
    static UnkStruct_001D2FA0_hdr mCmdHdr;
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
    int field_20;
    unsigned char pad_24[0x4];
    unsigned char field_28;
};

// 0x001D2FA0
int CGtFilePS2DVD::Abort()
{
    if (field_20 != 0 && field_18 == 2) {
        if (mCmdHandle != 0) {
            while (sceSifDmaStat(mCmdHandle) >= 0) {
            }
            mCmdHandle = 0;
        }
        mCmdHdr.field_C = field_28 | 0x100;
        do {
            mCmdHandle = sceSifSendCmd(4, &mCmdHdr, 0x10, 0, 0, 0);
        } while (mCmdHandle == 0);
        return 1;
    }
    return 0;
}
