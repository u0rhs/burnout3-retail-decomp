// CB3SFIOCallbacks::SFIOCloseCallback(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early returns instead of if/else chain).

// CB3SFIOCallbacks::SFIOCloseCallback(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SFIOCallbacks;
class CMemoryDevicePS2;
struct UnkStruct_D_004E2E10;

class CMemoryDevicePS2 {
public:
    int CloseFile();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2E10 {
    unsigned char field_0;
};

class CB3SFIOCallbacks {
public:
    void SFIOCloseCallback(int p0);
    static int gmeLastOperation;
    static int gmeProcess;
    static int gmeError;
};

extern UnkStruct_D_004E2E10 D_004E2E10;
extern CMemoryDevicePS2 D_005185A0;

// 0x003612C0
void CB3SFIOCallbacks::SFIOCloseCallback(int p0)
{
    if (D_004E2E10.field_0 == 0) {
        CB3SFIOCallbacks::gmeLastOperation = 0;
        CB3SFIOCallbacks::gmeProcess = 2;
        CB3SFIOCallbacks::gmeError = 0;
        return;
    }
    if (D_005185A0.CloseFile() == 0) {
        CB3SFIOCallbacks::gmeLastOperation = 0;
        CB3SFIOCallbacks::gmeProcess = 2;
        CB3SFIOCallbacks::gmeError = 17;
        return;
    }
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeLastOperation = 5;
    CB3SFIOCallbacks::gmeProcess = 2;
}
