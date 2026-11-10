// CB3SFIOCallbacks::SFIOFindCallback(const char*,SFIODeviceE) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SFIO static callback).

enum SFIODeviceE { };
class CMemoryDevicePS2 {
public:
    int FileExists(const char *);
    unsigned char pad_0[0x10];
};
extern CMemoryDevicePS2 D_005185A0;
struct UnkStruct_D_01EA3FD0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01EA3FD0 D_01EA3FD0;
extern "C" char * strncpy(char *, const char *, unsigned int);
class CB3SFIOCallbacks {
public:
    static void SFIOFindCallback(const char *, SFIODeviceE);
    static int gmeLastOperation;
    static int gmeProcess;
    static int gmeError;
};
// 0x00361510
void CB3SFIOCallbacks::SFIOFindCallback(const char *p0, SFIODeviceE p1)
{
    if (D_005185A0.FileExists(p0) == 0) {
        CB3SFIOCallbacks::gmeProcess = 2;
        CB3SFIOCallbacks::gmeError = 4;
        return;
    }
    strncpy((char *)&D_01EA3FD0, p0, 0x44);
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeLastOperation = 12;
    CB3SFIOCallbacks::gmeProcess = 1;
}
