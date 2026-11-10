// CMemoryDevicePS2::OpenFile(const char*,unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early-return error resets; GetDirAsync path as int-returning static inline helper; shared strcpy tail).

// lifter variant 0
// CMemoryDevicePS2::OpenFile(const char*,unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int OpenFile(const char* p0, unsigned int p1, unsigned int p2);

    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    unsigned char pad_5C[0x74];
    int field_D0;
    int field_D4;
    int field_D8;
};

extern "C" unsigned int strlen(const char *);
extern "C" char * strcpy(char *, const char *);
extern "C" int sceMc2GetDirAsync(int, const char*, int, int, void *, void *);
extern "C" int func_00242428(int, const char*);

// [G] inlined helper (name unknown): sceMc2GetDirAsync, error reset on failure; int result
static inline int func_0030A5E0_inl1(CMemoryDevicePS2 *d, const char *p0)
{
    if (sceMc2GetDirAsync(d->field_54, p0, 0, 1, (char *)d + 0x94, (char *)d + 0xCC) != 0) {
        d->field_4C = 0;
        d->field_50 = 14;
        d->field_58 = 13;
        d->field_D0 = 0;
        d->field_D8 = -1;
        d->field_D4 = 1;
        return 0;
    }
    return 1;
}
// 0x0030A5E0
int CMemoryDevicePS2::OpenFile(const char* p0, unsigned int p1, unsigned int p2)
{
    if (field_4C != 0) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        return 0;
    }
    if (strlen(p0) >= 69) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        return 0;
    }
    if (p1 == 0) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        return 0;
    }
    if (p1 & 4) {
        if (func_00242428(field_54, p0) != 0) {
            field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
            return 0;
        }
    } else {
        if (!func_0030A5E0_inl1(this, p0)) return 0;
        field_50 = 4;
    }
    strcpy((char *)this + 0x4, p0);
    field_4C = p1;
    return 1;
}
