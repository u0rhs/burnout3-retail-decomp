// Hand-written; the lifter refused it (CGTFileSystem::Open is a member (a2 = this), file read/close via vtable slots 0x10/0xC).

// Prepare__Q27GtComms16CGtCommsToolBaseFPCcP13CGTFileSystemPCc -- hand-written (the lifter refused it: member callee looked static).
// [C] E map / research/retail_names.csv @0x0021B830: GtComms::CGtCommsToolBase::Prepare(const char*,
// CGTFileSystem*,const char*) in GtCommsToolBase.cpp; kept under the asm label (C linkage) here because
// the retail asm and link still use the placeholder. The third parameter is not read.

struct UnkStruct_0021B830_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(void *, unsigned int);
    int field_4;
    int field_8;  // [G] file size (rounded up to 0x800 for the read)
};

class CGTFileSystem {
public:
    UnkStruct_0021B830_2 *Open(const char *, unsigned int);
};

extern "C" void InitialiseDefaultValues__Q27GtComms20CGtCommsDatabaseGameFv(void *);

// 0x0021B830
extern "C" int Prepare__Q27GtComms16CGtCommsToolBaseFPCcP13CGTFileSystemPCc(char *self, const char *p1, CGTFileSystem *p2)
{
    if (p1 != 0) {
        UnkStruct_0021B830_2 *f = p2->Open(p1, 1);
        if (f != 0) {
            f->vfunc_10(self + 0xE540, (f->field_8 + 0x7FF) & ~0x7FF);
            InitialiseDefaultValues__Q27GtComms20CGtCommsDatabaseGameFv(self + 0x10);
            f->vfunc_C();
        }
    }
    return 1;
}
