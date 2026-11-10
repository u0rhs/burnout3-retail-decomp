// CB3SFIOCallbacks::SFIOOpenCallback(const char*,const char*,SFIODeviceE,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SFIO static callback).

enum SFIODeviceE { };
class CMemoryDevicePS2 {
public:
    int OpenFile(const char *, unsigned int, unsigned int);
    unsigned char pad_0[0x10];
};
extern CMemoryDevicePS2 D_005185A0;
extern "C" int snprintf(char *, unsigned int, const char *, ...);
struct UnkStruct_D_004C74A8 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C74A8 D_004C74A8;
class CB3SFIOCallbacks {
public:
    static void SFIOOpenCallback(const char *, const char *, SFIODeviceE, unsigned int);
    static int gmeLastOperation;
    static int gmeProcess;
    static int gmeError;
};
// 0x00361340
void CB3SFIOCallbacks::SFIOOpenCallback(const char *p0, const char *p1, SFIODeviceE p2, unsigned int mode)
{
    char buf[0x44];
    snprintf(buf, 0x44, (char *)&D_004C74A8, p0, p1);
    if (mode == 3) {
        if (D_005185A0.OpenFile(buf, 3, 0) == 0) {
            CB3SFIOCallbacks::gmeLastOperation = 0;
            CB3SFIOCallbacks::gmeProcess = 2;
            CB3SFIOCallbacks::gmeError = 0x11;
            return;
        }
    } else if (mode == 0x203) {
        if (D_005185A0.OpenFile(buf, 6, 0) == 0) {
            CB3SFIOCallbacks::gmeLastOperation = 0;
            CB3SFIOCallbacks::gmeProcess = 2;
            CB3SFIOCallbacks::gmeError = 0x11;
            return;
        }
    }
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeLastOperation = 4;
    CB3SFIOCallbacks::gmeProcess = 1;
}
