// CMemoryDevicePS2::GetFinishStatus(int,int,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (switch(p0) in reverse-test order over static inline per-command error translators (switch on r&0xFFFF, break then return 13) and an inline error setter).

// lifter variant 0
// CMemoryDevicePS2::GetFinishStatus(int,int,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int GetFinishStatus(int p0, int p1, int* p2);
    int FinishedGetInfo(int);
    int FinishedGetFileSize(int, int*);

    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
    unsigned char pad_54[0x4];
    int field_58;
    unsigned char pad_5C[0x74];
    int field_D0;
    int field_D4;
    int field_D8;
};

// Inlined helpers (placeholder names [G]). The O0 build's symbol table (research/E_B3O0PCH_symbols.csv) lists
// CMemoryDevicePS2::SetLastError(EMemDevError) and Finished{CreateFile,Read,Write,Format,MkDir,Delete,FileExists}
// beside GetFinishStatus; which body is which is not evidenced, so they keep placeholders here.
static inline void func_003096E0_err(CMemoryDevicePS2 * d, int e)
{
    d->field_4C = 0;
    d->field_50 = 14;
    d->field_58 = e;
    d->field_D0 = 0;
    d->field_D8 = -1;
    d->field_D4 = 1;
}

static inline int func_003096E0_inl7(CMemoryDevicePS2 * d, int r)
{
    switch (r & 0xFFFF) {
    case 0:
        return 0;
    case 111:
    case 19:
        func_003096E0_err(d, 1);
        break;
    case 28:
        func_003096E0_err(d, 11);
        break;
    case 23:
        func_003096E0_err(d, 12);
        break;
    default:
        func_003096E0_err(d, 13);
        break;
    }
    return 13;
}

static inline int func_003096E0_inl5(CMemoryDevicePS2 * d, int r, int * out)
{
    if (r < 0) {
        switch (r & 0xFFFF) {
        case 111:
        case 19:
            func_003096E0_err(d, 1);
            break;
        default:
            func_003096E0_err(d, 13);
            break;
        }
        return 13;
    }
    if (out != 0) {
        *out = r;
    }
    return 0;
}

static inline int func_003096E0_inl6(CMemoryDevicePS2 * d, int r, int * out)
{
    if (r < 0) {
        switch (r & 0xFFFF) {
        case 28:
            func_003096E0_err(d, 11);
            break;
        case 111:
        case 19:
            func_003096E0_err(d, 1);
            break;
        default:
            func_003096E0_err(d, 13);
            break;
        }
        return 13;
    }
    if (out != 0) {
        *out = r;
    }
    return 0;
}

static inline int func_003096E0_inl11(CMemoryDevicePS2 * d, int r)
{
    switch (r & 0xFFFF) {
    case 0:
        return 0;
    case 28:
        func_003096E0_err(d, 11);
        break;
    case 111:
    case 19:
        func_003096E0_err(d, 1);
        break;
    default:
        func_003096E0_err(d, 13);
        break;
    }
    return 13;
}

static inline int func_003096E0_inl8(CMemoryDevicePS2 * d, int r)
{
    switch (r & 0xFFFF) {
    case 0:
        return 0;
    case 22:
    case 20:
        func_003096E0_err(d, 9);
        break;
    case 111:
    case 19:
        func_003096E0_err(d, 1);
        break;
    default:
        func_003096E0_err(d, 13);
        break;
    }
    return 13;
}

static inline int func_003096E0_inl3(CMemoryDevicePS2 * d, int r)
{
    switch (r & 0xFFFF) {
    case 0:
        return 0;
    case 111:
    case 19:
        func_003096E0_err(d, 1);
        break;
    default:
        func_003096E0_err(d, 13);
        break;
    }
    return 13;
}

static inline int func_003096E0_inl14(CMemoryDevicePS2 * d, int r)
{
    switch (r & 0xFFFF) {
    case 0:
        return 0;
    case 22:
    case 20:
    case 2:
        func_003096E0_err(d, 9);
        break;
    case 111:
    case 19:
        func_003096E0_err(d, 1);
        break;
    default:
        func_003096E0_err(d, 13);
        break;
    }
    return 13;
}

// 0x003096E0
int CMemoryDevicePS2::GetFinishStatus(int p0, int p1, int* p2)
{
    if (p2 != 0) {
        *p2 = -1;
    }
    switch (p0) {
    case 7:
        return func_003096E0_inl7(this, p1);
    case 5:
        return func_003096E0_inl5(this, p1, p2);
    case 6:
        return func_003096E0_inl6(this, p1, p2);
    case 11:
        return func_003096E0_inl11(this, p1);
    case 8:
        return func_003096E0_inl8(this, p1);
    case 3:
        return func_003096E0_inl3(this, p1);
    case 10:
        return FinishedGetFileSize(p1, p2);
    case 2:
        return FinishedGetInfo(p1);
    case 14:
        return func_003096E0_inl14(this, p1);
    default:
        func_003096E0_err(this, 13);
        return 13;
    }
}
