// Hand-written; the lifter refused it (int-held base (t+0x90)->field_14[1] char-array-style member keeps unfolded addiu 0x90/0x14).

extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void SyncDCache(void *, void *);
struct UnkStruct_002516C0 {
    unsigned char pad_0[0xA4];
    unsigned int field_A4;
};
struct UnkStruct_002516C0_blk {
    unsigned char pad_0[0x14];
    unsigned int field_14[1];
};
extern "C" void FixDown__10CGtTextureFv(UnkStruct_002516C0 *);
extern "C" void FixUp__10CGtTextureFv(void *);
// 0x002516C0
// [L] DNAT: CGtTexture::CreateCopy(unsigned int) (research/proto/new_names.csv, high); retail reads only (this, dst): a1 is the destination buffer, the caller's third arg is not read
extern "C" char *CreateCopy__10CGtTextureFUi(UnkStruct_002516C0 *self, int dst_)
{
    char * dst = (char *)dst_;
    FixDown__10CGtTextureFv(self);
    int t = (int)self;
    unsigned int *sz = ((UnkStruct_002516C0_blk *)(t + 0x90))->field_14;
    memcpy(dst, self, *sz);
    FixUp__10CGtTextureFv(self);
    FixUp__10CGtTextureFv(dst);
    SyncDCache(dst, dst + *sz - 1);
    return dst;
}
