// CGTFileSystem::FOpen(const char*,const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (gaps1b: hand-written from the asm, exact).

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2127A0). The fopen-style mode string becomes flags:
// "r" 1, "w" 6, "a" 0xA, "+" 3, "s" 0x10 (OR-ed) [C the ori constants]; then the device's Open.

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

// 0x002127A0
void * CGTFileSystem::FOpen(const char * name, const char * mode)
{
    unsigned int flags = 0;
    if (func_00127BF8(mode, D_004B96D8) != 0) flags |= 0x1;
    if (func_00127BF8(mode, D_004B96E0) != 0) flags |= 0x6;
    if (func_00127BF8(mode, D_004B96E8) != 0) flags |= 0xA;
    if (func_00127BF8(mode, D_004B96F0) != 0) flags |= 0x3;
    if (func_00127BF8(mode, D_004B96F8) != 0) flags |= 0x10;
    CGTFileSystem * fs = GetFileSystemFromFileName(name);
    if (fs == 0) {
        return 0;
    }
    return fs->Open(name, flags);
}
