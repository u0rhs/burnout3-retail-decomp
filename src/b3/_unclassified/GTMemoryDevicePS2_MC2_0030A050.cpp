// CMemoryDevicePS2::GetRunStatus(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (case 10 as if (field_50 == 4) return 4; return 11; case 2 merged with default).

// CMemoryDevicePS2::GetRunStatus(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int GetRunStatus(int p0);

    unsigned char pad_0[0x50];
    int field_50;
};

// 0x0030A050
int CMemoryDevicePS2::GetRunStatus(int p0)
{
    switch (p0) {
    case 7:
        return 4;
    case 5:
        return 7;
    case 6:
        return 8;
    case 11:
        return 10;
    case 8:
        return 6;
    case 3:
        return 9;
    case 10:
        if (field_50 == 4) return 4;
        return 11;
    case 14:
        return 12;
    case 2:
    default:
        return 1;
    }
}
