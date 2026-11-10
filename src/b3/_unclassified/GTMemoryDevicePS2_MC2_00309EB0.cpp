// CMemoryDevicePS2::FinishedGetInfo(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (one switch on (p0 & 0xFFFF) (cases in reverse test order), error-state static inline helper per arm, break to a shared 'return 13'; case 0 returns 0 early).

// lifter variant 0
// CMemoryDevicePS2::FinishedGetInfo(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int FinishedGetInfo(int p0);

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

// [G] inlined error-state helper (no name in any table): the same six stores recur across this class
static inline void func_00309EB0_inl1(CMemoryDevicePS2 * d, int code, int flag)
{
    d->field_4C = 0;
    d->field_50 = 14;
    d->field_58 = code;
    d->field_D0 = 0;
    d->field_D8 = -1;
    d->field_D4 = flag;
}
// 0x00309EB0
int CMemoryDevicePS2::FinishedGetInfo(int p0)
{
    switch (p0 & 0xFFFF) {
    case 0:
        if (field_D0 != 2) {
            func_00309EB0_inl1(this, 1, 1);
            break;
        }
        if (field_D4 == 0) {
            func_00309EB0_inl1(this, 3, 0);
            break;
        }
        return 0;
    case 0x9003:
        func_00309EB0_inl1(this, 2, 1);
        break;
    case 0x6F:
    case 0x13:
        func_00309EB0_inl1(this, 1, 1);
        break;
    case 0x9001:
        func_00309EB0_inl1(this, 6, 1);
        break;
    case 0x2F:
        func_00309EB0_inl1(this, 3, 0);
        break;
    default:
        func_00309EB0_inl1(this, 13, 1);
        break;
    }
    return 13;
}
