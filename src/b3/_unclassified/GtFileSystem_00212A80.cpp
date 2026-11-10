// CGTFileSystem::BuildFileName(char*,int,const char*,const char*,char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): if ((size - 1) < (lp + ln)); if ((lp + ln) > (size - 1))).

struct UnkStruct_GtFS_file {
    
    
    virtual void vfunc_8(); virtual void vfunc_C();
    virtual unsigned int vfunc_10(void *, unsigned int);
    virtual unsigned int vfunc_14(const void *, unsigned int);
    virtual void vfunc_18(int, int);
    long field_8;
    long field_10;
};
class CGTFileSystem {
public:
    
    virtual int vfunc_8(const char *);
    virtual void vfunc_C();
    virtual unsigned char * vfunc_10(unsigned int);
    int field_4;
    int field_8;
    unsigned int field_C;       

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
extern char D_00676470[];   
extern "C" unsigned int strlen(const char *);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" char * func_00127BF8(const char *, const char *);   
extern "C" int func_00127520(const char *, const char *, unsigned int);   
extern char D_004B96D8[], D_004B96E0[], D_004B96E8[], D_004B96F0[], D_004B96F8[];

// 0x00212A80
char *CGTFileSystem::BuildFileName(char *out, int size, const char *prefix, const char *name, char sep)
{
  int lp = strlen(prefix);
  int ln = strlen(name);
  if ((lp + ln) > (size - 1))
  {
    return 0;
  }
  strcpy(out, prefix);
  char *d = out + lp;
  for (int i = 0; i <= ln; i++)
  {
    char c = name[i];
    if ((c == '/') || (c == '\\'))
    {
      d[i] = sep;
    }
    else
    {
      d[i] = c;
    }
  }

  return out;
}
