// NONMATCHING: GetFileSystemFromFileName__13CGTFileSystemFPCc -- retail 53 / ours 53 instructions, 5 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x212BD0). A "dev:" prefix in the first 4 characters picks the
// registered device whose name matches (4 characters); no prefix or no match: the default file system.
// TRACK: clean
// EQUIV: [L] written from the retail asm: every branch, store and call accounted for

// [C] names: the mangled symbols in retail's tables (research/retail_names.csv: GtFileSystem.cpp, high; FTell has no
// row there: config/symbol_addrs.txt, its name from Burnout 2's debug info per that file). Static members unless they
// read `this` [C a0 use]. Field names placeholders, types [G] from widths.
struct UnkStruct_GtFS_file {
    // [C] an open file: vtable at +0, slot 0x10 read(buf, n), 0x14 write(buf, n), 0x18 seek(pos, whence) (FRead /
    // FWrite / FSeek); 64-bit size at +8 and position at +0x10 (FEof's ld)
    virtual void vfunc_8(); virtual void vfunc_C();
    virtual unsigned int vfunc_10(void *, unsigned int);
    virtual unsigned int vfunc_14(const void *, unsigned int);
    virtual void vfunc_18(int, int);
    long field_8;
    long field_10;
};
class CGTFileSystem {
public:
    // [C] vtable at +0: slot 8 exists(name) (FExist), slot 0x10 file object i (Init's loop)
    virtual int vfunc_8(const char *);
    virtual void vfunc_C();
    virtual unsigned char * vfunc_10(unsigned int);
    int field_4;
    int field_8;
    unsigned int field_C;       // [C] number of file objects (Init's a1)

    static int FTell(void *);
    static int FExist(const char *);
    static int FSeek(void *, int, int);
    static int FEof(void *);
    static unsigned int FPuts(const char *, void *);
    static unsigned int FWrite(const void *, unsigned int, unsigned int, void *);
    static unsigned int FRead(void *, unsigned int, unsigned int, void *);
    static void * FOpen(const char *, const char *);
    void * Open(const char *, unsigned int);
    int Init(unsigned int, const char *);
    static char * BuildFileName(char *, int, const char *, const char *, char);
    static const char * GetFileNameFromDeviceName(const char *);
    static CGTFileSystem * GetFileSystemFromFileName(const char *);

    static CGTFileSystem * mpDefaultFilesystem;
    static unsigned int mnNumFilesystems;
    static CGTFileSystem * mpaFilesystems[];
};
extern char D_00676470[];   // [C] the device names, 5 bytes each (Init's strncpy of 4 at n*5)
extern "C" unsigned int strlen(const char *);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" char * func_00127BF8(const char *, const char *);   // [L] strstr: a non-null result sets a mode flag
extern "C" int func_00127520(const char *, const char *, unsigned int);   // [L] strncmp: 0 = same device
extern char D_004B96D8[], D_004B96E0[], D_004B96E8[], D_004B96F0[], D_004B96F8[];   // [C] "r" "w" "a" "+" "s"

// 0x00212BD0
CGTFileSystem * CGTFileSystem::GetFileSystemFromFileName(const char * name)
{
    CGTFileSystem * fs = mpDefaultFilesystem;
    for (unsigned int i = 0; i < 4; i++) {
        if (name[i] == ':') {
            char dev[8];
            strncpy(dev, name, i + 1);
            dev[i + 1] = 0;
            for (unsigned int j = 0; j < mnNumFilesystems; j++) {
                if (func_00127520(dev, D_00676470 + j * 5, 4) == 0) {
                    return mpaFilesystems[j];
                }
            }
            return fs;
        }
    }
    return fs;
}
