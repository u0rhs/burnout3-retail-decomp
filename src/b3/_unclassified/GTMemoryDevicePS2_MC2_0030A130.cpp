// CMemoryDevicePS2::Sync(EMemDevPollOrWait,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (two switches sharing r; static inline reset helper + int-returning GetInfoAsync helper [G]; ==0 test with error arm first).

// lifter variant 0
// CMemoryDevicePS2::Sync(EMemDevPollOrWait,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EMemDevPollOrWait {};

class CMemoryDevicePS2;
struct UnkStruct_0030A130_1;

struct UnkStruct_0030A130_1 {
    int field_0;
    int field_4;
};

class CMemoryDevicePS2 {
public:
    int Sync(EMemDevPollOrWait p0, int* p1);
    int GetRunStatus(int);
    int GetFinishStatus(int, int, int*);

    int field_0;
    unsigned char pad_4[0x48];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    unsigned char pad_5C[0x74];
    int field_D0;
    int field_D4;
    int field_D8;
};

extern "C" int func_00242E00(int *, int *);
extern "C" int sceMc2GetInfoAsync(int, void *);
extern "C" int sceMc2Sync(int *, int *);

// [G] inlined helper (no name evidence): the error reset seen in several arms
static inline void func_0030A130_inl1(CMemoryDevicePS2 * d)
{
    d->field_4C = 0;
    d->field_50 = 14;
    d->field_58 = 13;
    d->field_D0 = 0;
    d->field_D8 = -1;
    d->field_D4 = 1;
}

// [G] inlined helper (no name evidence)
static inline int func_0030A130_inl2(CMemoryDevicePS2 * d)
{
    if (sceMc2GetInfoAsync(d->field_54, &d->field_D0) != 0) {
        func_0030A130_inl1(d);
        return 0;
    }
    return 1;
}

// 0x0030A130
int CMemoryDevicePS2::Sync(EMemDevPollOrWait p0, int* p1)
{
    int a;
    int b;
    int r;
    if (field_50 == 5) {
        field_50 = 14;
        field_0 = 0;
        return field_0;
    }
    switch (p0) {
    case 0:
        r = func_00242E00(&a, &b);
        break;
    case 1:
        r = sceMc2Sync(&a, &b);
        break;
    default:
        func_0030A130_inl1(this);
        field_0 = 13;
        return field_0;
    }
    switch (r) {
    case 0:
        field_0 = GetRunStatus(a);
        return field_0;
    case 1:
        field_0 = GetFinishStatus(a, b, p1);
        return field_0;
    case -1:
        if (func_0030A130_inl2(this) == 0) {
            func_0030A130_inl1(this);
            field_0 = 13;
            return field_0;
        }
        field_0 = 1;
        return field_0;
    default:
        func_0030A130_inl1(this);
        field_0 = 13;
        return field_0;
    }
}
