// CMemoryDevicePS2::FinishedGetFileSize(int,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (switch with inline error-state helper (sibling FinishedGetInfo shape); field_CC==1 arm wraps the success path).

// lifter variant 0
// CMemoryDevicePS2::FinishedGetFileSize(int,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int FinishedGetFileSize(int p0, int* p1);

    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
    unsigned char pad_54[0x4];
    int field_58;
    unsigned char pad_5C[0x48];
    int field_A4;
    unsigned short field_A8;
    unsigned char pad_AA[0x22];
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
};

// [G] inlined error-state helper (no name in any table): same six stores as func_00309EB0_inl1 in
// GTMemoryDevicePS2_MC2_00309EB0.cpp
static inline void func_00309D20_inl1(CMemoryDevicePS2 * d, int code, int flag)
{
    d->field_4C = 0;
    d->field_50 = 14;
    d->field_58 = code;
    d->field_D0 = 0;
    d->field_D8 = -1;
    d->field_D4 = flag;
}

// 0x00309D20
int CMemoryDevicePS2::FinishedGetFileSize(int p0, int* p1)
{
    switch (p0 & 0xFFFF) {
    case 0:
        if (field_CC == 1) {
            if (field_50 == 4) {
                field_50 = 14;
            } else if (p1 != 0) {
                if (field_A8 & 0x20) {
                    *p1 = 0;
                } else {
                    *p1 = field_A4;
                }
            }
            return 0;
        }
        func_00309D20_inl1(this, 9, 1);
        break;
    case 0x9002:
        func_00309D20_inl1(this, 10, 1);
        break;
    case 2:
    case 0x14:
        func_00309D20_inl1(this, 9, 1);
        break;
    case 0x6F:
    case 0x13:
        func_00309D20_inl1(this, 1, 1);
        break;
    default:
        func_00309D20_inl1(this, 13, 1);
        break;
    }
    return 13;
}
